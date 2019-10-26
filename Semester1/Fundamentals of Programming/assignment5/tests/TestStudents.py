import unittest

from validator.Validator import StudentValidator
from controller.StudentController import StudentController
from domain.Student import Student
from repository.StudentRepository import StudentRepository, StudentRepositoryException


class StudentTestCase(unittest.TestCase):
    def setUp(self):
        student_v = StudentValidator()
        repo = StudentRepository(student_v)
        self.cntr = StudentController(repo)

        repo.store_student_rep(Student(1, 'Tudor'))
        repo.store_student_rep(Student(2, 'Razvan'))
        repo.store_student_rep(Student(3, 'Diana'))
        repo.store_student_rep(Student(4, 'Ana'))
        repo.store_student_rep(Student(5, 'Alexandru'))
        repo.store_student_rep(Student(6, 'Bogdan'))
        repo.store_student_rep(Student(7, 'Izabela'))
        repo.store_student_rep(Student(8, 'George'))
        repo.store_student_rep(Student(9, 'Andrei'))
        repo.store_student_rep(Student(10, 'Stefania'))
        repo.store_student_rep(Student(11, 'Alexandra'))
        repo.store_student_rep(Student(12, 'Eduard'))
        repo.store_student_rep(Student(13, 'Cezar'))
        repo.store_student_rep(Student(14, 'Paul'))
        repo.store_student_rep(Student(15, 'Vlad'))
        repo.store_student_rep(Student(16, 'Cristian'))
        repo.store_student_rep(Student(17, 'Maria'))
        repo.store_student_rep(Student(18, 'Mirela'))
        repo.store_student_rep(Student(19, 'Mihai'))
        repo.store_student_rep(Student(20, 'Claudiu'))

    def tearDown(self):
        pass

    def test_add_student(self):
        self.assertTrue(self.cntr.store_student_ctr(Student(21, 'Darius')))
        self.assertRaises(StudentRepositoryException, self.cntr.store_student_ctr, Student(1, 'Diana'))
        self.assertRaises(StudentRepositoryException)

    def test_delete_student(self):
        self.assertFalse(self.cntr.delete_student_ctr(Student(21, 'Cristi')))
        self.assertEqual(self.cntr.delete_student_ctr(Student(17, 'Maria')).student_id(), 17)

    def test_find_student(self):
        self.assertTrue(self.cntr.find_student_ctr(3))
        self.assertFalse(self.cntr.find_student_ctr(21))

    def test_get_students(self):
        self.assertEqual(self.cntr.get_all_students_ctr()[0], Student(1, 'Tudor'))
        self.assertEqual(self.cntr.get_all_students_ctr()[0:2], [Student(1, 'Tudor'),Student(2, 'Razvan')])

    def test_update_student(self):
        self.assertTrue(self.cntr.update_student_ctr(Student(1, 'Tudor'), 'Dan'))
        self.assertFalse(self.cntr.update_student_ctr(Student(21, 'Renata'), 'Diana'))

    def test_find_by_name(self):
        self.assertEqual(self.cntr.find_student_name_ctr('dor'), ['Id:1, Name: Tudor'])
        self.assertNotEqual(self.cntr.find_student_name_ctr('r'), ['Id:1, Name: Tudor', 'Id:2, Name: Razvan'])
        self.assertRaises(StudentRepositoryException, self.cntr.find_student_name_ctr, 'xxys')

    def test_find_by_id(self):
        self.assertEqual(self.cntr.find_student_id_ctr('9'), ['Id:9, Name: Andrei', 'Id:19, Name: Mihai'])
        self.assertNotEqual(self.cntr.find_student_id_ctr('1'), ['Id: 1, Name:Tudor'])
        self.assertRaises(StudentRepositoryException, self.cntr.find_student_id_ctr, 'm')


if __name__ == "__main__":
    unittest.main()
