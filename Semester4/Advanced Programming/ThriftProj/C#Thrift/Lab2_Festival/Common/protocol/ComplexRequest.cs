using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.protocol
{
    [Serializable]
    public class ComplexRequest : IRequest
    {
        private List<object> data;
        private RequestType requestType;

        public ComplexRequest(RequestType requestType, params object[] data)
        {
            this.data = new List<object>(data);
            this.requestType = requestType;
        }

        public ComplexRequest(RequestType requestType)
        {
            this.data = null;
            this.requestType = requestType;
        }

        public object GetData()
        {
            return this.data;
        }

        public RequestType GetRequestType()
        {
            return this.requestType;
        }

        public override string ToString()
        {
            if (data == null)
                return "ComplexRequest: {"
                    + " RequestType: " + requestType.ToString() + "}";
            return "ComplexRequest: {"
                + " RequestType: " + requestType.ToString()
                + " Data: " + data.ToString() + "}";
        }
    }
}
