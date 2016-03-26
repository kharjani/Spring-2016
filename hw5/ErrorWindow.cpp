#include "ErrorWindow.h"

ErrorWindow::ErrorWindow(){
	setWindowTitle("Error Window");

	overallLayout = new QVBoxLayout();

	QFont headerFont;
  	headerFont.setBold(true);
  	headerFont.setPointSize(14);
	header = new QLabel(QString::fromStdString("Unable to open file"));
	header->setFont(headerFont);
	overallLayout->addWidget(header); 

	errorMessage = new QLabel(QString::fromStdString("The file could not be opened, please check the filename and try again."));
	overallLayout->addWidget(errorMessage);

	closeButton = new QPushButton("Close");
	connect(closeButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	overallLayout->addWidget(closeButton);

	setLayout(overallLayout);


}

ErrorWindow::~ErrorWindow(){

}

ErrorWindow::closeWindow(){
	this->hide();
}