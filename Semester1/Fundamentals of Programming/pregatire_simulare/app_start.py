"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 23:07
"""
from domain.validators import ClientValidator, CarValidator, RentalValidator
from repository.car_file_repo import CarFileRepository
from repository.car_repository import CarRepository
from repository.client_file_repo import ClientFileRepository
from repository.client_repository import ClientRepository
from repository.rental_file_repo import RentalFileRepository
from repository.rental_repository import RentalRepository
from services.car_service import CarService
from services.client_service import ClientService
from services.rental_service import RentalService
from ui.user_interface import UI

'''
The module where our application will start
'''

cl_val = ClientValidator()
car_val = CarValidator()
rt_val = RentalValidator()

#cl_rep = ClientRepository(cl_val)
cl_rep_file = ClientFileRepository("clients.txt")
#car_rep = CarRepository(car_val)
car_rep_file = CarFileRepository("cars.txt")
car_rep_file.remove_all()
#rt_rep = RentalRepository(rt_val)
rt_rep_file = RentalFileRepository("rentals.txt")
rt_rep_file.remove_all()

cl_serv = ClientService(cl_rep_file)
car_serv = CarService(car_rep_file)
rt_serv = RentalService(rt_rep_file, cl_rep_file, car_rep_file)


ui = UI(car_serv, cl_serv, rt_serv)
ui.show_ui()