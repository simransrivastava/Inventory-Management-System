#pragma once
#include "stdafx.h"

// Login dialog

class CEditProduct : public CDialogEx
{
	DECLARE_DYNAMIC(CEditProduct)

public:
	BOOL isValid[3];
	CEditProduct(CWnd* pParent = NULL);   // standard constructor

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_DIALOG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void saveProductInfo(POSITION pos);
	afx_msg void OnStnClickedStaticProductName();
	afx_msg void OnStnClickedStaticProductQuantity();
	afx_msg void Validate(UINT nID);
};
