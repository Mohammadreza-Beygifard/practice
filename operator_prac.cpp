#include <iostream>

class Position
{
	public:
		int x{10};
		int y{20};
		Position operator +(Position &pos) 
		{
			Position new_pos;
			new_pos.x = x + pos.x;
			new_pos.y = y + pos.y;
			return new_pos;

		};
		std::string print(){ return "x: " + std::to_string(x) + "y: " + std::to_string(y); };
};

int main()
{
	std::cout<<"Hello Operator"<<std::endl;
	
	Position pos1, pos2;
	Position pos3 = pos1 + pos2;

	std::cout<<"new Pos: " << pos3.print() <<std::endl;

	return 0;
}
