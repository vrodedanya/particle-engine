#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>

class Vector2D
{
private:
	double xpos;
	double ypos;
public:
	Vector2D() : xpos(0), ypos(0){}
	Vector2D(double x, double y) : xpos(x), ypos(y){}
	double& x(){return xpos;}
	double& y(){return ypos;}

	const double& x() const {return xpos;}
	const double& y() const {return ypos;}

	void zeroize(){xpos = 0; ypos = 0;}

	double length() {return std::sqrt(std::pow(xpos, 2) + std::pow(ypos, 2));}

	Vector2D& normalize()
	{
		double len = length();
		if (len != 0) *this /= len;
		return *this;
	}

	void add(const Vector2D& vec);
	void sub(const Vector2D& vec);
	void mul(const double& num);
	void div(const double& num);

	friend Vector2D operator+(const Vector2D& vec1, const Vector2D& vec2);
	friend Vector2D operator-(const Vector2D& vec1, const Vector2D& vec2);
	friend Vector2D operator*(const Vector2D& vec1, const double& number);
	friend Vector2D operator/(const Vector2D& vec1, const double& number);

	Vector2D& operator += (const Vector2D& vec);
	Vector2D& operator -= (const Vector2D& vec);
	Vector2D& operator *= (const double& num);
	Vector2D& operator /= (const double& num);
};

Vector2D operator+(const Vector2D& vec1, const Vector2D& vec2);
Vector2D operator-(const Vector2D& vec1, const Vector2D& vec2);
Vector2D operator*(const Vector2D& vec1, const double& number);
Vector2D operator/(const Vector2D& vec1, const double& number);


#endif
