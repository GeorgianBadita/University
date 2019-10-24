using Common.protocol;
using Common.service;
using Common.utils.observer;
using Lab2_Festival.domain.entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab2_Festival.Service
{
    class ServiceProxy : IService
    {
        private string host;
        private int port;

        private IObserver observer;

        private IFormatter formatter;
        private NetworkStream stream;
        private TcpClient connection;

        private Queue<IResponse> responseQueue;
        private EventWaitHandle _waitHandle;

        private volatile bool finished;

        public ServiceProxy(string host, int port)
        {
            this.port = port;
            this.host = host;
            responseQueue = new Queue<IResponse>();
        }

        private void CloseConnection()
        {
            finished = true;
            try
            {
                stream.Close();
                connection.Close();
                _waitHandle.Close();
                observer = null;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.StackTrace);
            }
        }

        private void InitializeConnection()
        {
            try
            {
                connection = new TcpClient(host, port);
                stream = connection.GetStream();
                formatter = new BinaryFormatter();
                finished = false;
                _waitHandle = new AutoResetEvent(false);
                StartReader();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.StackTrace);
            }
        }

        private void SendRequest(IRequest request)
        {
            try
            {
                formatter.Serialize(stream, request);
                stream.Flush();
                
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.StackTrace);
            }
        }

        private IResponse ReadResponse()
        {
            IResponse response = null;
            try
            {
                _waitHandle.WaitOne();
                lock (responseQueue)
                {
                    response = responseQueue.Dequeue();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.StackTrace);
            }
            return response;
        }

        private void StartReader()
        {
            Thread thr = new Thread(Run);
            thr.Start();
        }

        private void HandleUpdate(IResponse response)
        {
            observer.ReloadObserver();
        }

        public virtual void Run()
        {
            while (!finished)
            {
                try
                {
                    IResponse response = formatter.Deserialize(stream) as IResponse;
                   
                    Console.WriteLine("Received: " + response);
                    Console.WriteLine(response.GetResponseType());
                    if (response.GetResponseType() == ResponseType.UPDATE)
                    {
                        HandleUpdate(response);
                    }
                    else
                    {
                        lock (responseQueue)
                        {
                            responseQueue.Enqueue(response);
                        }
                        _waitHandle.Set();
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Reading error " + ex);
                }
            }
        }

        public bool ValidateLogIn(string userName, string password, IObserver observer)
        {
            InitializeConnection();
            IRequest request = new SimpleRequest(RequestType.LOGIN, new User(userName, password));
            var req = (SimpleRequest)request;
            var data = req.GetData();
            Console.WriteLine("Created simple Request " + data.ToString());

            SendRequest(request);
            IResponse response = ReadResponse();
            if(response.GetResponseType() == ResponseType.OK)
            {
                this.observer = observer;
                return true;
            }
            else
            {
                CloseConnection();
            }
            return false;
        }

        public List<DTOConcert> GetConcertDtos()
        {
            List<DTOConcert> concerts = null;
            IRequest request = new SimpleRequest(RequestType.INIT);
            SendRequest(request);
            IResponse response = ReadResponse();
            if(response.GetResponseType() == ResponseType.OK)
            {
                concerts = (List<DTOConcert>)response.GetData();
            }
            return concerts;
        }

        public List<DTOConcert> GetDTOsByDate(DateTime date)
        {
            List<DTOConcert> concerts = null;
            IRequest request = new SimpleRequest(RequestType.FILTER, date);
            SendRequest(request);
            IResponse response = ReadResponse();
            if(response.GetResponseType() == ResponseType.OK)
            {
                concerts = (List<DTOConcert>)response.GetData();
            }

            return concerts;
        }

        public Ticket SellTicket(int concId, string clName, DateTime date, int tickNum)
        {
            IRequest request = new ComplexRequest(RequestType.UPDATE, concId, clName, date, tickNum);
            SendRequest(request);
            IResponse response = ReadResponse();
            if(response.GetResponseType() == ResponseType.ERROR)
            {

            }
            return (Ticket)response.GetData();
        }


        public Concert FindConcert(int concId)
        {
            IRequest request = new SimpleRequest(RequestType.FIND);
            SendRequest(request);
            IResponse response = ReadResponse();

            return (Concert)response.GetData();
        }
    }
}
