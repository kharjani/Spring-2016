#include "LoadWindow.h"
#include "ErrorWindow.h"
#include "DebuggerWindow.h"
#include "ValuesWindow.h"
#include <QApplication>


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);


	DebuggerWindow DebuggerWindow; //use this to manage the other windows
	

	LoadWindow.show();

	//turn facile into a class, create instance of it in the debugger window, 
	//pass in filename through constructor - (need new public member functions
	// like continue, step, next etc. member data: programstate)

	



	return app.exec();
}