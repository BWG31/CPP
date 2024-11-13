#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *ptr = new Data();
	Data *start, *end;
	uintptr_t	tmp = 0;

	start = ptr;	//	Copy initial pointer

	std::cout << "ptr &:\t" << ptr << std::endl;	//	Starting ptr address
	tmp = Serializer::serialize(ptr);				//	Convert to uintptr_t
	std::cout << "tmp:\t" << tmp << std::endl;		//	Display conversion
	
	ptr = NULL;		//	Remove only address reference to Data object
	
	ptr = Serializer::deserialize(tmp);				//	Restore pointer from uintptr_t
	std::cout << "ptr &:\t" << ptr << std::endl;	//	Display restored ptr
	std::cout << *ptr << std::endl;					//	Display object contents

	end = ptr;		// Copy restored pointer

	if (start == end)
		std::cout << "Pointers are equal!" << std::endl;
	else
		std::cout << "Pointers are NOT equal!" << std::endl;

	delete ptr;
	return (0);
}
