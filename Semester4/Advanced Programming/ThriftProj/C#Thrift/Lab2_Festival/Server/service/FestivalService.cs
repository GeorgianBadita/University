using Common.service;
using Common.utils.observer;
using Lab2_Festival.domain.entities;
using Lab2_Festival.repository;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Thrift.Protocol;
using Thrift.Transport;
using UpdateClient;

namespace Lab2_Festival.service
{
    public class FestivalService: THRIFTService.Iface,IObservable
    {
        private readonly ICRUDRepository<int, Location> _locRepo;
        private readonly ICRUDRepository<int, Artist> _artistRepo;
        private readonly ICRUDRepository<int, Concert> _concertRepo;
        private readonly ICRUDRepository<int, Ticket> _ticketRepo;
        private readonly ICRUDRepository<int, User> _userRepo;
        IDictionary<string, IObserver> users;
        private List<UpdateService.Client> updateClients;

        public FestivalService(ICRUDRepository<int, Location> locRepo,
                               ICRUDRepository<int, Artist> artistRepo,
                               ICRUDRepository<int, Concert> concertRepo,
                               ICRUDRepository<int, Ticket> ticketRepo,
                               ICRUDRepository<int, User> userRepo)
        {
            this._artistRepo = artistRepo;
            this._locRepo = locRepo;
            this._ticketRepo = ticketRepo;
            this._concertRepo = concertRepo;
            this._userRepo = userRepo;
            users = new ConcurrentDictionary<string, IObserver>();
            this.updateClients = new List<UpdateService.Client>();
        }

        public IEnumerable<Location> GetAllLocations()
        {
            return _locRepo.FindAll(); 
        }

        public IEnumerable<Artist> GetAllArtists()
        {
            return _artistRepo.FindAll();
        }

        public IEnumerable<Concert> GetAllConcerts()
        {
            return _concertRepo.FindAll();
        }

        
        public IEnumerable<Ticket> GetAllTickets()
        {
            return _ticketRepo.FindAll();
        }



       

        public IEnumerable<User> GetAllUsers()
        {
            return this._userRepo.FindAll();
        }

        public void Notify()
        {
            users.AsEnumerable().ToList().ForEach((pair) =>
            {
                pair.Value.ReloadObserver();
                Console.WriteLine("Updating user: " + pair.Key);
            });
        }

    

        public bool validateLogIn(string userName, string password, int port)
        {
            bool correctLogin = false;

            foreach (var user in this.GetAllUsers())
            {
                if (user.Name.Equals(userName) && user.Password.Equals(password))
                {
                    correctLogin = true;
                    TTransport transport = new TSocket("localhost", port);
                    transport.Open();
                    TProtocol protocol = new TBinaryProtocol(transport);
                    UpdateClient.UpdateService.Client client = new UpdateClient.UpdateService.Client(protocol);
                    this.updateClients.Add(client);
                    Console.WriteLine("Received update client on port " + port);
                    break;
                }
            }

            
            return correctLogin;
        }

        public void sendUpdateNotification()
        {
            foreach (var client in this.updateClients)
            {
                try
                {
                    Console.WriteLine("Sending update to " + client);
                    client.update();
                    Console.WriteLine("Done sending update");
                }
                catch (Exception e)
                {
                    //Console.Write(e.Message);
                }
            }
        }

        public Concert findConcert(int concert)
        {
            return _concertRepo.FindOne(concert);
        }

        public Ticket sellTicket(int concert, string clientName, string now, int numSeats)
        {   
         
            var ticketId = _ticketRepo.Size() + 1;
            var conc = _concertRepo.FindOne(concert);
            conc.SeatsSold += numSeats;
            _concertRepo.Update(conc);
            
            sendUpdateNotification();
            //return _ticketRepo.Save(new Ticket(ticketId, concert, clientName, now.ToString(), numSeats));
            return null;
        }

        public bool canSellTicket(int concId, int numTickets)
        {
            Location location = null;
            Concert concert = null;
            foreach (Concert conc in this.GetAllConcerts())
            {
                if (conc.Id.Equals(concId))
                {
                    concert = conc;
                    break;
                }
            }

            if (concert == null)
            {
                return false;
            }

            foreach (var loc in this.GetAllLocations())
            {
                if (loc.Id.Equals(concert.LocationId))
                {
                    location = loc;
                    break;
                }
            }

            if (location == null)
            {
                return false;
            }

            return numTickets <= location.TotalSeats - concert.SeatsSold;
        }

        public List<DTOConcert> getConcertDtosByDate(string dateFilter)
        {
            List<DTOConcert> dtos = getConcertDtos();
            List<DTOConcert> fltrDtos = new List<DTOConcert>();
            foreach (var dto in dtos)
            {
                DateTime date = Convert.ToDateTime(dateFilter);
                DateTime dtoDate = Convert.ToDateTime(dto.Date);
                
                if(dtoDate.Date.Month.Equals(date.Date.Month) && dtoDate.Date.Day.Equals(date.Date.Day))
                {
                    fltrDtos.Add(dto);
                }
            }
            return fltrDtos;
        }

        public List<DTOConcert> getConcertDtos()
        {
            List<DTOConcert> dTOConcerts = new List<DTOConcert>();
            List<Concert> concerts = new List<Concert>();

            concerts = _concertRepo.FindAll().ToList();
            concerts.Sort((x, y) =>
            {
                if (x.ArtistId < y.ArtistId)
                {
                    return -1;
                }
                return 1;
            }
            );

            foreach (var concert in concerts)
            {
                var concertID = concert.Id;
                string artistName = null;
                string date = concert.Date;
                string locationName = null;
                int numOfSeats = 0;
                var soldSeats = concert.SeatsSold;
                foreach (var artist in _artistRepo.FindAll())
                {
                    if (artist.Id == concert.ArtistId)
                    {
                        artistName = artist.ArtistName;
                        break;
                    }
                }

                foreach (var location in _locRepo.FindAll())
                {
                    if (location.Id == concert.LocationId)
                    {
                        locationName = location.LocName;
                        numOfSeats = location.TotalSeats;
                        break;
                    }
                }
                dTOConcerts.Add(new DTOConcert(concertID, artistName, date, locationName, numOfSeats, soldSeats, numOfSeats - soldSeats));
            }
            foreach(DTOConcert dto in dTOConcerts)
            {
                Console.WriteLine(dto);
            }
            return dTOConcerts;
        }

        public Concert updateConcert(Concert conc)
        {
            return _concertRepo.Update(conc);
        }



        

        public void notifyClients()
        {
            
        }
    }
}
