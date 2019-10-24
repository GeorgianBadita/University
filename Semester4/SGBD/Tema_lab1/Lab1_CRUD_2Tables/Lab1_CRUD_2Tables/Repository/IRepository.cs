using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Repository
{
    /// <summary>
    /// Repository interface
    /// </summary>
    interface IRepository<TId, TE>
    {
        /// <summary>
        /// Function to find an element into the repository
        /// </summary>
        /// <param name="id">id of the element to be found</param>
        /// <returns>true if the entity exists, false otherwise</returns>
        bool FindOne(TId id);

        /// <summary>
        /// Function to get all elements of the repository as Enumerable
        /// </summary>
        /// <returns>Enumerable containing all the elements from the repositor</returns>
        IEnumerable<TE> FindAll();

        /// <summary>
        /// Function to save an entity into the repository
        /// </summary>
        /// <param name="entity">entity to be saved</param>
        /// <returns>null if the entity was saved, the given entity otherwise</returns>
        TE Save(TE entity);

        /// <summary>
        /// Function to delete an entity from the repository
        /// </summary>
        /// <param name="id">id of the entity to be deleted</param>
        /// <returns>the deleted entity if it could be deleted, null otherwise</returns>
        TE Delete(TId id);

        /// <summary>
        /// Function to update an entity from the repository
        /// </summary>
        /// <param name="entity">updated entity</param>
        /// <returns>null if the entity was udpated, the given entity otherwise</returns>
        TE Update(TE entity);
    }
}
