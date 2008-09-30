#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "relaycheckbox.h"

extern "C" {
	#include "lib/usbrelay.h"
}


class MyWidget : public QWidget
{
public:
	MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout;

	if(usbrelay_init() != 0) {
		QLabel *label= new QLabel(QString("No Relays available (")+usbrelay_strerror()+")");
		layout->addWidget(label);
	}
	else {
		int count= usbrelay_count();

		RelayCheckbox *relay;
		int i;
		count= 1;
		for (i=0; i < count; i++) {
			relay= new RelayCheckbox(i);
			layout-> addWidget(relay);
		}
	}

	setLayout(layout);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MyWidget widget;
	widget.show();
	return app.exec();
}
