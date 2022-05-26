

#include <rational/rational.h>
#include <iostream>
 
Rational::Rational(const int nominator, const int denominator)
	:nom(nominator),
	denom(denominator)
{
	if (denom == 0)
		throw "Division by zero!";
	reduce();
}
Rational::Rational(const int nominator)
	: nom(nominator),
	denom(1)
{
}
Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mult(lhs);
	mult *= rhs;
	mult.reduce();
	return mult;
}
Rational& Rational::operator*=(const Rational& rhs)
{
	nom *= rhs.nom;
	denom *= rhs.denom;
	reduce();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	sum.reduce();
	return sum;
}
Rational& Rational::operator+=(const Rational& rhs)
{
	nom = (nom * rhs.denom + rhs.nom * denom);
	denom = denom * rhs.denom;
	reduce();
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational dif(lhs);
	dif -= rhs;
	dif.reduce();
	return dif;
}
Rational& Rational::operator-=(const Rational& rhs)
{
	nom = nom * rhs.denom - rhs.nom * denom;
	denom = denom * rhs.denom;
	reduce();
	return *this;
}


Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if (rhs.nom == 0) throw "Zero in denominator!";
	Rational del(lhs);
	del /= rhs;
	del.reduce();
	return del;
}
Rational& Rational::operator/=(const Rational& rhs)
{
	if (rhs.nom == 0) throw "Zero in denominator!";
	nom = nom * rhs.denom;
	denom = denom * rhs.nom;
	reduce();
	return *this;
}
std::ostream& operator<<(std::ostream& ostrm,const Rational& temp)
{
	ostrm << temp.nom << temp.slash << temp.denom;
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Rational& temp)
{

	char frac('\0');
	int p(0);
	int q(0);
	char separator(0);

	istrm >> p;
	istrm.get(separator);
	if (!std::isdigit(istrm.peek())) {
		istrm >> q;
		istrm.setstate(std::ios_base::failbit);
	}
	else {
		istrm >> q;
	}
	if (istrm.good() || istrm.rdstate() == std::ios_base::eofbit) {
		if (separator == Rational::slash) {
			temp = Rational(p, q);
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}


