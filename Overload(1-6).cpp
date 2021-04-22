#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
class Fraction
{
public:
	const int numerator;
	const int denominator;
	int f_(int x, int y);
	Fraction(const int x, const int y);
	Fraction operator + (Fraction f);
	Fraction operator - (Fraction f);
	Fraction operator * (Fraction f);
	Fraction operator / (Fraction f);
	friend bool operator > (Fraction c,Fraction f)
	{	
		Fraction d = c - f;
		if (d.numerator * d.denominator > 0) return true;
		else return false;
	}
	friend bool operator < (Fraction c,Fraction f)
	{
		Fraction d = c - f;
		if (d.numerator * d.denominator < 0) return true;
		else return false;
	}
	friend ostream& operator << (ostream &os, const Fraction c)
	{
		assert(c.denominator != 0);
		if (c.numerator % c.denominator == 0) os << c.numerator / c.denominator << endl;
		else os << abs(c.numerator * c.denominator) / abs(c.denominator) << " / " << c.numerator * c.denominator / abs(c.numerator) << endl;
		return os;
	}
	void print();
};
template <class val>
val get_max(val x, val y)
{
	return (x > y ? x : y);
}
int main()
{
	Fraction f(-1, -2);
	Fraction c(1, 1);
	Fraction sum = f + c + f;
	sum.print();
	// kết quả vẫn in ra số nguyên và không mắc lỗi
	(f - c).print();
	(f * c).print();
	(f / c).print();
	cout << max(c, f);
	cout << get_max(c,f);
	return 0;
}

Fraction::Fraction(const int x, const int y) : numerator(x / f_(x, y)), denominator(y / f_(x, y)) {};
int Fraction::f_(int x, int y)
{
	x = abs(x);
	y = abs(y);
	if (x % y == 0) return y;
	if (y % x == 0) return x;
	while (true)
	{
		if (x > y) x = x % y;
		if (y % x == 0) return x;
		if (y > x) y = y % x;
		if (x % y == 0) return y;
		if (x == y) return x;
	}
	return 1;
}
Fraction Fraction :: operator + (Fraction f)
{
	assert(f.denominator != 0);
	assert(this->denominator != 0);
	Fraction c(this->numerator * f.denominator + this->denominator * f.numerator, this->denominator * f.denominator);
	return c;
}
Fraction Fraction :: operator - (Fraction f)
{
	assert(f.denominator != 0);
	assert(this->denominator != 0);
	Fraction c(this->numerator * f.denominator - this->denominator * f.numerator, this->denominator * f.denominator);
	return c;
}
Fraction Fraction :: operator * (Fraction f)
{
	assert(f.denominator != 0);
	assert(this->denominator != 0);
	Fraction c(this->numerator * f.numerator, this->denominator * f.denominator);
	return c;
}
Fraction Fraction :: operator / (Fraction f)
{
	assert(f.denominator != 0);
	assert(this->denominator != 0);
	Fraction c(this->numerator * f.denominator, this->denominator * f.numerator);
	return c;
}
void Fraction::print()
{
	if (this->numerator % this->denominator == 0) cout << this->numerator << endl;
	else cout << abs(this->numerator * this->denominator) / abs(this->denominator) << " / " << this->numerator * this->denominator / abs(this->numerator) << endl;
}
