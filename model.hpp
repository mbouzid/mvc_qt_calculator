#pragma once

#include <stack>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <model_exception.hpp>

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
		void addChar(const char) throw (model_exception&);
		void pushValue();
		
		int opPriority(const int op);
		int opArite(const int op) throw (model_exception&);
		void doCompute(const int nextOpe) throw (model_exception&) ;
		
		void plus();
		void minus();
		void times();
		void divide() throw (model_exception&);
		void square();
		double equal() throw (model_exception&) ;

		void bracketL();
		void bracketR();
		
		
		bool hasResult() const
		{
			return (_stackValues.size() == 1 );
		}
		
		
		const std::string & get_value() const
		{
			return _stringCreateValue;
		}
		
		~Calc()
		{}
};
