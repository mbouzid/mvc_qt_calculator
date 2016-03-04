#include "view.hpp"

#include <QtGui/QApplication>
#include <QtGui/QWidget>

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QWidget top(0);
	view v(&top);

	return app.exec();
}
