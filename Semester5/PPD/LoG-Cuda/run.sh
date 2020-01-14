#!/bin/bash
if [ "$3" != "" ]; then
    ffmpeg -i "$1" -s 1920x1080 -pix_fmt yuv420p yourjpeg.yuv
    ./laplacefilter yourjpeg.yuv $2 $3 0.5
else
    echo "Positional parameter give an image"
fi
