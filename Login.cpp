// Login.cpp : implementation file
//

#include "stdafx.h"
#include "SMS.h"
#include "Login.h"
#include "afxdialogex.h"
#include "SMSDlg.h"


// Login dialog

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LOGIN_USERNAME, userName);
	DDX_Text(pDX, IDC_LOGIN_PASSWORD, password);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(ID_BTN_LOGIN, &Login::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// Login message handlers


void Login::OnBnClickedBtnLogin()
{
	UpdateData();
	if (userName == "Admin"  && password == "Admin")
	{

		CSMSDlg *obj = new CSMSDlg();
		Login::OnCancel();
		obj->DoModal();
	}
	else
	{
		MessageBox(_T("Invalid username and password"));
	}
	// TODO: Add your control notification handler code here
}
