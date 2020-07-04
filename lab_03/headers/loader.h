#pragma once

#include <iostream>
#include <string.h>

#include "constants.h"
#include "objects.h"


class BaseLoader
{
public:
	virtual bool open(std::string fileName) = 0;
	virtual bool readPoints(std::vector<Point> &points) = 0;
	virtual bool readLinks(std::vector<Link> &links) = 0;
	virtual bool close() = 0;
};

class FileLoader : public BaseLoader
{
public:
	virtual bool open(std::string fileName) override;
	virtual bool readPoints(std::vector<Point> &points) override;
	virtual bool readLinks(std::vector<Link> &links) override;
	virtual bool close() override;

private:
	FILE *_f;
};

class Loader
{
public:
	virtual std::shared_ptr<Figure> loadFigure(std::string fileName) = 0;
	virtual void setLoader(std::shared_ptr<BaseLoader> &loader) {_loader = loader;}

protected:
	std::shared_ptr<BaseLoader> _loader;
};

class FigureLoader: public Loader
{
public:
	FigureLoader(std::shared_ptr<BaseLoader> &loader) { _loader = loader;}
	virtual std::shared_ptr<Figure> loadFigure(std::string fileName) override;
};