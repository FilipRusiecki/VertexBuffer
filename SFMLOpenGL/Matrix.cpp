#include "Matrix.h"
#include <math.h>
# define M_PI           3.14159265358979323846 
Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(MyVector3 Row1, MyVector3 Row2, MyVector3 Row3)
{
///////////////////
	A11 = Row1.x;
	A12 = Row1.y;
	A13 = Row1.z;
///////////////////

///////////////////
	A21 = Row1.x;
	A22 = Row1.y;
	A23 = Row1.z;
///////////////////

///////////////////
	A31 = Row1.x;
	A32 = Row1.y;
	A33 = Row1.z;
///////////////////
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21, double _A22, double _A23, double _A31, double _A32, double _A33)
{
///////////////////
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
///////////////////

///////////////////
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
///////////////////

///////////////////
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
///////////////////

}

MyVector3 Matrix3::operatorMultiply(Matrix3 M1, MyVector3 V1)
{
	MyVector3 newVecotor = { M1.A11 * V1.x + M1.A12 * V1.y + M1.A13 * V1.z,
							 M1.A21 * V1.x + M1.A22 * V1.y + M1.A23 * V1.z,
							 M1.A31 * V1.x + M1.A32 * V1.y + M1.A33 * V1.z };

	return newVecotor;
}

MyVector3 Matrix3::operatorMultiply(MyVector3 V1, Matrix3 M1)
{
	MyVector3 newVecotor = { M1.A11 * V1.x + M1.A21 * V1.y + M1.A31 * V1.z,
							 M1.A12 * V1.x + M1.A22 * V1.y + M1.A32 * V1.z,
							 M1.A13 * V1.x + M1.A23 * V1.y + M1.A33 * V1.z };

	return newVecotor;
}

Matrix3 Matrix3::transpose(Matrix3 M1)
{
	return Matrix3(M1.A11, M1.A21, M1.A31,
				   M1.A12, M1.A22, M1.A32,
			   	   M1.A13, M1.A23, M1.A33);
}



Matrix3 Matrix3::operatorAdd(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.A11 + M2.A11, M1.A12 + M2.A12, M1.A13 + M2.A13,
				   M1.A21 + M2.A21, M1.A22 + M2.A22, M1.A23 + M2.A23,
				   M1.A31 + M2.A31, M1.A32 + M2.A32, M1.A33 + M2.A33);
}

Matrix3 Matrix3::operatorMinus(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.A11 - M2.A11, M1.A12 - M2.A12, M1.A13 - M2.A13,
				   M1.A21 - M2.A21, M1.A22 - M2.A22, M1.A23 - M2.A23,
				   M1.A31 - M2.A31, M1.A32 - M2.A32, M1.A33 - M2.A33);
}

Matrix3 Matrix3::operatorMultiply(double x, Matrix3 M1)
{
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = M1.A11 * x;
	newMatrix.A12 = M1.A12 * x;
	newMatrix.A13 = M1.A13 * x;

	newMatrix.A21 = M1.A21 * x;
	newMatrix.A22 = M1.A22 * x;
	newMatrix.A23 = M1.A23 * x;

	newMatrix.A31 = M1.A31 * x;
	newMatrix.A32 = M1.A32 * x;
	newMatrix.A33 = M1.A33 * x;

	return newMatrix;
}

Matrix3 Matrix3::operatorMultiplyTwoMatrix(Matrix3 M1, Matrix3 M2)
{
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = M1.row(0).x * M2.row(0).x;
	newMatrix.A12 = M1.row(0).y * M2.row(0).y;
	newMatrix.A13 = M1.row(0).z * M2.row(0).z;

	newMatrix.A21 = M1.row(1).x * M2.row(1).x;
	newMatrix.A22 = M1.row(1).y * M2.row(1).y;
	newMatrix.A23 = M1.row(1).z * M2.row(1).z;

	newMatrix.A31 = M1.row(2).x * M2.row(2).x;
	newMatrix.A32 = M1.row(2).y * M2.row(2).y;
	newMatrix.A33 = M1.row(2).z * M2.row(2).z;

	return Matrix3(newMatrix);
}

