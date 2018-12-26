// Login.cpp : implementation file
//

#include "stdafx.h"
#include "EditProduct.h"
#include "afxdialogex.h"
#include "ProductManager.h"
#include "Product.h"
#include "resource.h"

// Login dialog

IMPLEMENT_DYNAMIC(CEditProduct, CDialogEx)

CEditProduct::CEditProduct(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EDIT_DIALOG, pParent)
{

}


void CEditProduct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditProduct, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CEditProduct::OnBnClickedButtonSearch)
	ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT_PRODUCT_NAME, IDC_EDIT_PRODUCT_QUANTITY, &CEditProduct::Validate)
END_MESSAGE_MAP()

BOOL CEditProduct::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int nIdx = IDC_STATIC_PRODUCT_NAME; nIdx <= IDC_EDIT_PRODUCT_QUANTITY; nIdx++)
	{
		GetDlgItem(nIdx)->ShowWindow(FALSE);
	}
	return TRUE;
}

void CEditProduct::OnBnClickedButtonSearch()
{
	CString temp;
	CString strMode;
	GetDlgItem(IDC_BUTTON_SEARCH)->GetWindowTextW(strMode);
	CString productName;
	float productPrice;
	int productQuantity;
	GetDlgItem(IDC_EDIT_PRODUCT_ID)->GetWindowTextW(temp);
	int productID = _wtoi(temp);
	ProductManager* productManager = ProductManager::getInstance();
	POSITION pos = NULL;
	Product item;
	item.setID(productID);
	pos = productManager->productList.Find(item);
	if (strMode == "Search")
	{
		if (!pos)
		{
			MessageBox(_T("Invalid Product ID"));
		}
		else
		{
			GetDlgItem(IDC_EDIT_PRODUCT_ID)->EnableWindow(FALSE);
			Product itemTemp = productManager->productList.GetAt(pos);
			for (int nIdx = IDC_STATIC_PRODUCT_NAME; nIdx <= IDC_EDIT_PRODUCT_QUANTITY; nIdx++)
			{
				GetDlgItem(nIdx)->ShowWindow(TRUE);
			}
			GetDlgItem(IDC_EDIT_PRODUCT_NAME)->SetWindowTextW(itemTemp.getName());
			temp.Format(_T("%f"), itemTemp.getPrice());
			GetDlgItem(IDC_EDIT_PRODUCT_PRICE)->SetWindowTextW(temp);
			temp.Format(_T("%d"), itemTemp.getQuantity());
			GetDlgItem(IDC_EDIT_PRODUCT_QUANTITY)->SetWindowTextW(temp);
			GetDlgItem(IDC_BUTTON_SEARCH)->SetWindowTextW(_T("Save"));
			Validate(IDC_EDIT_PRODUCT_NAME);
		}
	}
	else
	{
		saveProductInfo(pos);
		MessageBox(_T("Saved successfully!"));
	}
}

void CEditProduct::saveProductInfo(POSITION pos)
{
	CString temp;
	ProductManager* productManager = ProductManager::getInstance();
	Product item;
	GetDlgItem(IDC_EDIT_PRODUCT_ID)->GetWindowTextW(temp);
	item.setID(_wtoi(temp));
	GetDlgItem(IDC_EDIT_PRODUCT_NAME)->GetWindowTextW(temp);
	item.setName(temp);
	GetDlgItem(IDC_EDIT_PRODUCT_PRICE)->GetWindowTextW(temp);
	item.setPrice(_wtof(temp));
	GetDlgItem(IDC_EDIT_PRODUCT_QUANTITY)->GetWindowTextW(temp);
	item.setQuantity(_wtoi(temp));
	productManager->productList.SetAt(pos, item);
}

void CEditProduct::Validate(UINT nID)
{
	CString temp;
	GetDlgItem(nID)->GetWindowTextW(temp);
	isValid[nID - IDC_EDIT_PRODUCT_NAME] = !temp.IsEmpty();
	GetDlgItem(IDC_BUTTON_SEARCH)->EnableWindow(isValid[0] && isValid[1] && isValid[2]);
	GetDlgItem(nID)->GetWindowTextW(temp);
	if (nID == IDC_EDIT_PRODUCT_NAME)
	{
		isValid[0] = !temp.IsEmpty();
	}
	else if (nID == IDC_EDIT_PRODUCT_QUANTITY)
	{
		isValid[1] = (temp.SpanIncluding(_T("0123456789")) == temp) && (!temp.IsEmpty());
	}
	else if (nID == IDC_EDIT_PRODUCT_PRICE)
	{
		isValid[2] = (temp.SpanIncluding(_T("0123456789.")) == temp) && (!temp.IsEmpty());
	}
	GetDlgItem(IDC_BUTTON_SEARCH)->EnableWindow(isValid[0] && isValid[1] && isValid[2]);
}
