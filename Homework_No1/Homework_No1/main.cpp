#include<iostream>
#include <sstream>
#include<string>
#include "Stack.h"
#include <time.h>
using namespace std;
//function to decompress and evaluate the expression
bool IsNumber(char c){
	return(c >= '0' && c <= '9');
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

int main(){
	string expr;
	cout << "Enter expression: ";
	getline(cin,expr);

	Stack decompressor;
	string decompressed;
	for (string::iterator it = expr.begin(); it != expr.end(); ++it){
		if (*it != ')'){
			decompressor.push(*it);
		}
		else{
			string temp;
			char t;
			do{
				t = decompressor.pop();
				if (t != '(' && t != ')' && !IsNumber(t)){
					temp.push_back(t);
				}
			} while (!IsNumber(t));
			int val = ToNumber(t);
			decompressed = temp * val;
		}
	}
	for (string::iterator it = decompressed.begin(); it != decompressed.end(); ++it){
		decompressor.push(*it);
	}
	decompressor.print();

	return 0;
}