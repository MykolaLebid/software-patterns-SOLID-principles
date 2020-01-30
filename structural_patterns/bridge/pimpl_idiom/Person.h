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

