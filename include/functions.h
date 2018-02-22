#ifndef __H__FUNCTIONS__
#define __H__FUNCTIONS__

#include<string>
	
	//Checks for balanced brackets and parenthesis
	bool balancedSymbols(std::string input);
	
	//Turns valid infix to postfix
	std::string iToP(std::string input);
	
	//Helps return priority of operators
	int prec(char c);
#endif
