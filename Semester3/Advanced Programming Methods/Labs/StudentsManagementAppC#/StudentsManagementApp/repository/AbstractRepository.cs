using System;
using System.Collections.Generic;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;

namespace StudentsManagementApp.repository
{
	public abstract class AbstractRepository<TId, TE>: ICrudRepository<TId, TE> where TE : class, IHasId<TId>
	{
		private readonly IValidator<TE> _validator;
		private readonly IDictionary<TId, TE> _map;

		/// <summary>
		/// Constructor for AbstractRepository class
		/// </summary>
		/// <param name="val">validator for TE entity</param>
		protected AbstractRepository(IValidator<TE> val)
		{
			_validator = val;
			_map = new Dictionary<TId, TE>();
		}
		
		public TE FindOne(TId id)
		{
			if (id == null)
			{
				throw new IllegalArgumentException("Id can't be null!");
			}
			return _map.ContainsKey(id) ? _map[id] : null;
		}

		public IEnumerable<TE> FindAll()
		{
			return _map.Values;
		}

		public virtual TE Save(TE entity)
		{
			if (entity == null)
			{
				throw new IllegalArgumentException("Entity can't be null");
			}
			_validator.Validate(entity);
			if (_map.ContainsKey(entity.Id))
			{
				return entity;
			}
			
			_map.Add(entity.Id, entity);
			//Console.WriteLine(entity);
			return null;
		}

		public virtual TE Delete(TId id)
		{
			if (id == null)
			{
				throw new IllegalArgumentException("Id can't be null!");
			}
			var found = FindOne(id);

			if (found != null)
			{
				_map.Remove(id);
			}

			return found;
		}

		public virtual TE Update(TE entity)
		{
			if (entity == null)
			{
				throw new IllegalArgumentException("Entity can't be null");
			}
			var found = FindOne(entity.Id);

			if (found == null)
			{
				return entity;
			}

			_map[entity.Id] = entity;
			return null;
		}
	}
}