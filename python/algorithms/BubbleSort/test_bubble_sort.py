import unittest
from bubble_sort import asc_bubble_sort, des_bubble_sort

class TestBubbleSort(unittest.TestCase):

    def setUp(self):
        self.a1 = [3, 5, 4, 2, 1]
        self.a2 = [5, 2, 1, 4, 3]
        self.a3 = [3, 2, 1, 3, 2]
        self.a4 = [1, 2, 3, 4, 5]
        self.a5 = [5, 4, 3, 2, 1]

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
