#ifndef MYQQDEMO_H
#define MYQQDEMO_H

#include <QtGui/QFrame>
#include "appwidget.h"
class TitleBar;
class QWidget;
class ToolWidget;
class QSystemTrayIcon;
class SearchLineEdit;
class BuddyListWidget;
class ColumnWidget;

class ColumnWidget2;

class UserInfoWidget;

class UserInfoWidget2;

class AppWidget2;

class QStackedWidget;

enum AFX_HIDE_TYPE
{
	en_None = 0,		//������
	en_Top,				//��������
	en_Bottom,			//��������
	en_Left,			//��������
	en_Right			//��������
};


class MyQQDemo : public QFrame
{
	Q_OBJECT

public:
	MyQQDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyQQDemo();

	void mousePressEvent(QMouseEvent * e);
	void mouseMoveEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);

	void resizeEvent(QMouseEvent *e);

	bool winEvent ( MSG * message, long * result);
	void BeginHide(QPoint point);
	void FixMoving(const QPoint& point);
	void HideWindow();

	void timerEvent(QTimerEvent * e);
	void ShowWindow();
/*	QSize sizeHint();*/

	int m_iAniTimer;//��ʾ���غ���ʾ�Ķ�ʱ��

	int m_iMouseChecker;//��ʾ���

	void moveEvent ( QMoveEvent * event );

	//void paintEvent(QPaintEvent *e);

	
private:
	TitleBar *m_pTitleBar;

	ColumnWidget *m_pColumnWidget;



	QSystemTrayIcon *m_pSytemTrayIcon;

	SearchLineEdit *m_pSearchLineEdit;

	BuddyListWidget *m_pBuddyList;
	BuddyListWidget *m_pGroupList;
	BuddyListWidget *m_pLastGroup;


	QStackedWidget *m_pStackedWidget;

	UserInfoWidget2* m_UserInfoWidget;


	AppWidget2 *m_pAppWidget;


	AFX_HIDE_TYPE 			m_enHideType;				//����ģʽ
	bool					m_bFinished;				//���ػ���ʾ�����Ƿ����
	bool					m_bHiding;					//�ò���ֻ����!m_hsFinished����Ч,��:��������,��:������ʾ
	bool					m_bTimed;					//�Ƿ������˼������Timer

	bool m_bLeftBtnDown;

	bool m_bSearchEnable;

	

};

#endif // MYQQDEMO_H
