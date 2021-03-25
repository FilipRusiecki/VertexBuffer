
#include "MyVector3.h"
#include <string.h>
const float  PI = 3.14159265358979f;

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0f },
	y{ 0.0f },
	z{ 0.0f }
{
}


MyVector3::~MyVector3()
{
}


/// to string vector
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	y = t_y;
	z = t_z;
}


MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = t_sfVector.x;
	y = t_sfVector.y;
	z = t_sfVector.z;
}

MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = 0.0f;

}


//////////////////////////////////////////////////////////
MyVector3::operator sf::Vector2f()
{
	return sf::Vector2f{ x, y };
}
//////////////////////////////////////////////////////////
MyVector3::operator sf::Vector2u()
{
	return sf::Vector2u{};
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////A method to return the length of the vector
float MyVector3::length() const
{
	// declaration of variable + length  done
	float length{ 0.0f };
	length = sqrtf((x * x, y * y, z * z));
	return length;
}
////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////// A method to return the length squared of the vector
float MyVector3::lengthSquared() const
{
	// declaration of variable + length squared done
	float lengthSquared{ 0.0f };
	lengthSquared = ((x * x, y * y, z * z));
	return lengthSquared;
}
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////// A method to reduce the length of the vector to 1.0 
void MyVector3::normalise()
{
	const float originalLength = length();
	if (originalLength != 0.0f)
	{
		x /= originalLength;
		y /= originalLength;
		z /= originalLength;
	}
}
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////to return the vector product of 2 vectors
float MyVector3::dot(const MyVector3 t_other) const
{
	// declaration of the relevent variables aswell as the calculations to find the dot product
	float dotProduct{ 0.0f };
	dotProduct = ((x * t_other.x + y * t_other.y + x * t_other.z));
	return dotProduct;
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////Adding 2 vectors
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);

}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////Minus 2 vectors
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////Multiply 
MyVector3 MyVector3::operator*(const float t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
MyVector3 MyVector3::operator*(double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
MyVector3 MyVector3::operator*(int t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
MyVector3 MyVector3::operator*(MyVector3 t_scalar)
{
	return MyVector3(t_scalar.x * t_scalar.x, t_scalar.y + t_scalar.y, t_scalar.z *t_scalar.z);
}
//////////////////////////////////////////////////////////










