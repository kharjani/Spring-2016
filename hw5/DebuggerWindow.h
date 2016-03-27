#include "LoadWindow.h"
#include "ErrorWindow.h"
#include "Facile.h"
#include "ValuesWindow.h"
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QList>
#include <vector>

class DebuggerWindow : public QWidget
{
  Q_OBJECT
public:
  DebuggerWindow();
public slots:
  void mainButtonClicked();
  void otherButtonClicked();
  void setBreakPoint();
  void continueButtonClicked();
  void nextButtonClicked();
  void inspectButtonClicked();
  void quitButtonClicked();
private:
  QPushButton* mainButton;
  QWidget* LoadWindow;
  QWidget* DebuggerWindow;
  QWidget* ValuesWindow;
  QWidget* Facile;
  QList<int>* breakLines;
  QListWidgetItem* haltedLine;
  QListWidget* codeDisplay;
  QPushButton* otherButton;
  QPushButton* breakButton;
  QPushButton* continueButton;
  QPushButton* stepButton;
  QPushButton* nextButton;
  QPushButton* inspectButton;
  QPushButton* quitButton;
  QHBoxLayout* overallLayout;
  QVBoxLayout* leftLayout;
  QHBoxLayout* bottomLeftLayout;
  QVBoxLayout* buttonsLayout;

};
