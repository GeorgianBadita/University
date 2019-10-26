import unittest

from domain.Discipline import Discipline
from domain.Grade import Grade
from domain.Student import Student
from validator.Validator import ValidatorException, StudentValidator, DisciplineValidator, GradeValidator


class ValidatorTestCase(unittest.TestCase):
    def setUp(self):
        pass

    def test_validate_student(self):
        self.assertRaises(ValidatorException, StudentValidator.validate_student, Student('d', 'Maria'))
        self.assertRaises(ValidatorException, StudentValidator.validate_student, Student('', ''))
        self.assertRaises(ValidatorException, StudentValidator.validate_student, Student('', 'Dana'))
        self.assertRaises(ValidatorException, StudentValidator.validate_student, Student('3', ''))
        self.assertRaises(ValidatorException, StudentValidator.validate_student, Student('f', ''))
        self.assertTrue(StudentValidator.validate_student(Student(21, 'Alex')))

    def test_validate_discipline(self):
        self.assertRaises(ValidatorException, DisciplineValidator.validate_discipline, Discipline('', ''))
        self.assertRaises(ValidatorException, DisciplineValidator.validate_discipline, Discipline('2', ''))
        self.assertRaises(ValidatorException, DisciplineValidator.validate_discipline, Discipline('', 'Geometry'))
        self.assertRaises(ValidatorException, DisciplineValidator.validate_discipline, Discipline('d', ''))
        self.assertRaises(ValidatorException, DisciplineValidator.validate_discipline, Discipline('d', 'Geometry'))
        self.assertTrue(DisciplineValidator.validate_discipline(Discipline(3, 'Geometry')))

    def test_validate_grade(self):
        self.assertRaises(ValidatorException, GradeValidator.validate_grade, Grade(2, 3, 11))
        self.assertRaises(ValidatorException, GradeValidator.validate_grade, Grade(2, 5, 'a'))
        self.assertTrue(GradeValidator.validate_grade(Grade(5, 6, 7.5)))

