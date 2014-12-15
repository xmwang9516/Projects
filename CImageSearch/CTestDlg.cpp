// CTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CTest.h"
#include "CTestDlg.h"

#include <fstream>

#include <string>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTestDlg dialog

CCTestDlg::CCTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCTestDlg)

	// ��ʼ��Ϊ-1,��ʾͼ��û�б����,�������ʱ,m_RadioCancel�ͻᷢ���仯;

	m_RadioCancel1 = -1;  // λ��1��de���;
	m_RadioCancel6 = -1;
	m_RadioCancel7 = -1;
	m_RadioCancel8 = -1;
	m_RadioCancel9 = -1;
	m_RadioCancel10 = -1;
	m_RadioCancel11 = -1;
	m_RadioCancel12 = -1;
	m_RadioCancel2 = -1;
	m_RadioCancel3 = -1;
	m_RadioCancel4 = -1;
	m_RadioCancel5 = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// ��ӳ�ʼ��;
	nPageNo = 0;  // ��ʼ��nPageNoΪ0,�����仯ָʾ��һҳ����һҳ;
	nTotalReturn = 0;
	haveTopicName = 0;



}

void CCTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCTestDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_RadioCancel1);
	DDX_Radio(pDX, IDC_RADIO11, m_RadioCancel6);
	DDX_Radio(pDX, IDC_RADIO13, m_RadioCancel7);
	DDX_Radio(pDX, IDC_RADIO15, m_RadioCancel8);
	DDX_Radio(pDX, IDC_RADIO17, m_RadioCancel9);
	DDX_Radio(pDX, IDC_RADIO19, m_RadioCancel10);
	DDX_Radio(pDX, IDC_RADIO21, m_RadioCancel11);
	DDX_Radio(pDX, IDC_RADIO23, m_RadioCancel12);
	DDX_Radio(pDX, IDC_RADIO3, m_RadioCancel2);
	DDX_Radio(pDX, IDC_RADIO5, m_RadioCancel3);
	DDX_Radio(pDX, IDC_RADIO7, m_RadioCancel4);
	DDX_Radio(pDX, IDC_RADIO9, m_RadioCancel5);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCTestDlg, CDialog)
	//{{AFX_MSG_MAP(CCTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonPre)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonNext)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, OnRadio8)
	ON_BN_CLICKED(IDC_RADIO9, OnRadio9)
	ON_BN_CLICKED(IDC_RADIO10, OnRadio10)
	ON_BN_CLICKED(IDC_RADIO11, OnRadio11)
	ON_BN_CLICKED(IDC_RADIO12, OnRadio12)
	ON_BN_CLICKED(IDC_RADIO13, OnRadio13)
	ON_BN_CLICKED(IDC_RADIO14, OnRadio14)
	ON_BN_CLICKED(IDC_RADIO15, OnRadio15)
	ON_BN_CLICKED(IDC_RADIO16, OnRadio16)
	ON_BN_CLICKED(IDC_RADIO17, OnRadio17)
	ON_BN_CLICKED(IDC_RADIO18, OnRadio18)
	ON_BN_CLICKED(IDC_RADIO19, OnRadio19)
	ON_BN_CLICKED(IDC_RADIO20, OnRadio20)
	ON_BN_CLICKED(IDC_RADIO21, OnRadio21)
	ON_BN_CLICKED(IDC_RADIO22, OnRadio22)
	ON_BN_CLICKED(IDC_RADIO23, OnRadio23)
	ON_BN_CLICKED(IDC_RADIO24, OnRadio24)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CCTestDlg::OnBnClickedButton3)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTestDlg message handlers

