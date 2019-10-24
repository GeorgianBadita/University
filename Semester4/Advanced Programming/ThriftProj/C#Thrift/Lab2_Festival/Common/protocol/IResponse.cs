using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.protocol
{
    
    public interface IResponse
    {
        object GetData();
        ResponseType GetResponseType();
    }
}
