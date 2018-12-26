#pragma once
#include "stdafx.h"

// Login dialog

class CDeleteProduct : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteProduct)

public:
	CDeleteProduct(CWnd* pParent = NULL);   // standard constructor

										  // Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonDelete();
};
