#include<iostream>
#include <sstream>
#include<string>
#include "Stack.h"
using namespace std;

bool IsNumber(char c){
	return(c >= '0' && c <= '9');
}

string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--)
		out << s;
	return out.str();
}

string operator*(unsigned int n, const string& s) { 
	return s * n; 
}

string removeNumbers(string arg){
	string clear;
	for (string::iterator it = arg.begin(); it != arg.end(); ++it){
		if (!IsNumber(*it)){
			clear.push_back(*it);
		}
	}
	return clear;
}

string expand(Stack& reverse){
	string x;
	char t;
	do
	{
		t = reverse.top();
		reverse.pop();
		if (t != '('){
			x.push_back(t);
		}
	} while (reverse.GetArrSize() > 0);

	unsigned int mult = atoi(x.c_str());

	x = removeNumbers(x);

	string decompressed = x * mult;
	return decompressed;
}

Stack decompress(string expression){
	Stack original;
	string decompressed;

	int index = 0;
	for (string::iterator it = expression.begin(); it != expression.end(); ++it){
		if (*it != ')'){
			if (IsNumber(*it)){
				original.push(*it);
				index = original.GetTop();
			}
			else{
				original.push(*it);
			}
		}
		if (*it == ')'){
			Stack reverse;
			char t;

			if (original.GetTop() == index){
				while (original.GetTop() >= 0){
					t = original.top();
					reverse.push(t);
					original.pop();
				}
			}
			else{
				while (original.GetTop() >= index){
					t = original.top();
					reverse.push(t);
					original.pop();
				}
			}

			string expanded = expand(reverse);

			for (string::iterator it = expanded.begin(); it != expanded.end(); ++it){
				original.push(*it);
			}
			index = original.GetTop();
		}
	}
	return original;
}

int main(){
	
	string expression;
	cout << "expression: " << '\n';
	getline(cin, expression);
	Stack result = decompress(expression);
	std::cout << "result: ";
	result.print();

	return 0;
}