BOOL CCTestDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	for (int c=1;c<=12;c++)
	{
		ShowHideWin(0, c);
	}

	showDefaultFlag = 1; // ��ʼֵ��Ϊ0;

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCTestDlg::OnPaint() 
{
	if (showDefaultFlag == 1)
	{
		// add default image;
		CString  defaultImg = "";
		defaultImg.Format("%s",".\\defaultImg.jpg");
		//MessageBox(defaultImg,"OK",0);
		OnShowQryImg(defaultImg);
		showDefaultFlag = 2;
	}

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

		



	}
	else
	{
		
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//ÿ12��ͼ����Ϊһ��ѭ������ҳ,����ͨ������õ�ͼ����Ŀ,Ȼ��ֱ��ȷ�����Էּ�ҳ;
void CCTestDlg::OnButtonPre()  // ��һҳ;
{
	/***********************************************************************************
	// TODO: Add your control notification handler code here
	//OnShowPhoto1(".//ZP.bmp"); //λ��1����Ƭ;
	//OnShowPhoto2(".//22.bmp"); //λ��2����Ƭ;
	// ���"��һҳ"ʱҲҪ���浱ǰҳ�ı�ע�����һ����ʱ�����������;
	//  
	***********************************************************************************/
	//UpdateData(1);

	char szLabelResults[30];  //1 1 -1 1 -1  �������пո�Ķ�д��ʽ,���浱ǰҳ��ͼ���ע���.
	char szShowPage[30];

	CString strReadIndex = "";
	CString strReadValue = "";
	CString strLabelsFile = "";
	int i = 0;
	int j = 0;

	memset(szLabelResults,0,sizeof(szLabelResults));
	memset(szShowPage,0,sizeof(szShowPage));

	////// ��������ʾ��ǰҳ��Ĵ���;////////////////////////////////////////
	if (nPageNo > 0)
	{
		if (nPageNo==1)
		{
			//ShowEachPage(nPageNo,12);  // ����ǵ�һҳ,����ʾ��һҳ��ͼ�����;
			sprintf(szShowPage,"%s","��ǰ��Ϊ��1ҳ");
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
		else
		{
			nPageNo -= 1; // ��ǰ���ע���������ٽ�ҳ���1,��ʾ��һҳ; 
			ShowEachPage(nPageNo,12, haveTopicName);
			sprintf(szShowPage,"%d/%d ҳ",nPageNo,(nTotalReturn/12+1));
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
	}

	////////////////////////////////////////////////////////////////////////	
}

void CCTestDlg::OnButtonNext() // ��һҳ; 
{
	// TODO: Add your control notification handler code here
	/******************************************************************************************
	//�ڴ˺����д����ǩ���,���������һҳ��ʱ����һҳ�ı�ע�����ʱ������һ��������
	//������ͼ�񶼱�ע��֮���ٽ����������һ���ļ���.
	//�����"��һҳ"ʱ����ǰҳ�ı�ע������ܲ�����ͬ����ʱ������һ�����������?
	//�����б�����ʱ����ÿҳ12�������ӣ�û�б�ע������ͼ�����ʼ����0ֵ.
	//���"��һҳ"ʱ,Ҫ����һҳ�ı�ע�����ʾ����,ÿ����Դ�"��һҳ",���ν�ÿҳ�ı�ע�����ʾ����.
	//�˺����л�Ҫ���Ƿ��ص����һҳ��ͼ��С��12�����;

	// 
	*******************************************************************************************/
	// UpdateData(1);

	char szShowPage[30];
	memset(szShowPage,0,sizeof(szShowPage));

	if (nPageNo > 0)
	{
		if(nPageNo == (nTotalReturn/12+1)) // ���һҳ���ж�����;
			//if (nPageNo==12)  // ��֤��������12Ϊ��;
		{
			//ShowEachPage(nPageNo,nTotalReturn-(nPageNo-1)*12);  // ������һҳ,����else���Ѿ���ʾ����һҳ��ͼ��,���ԾͲ�Ҫ��ʾ��;
			SaveLabel(nPageNo , nTotalReturn-(nPageNo-1)*12);
			sprintf(szShowPage,"%s","��ǰ��Ϊ���ҳ");
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
		else
		{	
			SaveLabel(nPageNo , 12);
			nPageNo += 1; // ��ǰ���ע���������ٽ�ҳ���1,��ʾ��һҳ; 	
			sprintf(szShowPage,"%d/%d ҳ",nPageNo,(nTotalReturn/12+1));
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
			ShowEachPage(nPageNo,12,haveTopicName);  // ��ʾÿҳ��ͼ�����;
		}
	}

}

void CCTestDlg::OnOK() // ȷ��,Ȼ��Ժ�����Ӧ��ǩ��ͼ����в���,������ʾǰ12��ͼ��;
{
	// TODO: Add extra validation here
	/***************************************************************************************
	// �˴����о���Ĳ������򵥵��Ƕ�ͼ���ǩ���ѯ�ʽ���ƥ��,����ͼ���ͼ����б�ע.
	// ����ͼ����ÿҳ12��������ʾ.
	// ���Ҫ��ͼ����м������߱�ע����,�Ϳ����ڴ˴�������дһ���������ý��д���.
	// ����õ�Ҫ���ص�ͼ����ܸ���;
	// ���ú���ShowEachPage(int n , int nEachPachNum);
	// ��ȡ�û������ѯ��strQuery;

	//
	***************************************************************************************/

	UpdateData(1);


	char szShowPage[20]; // ��ǰҳ
	char szTotalNum[20]; // ������ҳ,ͼ�����;
	CString strKeyReadIndex = "";
	CString strKeyReadTopic = "";
	CString strFindQuery = "";
	CString strLabelsFile = "";
	CString strRetImageFile = "";
	CString strTotalNum = "";
	CString strFileLabel = "";
	//char str[100];//���峣����Ŀ����Ϊ�˶�ȡ�㹻������
	int iTotalTopic;
	int i = 0;
	int n = 0;
	int j = 0;


	memset(szShowPage,0,sizeof(szShowPage));
	memset(szTotalNum,0,sizeof(szTotalNum));

	//CString strQuery;
	strQuery = "";

	GetDlgItemText(IDC_EDIT_TOPIC,strQuery); // ��ȡ�û������ѯ��strQuery;


	haveTopicName = 2;

	if (haveTopicName == 1)
	{
		//DeleteFile(".\\ReturnImages\\SecRetImages.txt"); // �ڼ�����һ������ʱ�ֻ����һ��ini�ļ�,��˽�ǰһ��ɾ��.
		//// ����и���ʵ����е�ͼ��û�б���ע��ͼ�񷵻���ʾ����ע�Ĵ���;
		//         //MessageBox("TopicName���д˸���",NULL,MB_OK);
		//strLabelsFile.Format(".\\NewImageLabels\\%sLabels.txt",strQuery); // ���˸��������,���ҵ��������ʵ�����ͼ��ı�ǽ���ļ�;
		//strKeyReadIndex = "";
		//         strKeyReadTopic = "";
		//strKeyReadIndex.Format("%s","TotalNum");
		//         GetPrivateProfileString("ImageLabels",strKeyReadIndex,"-1",strKeyReadTopic.GetBuffer(500),500,strFileLabel);
		//   n = atoi(strKeyReadTopic); // �������Ҫ��ķ��ص�ͼ��ĸ���;
		//iTotalTopic = 0;
		//for (j=1;j<=n;j++)
		//{
		//	strKeyReadIndex = "";
		//	strKeyReadTopic = "";
		//    strKeyReadIndex.Format("labels%d",j);
		//	GetPrivateProfileString("ImageLabels",strKeyReadIndex,"-1",strKeyReadTopic.GetBuffer(500),500,strFileLabel);
		//             if (atoi(strKeyReadTopic) == (-1))
		//             {
		//                 iTotalTopic += 1;
		//		strKeyReadIndex = "";
		//	    strKeyReadTopic = "";
		//		strKeyReadIndex.Format("ReturnImages%d",j); //�ҳ���Ӧ��δ����ǵ�ͼ��,��ReturnImages��;
		//		GetPrivateProfileString("ImageName",strKeyReadIndex,0,strKeyReadTopic.GetBuffer(500),500,strRetImageFile);
		//		strKeyReadIndex = "";
		//		strKeyReadIndex.Format("SecRetImage%d",iTotalTopic); // ��û�б���ǵ�ͼ����ʱ��������һ��ini�ļ���:
		//                 WritePrivateProfileString("SecRetImages",strKeyReadIndex,strKeyReadTopic,".\\ReturnImages\\SecRetImages.txt");
		//             }
		//}

		// �����ǽ�δ��ǵ�ͼ�񱣴���һ��ini��,����ΪiTotalTopic-1;

		//nTotalReturn = iTotalTopic; // ������������ͼ�񷵻ر�����һ��ini�ļ���;

		//if (nTotalReturn > 0)
		//{
		//	nPageNo = 1; //����������ʱ,��nPageNo��ֵΪ1,��ʾ��ʾ��һҳ;
		//	if(nTotalReturn <= 12)  // ���ص�ͼ��С��12�������;
		//	{
		//		ShowEachPage(nPageNo,nTotalReturn,haveTopicName); // �ڶ���������ʾÿҳ��ʾ��ͼ�����,��Ϊ���һҳͼ����ܲ���12��;
		//	}
		//	else     // ͼ��ҳ������12�����;
		//	{
		//		ShowEachPage(nPageNo,12,haveTopicName);  //ͼ��ҳ������12�������ʱ;
		//	}		
		//	sprintf(szTotalNum,"��%d��ͼ��",nTotalReturn);
		//	GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);		
		//	sprintf(szShowPage,"%d/%d ҳ",nPageNo,(nTotalReturn/12+1));
		//    GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);				
		//}
	}else if(haveTopicName ==2)
	{	
		//nTotalReturn = ReturnImageName(qryImg); // ������������ͼ�񷵻ر�����һ��ini�ļ���;

		nTotalReturn = RetImgsNumber(qryImg); // ���ؽ��ͼ���ļ�����;

		if (nTotalReturn > 0) // ����ͼ���ܸ��� Ҫ����0,���������;
		{
			nPageNo = 1; //����������ʱ,��nPageNo��ֵΪ1,��ʾ��ʾ��һҳ;
			
			strKeyReadIndex = "";
			strKeyReadTopic = "";
		

			strKeyReadIndex = "";
			strKeyReadTopic = "";
			strLabelsFile = "";
		
			//nTotalReturn = 224;
			if(nTotalReturn <= 12)  // ���ص�ͼ��С��12�������;
			{
				//ShowEachPage(nPageNo,nTotalReturn,haveTopicName); // �ڶ���������ʾÿҳ��ʾ��ͼ�����,��Ϊ���һҳͼ����ܲ���12��;
				ShowEachPage(nPageNo,nTotalReturn,haveTopicName,qryImg);
			}
			else      // ͼ��ҳ������1�����;
			{
				//ShowEachPage(nPageNo,12,haveTopicName);  //ͼ��ҳ������12�������ʱ;
				ShowEachPage(nPageNo,12,haveTopicName,qryImg);
			}

			sprintf(szTotalNum,"��%d��ͼ��",nTotalReturn);
			GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);
			sprintf(szShowPage,"%d/%d ҳ",nPageNo,(nTotalReturn/12+1));
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);

			UpdateData(0);
		}
	}


	UpdateData(0);



	//UpdateData(0);
	//CDialog::OnOK();
}

void CCTestDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}

void CCTestDlg::OnShowPhoto1(CString strPhotoName)  // ��ʾͼ����,ÿҳ��ʾʱ�����������;
{
	/**************************************************************************************************************  
	HBITMAP bmp = (HBITMAP)::LoadImage(0,  strPhotoName,IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR|LR_LOADFROMFILE);
	m_cphoto1.SetBitmap(bmp);   // �˴�����ʾbmpͼ��,����Ҫ���ص�ͼ����jpg��;
	DeleteObject(bmp);
	UpdateData(0);
	return 0;

	//
	****************************************************************************************************************/

	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect01;
	CStatic *m_pic01;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic01  = (CStatic*)GetDlgItem(IDC_STATIC1);
	pDC = (*m_pic01).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic01).GetWindowRect(&rect01);

		//get image height and width   
		Width   = (unsigned long) rect01.Width();
		Height  = (unsigned long) rect01.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  

}

