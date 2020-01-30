#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include <algorithm>
struct Point 
{
	int x,y;
};

struct Line
{
	Point begin, end;
};

struct VectorObject
{
	virtual std::vector<Line>::iterator begin() = 0;
	virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject 
{
	VectorRectangle(int x, int y, int width, int height)
	{
		lines.emplace_back(Line{Point{x, y}, Point{x + width,y}});
		lines.emplace_back(Line{Point{x + width, y}, Point{x + width,y + height}});
		lines.emplace_back(Line{Point{x, y}, Point{x,y + height}});
		lines.emplace_back(Line{Point{x, y + height}, Point{x + width,y + height}});
	}
	
	//override
	std::vector<Line>::iterator begin() override {
		return lines.begin();
	}
	
	std::vector<Line>::iterator end() override {
		return lines.end();
	}
	private:
	std::vector<Line> lines;
};

struct LineToPointAdapter
{
	typedef std::vector<Point> Points;
	LineToPointAdapter(Line& line){
		const auto [minX, maxX] = std::minmax(line.begin.x, line.end.x);
		const auto [minY, maxY] = std::minmax(line.begin.y, line.end.y);
		
		for(int i = minX; i<=maxX; i++)
			for(int j = minY; j<=maxY; j++)
				points.emplace_back(Point{i,j});	
	}
	
	virtual Points::iterator begin () {return points.begin();};
	virtual Points::iterator end () {return points.end();};
	Points points;
};

void DrawPoints(std::vector<Point>::iterator begin_it, 
		std::vector<Point>::iterator end_it){
	std::for_each(begin_it, end_it, [](auto & it){
		       			 std::cout << "(" << it.x << ";" 
					 	          << it.y << ")" << std::endl;});
}
	
int main()
{
	std::vector<std::shared_ptr<VectorObject>> vectorObjects{
		std::make_shared<VectorRectangle>(10,10,100,100),
		std::make_shared<VectorRectangle>(30,30,60,60)
	}; 
	for (auto& obj :vectorObjects){
		for(auto & line: *obj){
			LineToPointAdapter lpo{line};
			DrawPoints(lpo.begin(),lpo.end());
		}
	}
	return 0;
}

