using Lab2_Festival.domain.entities;
using Lab2_Festival.domain.validators;
using Lab2_Festival.repository.dbUtils;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository.entitiesRepos
{
    public class ArtistDBRepository : ICRUDRepository<int, Artist>
    {
        private readonly IValidator<Artist> _artistValidator;
        private readonly IDictionary<string, string> _props;

        /// <summary>
        /// Constructor for ArtistDBRepository class
        /// </summary>
        /// <param name="props">properties file</param>
        /// <param name="validator">validator for artist class</param>
        public ArtistDBRepository(IDictionary<string, string> props, IValidator<Artist> validator)
        {
            this._props = props;
            this._artistValidator = validator;
        }

        public Artist Delete(int id)
        {
            IDbConnection con = DBUtil.GetConnection(_props);

            using(var comm = con.CreateCommand())
            {
                var artist = FindOne(id);
                if(artist == null)
                {
                    return null;
                }

                comm.CommandText = "delete from artist where artistId=@id";

                var paramID = comm.CreateParameter();
                paramID.ParameterName = "@id";
                paramID.Value = id;
                comm.Parameters.Add(paramID);
                var dataR = comm.ExecuteNonQuery();
                return artist;
            }
        }

        public IEnumerable<Artist> FindAll()
        {
            IList<Artist> lst = new List<Artist>();
            var conn = DBUtil.GetConnection(_props);
            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "select artistId, artistName from artist";

                using(var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        int artistId = dataR.GetInt32(0);
                        string artistName = dataR.GetString(1);
                        lst.Add(new Artist(artistId, artistName));
                    }
                }
            }

            return lst;
        }

        public Artist FindOne(int id)
        {
            var con = DBUtil.GetConnection(_props);
            using(var comm = con.CreateCommand())
            {
                comm.CommandText = "select artistId, artistName from artist where artistId=@id";
                var paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);

                using(var datR = comm.ExecuteReader())
                {
                    if (datR.Read())
                    {
                        int artistId = datR.GetInt32(0);
                        string artistName = datR.GetString(1);
                        return new Artist(artistId, artistName);
                    }
                }
            }
            return null;
        }

        public Artist Save(Artist e)
        {
            var conn = DBUtil.GetConnection(_props);
            _artistValidator.Validate(e);
            var artist = FindOne(e.Id);
            if(artist != null)
            {
                return e;
            }

            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "insert into artist values(@id, @artistName)";

                var artistId = comm.CreateParameter();
                artistId.ParameterName = "@id";
                artistId.Value = e.Id;
                comm.Parameters.Add(artistId);

                var artistName = comm.CreateParameter();
                artistName.ParameterName = "@artistName";
                artistName.Value = e.ArtistName;
                comm.Parameters.Add(artistName);

                var res = comm.ExecuteNonQuery();

                return null;
      
            }
        }

        public int Size()
        {
            return FindAll().Count();
        }

        public Artist Update(Artist e)
        {
            var con = DBUtil.GetConnection(_props);
            var artist = FindOne(e.Id);
            if(artist == null)
            {
                return null;
            }

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update artist set artistName=@artistName where artistId=@id";
                var artistName = comm.CreateParameter();
                artistName.ParameterName = "@artistName";
                artistName.Value = e.ArtistName;
                comm.Parameters.Add(artistName);

                var id = comm.CreateParameter();
                id.ParameterName = "@id";
                id.Value = e.Id;
                comm.Parameters.Add(id);
                var res = comm.ExecuteNonQuery();
                return null;
            }
        }
    }
}
