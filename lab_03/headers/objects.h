#pragma once

#include <iterator>
#include <iostream>
#include <vector>
#include <memory>

#include "matrix.h"
#include "point.h"
#include "link.h"

class Visitor;
class Object;

using VectorComponent = std::vector<std::shared_ptr<Object>>;
using IteratorComponent = VectorComponent::const_iterator;

class Object
{
public:
	virtual void transform(Matrix<double, 4> &matrix) = 0;
	virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
	virtual bool isComposite() { return false; }
	virtual bool isVisible() { return false; }
	virtual bool add(std::shared_ptr<Object> obj)  { return false; };
	virtual bool remove(const IteratorComponent& it) { return false; }
	virtual IteratorComponent begin() { return IteratorComponent(); }
	virtual IteratorComponent end() { return IteratorComponent(); }
	virtual int getSize() { return -1; }
};

class Figure: public Object
{
private:
	std::vector<Point> _points;
	std::vector<Link> _links;
public:
	Figure(Figure &);
	Figure(std::shared_ptr<Object> o) {std::cout << "z nen\n";}
	Figure() = default;
	~Figure() = default;
	
	void addPoint(Point &p);
	void addLink(Link &l);

	virtual void transform(Matrix<double, 4> &matrix) override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
	virtual bool isVisible()  { return true; }
	//
	void print();
};

class Camera: public Object
{
private:
	double _nx, _ny, _nz;
	Point _position;

public:
	Camera(double nx, double ny, double nz, Point p);
	virtual void transform(Matrix<double, 4> &matrix) override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;
	
	void print();
};

class Composite: public Object
{
private:
	VectorComponent _data;

public:
	virtual void transform(Matrix<double, 4> &matrix) override;
	virtual void accept(std::shared_ptr<Visitor> visitor) override;

	virtual bool isComposite() override;
	virtual bool add(std::shared_ptr<Object> obj) override;
	virtual bool remove(const IteratorComponent& it) override;
	virtual IteratorComponent begin() override;
	virtual IteratorComponent end() override;
	virtual int getSize() override { return _data.size(); }
};


