#include "friendlistview.h"
#include <QMouseEvent>
#include "FriendGroupInfo.h"
#include "FriendInfo.h"
#include <QMenu>
#include "friendinfoui.h"
#include <QTimer>
#include "qqchatwindow.h"

FriendListView::FriendListView(QWidget *parent)
	: QTreeView(parent)
{
	m_pWidget = new FriendInfoUI();

	m_pWidget->hide();

	m_pWidget->setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
	setMouseTracking(true);

	m_CurMouseHoverIndex = QModelIndex();

	m_pTimeChecker = new QTimer(this);
	m_pTimeChecker->stop();
	QObject::connect(m_pTimeChecker,
		SIGNAL(timeout()),
		this,
		SLOT(CheckMousePosForShow()));

	QObject::connect(this,
		SIGNAL(mouseHoverIndexChanged(QModelIndex)),
		this,
		SLOT(CheckMousePosForShowMessage(QModelIndex)));

	this->setFocusPolicy(Qt::StrongFocus);

	this->setRootIsDecorated(false);

}

FriendListView::~FriendListView()
{

}

void FriendListView::mouseDoubleClickEvent( QMouseEvent *event )
{
	QPoint pt = event->pos();

	QModelIndex index = indexAt(pt);

	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		return;
// 		if (isExpanded(index))
// 		{
// 			setExpanded(index,false);
// 		}
// 		else
// 		{
// 			setExpanded(index,true);
// 		}
// 		
	}

	if (pInfo)
	{
		QQChatWindow *pWindow = new QQChatWindow();
		pWindow->setWindowFlags(Qt::SubWindow);
		pWindow->setWindowTitle(QString("��%1������").arg(pInfo->m_Markname));
		pWindow->show();
		if (pInfo->m_bMessageArrive)
		{
			pInfo->m_bMessageArrive = false;
		}

	}


}

void FriendListView::mousePressEvent( QMouseEvent *event )
{
	QPoint pt = event->pos();
	if (event->button() == Qt::LeftButton)
	{
		QModelIndex index = indexAt(pt);

		FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
		FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
		if (pGroupInfo)
		{
			if (isExpanded(index))
			{
				setExpanded(index,false);
			}
			else
			{
				setExpanded(index,true);
			}

		}
	}
	if (event->button() == Qt::RightButton)
	{
		QModelIndex index = indexAt(event->pos());
		FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
		FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());
		if (pGroupInfo)
		{
			return;
		}
		QMenu menu;
		menu.setFixedWidth(150);
		menu.addAction(tr("���ͼ�ʱ��Ϣ"));
		menu.addAction(tr("���͵����ʼ�"));
		menu.addSeparator();
		menu.addAction(tr("�鿴����"));
		menu.addAction(tr("��Ϣ��¼"));
		menu.addSeparator();
		menu.addAction(tr("����Ȩ��"));
		menu.addAction(tr("�޸ı�ע����"));
		menu.addAction(tr("�ƶ���ϵ����"));
		menu.addAction(tr("ɾ������"));
		menu.addAction(tr("�ٱ����û�"));
		menu.addAction(tr("���ѹ���"));
		menu.addSeparator();
		menu.addAction(tr("��Ա��ݹ���"));
		menu.addAction(tr("����QQ�ռ�"));
		menu.exec(mapToGlobal(event->pos()));

	}

}

void FriendListView::mouseMoveEvent( QMouseEvent *event )
{
	QPoint pt = event->pos();

	QModelIndex index = indexAt(pt);

	QRect rect = visualRect(index);

	QRect headerImg(rect);
	headerImg.setWidth(48);
	headerImg.setHeight(48);
	headerImg.setLeft(rect.left()+2);
	headerImg.setTop(rect.top()+2);

	if (m_CurMouseHoverIndex != index)
	{
		m_CurMouseHoverIndex = index;
		emit mouseHoverIndexChanged(m_CurMouseHoverIndex);
	}
	if (!headerImg.contains(pt))
	{
		m_CurMouseHoverIndex = QModelIndex();
		emit mouseHoverIndexChanged(m_CurMouseHoverIndex);
	}
}

void FriendListView::CheckMousePosForShowMessage(QModelIndex index)
{
	if (!index.isValid())
	{
		m_pWidget->hide();
		return;
	}
	QRect tempRect = visualRect(index);
	FriendGroupInfo* pGroupInfo = qobject_cast<FriendGroupInfo*>((QObject*)index.internalPointer());
	if (pGroupInfo)
	{
		m_pWidget->hide();
		return;
	}
	FriendInfo* pInfo = qobject_cast<FriendInfo*>((QObject*)index.internalPointer());

	if (pInfo)
	{
		QPoint widgetPos = this->pos();

		QPoint ptNew(widgetPos.x() - 276,tempRect.y() + 5);

		QPoint ptGlobal = mapToGlobal(ptNew);

		m_pWidget->setGeometry(ptGlobal.x(),ptGlobal.y(),270,149);

		m_pWidget->ui.labelName->setText(pInfo->m_Markname);
		m_pWidget->ui.labelNickName->setText(pInfo->m_nickName);

		m_pTimeChecker->setInterval(200);

		m_pWidget->show();
	}
}

// void FriendListView::CheckMousePosForShow()
// {
// 	
// }

