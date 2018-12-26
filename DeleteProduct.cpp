// Login.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteProduct.h"
#include "afxdialogex.h"
#include "ProductManager.h"
#include "Product.h"
#include "resource.h"

// Login dialog

IMPLEMENT_DYNAMIC(CDeleteProduct, CDialogEx)

CDeleteProduct::CDeleteProduct(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DELETE_DIALOG, pParent)
{

}


void CDeleteProduct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteProduct, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DEL_DELETE, &CDeleteProduct::OnBnClickedButtonDelete)
END_MESSAGE_MAP()

BOOL CDeleteProduct::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}

void CDeleteProduct::OnBnClickedButtonDelete()
{
	CString temp;
	GetDlgItem(IDC_EDIT_DEL_PRODUCT_ID)->GetWindowTextW(temp);
	int productID = _wtoi(temp);
	ProductManager* productManager = ProductManager::getInstance();
	POSITION pos = NULL;
	Product item;
	item.setID(productID);
	pos = productManager->productList.Find(item);
	if (!pos)
	{
		MessageBox(_T("Invalid Product ID"));
	}
	else
	{
		productManager->productList.RemoveAt(pos);
		MessageBox(_T("Item successfully deleted"));
		GetDlgItem(IDC_EDIT_DEL_PRODUCT_ID)->SetWindowTextW(_T(""));
	}
}