double Matrix3::Determinant(Matrix3 M1)
{
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

MyVector3 Matrix3::row(int i)
{
	switch (i)
	{
	case 0:
		return MyVector3{ A11, A12, A13 };
	case 1:
		return MyVector3{A21, A22, A23};
	case 2:
	default:
		return MyVector3{ A31, A32, A33 };
	}
	
}

MyVector3 Matrix3::column(int i)
{
	switch (i)
	{
	case 0:
		return MyVector3{ A11, A21, A31 };
	case 1:
		return MyVector3{ A12, A22, A32 };
	case 2:
	default:
		return MyVector3{ A13, A23, A33};
	}
}

Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	double det = Determinant(M1);
	if (det == 0)
		return  Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 newMatrix =  Matrix3();
		newMatrix.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		newMatrix.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		newMatrix.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		newMatrix.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		newMatrix.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		newMatrix.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		newMatrix.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		newMatrix.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		newMatrix.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return newMatrix;
	}
}

Matrix3 Matrix3::Rotation(int _angle)
{
	double radians = M_PI / 180 * _angle;
	Matrix3 newMatrix =  Matrix3();
	newMatrix.A11 = cos(radians);
	newMatrix.A12 = sin(radians);
	newMatrix.A13 = 0;
	newMatrix.A21 = -sin(radians);
	newMatrix.A22 = cos(radians);
	newMatrix.A23 = 0;
	newMatrix.A31 = 0;
	newMatrix.A32 = 0;
	newMatrix.A33 = 1;

	return newMatrix;
}

Matrix3 Matrix3::Translate(int dx, int dy)
{
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = 1;
	newMatrix.A12 = 0;
	newMatrix.A13 = 0;
	newMatrix.A21 = 0;
	newMatrix.A22 = 1;
	newMatrix.A23 = 0;
	newMatrix.A31 = dx;
	newMatrix.A32 = dy;
	newMatrix.A33 = 1;

	return newMatrix;
}

Matrix3 Matrix3::Scale(int dx, int dy)
{
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = (double)dx / 100;
	newMatrix.A12 = 0;
	newMatrix.A13 = 0;
	newMatrix.A21 = 0;
	newMatrix.A22 = (double)dy / 100;
	newMatrix.A23 = 0;
	newMatrix.A31 = 0;
	newMatrix.A32 = 0;
	newMatrix.A33 = 1;

	return newMatrix;
}

Matrix3 Matrix3::operator-(Matrix3 M1)
{
	Matrix3 newVector = Matrix3();
	newVector.A11 *= -1;
	newVector.A12 *= -1;
	newVector.A13 *= -1;

	newVector.A21 *= -1;
	newVector.A22 *= -1;
	newVector.A23 *= -1;

	newVector.A31 *= -1;
	newVector.A32 *= -1;
	newVector.A33 *= -1;
	return newVector;
}

Matrix3 Matrix3::RotationX(int _angle)
{
	double radians = M_PI / 180 * _angle;
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = 1;
	newMatrix.A12 = 0;
	newMatrix.A13 = 0;
	newMatrix.A21 = 0;
	newMatrix.A22 = cos(radians);
	newMatrix.A23 = -sin(radians);
	newMatrix.A31 = 0;
	newMatrix.A32 = sin(radians);
	newMatrix.A33 = cos(radians);

	return newMatrix;
}

Matrix3 Matrix3::RotationY(int _angle)
{
	double radians = M_PI / 180 * _angle;
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = cos(radians);
	newMatrix.A12 = 0;
	newMatrix.A13 = sin(radians);
	newMatrix.A21 = 0;
	newMatrix.A22 = 1;
	newMatrix.A23 = 0;
	newMatrix.A31 = -sin(radians);
	newMatrix.A32 = 0;
	newMatrix.A33 = cos(radians);

	return newMatrix;
}

Matrix3 Matrix3::RotationZ(int _angle)
{
	double radians = M_PI / 180 * _angle;
	Matrix3 newMatrix =  Matrix3();
	newMatrix.A11 = cos(radians);
	newMatrix.A12 = -sin(radians);
	newMatrix.A13 = 0;
	newMatrix.A21 = sin(radians);
	newMatrix.A22 = cos(radians);
	newMatrix.A23 = 0;
	newMatrix.A31 = 0;
	newMatrix.A32 = 0;
	newMatrix.A33 = 1;

	return newMatrix;
}

Matrix3 Matrix3::Scale3D(int dx)
{
	Matrix3 newMatrix = Matrix3();
	newMatrix.A11 = (double)dx / 100;
	newMatrix.A12 = 0;
	newMatrix.A13 = 0;
	newMatrix.A21 = 0;
	newMatrix.A22 = (double)dx / 100;
	newMatrix.A23 = 0;
	newMatrix.A31 = 0;
	newMatrix.A32 = 0;
	newMatrix.A33 = (double)dx / 100;

	return newMatrix;
}

