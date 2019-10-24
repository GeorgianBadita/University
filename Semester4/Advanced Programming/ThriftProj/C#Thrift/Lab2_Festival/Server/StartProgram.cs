using Common.service;
using Lab2_Festival;
using Lab2_Festival.domain.validators;
using Lab2_Festival.repository;
using Lab2_Festival.repository.entitiesRepos;
using Lab2_Festival.service;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Thrift.Server;
using Thrift.Transport;

namespace Server
{
    class StartProgram
    {
        [STAThread]
        static void Main()
        {
            IDictionary<string, string> props = new SortedList<string, string>();
            props.Add("ConnectionString", GetConnectionStringByName("festivalDB"));

            Console.WriteLine(GetConnectionStringByName("festivalDB"));
            FestivalService festivalService = GetFestivalService(props);

            THRIFTService.Processor processor = new THRIFTService.Processor(festivalService);

            TServerTransport serverTransport = new TServerSocket(9095);

            TServer server = new TThreadedServer(processor, serverTransport);

            server.Serve();

        }

        private static FestivalService GetFestivalService(IDictionary<string, string> props)
        {
            var artistRepo = new ArtistDBRepository(props, new ArtistValidator());
            var concertRepo = new ConcertDBRepository(props, new ConcertValidator());
            var locationRepo = new LocationDBRepository(props, new LocationValidator());
            var ticketRepo = new TicketDBRepository(props, new TicketValidator());
            var userRepo = new UserDBRepository(props, new UserValidator());
            return new FestivalService(locationRepo, artistRepo, concertRepo, ticketRepo, userRepo);
        }

        static string GetConnectionStringByName(string name)
        {
            string retValue = null;

            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[name];

            if (settings != null)
            {
                retValue = settings.ConnectionString;
            }
            return retValue;
        }
    }
}

