#include <QVBoxLayout>
#include "DebuggerWindow.h"

DebuggerWindow::DebuggerWindow() : QWidget(NULL)
{
  setWindowTitle("Debugger Window");
  //create and show the LoadWindow object
  LoadWindow = new QWidget;
  LoadWindow->show();
  //create errorWindow
  ErrorWindow ErrorWindow;
  
  
  //create Facile Object
  string filename = LoadWindow->getFilename();
  Facile Facile(filename);
  if(!Facile->verifiedFile()){ // if bad filename
    ErrorWindow->show();
  }


  //create all debuggerWindow content
  codeDisplay = new QListWidget();
  codeDisplay.insertItems(Facile->getCode());
  codeDisplay.setSelectionMode(QAbstractItemView::SingleSelection);
  currentLine = codeDisplay.item(codeDisplay.currentRow());

  buttonsLayout = new QVBoxLayout();
  breakButton = new QPushButton("Break");
  buttonsLayout->addWidget(breakButton);
  connect(breakButton, SIGNAL(clicked()), this, SLOT(setBreakPoint()));
  continueButton = new QPushButton("Continue");
  buttonsLayout->addWidget(continueButton);
  connect(continueButton, SIGNAL(clicked()), this, SLOT(continue()));
  stepButton = new QPushButton("Step");
  buttonsLayout->addWidget(stepButton);
  nextButton = new QPushButton("Next");
  buttonsLayout->addWidget(nextButton);
  inspectButton = new QPushButton("Inspect");
  buttonsLayout->addWidget(inspectButton);
  
  leftLayout = new QVBoxLayout();
  leftLayout->addWidget(codeDisplay);
  
  quitButton = new QPushButton("Quit");
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));

  leftLayout->addWidget(quitButton);

  overallLayout = new QHBoxLayout();
  overallLayout->addLayout(leftLayout);
  overallLayout->addLayout(buttonsLayout);
  setLayout(overallLayout);
}

void Multiwin::mainButtonClicked()
{
  otherWin->show();
}
void Multiwin::otherButtonClicked()
{
  otherWin->hide();
}

void DebuggerWindow::setBreakPoint(){
  currentLine->setBackground(Qt::green);
  breakLines.append(codeDisplay.currentRow());
}

void DebuggerWindow::continueButtonClicked(){
  Facile->continue(breakLines);
}

void DebuggerWindow::nextButtonClicked(){
  bool isGosub = (codeDisplay[codeDisplay.currentRow()].text()).contains("GOSUB", Qt::CaseInsensitive);
  Facile->next(isGosub, breakLines);
}

void DebuggerWindow::inspectButtonClicked(){
  ValuesWindow ValuesWindow(Facile->getMap);
  ValuesWindow->show();
}

void Debugger::quitButtonClicked(){
  QApplication::quit();
}