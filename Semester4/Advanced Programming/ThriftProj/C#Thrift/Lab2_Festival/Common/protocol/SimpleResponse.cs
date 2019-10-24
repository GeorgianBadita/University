using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.protocol
{
    [Serializable]
    public class SimpleResponse : IResponse
    {
        private ResponseType responseType;
        private object data;

        public SimpleResponse(ResponseType responseType, object data)
        {
            this.responseType = responseType;
            this.data = data;
        }

        public SimpleResponse(ResponseType responseType)
        {
            this.responseType = responseType;
            data = null;
        }
        
        public object GetData()
        {
            return data;
        }

        public ResponseType GetResponseType()
        {
            return this.responseType;
        }

        public override string ToString()
        {
            if (data == null)
                return "Response: {"
                + " ResponseType: " + responseType.ToString() + " }";
            return "Response: {"
                + " ResponseType: " + responseType.ToString()
                + " Data: " + data.ToString() + "}";
        }
    }
}
