#pragma once
#include <QString>
#include <QList>
#include "BuddyItem.h"
#include <QPixmap>

class BuddyItem;

class BuddyTeam
{
public:
	BuddyTeam(QString strGroupName,int iAllNumber,int iCurrentNumber)
	{
		m_GroupName = strGroupName;
		m_iAllNumber = iAllNumber;
		m_iCurrentNumber = iCurrentNumber;

		m_nHeadFlashAnimState = 0;

		m_bExpand = false;

		m_nHeadFlashAnim = 0;

		for (int i = 0;i<9;++i)
		{
			BuddyItem *pNewItem = new BuddyItem();
			m_BuddyItemList.push_back(pNewItem);

			pNewItem->m_lpHeadImg = new QPixmap(":/headers/Resources/94.png");
			pNewItem->m_strMarkName = "����";
			pNewItem->m_strNickName = "����";
			pNewItem->m_strSign = "����һ��ѧMFC";

		}
	}
	~BuddyTeam(void);

	QString	 GetDesc()
	{
		QString str;
		str.sprintf("[%d/%d]",m_iCurrentNumber,m_iAllNumber);

		return m_GroupName + str;
	}

	QString m_GroupName;
	int m_iAllNumber;
	int m_iCurrentNumber;

	int Size()
	{
		return m_BuddyItemList.size();
	}

	void setExpand(bool Expand);

	bool Expand();

	bool m_bExpand;

	QList<BuddyItem*> m_BuddyItemList;

	int m_nHeadFlashAnim;

	int m_nHeadFlashAnimState;
};

