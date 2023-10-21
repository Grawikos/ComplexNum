#include "complex.h"
#include <iostream>

using namespace std;

void checkBinaryOp(ComplexNum complexA, ComplexNum complexB, double dA, double dB){
	cout << "Check binary operations" << endl;
	std::cout << "a = " << complexA << endl;
	std::cout << "b = " << complexB << endl;
    
    std::cout << "a + b = " << complexA + complexB << endl;
    std::cout << "a - b = " << complexA - complexB << endl;
    std::cout << "a * b = " << complexA * complexB << endl;
    std::cout << "a / b = " << complexA / complexB << endl;
    
    std::cout << "a + dA = " << complexA + dA << endl; 
    std::cout << "a - dA = " << complexA - dA << endl;
    std::cout << "a * dA = " << complexA * dA << endl;
    std::cout << "a / dA = " << complexA / dA << endl;
    
    std::cout << "dA + a = " << dA + complexA << endl;
    std::cout << "dA - a = " << dA - complexA << endl;
    std::cout << "dA * a = " << dA * complexA << endl;
    std::cout << "dA / a = " << dA / complexA << endl;
    
}


void testEquality() {
    ComplexNum a(2, 3);
    ComplexNum b(2, 3);
    ComplexNum c(3, 4);
    
    std::cout << "Equality Test" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    
    ComplexNum d;
    ComplexNum e(5, 0);
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "d == 0: " << (d == 0) << std::endl;
    std::cout << "d != 0: " << (d != 0) << std::endl;
    std::cout << "5 == e: " << (5 == e) << std::endl;
    std::cout << "5 != e: " << (5 != e) << std::endl;
}

void testUnaryOp() {
    ComplexNum a(2, 3);
    ComplexNum b(1, 2);
    double d = 4;

    std::cout << "Check compound assignment operations" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "d = " << d << std::endl;

    a += b;
    std::cout << "a += b: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a -= b;
    std::cout << "a -= b: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a *= b;
    std::cout << "a *= b: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a /= b;
    std::cout << "a /= b: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a += d;
    std::cout << "a += d: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a -= d;
    std::cout << "a -= d: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a *= d;
    std::cout << "a *= d: a = " << a << std::endl;

    a = ComplexNum(2, 3);
    a /= d;
    std::cout << "a /= d: a = " << a << std::endl;
}

void ambigousTests(){
	ComplexNum a(1, 1), b(2, 2), c(3, 3);
	a += b += c;
	cout << "a += b += c\na = " << a << std::endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	(a += b) += c;
	cout << "(a += b) += c\na = " << a << std::endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	a *= b *= c;
	cout << "a *= b *= c\na = " << a << std::endl;
	a = ComplexNum(1, 1);
	b = ComplexNum(2, 2);
	c = ComplexNum(3, 3);
	(a *= b) *= c;
	cout << "(a *= b) *= c\na = " << a << std::endl;
	
	
}

int main()
{
	ComplexNum a(2, 2), b(-2, -2);
	
	checkBinaryOp(a, b, 2, 5);
	testUnaryOp();
	testEquality();
	ambigousTests();
	
	return 0;
}
