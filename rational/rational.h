// authoring
#pragma once
#ifndef RATIONAL_RATIONAL_H_20220309
#define RATIONAL_RATIONAL_H_20220309
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
class Rational {
public:
	~Rational() = default;
	Rational() = default;
	Rational(const int nominator);
	Rational(const int nominator, const int denominator);
	Rational& operator=(const Rational& rhs) = default;
	Rational(const Rational& copy) = default;
	bool operator == (const Rational& rhs) const { return (nom == rhs.nom) && (denom == rhs.denom); }
	bool operator != (const Rational& rhs) const { return !operator==(rhs); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	Rational operator-() const { return Rational(nom * (-1), denom); }
	bool operator >(const Rational& rhs) const
	{
		if (rhs.denom != denom)
			return denom < rhs.denom;
		else
			return nom > rhs.nom;
	}
	bool operator <(const Rational& rhs) const
	{
		if (rhs.denom != denom)
			return denom > rhs.denom;
		else
			return nom < rhs.nom;
	}
	bool operator >=(const Rational& rhs) const
	{
		if (rhs.denom != denom)
		{
			if (denom < rhs.denom || denom == rhs.denom)
				return true;
			else return false;
		}
		else
		{
			if (nom == rhs.nom || nom > rhs.nom)
				return true;
			else return false;
		}
	}
	bool operator <=(const Rational& rhs) const
	{
		if (rhs.denom != denom)
		{
			if (denom > rhs.denom || denom == rhs.denom)
				return true;
			else return false;
		}
		else
		{
			if (nom == rhs.nom || nom < rhs.nom)
				return true;
			else return false;
		}
	}/*
	int nom = { 0 };
	int denom = { 1 };*/
	int gcd(int a, int b)
	{
		while (a)
		{
			int c = b % a;
			b = a;
			a = c;
		}
		return b;
	}
	void reduce()
	{
		int a = gcd(nom, denom);
		nom /= a;
		denom /= a;
		if (denom < 0)
		{
			denom *= (-1);
			nom *= (-1);
		}
	}
	int nom{ 0 };
	int denom{ 1 };
	
	static const char slash{ '/' };
};
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);


#endif
