#include "stdafx.h"
#include "Add.h"
#include "resource.h"
#include "ProductManager.h"

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAddDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CAddDlg::OnBnClickedButtonCancel)
	ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT_NAME, IDC_EDIT_PRICE, &CAddDlg::Validate)
END_MESSAGE_MAP()

BOOL CAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_BUTTON_ADD)->EnableWindow(FALSE);
	return TRUE;
}

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_DIALOG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CAddDlg::OnBnClickedButtonAdd()
{
	UpdateData();
	// TODO: Add your control notification handler code here
	ProductManager* productManager = ProductManager::getInstance();
	CString temp;
	int id = productManager->productList.GetCount()+1;
	GetDlgItem(IDC_EDIT_NAME)->GetWindowTextW(temp);
	CString name = temp;
	GetDlgItem(IDC_EDIT_PRICE)->GetWindowTextW(temp);
	float price = _wtof(temp);
	GetDlgItem(IDC_EDIT_QUANTITY)->GetWindowTextW(temp);

	int quantity = _wtoi(temp);
	Product item;
	item.setID(id);
	item.setName(name);
	item.setPrice(price);
	item.setQuantity(quantity);
	
	//Productmanager obj;

	productManager->productList.AddHead(item);
	MessageBox(_T("Item successfully added"));
	GetDlgItem(IDC_EDIT_NAME)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT_PRICE)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT_QUANTITY)->SetWindowTextW(_T(""));

}


void CAddDlg::OnBnClickedButtonCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CAddDlg::Validate(UINT nID)
{
	CString temp;
	GetDlgItem(nID)->GetWindowTextW(temp);
	if (nID == IDC_EDIT_NAME)
	{
		isValid[0] = !temp.IsEmpty();
	}
	else if (nID == IDC_EDIT_QUANTITY)
	{
		isValid[1] = (temp.SpanIncluding(_T("0123456789")) == temp) && (!temp.IsEmpty());
	}
	else if (nID == IDC_EDIT_PRICE)
	{
		isValid[2] = (temp.SpanIncluding(_T("0123456789.")) == temp) && (!temp.IsEmpty());
	}	
	GetDlgItem(IDC_BUTTON_ADD)->EnableWindow(isValid[0] && isValid[1] && isValid[2]);
}
