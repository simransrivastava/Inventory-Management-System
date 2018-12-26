#pragma once
#include "stdafx.h"
class CAddDlg : public CDialogEx
{
	// Construction
public:
	CAddDlg(CWnd* pParent = NULL);	// standard constructor

									// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
protected:
	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	BOOL isValid[3];
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnEnChangeEditQuantity();
	afx_msg void Validate(UINT nID);
};