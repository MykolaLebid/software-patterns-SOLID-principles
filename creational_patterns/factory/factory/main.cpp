#include <math.h>
#include <iostream>
struct PointFactory;
struct Point
{
	float x, y;
	friend struct PointFactory;
protected:
	Point(float _x, float _y)
		: x(_x), y(_y){}
};

struct PointFactory
{
	static Point NewPolarPoint(float r, float theta) {
		return Point{r*cos(theta), r*sin(theta)};
	}
	static Point NewCartesianPoint(float x, float y) {
		return Point{x, y}; 
	}
	protected:
	PointFactory(){}
};

int main()
{
	std::cout << "Enter polar point with r = " ; 
	float r;
	std::cin >> r;
	
	std::cout << std::endl << "and theta = ";
	float theta;
	std::cin >> theta;
	
	auto a = PointFactory::NewPolarPoint(r, theta);
	std::cout << "the Cartesian coodinates:(" << a.x << "; " << a.y << ")"<<std::endl;
	return 0;
}
