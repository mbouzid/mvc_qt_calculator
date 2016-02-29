#pragma once

// qt lib
#include <QtGui/QGridLayout>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtCore/QString>
#include <QtGui/QLineEdit>

// std lib
#include <vector>

// own lib
#include "controller.hpp"

class view 
{
	private :

		QWidget * m_top ;
		QWidget * m_numpad ;
		QWidget * m_operators ;
		std::vector<QPushButton *> m_figures ;
		QPushButton * m_zero ;
		QLineEdit * m_result ;
		controller m_controller ;
		QGridLayout * m_box ;
		
		QPushButton * m_addition ;
		QPushButton * m_substraction ;
		QPushButton * m_multiplication ;
		QPushButton * m_division ;
		QPushButton * m_r_parenthesis;
		QPushButton * m_l_parenthesis ;
		QPushButton * m_square ;
		QPushButton * m_equal ;
		QPushButton * m_comma ;
		
	public :
		
		view( QWidget * top = 0 ): m_top(top)
		{
			
			m_numpad = new QWidget(m_top);
			m_operators = new QWidget(m_top) ;
			
			m_result = new QLineEdit("0",m_top);
			m_result->setReadOnly(true);
			
			QGridLayout * grid_numpad = new QGridLayout(m_numpad) ;
			grid_numpad->setMargin(0); 
			grid_numpad->setVerticalSpacing(0) ;
			grid_numpad->setHorizontalSpacing(0) ;
			
			for( int i=1 ; i<10 ; ++i )
			{
				m_figures.push_back(new QPushButton(QString::number(i),m_numpad) );

			}
			
			m_comma = new QPushButton(",",m_numpad);
			m_zero = new QPushButton(QString::number(0),m_numpad);
			

			
			std::vector<QPushButton*>::reverse_iterator j=m_figures.rbegin() ;
			
			while (  j!= m_figures.rend() )
			{
				for ( int i = 0 ; i < 3 ; ++i )
				{	
					for ( int k = 2 ; k >=0 ; --k )
					{
						grid_numpad->addWidget(*j,i,k);
						++j ;
					}
				}
			}
			
			
			grid_numpad->addWidget(m_zero,3,0,1,2,Qt::Alignment(0));
			grid_numpad->addWidget(m_comma,3,2,1,1,Qt::Alignment(0));
			
			m_addition = new QPushButton("+");
			m_substraction = new QPushButton("-");
			m_multiplication = new QPushButton("*");
			m_division = new QPushButton("/");
			m_r_parenthesis = new QPushButton("(");
			m_l_parenthesis = new QPushButton(")");
			m_square = new QPushButton("^2");
			m_equal = new QPushButton("=");
			
			
			
			QGridLayout * grid_operators = new QGridLayout(m_operators) ;
			grid_operators->setMargin(0); 
			grid_operators->setVerticalSpacing(0) ;
			grid_operators->setHorizontalSpacing(0) ;
			
			
			grid_operators->addWidget(m_addition,0,0);
			grid_operators->addWidget(m_substraction,0,1);
			grid_operators->addWidget(m_multiplication,1,0);
			grid_operators->addWidget(m_division,1,1);
			grid_operators->addWidget(m_r_parenthesis,2,0);
			grid_operators->addWidget(m_l_parenthesis,2,1);
			grid_operators->addWidget(m_square,3,0);
			grid_operators->addWidget(m_equal,3,1);
					
			m_box = new QGridLayout(m_top);
			
			
			m_box->addWidget(m_result,0,0,1,2,Qt::Alignment(0));
			m_box->addWidget(m_numpad,1,0,1,1,Qt::Alignment(0));
			m_box->addWidget(m_operators,1,1,1,1,Qt::Alignment(0));
			
			
			//signals & slots
			
			QObject::connect(m_addition,SIGNAL(clicked()),&m_controller,SLOT(add_plus()) );
			QObject::connect(m_substraction,SIGNAL(clicked()),&m_controller,SLOT(add_minus()) );
			QObject::connect(m_multiplication,SIGNAL(clicked()),&m_controller,SLOT(add_times()) );
			QObject::connect(m_division,SIGNAL(clicked()),&m_controller,SLOT(add_divide()) );
			QObject::connect(m_r_parenthesis,SIGNAL(clicked()),&m_controller,SLOT(add_bracket_r()) );
			QObject::connect(m_l_parenthesis,SIGNAL(clicked()),&m_controller,SLOT(add_bracket_l()) );
			QObject::connect(m_square,SIGNAL(clicked()),&m_controller,SLOT(add_square()) );
			QObject::connect(m_equal,SIGNAL(clicked()),&m_controller,SLOT(equal()) );
			
			QObject::connect(&m_controller,SIGNAL(result(QString)),m_result,SLOT(setText(QString)));
			
			
			QObject::connect(m_zero,SIGNAL(clicked()),&m_controller,SLOT(add_zero()) );
			QObject::connect(m_figures[0],SIGNAL(clicked()),&m_controller,SLOT(add_one()) );
			QObject::connect(m_figures[1],SIGNAL(clicked()),&m_controller,SLOT(add_two()) );
			QObject::connect(m_figures[2],SIGNAL(clicked()),&m_controller,SLOT(add_three()) );
			QObject::connect(m_figures[3],SIGNAL(clicked()),&m_controller,SLOT(add_four()) );
			QObject::connect(m_figures[4],SIGNAL(clicked()),&m_controller,SLOT(add_five()) );
			QObject::connect(m_figures[5],SIGNAL(clicked()),&m_controller,SLOT(add_six()) );
			QObject::connect(m_figures[6],SIGNAL(clicked()),&m_controller,SLOT(add_seven()) );
			QObject::connect(m_figures[7],SIGNAL(clicked()),&m_controller,SLOT(add_eight()) );
			QObject::connect(m_figures[8],SIGNAL(clicked()),&m_controller,SLOT(add_nine()) );
			
			QObject::connect(m_comma,SIGNAL(clicked()),&m_controller,SLOT(add_comma()) );
			
			QObject::connect(&m_controller,SIGNAL(change_text(QString)),m_result,SLOT(setText(QString)));
			top->show();
		
		}



};
