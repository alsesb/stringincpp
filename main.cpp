#include "stringMain.h"
#include <iostream>


int main(){
	String thread, twine, rope("Hello");
	thread = "world";
	thread += "\n";
	rope += " ";
	twine = rope + thread;

	if(twine(0,4) == String("Hell"))
		std::cout << "Heaven" << std::endl;
		
	std::cout << twine << std::endl;
	twine[6] = 'W';
	std::cout << twine << std::endl;
	const String hang{"one two three"};
	std::cout << twine << std::endl;
	std::cout << hang[2] << std::endl;

	return 0;
	
}
