#include <vector>
#include <iostream>




template <typename Self>// inheritor class of SomeNeurons 
struct SomeNeurons
{
	template <typename T> 
	void connect_to(T& other){
		for(auto& from : *static_cast<Self*>(this))// we want to iterate over dereference Self(inheritor class)
			for(auto& to : other){
				from.out.push_back(&to);
				to.in.push_back(&from);
			};
		
	};
// print part
	void print(){
		print_sub_layers(0);
	};
	private:
	void print_sub_layers(unsigned int shift){	
		shift+=2;
		std::string tab (shift, ' ');
	        for(auto& n: *static_cast<Self*>(this)){
			std::cout << tab <<"|_"<< n.id <<" ";
			std::cout << std::endl; 		
			for(auto& sub_n: n.out)
				sub_n->print_sub_layers(shift);
		};
		
		

	};
};
struct Neuron: SomeNeurons<Neuron> 
{
	std::vector <Neuron* > in, out;
	unsigned int id;

	Neuron (){
		static int id = 1;
		this->id = id ++;	
	}
	
	
	Neuron* begin() {return this;} // mimic iterator
	Neuron* end() {return this + 1;}
			
};

struct NeuronLayer: std::vector<Neuron>, SomeNeurons<NeuronLayer> 
{
	NeuronLayer(int count){
		while(count-- > 0)
			emplace_back(Neuron{});
	}
};



int main()
{
	Neuron n1, n2, n3;
	NeuronLayer nL1(2), nL2(3), nL3(4);
	n1.connect_to(n2);	
	n2.connect_to(nL1);
	nL1.connect_to(nL2);
	nL2.connect_to(n3);        
	
	n1.print();	
	
	return 0;

}
