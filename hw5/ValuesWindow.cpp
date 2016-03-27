#include "ValuesWindow.h"
#include <map>

using namespace std;

ValuesWindow::ValuesWindow(map<string, int>* map){
	setWindowTitle("Values Window");
	overallLayout = new QHBoxLayout();
	leftLayout = new QVBoxLayout();
	rightLayout = new QVBoxLayout();


	
	data = new QStringList();
	typename map<string,int>::iterator it;
	for (it=map.begin(); it!=map.end(); ++it){
    	QString line = it->first + " " + it->second;
    	data << line;
	}
	mapDisplay = new QListWidget();
	mapDisplay.insertItems(data);
	leftLayout->addWidget(mapDisplay);

	hideButon = new QPushButton("Hide");
	leftLayout->addWidget(hideButon);
	connect(hideButton, SIGNAL(clicked()), this, SLOT(hideButtonClicked()));

	updateButton = new QPushButton("Update");
	leftLayout->addWidget(updateButton);
	connect(updateButton, SIGNAL(clicked()), this, SLOT(updateButtonClicked()));
}

ValuesWindow::hideButtonClicked(){
	hide();
}

ValuesWindow::updateButtonClicked(){

}