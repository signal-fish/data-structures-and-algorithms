import unittest
import random
from bubble_sort import asc_bubble_sort, des_bubble_sort

class TestBubbleSort(unittest.TestCase):

    def setUp(self):
        self.arr = [random.randint(i, i+100) for i in range(1000)]

    def test_asc_bubble_sort(self):
        self.assertEqual(asc_bubble_sort(self.arr), sorted(self.arr))

    def test_des_bubble_sort(self):
        self.assertEqual(des_bubble_sort(self.arr), sorted(self.arr, reverse=True))


if __name__ == '__main__':
    unittest.main()
