using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Async_Tasks
{
    public class Obj
    {
        public Socket sock = null;

        public const int BUFF_SIZE = 512;
        
        public byte[] buffer = new byte[BUFF_SIZE];

        public StringBuilder responseContent = new StringBuilder();

        public int id;
        public string hostname;
        public string endpoint;

        public IPEndPoint remoteEndPoint;

        public ManualResetEvent connectDone = new ManualResetEvent(false);
        public ManualResetEvent sendDone = new ManualResetEvent(false);
        public ManualResetEvent receiveDone = new ManualResetEvent(false);

    }
}