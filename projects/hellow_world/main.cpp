#include <iostream>
#include <vector>
#include <string>

/**
 * @brief An example program. This program demonstrates simple vextor storage and element iteration.
 *        A welcome string is output to the user.
 * 
 * @return Returns 0 when execution completes successfully.
 */

int main()
{
	std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

	for (const std::string& word : msg)
	{
		std::cout << word << " ";
	}
	std::cout << std::endl;
	
	std::cin;

}