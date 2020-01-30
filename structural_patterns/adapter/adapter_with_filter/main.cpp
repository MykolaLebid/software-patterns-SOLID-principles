#include <boost/functional/hash.hpp>
#include <map>
#include <vector>
#include <iostream>

struct Point 
{
	int x,y;

	friend std::size_t hash_value(const Point &obj)
	{
		std::size_t seed = 0x7253686F;
		boost::hash_combine(seed, obj.x);
		boost::hash_combine(seed, obj.y);
		return seed;
	}	
};


struct Line
{
	Point begin, end;
	friend std::size_t hash_value(const Line &obj){
		std::size_t seed = 0x1234fE3A;
		boost::hash_combine(seed, obj.begin);
		boost::hash_combine(seed, obj.end);
		return seed;
	}
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


typedef std::vector<Point> Points;
struct LineToPointCachingAdapter
{
	static std::map<std::size_t, Points> cache;
	
	size_t line_hash;
	LineToPointCachingAdapter(Line& line){
		static boost::hash<Line> hash;
		line_hash = hash(line);	
		
		if (cache.find(line_hash) != cache.end())
		{	
			line_hash = 0;
			cache[line_hash] = {{0,0},{0,0}};
			return;
		};
	
		std::cout << "line_hash"<<line_hash << std::endl;
		Points point;
		const auto [minX, maxX] = std::minmax(line.begin.x, line.end.x);
		const auto [minY, maxY] = std::minmax(line.begin.y, line.end.y);
		
		for(int i = minX; i<=maxX; i++)
			for(int j = minY; j<=maxY; j++)
				points.emplace_back(Point{i,j});	
	
		cache[line_hash] = points;
	}
	
	virtual Points::iterator begin () {return cache[line_hash].begin();};
	virtual Points::iterator end () {return cache[line_hash].end();};
	Points points;
};
std::map<std::size_t, Points> LineToPointCachingAdapter::cache;
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
		std::make_shared<VectorRectangle>(30,30,60,60),
		std::make_shared<VectorRectangle>(10,10,100,100),
		std::make_shared<VectorRectangle>(30,30,60,60)
	}; 
	int j = 0;
	for (auto& obj :vectorObjects){
		
//		std::cout<< ++i << std::endl;
		for(auto & line: *obj){
			LineToPointCachingAdapter lpo{line};
			DrawPoints(lpo.begin(),lpo.end());
			std::cout << ++j << std::endl;
		}
	}

	return 0;
}

