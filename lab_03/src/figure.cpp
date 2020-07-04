#include "objects.h"
#include "visitor.h"

void Figure::print()
{
	std::cout << "Points:\n";
	for (int i = 0; i < _points.size(); i++)
		std::cout << _points[i].getX() <<  " " << _points[i].getY() << " "
				  << _points[i].getZ() << std::endl;

	std::cout << "Links::\n";
	for (int i = 0; i < _links.size(); i++)
		std::cout << _links[i].getFirst() << _links[i].getLast() << std::endl;
}

void Figure::addPoint(Point &p)
{
	_points.push_back(p);
}

void Figure::addLink(Link &l)
{
	_links.push_back(l);
}

Figure::Figure(Figure &obj)
{
	_points = obj._points;
	_links = obj._links;
}

void Figure::transform(Matrix<double, 4> &matrix)
{
	for (int i = 0; i < _points.size(); i++)
	{
		MathVector<double, 4> vec = {_points[i].getX(), _points[i].getY(), _points[i].getZ(), 1};
	    vec.multiplication(matrix);
		_points[i].set(vec.at(0), vec.at(1), vec.at(2));
	}
}

void Figure::accept(std::shared_ptr<Visitor> visitor) 
{
	visitor->visit(*this);
}