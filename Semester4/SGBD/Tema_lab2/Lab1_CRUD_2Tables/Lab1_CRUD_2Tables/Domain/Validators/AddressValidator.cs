using Lab1_CRUD_2Tables.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Validators
{
    class AddressValidator : IValidator<Address>
    {
        /// <summary>
        /// Function to validate an Address
        /// </summary>
        /// <param name="entity">address object to be validated</param>
        public void Validate(Address entity)
        {
            var errors = "";
            if(entity.Id < 0)
            {
                errors += "Id of the address must be a positive!\n";
            }
            if(entity.City.Length > 50 || entity.City.Length == 0)
            {
                errors += "City length must be between 0 and 50\n";
            }
            if(entity.Street.Length == 50 || entity.Street.Length == 0)
            {
                errors += "Street length must be between 0 and 50\n";
            }
            if(entity.Number < 0)
            {
                errors += "Number must be a positive integer!\n";
            }
            if(errors.Length > 0)
            {
                throw new ValidatorException(errors);
            }
        }
    }
}
