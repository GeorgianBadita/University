import unittest
from validator.Validator import DisciplineValidator
from controller.DisciplineController import DisciplineController
from domain.Discipline import Discipline
from repository.DisciplineRepository import DisciplineRepository, DisciplineRepositoryException


class DisciplineTestCase(unittest.TestCase):
    def setUp(self):
        discipline_v = DisciplineValidator()
        repo = DisciplineRepository(discipline_v)
        self.cntr = DisciplineController(repo)

        repo.store_discipline_rep(Discipline(1, 'Computer Systems Architecture'))
        repo.store_discipline_rep(Discipline(2, 'Computational Logic'))
        repo.store_discipline_rep(Discipline(3, 'Mathematical Analysis'))
        repo.store_discipline_rep(Discipline(4, 'Algebra'))
        repo.store_discipline_rep(Discipline(5, 'Fundamentals of programming'))
        repo.store_discipline_rep(Discipline(6, 'Data Structures and Algorithms'))
        repo.store_discipline_rep(Discipline(7, 'Graph Algorithms'))
        repo.store_discipline_rep(Discipline(8, 'Operating Systems'))

    def tearDown(self):
        pass

    def test_store_discipline(self):
        self.assertTrue(self.cntr.store_discipline_ctr(Discipline(9, 'OOP')))
        self.assertRaises(DisciplineRepositoryException, self.cntr.store_discipline_ctr, Discipline(1, 'German'))

    def test_delete_discipline(self):
        self.assertFalse(self.cntr.delete_discipline_ctr(Discipline(21, 'OOP')))
        self.assertEqual(self.cntr.delete_discipline_ctr(Discipline(7, 'Graph Algorithms')).discipline_id(), 7)

    def test_find_discipline(self):
        self.assertTrue(self.cntr.find_discipline_ctr(6))
        self.assertFalse(self.cntr.find_discipline_ctr(10))

    def test_get_disciplines(self):
        self.assertEqual(self.cntr.get_all_disciplines_ctr()[1], Discipline(1, 'Computational Logic'))
        self.assertNotEqual(self.cntr.get_all_disciplines_ctr()[4], Discipline(3, 'Mathematical Analysis'))

    def test_update_discipline(self):
        self.assertTrue(self.cntr.update_discipline_ctr(Discipline(3, 'Mathematical Analysis'), 'German'))
        self.assertFalse(self.cntr.update_discipline_ctr(Discipline(9, 'French'), 'Graphic Design'))

    def test_find_by_name(self):
        self.assertEqual(self.cntr.find_discipline_name_ctr('fun'), ['ID:5, Name: Fundamentals of programming'])
        self.assertNotEqual(self.cntr.find_discipline_name_ctr('al'), ['ID:4, Name: Algebra'])
        self.assertRaises(DisciplineRepositoryException, self.cntr.find_discipline_name_ctr, 'dde')

    def test_find_by_id(self):
        self.assertEqual(self.cntr.find_discipline_id_ctr('8'), ['ID:8, Name: Operating Systems'])
        self.assertNotEqual(self.cntr.find_discipline_id_ctr('5'), ['ID:6, Name: Biochemistry'])
        self.assertRaises(DisciplineRepositoryException, self.cntr.find_discipline_id_ctr, '9')


if __name__ == "__main__":
    unittest.main()
