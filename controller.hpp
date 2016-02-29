#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>

#include "model.hpp"

class controller : public QObject
{
	Q_OBJECT

	private :
	
		Calc m_model ;
	
	private slots :
	
		void add_comma()
		{
			m_model.addChar('.');
			emit change_text(",");
		}
		
		void add_zero( )
		{	
			m_model.addChar('0');
			emit change_text(QString::number(0));
			
		}
		
		void add_one( )
		{	
			m_model.addChar('1');
			emit change_text(QString::number(1));
			
		}
		
		void add_two( )
		{	
			m_model.addChar('2');
			emit change_text(QString::number(2));
			
		}
		
		void add_three( )
		{	
			m_model.addChar('3');
			emit change_text(QString::number(3));
			
		}
		
		void add_four( )
		{	
			m_model.addChar('4');
			emit change_text(QString::number(4));
			
		}
		
		void add_five( )
		{	
			m_model.addChar('5');
			emit change_text(QString::number(5));
			
		}
		
		void add_six( )
		{	
			m_model.addChar('6');
			emit change_text(QString::number(6));
			
		}
		
		void add_seven( )
		{	
			m_model.addChar('7');
			m_model.pushValue();
			emit change_text(QString::number(7));
			
		}
		
		void add_eight( )
		{	
			m_model.addChar('8');
			emit change_text(QString::number(8));
			
		}
		
		void add_nine( )
		{	
			m_model.addChar('9');
			emit change_text(QString::number(9));
			
		}
		
		
		void add_plus()
		{
				m_model.plus()  ;
				emit change_text("+");
		}
		
		void add_minus(  )
		{
				m_model.minus() ;
				emit change_text("-");
		}
		
		void add_times( )
		{
				m_model.times()  ;
				emit change_text("*");
		}
		
		void add_divide( )
		{
				m_model.divide() ;
				emit change_text("/");
		}
		
		void equal( )
		{
				emit change_text("=");
				emit change_text( QString::number(m_model.equal()) ) ;
		}
		
		void add_bracket_l( )
		{
				m_model.bracketL() ;
				emit change_text(")");
		}
		
		void add_bracket_r(  )
		{
				m_model.bracketR() ;
				emit change_text("(");
		}
		
		void add_square( )
		{
				emit change_text("^2");
				m_model.square() ;
		}
		
		
	signals :
		void result( const QString & res ) ;
		void change_text( const QString & expr);
	public :
	
		controller():m_model()
		{
			
		}
	
	
};
