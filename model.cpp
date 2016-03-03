#include "model.hpp"

Calc::Calc()
{}

void Calc::addChar(const char c) throw (model_exception &)
{
	// On vérifie le caractère
	bool ok = (c == '0' or c == '1' or c == '2' or c == '3' or c == '4' or c == '5' or c == '6' or c == '7' or c == '8' or c == '9' or c == '.' );
       
    if (!ok) 
	{	
		throw(new model_exception("Calc::addChar(const char c) --> Le caractère n'est pas accepté." ));
	}

	_stringCreateValue.push_back(c);
}

void Calc::pushValue()
{
	if (_stringCreateValue.size() == 0) return;
	std::istringstream iss(_stringCreateValue);
	double number;
	assert(iss >> number);
	_stackValues.push(number);
	_stringCreateValue.clear();
}

int Calc::opPriority(const int ope)
{
	switch (ope)
	{
		case PLUS:
		case MINUS:
			return 2;
		case TIMES:
		case DIV:
			return 3;
		case SQUARE:
			return 4;
		case BRACKETL:
		case BRACKETR:
			return 1;	
	}
	// Default --> Renvoyer lorsque l'utilisateur appuie sur égale
	return 0;
}

int Calc::opArite(const int ope) throw (model_exception &)
{
	switch (ope)
	{
		case PLUS:
		case MINUS:
		case TIMES:
		case DIV:
			return 2;
		case SQUARE:
			return 1;
		case BRACKETL:
		case BRACKETR:
			return 0;
	}
	
	throw ( new model_exception("Calc::opArite(const int ope) --> L'opérateur  n'est pas reconnu."));
	exit(EXIT_FAILURE);
	return -1;
}

void Calc::doCompute(const int nextOpe) throw (model_exception &)
{
	// On ne calcule pas ce qu'il y a avant une parenthèse ouvrante
	if ( nextOpe == BRACKETL ) return;

	while ( _stackOpe.size() > 0 && opPriority(_stackOpe.top()) >= opPriority(nextOpe) )
	{
		int ope=_stackOpe.top();
		_stackOpe.pop();

		// Si on a terminé un calcul entre parenthèse, on s'arrete
		if (ope == BRACKETL && nextOpe == BRACKETR ) break;
		
		double x=0,y=0;
		
		if (opArite(ope) > 0)
		{
			if (_stackValues.empty()) continue;
			y = _stackValues.top();
			_stackValues.pop();
		}
		
		if (opArite(ope) > 1)
		{
			if (_stackValues.empty()) continue;
			x = _stackValues.top();
			_stackValues.pop();
		}

		switch (ope)
		{
			case PLUS:
				_stackValues.push(x+y);
				break;
			case MINUS:
				_stackValues.push(x-y);
				break;
			case TIMES:
				_stackValues.push(x*y);
				break;
			case DIV:
			{
				if ( ((y==0)or(x==0)) ) 
				{
					throw (new model_exception("MATH ERROR"));
				}
				else
					_stackValues.push(x/y);
				break;
			}
			case SQUARE:
				_stackValues.push(y*y);
				break;
		}
	}
}

void Calc::plus()
{
	pushValue();
	doCompute(PLUS);
	_stackOpe.push(PLUS);
}

void Calc::minus()
{
	pushValue();
	doCompute(MINUS);
	_stackOpe.push(MINUS);
}

void Calc::times()
{
	pushValue();
	doCompute(TIMES);
	_stackOpe.push(TIMES);
}

void Calc::divide() throw (model_exception&)
{
	pushValue();
	doCompute(DIV);
	_stackOpe.push(DIV);
}

void Calc::square()
{
	pushValue();
	doCompute(SQUARE);
	_stackOpe.push(SQUARE);
}


double Calc::equal() throw (model_exception &)
{	
	pushValue();
	doCompute(-1);

	if (_stackValues.empty()) return 0;
		else if (_stackValues.size() == 1) return _stackValues.top();
			else 
			{
				throw (new model_exception("Calc::equal() --> La pile _stackValues contient plus d'1 valeur"));
				exit(EXIT_FAILURE);
			}
	return 0;
}

void Calc::bracketL()
{
	pushValue();
	doCompute(BRACKETL);
	_stackOpe.push(BRACKETL);
}

void Calc::bracketR()
{
	pushValue();
	doCompute(BRACKETR);
	// Pas d'insertion de parenthèse droite puisque l'on traite le calcul
}
