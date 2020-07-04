#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

#include "constants.h"

#include "objects.h"

class Visitor
{
public:
	virtual void visit(Figure &figure) = 0;
	virtual void visit(Camera &camera) = 0;
	virtual void visit(Composite &composite) = 0;
};

class MoveVisitor: public Visitor
{
private:
	double _dx, _dy, _dz;

public:
	MoveVisitor(double dx, double dy, double dz);

	virtual void visit(Figure &figure) override;
	virtual void visit(Camera &camera) override;
	virtual void visit(Composite &composite) override;
};

class ScaleVisitor: public Visitor
{
private:
	double _kx, _ky, _kz;

public:
	ScaleVisitor(double kx, double ky, double kz);

	virtual void visit(Figure &figure) override;
	virtual void visit(Camera &camera) override;
	virtual void visit(Composite &composite) override;
};

class RotateVisitor: public Visitor
{
private:
	double _angleX, _angleY, _angleZ;

public:
	RotateVisitor(double angleX, double angleY, double angleZ);

	virtual void visit(Figure &figure) override;
	virtual void visit(Camera &camera) override;
	virtual void visit(Composite &composite) override;
};

class DrawVisitor: public Visitor
{
private:
	// Тут должен быть drawer.
public:
	virtual void visit(Figure &figure) override;
	virtual void visit(Camera &camera) override;
	virtual void visit(Composite &composite) override;
};
