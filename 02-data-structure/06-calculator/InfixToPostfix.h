#pragma once
#include <string>

std::string ConvToRPNExp(const std::string& expression);

int GetOpPrec(char op);

int WhoPrecOp(char op1, char op2);

int EvalRPNExp(const std::string& expression);

int Calculate(const std::string& expression);