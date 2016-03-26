#include "LoadWindow.h"
#include "ErrorWindow.h"
#include "DebuggerWindow.h"
#include "ValuesWindow.h"
#include <QApplication>


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	LoadWindow LoadWindow;
	ErrorWindow ErrorWindow;
	DebuggerWindow DebuggerWindow;
	ValuesWindow ValuesWindow;

	LoadWindow.show();

	



	return app.exec();
}