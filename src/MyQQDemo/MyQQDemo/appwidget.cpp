#include "appwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>

AppWidget::AppWidget(QWidget *parent)
	: QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	//setLayout(mainLayout);

	setStyleSheet("background-color:red;");//rgb(233,221,213)
	m_pAppMenu = new QPushButton(this);

	//m_pAppMenu->setGeometry(2,2,24,24);
	m_pAppMenu->setIcon(QIcon(":/AppMenu/Resources/mainmenubutton/menu_btn_normal.png"));

	m_pAppMenu->setToolTip("���˵�");


	QMenu *pMenu = new QMenu(m_pAppMenu);
	//m_pAppMenu->addAction(new QAction("���ļ����ֻ�"));
	//m_pAppMenu->addAction("�����ֻ����");

	m_pAppMenu->setMenu(pMenu);


	m_pSystemSetting = new QPushButton(this);
	m_pSystemSetting->setToolTip("��ϵͳ����");
	m_pSystemSetting->setIcon("");



	m_pMessageManager = new QPushButton(this);
	m_pMessageManager->setToolTip("����Ϣ������");
	m_pFileAssiant= new QPushButton(this);
	m_pFileAssiant->setToolTip("���ļ�����");
	m_pMyShouCang= new QPushButton(this);
	m_pMyShouCang->setToolTip("���ҵ��ղ�");
	m_pFind = new QPushButton(this);
	m_pFind->setToolTip("����");
	m_pAppBaby = new QPushButton(this);

	m_pAppBaby->setToolTip("Ӧ�ñ�");

	

}

AppWidget::~AppWidget()
{

}

void AppWidget::paintEvent( QPaintEvent *event )
{

	return QWidget::paintEvent(event);

}
