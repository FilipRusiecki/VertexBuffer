#ifndef MYVECTOR3_HPP 
#define MYVECTOR3_HPP




#include <iostream>
#include <SFML/Graphics.hpp>


class MyVector3
{
public:
	float x;
	float y;
	float z;

	MyVector3();
	~MyVector3();
	std::string toString();


	
	MyVector3(double t_x, double t_y, double t_z);
	MyVector3(sf::Vector3f t_sfVector);
	MyVector3(sf::Vector3i t_sfVector);
	MyVector3(sf::Vector2i t_sfVector);
	MyVector3(sf::Vector2u t_sfVector);
	MyVector3(sf::Vector2f t_sfVector); 
	
	
	MyVector3 operator +(const MyVector3 t_right) const;
	MyVector3 operator -(const MyVector3 t_right) const;
	MyVector3 operator *(const float t_scalar) const;
	MyVector3 operator *(double t_scalar) const;
	MyVector3 operator *(int t_scalar) const;
	MyVector3 operator *(MyVector3 t_scalar);




	float length()const;
	float lengthSquared()const;
	float dot(const MyVector3 t_other) const;
	void normalise(); 
	
	operator sf::Vector2f(); 
	operator sf::Vector2u(); 

};


#endif // !MYVECTOR3_HPP
