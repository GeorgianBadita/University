import unittest

from controller.DisciplineController import DisciplineController
from controller.StudentController import StudentController
from domain.Discipline import Discipline
from domain.Student import Student
from repository.DisciplineRepository import DisciplineRepository, DisciplineRepositoryException
from repository.StudentRepository import StudentRepository, StudentRepositoryException
from validator.Validator import DisciplineValidator, StudentValidator


class UndoRedoTestCase(unittest.TestCase):
    def setUp(self):
        discipline_v = DisciplineValidator()
        repo = DisciplineRepository(discipline_v)
        self.cntr_disc = DisciplineController(repo)
        student_v = StudentValidator()
        repo_s = StudentRepository(student_v)
        self.cntr_stud = StudentController(repo_s)

        repo.store_discipline_rep(Discipline(1, 'Computer Systems Architecture'))
        repo.store_discipline_rep(Discipline(2, 'Computational Logic'))
        repo.store_discipline_rep(Discipline(3, 'Mathematical Analysis'))
        repo.store_discipline_rep(Discipline(4, 'Algebra'))
        repo.store_discipline_rep(Discipline(5, 'Fundamentals of programming'))
        repo.store_discipline_rep(Discipline(6, 'Data Structures and Algorithms'))
        repo.store_discipline_rep(Discipline(7, 'Graph Algorithms'))
        repo.store_discipline_rep(Discipline(8, 'Operating Systems'))

        repo_s.store_student_rep(Student(1, 'Tudor'))
        repo_s.store_student_rep(Student(2, 'Razvan'))
        repo_s.store_student_rep(Student(3, 'Diana'))
        repo_s.store_student_rep(Student(4, 'Ana'))
        repo_s.store_student_rep(Student(5, 'Alexandru'))
        repo_s.store_student_rep(Student(6, 'Bogdan'))
        repo_s.store_student_rep(Student(7, 'Izabela'))
        repo_s.store_student_rep(Student(8, 'George'))
        repo_s.store_student_rep(Student(9, 'Andrei'))
        repo_s.store_student_rep(Student(10, 'Stefania'))

    def tearDown(self):
        pass

    def test_store_discipline(self):
        self.assertTrue(self.cntr_disc.store_discipline_ctr(Discipline(9, 'OOP')))
        self.assertRaises(DisciplineRepositoryException, self.cntr_disc.store_discipline_ctr, Discipline(1, 'German'))

    def test_store_student(self):
        self.assertTrue(self.cntr_stud.store_student_ctr(Student(11, 'Andrei')))
        self.assertRaises(StudentRepositoryException, self.cntr_stud.store_student_ctr, Student(1, 'Alexandru'))

    def test_find_discipline(self):
        self.assertTrue(self.cntr_disc.find_discipline_ctr(6))
        self.assertFalse(self.cntr_disc.find_discipline_ctr(10))

    def test_get_disciplines(self):
        self.assertEqual(self.cntr_disc.get_all_disciplines_ctr()[1], Discipline(1, 'Computational Logic'))
        self.assertNotEqual(self.cntr_disc.get_all_disciplines_ctr()[4], Discipline(3, 'Mathematical Analysis'))

    def test_update_discipline(self):
        self.assertTrue(self.cntr_disc.update_discipline_ctr(Discipline(3, 'Mathematical Analysis'), 'German'))
        self.assertFalse(self.cntr_disc.update_discipline_ctr(Discipline(9, 'French'), 'Graphic Design'))

    def test_find_by_name(self):
        self.assertEqual(self.cntr_disc.find_discipline_name_ctr('fun'), ['ID:5, Name: Fundamentals of programming'])
        self.assertNotEqual(self.cntr_disc.find_discipline_name_ctr('al'), ['ID:4, Name: Algebra'])
        self.assertRaises(DisciplineRepositoryException, self.cntr_disc.find_discipline_name_ctr, 'dde')

    def test_find_by_id(self):
        self.assertEqual(self.cntr_disc.find_discipline_id_ctr('8'), ['ID:8, Name: Operating Systems'])
        self.assertNotEqual(self.cntr_disc.find_discipline_id_ctr('5'), ['ID:6, Name: Biochemistry'])
        self.assertRaises(DisciplineRepositoryException, self.cntr_disc.find_discipline_id_ctr, '9')


if __name__ == "__main__":
    unittest.main()