void CCTestDlg::OnShowPhoto2(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect02;
	CStatic *m_pic02;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic02  = (CStatic*)GetDlgItem(IDC_STATIC2);
	pDC = (*m_pic02).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic02).GetWindowRect(&rect02);

		//get image height and width   
		Width   = (unsigned long) rect02.Width();
		Height  = (unsigned long) rect02.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto3(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect03;
	CStatic *m_pic03;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic03  = (CStatic*)GetDlgItem(IDC_STATIC3);
	pDC = (*m_pic03).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic03).GetWindowRect(&rect03);

		//get image height and width   
		Width   = (unsigned long) rect03.Width();
		Height  = (unsigned long) rect03.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  

}

void CCTestDlg::OnShowPhoto4(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect04;
	CStatic *m_pic04;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic04  = (CStatic*)GetDlgItem(IDC_STATIC4);
	pDC = (*m_pic04).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic04).GetWindowRect(&rect04);

		//get image height and width   
		Width   = (unsigned long) rect04.Width();
		Height  = (unsigned long) rect04.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto5(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect05;
	CStatic *m_pic05;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic05  = (CStatic*)GetDlgItem(IDC_STATIC5);
	pDC = (*m_pic05).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic05).GetWindowRect(&rect05);

		//get image height and width   
		Width   = (unsigned long) rect05.Width();
		Height  = (unsigned long) rect05.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto6(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect06;
	CStatic *m_pic06;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic06  = (CStatic*)GetDlgItem(IDC_STATIC6);
	pDC = (*m_pic06).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic06).GetWindowRect(&rect06);

		//get image height and width   
		Width   = (unsigned long) rect06.Width();
		Height  = (unsigned long) rect06.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto7(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect07;
	CStatic *m_pic07;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic07  = (CStatic*)GetDlgItem(IDC_STATIC7);
	pDC = (*m_pic07).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic07).GetWindowRect(&rect07);

		//get image height and width   
		Width   = (unsigned long) rect07.Width();
		Height  = (unsigned long) rect07.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto8(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect08;
	CStatic *m_pic08;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic08  = (CStatic*)GetDlgItem(IDC_STATIC8);
	pDC = (*m_pic08).GetDC();    //�����ʾ�ؼ���DC;

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic08).GetWindowRect(&rect08);

		//get image height and width   
		Width   = (unsigned long) rect08.Width();
		Height  = (unsigned long) rect08.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto9(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect09;
	CStatic *m_pic09;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic09  = (CStatic*)GetDlgItem(IDC_STATIC9);
	pDC = (*m_pic09).GetDC();    //�����ʾ�ؼ���DC;

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic09).GetWindowRect(&rect09);

		//get image height and width   
		Width   = (unsigned long) rect09.Width();
		Height  = (unsigned long) rect09.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto10(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect10;
	CStatic *m_pic10;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic10  = (CStatic*)GetDlgItem(IDC_STATIC10);
	pDC = (*m_pic10).GetDC();    //�����ʾ�ؼ���DC;

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic10).GetWindowRect(&rect10);

		//get image height and width   
		Width   = (unsigned long) rect10.Width();
		Height  = (unsigned long) rect10.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto11(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect11;
	CStatic *m_pic11;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic11  = (CStatic*)GetDlgItem(IDC_STATIC11);
	pDC = (*m_pic11).GetDC();    //�����ʾ�ؼ���DC;

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic11).GetWindowRect(&rect11);

		//get image height and width   
		Width   = (unsigned long) rect11.Width();
		Height  = (unsigned long) rect11.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowPhoto12(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rect12;
	CStatic *m_pic12;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_pic12  = (CStatic*)GetDlgItem(IDC_STATIC12);
	pDC = (*m_pic12).GetDC();    //�����ʾ�ؼ���DC;

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_pic12).GetWindowRect(&rect12);

		//get image height and width   
		Width   = (unsigned long) rect12.Width();
		Height  = (unsigned long) rect12.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

