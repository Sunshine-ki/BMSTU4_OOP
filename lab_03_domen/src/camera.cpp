#include "objects.h"
#include "visitor.h"

void Camera::transform(Matrix<double, 4> &matrix)
{
	MathVector<double, 4> vec = {_position.getX(), _position.getY(), _position.getZ(), 1};
	vec.multiplication(matrix);
	_position.set(vec.at(0), vec.at(1), vec.at(2));
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
	visitor->visit(*this);
}

Camera::Camera(double nx, double ny, double nz, Point p)
{
	_nx = nx;
	_ny = ny;
	_nz = nz;
	_position.set(p.getX(), p.getY(), p.getZ());
}

void Camera::print()
{
	std::cout << "Norm: " << _nx << " " << _ny << " "  << _nz << std::endl;
	std::cout << "Position: " << _position.getX() << " " << _position.getY() << " " << _position.getZ() << std::endl;
}
