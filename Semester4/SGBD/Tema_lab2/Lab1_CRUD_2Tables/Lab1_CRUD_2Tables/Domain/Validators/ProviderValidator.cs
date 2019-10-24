using Lab1_CRUD_2Tables.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Validators
{
    class ProviderValidator : IValidator<Provider>
    {
        /// <summary>
        /// Function to validate a provider entity
        /// </summary>
        /// <param name="entity">provider object to be verified</param>
        public void Validate(Provider entity)
        {
            var errors = "";
            if (entity.Id < 0)
            {
                errors += "Provider id must be a positive integer!\n";
            }
            if (entity.Name.Length > 50 || entity.Name.Length == 0)
            {
                errors += "Provider name must have a length between 0 and 50\n";
            }
            if(entity.Quant < 0)
            {
                errors += "Provider quantity must be a positive integer!\n";
            }
            if(entity.IdAddr < 0)
            {
                errors += "Provider address Id must be a positive integer!\n";
            }

        }
    }
}
