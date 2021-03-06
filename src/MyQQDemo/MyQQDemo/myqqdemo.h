#ifndef MYQQDEMO_H
#define MYQQDEMO_H

#include <QtGui/QFrame>
#include "appwidget.h"
#include <QSystemTrayIcon>
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

class NavigationWidget;
class MessageBoxDemo;

enum AFX_HIDE_TYPE
{
	en_None = 0,		//不收缩
	en_Top,				//向上收缩
	en_Bottom,			//向下收缩
	en_Left,			//向左收缩
	en_Right			//向右收缩
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

	bool	eventFilter ( QObject * watched, QEvent * event );

	//void closeEvent(QCloseEvent *event);

	bool winEvent ( MSG * message, long * result);
	void BeginHide(QPoint point);
	void FixMoving(const QPoint& point);
	void HideWindow();

	void timerEvent(QTimerEvent * e);
	void ShowWindow();

	int m_iAniTimer;//表示隐藏和显示的定时器

	int m_iMouseChecker;//表示检测

	void moveEvent ( QMoveEvent * event );

	//void paintEvent(QPaintEvent *e);

	public slots:
	void ShowMainBoard(QSystemTrayIcon::ActivationReason);

	
private:
	TitleBar *m_pTitleBar;

	//NavigationWidget *m_pColumnWidget;

	ColumnWidget *m_pColumnWidget;



	QSystemTrayIcon *m_pSytemTrayIcon;

	SearchLineEdit *m_pSearchLineEdit;
	QStackedWidget *m_pStackedWidget;
	UserInfoWidget2* m_UserInfoWidget;


	AppWidget2 *m_pAppWidget;


	AFX_HIDE_TYPE 			m_enHideType;				//隐藏模式
	bool					m_bFinished;				//隐藏或显示过程是否完成
	bool					m_bHiding;					//该参数只有在!m_hsFinished才有效,真:正在隐藏,假:正在显示
	bool					m_bTimed;					//是否设置了检测鼠标的Timer

	bool m_bLeftBtnDown;



	MessageBoxDemo *m_pMessageBox;

	

};

#endif // MYQQDEMO_H
