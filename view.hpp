#pragma once

// qt lib
#include <QtGui/QGridLayout>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtCore/QString>
#include <QtGui/QLineEdit>
#include <QtCore/QVector>
#include <QtGui/QTextEdit>

// own lib
#include "controller.hpp"
class view 
{
	private :

		// widgets
		QWidget * m_top ;
		QWidget * m_numpad ;
		QWidget * m_operators ;
		
		// outputs
		QLineEdit * m_output ;
		QLineEdit * m_result ;
		
		
		controller m_controller ;
		
		// layouts
		QGridLayout * m_box ;	
		QGridLayout * m_grid_numpad ;
		QGridLayout * m_grid_operators ;	
		
		// buttons
		QPushButton * m_addition ;
		QPushButton * m_substraction ;
		QPushButton * m_multiplication ;
		QPushButton * m_division ;
		QPushButton * m_r_bracket;
		QPushButton * m_l_bracket ;
		QPushButton * m_square ;
		QPushButton * m_equal ;
		QPushButton * m_comma ;
		QVector<QPushButton *> m_figures ;
		
		
	public :
		
		view( QWidget * top = 0 ): m_top(top)
		{

		
			m_numpad = new QWidget(m_top);
			m_operators = new QWidget(m_top) ;
			
			// output
			m_output = new QLineEdit("0",m_top);
			
			m_output->setReadOnly(true);
			m_output->setStyleSheet("QLineEdit { background-color: #8B8B7A; border-style: outset; border-width: 2px; border-color: #8B8B7A ; color: white ; }");
			
			// result output
			m_result = new QLineEdit("0",m_top);
			m_result->setReadOnly(true);
			m_result->setStyleSheet("QLineEdit { background-color: #8B8B7A; border-style: outset; border-width: 2px; border-color: #8B8B7A ; color: white ; }");
		
		
			// numpad grid
			m_grid_numpad = new QGridLayout(m_numpad) ;
			
			
			
			// initialize buttons
			for( int i=0 ; i<10 ; ++i )
			{
				m_figures.insert(i,new QPushButton(QString::number(i),m_numpad) );
				m_figures.at(i)->setStyleSheet(" QPushButton { background-color:  #333333 ; color: white ; }");
			}
			
			m_comma = new QPushButton(",",m_numpad);
			m_comma->setStyleSheet("QPushButton { background-color:  #333333 ; color: white ; }");

			
			int j = 9 ;
			while ( j>=1 )
			{
				for ( int i = 0 ; i < 3 ; ++i )
				{	
					for ( int k = 2 ; k >=0 ; --k )
					{
						m_grid_numpad->addWidget(m_figures[j],i,k);
						--j;
					}
				}
			}
			
			
			m_grid_numpad->addWidget(m_figures[0],3,0,1,2);
			m_grid_numpad->addWidget(m_comma,3,2,1,1);
			m_grid_numpad->setMargin(0); 
			m_grid_numpad->setVerticalSpacing(0) ;
			m_grid_numpad->setHorizontalSpacing(0) ;
			
			

			m_addition = new QPushButton("+",m_operators);
			m_substraction = new QPushButton("-",m_operators);
			m_multiplication = new QPushButton("*",m_operators);
			m_division = new QPushButton("/",m_operators);
			m_r_bracket = new QPushButton("(",m_operators);
			m_l_bracket = new QPushButton(")",m_operators);
			m_square = new QPushButton("^2",m_operators);
			m_equal = new QPushButton("=",m_operators);
			
			
			//style 
			m_addition->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_substraction->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_multiplication->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_division->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_r_bracket->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_l_bracket->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_square->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			m_equal->setStyleSheet("QPushButton { background-color: #333333 ; color: white ; }");
			
			
			m_grid_operators = new QGridLayout(m_operators) ;
			m_grid_operators->setMargin(0); 
			m_grid_operators->setVerticalSpacing(0) ;
			m_grid_operators->setHorizontalSpacing(0) ;
			
			
			m_grid_operators->addWidget(m_addition,0,0);
			m_grid_operators->addWidget(m_substraction,0,1);
			m_grid_operators->addWidget(m_multiplication,1,0);
			m_grid_operators->addWidget(m_division,1,1);
			m_grid_operators->addWidget(m_r_bracket,2,0);
			m_grid_operators->addWidget(m_l_bracket,2,1);
			m_grid_operators->addWidget(m_square,3,0);
			m_grid_operators->addWidget(m_equal,3,1);
			
	
			// main layout
			m_box = new QGridLayout(m_top);
		
			
			m_box->addWidget(m_output,1,1,1,3);
			m_box->addWidget(m_result,2,2,1,2);
			m_box->addWidget(m_numpad,4,1,1,1);
			m_box->addWidget(m_operators,4,3,1,1);
			m_box->setRowStretch(0,1);
			m_box->setRowStretch(3,1);
			m_box->setRowStretch(5,1);
			
			m_box->setColumnStretch(0,1);
			m_box->setColumnStretch(0,1);
			m_box->setColumnStretch(2,1);
			
			m_box->setColumnStretch(4,1);
			
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
			top->show();
		
		}

		~view()
		{
			QLayoutItem * childOp, *childNum, *childBox;
			
			while ((childOp = m_grid_operators->takeAt(0)) != 0) 
			{
   				delete childOp;
   			}
   			

   			
   			while ((childNum = m_grid_numpad->takeAt(0)) != 0) 
			{
   				delete childNum;
   			}
   			

   			while ((childBox = m_box->takeAt(0)) != 0) 
			{
   				delete childBox;
   			}
		}

};
