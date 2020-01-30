#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
struct GraphicalObject
{
	virtual void draw() = 0;
};

struct Group : GraphicalObject 
{
	std::string name;
	using item = std::unique_ptr<GraphicalObject>;
	std::vector<item> group;
	
	explicit Group(const std::string& _name):name{_name}{}
	
	void draw() override {
		std::cout<< "Group: " << name << " contains:" << std::endl;
//		for (item& a: group)
//		{
//			a->draw();
//		}
		std::for_each(group.begin(), group.end(), 
				[](auto& i){
					i->draw();
				}
			     );	

		std::cout<<"-----------"<<std::endl;
	} 		
};

struct Circle : GraphicalObject 
{
	void draw() override 
	{
		std::cout << "Circle" << std::endl; 
	}
};


struct Square : GraphicalObject 
{
	void draw() override 
	{
		std::cout << "Square" << std::endl; 
	}
};

int main()
{

	//Circle c1;
	//Square s1,s3;
	std::unique_ptr<Group> g1 = std::make_unique<Group>("g1"); 
	Group g2("g2");
	g1->group.emplace_back(std::make_unique<Circle>());
	g1->group.emplace_back(std::make_unique<Square>());
	g2.group.emplace_back(std::move(g1));
	g2.draw();
//	g1.group.push_back(std::make_unique<Circle>());
//	g1.group.push_back(std::make_unique<Square>());
//	g2.group.emplace_back(std::move(g1));
	//g2.group.push_back(&s3);
	//g2.draw();
		

	return 0;
};
