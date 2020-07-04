#include "loader.h"
#include "builder.h"


bool FileLoader::open(const char *fileName)
{
	_f = fopen(fileName, MODE_READ);

	if (!_f)
		return false;

	return true;
}

bool FileLoader::readPoints(std::vector<Point> &points)
{
	int count, rc;
	rc = fscanf(_f, "%d", &count);
	if (rc != 1 or count < 0)
		return false;
	// printf("Count points = %d\n", count);

	double x,y,z;
	Point p;
	for (size_t i = 0; i < count; i++)
	{
		rc = fscanf(_f, "%lf %lf %lf", &x, &y, &z);
		if (rc != 3)
			return false;
		// printf("%f %f %f\n", x, y, z);
		p.set(x, y, z);
		points.push_back(p);
	}

	return true;
}

bool FileLoader::readLinks(std::vector<Link> &links)
{
	int count, rc;
	rc  = fscanf(_f, "%d", &count);
	if (rc != 1 or count < 0)
		return false;
	// printf("Count links = %d\n", count);

	int l1, l2;
	Link l;
	for (size_t i = 0; i < count; i++)
	{
		rc = fscanf(_f, "%d %d", &l1, &l2);
		if (rc != 2)
			return false;
		// printf("%d %d\n", l1, l2);
		if (l1 < 0 or l2 < 0)
			return false;
		l.set(l1, l2);
		links.push_back(l);
	}

	return true;
}

bool FileLoader::close()
{
	fclose(_f);
	return true;
}

std::shared_ptr<Figure> FigureLoader::loadFigure(const char *fileName)
{
	std::shared_ptr<Figure> result;

    bool err = _loader->open(fileName);
	if (!err)
	{		
		std::cout << "Error open" << std::endl;
		return result;
	}

    std::vector<Point> points;
    err = _loader->readPoints(points);
	if (!err)
	{		
		std::cout << "Error readPoint" << std::endl;
    	_loader->close();
		return result;
	}    

    std::vector<Link> links;
    err = _loader->readLinks(links);
	if (!err)
	{		
		std::cout << "Error readLinks" << std::endl;
	    _loader->close();
		return result;
	}   

    _loader->close();
	std::shared_ptr<BaseFigureBuilder> builder(new FigureBuilder());
	std::shared_ptr<Director> director(new Director(builder));

	result = director->createFigure(points, links);
	
	return result;
}
