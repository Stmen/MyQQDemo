#pragma once
#include <QString>
class QPixmap;

class BuddyItem
{
public:
	BuddyItem(void);
	~BuddyItem(void);

public:
	int							m_nID;						// ��ID
	QString						m_strQQNum;					// QQ����
	QString						m_strNickName;				// �ǳ�
	QString						m_strMarkName;				// ��ע
	QString						m_strSign;					// ǩ��
	bool						m_bOnline;					// �Ƿ����߱�־
	bool						m_bOnlineAnim;				// ���߶�����־
	int							m_nOnlineAnimState;			// ���߶���״̬
	bool						m_bOfflineAnim;				// ���߶�����־
	bool						m_bHeadFlashAnim;			// ͷ������������־
	int							m_nHeadFlashAnimState;		// ͷ����������״̬
	QPixmap					* m_lpHeadImg;				// ͷ��ͼƬ
	bool						m_bGender;	
};

