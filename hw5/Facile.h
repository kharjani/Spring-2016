#include "Statement.h"
#include "LetStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "PrintStatement.h"
#include "PrintAllStatement.h"
#include "GoSubStatement.h"
#include "GotoStatement.h"
#include "EndStatement.h"
#include "ReturnStatement.h"
#include "IfStatement.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QFont>
#include <QList>
#include <QStrinList>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <map>

#include <string>

class Facile : public QWidget
{
	Q_OBJECT
public:
	Facile(string filename);
	~Facile();
	bool verifiedFile();
	void parseProgram();
	void interpretProgram();
	QStringList* getCode();
	Statement* parseLine(string line)
	QstringList* getCode();
	void continue(QList* breakLines);
	void step();
	void next(bool isGosub, QList* breakLines);
	int getCurrentLine();
	map<string, int> *getMap();
	





private slots:
	void startProgram();
	void quitProgram();

private:

	// // UI

	QVBoxLayout* overallLayout;
	
	

	// // Data
	QStringList* code;
	ProgramState* state;
	Statement * parseLine(string line);
	vector<Statement *> program;
	string filename;
	bool goodFile = true;
	istream inf;
	ostream outf;
	
};
