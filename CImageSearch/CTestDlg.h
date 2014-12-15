// CTestDlg.h : header file
//







#if !defined(AFX_CTESTDLG_H__DAD70621_AE53_4388_ACE3_7D87445A48C1__INCLUDED_)
#define AFX_CTESTDLG_H__DAD70621_AE53_4388_ACE3_7D87445A48C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCTestDlg dialog

class CCTestDlg : public CDialog
{
// Construction
public:

	void ShowHideWin(int nFlag, int a);
	int SaveLabel(int n , int nEachPachNum);
	int ReturnImageName(CString strQuery);
	int RetImgsNumber(CString strQuery);

	int haveTopicName; // 如果查询概念词是第一次查询,则haveTopicName=2;如果是第二次或更多次数显,则此值为1;
	int nPageNo;  // 图像页数的表征，=1表示第一页;
	int ShowEachPage(int n , int nEachPachNum,int nFlag); 
	int ShowEachPage(int n , int nEachPachNum,int nFlag, CString qryImg);
	int  nTotalReturn; // 将总的返回的推向的个数设置为类变量,为了其他函数的调用.
	//int  ReturnImageName(CString strQuery);
	//int i;

	// 标记图像是否被标注的变量;


	CWnd *pwnd;
	CDC  *pdc;
	HDC  hdc;

	CString strQuery;

	CString qryImg ;
	int showDefaultFlag ;
	



	void OnShowQryImg(CString strPhotoName);

	void OnShowPhoto12(CString strPhotoName);
	void OnShowPhoto11(CString strPhotoName);
	void OnShowPhoto10(CString strPhotoName);
	void OnShowPhoto9(CString strPhotoName);
	void OnShowPhoto8(CString strPhotoName);
	void OnShowPhoto7(CString strPhotoName);
	void OnShowPhoto6(CString strPhotoName);
	void OnShowPhoto5(CString strPhotoName);
	void OnShowPhoto4(CString strPhotoName);
	void OnShowPhoto3(CString strPhotoName);
	void OnShowPhoto2(CString strPhotoName);
	void OnShowPhoto1(CString strPhotoName);
	CCTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCTestDlg)
	enum { IDD = IDD_CTEST_DIALOG };
	CStatic m_cphoto;
	// 取值为-1,0,1这三个值,用来标记图像是否被标记;
	// 即在界面显示的图像中被标记"是"的赋值1,标记"否"的赋值为0,未标记的赋值-1;
	// 这样未标记的图像重新进行显示;	
	int		m_RadioCancel1;
	int		m_RadioCancel6;
	int		m_RadioCancel7;
	int		m_RadioCancel8;
	int		m_RadioCancel9;
	int		m_RadioCancel10;
	int		m_RadioCancel11;
	int		m_RadioCancel12;
	int		m_RadioCancel2;
	int		m_RadioCancel3;
	int		m_RadioCancel4;
	int		m_RadioCancel5;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonPre();
	afx_msg void OnButtonNext();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	afx_msg void OnRadio8();
	afx_msg void OnRadio9();
	afx_msg void OnRadio10();
	afx_msg void OnRadio11();
	afx_msg void OnRadio12();
	afx_msg void OnRadio13();
	afx_msg void OnRadio14();
	afx_msg void OnRadio15();
	afx_msg void OnRadio16();
	afx_msg void OnRadio17();
	afx_msg void OnRadio18();
	afx_msg void OnRadio19();
	afx_msg void OnRadio20();
	afx_msg void OnRadio21();
	afx_msg void OnRadio22();
	afx_msg void OnRadio23();
	afx_msg void OnRadio24();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnStnClickedStatic3();
	afx_msg void OnBnClickedRect2();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTDLG_H__DAD70621_AE53_4388_ACE3_7D87445A48C1__INCLUDED_)
