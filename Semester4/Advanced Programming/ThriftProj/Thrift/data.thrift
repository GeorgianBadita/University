
namespace java org.geo.festival
namespace csharp Lab2_Festival


enum ConcertType{
    ROCK=1,
    POP=2,
    TECHNO=3,
    HOUSE=4
}

struct DTOConcert{
    1: i32 concertId
    2: string artistName
    3: string date
    4: string locationName
    5: i32 numOfSeats
    6: i32 soldSeats
    7: i32 freeSeats
}

struct Concert{
    1: i32 id
    2: i32 locationId
    3: i32 artistId
    4: string date
    5: ConcertType type
    6: i32 seatsSold
}

struct Ticket{
    1: i32 id
    2: i32 concertId
    3: string clientName
    4: string buyDate
    5: i32 numOfSeats
}

service THRIFTService{
    bool validateLogIn(1: string userName, 2: string password, 3: i32 port)
    Concert findConcert(1: i32 concert)
    Ticket sellTicket(1: i32 concert, 2:string clientName, 3: string now, 4: i32 numSeats)
    bool canSellTicket(1: i32 concId, 2: i32 numTickets) 
    list<DTOConcert> getConcertDtosByDate(1: string dateFilter)
    list<DTOConcert> getConcertDtos() 
    Concert updateConcert(1: Concert conc)
    void notifyClients()
}
