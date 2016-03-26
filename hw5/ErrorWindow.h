#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>
#include <string>


class ErrorWindow : public QWidget
{
	Q_OBJECT
public:
	ErrorWindow();
	~ErrorWindow();

private slots:
	
	void closeWindow();

private:

	// // UI

	QVBoxLayout* overallLayout;
	QLabel* header;
	QPushButton* closeButton;
	QLabel* errorMessage;
	
	

	// // Data
	
};
