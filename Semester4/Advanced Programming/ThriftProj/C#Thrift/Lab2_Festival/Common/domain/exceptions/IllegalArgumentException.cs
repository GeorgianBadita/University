using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.exceptions
{
    /// <summary>
    /// Exception for illegal argument
    /// </summary>
    public class IllegalArgumentException : Exception
    {
        /// <summary>
        /// IllegalArgumentException class constructor
        /// Throws error containing the given string
        /// </summary>
        /// <param name="err">String error to be thrown</param>
        public IllegalArgumentException(string err) : base(err)
        {

        }
    }
}
