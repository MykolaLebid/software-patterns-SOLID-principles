#include <string>
#include <iostream>
#include <memory>
class PersonBuilder;
class Person 
{
public:
//adress	
	std::string street_address, post_code, city;

//employment
	std::string company_name, position;
	int annual_income = 0;
	Person() {}
public:
	static std::unique_ptr<PersonBuilder> create(){	
		return std::make_unique<PersonBuilder>();		
	}; 
};

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase 
{
protected:
	Person& person;
	explicit PersonBuilderBase(Person& _person)
		: person{ _person} {}
public:
	operator Person()
	{
		return std::move(person);
	}
// builder facets 

	PersonAddressBuilder lives() const ;
	
	PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
	Person p; // object being built
public:
	PersonBuilder() : PersonBuilderBase{p} {}
};

class PersonAddressBuilder : public PersonBuilderBase 
{
	typedef PersonAddressBuilder self;
public:
	explicit PersonAddressBuilder(Person & person)
		:PersonBuilderBase{ person} {}

	self& at(std::string street_address){
		person.street_address = street_address;
		return *this;
	}

	self& with_postcode( std::string post_code){
		person.post_code= post_code;
		return *this;
	} 

	self& in(std::string city){
		person.city = city;
		return *this;
	}
};


class PersonJobBuilder : public PersonBuilderBase 
{
	typedef PersonJobBuilder self;
public:
	explicit PersonJobBuilder(Person & person)
		:PersonBuilderBase{ person} {}


	self& at(std::string company){
		person.company_name = company;
		return *this;
	}
	self& as_a(std::string profession){
		person.position = profession;
		return *this;
	}
};


int main(){
	Person p = Person::create()->lives().at("123 London Road").with_postcode("SW1 1Gb").in("London").works().at("PragmaSoft").as_a("Consultant");
	return 0;

}