void CCTestDlg::OnShowQryImg(CString strPhotoName)
{
	long cb;
	unsigned long Width,Height;  
	long hmWidth; 
	long hmHeight; 

	IStream *pStm; 
	CFileStatus fstatus; 
	CFile file; 

	CDC* pDC =NULL;
	IPicture *pPic;
	CRect rectQry;
	CStatic *m_picQry;

	CoInitialize(NULL);

	if (file.Open(strPhotoName,CFile::modeRead)&&file.GetStatus(strPhotoName,fstatus)&& ((cb = fstatus.m_size) != -1)) 
	{    
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);  
		void *  pvData = NULL; 
		if (hGlobal != NULL) 
		{    
			pvData = GlobalLock(hGlobal);
			if (pvData != NULL) 
			{
				file.Read(pvData, cb); 
				GlobalUnlock(hGlobal); 
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 
			}
		}
	}
	else
	{     
		return;  
	}

	//��ʾͼƬ
	m_picQry  = (CStatic*)GetDlgItem(IDC_STATIC13);
	pDC = (*m_picQry).GetDC();    //�����ʾ�ؼ���DC

	if( SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)) )     
	{
		pPic->get_Width(&hmWidth); 
		pPic->get_Height(&hmHeight);    

		//get image position
		//GetDlgItem(IDC_STATIC001)->GetWindowRect(&rect1);
		(*m_picQry).GetWindowRect(&rectQry);

		//get image height and width   
		Width   = (unsigned long) rectQry.Width();
		Height  = (unsigned long) rectQry.Height(); 

		//use render function display image   
		if(FAILED(pPic->Render(*pDC,0,0,(unsigned long)Width,(unsigned long)Height,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		{    
			pPic->Release();    
			return;    
		}   
		pPic->Release();    
	}   
	else    
	{   
		return; 
	}
	CoUninitialize();
	return;  
}

/************************************************************************
// ��ʾÿҳͼ��ĺ���;
// �������������ص�ͼ���Ѿ�������һ��ini�ļ�����;

************************************************************************/

int CCTestDlg::ShowEachPage(int n , int nEachPachNum,int nFlag) //n��ʾ��nҳ,nTotalNum��ʾҪ��ʾ��ͼ�����; 
{

	//int a = 0; 
	int i = 1;
	int j = 1;
	int k = 1;
	CString strName;
	char KeyRowName[50]; // �ڼ��е�������
	char KeyRowImageName[500];// ͼ�������
	CString strImageFullName;
	CString strImageFileName;
	CString strSecImageFileName;

	//if(nTotal<=(n-1)*12)//��֤��Ҫ�����ܵ�ͼ����Ŀ,nTotalΪ�ܵ�ͼ����Ŀ;
	//    {
	//      return  -1;
	//������ж��ڴ˺���֮���ǰ���ж�,Ȼ����øú���;

	UpdateData(1);

	for (k=1;k<=12;k++) // �˲����������ڵ��'��һҳ'ʱ������һҳ�ı�עѡ�в�����һҳ����ʾ;
	{
		m_RadioCancel1 = -1;
		m_RadioCancel2 = -1;
		m_RadioCancel3 = -1;
		m_RadioCancel4 = -1;
		m_RadioCancel5 = -1;
		m_RadioCancel6 = -1;
		m_RadioCancel7 = -1;
		m_RadioCancel8 = -1;
		m_RadioCancel9 = -1;
		m_RadioCancel10 = -1;
		m_RadioCancel11 = -1;
		m_RadioCancel12 = -1;
	}

	for (j=1;j<=12;j++)  // ÿ��ʾ��һҳʱ�������еĿ���ʾ;
	{
		ShowHideWin(0, j);
	}

	strImageFileName.Format("%s",".\\AllImageName\\01_RetImages.txt");



	for (i=1;i<=nEachPachNum;i++)
	{
		memset(KeyRowName,0,sizeof(KeyRowName));
		memset(KeyRowImageName,0,sizeof(KeyRowImageName));

		if (nFlag == 1) //�� SecRetImage�ж�ȡͼ�����ֲ���ʾ;
		{
			sprintf(KeyRowName,"SecRetImage%d",(n-1)*12+i);
			GetPrivateProfileString("SecRetImages",KeyRowName,"Game Over",KeyRowImageName,1000,strSecImageFileName);//.//ImageName.txt
		}
		if (nFlag == 2) //�� RetImage�ж�ȡͼ�����ֲ���ʾ;
		{
			sprintf(KeyRowName,"ReturnImages%d",(n-1)*12+i);
			GetPrivateProfileString("IMAGENAME",KeyRowName,"Game Over",KeyRowImageName,1000,strImageFileName);//.//ImageName.txt
		}

		strImageFullName = "";
		strImageFullName.Format("%s",KeyRowImageName);

		//strImageFullName.Format(".\\AllImages\\%s",KeyRowImageName);
		//strImageFullName.Format(".\\waterfallsImages\\%s",KeyRowImageName);   //����·�����ļ���;
		// MessageBox(strImageFullName,NULL,MB_OK);
		if(i == 1)
		{
			ShowHideWin(1, 1);
			OnShowPhoto1(strImageFullName);// λ��1����ͼ��;
		}
		if(i == 2)
		{
			//GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			ShowHideWin(1, 2);
			OnShowPhoto2(strImageFullName);// λ��2����ͼ��;
		}
		if(i == 3)
		{
			ShowHideWin(1, 3);
			OnShowPhoto3(strImageFullName);// λ��3����ͼ��;
		}
		if(i == 4)
		{
			ShowHideWin(1, 4);
			OnShowPhoto4(strImageFullName);// λ��4����ͼ��;
		}
		if(i == 5)
		{
			ShowHideWin(1, 5);
			OnShowPhoto5(strImageFullName);// λ��5����ͼ��;
		}
		if(i == 6)
		{
			ShowHideWin(1, 6);
			OnShowPhoto6(strImageFullName);// λ��6����ͼ��;
		}
		if(i == 7)
		{
			ShowHideWin(1, 7);
			OnShowPhoto7(strImageFullName);// λ��7����ͼ��;
		}
		if(i == 8)
		{
			ShowHideWin(1, 8);
			OnShowPhoto8(strImageFullName);// λ��8����ͼ��;
		}
		if(i == 9)
		{
			ShowHideWin(1, 9);
			OnShowPhoto9(strImageFullName);// λ��9����ͼ��;
		}
		if(i == 10)
		{
			ShowHideWin(1, 10);
			OnShowPhoto10(strImageFullName);// λ��10����ͼ��;
		}
		if(i == 11)
		{
			ShowHideWin(1, 11);
			OnShowPhoto11(strImageFullName);// λ��11����ͼ��;
		}
		if(i == 12)
		{
			ShowHideWin(1, 12);
			OnShowPhoto12(strImageFullName);// λ��12����ͼ��;
		}

	}
	UpdateData(0);

	return 0;
}

int CCTestDlg::ShowEachPage(int n , int nEachPachNum,int nFlag, CString qryImg) //n��ʾ��nҳ,nTotalNum��ʾҪ��ʾ��ͼ�����; 
{

	//int a = 0; 
	int i = 1;
	int j = 1;
	int k = 1;
	CString strName;
	char KeyRowName[50]; // �ڼ��е�������
	char KeyRowImageName[500];// ͼ�������
	CString strImageFullName;
	CString strImageFileName;
	CString strSecImageFileName;

	//if(nTotal<=(n-1)*12)//��֤��Ҫ�����ܵ�ͼ����Ŀ,nTotalΪ�ܵ�ͼ����Ŀ;
	//    {
	//      return  -1;
	//������ж��ڴ˺���֮���ǰ���ж�,Ȼ����øú���;

	UpdateData(1);

	for (k=1;k<=12;k++) // �˲����������ڵ��'��һҳ'ʱ������һҳ�ı�עѡ�в�����һҳ����ʾ;
	{
		m_RadioCancel1 = -1;
		m_RadioCancel2 = -1;
		m_RadioCancel3 = -1;
		m_RadioCancel4 = -1;
		m_RadioCancel5 = -1;
		m_RadioCancel6 = -1;
		m_RadioCancel7 = -1;
		m_RadioCancel8 = -1;
		m_RadioCancel9 = -1;
		m_RadioCancel10 = -1;
		m_RadioCancel11 = -1;
		m_RadioCancel12 = -1;
	}

	for (j=1;j<=12;j++)  // ÿ��ʾ��һҳʱ�������еĿ���ʾ;
	{
		ShowHideWin(0, j);
	}

	strImageFileName.Format(".\\AllImageName\\%s_RetImages.txt",qryImg);



	for (i=1;i<=nEachPachNum;i++)
	{
		memset(KeyRowName,0,sizeof(KeyRowName));
		memset(KeyRowImageName,0,sizeof(KeyRowImageName));

		if (nFlag == 1) //�� SecRetImage�ж�ȡͼ�����ֲ���ʾ;
		{
			sprintf(KeyRowName,"SecRetImage%d",(n-1)*12+i);
			GetPrivateProfileString("SecRetImages",KeyRowName,"Game Over",KeyRowImageName,1000,strSecImageFileName);//.//ImageName.txt
		}
		if (nFlag == 2) //�� RetImage�ж�ȡͼ�����ֲ���ʾ;
		{
			sprintf(KeyRowName,"ReturnImages%d",(n-1)*12+i);
			GetPrivateProfileString("IMAGENAME",KeyRowName,"Game Over",KeyRowImageName,1000,strImageFileName);//.//ImageName.txt
		}

		strImageFullName = "";
		strImageFullName.Format("%s",KeyRowImageName);

		//strImageFullName.Format(".\\AllImages\\%s",KeyRowImageName);
		//strImageFullName.Format(".\\waterfallsImages\\%s",KeyRowImageName);   //����·�����ļ���;
		// MessageBox(strImageFullName,NULL,MB_OK);
		if(i == 1)
		{
			ShowHideWin(1, 1);

			OnShowPhoto1(strImageFullName);// λ��1����ͼ��;
		}
		if(i == 2)
		{
			//GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);

			ShowHideWin(1, 2);

			OnShowPhoto2(strImageFullName);// λ��2����ͼ��;
		}
		if(i == 3)
		{
			ShowHideWin(1, 3);
			//GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
			OnShowPhoto3(strImageFullName);// λ��3����ͼ��;
		}
		if(i == 4)
		{
			ShowHideWin(1, 4);
			//GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
			OnShowPhoto4(strImageFullName);// λ��4����ͼ��;
		}
		if(i == 5)
		{
			ShowHideWin(1, 5);
			//GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
			OnShowPhoto5(strImageFullName);// λ��5����ͼ��;
		}
		if(i == 6)
		{
			ShowHideWin(1, 6);
			//GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
			OnShowPhoto6(strImageFullName);// λ��6����ͼ��;
		}
		if(i == 7)
		{
			ShowHideWin(1, 7);
			//GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
			OnShowPhoto7(strImageFullName);// λ��7����ͼ��;
		}
		if(i == 8)
		{
			ShowHideWin(1, 8);
			//GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
			OnShowPhoto8(strImageFullName);// λ��8����ͼ��;
		}
		if(i == 9)
		{
			ShowHideWin(1, 9);
			//GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
			OnShowPhoto9(strImageFullName);// λ��9����ͼ��;
		}
		if(i == 10)
		{
			ShowHideWin(1, 10);
			//GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
			OnShowPhoto10(strImageFullName);// λ��10����ͼ��;
		}
		if(i == 11)
		{
			ShowHideWin(1, 11);
			//GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
			OnShowPhoto11(strImageFullName);// λ��11����ͼ��;
		}
		if(i == 12)
		{
			ShowHideWin(11, 12);
			//GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
			OnShowPhoto12(strImageFullName);// λ��12����ͼ��;
		}

	}
	UpdateData(0);

	return 0;
}

/********************************************************************
// �˺����ǽ��м���,������Ҫ���ͼ�񷵻�,Ȼ��ʹ�ú����ڽ�������ʾ.
********************************************************************/
int CCTestDlg::ReturnImageName(CString strQuery)
{
	//CString strQueryTag;
	int nTagsFileIndex; // �������ͼ��λ�ã����ڽ�ͼ�����Ʊ������;
	int nTagNumber;//����������ע�в�ѯ��strQueryTag��ͼ��ĸ���;
	//��������nTagNumber��Ϊ�����ѯ��strQueryTag������ͼ���б���ǵĴ���;
	//CString strTagsFileName;

	CString strKeyReadName;
	CString strKeyReadValue;
	// strKeyImageName  is �����е�ͼ���������ҳ�����strQueryTag��ͼ������,�˴���ͼ�������ǰ���·��,����,C:\\ImageData\\Flickr\\actor\\0001_2124494179.jpg.
	CString strKeyImageName; 
	CString strKeyImageIndex;
	CString strKeyWriteIndex;
	CString strQueryTag;
	CString strSaveImageFile;
	//CString strWriteImageName;
	int nTotalImageNum;
	int nFirstImage;
	//nTotalImageNum = 269648;
	nTotalImageNum = 70000; // ����ͼ��,Ҳ����ͼ����ܸ���;
	nFirstImage = 1; // ��ʼͼ��
	nTagNumber = 70000;

	//DeleteFile(".\\ReturnImages\\ReturnImages.txt"); // �ڼ�����һ������ʱ�ֻ����һ��ini�ļ�,��˽�ǰһ��ɾ��.
	// ��Ҫɾ��,Ҫ�����strQueryRetImages.txt����ʽ;

	//nTagsFileIndex = 269648;// ʹ�õ�ͼ����ܵĸ���;

	//strTagsFileName.Format(".\\tags\\%s.txt",AllImageTags); // ����ͼ���tags������AllImageTags��;
	//strQueryTag.Format(",%s,",strQuery);
	//strSaveImageFile.Format(".\\ReturnImages\\%sRetImages.txt",strQuery);

	strSaveImageFile.Format(".\\AllImageName\\%s_RetImages.txt",qryImg);

	//for(nTagsFileIndex=nFirstImage;nTagsFileIndex++)
	{
		//strKeyReadName = "";  //�ڼ���;
		//strKeyReadValue = "";// �ڼ��е�ֵ,���ڼ��е�ͼ��ı�ǩ;
		//strKeyReadName.Format("TAGS%d",nTagsFileIndex);
		//GetPrivateProfileString("ImageTags",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\AllImageTags\\AllImageTags.txt");
		//      //GetPrivateProfileString("IMAGETAGS",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\waterfallsTags.txt");		

		//if(strKeyReadValue.Find(strQueryTag)!=(-1))	// for example,���� ,beach, ����ʽ������, xxxbeach����ʽ�����ҵ�beach��.
		{
			//// ��Ӵ���,�����б�ǩstrQueryTag��ͼ��������ҳ������ڽ�����ʾ.
			//nTagNumber += 1; // Ҫ���ص�ͼ�����;
			//strKeyImageName = "";
			//strKeyImageIndex = "";
			//strKeyWriteIndex = "";

			////strKeyImageIndex.Format("ImageIndex%d",nTagsFileIndex);
			//strKeyImageIndex.Format("NAME%d",nTagsFileIndex);
			//GetPrivateProfileString("IMAGENAME",strKeyImageIndex,"Game Over",strKeyImageName.GetBuffer(1000),1000,".\\AllImageName\\AllImageName.txt");
			////GetPrivateProfileString("ROW",strKeyImageIndex,"Game Over",strKeyImageName.GetBuffer(1000),1000,".\\waterfallsName.txt");
			//strKeyWriteIndex.Format("ReturnImages%d",nTagNumber);
			//WritePrivateProfileString("ImageName",strKeyWriteIndex,strKeyImageName,strSaveImageFile);
		}
	}

	return nTagNumber;
}

/********************************************************************
// �˺������Խ��м���,������Ҫ���ͼ�񷵻�,Ȼ��ʹ�ú����ڽ�������ʾ;
// Ҳ������ֱ�Ӷ�ȡ�㷨�ļ�������ļ���Ȼ�󷵻ؼ������ͼ��ĸ���;
// ���ַ�ʽ,�û��Լ�ѡ������Լ��ļ��������ӿ�;
********************************************************************/
int CCTestDlg::RetImgsNumber(CString strQuery)
{
	// ֻ��ȡ�������صĽ���ļ�����ʾͼ��;
	
	CString strRetImgsResults;
	CString strKeyReadName;
	CString strKeyReadValue;


	int nTotalImageNum = 0;
	int nFirstImage = 0;
	int nTagsFileIndex = 1;

	//nTotalImageNum = 269648; // ����ͼ��,Ҳ����ͼ����ܸ���;
	
	strRetImgsResults = "";
	strRetImgsResults.Format(".\\AllImageName\\%s_RetImages.txt",strQuery);

	for(nTagsFileIndex=1;;nTagsFileIndex++)
	{
		strKeyReadName = "";  //�ڼ���;
		strKeyReadValue = "";// �ڼ��е�ֵ,���ڼ��е�ͼ��ı�ǩ;
		strKeyReadName.Format("ReturnImages%d",nTagsFileIndex);
		GetPrivateProfileString("IMAGENAME",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,strRetImgsResults);
		//      //GetPrivateProfileString("IMAGETAGS",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\waterfallsTags.txt");		

		// �ж��Ƿ��ļ����λ��;
		if (strKeyReadValue == "Game Over")
		{
			break;
		}
		else
		{
			nTotalImageNum ++;
		}

		
	}

	return nTotalImageNum;

}


/******************************************************************************
// SaveLabel(int n , int nEachPachNum);
// �����û���ͼ����еı�ע;
// n  �����ǽ����ini�ļ���ʱ������Ϊ��Ϊͼ�������indexʹ��,��label110;
// nEachPachNum  ��Ϊѭ������;
******************************************************************************/
int CCTestDlg::SaveLabel(int n , int nEachPachNum)
{
	CString strKeyWriteName;  // ��label110;
	CString strkeyWriteValue; // ���浱ǰҳ��ÿ��ͼ��ı�ע���.
	CString strFileName;


	int i = 0;
	int nLabelResult = -1;  // ��ʼ��Ϊδ��ע,��û��ѡ��"��"Ҳû��ѡ��"��";
	strFileName = "";
	strFileName.Format(".\\NewImageLabels\\%sLabels.txt",strQuery);

	for(i=1;i<=nEachPachNum;i++)  //nEachPachNumΪÿһҳ��ͼ�����;
	{
		strKeyWriteName = "";
		strkeyWriteValue = "";

		if(i == 1)
		{
			nLabelResult = m_RadioCancel1;// λ��1����ͼ��;
		}
		if(i == 2)
		{
			nLabelResult = m_RadioCancel2;// λ��2����ͼ��;
		}
		if(i == 3)
		{
			nLabelResult = m_RadioCancel3;// λ��3����ͼ��;
		}
		if(i == 4)
		{
			nLabelResult = m_RadioCancel4;// λ��4����ͼ��;
		}
		if(i == 5)
		{
			nLabelResult = m_RadioCancel5;// λ��5����ͼ��;
		}
		if(i == 6)
		{
			nLabelResult = m_RadioCancel6;// λ��6����ͼ��;
		}
		if(i == 7)
		{
			nLabelResult = m_RadioCancel7;// λ��7����ͼ��;
		}
		if(i == 8)
		{
			nLabelResult = m_RadioCancel8;// λ��8����ͼ��;
		}
		if(i == 9)
		{
			nLabelResult = m_RadioCancel9;// λ��9����ͼ��;
		}
		if(i == 10)
		{
			nLabelResult = m_RadioCancel10;// λ��10����ͼ��;
		}
		if(i == 11)
		{
			nLabelResult = m_RadioCancel11;// λ��11����ͼ��;
		}
		if(i == 12)
		{
			nLabelResult = m_RadioCancel12;// λ��12����ͼ��;
		}

		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%d",nLabelResult);
		/*
		if(nLabelResult == 1)  // 1 ��ʾѡ�� "��";
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","1 ");    // ������ʾ�е�����;

		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","1");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		else if(nLabelResult == 0)  // 0 ��ʾѡ�� "��";
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","0 ");
		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","0");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		else     // ɶҲûѡ��,û������ע�ı��Ϊ2;
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","2 ");
		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","2");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		*/	
		WritePrivateProfileString("ImageLabels",strKeyWriteName,strkeyWriteValue,strFileName); // �����ڵ�ǰNewImageLabels·����;
	}



	return 0;
}


//�˺����ǽ�12��ͼ����ʾ�����ػ���ʾ,0��ʾ���أ�1��ʾ��ʾ;
void CCTestDlg::ShowHideWin(int nFlag, int a)
{

	if (nFlag==0)  // ������ʾ��;
	{
		if(a = 1)
		{
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
		}
		if(a = 2)
		{
			GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO3)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO4)->ShowWindow(SW_HIDE);
		}
		if(a = 3)
		{
			GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT3)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO5)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO6)->ShowWindow(SW_HIDE);
		}
		if(a = 4)
		{
			GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT4)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO7)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO8)->ShowWindow(SW_HIDE);
		}
		if(a = 5)
		{
			GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT5)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO9)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO10)->ShowWindow(SW_HIDE);
		}
		if(a = 6)
		{
			GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT6)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO11)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO12)->ShowWindow(SW_HIDE);
		}
		if(a = 7)
		{
			GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT7)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO13)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO14)->ShowWindow(SW_HIDE);
		}
		if(a = 8)
		{
			GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT8)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO15)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO16)->ShowWindow(SW_HIDE);
		}
		if(a = 9)
		{
			GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT9)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO17)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO18)->ShowWindow(SW_HIDE);
		}
		if(a = 10)
		{
			GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT10)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO19)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO20)->ShowWindow(SW_HIDE);
		}
		if(a = 11)
		{
			GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT11)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO21)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO22)->ShowWindow(SW_HIDE);
		}

		if(a = 12)
		{
			GetDlgItem(IDC_STATIC12)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RECT12)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO23)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO24)->ShowWindow(SW_HIDE);
		}
	}
	else  //��ʾ��ʾ��;
	{
		if(a = 1)
		{
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
		}
		if(a = 2)
		{
			GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO3)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO4)->ShowWindow(SW_HIDE);
		}
		if(a = 3)
		{
			GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT3)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO5)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO6)->ShowWindow(SW_HIDE);
		}
		if(a = 4)
		{
			GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT4)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO7)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO8)->ShowWindow(SW_HIDE);
		}
		if(a = 5)
		{
			GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT5)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO9)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO10)->ShowWindow(SW_HIDE);

		}
		if(a = 6)
		{
			GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT6)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO11)->ShowWindow(SW_HIDE);
			//GetDlgItem(IDC_RECT517)->ShowWindow(SW_HIDE);
		}
		if(a = 7)
		{
			GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT7)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO13)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO14)->ShowWindow(SW_HIDE);
		}
		if(a = 8)
		{
			GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT8)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO15)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO16)->ShowWindow(SW_HIDE);
		}
		if(a = 9)
		{
			GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT9)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO17)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO18)->ShowWindow(SW_HIDE);
		}
		if(a = 10)
		{
			GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT10)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO19)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO20)->ShowWindow(SW_HIDE);
		}
		if(a = 11)
		{
			GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT11)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO21)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO22)->ShowWindow(SW_HIDE);
		}

		if(a = 12)  
		{
			GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RECT12)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO23)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RADIO24)->ShowWindow(SW_HIDE);
		}
	}


}

void CCTestDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	//nLabel1 = 1;  
	m_RadioCancel1 = 1;// 1 ��ʾ����� "��".
}

void CCTestDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel1 = 0; // 1 ��ʾ����� "��".
}

void CCTestDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel2 = 1;
}

void CCTestDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel2 = 0;
}

void CCTestDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel3 = 1;
}

void CCTestDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel3 = 0;
}

void CCTestDlg::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel4 = 1;
}

void CCTestDlg::OnRadio8() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel4 = 0;
}

void CCTestDlg::OnRadio9() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel5 = 1;
}

void CCTestDlg::OnRadio10() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel5 = 0;
}

void CCTestDlg::OnRadio11() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel6 = 1;
}

void CCTestDlg::OnRadio12() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel6 = 0;
}

void CCTestDlg::OnRadio13() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel7 = 1;
}

void CCTestDlg::OnRadio14() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel7 = 0;
}

void CCTestDlg::OnRadio15() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel8 = 1;
}

void CCTestDlg::OnRadio16() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel8 = 0;
}

void CCTestDlg::OnRadio17() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel9 = 1;
}

void CCTestDlg::OnRadio18() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel9 = 0;
}

void CCTestDlg::OnRadio19() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel10 = 1;
}

void CCTestDlg::OnRadio20() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel10 = 0;
}

