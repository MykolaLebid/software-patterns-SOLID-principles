#include <iostream>
#include <memory>
#include <vector>
#include <map>
struct HotDrink
{
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	void prepare(int volume) override {
	std::cout << "Take tea bag, boil water, pour " 
		  << volume << "ml, add some lemon" << std::endl; 
	}

};


struct Coffee : HotDrink
{
	void prepare(int volume) override {
	std::cout << "Take coffee bag, boil water, pour " 
		  << volume << "ml, add some sugar" << std::endl; 
	}

};

// Abstact Factory 
struct HotDrinkFactory
{
	virtual std::unique_ptr<HotDrink> make() = 0;
};

struct CoffeeFactory : HotDrinkFactory
{
	std::unique_ptr<HotDrink> make () override {
		return std::make_unique<Coffee>();
	}
};

struct TeaFactory : HotDrinkFactory
{
	std::unique_ptr<HotDrink> make () override {
		return std::make_unique<Tea>();
	}
};

class DrinkFactory 
{
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_drink_factory;
	public:
	DrinkFactory(){
		hot_drink_factory["coffee"] = std::make_unique<CoffeeFactory>();
		hot_drink_factory["tea"] = std::make_unique<TeaFactory>();
	}
	
	std::unique_ptr<HotDrink> make_hot_drink(std::string hot_drink_name, unsigned int ml){
		auto drink = hot_drink_factory[hot_drink_name]->make();	
		drink->prepare(ml);	
		return drink;
	}
};
int main()
{
	DrinkFactory d_f;
	std::unique_ptr<HotDrink> ptr_hot_drink = d_f.make_hot_drink("coffee", 38);
	return 0;
};
