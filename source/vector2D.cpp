#include "vector2D.hpp"


void Vector2D::add(const Vector2D& vec)
{
	xpos += vec.xpos;
	ypos += vec.ypos;
}
void Vector2D::sub(const Vector2D& vec)
{
	xpos -= vec.xpos;
	ypos -= vec.ypos;
}
void Vector2D::mul(const double& num)
{
	xpos *= num;
	ypos *= num;
}
void Vector2D::div(const double& num)
{
	if (num != 0)
	{
		xpos /= num;
		ypos /= num;
	}
}

Vector2D operator+(const Vector2D& vec1, const Vector2D& vec2)
{
	return Vector2D(vec1.xpos + vec2.xpos, vec1.ypos + vec2.ypos);
}
Vector2D operator-(const Vector2D& vec1, const Vector2D& vec2)
{
	return Vector2D(vec1.xpos - vec2.xpos, vec1.ypos - vec2.ypos);
}
Vector2D operator*(const Vector2D& vec1, const double& number)
{
	return Vector2D(vec1.xpos * number, vec1.ypos * number);
}
Vector2D operator/(const Vector2D& vec1, const double& number)
{
	if (number != 0) return Vector2D(vec1.xpos / number, vec1.ypos / number);
	else return Vector2D(vec1.xpos, vec1.ypos);
}

Vector2D& Vector2D::operator += (const Vector2D& vec)
{
	xpos += vec.xpos;
	ypos += vec.ypos;
	return *this;
}
Vector2D& Vector2D::operator -= (const Vector2D& vec)
{
	xpos -= vec.xpos;
	ypos -= vec.ypos;
	return *this;
}
Vector2D& Vector2D::operator *= (const double& num)
{
	xpos *= num; 
	ypos *= num;
	return *this;
}
Vector2D& Vector2D::operator /= (const double& num)
{
	if (num != 0)
	{
		xpos /= num;
		ypos /= num;
	}
	return *this;
}

