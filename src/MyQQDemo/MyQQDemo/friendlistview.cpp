#include "friendlistview.h"
#include <QMouseEvent>
#include "FriendGroupInfo.h"
#include "FriendInfo.h"
#include <QMenu>

FriendListView::FriendListView(QWidget *parent)
	: QTreeView(parent)
{

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
		if (isExpanded(index))
		{
			setExpanded(index,false);
		}
		else
		{
			setExpanded(index,true);
		}
		
	}

	if (pInfo)
	{
	}


}

void FriendListView::mousePressEvent( QMouseEvent *event )
{
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
