#include <iostream>

struct Render
{
	virtual void render_circle(int x, int y, int radius) = 0;
};


struct RasterRender : Render
{
	void render_circle(int x, int y, int radius) override {
		std::cout << "We render in Raster a circle with radius "
			<< radius << " and the center ("
			<< x << "; " << y << ")" << std::endl;
	}
};


struct VectorRender : Render
{
	void render_circle(int x, int y, int radius) override {
		std::cout << "We render in Vector a circle with radius "
			<< radius << " and the center ("
			<< x << "; " << y << ")" << std::endl;
	}
};

struct Shape 
{
protected:
	Render& render;
	Shape(Render& _render): render{_render}{};
public:
	virtual void draw() = 0;
	virtual void scale (int factor) = 0;
};

struct Circle : Shape {

	int x,y,radius;

	void scale (int factor) override {
		radius*=factor;	
	}

	void draw () override {
		render.render_circle(x,y,radius);
	}
	
	Circle(Render& _render, int _x, int _y, int _radius)
		: Shape{_render}, x{_x}, y{_y}, radius{_radius} {}
	
};

int main()
{
	RasterRender rr;
	Circle raster_circle{rr, 5,5,5};
	raster_circle.draw();

	return 0;
}
