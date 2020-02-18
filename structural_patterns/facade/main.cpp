#include <iostream>


class Engine
{

public:
    void Start() { std::cout << "We start an engine" << std::endl;}

};

class Headlights
{

public:
    void TurnOn() { std::cout<< "We turn on head lights" << std::endl;  }

};

//  That's your facade.
class Car
{

private:
    Engine engine;
    Headlights headlights;

public:
    void TurnIgnitionKeyOn()
    {
      	std::cout<<"Key on (then automatically ...)" << std::endl; 
	headlights.TurnOn();
        engine.Start();
    }

};

int main()
{
    //  Consuming facade.
    Car car;
    
    car.TurnIgnitionKeyOn();

    return 0;
}


