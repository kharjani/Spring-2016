#include "ValuesWindow.h"
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QList>
#include <vector>
#include <map>

class ValuesWindow : public QWidget
{
  Q_OBJECT
public:
  ValuesWindow();
public slots:
  void hideButtonClicked();
  void updateButtonClicked();
 
private:
  QPushButton* hideButton;
  QPushButton* updateButton;

  QListWidget* mapDisplay;
  QStringList* data;
  
  
  QHBoxLayout* overallLayout;
  QVBoxLayout* leftLayout;
  QVBoxLayout* rightLayout;
  
};
