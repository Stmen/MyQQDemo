#include "columnwidget.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QMenu>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QAction>

ColumnWidget::ColumnWidget(QWidget *parent)
	: QWidget(parent)
{
	 m_iCurrentHoverItem = -1;
	 m_iCurrentChooseItem = -1;
	 Init();
	 setMouseTracking(true);

	 m_nLeft = m_nTop = 0;

	 SetCurrentItem(0);
	 setStyleSheet("border:none");
	 this->setFocusPolicy(Qt::StrongFocus);

	 m_bShowRect = false;
}

ColumnWidget::~ColumnWidget()
{

}



void ColumnWidget::paintEvent( QPaintEvent * e )
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.drawPixmap(0,0,width(),height(),QPixmap(":/MainTab/Resources/main_tabctrl_background.png"));

	for (int i = 0;i < m_TabCtrlList.size();++i)
	{
		DrawItem(i);
	}

}

void ColumnWidget::mousePressEvent( QMouseEvent * e )
{
	int iIndex = GetPointIndex(e->pos());
	SetCurrentItem(iIndex);
	update();

	QPoint pt = e->pos();
	if (iIndex == m_iCurrentChooseItem)
	{
		if (m_CurCurrentArrowRect.contains(e->pos()))
		{
			QMenu *pMenu = new QMenu(this);

			QMenu *pHeadImage = new QMenu(pMenu);

			QAction *pShowLargeHead = new QAction(pHeadImage);
			pShowLargeHead->setCheckable(true);
			pShowLargeHead->setChecked(true);
			pShowLargeHead->setText("��ͷ��");

			pHeadImage->addAction(pShowLargeHead);
			pHeadImage->addAction("Сͷ��");
			pHeadImage->addSeparator();

			pHeadImage->addAction("ѡ��ʱ��ʾ��ͷ��");
			pHeadImage->addSeparator();
			pHeadImage->addAction("��ʾ�ҵĴ�ͷ��");
			QAction *pHeaderShow = new QAction(this);
			pHeaderShow->setText("ͷ����ʾ");
			pHeaderShow->setMenu(pHeadImage);
			pMenu->addAction(pHeaderShow);
			pMenu->addAction(new QAction("������ʾ",this));
			pMenu->addAction(new QAction("�б���ʾ",this));
			pMenu->addSeparator();
			pMenu->addAction(new QAction("������ʾ",this));
			pMenu->addAction(new QAction("ˢ�º����б�",this));
			pMenu->addAction(new QAction("��ʾ������ϵ��",this));
			pMenu->addSeparator();
			pMenu->addAction(new QAction("��ʾ����������",this));
			pMenu->addAction(new QAction("��ʾİ���˷���",this));
			pMenu->addAction(new QAction("��ʾ������",this));
			pMenu->exec(e->globalPos()+QPoint(0,20));
		}
		emit currentRowChanged(m_iCurrentChooseItem);
	}
}

void ColumnWidget::mouseMoveEvent( QMouseEvent *e )
{
	int iIndex = GetPointIndex(e->pos());
	SetHoverItem(iIndex);
	update();
}

int ColumnWidget::GetPointIndex(const QPoint &pt )
{
	int iRet = -1;
	for (int i = 0;i < m_TabCtrlList.size();++i)
	{
		QRect rect;
		GetItemRectByIndex(i,rect);
		if (rect.contains(pt))
		{
			iRet = i;
			break;
		}
	}

	return iRet;
}


bool ColumnWidget::GetItemRectByIndex(int nIndex, QRect& rect)
{
	TabCtrlItem * lpItem;
	int nLeft = m_nLeft, nTop = m_nTop;

	int iWidth = (width()-2)/3-1;

	for (int i = 0; i < (int)m_TabCtrlList.size(); i++)
	{
		lpItem = m_TabCtrlList.at(i);
		if (lpItem != NULL)
		{
			if (i == nIndex)
			{
				rect = QRect(nLeft, nTop,iWidth,35);
				return TRUE;
			}
			nLeft += iWidth;
			nLeft += 1;
		}
	}

	return false;
}


void ColumnWidget::DrawItem(int i)
{
	QPainter painter(this);

	TabCtrlItem * lpItem = m_TabCtrlList.at(i);
	if (NULL == lpItem) return;

	QRect rcItem;
	GetItemRectByIndex(i, rcItem);


	if (m_iCurrentChooseItem == i)
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);
		painter.drawPixmap(rcItem,QPixmap(":/MainTab/Resources/maintab/main_tab_check.png"));

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);

		if (m_bShowRect)
		{
			painter.setPen(QPen(Qt::black,0.5,Qt::DotLine));
			painter.drawRect(rcItem);
		}
	}
	else if (m_iCurrentHoverItem == i)
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);
	}
	else
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);
	}

	if (m_iCurrentChooseItem == i)
	{

			QRect rcArrow = rcItem;
// 			rcArrow.setLeft(rcItem.left()+lpItem->m_nLeftWidth);
// 			rcArrow.setTop(rcItem.top()+20);

			int m = rcArrow.right()-14-6;
			int n = rcArrow.left()+2;
			painter.drawPixmap(rcArrow.right()-14 - 6,rcArrow.left()+2,14,30,QPixmap(":/MainTab/Resources/maintab/main_tabbtn_down.png"));

			QRect temp(rcItem.width()-14 - 6,2,14,30);
			m_CurCurrentArrowRect = temp;

			int iXPosition = rcItem.left() + rcItem.width()/3 + 3;


			painter.drawPixmap(iXPosition,0,22,38,QPixmap(":/MainTab/Resources/main_tabctrl_arrow.png"));

	}

}


void ColumnWidget::CalcCenterRect(QRect& rcDest, int cx, int cy, QRect& rcCenter )
{
	int x = ((rcDest.width()) - cx + 1) / 2;
	int y = ((rcDest.height()) - cy + 1) / 2;

	rcCenter.setLeft(rcDest.left() + x);
	rcCenter.setTop(rcDest.top() + y);
	rcCenter.setWidth(cx);
	rcCenter.setHeight(cy);

}

void ColumnWidget::keyPressEvent( QKeyEvent * e )
{
	if (e->key() == Qt::Key_Left)
	{
		m_iCurrentChooseItem -= 1;
		if (m_iCurrentChooseItem < 0)
		{
			m_iCurrentChooseItem += 3;
		}
		update();
		emit currentRowChanged(m_iCurrentChooseItem);
		return;
	}
	if (e->key() == Qt::Key_Right)
	{
		m_iCurrentChooseItem += 1;
		if (m_iCurrentChooseItem >= 3)
		{
			m_iCurrentChooseItem -= 3;
		}
		update();
		emit currentRowChanged(m_iCurrentChooseItem);
		return;
	}

}

void ColumnWidget::focusInEvent( QFocusEvent *e )
{
	if (e->reason() == Qt::TabFocus)
	{
		m_bShowRect = true;
	}
// 	else
// 	{
// 		m_bShowRect = false;
// 	}

}

// void ColumnWidget::focusOutEvent( QFocusEvent *e )
// {
// 	m_bShowRect = false;
// }
