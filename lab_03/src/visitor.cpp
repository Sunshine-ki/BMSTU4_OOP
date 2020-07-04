#include "visitor.h"

#include "constants.h"

ScaleVisitor::ScaleVisitor(double kx, double ky, double kz)
{
	_kx = kx;
	_ky = ky;
	_kz = kz;
}

MoveVisitor::MoveVisitor(double dx, double dy, double dz)
{
	_dx = dx;
	_dy = dy;
	_dz = dz;
}

RotateVisitor::RotateVisitor(double angleX, double angleY, double angleZ)
{
	_angleX = angleX * M_PI / 180;
	_angleY = angleY * M_PI / 180;
	_angleZ = angleZ * M_PI / 180;
}

void ScaleVisitor::visit(Figure &figure)
{
	Matrix<double, 4> matrix = MATRIX_SCALE(_kx, _ky, _kz);
	figure.transform(matrix);
}

void ScaleVisitor::visit(Camera &camera)
{
	Matrix<double, 4> matrix = MATRIX_SCALE(_kx, _ky, _kz);
	camera.transform(matrix);
}

void ScaleVisitor::visit(Composite &composite)
{
	Matrix<double, 4> matrix = MATRIX_SCALE(_kx, _ky, _kz);
	composite.transform(matrix);
}

void MoveVisitor::visit(Figure &figure)
{
	Matrix<double, 4> matrix = MATRIX_MOVING(_dx, _dy, _dz);
	figure.transform(matrix);
}

void MoveVisitor::visit(Camera &camera)
{
	Matrix<double, 4> matrix = MATRIX_MOVING(_dx, _dy, _dz);
	camera.transform(matrix);
}

void MoveVisitor::visit(Composite &composite)
{
	Matrix<double, 4> matrix = MATRIX_MOVING(_dx, _dy, _dz);
	composite.transform(matrix);
}

void RotateVisitor::visit(Figure &figure)
{
	Matrix<double, 4> matrixX = MATRIX_ROTATE_X(_angleX);
	Matrix<double, 4> matrixY = MATRIX_ROTATE_Y(_angleY);
	Matrix<double, 4> matrixZ = MATRIX_ROTATE_Z(_angleZ);

	figure.transform(matrixX);
	figure.transform(matrixY);
	figure.transform(matrixZ);
}

void RotateVisitor::visit(Camera &camera)
{
	Matrix<double, 4> matrixX = MATRIX_ROTATE_X(_angleX);
	Matrix<double, 4> matrixY = MATRIX_ROTATE_Y(_angleY);
	Matrix<double, 4> matrixZ = MATRIX_ROTATE_Z(_angleZ);

	camera.transform(matrixX);
	camera.transform(matrixY);
	camera.transform(matrixZ);
}

void RotateVisitor::visit(Composite &composite)
{
	Matrix<double, 4> matrixX = MATRIX_ROTATE_X(_angleX);
	Matrix<double, 4> matrixY = MATRIX_ROTATE_Y(_angleY);
	Matrix<double, 4> matrixZ = MATRIX_ROTATE_Z(_angleZ);

	composite.transform(matrixX);
	composite.transform(matrixY);
	composite.transform(matrixZ);
}

void DrawVisitor::visit(Figure &figure)
{
	figure.print();
}

void DrawVisitor::visit(Camera &camera)
{
	camera.print();
}

void DrawVisitor::visit(Composite &composite)
{
	std::cout << "visit drawer composite";
	// 
	// camera.print();
}