#include "Person.h"
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

Person::~Person(){}
