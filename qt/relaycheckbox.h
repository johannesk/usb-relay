#include <QCheckBox>

class RelayCheckbox : public QCheckBox
{
	Q_OBJECT

public:
	RelayCheckbox(QWidget* parent, int number);
	RelayCheckbox(int number);

	int number();

public slots:
	void setNumber(int number);

private:
	int relayNumber;

private slots:
	void setRelay(int state);

};
