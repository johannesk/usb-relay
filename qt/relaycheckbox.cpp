#include <QString>

#include "relaycheckbox.h"

extern "C" {
	#include "lib/usbrelay.h"
}

RelayCheckbox::RelayCheckbox(QWidget *parent, int number)
	: QCheckBox(parent)
{
	setNumber(number);
	connect(this, SIGNAL(stateChanged), this, SLOT(setRelay));
}

RelayCheckbox::RelayCheckbox(int number)
	: QCheckBox(0)
{
	setNumber(number);
	connect(this, SIGNAL(stateChanged(int)), this, SLOT(setRelay(int)));
}

void RelayCheckbox::setNumber(int number)
{
	relayNumber= number;
	QString num;
	num.setNum(number);
	setText(num);
}

void RelayCheckbox::setRelay(int state)
{
	if (state == Qt::Checked)
		usbrelay_set(relayNumber, 1);
	else
		usbrelay_set(relayNumber, 0);
}

