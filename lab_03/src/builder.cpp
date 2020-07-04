#include "builder.h"

bool FigureBuilder::create()
{
	std::shared_ptr<Figure> figure(new Figure());
	_figure = figure;
	return true;
}


bool FigureBuilder::fillPoints(std::vector<Point> &points)
{
	if (!points.size())
		return false;
	for (size_t i = 0; i < points.size(); i++)
		_figure->addPoint(points[i]);
	return true;
}

bool FigureBuilder::fillLinks(std::vector<Link> &links)
{
	if (!links.size())
		return false;
	for (size_t i = 0; i < links.size(); i++)
	{
		if (links[i].getLast() < 0 or links[i].getFirst() < 0)
			return false;
		_figure->addLink(links[i]);
	}
	return true;
}

std::shared_ptr<Figure> FigureBuilder::returnResult() 
{
	return _figure;
}

std::shared_ptr<Figure> Director::createFigure(std::vector<Point> &points, std::vector<Link> &links)
{
	if (_builder->create() && _builder->fillPoints(points) && _builder->fillLinks(links))
		return _builder->returnResult();
	return std::shared_ptr<Figure>();
}
