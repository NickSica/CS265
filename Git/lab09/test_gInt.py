#!/usr/bin/env python3
# test_gInt - Unit Test for gInt class
#
# Nicholas Sica
# 5/31/19

import sys
import unittest

from gInt import gInt

class GaussianTest(unittest.TestCase):
	'''Tests for gInt class'''
	
	def setUp(self):
		'''Optional.  Run before for each test.'''
		self.u1 = gInt(5, 13)
		self.u1copy = gInt( 5, 13)
		self.u2 = gInt(-12, -7)
		self.u2copy = gInt(-12, -7)
		self.p1 = gInt(11, 15)
		self.n1 = gInt(90, 76)
		self.n1copy = gInt(90, 76)
		self.n2 = gInt(-19, 5)

	def test_equals(self):
		self.assertEqual(self.u1, self.u1, 'gInt not equal to itelf')
		self.assertEqual(self.u1, self.u1copy, 'gInts not equal')
		self.assertEqual(self.n1, self.n1copy, 'gInts not equal')

		self.assertNotEqual(self.u1, self.u2, '5 == 12 and 13 == -7')
		self.assertNotEqual(self.u1, self.p1, '5 == 11 and 13 == 15')
		self.assertNotEqual(self.u1, self.n1, '5 == 90 and 13 == 76')

	def test_add(self):
		r = self.u1 + self.n1
		self.assertEqual(self.u1, self.u1copy, 'Left operand changed after addition')
		self.assertEqual(self.n1, self.n1copy, 'Right operand changed after addition')
		self.assertEqual(r, gInt(95, 89), 'Addition failed')

		r = self.u1 + self.u2
		self.assertEqual(r, gInt(-7, 6), 'Addition of one negative failed')

		r = self.u2 + self.n2
		self.assertEqual(r, gInt(-31, -2), 'Addition of two negatives failed')
			
	def test_mul(self):	
		r = self.u1 * self.n1
		self.assertEqual(self.u1, self.u1copy, 'Left operand changed after multiplication')
		self.assertEqual(self.n1, self.n1copy, 'Right operand changed after multiplication')
		self.assertEqual(r, gInt(-538, 1550), 'Multiplication failed')

		r = self.u1 * self.u2
		self.assertEqual(r, gInt(31, -191), 'Multiplication of one negative failed')

		r = self.u2 * self.n2
		self.assertEqual(r, gInt(263, 73), 'Multiplication of two negatives failed') 		
	
	def test_norm(self):
		r = self.u1.norm()
		self.assertEqual(self.u1, self.u1copy, 'Left operand changed after norm')
		self.assertEqual(r, 194, 'Norm failed')

		r = self.n2.norm()
		self.assertEqual(r, 386, 'Norm of one negative failed')

		r = self.u2.norm()
		self.assertEqual(r, 193, 'Norm of two negatives failed')
		

if __name__ == '__main__' :
	sys.argv.append( '-v' )
	unittest.main()

