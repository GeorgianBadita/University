using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Validators
{
    class IllegalArgumentException : Exception
    {

        /// <summary>
        /// Constructor for IllegalArgumentException class
        /// </summary>
        /// <param name="err">error to be thrown</param>
        public IllegalArgumentException(string err): base(err)
        {

        }

    }
}
