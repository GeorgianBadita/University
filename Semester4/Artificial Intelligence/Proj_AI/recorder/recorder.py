import pyaudio
import wave
import subprocess
import os

dirname = os.path.dirname(__file__)
filename = os.path.join(dirname, 'data\\output.wav')

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 2
RATE = 44100


def record(OUTPUT_FILENAME, RECORD_SECONDS=5, ):
    OUTPUT_FILENAME = os.path.join(dirname, OUTPUT_FILENAME)
    p = pyaudio.PyAudio()

    stream = p.open(format=FORMAT,
                    channels=CHANNELS,
                    rate=RATE,
                    input=True,
                    frames_per_buffer=CHUNK)

    print("* recording")

    frames = []

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        data = stream.read(CHUNK)
        frames.append(data)

    print("* done recording")

    stream.stop_stream()
    stream.close()
    p.terminate()

    wf = wave.open(filename, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(p.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frames))
    wf.close()

    wav = filename
    cmd = 'lame --preset insane %s %s' % (wav, OUTPUT_FILENAME)
    print(cmd)
    subprocess.call(cmd, shell=True, cwd='recorder')
