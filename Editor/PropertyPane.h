#pragma once
#include "afxdockablepane.h"
#include "Irrlicht.h"
#include<vector>

enum ID
{
	P_X, P_Y, P_Z,
	S_X, S_Y, S_Z,
	R_X, R_Y, R_Z,
	C_A, C_R, C_G, C_B,
	C_2A, C_2R, C_2G, C_2B,
	D_X, D_Y, D_Z, D_Angle,
	Part_V_Small, Part_V_Large,
	Part_W_Small, Part_H_Small, Part_W_Large, Part_H_Large,
	Part_Life_Small, Part_Life_Large,
	Part_Misc_Shape, Part_Misc_Motion,
	E_LIGHT,
	RADIUS,
	NAME
};

struct IdProperty
{
	CMFCPropertyGridProperty * pProp;
	ID pId;
};


class CPaneCtrl:public CMFCPropertyGridCtrl
{
public:
	std::vector<IdProperty>idPropList;
public:
	virtual void OnPropertyChanged(CMFCPropertyGridProperty* pProp) const;
};

class CPropertyPane :
	public CDockablePane
{
public:
	//控件
	CPaneCtrl m_wndPropList;
public:
	CPropertyPane(void);
	~CPropertyPane(void);
public:
	//辅助函数，包括构造属性列表
	void UpdatePropList();
public:
	//默认值较多的外部接口，针对Property
	BOOL create(CFrameWndEx * parent);
public:
	//消息处理
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

