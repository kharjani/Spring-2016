#include <QVBoxLayout>
#include "multiwin.h"

Multiwin::Multiwin() : QWidget(NULL)
{
  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainButton = new QPushButton("&Open OtherWin");
  mainLayout->addWidget(mainButton);
  setLayout(mainLayout);

  QVBoxLayout* otherLayout = new QVBoxLayout;
  otherWin = new QWidget;
  otherButton = new QPushButton("&Close");
  otherLayout->addWidget(otherButton);
  otherWin->setLayout(otherLayout);
  QObject::connect(mainButton, SIGNAL(clicked()), this, SLOT(mainButtonClicked()
));
  QObject::connect(otherButton, SIGNAL(clicked()), this, SLOT(otherButtonClicked
()));
}

void Multiwin::mainButtonClicked()
{
  otherWin->show();
}
void Multiwin::otherButtonClicked()
{
  otherWin->hide();
}