"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 19:41
"""
import unittest

from Domain.medicine import Medicine
from unittest import TestCase
from Repository.medicine_repository import MedicineRepository
'''
---------------
|TESTING MODULE|
---------------
'''

class test_medicine(TestCase):
    '''
    class for testing the Medicine class
    '''

    def setUp(self):
        self.medicine = Medicine("Nurofen 500 mg", 24.5)

    def test_create_medicine(self):
        self.assertEqual(self.medicine.get_name(), "Nurofen 500 mg")
        self.assertEqual(self.medicine.get_price(), 24.5)

class test_medicine(TestCase):
    '''
    Class for testing the Medicine Repository Class
    '''

    def setUp(self):
        self.repo = MedicineRepository("test_repo.txt")
        self.medicines = self.repo.load_from_file()


    def test_load(self):
        self.assertTrue(len(self.medicines) != 0)
        self.assertEqual(self.medicines[0].get_name(), "Nurofen 500g")

    def test_store(self):
        new_med = Medicine("Best pill 200g", 12.6)
        self.medicines.append(new_med)


    def test_get_all(self):
        self.assertEqual(len(self.repo.get_all()), 8)

    def test_find_name(self):
        self.assertEqual(self.repo.find_by_name("Nurofen 500g").get_price(), 24.75)
        self.assertTrue(self.repo.find_by_name("alabala") is None)


if __name__ == '__main__':
    unittest.main()