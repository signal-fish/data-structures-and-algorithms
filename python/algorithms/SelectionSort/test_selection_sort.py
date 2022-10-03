import unittest
import random
from selection_sort import asc_selection_sort, des_selection_sort

class TestSelectionSort(unittest.TestCase):
    def setUp(self):
        self.arr = [random.randint(i, i+100) for i in range(100)]

    def test_asc_selection_sort(self):
        self.assertEqual(asc_selection_sort(self.arr), sorted(self.arr))

    def test_des_selection_sort(self):
        self.assertEqual(des_selection_sort(self.arr), sorted(self.arr, reverse=True))

if __name__ == '__main__':
    unittest.main()
