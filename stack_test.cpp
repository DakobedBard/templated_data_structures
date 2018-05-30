
#include "stack.h"
#include <iostream>
int main(){

	Stack<int, 10> s ; // stack of 10 chars
	s.push(3);
	int k = s.pop();
	std::cout << k << std::endl;
}
