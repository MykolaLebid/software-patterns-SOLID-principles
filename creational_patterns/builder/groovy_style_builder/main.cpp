#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

struct Tag
{
	std::string name;
	std::string text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		os << tag.name << "   " << tag.text << "\n";
		for(auto& child: tag.children)
			os << child.name
			   << "		"	
			   << child.text << "\n";
		return os;
	}

protected:
	Tag(const std::string& _name, const std::string& _text)
		: name(_name), text(_text) {}	
	Tag(const std::string& _name, const std::vector<Tag>& _children)
		: name(_name), children{_children} {}
};

struct P : Tag 
{
	explicit P(const std::string& _text)
		: Tag{"p", _text} {}
	P(std::initializer_list<Tag> _children)
		: Tag{"p", _children} {}
};

struct IMG : Tag
{
       
	explicit IMG(const std::string& url)
		:Tag{"img", ""}
	{	
		attributes.push_back({"src", url});
	}
};

int main(){
 std::cout << 

	 P {
		 IMG { "http://pokemon.com/pikachu.png"}
	 }
 	<< std::endl;
return 0;

}
