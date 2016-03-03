#pragma once

#include <iostream>
#include <string>
#include <exception>

class model_exception : public std::exception 
{
	private :
		
		std::string m_what ;
		
	public :
		
		model_exception( const std::string & what ):m_what(what){;}
		
		const char * what() const throw()
		{
			return m_what.c_str();
		}
		
		~model_exception() throw()
		{}
		
};
