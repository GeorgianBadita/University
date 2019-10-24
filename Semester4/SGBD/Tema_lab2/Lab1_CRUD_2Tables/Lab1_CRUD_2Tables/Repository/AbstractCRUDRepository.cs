using Lab1_CRUD_2Tables.Domain.Entities;
using Lab1_CRUD_2Tables.Domain.Validators;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Lab1_CRUD_2Tables.Repository
{

    public delegate SqlCommand Te2InsCmd<TE>(TE entity, SqlConnection conn);
    public delegate SqlCommand Te2DelCmd<TE>(TE entity, SqlConnection conn);
    public delegate SqlCommand Te2UpdCmd<TE>(TE entity, SqlConnection conn);
    public delegate SqlCommand Te2FindCmd<Tid>(Tid id, SqlConnection conn);

    public abstract class AbstractCRUDRepository<Tid, TE> : IRepository<Tid, TE> where TE : class, IHasID<Tid>
    {
        protected readonly IValidator<TE> _validatr; //entity validaor
        protected readonly string _connString; //connection string for the database
        protected readonly  Te2InsCmd<TE> _funTe2InsCmd;
        protected readonly  Te2DelCmd<TE> _funTe2DelCmd;
        protected readonly  Te2UpdCmd<TE> _funTe2UpdCmd;
        protected readonly Te2FindCmd<Tid> _funTe2FindCmd;


        /// <summary>
        /// Constructor for AbstractCRUDRepository class
        /// </summary>
        /// <param name="val">validator for entities</param>
        /// <param name="connString">connection String to database</param>
        public AbstractCRUDRepository(IValidator<TE> val, string connString, Te2InsCmd<TE> funTe2InsCmd,
                                      Te2DelCmd<TE> funTe2DelCmd, Te2UpdCmd<TE> funTe2UpdCmd, Te2FindCmd<Tid> funTe2FindCmd)
        {
            _validatr = val;
            _connString = connString;
            _funTe2InsCmd = funTe2InsCmd;
            _funTe2DelCmd = funTe2DelCmd;
            _funTe2UpdCmd = funTe2UpdCmd;
            _funTe2FindCmd = funTe2FindCmd;

            SqlConnection sqlConn = new SqlConnection(_connString);
            try
            {
                sqlConn.Open();
                sqlConn.Close();
            }
            catch(Exception)
            {
                throw new ValidatorException("Could not establish the connection!");
            }
        }

        /// <summary>
        /// Function to find an element into the repository
        /// </summary>
        /// <param name="id">id of the element to be found</param>
        /// <returns>true if the entity exists, false otherwise/returns>
        public bool FindOne(Tid id)
        {
            if(id == null)
            {
                throw new IllegalArgumentException("Entity id can't be null!");
            }

            using(SqlConnection sqlConn = new SqlConnection(this._connString))
            {
                var cmd = _funTe2FindCmd(id, sqlConn);
                int result = cmd.ExecuteNonQuery();
                return result > 0 ? true : false;
            
            }
        }

        /// <summary>
        /// Function to get all elements of the repository as Enumerable
        /// </summary>
        /// <returns>Enumerable containing all the elements from the repositor</returns>
        public IEnumerable<TE> FindAll()
        {
            return null;
        }

        /// <summary>
        /// Function to save an entity into the repository
        /// </summary>
        /// <param name="entity">entity to be saved</param>
        /// <returns>null if the entity was saved, the given entity otherwise</returns>
        public TE Save(TE entity)
        {
           if(entity == null)
            {
                throw new IllegalArgumentException("Entity can't be null!");
            }
            if (FindOne(entity.Id))
            {
                return entity;
            }
            _validatr.Validate(entity);
            using(SqlConnection sqlConn = new SqlConnection(this._connString))
            {
                var cmd = _funTe2InsCmd(entity, sqlConn);
                int rowsAffected = cmd.ExecuteNonQuery();
                sqlConn.Close();
                if (rowsAffected != 0)
                {
                    return null;
                }
                return entity;
            }
        }

        /// <summary>
        /// Function to delete an entity from the repository
        /// </summary>
        /// <param name="id">id of the entity to be deleted</param>
        /// <returns>the deleted entity if it could be deleted, null otherwise</returns>
        public TE Delete(Tid id)
        {
            if(id == null)
            {
                throw new IllegalArgumentException("Entity can't be null!");
            }
            return null;
        }

        /// <summary>
        /// Function to update an entity from the repository
        /// </summary>
        /// <param name="entity">updated entity</param>
        /// <returns>null if the entity was udpated, the given entity otherwise</returns>
        public TE Update(TE entity)
        {
            return null;
        }
    }
}
