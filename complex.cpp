#include "complex.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

ComplexNum::ComplexNum(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNum::ComplexNum(const ComplexNum& c)
{
	real = c.real;
	imaginary = c.imaginary;
}

ComplexNum& ComplexNum::operator=(const ComplexNum& c)
{
	if (this == &c)
		return *this;
	real = c.real;
	imaginary = c.imaginary;
	return *this;
}

ostream& operator<<(ostream& Out, const ComplexNum& c)
{
	Out << c.real;
	if (c.imaginary >= 0)
		Out << "+" << c.imaginary << "i";
	else
		Out << "-" << -c.imaginary << "i";

	return Out;
}

//+
ComplexNum ComplexNum::operator+(const ComplexNum& c) const
{
	return ComplexNum(real + c.real, imaginary + c.imaginary);
}

ComplexNum ComplexNum::operator+(const double& c) const
{
	return ComplexNum(real + c, imaginary);
}

ComplexNum operator+(const double d, const ComplexNum& c)
{
	return ComplexNum(d + c.real, c.imaginary);
}

//-
ComplexNum ComplexNum::operator-(const ComplexNum& c) const
{
	return ComplexNum(real - c.real, imaginary - c.imaginary);
}

ComplexNum ComplexNum::operator-(const double& c) const
{
	return ComplexNum(real - c, imaginary);
}

ComplexNum operator-(const double d, const ComplexNum& c)
{
	return ComplexNum(d - c.real, -c.imaginary);
}

//*
ComplexNum ComplexNum::operator*(const ComplexNum& c) const
{
	return ComplexNum(real * c.real - imaginary * c.imaginary,
					  real * c.imaginary + imaginary * c.real);
}

ComplexNum ComplexNum::operator*(const double& c) const
{
	return ComplexNum(real * c, imaginary * c);
}

ComplexNum operator*(const double d, const ComplexNum& c)
{
	return ComplexNum(d * c.real, d * c.imaginary);
}

// /
ComplexNum ComplexNum::operator/(const ComplexNum& c) const
{
	if (c.real == 0 and c.imaginary == 0) {
		cout << "Division by 0!";
		exit(1);
	}
	double divisor = c.real * c.real + c.imaginary * c.imaginary;
	double realPart = (real * c.real + imaginary * c.imaginary) / divisor;
	double imaginaryPart = (imaginary * c.real - real * c.imaginary) / divisor;
	return ComplexNum(realPart, imaginaryPart);
}

ComplexNum ComplexNum::operator/(const double& c) const
{
	if (real == 0 and imaginary == 0) {
		cout << "Division by 0!";
		exit(1);
	}
	return ComplexNum(real / c, imaginary / c);
}

ComplexNum operator/(const double d, const ComplexNum& c)
{
	if (c.real == 0 and c.imaginary == 0) {
		cout << "Division by 0!";
		exit(1);
	}
	double divisor = c.real * c.real + c.imaginary * c.imaginary;
	double realPart = (c.real * d) / divisor;
	double imaginaryPart = (-c.imaginary * d) / divisor;
	return ComplexNum(realPart, imaginaryPart);
}

// x=
ComplexNum& ComplexNum::operator+=(const ComplexNum& c)
{
	real += c.real;
	imaginary += c.imaginary;
	return *this;
}

ComplexNum& ComplexNum::operator+=(const double& d)
{
	real += d;
	return *this;
}


ComplexNum& ComplexNum::operator-=(const ComplexNum& c)
{
	real -= c.real;
	imaginary -= c.imaginary;
	return *this;
}

ComplexNum& ComplexNum::operator-=(const double& d)
{
	real -= d;
	return *this;
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& c)
{
	double tempReal = real * c.real - imaginary * c.imaginary;
	double tempImaginary = real * c.imaginary + imaginary * c.real;
	real = tempReal;
	imaginary = tempImaginary;
	return *this;
}


ComplexNum& ComplexNum::operator*=(const double& d)
{
	real *= d;
	imaginary *= d;
	return *this;
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& c)
{
	if (real == 0 and imaginary == 0) {
		cout << "Division by 0!";
		exit(1);
	}
	double divisor = c.real * c.real + c.imaginary * c.imaginary;
	double tempReal = (real * c.real + imaginary * c.imaginary) / divisor;
	double tempImaginary = (imaginary * c.real - real * c.imaginary) / divisor;
	real = tempReal;
	imaginary = tempImaginary;
	return *this;
}

ComplexNum& ComplexNum::operator/=(const double& d)
{
	if (d == 0) {
		cout << "Division by 0!";
		exit(1);
	}
	real /= d; 
	imaginary /= d;
	return *this;
}


bool ComplexNum::operator==(const ComplexNum& c) const{
	return (real == c.real) && (imaginary == c.imaginary);
}

bool ComplexNum::operator==(const double& d) const{
	return (real == d) && (imaginary == 0);
}

bool operator==(const double d, const ComplexNum& c){
	return (c.real == d) && (c.imaginary == 0);	
}

bool ComplexNum::operator!=(const ComplexNum& c) const{
	return (real != c.real) || (imaginary != c.imaginary);
}

bool ComplexNum::operator!=(const double d) const{
	return (real != d) || (imaginary != 0);
}

bool operator!=(const double d, const ComplexNum& c){
	return (c.real != d) || (c.imaginary != 0);	
}
