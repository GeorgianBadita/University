"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/9/2017 21:59
"""
from domain.entities import Client, Car, Rental
from domain.validators import ClientValidator, CarValidator, ValidatorException, RentalValidator
from repository.car_repository import CarRepository
from repository.client_repository import RepositoryException, ClientRepository
from repository.rental_repository import RentalRepository
from services.client_service import ClientService


def test_create_client():

    cl = Client(1, "Badita", "Valcea")
    assert cl.get_cl_address() == "Valcea"
    assert cl.get_cl_name() == "Badita"
    assert cl.get_cl_id() == 1


def test_create_car():
    car = Car(1, "BMW M3", 2007, "1.6")
    assert car.get_car_engine() == "1.6"
    assert car.get_car_id() == 1
    assert car.get_car_model() == "BMW M3"
    assert car.get_car_year() == 2007


def test_cleint_validator():
    cl = Client("", "", "")
    cl_val = ClientValidator()
    try:
        cl_val.validate(cl)
        assert False
    except ValidatorException as errs:
        assert len(errs.get_errs()) == 3
    cl = Client(1, "", "")
    try:
        cl_val.validate(cl)
        assert False
    except ValidatorException as errs:
        assert len(errs.get_errs()) == 2

    cl = Client(1, "Badita", "Valcea")
    try:
        cl_val.validate(cl)
        assert True
    except ValidatorException:
        assert False

def test_car_validator():

    car = Car("", "", "", "")
    car_val = CarValidator()

    try:
        car_val.validate(car)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 4

    car = Car(1, "Dacia", 2009, "1.9")

    try:
        car_val.validate(car)
        assert True
    except ValidatorException:
        assert False

def test_store_client():
    cl1 = Client(1, "Badita", "Olanu")
    cl2 = Client(2, "Alexandru", "Georgia")
    cl3 = Client(1, "Istvan", "Algeria")
    cl_val = ClientValidator()
    repo = ClientRepository(cl_val)
    repo.store_client(cl1)
    assert len(repo.get_all_clients()) == 1
    repo.store_client(cl2)
    assert len(repo.get_all_clients()) == 2

    try:
        repo.store_client(cl3)
        assert False
    except RepositoryException:
        assert True


def test_find_client():
    cl1 = Client(1, "Badita", "Olanu")
    cl2 = Client(2, "Alexandru", "Georgia")
    cl_val = ClientValidator()
    repo = ClientRepository(cl_val)
    repo.store_client(cl1)
    assert len(repo.get_all_clients()) == 1
    repo.store_client(cl2)
    assert len(repo.get_all_clients()) == 2
    assert repo.find_client(1) == cl1
    assert repo.find_client(2) == cl2
    assert repo.find_client(3) is  None


def test_find_car():
    car1 = Car(1, "M3", 2005, "1.9")
    car2 = Car(2, "M6", 2007, "2.6")
    car_val = CarValidator()
    repo = CarRepository(car_val)
    repo.store_car(car1)
    assert len(repo.get_all_cars()) == 1
    repo.store_car(car2)
    assert len(repo.get_all_cars()) == 2
    assert repo.find_car(1) == car1
    assert repo.find_car(2) == car2
    assert repo.find_car(3) is None



def test_store_car():
    car1 = Car(1, "M3", 2005, "1.9")
    car2 = Car(2, "M6", 2007, "2.6")
    car3 = Car(1, "1300", 2010, "2.1")
    car_val = CarValidator()
    repo = CarRepository(car_val)
    repo.store_car(car1)
    assert len(repo.get_all_cars()) == 1
    repo.store_car(car2)
    assert len(repo.get_all_cars()) == 2
    try:
        repo.store_car(car3)
        assert False
    except RepositoryException:
        assert True


def test_delete_car():
    car1 = Car(1, "M3", 2005, "1.9")
    car2 = Car(2, "M6", 2007, "2.6")
    car_val = CarValidator()
    repo = CarRepository(car_val)
    repo.store_car(car1)
    repo.store_car(car2)
    assert repo.delete_car(1) == car1
    assert len(repo.get_all_cars()) == 1
    assert repo.delete_car(3) is None
    assert len(repo.get_all_cars()) == 1

def test_delete_client():
    cl1 = Client(1, "Badita", "Olanu")
    cl2 = Client(2, "Alexandru", "Georgia")
    cl_val = ClientValidator()
    repo = ClientRepository(cl_val)
    repo.store_client(cl1)
    repo.store_client(cl2)
    assert repo.delete_client(1) == cl1
    assert len(repo.get_all_clients()) == 1
    assert repo.delete_client(3) is None
    assert len(repo.get_all_clients()) == 1
    assert repo.delete_client(2) == cl2
    assert len(repo.get_all_clients()) == 0


def test_add_client_serv():
    cl_val = ClientValidator()
    cl_repo = ClientRepository(cl_val)
    cl_serv = ClientService(cl_repo)
    cl_serv.add_cl_srv(1, "Geo", "Valcea")
    assert len(cl_repo.get_all_clients()) == 1
    assert cl_repo.get_all_clients()[0].get_cl_name() == "Geo"



def test_rental_validator():
    rt = Rental("", "")
    rt2 = Rental(1, "")
    rt_val = RentalValidator()
    try:
        rt_val.validate(rt)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 2

    try:
        rt_val.validate(rt2)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 1

def test_create_rental():
    rt = Rental(1, 2)
    rt2 = Rental(3, 2)
    assert rt.get_id_client() == 2
    assert rt.get_id_car() == 1
    assert rt2.get_id_car() == 3
    assert rt2.get_id_client() == 2



def test_rental_store_repo():
    rt_val = RentalValidator()
    rt_rep = RentalRepository(rt_val)
    rt1 = Rental(1, 2)
    rt2 = Rental(2, 3)
    rt_rep.store(rt1)
    assert len(rt_rep.get_all_rents()) == 1
    rt_rep.store(rt2)
    assert len(rt_rep.get_all_rents()) == 2


test_rental_store_repo()
test_rental_validator()
test_create_rental()
test_add_client_serv()
test_delete_car()
test_delete_client()
test_store_car()
test_find_car()
test_store_client()
test_find_client()
test_car_validator()
test_cleint_validator()
test_create_client()
test_create_car()
