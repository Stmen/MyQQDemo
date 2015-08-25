#include "appwidget2.h"
#include "QMenu"

AppWidget2::AppWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QMenu *pMenu = new QMenu((QWidget*)(this->parent()));
	pMenu->addAction(tr("���ļ����ֻ�"));
	pMenu->addAction(tr("�����ֻ����"));
	pMenu->addAction(tr("�ҵ��ղ�"));

	pMenu->addAction(tr("���з���"));
	pMenu->addAction(tr("QQ��Ա"));
	pMenu->addAction(tr("����"));

	pMenu->addAction(tr("��ȫ"));
	pMenu->addAction(tr("����"));
	pMenu->addAction(tr("����"));
	pMenu->addAction(tr("�������"));
	pMenu->setFixedWidth(212);
	ui.toolButton->setMenu(pMenu);
	ui.toolButton->setPopupMode(QToolButton::InstantPopup);

	setAutoFillBackground(true);


	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QColor(233,221,213));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);
}

AppWidget2::~AppWidget2()
{

}
