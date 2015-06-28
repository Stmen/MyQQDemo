#include "appwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>

AppWidget::AppWidget(QWidget *parent)
	: QWidget(parent)
{
	mainLayout = new QHBoxLayout(this);
	setLayout(mainLayout);



	//setStyleSheet("background-color:red;");//rgb(233,221,213)
	m_pAppMenuBtn = new QPushButton(this);
	  
	//m_pAppMenu->setGeometry(2,2,24,24);
	//m_pAppMenuBtn->setIcon(QIcon(":/AppMenu/Resources/mainmenubutton/menu_btn_normal.png"));

	m_pAppMenuBtn->setToolTip("���˵�");

	m_pAppMenuBtn->setFixedSize(24,24);

	//m_pAppMenuBtn->setFlat(true);

	m_pAppMenuBtn->setObjectName("AppMenu");

	m_pAppMenuBtn->setCheckable(false);
	//m_pAppMenuBtn->setStyleSheet("QPushButton{border:none}");


// 	QMenu *pMenu = new QMenu(m_pAppMenuBtn);
// 	QAction *pTransferFile = new QAction("���ļ����ֻ�",this);
// 	pTransferFile->setCheckable(true);
// 	pTransferFile->setChecked(true);
// 
// 	pMenu->addAction(pTransferFile);
// 	pMenu->addSeparator();
// 
// 	pMenu->addAction(new QAction("�����ֻ����",this));
// 	pMenu->addAction(new QAction("�ҵ��ղ�",this));

	//pMenu->setIcon(QIcon(":/MyQQDemo/Resources/close_normal.png"));


/*	m_pAppMenuBtn->setMenu(pMenu);*/

	


	m_pSystemSetting = new QPushButton(this);
	m_pSystemSetting->setToolTip("��ϵͳ����");
	m_pSystemSetting->setIcon(QIcon(""));

	m_pSystemSetting->setFixedSize(20,20);



	m_pMessageManager = new QPushButton(this);
	m_pMessageManager->setToolTip("����Ϣ������");
	m_pMessageManager->setFixedSize(20,20);

	m_pFileAssiant= new QPushButton(this);
	m_pFileAssiant->setToolTip("���ļ�����");
	m_pFileAssiant->setFixedSize(20,20);

	m_pMyShouCang= new QPushButton(this);
	m_pMyShouCang->setToolTip("���ҵ��ղ�");
	m_pMyShouCang->setFixedSize(20,20);

	m_pFind = new QPushButton(this);
	m_pFind->setToolTip("����");
	m_pFind->setFixedSize(20,20);

	m_pAppBaby = new QPushButton(this);
	m_pAppBaby->setFixedSize(20,20);

	m_pAppBaby->setToolTip("Ӧ�ñ�");

	mainLayout->addWidget(m_pAppMenuBtn);
	mainLayout->addWidget(m_pSystemSetting);
	mainLayout->addWidget(m_pMessageManager);
	mainLayout->addWidget(m_pFileAssiant);
	mainLayout->addWidget(m_pMyShouCang);
	mainLayout->addWidget(m_pFind);
	mainLayout->addWidget(m_pAppBaby);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);



	

}

AppWidget::~AppWidget()
{

}

// void AppWidget::paintEvent( QPaintEvent *event )
// {
// 
// 	return QWidget::paintEvent(event);
// 
// }
