import unittest
import random
from bubble_sort import asc_bubble_sort, des_bubble_sort

class TestBubbleSort(unittest.TestCase):

    def setUp(self):
        self.a1 = [random.randint(i, i+100) for i in range(1000)]
        self.a2 = [random.randint(i, i+100) for i in range(1000)]
        self.a3 = [random.randint(i, i+100) for i in range(1000)]
        self.a4 = [random.randint(i, i+100) for i in range(1000)]
        self.a5 = [random.randint(i, i+100) for i in range(1000)]

    def test_asc_bubble_sort(self):
        self.assertEqual(asc_bubble_sort(self.a1), sorted(self.a1))
        self.assertEqual(asc_bubble_sort(self.a2), sorted(self.a2))
        self.assertEqual(asc_bubble_sort(self.a3), sorted(self.a3))
        self.assertEqual(asc_bubble_sort(self.a4), sorted(self.a4))
        self.assertEqual(asc_bubble_sort(self.a5), sorted(self.a5))

    def test_des_bubble_sort(self):
        self.assertEqual(des_bubble_sort(self.a1), sorted(self.a1, reverse=True))
        self.assertEqual(des_bubble_sort(self.a2), sorted(self.a2, reverse=True))
        self.assertEqual(des_bubble_sort(self.a3), sorted(self.a3, reverse=True))
        self.assertEqual(des_bubble_sort(self.a4), sorted(self.a4, reverse=True))
        self.assertEqual(des_bubble_sort(self.a5), sorted(self.a5, reverse=True))


if __name__ == '__main__':
    unittest.main()
