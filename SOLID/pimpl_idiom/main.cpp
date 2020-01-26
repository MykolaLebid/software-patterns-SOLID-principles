#include <iostream>
#include <memory>

struct Person
{
	std::string name;
	void greet();
	Person();

	~Person();
	struct PersonImpl;

	std::unique_ptr<PersonImpl> impl;
};

struct Person::PersonImpl
{
	void greet(Person* p);
};

Person::Person()
	: impl(std::make_unique<PersonImpl>()) {}

void Person::greet() 
{
	impl->greet(this);
}

void Person::PersonImpl::greet(Person* p)
{
	std::cout<<"hello " << p->name << std::endl;
}

