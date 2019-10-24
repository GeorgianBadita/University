using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.utils.observer
{
    public interface IObservable
    {
        void Notify();
    }
}
