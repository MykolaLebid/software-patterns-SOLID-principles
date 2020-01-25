#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

struct HtmlBuilder;
struct HtmlElement
{
	std::string name = "";
	std::string text = "";
	std::vector<HtmlElement> elements;

	std::string str(int indent = 0) const 
	{
		std::ostringstream oss;
		std::string s_ind(indent, ' ');
	 	if (name!="") oss <<s_ind << "<" << name << ">\n"; 
		if (text!="") oss <<s_ind << " " <<  text << "\n";
		int next_ind = indent + 1;	
		for(HtmlElement h_e: elements)
			oss << h_e.str(next_ind);
	
		if (name!="") oss <<s_ind << "</" << name << ">\n"; 

		return oss.str();
	}

	friend struct HtmlBuilder;
	static std::unique_ptr<HtmlBuilder> build(const std::string& root_name){
		return std::make_unique<HtmlBuilder>(root_name);
	};
protected:
	HtmlElement() {}
	HtmlElement(const std::string& _name, const std::string& _text)
		: name(_name), text(_text) {}
};

struct HtmlBuilder
{
	
	operator HtmlElement() const{return root;};	
	HtmlElement root;
	HtmlBuilder(std::string _root_name){
		root.name = _root_name;
	} 
	
	//fluent interface init
	HtmlBuilder& add_child(std::string child_name, std::string child_text){
		HtmlElement e{child_name, child_text};
		root.elements.emplace_back(e);
		return *this;
	}
	
	std::string str() {return root.str();};	
}; 


int main(){
	HtmlElement e = HtmlElement::build("ul")->add_child("li", "hello").add_child("li", "world");	

	std::cout << e.str() << std::endl;	
	return 0;
}
