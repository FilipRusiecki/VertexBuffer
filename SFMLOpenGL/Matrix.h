#pragma once
#include <iostream>
#include "MyVector3.h"


class Matrix3
{

public:
	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;

	Matrix3();
	Matrix3(MyVector3 Row1, MyVector3 Row2, MyVector3 Row3);
	Matrix3(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33);

	MyVector3 operatorMultiply(Matrix3 M1, MyVector3 V1);
	MyVector3 operatorMultiply(MyVector3 V1, Matrix3 M1);
	Matrix3 transpose(Matrix3 M1);
	Matrix3 operatorAdd(Matrix3 M1, Matrix3 M2);
	Matrix3 operatorMinus(Matrix3 M1, Matrix3 M2);
	Matrix3 operatorMultiply(double x, Matrix3 M1);
	Matrix3 operatorMultiplyTwoMatrix(Matrix3 M1, Matrix3 M2);
	double Determinant(Matrix3 M1);
	MyVector3 row(int i);
	MyVector3 column(int i);
	Matrix3 Inverse(Matrix3 M1);
	Matrix3 Rotation(int _angle);
	Matrix3 Translate(int dx, int dy);
	Matrix3 Scale(int dx, int dy);
	Matrix3 operator -(Matrix3 M1);
	Matrix3 RotationX(int _angle);
	Matrix3 RotationY(int _angle);
	Matrix3 RotationZ(int _angle);
	Matrix3 Scale3D(int dx);
};
