#include "complex.h"
#include <iostream>

using namespace std;

void checkBinaryOp()
{
	ComplexNum complexA(2, 2), complexB(-3, -3);
	double dA = 2;

	cout << "Check binary operations" << endl;
	cout << "a = " << complexA << endl;
	cout << "b = " << complexB << endl;
	cout << "dA = " << dA << endl;

	cout << "a + b = " << complexA + complexB << endl;
	cout << "a - b = " << complexA - complexB << endl;
	cout << "a * b = " << complexA * complexB << endl;
	cout << "a / b = " << complexA / complexB << endl;

	cout << "a + dA = " << complexA + dA << endl;
	cout << "a - dA = " << complexA - dA << endl;
	cout << "a * dA = " << complexA * dA << endl;
	cout << "a / dA = " << complexA / dA << endl;

	cout << "dA + a = " << dA + complexA << endl;
	cout << "dA - a = " << dA - complexA << endl;
	cout << "dA * a = " << dA * complexA << endl;
	cout << "dA / a = " << dA / complexA << endl;
}

void testEquality()
{
	ComplexNum a(2, 3);
	ComplexNum b(2, 3);
	ComplexNum c(3, 4);

	cout << "Equality Test" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;
	cout << "a == c: " << (a == c) << endl;
	cout << "a != c: " << (a != c) << endl;

	ComplexNum d;
	ComplexNum e(5, 0);
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "d == 0: " << (d == 0) << endl;
	cout << "d != 0: " << (d != 0) << endl;
	cout << "5 == e: " << (5 == e) << endl;
	cout << "5 != e: " << (5 != e) << endl;
}

void testArithAssingmentOp()
{
	ComplexNum a(2, 3);
	ComplexNum b(1, 2);
	double d = 4;

	cout << "Check compound assignment operations" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "d = " << d << endl;

	a += b;
	cout << "a += b: a = " << a << endl;

	a = ComplexNum(2, 3);
	a -= b;
	cout << "a -= b: a = " << a << endl;

	a = ComplexNum(2, 3);
	a *= b;
	cout << "a *= b: a = " << a << endl;

	a = ComplexNum(2, 3);
	a /= b;
	cout << "a /= b: a = " << a << endl;

	a = ComplexNum(2, 3);
	a += d;
	cout << "a += d: a = " << a << endl;

	a = ComplexNum(2, 3);
	a -= d;
	cout << "a -= d: a = " << a << endl;

	a = ComplexNum(2, 3);
	a *= d;
	cout << "a *= d: a = " << a << endl;

	a = ComplexNum(2, 3);
	a /= d;
	cout << "a /= d: a = " << a << endl;
}

void ambigousTests()
{
	cout << "Ambigous Tests:" << endl;

	ComplexNum a(1, 1), b(2, 2), c(3, 3), d(-1, -2);
	cout << "a = " << a << "\nb = " << b << "\nc = " << c << endl;
	a += b += c;
	cout << "a += b += c\na = " << a << endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	(a += b) += c;
	cout << "(a += b) += c\na = " << a << endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	a *= b *= c;
	cout << "a *= b *= c\na = " << a << endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	(a *= b) *= c;
	cout << "(a *= b) *= c\na = " << a << endl;
	a = ComplexNum(1, 1);
	cout << "-a: " << -a << endl;

	cout << "Phase of a:\n" << a.phase() * 180 / M_PI << endl;
	cout << "Magnitude of a:\n" << a.magnitude() << endl;

	cout << "Phase of " << d << ":\n" << d.phase() * 180 / M_PI << endl;
	cout << "Magnitude of " << d << ":\n" << d.magnitude() << endl;
}

int main()
{
	checkBinaryOp();
	testArithAssingmentOp();
	testEquality();
	ambigousTests();

	return 0;
}
