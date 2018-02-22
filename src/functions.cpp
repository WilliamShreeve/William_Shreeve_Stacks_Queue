
#include "../include/functions.h"
#include <string>
#include <stack>

/**********************************************************************
 * This class contains two functions. One is balanced symbols,
 * which will check to ensure any symbol of the following (,{, or [ 
 * has a corresponding, matching symbol before a new symbol is 
 * declared. The second takes an infix expression and converts it 
 * to post-fix.
 * 
 * @author William Shreeve
 * @version Winter 2018
 *
 * *******************************************************************/


/*********************************************************************
 * balanced symbols takes an input and checks it has balanced (,{, and
 * [ characters (i.e., they have matching corresponding characters.
 *
 * @param input to check fo balance
 * @return boolean of true if balanced, or false if not.
 * *******************************************************************/
bool balancedSymbols(std::string input){
	
	std::stack<char, std::deque<char> > symbols;
	
	for(std::string::iterator it = input.begin(); it!=input.end(); it++){
		if(*it == '(' || *it == '[' || *it == '{')
			symbols.push(*it);
		else {
			if(*it == ')'){
				if(symbols.top() == '(')
					symbols.pop();
				else
					return false;
			}
			else if(*it == ']'){
				if(symbols.top() == '[')
					symbols.pop();
				else
					return false;
			}
			else if(*it == '}'){
				if(symbols.top() == '{')
					symbols.pop();
				else
					return false;
			} 		
		}	
	}

	if(symbols.empty())
		return true;
	
	return false;
}
/**********************************************************************
 * Helper method to find the priority of each symbol. Returns 0 if 
 * not an operator.
 * 
 * @param character to find priority
 * @return integer of priority
 * *******************************************************************/
int prec(char c){
	int p=0;
	switch(c){
		case '+':
		case '-':
			p = 1;
			break;
		case '*':
		case '/':
			p = 2;
			break;
		case '^':
			p = 3;
			break;
		case '(':
		case ')':
			p = -1;
			break;
		default:
			p = 0;
			break;
	}	
	return p;
}

/**********************************************************************
 * iToP takes an infix expression, and returns a string of the
 * converted postfix expression.
 *
 * @param input infix string to be converted
 * @return converted postfix string
 * *******************************************************************/
std::string iToP(std::string input){
	std::string output = "";
	
	std::stack<char, std::deque<char> > ops;

	for(std::string::iterator it = input.begin(); it != input.end(); it++){
			
		//If character isn't an operator, add to output.
		if(prec(*it) == 0){
			output += *it;
		}
		//If parenthesis, push it
		else if(*it == '('){
			ops.push(*it);
		}

		//If end of parenthesis
		else if(*it == ')'){
			//While the top isn't the matching parenthesis
			while(ops.top() != '(' && !ops.empty()){
				output += ops.top();
				ops.pop();
			}
			//Pop the remaining parenthesis
			ops.pop();
		}

		//If stack is empty, add operator
		else if(ops.empty()){
			ops.push(*it);
		}	
		
		//If priority of operator is less than the top of stack
		else if(prec(*it) < prec(ops.top())){
			while(!ops.empty() && ops.top() != '('){
				output += ops.top();
				ops.pop();
			}
			ops.push(*it); 	
		}
		
		//If priority of operator is greater/equal to top of stack
		else if(prec(*it) >= prec(ops.top())){
			ops.push(*it);
		}
	}
	//Pop the remaining symbols to the stack
	while(!ops.empty()){
		if(ops.top() != '(' || ops.top() != ')')
			output += ops.top();
		ops.pop();
	}
	return output;
}




