using System.Collections.Generic;
using System.Linq;

namespace StudentsManagementApp.repository
{
	/// <summary>
	/// CRUD operations repository interface
	/// </summary>
	/// <typeparam name="TId"> TE must have an attribute of type TId</typeparam>
	/// <typeparam name="TE">Type of elements saved in Repository</typeparam>
	public interface ICrudRepository<TId, TE>
	{
		/// <summary>
		/// Function to find an element into the repository
		/// </summary>
		/// <param name="id">id of the entity to be returned</param>
		/// <returns>The element if it exists, null otherwise</returns>
		TE FindOne(TId id);

		/// <summary>
		/// Function to get all elements of the repository as Enumerable
		/// </summary>
		/// <returns>Enumerable containing all entities from the repository</returns>
		IEnumerable<TE> FindAll();

		/// <summary>
		/// Function to save an entity to the repository
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
		/// <param name="entity">new entity</param>
		/// <returns>null if the entity was updated, the given entity otherwise</returns>
		TE Update(TE entity);
	}
}