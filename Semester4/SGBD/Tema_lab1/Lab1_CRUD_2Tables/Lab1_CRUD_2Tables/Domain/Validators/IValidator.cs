using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Validators
{
    public interface IValidator<TE>
    {
        /// <summary>
        /// Function to validate the entity E
        /// </summary>
        /// <param name="entity">entity to be validated</param>
        void Validate(TE entity);
    }
}
