#pragma once

#include <iostream>
#include <memory>

#include "objects.h"
#include "point.h"
#include "link.h"

class BaseFigureBuilder
{
public:
	virtual bool create() = 0;
	virtual bool fillPoints(std::vector<Point> &points) = 0;
	virtual bool fillLinks(std::vector<Link> &links) = 0;
	virtual std::shared_ptr<Figure> returnResult() = 0;
protected:
	std::shared_ptr<Figure> _figure;
};

class FigureBuilder: public BaseFigureBuilder
{
public:
	FigureBuilder() = default; 
	virtual bool create() override;
	virtual bool fillPoints(std::vector<Point> &points) override;
	virtual bool fillLinks(std::vector<Link> &links) override;
	virtual std::shared_ptr<Figure> returnResult() override;
};

class Director
{
private:
	std::shared_ptr<BaseFigureBuilder> _builder;
public:
	Director(std::shared_ptr<BaseFigureBuilder> &builder): _builder(builder) {};
	std::shared_ptr<Figure> createFigure(std::vector<Point> &points, std::vector<Link> &links);
};
