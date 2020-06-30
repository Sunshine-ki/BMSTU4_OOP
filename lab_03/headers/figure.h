#pragma once 

#include <iostream>
#include <vector>
#include <memory>

#include "object.h"
#include "point.h"
#include "link.h"

// class Figure: public Object
class Figure
{
private:
	std::vector<Point> _points;
	std::vector<Link> _links;
public:
	Figure(Figure &);
	Figure() = default;
	~Figure() = default;
	
	void addPoint(Point &p);
	void addLink(Link &l);

	// std::vector<Point> &getPoints();
    // std::vector<Link> &getLinks();
	void print();
};