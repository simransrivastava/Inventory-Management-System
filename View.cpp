// listcontrolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "View.h"
#include "Product.h"
#include "resource.h"
#include "ProductManager.h"

CViewProducts::CViewProducts(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VIEW_DIALOG, pParent)
{
}

void CViewProducts::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_view);
}

BEGIN_MESSAGE_MAP(CViewProducts, CDialogEx)
END_MESSAGE_MAP()


// ClistcontrolDlg message handlers

BOOL CViewProducts::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	CString temp;
	m_view.GetClientRect(&rect);
	int ncolInterval = rect.Width() / 4;
	m_view.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_view.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_view.InsertColumn(0, _T("ID"), LVCFMT_LEFT, ncolInterval);
	m_view.InsertColumn(1, _T("Name"), LVCFMT_LEFT, ncolInterval);
	m_view.InsertColumn(2, _T("Price"), LVCFMT_LEFT, ncolInterval);
	m_view.InsertColumn(3, _T("Quantity"), LVCFMT_LEFT, ncolInterval);
	ProductManager* productManager = ProductManager::getInstance();
	POSITION pos = productManager->productList.GetHeadPosition();
	while (pos != NULL)
	{
		Product item = productManager->productList.GetNext(pos);
		temp.Format(_T("%d"), item.getID());
		int nIndex = m_view.InsertItem(0, temp);
		m_view.SetItemText(nIndex, 1, item.getName());
		temp.Format(_T("%.2f"), item.getPrice());
		m_view.SetItemText(nIndex, 2, temp);
		temp.Format(_T("%d"), item.getQuantity());
		m_view.SetItemText(nIndex, 3, temp);
	}
	return TRUE;
}