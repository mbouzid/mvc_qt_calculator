#pragma once

#include <stack>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <assert.h>

enum typeOp {
	PLUS,
	MINUS,
	TIMES,
	DIV,
	SQUARE,
	BRACKETL,
	BRACKETR
};

class Calc
{
	private:
		std::stack<double> _stackValues;
		std::string _stringCreateValue;
		std::stack<char> _stackOpe;
		

	public:
		Calc();
		void addChar(const char);
		void pushValue();
		
		int opPriority(const int op);
		int opArite(const int op);
		void doCompute(const int nextOpe);
		
		void plus();
		void minus();
		void times();
		void divide();
		void square();
		double equal();

		void bracketL();
		void bracketR();

};