void CCTestDlg::OnRadio21() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel11 = 1;
}

void CCTestDlg::OnRadio22() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel11 = 0;
}

void CCTestDlg::OnRadio23() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel12 = 1;
}

void CCTestDlg::OnRadio24() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel12 = 0;
}


void CCTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;

	for (int c=1;c<=12;c++)
	{
		ShowHideWin(0, c);
	}


	CCTestDlg::OnOK();
}

// �������������һ��ͼ����ʾ�������ͼ��ռ���;
void CCTestDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	CString    strOriVideoPath;
	char       szShowPage[20]; // ��ǰҳ
	char       szTotalNum[20]; // ������ҳ,ͼ�����;

	CString szFilters="Data Files (*.*)|*.*|All Files (*.*)|*.*||";
	CFileDialog fileDlg(TRUE,NULL,"*.*",OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,szFilters,this);
	CString filename;
	if (fileDlg.DoModal()==IDOK)
	{
		filename = fileDlg.GetPathName();

		strOriVideoPath.Format("%s",filename);// ȡ����Ƶ��·��+����;

		OnShowQryImg(strOriVideoPath);

		//MessageBox(strOriVideoPath,"OK",0);

		string str(strOriVideoPath.GetBuffer());
		int nFindstart = str.find_last_of('\\');
		int nFindend = str.find(".jpg");
		string strqry = str.substr(nFindstart+1,nFindend-nFindstart-1);

		qryImg.Format("%s",strqry.c_str());

		//MessageBox(qryImg,"OK",0);

		// �����һ�εļ�����ʾ���;
		// ����һ�β�ѯ��ͼ����������;
		sprintf(szTotalNum,"%s"," ");
		GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);
		sprintf(szShowPage,"%s"," ");
		GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		// ������һ�ε�ͼ�����������;
		for (int c=1;c<=12;c++)
		{
			ShowHideWin(0, c);
		}

		UpdateData(0);

	}

}
