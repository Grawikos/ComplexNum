#include <cmath>
#include <fstream>
#include <iostream>
#pragma once

class ComplexNum {
  public:
	double real;
	double imaginary;

	ComplexNum(double real = 0, double imaginary = 0);
	ComplexNum(const ComplexNum& c);
	ComplexNum& operator=(const ComplexNum& c);
	friend std::ostream& operator<<(std::ostream& Out, const ComplexNum& c);
	ComplexNum operator+(const ComplexNum& c) const;
	ComplexNum operator+(const double& c) const;

	ComplexNum operator-(const ComplexNum& c) const;
	ComplexNum operator-(const double& c) const;
	ComplexNum operator-();

	ComplexNum operator*(const ComplexNum& c) const;
	ComplexNum operator*(const double& c) const;

	ComplexNum operator/(const ComplexNum& c) const;
	ComplexNum operator/(const double& c) const;

	ComplexNum& operator+=(const ComplexNum& c);
	ComplexNum& operator+=(const double& d);

	ComplexNum& operator-=(const ComplexNum& c);
	ComplexNum& operator-=(const double& d);

	ComplexNum& operator*=(const ComplexNum& c);
	ComplexNum& operator*=(const double& d);

	ComplexNum& operator/=(const ComplexNum& c);
	ComplexNum& operator/=(const double& d);

	bool operator==(const ComplexNum& c) const;
	bool operator==(const double& d) const;

	bool operator!=(const ComplexNum& c) const;
	bool operator!=(const double& d) const;

	double phase();
	double magnitude() const;
};

ComplexNum operator+(const double d, const ComplexNum& c);

ComplexNum operator-(const double d, const ComplexNum& c);

ComplexNum operator*(const double d, const ComplexNum& c);

ComplexNum operator/(const double d, const ComplexNum& c);

bool operator==(const double d, const ComplexNum& c);

bool operator!=(const double d, const ComplexNum& c);

//#endif
