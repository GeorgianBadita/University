using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.exceptions
{
    /// <summary>
    /// Class for ValidatorException
    /// </summary>
    class ValidatorException : Exception
    {
        /// <summary>
        /// Constructor for ValidatorException
        /// </summary>
        /// <param name="err">String error to be thrown</param>
        public ValidatorException(string err): base(err)
        {

        }
    }
}
