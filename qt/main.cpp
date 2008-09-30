#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
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
	int count;
	usbrelay_init();
	count= usbrelay_count();
	QVBoxLayout *layout = new QVBoxLayout;

	RelayCheckbox *relay;
	int i;
	count= 1;
	for (i=0; i < count; i++) {
		relay= new RelayCheckbox(i);
		layout-> addWidget(relay);
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
