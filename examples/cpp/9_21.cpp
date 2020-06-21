// Пример 21. Свойство (Property).
# include <iostream>
# include <memory>

using namespace std;

template <typename Owner, typename Type>
class Property
{
private:
	using Getter = Type (Owner::*)() const;
	using Setter = void (Owner::*)(const Type&);

	Owner* owner; 		// Указатель на сам объект.
	Getter methodGet;	// Указатель на Getter 
	Setter methodSet;	// Указатель на Setter 

public:
	Property() = default;
	Property(Owner* owr, Getter getmethod, Setter setmethod) : owner(owr), methodGet(getmethod), methodSet(setmethod) {}

	void init(Owner* owr, Getter getmethod, Setter setmethod)
	{
		owner = owr;
		methodGet = getmethod;
		methodSet = setmethod;
	}

	operator Type() { return (owner->*methodGet)();	}					// Getter
	void operator=(const Type& data) {	(owner->*methodSet)(data); }	// Setter

//	Property(const Property&) = delete;
//	Property& operator=(const Property&) = delete;
};

class Object
{
private:
	double value;

public:
	Object(double v) : value(v) { Value.init(this, &Object::getValue, &Object::setValue); }

	double getValue() const { return value; }
	void setValue(const double& v) { value = v; }

	Property<Object, double> Value;
};

int main()
{
	Object obj(5.);

	cout << "value = " << obj.Value << endl;

	obj.Value = 10.;

	cout << "value = " << obj.Value << endl;

	unique_ptr<Object> ptr(new Object(15.));

	cout << "value =" << ptr->Value << endl;

	obj = *ptr;
	obj.Value = ptr->Value;
}