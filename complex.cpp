#include <complex/complex.h>
#include <iostream>
#include <sstream>
#include<limits>
double const eps = std::numeric_limits<double>::epsilon();
Complex::Complex(const double real, const double imaginary)
	:re(real),
	im(imaginary)
{
	return;
}
Complex::Complex(const double real)
	: re(real),
	im(0.0)
{
	return;
}
bool Complex::operator==(const Complex& rhs) const {
	return std::abs(re - rhs.re) < 2 * eps &&
		std::abs(im - rhs.im) < 2 * eps;
};
Complex& Complex::operator*=(const Complex& rhs)
{
	Complex lhs = *this;
	re = lhs.re * rhs.re - lhs.im * rhs.im;
	im = lhs.re * rhs.im + lhs.im * rhs.re;
	return (*this);
}
Complex& Complex::operator/=(const Complex& rhs)
{
	if (rhs == Complex{ 0.0, 0.0 }) {
		throw "Division by zero!";
	}
	Complex lhs = *this;
	re = (lhs.re * rhs.re + lhs.im * rhs.im) /
		(rhs.re * rhs.re + rhs.im * rhs.im);
	im = (lhs.im * rhs.re - lhs.re * rhs.im) /
		(rhs.re * rhs.re + rhs.im * rhs.im);
	return (*this);
}
Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex lhs_copy = lhs;
	return lhs_copy += rhs;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{

	Complex lhs_copy = lhs;
	return lhs_copy -= rhs;
}
Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex lhs_copy = lhs;
	return lhs_copy *= rhs;
}
Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex lhs_copy = lhs;
	return lhs_copy /= rhs;
}

/*Complex operator+(const Complex& lhs, const double rhs)
{
	Complex sum(lhs);
	sum.re += rhs;
	return sum;
}
Complex operator-(const Complex& lhs, const double rhs)
{
	Complex dif(lhs);
	dif.re -= rhs;
	return dif;
}
Complex operator*(const Complex& lhs, const double rhs)
{
	Complex mult(lhs);
	mult.re *= rhs;
	mult.im *= rhs;
	return mult;
}
Complex operator/(const Complex& lhs, const double rhs)
{
	Complex del(lhs);
	del.re = (del.re * rhs) / rhs / rhs;
	del.im = (del.im * rhs) / rhs; rhs;
	return del;
}
Complex operator+ (const double lhs, const Complex& rhs)
{
	Complex sum(rhs);
	sum.re += lhs;
	return sum;
}
Complex operator- (const double lhs, const Complex& rhs)
{
	Complex dif;
	dif.re =lhs-rhs.re;
	dif.im = (-1) * rhs.im;
	return dif;
}
Complex operator* (const double lhs, const Complex& rhs)
{
	Complex mult(rhs);
	mult.re *= lhs;
	mult.im *= lhs;
	return mult;
}
Complex operator/ (const double lhs, const Complex& rhs)
{
	Complex del;
	del.re = lhs / rhs.re;
	del.im = 0;
	return del;
}*/
std::ostream& operator<<(std::ostream& ostream, const Complex& temp)
{
	ostream << temp.leftBrace << temp.re << temp.separator << temp.im << temp.rightBrace;
	return ostream;
}

std::istream& operator>>(std::istream& istream, Complex& temp)
{
	char leftBrace(0);
	char rightBrace(0);
	double real(0.0);
	double imaginary(0.0);
	char comma(0);
	istream >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istream.good())
	{
		if (Complex::leftBrace == leftBrace && Complex::separator == comma && Complex::rightBrace == rightBrace)
		{
			temp.re = real;
			temp.im = imaginary;
		}
		else
		{
			istream.setstate(std::ios_base::failbit);
		}
	}
	return istream;
}



