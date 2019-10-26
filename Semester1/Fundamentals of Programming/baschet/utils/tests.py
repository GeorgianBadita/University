"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   1/28/2018 14:48
"""
from domain.entities import Jucator
from domain.validators import JucatorValidator, ValidatorException
from repository.file_repository import FileRepository
from repository.repository_validator import RepositoryException


def test_jucatr():
    jc = Jucator("Balau", "Ioan", 185, "Fundas")
    assert jc.get_prenume() == "Ioan"
    assert jc.get_inaltime() == 185
    assert jc.get_post() == "Fundas"
    assert jc.get_nume() == "Balau"


def test_validator():
    jc = Jucator("", "", -1, "fundas")
    val = JucatorValidator()
    try:
        val.validate(jc)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errors()) == 4

    jc = Jucator("", "Alexandru", 164, "Fundas")
    try:
        val.validate(jc)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errors()) == 1

    jc = Jucator("Badita", "Georgian", 194, "Pivot")
    try:
        val.validate(jc)
        assert True
    except ValidatorException as ex:
        assert False

def test_store_to_file():
    repo = FileRepository("test_juc.txt")
    repo.sterge_fisier()
    all_j = repo.load_from_file()
    new_jc = Jucator("Luncas", "Mihai", 188, "Pivot")
    all_j.append(new_jc)
    repo.store_to_file(all_j)
    all_j = repo.load_from_file()
    last = len(all_j) - 1
    assert all_j[last] == new_jc
    new_jc = Jucator("Badita", "Alexandru", 193, "Fundas")
    all_j.append(new_jc)
    repo.store_to_file(all_j)

def test_cauta_jucator():
    jc = Jucator("Badita", "Alexandru", 193, "Fundas")
    repo = FileRepository("test_juc.txt")
    assert repo.cauta_jucator(jc) == jc
    jc = Jucator("Badea", "Ioan", 210, "Pivot")
    assert repo.cauta_jucator(jc) == None

def test_schimba_h():
    repo = FileRepository("test_juc.txt")
    modif = repo.modificare_h("Badita", "Alexandru", 199)
    assert modif.get_inaltime() == 199
    modif = repo.modificare_h("Balau", "Cugacoski", 200)
    assert modif == None

def test_adauga_jucator():
    repo = FileRepository("test_juc.txt")
    jc = Jucator("Badita", "Alexandru", 193, "Fundas")
    try:
        repo.adauga_jucator(jc)
        assert False
    except RepositoryException:
        assert True
    jc = Jucator("Balau", "Gheorghe", 188, "Extrema")
    assert repo.adauga_jucator(jc) == jc



test_adauga_jucator()
test_schimba_h()
test_cauta_jucator()
test_store_to_file()
test_validator()
test_jucatr()