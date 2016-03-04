#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtGui/QPushButton>

#include "model.hpp"

class controller : public QObject
{
	Q_OBJECT
			
	private :
	
		Calc m_model ;
		
	public :
	
		controller():m_model()
		{}
		
		~controller()
		{}

	
	public slots :
	
		void add() 
		{
			QPushButton * button = qobject_cast<QPushButton*>(sender());
			
			if ( button )
			{
				
				emit change_text(QString::fromStdString(m_model.get_value())+button->text());
				char label = button->text().at(0).toAscii() ;
				if ( (label >= '0') && ( label <='9' ) )
				{
					m_model.addChar(button->text().at(0).toAscii());
				}
				else
				{
					
					if ( m_model.hasResult() )
					{
						emit result(QString::number(m_model.equal()));
					}
					
					switch ( label )
					{
						case '+' :
						{
							m_model.plus();
							break ;
						}
						case '-' :
						{
							m_model.minus();
							break;
						}
						case '*' :
						{
							m_model.times();
							break;
						}
						case '/' :
						{
							m_model.divide();
							break;
						}
						case '^' :
						{	
							m_model.square();
							break;
						
						}
						case '=' :
						{
							emit result(QString::number(m_model.equal()));
							
							break;
						
						}
						
						case '(' :
						{
							m_model.bracketL();
							break;
						}
						
						case ')' :
						{
							m_model.bracketR();
							break;
						}
						
						
						
					}	
				
					
				}
			
			}
		}
		
		
         
	signals :
		void result( const QString & res ) ;
		void change_text( const QString & expr);

	
};
