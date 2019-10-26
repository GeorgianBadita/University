from sutdent import Student
import re
from helper import  *


class ValidatorException(Exception):

    def __init__(self, errors):
        self.errors = errors

    def getErrors(self):
        return self.errors

class StudentValidator:

    def validate(self, student):
        erros = []
        if student.getVarsta() == "": erros.append("Age can't be empty!")
        if student.getNrMatricol() == "": erros.append("Nr Matricol can't be empty")
        if student.getVarsta() == "": erros.append("Age can't be empty")
        age = student.getVarsta()
        if re.match('-', str(age)) == "-1": erros.append("Age can't be negative")
        erros += self.__checkNrMatricol(erros, student)
        if len(erros) > 0:
            raise ValidatorException(erros)

    def __checkNrMatricol(self, erros, student):
        if len(student.getNrMatricol()) != 7: erros.append("Nr Matricol must be 7 chrs long")
        if not student.getNrMatricol().isalnum(): erros.append("Nr matricol format icorrect")
        if not student.getNrMatricol()[:2].isalpha(): erros.append("Nr matricol format incorrect")
        if not student.getNrMatricol()[2:].isdecimal(): erros.append("Nr matricol format incorrect")
        return erros


def testValidatorStudent():
    #toate campurile vide
    val = StudentValidator()
    st = Student("", "", "")
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True
    st = Student("1", "", "")
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True
    st = Student("", "Gabriel", "")
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True
    st = Student("2", "Gabriel", "19")
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True
    st = Student("1", "Geo", -1)
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True
    st = Student("12345678", "", "")
    try:
        val.validate(st)
        assert False
    except ValidatorException:
        assert True



    #st = StudentValidator("12abcde", "Geo", "18")

testValidatorStudent()