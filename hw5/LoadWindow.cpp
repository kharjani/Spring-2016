#include "LoadWindow.h"

LoadWindow::LoadWindow(){
	setWindowTitle("Load Window");

	overallLayout = new QVBoxLayout();
	buttonLayout = new QHBoxLayout();

	QFont headerFont;
  	headerFont.setBold(true);
  	headerFont.setPointSize(14);
	header = new QLabel(QString::fromStdString("CS104 Project"));
	header->setFont(headerFont);
	overallLayout->addWidget(header); 


	// Filename label
	filenameLabel = new QLabel("Enter Filename:");
	overallLayout->addWidget(filenameLabel);

	// Filename input
	filenameInput = new QLineEdit();
	overallLayout->addWidget(filenameInput);

	// Start button
	startButton = new QPushButton("Start");
	startButton->setDefault(true);
   	startButton->setAutoDefault(false);
	connect(startButton, SIGNAL(clicked()), this, SLOT(startProgram(filenameInput)));
	buttonLayout->addWidget(startButton);

	// Quit button
	quitButton = new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));
	buttonLayout->addWidget(quitButton);

	overallLayout->addLayout(buttonLayout);

	setLayout(overallLayout);
}

LoadWindow::~LoadWindow(){
	

}

void LoadWindow::startProgram(QLineEdit* filenameInput){

}

void LoadWindow::quitProgram(){
	QApplication::exit( );

}
string LoadWindow::getFilename(){
	return filenameInput->text().toStdString();
}
