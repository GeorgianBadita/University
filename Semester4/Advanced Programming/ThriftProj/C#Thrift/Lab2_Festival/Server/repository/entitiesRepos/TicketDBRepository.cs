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
    public class TicketDBRepository : ICRUDRepository<int, Ticket>
    {
        private readonly IValidator<Ticket> _validator;
        private readonly IDictionary<string, string> _props;
        private IDictionary<string, string> props;
        private TicketValidator ticketValidator;

        public TicketDBRepository(IDictionary<string, string> props, IValidator<Ticket> validator) 
        {
            this._props = props;
            this._validator = validator;
        }

        public TicketDBRepository(IDictionary<string, string> props, TicketValidator ticketValidator)
        {
            this.props = props;
            this.ticketValidator = ticketValidator;
        }

        public Ticket Delete(int id)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<Ticket> FindAll()
        {
            IList<Ticket> tickets = new List<Ticket>();

            var conn = DBUtil.GetConnection(_props);

            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "select * from ticket";

                using(var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        int ticketId = dataR.GetInt32(0);
                        int concertId = dataR.GetInt32(1);
                        string clientName = dataR.GetString(2);
                        DateTime buyDate = dataR.GetDateTime(3);
                        int numOfSeats = dataR.GetInt32(4);
                        
                        tickets.Add(new Ticket(ticketId, concertId, clientName, buyDate.ToString("MM/dd/yyyy"), numOfSeats));
                    }
                }
            }
            return tickets;
        }

        public Ticket FindOne(int id)
        {
            var con = DBUtil.GetConnection(_props);
            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "select ticketId, concertId, clientName, buyDate, numOfSeats from ticket where ticketId=@id";
                var paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);

                using (var datR = comm.ExecuteReader())
                {
                    if (datR.Read())
                    {
                        int ticketId = datR.GetInt32(0);
                        int concertId = datR.GetInt32(1);
                        string clientName = datR.GetString(2);
                        var date = datR.GetDateTime(3);
                        var numOfSeats = datR.GetInt32(4);
                        //TODO change this
                        
                        return new Ticket(ticketId, concertId, clientName, date.ToString("MM/dd/yyyy"), numOfSeats);
                       
                    }
                }
            }
            return null;
        }

        public Ticket Save(Ticket e)
        {
            var conn = DBUtil.GetConnection(_props);
     
            var artist = FindOne(e.Id);
            if (artist != null)
            {
                return e;
            }

            using (var comm = conn.CreateCommand())
            {
                comm.CommandText = "insert into ticket values(@id, @concertId, @clientName, @buyDate, @numOfSeats)";

                var tickId = comm.CreateParameter();
                tickId.ParameterName = "@id";
                tickId.Value = e.Id;
                comm.Parameters.Add(tickId);


                var concId = comm.CreateParameter();
                concId.ParameterName = "@concertId";
                concId.Value = e.ConcertId;
                comm.Parameters.Add(concId);

                var clName = comm.CreateParameter();
                clName.ParameterName = "@clientName";
                clName.Value = e.ClientName;
                comm.Parameters.Add(clName);

                var buyDate = comm.CreateParameter();
                buyDate.ParameterName = "@buyDate";
                buyDate.Value = Convert.ToDateTime(e.BuyDate);
                comm.Parameters.Add(buyDate);

                var numSeats = comm.CreateParameter();
                numSeats.ParameterName = "numOfSeats";
                numSeats.Value = e.NumOfSeats;
                comm.Parameters.Add(numSeats);


                var res = comm.ExecuteNonQuery();

                return null;

            }
        }

        public int Size()
        {
            var nrTickets = 0;
            var conn = DBUtil.GetConnection(_props);
            using (var comm = conn.CreateCommand())
            {
                comm.CommandText = "select * from ticket";

                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        nrTickets++;
                    }
                }
            }

            return nrTickets;
        }

        public Ticket Update(Ticket e)
        {
            throw new NotImplementedException();
        }
    }
}
