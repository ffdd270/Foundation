#include "LinkedList.h"
#include <cassert>

template <typename T>
bool is_nullptr(T* any_ptr) noexcept;

int main(void) try
{
	LinkedList<int> list;
	
	std::cout << "------------- Test 1 -------------\n";
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(5);
	list.push_back(10);

	std::cout << list << std::endl;
	list.print();
	std::cout << std::endl;

	std::cout << "------------- Test 2 -------------\n";
	Node<int>* searched_node_1 = list.search(3);
	std::cout << std::boolalpha << is_nullptr(searched_node_1) << std::endl;

	Node<int>* searched_node_2 = list.search(4);
	std::cout << std::boolalpha << is_nullptr(searched_node_2) << std::endl;

	
	
	std::cout << "------------- Test 3 -------------\n";
	Node<int>* data = list.search(2);
	list.remove(data);

	std::cout << list << std::endl;
	list.print();
	std::cout << std::endl;

	

	std::cout << "------------- Test 4 -------------\n";
	std::cout << static_cast<int>(list.size()) << std::endl;



	std::cout << "------------- Test 5 -------------\n";
	list.print();
	std::cout << std::endl;


	
	std::cout << "------------- Test 6 -------------\n";
	LinkedList<int> list2 = { 4, 10, 12 };

	list += list2;
	std::cout << list << std::endl;
	list.print();
	std::cout << std::endl;


	
	std::cout << "------------ Test END ------------\n";

	return 0;
}
catch (std::exception& e)
{
	std::cout << e.what() << std::endl;
}

template<typename T>
bool is_nullptr(T* any_ptr) noexcept
{
	if(any_ptr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
