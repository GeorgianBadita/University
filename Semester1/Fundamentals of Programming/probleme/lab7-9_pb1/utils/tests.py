"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/6/2018 22:26
"""
from domain.entities import Student, Discipline
from domain.validators import StudentValidator, ValidatorException, DisciplineValidator
from repository.discipline_repository import DisciplineRepository
from repository.student_repository import StudentRepository


def test_student():
    st = Student("ab123", "Marin-Georgian")
    assert st.get_st_id() == "ab123"
    assert st.get_st_name() == "Marin-Georgian"


def test_disc():
    disc = Discipline("1", "Fundamentele programarii", "Istvan")
    assert disc.get_dis_id() == "1"
    assert disc.get_dis_name() == "Fundamentele programarii"
    assert disc.get_dis_prof() == "Istvan"


def test_validator_st():
    st = Student("", "")
    val = StudentValidator()
    try:
        val.validate(st)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errors()) == 5

    st = Student("cd467", "Marin Ionescu")
    try:
        val.validate(st)
        assert True
    except ValidatorException:
        assert False

def test_validator_disc():
    dis = Discipline("", "", "")
    val = DisciplineValidator()
    try:
        val.validate(dis)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errors()) == 3

    dis = Discipline("1", "Matematica", "Berinde")
    try:
        val.validate(dis)
        assert True
    except ValidatorException:
        assert False


def test_store_repo():
    st_repo = StudentRepository()
    st = Student("ab123", "Badita Marin-Georgian")
    st_repo.store_st(st)
    lst = st_repo.get_all_st_rep()
    assert len(lst) == 1
    assert lst[0].get_st_id() == "ab123"
    assert lst[0].get_st_name() == "Badita Marin-Georgian"
    try:
        st_repo.store_st(st)
        assert False
    except ValueError:
        assert True
    st2 = Student("qw123", "Amalia")
    st_repo.store_st(st2)
    assert st_repo.find_by_id_st("qw123") == st2
    assert st_repo.delete_by_id_st("qw123") == st2
    assert len(st_repo.get_all_st_rep()) == 1
    assert st_repo.delete_by_id_st("as214") is None\



def test_store_disc_repo():
    disc_repo = DisciplineRepository()
    disc = Discipline("1", "FP", "Istvan")
    disc_repo.store_disc(disc)
    lst = disc_repo.get_all_disc_rep()
    assert len(lst) == 1
    assert lst[0].get_dis_id() == "1"
    assert lst[0].get_dis_name() == "FP"
    assert lst[0].get_dis_prof() == "Istvan"
    try:
        disc_repo.store_disc(disc)
        assert False
    except ValueError:
        assert True
    disc2 = Discipline("2", "ASC", "Vancea")
    disc_repo.store_disc(disc2)
    assert disc_repo.find_by_id_disc("2") == disc2
    assert disc_repo.delete_by_id_disc("2") == disc2
    assert len(disc_repo.get_all_disc_rep()) == 1
    assert disc_repo.delete_by_id_disc("4") is None


test_store_disc_repo()
test_store_repo()
test_validator_st()
test_validator_disc()
test_disc()
test_student()