using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.validators
{
    /// <summary>
    /// Validator interface
    /// </summary>
    /// <typeparam name="TE">entity for validator</typeparam>
    public interface IValidator<TE>
    {
        /// <summary>
        /// Function to validate an entity 
        /// </summary>
        /// <param name="Entity">entity to be validated</param>
        void Validate(TE Entity);
    
    }
}
