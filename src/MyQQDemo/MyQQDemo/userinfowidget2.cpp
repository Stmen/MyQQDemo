#include "userinfowidget2.h"
#include <QMenu>

UserInfoWidget2::UserInfoWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.lineEdit->setAttribute(Qt::WA_TranslucentBackground, true);  


	QMenu *pMenu = new QMenu((QWidget*)(this->parent()));
	pMenu->setFixedWidth(160);
	pMenu->addAction(tr("��������"));
	pMenu->addAction(tr("Q�Ұ�"));
	pMenu->addAction(tr("�뿪"));
	pMenu->addAction(tr("æµ"));
	pMenu->addAction(tr("�������"));
	pMenu->addAction(tr("����"));

	pMenu->addAction(tr("����"));
	pMenu->addAction(tr("���״̬��Ϣ"));

	pMenu->addSeparator();
	pMenu->addAction(tr("�ر���������"));

	pMenu->addAction(tr("�ر�ͷ������"));
	pMenu->addAction(tr("���״̬��Ϣ"));
	pMenu->addAction(tr("����QQ Ctrl +Alt + L"));

	pMenu->addSeparator();

	pMenu->addAction(tr("ϵͳ����"));
	pMenu->addAction(tr("�ҵ�����"));
	pMenu->addAction(tr("�ҵ�QQ����"));
	ui.toolButton->setMenu(pMenu);
	ui.toolButton->setPopupMode(QToolButton::InstantPopup);
}

UserInfoWidget2::~UserInfoWidget2()
{

}
