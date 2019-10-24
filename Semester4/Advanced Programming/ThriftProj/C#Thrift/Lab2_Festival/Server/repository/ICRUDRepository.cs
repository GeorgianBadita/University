using Lab2_Festival.domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository
{
    /// <summary>
    /// Crud repository interface
    /// </summary>
    /// <typeparam name="ID">ID parameter of the entity</typeparam>
    /// <typeparam name="TE">The actual entity</typeparam>
    public interface ICRUDRepository<ID, TE> where TE : class
    {
        /// <summary>
        /// Function for saving an entity into the database
        /// </summary>
        /// <param name="e">entity to be saved</param>
        /// <returns>Null if the entity was saved, the given entity otherwise</returns>
        /// <exception cref="IllegalArgumentException" >Illegal argument exception if e is null</exception>
        /// <exception cref="ValidatorException" >If the entity is not well formed</exception>
        TE Save(TE e);

        /// <summary>
        /// Function to find an entity from the database
        /// </summary>
        /// <param name="id">id of the searched entity</param>
        /// <returns>the found entity if it exists, null otherwise</returns>
        /// <exception cref="IllegalArgumentException" >Illegal argument exception if id is null</exception>
        TE FindOne(ID id);

        /// <summary>
        /// Function to get all entities from the database
        /// </summary>
        /// <returns>An enumerable containing all the entities from the database</returns>
        IEnumerable<TE> FindAll();

        /// <summary>
        /// Function to delete an entity from the database
        /// </summary>
        /// <param name="id">id of the entity to be deleted</param>
        /// <returns>the deleted entity if it exists, null otherwise</returns>
        /// <exception cref="IllegalArgumentException" >Illegal argument exception if id is null</exception>
        TE Delete(ID id);

        /// <summary>
        /// Function to update an entity
        /// </summary>
        /// <param name="e">new entity, having the same id as the old one</param>
        /// <returns>null if the entity was update, the given entity otherwise</returns>
        /// <exception cref="IllegalArgumentException" >Illegal argument exception if e is null</exception>
        /// <exception cref="ValidatorException" >If the entity is not well formed</exception>
        TE Update(TE e);

        /// <summary>
        /// Function to get the number of entities stored in the database
        /// </summary>
        /// <returns>number of entities stored in the database</returns>
        int Size();
    }
}
