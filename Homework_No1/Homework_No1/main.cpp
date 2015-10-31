#include<iostream>
#include <sstream>
#include<string>
#include "Stack.h"
using namespace std;

bool IsNumber(char c){
	return(c >= '0' && c <= '9');
}

bool IsAlpha(char c){
	return(c >= 'A' && c <= 'Z');
}
int ToNumber(char c){
	return(c - '0');
}

string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--)
		out << s;
	return out.str();
}

string operator*(unsigned int n, const string& s) { return s * n; }


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


			string x;
			do
			{
				t = reverse.top();
				reverse.pop();
				if (t != '('){
					x.push_back(t);
				}
			} while (reverse.GetArrSize() > 0);
			unsigned int mult = atoi(x.c_str());



			string clear;
			for (string::iterator it = x.begin(); it != x.end(); ++it){
				if (!IsNumber(*it)){
					clear.push_back(*it);
				}
			}
			decompressed = clear * mult;

			for (string::iterator it = decompressed.begin(); it != decompressed.end(); ++it){
				original.push(*it);
			}
			index = original.GetTop();
		}
	}
	return original;
}

int main(){
	
	string expression("2(2(A)3(B))");
	Stack result = decompress(expression);
	std::cout << "result: ";
	result.print();

	return 0;
}