#pragma once

class Point
{
private:
	double _x, _y, _z;

public:
	Point() = default;
	Point(double x, double y, double z) : _x(x), _y(y), _z(z){};

	void set(double, double, double);

	double getX() const { return _x; }
	double getY() const { return _y; }
	double getZ() const { return _z; }
};