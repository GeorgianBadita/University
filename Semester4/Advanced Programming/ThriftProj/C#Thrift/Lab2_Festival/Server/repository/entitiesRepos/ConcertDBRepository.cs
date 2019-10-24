using Lab2_Festival.domain.entities;
using Lab2_Festival.domain.validators;
using Lab2_Festival.repository.dbUtils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository.entitiesRepos
{
    public class ConcertDBRepository : ICRUDRepository<int, Concert>
    {
        private readonly IValidator<Concert> _validator;
        private readonly IDictionary<string, string> _props;
        private IDictionary<string, string> props;
        private ConcertValidator concertValidator;

        public ConcertDBRepository(IDictionary<string, string> props, IValidator<Concert> validator)
        {
            this._validator = validator;
            this._props = props;
        }

        public ConcertDBRepository(IDictionary<string, string> props, ConcertValidator concertValidator)
        {
            this.props = props;
            this.concertValidator = concertValidator;
        }

        public Concert Delete(int id)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<Concert> FindAll()
        {
            IList<Concert> concerts = new List<Concert>();
            var conn = DBUtil.GetConnection(_props);

            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "select * from concert";

                using(var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        int concertId = dataR.GetInt32(0);
                        int locationId = dataR.GetInt32(1);
                        int artistId = dataR.GetInt32(2);
                        DateTime date = dataR.GetDateTime(3);
                        ConcertType type = (ConcertType)Enum.Parse(typeof(ConcertType), dataR.GetString(4));
                        int soldSeats = dataR.GetInt32(5);
                        
                        concerts.Add(new Concert(concertId, locationId, artistId, date.ToString("MM/dd/yyyy"), type, soldSeats));
                    }
                }
            }

            return concerts;
        }

        public Concert FindOne(int id)
        {
            var all = this.FindAll();
            foreach(Concert conc in all)
            {
                if(conc.Id == id)
                {
                    return conc;
                }
            }
            return null;
        }

        public Concert Save(Concert e)
        {
            throw new NotImplementedException();
        }

        public int Size()
        {
            throw new NotImplementedException();
        }

        public Concert Update(Concert e)
        {
            var con = DBUtil.GetConnection(_props);
            var concert = FindOne(e.Id);
            if (concert == null)
            {
                return null;
            }

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update concert set locationId=@locationId, artistId=@artistId, date=@date, type=@type, seatsSold=@seatsSold where concertId=@id";
                var locationId = comm.CreateParameter();
                locationId.ParameterName = "@locationId";
                locationId.Value = e.LocationId;
                comm.Parameters.Add(locationId);

                var artistId = comm.CreateParameter();
                artistId.ParameterName = "@artistId";
                artistId.Value = e.ArtistId;
                comm.Parameters.Add(artistId);

                var date = comm.CreateParameter();
                date.ParameterName = "@date";
                date.Value = Convert.ToDateTime(e.Date);
                comm.Parameters.Add(date);

                var type = comm.CreateParameter();
                type.ParameterName = "@type";
                type.Value = e.Type;
                comm.Parameters.Add(type);

                var seats = comm.CreateParameter();
                seats.ParameterName = "@seatsSold";
                seats.Value = e.SeatsSold;
                comm.Parameters.Add(seats);

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
