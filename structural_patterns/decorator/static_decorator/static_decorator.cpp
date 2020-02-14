#include <string>
#include <iostream>
#include <sstream>


struct Shape 
{
	virtual std::string str() const = 0;
};


struct Circle : Shape
{
	float radius;

	explicit Circle (const float _radius)
	: radius(_radius){}

	void resize(float factor) { radius *= factor;}

	std::string str() const override {
		std::ostringstream oss;
		oss << "There is a beautiful circle with radius " << radius;
		return oss.str();
	}

};

struct Square : Shape
{
	float side_size;

	explicit Square (const float _side_size)
	: side_size(_side_size){}

	void resize(float factor) { side_size *= factor;}

	std::string str() const override {
		std::ostringstream oss;
		oss << "There is a beautiful square with the side size " << side_size;
		return oss.str();
	}

};

template <typename T>
struct ColoredShape : T 
{
	std::string color;

	template <typename ...Args>	
	ColoredShape(const std::string & _color,Args ...args)
		:color{_color}, T(std::forward<Args>(args)...){}

	std::string str() const override {
		std::ostringstream oss;
		oss << T::str() << " has a color " << color;
		return oss.str();
	}
};

template <typename T>
struct TransparentShape : T
{
	uint8_t transparency;
	
	template <typename ...Args>
	TransparentShape(const uint8_t & _transparency,Args ...args)
		: transparency{_transparency}, T(std::forward<Args>(args)...){}

	std::string str() const override {
		std::ostringstream oss;
		oss << T::str() << " has "<< static_cast<float>(transparency) / 255.f*100.f << "% transparency";
		return oss.str();	
	}


};
int main()
{
	// easy to init 
	ColoredShape<TransparentShape<Square>> sq = {"red", 52, 5};
	
	std::cout << sq.str() << std::endl;
	
	// easy to work with
	sq.color = "green";
	sq.transparency = 230;
	sq.side_size = 17; 

	std::cout << sq.str() << std::endl;
	return 0;

}
