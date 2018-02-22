#include "functions.h"
#include <string>
#include <iostream>

int main(){
	
	
	

	if(balancedSymbols("(s()()()	d{s[]	[]	d[()()sd]ds}ds)"))
		std::cout << "TEST 1 PASS" << std::endl;
	else
		std::cout << "TEST 1 FAIL" << std::endl;
	if(balancedSymbols("({[(}]})"))
		std::cout << "TEST 2 FAIL" << std::endl;
	else
		std::cout << "TEST 2 PASS" << std::endl;
	if(balancedSymbols("((([[[{{{}}}]]])))"))
		std::cout << "TEST 3 PASS" << std::endl;
	else
		std::cout << "TEST 3 FAIL" << std::endl;



	std::cout << iToP("(a+b)*c") << std::endl;
	std::cout << iToP("((a+b)*(c-d)+e)/(f+g)") << std::endl;
}
