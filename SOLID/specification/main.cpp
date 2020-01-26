#include <vector>
#include <iostream>

enum class Color {Red, Green, Blue};
enum class Size {Tiny, Medium, Large};

struct Product{
	std::string name;
	Color color;
	Size size;
};

template<typename T> struct AndSpecification;


template<typename T> struct Specification{
	virtual bool is_specified(T&) = 0;
       	
	AndSpecification<T> operator&&(Specification& rhs){
		return AndSpecification<T>(*this, rhs);
	}
};


template<typename T> struct AndSpecification :
Specification<T>
{
        Specification<T> & first;
	Specification<T> & second;
	
	explicit AndSpecification(Specification<T> & _lhs,
				  Specification<T> & _rhs)
		 :first{_lhs}, second{_rhs} {}
	bool is_specified(T& item) override
	{
		return first.is_specified(item) && 
		       second.is_specified(item);
	}

};

struct ColorSpecification: Specification<Product>{
	Color color;
	explicit ColorSpecification(const Color _color)
		: color{_color}{}; 
	bool is_specified(Product& P) override
		{return color == P.color;};
};

struct SizeSpecification: Specification<Product>{
	Size size;
	explicit SizeSpecification(const Size _size)
		: size{_size}{};
	bool is_specified(Product& P) override
		{return size == P.size;};
};

template<typename T> struct Filter{
	std::vector<T*> vec; 
	virtual std::vector<T*> filter(
		std::vector<T*> items,
		Specification<T> & specification) = 0;
};

struct ProductFilter: Filter<Product>{
	std::vector<Product*> filter(
		std::vector<Product*> product_items,
		Specification<Product> & specification 
		) override {
	std::vector<Product*> result_items;
	for(auto p:product_items)
		if(specification.is_specified(*p)) 
			result_items.push_back(p);
	return result_items;	
	}
};

int main(){

	Product apple{"Apple", Color::Green, Size::Tiny};
	Product tree{"Tree", Color::Green, Size::Large};
	Product house{"House", Color::Red, Size::Large};


	ColorSpecification green(Color::Green); 
	SizeSpecification large(Size::Large);

//	auto green_and_large = ColorSpecification(Color::Green) 
//			    && SizeSpecification(Size::Large); 
	auto green_and_large = green && large;
	std::vector<Product*> all{&apple, &tree, &house};
	
	//AndSpecification<Product> green_and_large(green,large);
	ProductFilter pf;
	auto filtered_all = pf.filter(all, green_and_large);
	for(auto p: filtered_all)
		std::cout << "Product: " << p->name << " is green and large" << std::endl;

	return 0;	

       	

}; 
