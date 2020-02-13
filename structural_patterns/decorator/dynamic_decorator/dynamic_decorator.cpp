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
		oss << "There is a beautiful square with the side size" << side_size;
		return oss.str();
	}

};

struct ColoredShape : Shape 
{
	Shape& shape;
	std::string color;
	
	ColoredShape(Shape& _shape, const std::string & _color)
		:shape{_shape}, color{_color}{}

	std::string str() const override {
		std::ostringstream oss;
		oss << shape.str() << " has a color " << color;
		return oss.str();
	}
};


struct TransparentShape : Shape
{
	Shape& shape;
	uint8_t transparency;

	TransparentShape(Shape& _shape, const uint8_t & _transparency)
		: shape{_shape}, transparency{_transparency}{}

	std::string str() const override {
		std::ostringstream oss;
		oss << shape.str() << " has "<< static_cast<float>(transparency) / 255.f*100.f << "% transparency";
		return oss.str();	
	}


};
int main()
{
	Circle circle{0.5f};
	ColoredShape redCircle{circle,"red"};
	ColoredShape greenCircle(circle, "green");
	TransparentShape halfTransparentGreenCircle(greenCircle, 23);

	std::cout << redCircle.str() << std::endl;
	std::cout << halfTransparentGreenCircle.str() << std::endl;
	return 0;

}
