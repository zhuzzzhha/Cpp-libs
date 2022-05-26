//authoring
#pragma once
#ifndef COMPLEX_COMPLEX_H_20220309
#define COMPLEX_COMPLEX_H_20220309
#include <iostream>
#include <sstream>
#include <cctype>
struct Complex {
public:
	Complex(const double real, const double imaginary);
	Complex(const double real);
	Complex() = default;
	Complex(const Complex& copy) = default;
	~Complex() = default;
	
	Complex operator-() const { return Complex(-re, -im); }
	Complex operator+() const {
		return *this;
	}
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const {
		return !(*this == rhs);
	};

	Complex& operator=(const Complex& rhs) = default;

	
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);
	/*Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }*/
	double re{ 0.0 };
	double im{ 0.0 };
	static const char leftBrace = '{';
	static const char rightBrace = '}';
	static const char separator = ',';
};
std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);



#endif
