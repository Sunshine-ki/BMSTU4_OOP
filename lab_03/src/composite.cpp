#include "objects.h"
#include "visitor.h"

void Composite::transform(Matrix<double, 4> &matrix)
{
	for (size_t i = 0; i < _data.size(); i++)
	{
		std::cout << "Next object:\n";
		_data[i]->transform(matrix);
	}
}

bool Composite::isComposite()
{
	return true;
}

bool Composite::add(std::shared_ptr<Object> obj)
{
	_data.push_back(obj);
	return true;
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
	visitor->visit(*this);
}

bool Composite::remove(const IteratorComponent& it)
{
    try 
	{
        _data.erase(it);
    } catch (std::exception &err) 
	{
        return false;
    }
    return true;
}

IteratorComponent Composite::begin()
{
    return _data.begin();
} 


IteratorComponent Composite::end()
{
    return _data.end();
} 
