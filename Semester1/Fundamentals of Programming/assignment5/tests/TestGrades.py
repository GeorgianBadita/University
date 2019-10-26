import unittest
from validator.Validator import GradeValidator
from controller.GradeController import GradeController
from domain.Grade import Grade
from repository.GradeRepository import GradeRepository

class GradesTestCase(unittest.TestCase):
    def setUp(self):
        grade_v = GradeValidator()
        grade_repository = GradeRepository(grade_v)
        self.cntr = GradeController(grade_repository)

        grade_repository.store_grade_rep(Grade(1, 1, 3.5))
        grade_repository.store_grade_rep(Grade(3, 1, 5.4))
        grade_repository.store_grade_rep(Grade(5, 1, 2.5))
        grade_repository.store_grade_rep(Grade(7, 1, 1.7))
        grade_repository.store_grade_rep(Grade(2, 2, 6.5))
        grade_repository.store_grade_rep(Grade(4, 2, 5))
        grade_repository.store_grade_rep(Grade(6, 2, 4.8))
        grade_repository.store_grade_rep(Grade(8, 2, 9.3))
        grade_repository.store_grade_rep(Grade(1, 3, 8.5))
        grade_repository.store_grade_rep(Grade(2, 3, 9))
        grade_repository.store_grade_rep(Grade(3, 3, 7))
        grade_repository.store_grade_rep(Grade(4, 3, 7.6))
        grade_repository.store_grade_rep(Grade(5, 4, 9.4))
        grade_repository.store_grade_rep(Grade(6, 4, 5.7))
        grade_repository.store_grade_rep(Grade(7, 4, 7.7))
        grade_repository.store_grade_rep(Grade(8, 4, 6.8))
        grade_repository.store_grade_rep(Grade(8, 5, 7.6))
        grade_repository.store_grade_rep(Grade(7, 5, 9.8))
        grade_repository.store_grade_rep(Grade(6, 5, 4.3))
        grade_repository.store_grade_rep(Grade(5, 5, 6.8))
        grade_repository.store_grade_rep(Grade(4, 6, 8.4))
        grade_repository.store_grade_rep(Grade(3, 6, 7))
        grade_repository.store_grade_rep(Grade(2, 6, 5.5))
        grade_repository.store_grade_rep(Grade(1, 6, 3.5))
        grade_repository.store_grade_rep(Grade(8, 7, 8.3))
        grade_repository.store_grade_rep(Grade(6, 7, 8))
        grade_repository.store_grade_rep(Grade(4, 7, 4.2))
        grade_repository.store_grade_rep(Grade(2, 7, 8.5))
        grade_repository.store_grade_rep(Grade(7, 8, 9.6))
        grade_repository.store_grade_rep(Grade(5, 8, 7))
        grade_repository.store_grade_rep(Grade(3, 8, 4.5))
        grade_repository.store_grade_rep(Grade(1, 8, 6.8))
        grade_repository.store_grade_rep(Grade(1, 9, 5))
        grade_repository.store_grade_rep(Grade(3, 9, 7.25))
        grade_repository.store_grade_rep(Grade(5, 9, 9))
        grade_repository.store_grade_rep(Grade(7, 9, 6.3))
        grade_repository.store_grade_rep(Grade(2, 10, 7.4))
        grade_repository.store_grade_rep(Grade(4, 10, 9))
        grade_repository.store_grade_rep(Grade(6, 10, 8.2))
        grade_repository.store_grade_rep(Grade(8, 10, 6.9))
        grade_repository.store_grade_rep(Grade(1, 11, 5.25))
        grade_repository.store_grade_rep(Grade(2, 11, 2.3))
        grade_repository.store_grade_rep(Grade(3, 11, 5))
        grade_repository.store_grade_rep(Grade(4, 11, 6.7))
        grade_repository.store_grade_rep(Grade(5, 12, 6))
        grade_repository.store_grade_rep(Grade(6, 12, 7.5))
        grade_repository.store_grade_rep(Grade(7, 12, 8))
        grade_repository.store_grade_rep(Grade(8, 12, 6))
        grade_repository.store_grade_rep(Grade(8, 13, 5.5))
        grade_repository.store_grade_rep(Grade(7, 13, 3.4))
        grade_repository.store_grade_rep(Grade(6, 13, 8))
        grade_repository.store_grade_rep(Grade(5, 13, 6.5))
        grade_repository.store_grade_rep(Grade(4, 14, 4))
        grade_repository.store_grade_rep(Grade(3, 14, 7))
        grade_repository.store_grade_rep(Grade(2, 14, 6.75))
        grade_repository.store_grade_rep(Grade(1, 14, 5.25))
        grade_repository.store_grade_rep(Grade(8, 15, 9.5))
        grade_repository.store_grade_rep(Grade(6, 15, 10))
        grade_repository.store_grade_rep(Grade(4, 15, 9))
        grade_repository.store_grade_rep(Grade(2, 15, 9.25))
        grade_repository.store_grade_rep(Grade(7, 16, 7.2))
        grade_repository.store_grade_rep(Grade(5, 16, 8))
        grade_repository.store_grade_rep(Grade(3, 16, 6.75))
        grade_repository.store_grade_rep(Grade(1, 16, 7))
        grade_repository.store_grade_rep(Grade(5, 17, 9))
        grade_repository.store_grade_rep(Grade(6, 17, 9.5))
        grade_repository.store_grade_rep(Grade(7, 17, 9.7))
        grade_repository.store_grade_rep(Grade(8, 17, 9.9))
        grade_repository.store_grade_rep(Grade(8, 18, 8))
        grade_repository.store_grade_rep(Grade(7, 18, 7.25))
        grade_repository.store_grade_rep(Grade(6, 18, 7.5))
        grade_repository.store_grade_rep(Grade(5, 18, 6))
        grade_repository.store_grade_rep(Grade(4, 19, 4.9))
        grade_repository.store_grade_rep(Grade(3, 19, 6.5))
        grade_repository.store_grade_rep(Grade(2, 19, 7))
        grade_repository.store_grade_rep(Grade(1, 19, 6))
        grade_repository.store_grade_rep(Grade(8, 20, 8))
        grade_repository.store_grade_rep(Grade(6, 20, 8.5))
        grade_repository.store_grade_rep(Grade(4, 20, 9.25))
        grade_repository.store_grade_rep(Grade(2, 20, 6))

    def tearDown(self):
        pass

    def test_store_grade(self):
        self.assertTrue(self.cntr.store_grade_ctr(Grade(3, 4, 5)))
        self.assertTrue(self.cntr.store_grade_ctr, Grade(2, 8, 9.5))

    def test_get_grades(self):
        self.assertNotEqual(self.cntr.get_all_grades_ctr(), Grade(1, 1, 3.5))
        self.assertNotEqual(self.cntr.get_all_grades_ctr(), [2, 4, 7])

    def test_gstudent(self):
        self.assertNotEqual(self.cntr.delete_gstudent_ctr(3), 0)
        self.assertNotEqual(self.cntr.delete_gstudent_ctr(15), 0)

    def test_gdiscipline(self):
        self.assertNotEqual(self.cntr.delete_gdiscipline_ctr(5), 0)
        self.assertNotEqual(self.cntr.delete_gdiscipline_ctr(3), 0)

    def test_students_at_discipline(self):
        self.assertEqual(self.cntr.get_students_at_discipline(2), [2, 3, 6, 7, 10, 11, 14, 15, 19, 20])
        self.assertNotEqual(self.cntr.get_students_at_discipline(6), [2, 7, 13])

    def test_average_grade(self):
        self.assertEquals(self.cntr.average_grade_ctr(2, 9), 0)
        self.assertEquals(self.cntr.average_grade_ctr(12, 6), 7.5)
        self.assertNotEquals(self.cntr.average_grade_ctr(1, 8), 8.25)

    def test_average_discipline(self):
        self.assertEqual(self.cntr.average_discipline_ctr(10), 0)
        self.assertEqual(self.cntr.average_discipline_ctr(7), 7.065)
        self.assertNotEqual(self.cntr.average_discipline_ctr(3), 6.2667)

    def test_student_average(self):
        self.assertEqual(self.cntr.get_student_average(10), 7.875)
        self.assertNotEqual(self.cntr.get_student_average(16), 8.5)


if __name__ == "__main__":
    unittest.main()
