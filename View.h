
// listcontrolDlg.h : header file
//

#pragma once
#include "stdafx.h"


// ClistcontrolDlg dialog
class CViewProducts : public CDialogEx
{
	// Construction
public:
	CViewProducts(CWnd* pParent = NULL);	// standard constructor

											// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_DIALOG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_view;
};
#pragma once
