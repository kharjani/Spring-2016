#ifndef MULTIWIN_H
#define MULTIWIN_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class Multiwin : public QWidget
{
  Q_OBJECT
public:
  Multiwin();
public slots:
  void mainButtonClicked();
  void otherButtonClicked();
private:
  QPushButton* mainButton;
  QWidget* LoadWindow;
  QWidget* DebuggerWindow;
  QWidget* ValuesWindow;
  QPushButton* otherButton;
};
#endif