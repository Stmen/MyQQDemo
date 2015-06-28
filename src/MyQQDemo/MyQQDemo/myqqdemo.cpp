#include "myqqdemo.h"
#include "titlebar.h"
#include "columnwidget.h"
#include "toolwidget.h"
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include "searchlineedit.h"
#include "buddylistwidget.h"
#include "columnwidget2.h"
#include <Windows.h>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>

MyQQDemo::MyQQDemo(QWidget *parent, Qt::WFlags flags)
	: QFrame(parent, flags)
{
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(270,650);
	setMaximumSize(600,715);

	this->setFixedSize(QSize(281,700));

	//this->setFixedSize(270,650);
	//QString styleSheet = "QMainWindow:{border:0px;}";
	//setStyleSheet("QFrame {background-image:url(:/MyQQDemo/Resources/main.jpg);border:0px solid black;}");

	m_pTitleBar = new TitleBar(this);
	m_pTitleBar->setGeometry(0,0,281,30);


 	m_pColumnWidget = new ColumnWidget(this);//new ColumnWidget(this);

 	m_pColumnWidget->setGeometry(0,150,281,38);

	m_pColumnWidget->setObjectName("widgetColumn");


	//setCursor();

// 	m_pToolWidget = new ToolWidget(this);
// 
// 	m_pToolWidget->setGeometry(0,100,270,30);

	m_pSytemTrayIcon = new QSystemTrayIcon(this);
	m_pSytemTrayIcon->setIcon(QIcon(""));
	m_pSytemTrayIcon->show();

	QMenu *pMenu = m_pSytemTrayIcon->contextMenu();
	//pMenu->addAction(new QAction(tr("��ʾ������")));

	m_pSytemTrayIcon->setContextMenu(pMenu);

	m_pSearchLineEdit = new SearchLineEdit(this);

	m_pSearchLineEdit->setGeometry(0,100,260,30);

	m_pBuddyList = new BuddyListWidget(this);

	m_pBuddyList->SetBuddyItemHeadFlashAnim(0,1,true);

	m_pBuddyList->setGeometry(0,204,278,443);
	m_pAppWidget = new AppWidget(this);

	m_pAppWidget->setGeometry(0,657,278,30);

	m_enHideType = en_None;

	//setMouseTracking(true);

	

	

	
}

MyQQDemo::~MyQQDemo()
{

}

void MyQQDemo::mousePressEvent( QMouseEvent * e )
{

}

void MyQQDemo::mouseMoveEvent( QMouseEvent * e )
{
	Qt::MouseButton b = e->button();
	//if (e->button() == Qt::LeftButton)
	{
		FixMoving(e->globalPos());
	}

}

void MyQQDemo::mouseReleaseEvent( QMouseEvent * e )
{

}

bool MyQQDemo::winEvent( MSG * message, long * result )
{
	switch(message->message)  
	{  
	case WM_NCHITTEST:
		{
			return false;
		}
		 

		
	}  
	return false;  

}


void MyQQDemo::BeginHide(QPoint point)
{
//	if( (m_enHideType != en_None) && !m_bTimed && (point.x < GetSystemMetrics(SM_CXSCREEN) + INFALTE))
//	{   
//		m_HideTimer = startTimer(1000);
//		
//		m_bTimed = true;
//
//		m_bFinished = false;
//		m_bHiding = false;
///*		::SetTimer(m_hOwnHwnd,IDI_BEGINHIDE,BH_ELAPSE,NULL); //������ʾ����*/
//	}
}

void MyQQDemo::FixMoving(const QPoint& point)
{
	QRect rect = QApplication::desktop()->availableGeometry();

	INT nHeight = height();
	INT nWidth  = width();

	//ճ�����ϱ�
	if (point.y() <= 20)
	{  
		m_enHideType = en_Top;
	}
// 	//ճ�����±�
// 	else if(point.y >= (nScreenHeight - INTERVAL - m_nTaskBarHeight))
// 	{   
// 		pRect->top = nScreenHeight - m_nTaskBarHeight - nHeight;
// 		pRect->bottom = nScreenHeight - m_nTaskBarHeight;
// 		m_enHideType = en_Bottom;
// 	}
// 	//ճ�������	
// 	else if (point.x < INTERVAL)
// 	{	
// 		if(!m_bSized)
// 		{
// 			CRect tRect;
// 			::GetWindowRect(m_hOwnHwnd,tRect);
// 			m_nWindowHeight = tRect.Height();			
// 		}
// 		pRect->right = nWidth;
// 		pRect->left = 0;
// 		pRect->top = -m_nEdgeHeight;
// 		pRect->bottom = nScreenHeight - m_nTaskBarHeight;
// 		m_bSized = TRUE;
// 		m_enHideType = en_Left;
// 	}
// 	//ճ�����ұ�
// 	else if(point.x >= (nScreenWidth - INTERVAL))
// 	{   
// 		if(!m_bSized)
// 		{
// 			CRect tRect;
// 			::GetWindowRect(m_hOwnHwnd,tRect);
// 			m_nWindowHeight = tRect.Height();						
// 		}
// 		pRect->left = nScreenWidth - nWidth;
// 		pRect->right = nScreenWidth;
// 		pRect->top = -m_nEdgeHeight;
// 		pRect->bottom = nScreenHeight - m_nTaskBarHeight;
// 		m_bSized = true;
// 		m_enHideType = en_Right;
// 	}
// 	//��ճ��
// 	else
// 	{   
// 		if(m_bSized)
// 		{  
// 			pRect->bottom = pRect->top + m_nWindowHeight;
// 			m_bSized = false;
// 			InvalidateRect(m_hOwnHwnd,NULL,FALSE);
// 			SetWindowPos(HWND_TOPMOST,CRect(pRect->left,pRect->top,pRect->right,m_nWindowHeight));
// 		}
// 
// 		//���Timer������,��ر�֮
// 		if(m_bTimed)
// 		{  
// 			if(::KillTimer(m_hOwnHwnd,IDI_CHECKMOUSE) == 1)
// 				m_bTimed = false;
// 		}
// 		m_enHideType = en_None;
// 	}
}


void MyQQDemo::HideWindow()
{
	
}

// QSize MyQQDemo::sizeHint()
// {
// 	if(m_enHideType == en_None) return;
// 
// 	INT nHeight = height();
// 	INT nWidth  = width();
// 
// 	//����
// 	INT nStride = 0;
// 
// 	switch(m_enHideType)
// 	{
// 	case en_Top:
// 		{
// 			nStride = nHeight/7;
// 			rcWindow.bottom -= nStride;
// 
// 
// 
// 			if(rcWindow.bottom <= m_nEdgeWidth)
// 			{
// 				rcWindow.bottom = m_nEdgeWidth;
// 				m_bFinished = true;
// 			}
// 			rcWindow.top = rcWindow.bottom - nHeight; 
// 		}
// 		break;
// 	}
// 
// }
