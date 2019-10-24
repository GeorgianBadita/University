using System.IO;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;

namespace StudentsManagementApp.repository
{
	public delegate TE String2Te<TE>(string s);

	public delegate string Te2String<TE>(TE entity);
	
	public class StorageRepository<TId, TE> : AbstractRepository<TId, TE> where TE : class, IHasId<TId>
	{

		private readonly string _fileName;
		private readonly String2Te<TE> _funS2Te;
		private readonly Te2String<TE> _funTe2S;

		/// <inheritdoc />
		/// <summary>
		/// Constructor for StorageRepository class
		/// </summary>
		/// <param name="val">Validator for TE entity</param>
		/// <param name="funTe2S">Function to get string form of entity</param>
		/// <param name="funS2Te">Function to get element from string</param>
		/// <param name="fileName">path to the file where we'll store entities</param>
		public StorageRepository(IValidator<TE> val, Te2String<TE> funTe2S, String2Te<TE> funS2Te, string fileName) : base(val)
		{
			this._funTe2S = funTe2S;
			this._funS2Te = funS2Te;
			_fileName = fileName;
			ReadFromFile();
		}

		/// <summary>
		/// Function to read all entities from the file
		/// </summary>
		private void ReadFromFile()
		{
			using (TextReader tr = File.OpenText(_fileName))
			{
				string line;
				while ((line = tr.ReadLine()) != null)
				{
					var entity = _funS2Te(line);
					if (entity != null)
					{
						base.Save(entity);	
					}
					
				}
			}
		}

		/// <summary>
		/// Function to store entities to the file
		/// </summary>
		private void StoreToFile()
		{
			using (var sw = new StreamWriter(_fileName))
			{
				foreach (var entity in FindAll())
				{
					sw.WriteLine(_funTe2S(entity));
				}
			}
		}
		

		/// <summary>
		/// Overriding Save method for files
		/// </summary>
		/// <param name="entity">entity to be saved</param>
		/// <returns></returns>
		public override TE Save(TE entity)
		{
			var saved = base.Save(entity);
			if (saved == null)
			{
				StoreToFile();
			}

			return saved;
		}


		/// <summary>
		/// Overriding Delete method for files
		/// </summary>
		/// <param name="id">id of the entity to be deleted</param>
		/// <returns></returns>
		public override TE Delete(TId id)
		{
			var deleted = base.Delete(id);
			if (deleted != null)
			{
				StoreToFile();
			}

			return deleted;
		}

		/// <summary>
		/// Overriding Update method for files
		/// </summary>
		/// <param name="entity">entity to be updated</param>
		/// <returns></returns>
		public override TE Update(TE entity)
		{
			var updated = base.Update(entity);
			if (updated == null)
			{
				StoreToFile();
			}

			return updated;
		}
	}

}