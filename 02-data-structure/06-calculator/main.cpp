#include <iostream>
#include "InfixToPostfix.h"

int main()
{
    std::string exp1 = "1 + 2 * 3";
    std::string exp2 = "(1 + 2) * 3";
    std::string exp3 = "((1 - 2) + 3) * (5 - 2)";

    std::cout << exp1 << " = " << Calculate(exp1) << std::endl;
    std::cout << exp2 << " = " << Calculate(exp2) << std::endl;
    std::cout << exp3 << " = " << Calculate(exp3) << std::endl;
	
    return 0;
}