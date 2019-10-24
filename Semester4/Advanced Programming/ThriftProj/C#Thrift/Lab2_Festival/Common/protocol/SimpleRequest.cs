using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.protocol
{
    [Serializable]
    public class SimpleRequest : IRequest
    {
        private RequestType requestType;
        private object data;

        public SimpleRequest(RequestType requestType)
        {
            this.requestType = requestType;
            this.data = null;
        }

        public SimpleRequest(RequestType requestType, object data)
        {
            this.requestType = requestType;
            this.data = data;
        }

        public RequestType GetRequestType()
        {
            return this.requestType;
        }

        public object GetData()
        {
            return this.data;
        }

        public override string ToString()
        {
            if (data == null)
                return "Request: {"
                    + " RequestType: " + requestType.ToString() + "}";
                return "Request: {"
                    + " RequestType: " + requestType.ToString()
                    + " Data: " + data.ToString() + "}";
        }
    }
}
