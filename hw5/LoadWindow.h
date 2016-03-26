#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QFont>

#include <string>

class LoadWindow : public QWidget
{
	Q_OBJECT
public:
	LoadWindow();
	~LoadWindow();

private slots:
	void startProgram();
	void quitProgram();

private:

	// // UI

	QVBoxLayout* overallLayout;
	QHBoxLayout* buttonLayout;
	QLabel* header;
	QPushButton* startButton;
	QPushButton* quitButton;
	QLabel* filenameLabel;
	QLineEdit* filenameInput;
	

	// // Data
	
};
