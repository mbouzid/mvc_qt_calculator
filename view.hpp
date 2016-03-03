#pragma once

// qt lib
#include <QtGui/QGridLayout>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtCore/QString>
#include <QtGui/QLineEdit>
#include <QtCore/QVector>
#include <QtCore/QDebug>
#include <QtGui/QTextEdit>
#include <QtCore/QRect>
#include <QtCore/QSize>
// own lib
#include "controller.hpp"
class view 
{
	private :

		QWidget * m_top ;
		QWidget * m_numpad ;
		QWidget * m_operators ;
		QVector<QPushButton *> m_figures ;
		QLineEdit * m_output ;
		QLineEdit * m_result ;
		controller m_controller ;
		QGridLayout * m_box ;
		
		QPushButton * m_addition ;
		QPushButton * m_substraction ;
		QPushButton * m_multiplication ;
		QPushButton * m_division ;
		QPushButton * m_r_bracket;
		QPushButton * m_l_bracket ;
		QPushButton * m_square ;
		QPushButton * m_equal ;
		QPushButton * m_comma ;
		
	public :
		
		view( QWidget * top = 0 ): m_top(top)
		{
			QWidget * main_widget = new QWidget(m_top);
			main_widget->resize(50,50);
			QGridLayout * main = new QGridLayout(main_widget);
			
			
			
			m_numpad = new QWidget(m_top);
			m_operators = new QWidget(m_top) ;
			
			m_output = new QLineEdit("0",m_top);
			
			m_output->setReadOnly(true);
			
			m_result = new QLineEdit("0",m_top);
			m_result->setAlignment(Qt::AlignLeft);
			m_result->setReadOnly(true);
			
			main->addWidget(m_output,0,0);
			main->addWidget(m_result,1,1);
			main->addWidget(m_numpad,2,0);
			main->addWidget(m_operators,2,2);
			
			
			QGridLayout * grid_numpad = new QGridLayout(m_numpad) ;
			grid_numpad->setMargin(0); 
			grid_numpad->setVerticalSpacing(0) ;
			grid_numpad->setHorizontalSpacing(0) ;
			
			for( int i=0 ; i<10 ; ++i )
			{
				m_figures.insert(i,new QPushButton(QString::number(i),m_numpad) );
			}
			
			m_comma = new QPushButton(",",m_numpad);
			

			
			int j = 9 ;
			while ( j>=1 )
			{
				for ( int i = 0 ; i < 3 ; ++i )
				{	
					for ( int k = 2 ; k >=0 ; --k )
					{
						grid_numpad->addWidget(m_figures[j],i,k);
						--j;
					}
				}
			}
			
			
			grid_numpad->addWidget(m_figures[0],3,0,1,2,Qt::Alignment(0));
			grid_numpad->addWidget(m_comma,3,2,1,1,Qt::Alignment(0));
			
			m_addition = new QPushButton("+",m_operators);
			m_substraction = new QPushButton("-",m_operators);
			m_multiplication = new QPushButton("*",m_operators);
			m_division = new QPushButton("/",m_operators);
			m_r_bracket = new QPushButton("(",m_operators);
			m_l_bracket = new QPushButton(")",m_operators);
			m_square = new QPushButton("^2",m_operators);
			m_equal = new QPushButton("=",m_operators);
			
			
			
			QGridLayout * grid_operators = new QGridLayout(m_operators) ;
			grid_operators->setMargin(0); 
			grid_operators->setVerticalSpacing(0) ;
			grid_operators->setHorizontalSpacing(0) ;
			
			
			grid_operators->addWidget(m_addition,0,0);
			grid_operators->addWidget(m_substraction,0,1);
			grid_operators->addWidget(m_multiplication,1,0);
			grid_operators->addWidget(m_division,1,1);
			grid_operators->addWidget(m_r_bracket,2,0);
			grid_operators->addWidget(m_l_bracket,2,1);
			grid_operators->addWidget(m_square,3,0);
			grid_operators->addWidget(m_equal,3,1);
					
			m_box = new QGridLayout(m_top);
			
			
			m_box->addWidget(m_output,0,0,1,2,Qt::Alignment(0));
			m_box->addWidget(m_result,1,1,1,1,Qt::Alignment(0));
			m_box->addWidget(m_numpad,2,0,1,1,Qt::Alignment(0));
			m_box->addWidget(m_operators,2,1,1,1,Qt::Alignment(0));
			
			
			
			QObject::connect(m_addition,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_substraction,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_multiplication,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_division,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_r_bracket,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_l_bracket,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_square,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_equal,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			QObject::connect(m_comma,SIGNAL(clicked()),&m_controller,SLOT(add()) );
			

			for( int i=0 ; i<10 ; ++i )
			{
				QObject::connect(m_figures[i],SIGNAL(clicked()),&m_controller,SLOT(add()));
			}
			
			QObject::connect(&m_controller,SIGNAL(result(QString)),m_result,SLOT(setText(QString)));
			QObject::connect(&m_controller,SIGNAL(change_text(QString)),m_output,SLOT(setText(QString)));
			QObject::connect(&m_controller,SIGNAL(error(QString)),m_output,SLOT(setText(QString)));
			top->show();
		
		}

		~view()
		{}

};
