using Lab2_Festival.domain.entities;
using Lab2_Festival.domain.validators;
using Lab2_Festival.repository.dbUtils;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository
{
    public class LocationDBRepository : ICRUDRepository<int, Location>
    {
        private readonly  IValidator<Location> _locValidator;
        private readonly IDictionary<string, string> _props;

        /// <summary>
        /// Constructor for LocationDBRepository class
        /// </summary>
        /// <param name="props">properties file</param>
        /// <param name="validator">vlidator for location class</param>
        public LocationDBRepository(IDictionary<string, string> props, IValidator<Location> validator)
        {
            this._locValidator = validator;
            this._props = props;
        }

        public Location Delete(int id)
        {
            IDbConnection con = DBUtil.GetConnection(_props);
            using(var comm = con.CreateCommand())
            {
                var loc = FindOne(id);
                if(loc == null)
                {
                    return null;
                }
                comm.CommandText = "delete from location where locationId=@id";
                IDbDataParameter paramID = comm.CreateParameter();
                paramID.ParameterName = "@id";
                paramID.Value = id;
                comm.Parameters.Add(paramID);
                var dataR = comm.ExecuteNonQuery();
                return loc;
            }

        }

        public IEnumerable<Location> FindAll()
        {
            IDbConnection con = DBUtil.GetConnection(_props);
            IList<Location> locations = new List<Location>();

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select locationId, locationName, totalSeats from location";
                using(var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        int id = dataR.GetInt32(0);
                        string locName = dataR.GetString(1);
                        int numSeats = dataR.GetInt32(2);
                        var loc = new Location(id, locName, numSeats);
                        locations.Add(loc);
                    }
                }
            }
            return locations;
        }

        public Location FindOne(int id)
        {
            IDbConnection con = DBUtil.GetConnection(_props);
            using(var comm = con.CreateCommand())
            {
                comm.CommandText = "select locationId, locationName, totalSeats from location where locationId=@id";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);

                using(var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        int locId = dataR.GetInt32(0);
                        String locName = dataR.GetString(1);
                        int numSeats = dataR.GetInt32(2);
                        Location location = new Location(locId, locName, numSeats);
                        return location;
                    }
                }

                return null;
            }
        }

        public Location Save(Location e)
        {
            var conn = DBUtil.GetConnection(_props);
            _locValidator.Validate(e);
            var loc = FindOne(e.Id);

            if(loc != null)
            {
                return e;
            }

            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "insert into location values (@id, @locName, @numSeats)";
                var locId = comm.CreateParameter();
                locId.ParameterName = "@id";
                locId.Value = e.Id;
                comm.Parameters.Add(locId);

                var locName = comm.CreateParameter();
                locName.ParameterName = "@locName";
                locName.Value = e.LocName;
                comm.Parameters.Add(locName);

                var numSeats = comm.CreateParameter();
                numSeats.ParameterName = "@numSeats";
                numSeats.Value = e.TotalSeats;
                comm.Parameters.Add(numSeats);

                var res = comm.ExecuteNonQuery();
                return null;
            }
        }

        public int Size()
        {
            return FindAll().Count();
        }

        public Location Update(Location e)
        {
            var loc = FindOne(e.Id);
            if(loc == null)
            {
                return null;
            }

            Delete(e.Id);
            return Save(e);
        }
    }
}
