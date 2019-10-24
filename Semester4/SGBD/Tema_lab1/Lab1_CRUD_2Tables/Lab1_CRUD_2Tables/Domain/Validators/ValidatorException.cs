using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Validators
{
    class ValidatorException : Exception
    {
        /// <summary>
        /// Constructor for Validator exception class
        /// </summary>
        /// <param name="err">error to be printed</param>
        public ValidatorException(string err):base(err){

        }
    }
}
