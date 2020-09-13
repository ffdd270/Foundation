#include <iostream>
#include <string>
#include "ExpressionTree.h"

int main()
{
    std::string exp = "12+7*";
    BtreeNode<int>* eTree = MakeExpTree(exp);

    std::cout << "전위 표기법의 수식 : ";
    ShowPrefixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "중위 표기법의 수식 : ";
    ShowInfixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "후위 표기법의 수식 : ";
    ShowPostfixTypeExp(eTree);
    std::cout << std::endl;

    std::cout << "계산 결과 : " << EvaluateExpTree(eTree);
    return 0;
}