// Пример 22. Посетитель (Visitor).
# include <iostream>
# include <memory>
# include <vector>

using namespace std;

class Circle;
class Rectangle;
class triangle;


class Visitor
{
public:
	// virtual ~Visitor() = default;

	virtual void visit(Circle& ref) = 0;
	virtual void visit(Rectangle& ref) = 0;
	virtual void visit(triangle& ref) = 0;

};

class Shape
{
public:
	// virtual ~Shape() = default;

	virtual void accept(shared_ptr<Visitor> visitor) = 0;
};

class Circle : public Shape
{
public:
	// 
	virtual void accept(shared_ptr<Visitor> visitor)  override { visitor->visit(*this);	}
};

class triangle : public Shape
{
public:
	// 
	virtual void accept(shared_ptr<Visitor> visitor)  override { visitor->visit(*this);	}
};


class Rectangle : public Shape
{
public:
	virtual void accept(shared_ptr<Visitor> visitor)  override { visitor->visit(*this);	}
};

class ConVisitor : public Visitor
{
public:
	virtual void visit(Circle& ref) override { cout << "Circle;" << endl; }
	virtual void visit(Rectangle& ref) override { cout << "Rectangle;" << endl; }
	virtual void visit(triangle& ref) override { cout << "triangle;" << endl; }

};

class Formation
{
public:
	static vector<shared_ptr<Shape>> initialization(shared_ptr<Shape> elem, ...)
	{
		vector<shared_ptr<Shape>> vec;

		for (shared_ptr<Shape>* ptr = &elem; *ptr; ++ptr)
			vec.push_back(*ptr);

		return vec;		
	}
};

int main()
{
	// vector<shared_ptr<Shape>> figure = Formation::initialization(
	// 	shared_ptr<Shape>(new Circle()),
	// 	shared_ptr<Shape>(new Rectangle()),
	// 	shared_ptr<Shape>(new Circle()),
	// 	shared_ptr<Shape>(new triangle()),
	// 	shared_ptr<Shape>()
	// );
	shared_ptr<Visitor> visitor(new ConVisitor());
	shared_ptr<Shape> c(new Circle());

	c->accept(visitor);

	// for (auto& elem : figure)
		// elem->accept(visitor);
}
