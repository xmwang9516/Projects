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

	// 初始化为-1,表示图像都没有被标记,当作标记时,m_RadioCancel就会发生变化;

	m_RadioCancel1 = -1;  // 位置1处de标记;
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
	// 添加初始化;
	nPageNo = 0;  // 初始化nPageNo为0,用来变化指示上一页或下一页;
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

	showDefaultFlag = 1; // 初始值设为0;

	

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



//每12幅图像作为一个循环来分页,事先通过程序得到图像数目,然后直接确定可以分几页;
void CCTestDlg::OnButtonPre()  // 上一页;
{
	/***********************************************************************************
	// TODO: Add your control notification handler code here
	//OnShowPhoto1(".//ZP.bmp"); //位置1的照片;
	//OnShowPhoto2(".//22.bmp"); //位置2的照片;
	// 点击"上一页"时也要保存当前页的标注结果到一个暂时结果保存数组;
	//  
	***********************************************************************************/
	//UpdateData(1);

	char szLabelResults[30];  //1 1 -1 1 -1  这样含有空格的读写格式,保存当前页的图像标注结果.
	char szShowPage[30];

	CString strReadIndex = "";
	CString strReadValue = "";
	CString strLabelsFile = "";
	int i = 0;
	int j = 0;

	memset(szLabelResults,0,sizeof(szLabelResults));
	memset(szShowPage,0,sizeof(szShowPage));

	////// 下面是显示当前页码的代码;////////////////////////////////////////
	if (nPageNo > 0)
	{
		if (nPageNo==1)
		{
			//ShowEachPage(nPageNo,12);  // 如果是第一页,则显示第一页的图像个数;
			sprintf(szShowPage,"%s","当前已为第1页");
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
		else
		{
			nPageNo -= 1; // 当前面标注结果保存后再将页码加1,显示下一页; 
			ShowEachPage(nPageNo,12, haveTopicName);
			sprintf(szShowPage,"%d/%d 页",nPageNo,(nTotalReturn/12+1));
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
	}

	////////////////////////////////////////////////////////////////////////	
}

void CCTestDlg::OnButtonNext() // 下一页; 
{
	// TODO: Add your control notification handler code here
	/******************************************************************************************
	//在此函数中处理标签结果,当点击“下一页”时，上一页的标注结果暂时保存在一个数组中
	//待所有图像都标注完之后再将结果保存在一个文件中.
	//当点击"上一页"时，当前页的标注结果不能不处理，同样暂时保存在一个这个数组中?
	//数组中保存结果时按照每页12个来增加，没有标注操作的图像赋予初始化的0值.
	//点击"上一页"时,要将上一页的标注结果显示出来,每点击以此"上一页",依次将每页的标注结果显示出来.
	//此函数中还要考虑返回的最后一页的图像小于12的情况;

	// 
	*******************************************************************************************/
	// UpdateData(1);

	char szShowPage[30];
	memset(szShowPage,0,sizeof(szShowPage));

	if (nPageNo > 0)
	{
		if(nPageNo == (nTotalReturn/12+1)) // 最后一页的判断条件;
			//if (nPageNo==12)  // 验证程序暂以12为例;
		{
			//ShowEachPage(nPageNo,nTotalReturn-(nPageNo-1)*12);  // 如果最后一页,由于else中已经显示了这一页的图像,所以就不要显示了;
			SaveLabel(nPageNo , nTotalReturn-(nPageNo-1)*12);
			sprintf(szShowPage,"%s","当前已为最后页");
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		}
		else
		{	
			SaveLabel(nPageNo , 12);
			nPageNo += 1; // 当前面标注结果保存后再将页码加1,显示下一页; 	
			sprintf(szShowPage,"%d/%d 页",nPageNo,(nTotalReturn/12+1));
			GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
			ShowEachPage(nPageNo,12,haveTopicName);  // 显示每页的图像个数;
		}
	}

}

void CCTestDlg::OnOK() // 确定,然后对含有相应标签的图像进行查找,首先显示前12副图像;
{
	// TODO: Add extra validation here
	/***************************************************************************************
	// 此处进行具体的操作，简单的是对图像标签与查询词进行匹配,返回图像对图像进行标注.
	// 返回图像以每页12副进行显示.
	// 如果要对图像进行检索或者标注工作,就可以在此处或者另写一个函数调用进行处理.
	// 计算得到要返回的图像的总个数;
	// 调用函数ShowEachPage(int n , int nEachPachNum);
	// 获取用户输入查询词strQuery;

	//
	***************************************************************************************/

	UpdateData(1);


	char szShowPage[20]; // 当前页
	char szTotalNum[20]; // 共多少页,图像个数;
	CString strKeyReadIndex = "";
	CString strKeyReadTopic = "";
	CString strFindQuery = "";
	CString strLabelsFile = "";
	CString strRetImageFile = "";
	CString strTotalNum = "";
	CString strFileLabel = "";
	//char str[100];//定义常数，目的是为了读取足够长的行
	int iTotalTopic;
	int i = 0;
	int n = 0;
	int j = 0;


	memset(szShowPage,0,sizeof(szShowPage));
	memset(szTotalNum,0,sizeof(szTotalNum));

	//CString strQuery;
	strQuery = "";

	GetDlgItemText(IDC_EDIT_TOPIC,strQuery); // 获取用户输入查询词strQuery;


	haveTopicName = 2;

	if (haveTopicName == 1)
	{
		//DeleteFile(".\\ReturnImages\\SecRetImages.txt"); // 在检索下一个概念时又会产生一个ini文件,因此将前一个删掉.
		//// 添加有概念词但是有的图像没有被标注的图像返回显示并标注的代码;
		//         //MessageBox("TopicName中有此概念",NULL,MB_OK);
		//strLabelsFile.Format(".\\NewImageLabels\\%sLabels.txt",strQuery); // 若此概念词已有,则找到这个概念词的所有图像的标记结果文件;
		//strKeyReadIndex = "";
		//         strKeyReadTopic = "";
		//strKeyReadIndex.Format("%s","TotalNum");
		//         GetPrivateProfileString("ImageLabels",strKeyReadIndex,"-1",strKeyReadTopic.GetBuffer(500),500,strFileLabel);
		//   n = atoi(strKeyReadTopic); // 获得满足要求的返回的图像的个数;
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
		//		strKeyReadIndex.Format("ReturnImages%d",j); //找出对应的未被标记的图像,从ReturnImages中;
		//		GetPrivateProfileString("ImageName",strKeyReadIndex,0,strKeyReadTopic.GetBuffer(500),500,strRetImageFile);
		//		strKeyReadIndex = "";
		//		strKeyReadIndex.Format("SecRetImage%d",iTotalTopic); // 将没有被标记的图像暂时保存在另一个ini文件中:
		//                 WritePrivateProfileString("SecRetImages",strKeyReadIndex,strKeyReadTopic,".\\ReturnImages\\SecRetImages.txt");
		//             }
		//}

		// 上面是将未标记的图像保存在一个ini中,个数为iTotalTopic-1;

		//nTotalReturn = iTotalTopic; // 将满足条件的图像返回保存在一个ini文件中;

		//if (nTotalReturn > 0)
		//{
		//	nPageNo = 1; //当搜索结束时,将nPageNo赋值为1,表示显示第一页;
		//	if(nTotalReturn <= 12)  // 返回的图像小于12副的情况;
		//	{
		//		ShowEachPage(nPageNo,nTotalReturn,haveTopicName); // 第二个参数表示每页显示的图像个数,因为最后一页图像可能不够12副;
		//	}
		//	else     // 图像页数大于12的情况;
		//	{
		//		ShowEachPage(nPageNo,12,haveTopicName);  //图像页数大于12副的情况时;
		//	}		
		//	sprintf(szTotalNum,"共%d幅图像",nTotalReturn);
		//	GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);		
		//	sprintf(szShowPage,"%d/%d 页",nPageNo,(nTotalReturn/12+1));
		//    GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);				
		//}
	}else if(haveTopicName ==2)
	{	
		//nTotalReturn = ReturnImageName(qryImg); // 将满足条件的图像返回保存在一个ini文件中;

		nTotalReturn = RetImgsNumber(qryImg); // 返回结果图像文件个数;

		if (nTotalReturn > 0) // 返回图像总个数 要大于0,否则不予操作;
		{
			nPageNo = 1; //当搜索结束时,将nPageNo赋值为1,表示显示第一页;
			
			strKeyReadIndex = "";
			strKeyReadTopic = "";
		

			strKeyReadIndex = "";
			strKeyReadTopic = "";
			strLabelsFile = "";
		
			//nTotalReturn = 224;
			if(nTotalReturn <= 12)  // 返回的图像小于12副的情况;
			{
				//ShowEachPage(nPageNo,nTotalReturn,haveTopicName); // 第二个参数表示每页显示的图像个数,因为最后一页图像可能不够12副;
				ShowEachPage(nPageNo,nTotalReturn,haveTopicName,qryImg);
			}
			else      // 图像页数大于1的情况;
			{
				//ShowEachPage(nPageNo,12,haveTopicName);  //图像页数大于12副的情况时;
				ShowEachPage(nPageNo,12,haveTopicName,qryImg);
			}

			sprintf(szTotalNum,"共%d幅图像",nTotalReturn);
			GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);
			sprintf(szShowPage,"%d/%d 页",nPageNo,(nTotalReturn/12+1));
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

void CCTestDlg::OnShowPhoto1(CString strPhotoName)  // 显示图像函数,每页显示时调用这个函数;
{
	/**************************************************************************************************************  
	HBITMAP bmp = (HBITMAP)::LoadImage(0,  strPhotoName,IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR|LR_LOADFROMFILE);
	m_cphoto1.SetBitmap(bmp);   // 此处是显示bmp图像,但是要返回的图像都是jpg的;
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

	//显示图片
	m_pic01  = (CStatic*)GetDlgItem(IDC_STATIC1);
	pDC = (*m_pic01).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic02  = (CStatic*)GetDlgItem(IDC_STATIC2);
	pDC = (*m_pic02).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic03  = (CStatic*)GetDlgItem(IDC_STATIC3);
	pDC = (*m_pic03).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic04  = (CStatic*)GetDlgItem(IDC_STATIC4);
	pDC = (*m_pic04).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic05  = (CStatic*)GetDlgItem(IDC_STATIC5);
	pDC = (*m_pic05).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic06  = (CStatic*)GetDlgItem(IDC_STATIC6);
	pDC = (*m_pic06).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic07  = (CStatic*)GetDlgItem(IDC_STATIC7);
	pDC = (*m_pic07).GetDC();    //获得显示控件的DC

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

	//显示图片
	m_pic08  = (CStatic*)GetDlgItem(IDC_STATIC8);
	pDC = (*m_pic08).GetDC();    //获得显示控件的DC;

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

	//显示图片
	m_pic09  = (CStatic*)GetDlgItem(IDC_STATIC9);
	pDC = (*m_pic09).GetDC();    //获得显示控件的DC;

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

	//显示图片
	m_pic10  = (CStatic*)GetDlgItem(IDC_STATIC10);
	pDC = (*m_pic10).GetDC();    //获得显示控件的DC;

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

	//显示图片
	m_pic11  = (CStatic*)GetDlgItem(IDC_STATIC11);
	pDC = (*m_pic11).GetDC();    //获得显示控件的DC;

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

	//显示图片
	m_pic12  = (CStatic*)GetDlgItem(IDC_STATIC12);
	pDC = (*m_pic12).GetDC();    //获得显示控件的DC;

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

	//显示图片
	m_picQry  = (CStatic*)GetDlgItem(IDC_STATIC13);
	pDC = (*m_picQry).GetDC();    //获得显示控件的DC

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
// 显示每页图像的函数;
// 假设检索结果返回的图像已经保存在一个ini文件中了;

************************************************************************/

int CCTestDlg::ShowEachPage(int n , int nEachPachNum,int nFlag) //n表示第n页,nTotalNum表示要显示的图像个数; 
{

	//int a = 0; 
	int i = 1;
	int j = 1;
	int k = 1;
	CString strName;
	char KeyRowName[50]; // 第几行的行名称
	char KeyRowImageName[500];// 图像的名称
	CString strImageFullName;
	CString strImageFileName;
	CString strSecImageFileName;

	//if(nTotal<=(n-1)*12)//保证不要大于总的图像数目,nTotal为总的图像数目;
	//    {
	//      return  -1;
	//上面的判断在此函数之外的前面判断,然后调用该函数;

	UpdateData(1);

	for (k=1;k<=12;k++) // 此部分作用是在点击'下一页'时，将上一页的标注选中不在下一页上显示;
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

	for (j=1;j<=12;j++)  // 每显示下一页时，将所有的框不显示;
	{
		ShowHideWin(0, j);
	}

	strImageFileName.Format("%s",".\\AllImageName\\01_RetImages.txt");



	for (i=1;i<=nEachPachNum;i++)
	{
		memset(KeyRowName,0,sizeof(KeyRowName));
		memset(KeyRowImageName,0,sizeof(KeyRowImageName));

		if (nFlag == 1) //从 SecRetImage中读取图像名字并显示;
		{
			sprintf(KeyRowName,"SecRetImage%d",(n-1)*12+i);
			GetPrivateProfileString("SecRetImages",KeyRowName,"Game Over",KeyRowImageName,1000,strSecImageFileName);//.//ImageName.txt
		}
		if (nFlag == 2) //从 RetImage中读取图像名字并显示;
		{
			sprintf(KeyRowName,"ReturnImages%d",(n-1)*12+i);
			GetPrivateProfileString("IMAGENAME",KeyRowName,"Game Over",KeyRowImageName,1000,strImageFileName);//.//ImageName.txt
		}

		strImageFullName = "";
		strImageFullName.Format("%s",KeyRowImageName);

		//strImageFullName.Format(".\\AllImages\\%s",KeyRowImageName);
		//strImageFullName.Format(".\\waterfallsImages\\%s",KeyRowImageName);   //包含路径的文件名;
		// MessageBox(strImageFullName,NULL,MB_OK);
		if(i == 1)
		{
			ShowHideWin(1, 1);
			OnShowPhoto1(strImageFullName);// 位置1处得图像;
		}
		if(i == 2)
		{
			//GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			ShowHideWin(1, 2);
			OnShowPhoto2(strImageFullName);// 位置2处得图像;
		}
		if(i == 3)
		{
			ShowHideWin(1, 3);
			OnShowPhoto3(strImageFullName);// 位置3处得图像;
		}
		if(i == 4)
		{
			ShowHideWin(1, 4);
			OnShowPhoto4(strImageFullName);// 位置4处得图像;
		}
		if(i == 5)
		{
			ShowHideWin(1, 5);
			OnShowPhoto5(strImageFullName);// 位置5处得图像;
		}
		if(i == 6)
		{
			ShowHideWin(1, 6);
			OnShowPhoto6(strImageFullName);// 位置6处得图像;
		}
		if(i == 7)
		{
			ShowHideWin(1, 7);
			OnShowPhoto7(strImageFullName);// 位置7处得图像;
		}
		if(i == 8)
		{
			ShowHideWin(1, 8);
			OnShowPhoto8(strImageFullName);// 位置8处得图像;
		}
		if(i == 9)
		{
			ShowHideWin(1, 9);
			OnShowPhoto9(strImageFullName);// 位置9处得图像;
		}
		if(i == 10)
		{
			ShowHideWin(1, 10);
			OnShowPhoto10(strImageFullName);// 位置10处得图像;
		}
		if(i == 11)
		{
			ShowHideWin(1, 11);
			OnShowPhoto11(strImageFullName);// 位置11处得图像;
		}
		if(i == 12)
		{
			ShowHideWin(1, 12);
			OnShowPhoto12(strImageFullName);// 位置12处得图像;
		}

	}
	UpdateData(0);

	return 0;
}

int CCTestDlg::ShowEachPage(int n , int nEachPachNum,int nFlag, CString qryImg) //n表示第n页,nTotalNum表示要显示的图像个数; 
{

	//int a = 0; 
	int i = 1;
	int j = 1;
	int k = 1;
	CString strName;
	char KeyRowName[50]; // 第几行的行名称
	char KeyRowImageName[500];// 图像的名称
	CString strImageFullName;
	CString strImageFileName;
	CString strSecImageFileName;

	//if(nTotal<=(n-1)*12)//保证不要大于总的图像数目,nTotal为总的图像数目;
	//    {
	//      return  -1;
	//上面的判断在此函数之外的前面判断,然后调用该函数;

	UpdateData(1);

	for (k=1;k<=12;k++) // 此部分作用是在点击'下一页'时，将上一页的标注选中不在下一页上显示;
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

	for (j=1;j<=12;j++)  // 每显示下一页时，将所有的框不显示;
	{
		ShowHideWin(0, j);
	}

	strImageFileName.Format(".\\AllImageName\\%s_RetImages.txt",qryImg);



	for (i=1;i<=nEachPachNum;i++)
	{
		memset(KeyRowName,0,sizeof(KeyRowName));
		memset(KeyRowImageName,0,sizeof(KeyRowImageName));

		if (nFlag == 1) //从 SecRetImage中读取图像名字并显示;
		{
			sprintf(KeyRowName,"SecRetImage%d",(n-1)*12+i);
			GetPrivateProfileString("SecRetImages",KeyRowName,"Game Over",KeyRowImageName,1000,strSecImageFileName);//.//ImageName.txt
		}
		if (nFlag == 2) //从 RetImage中读取图像名字并显示;
		{
			sprintf(KeyRowName,"ReturnImages%d",(n-1)*12+i);
			GetPrivateProfileString("IMAGENAME",KeyRowName,"Game Over",KeyRowImageName,1000,strImageFileName);//.//ImageName.txt
		}

		strImageFullName = "";
		strImageFullName.Format("%s",KeyRowImageName);

		//strImageFullName.Format(".\\AllImages\\%s",KeyRowImageName);
		//strImageFullName.Format(".\\waterfallsImages\\%s",KeyRowImageName);   //包含路径的文件名;
		// MessageBox(strImageFullName,NULL,MB_OK);
		if(i == 1)
		{
			ShowHideWin(1, 1);

			OnShowPhoto1(strImageFullName);// 位置1处得图像;
		}
		if(i == 2)
		{
			//GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);

			ShowHideWin(1, 2);

			OnShowPhoto2(strImageFullName);// 位置2处得图像;
		}
		if(i == 3)
		{
			ShowHideWin(1, 3);
			//GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
			OnShowPhoto3(strImageFullName);// 位置3处得图像;
		}
		if(i == 4)
		{
			ShowHideWin(1, 4);
			//GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
			OnShowPhoto4(strImageFullName);// 位置4处得图像;
		}
		if(i == 5)
		{
			ShowHideWin(1, 5);
			//GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
			OnShowPhoto5(strImageFullName);// 位置5处得图像;
		}
		if(i == 6)
		{
			ShowHideWin(1, 6);
			//GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
			OnShowPhoto6(strImageFullName);// 位置6处得图像;
		}
		if(i == 7)
		{
			ShowHideWin(1, 7);
			//GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
			OnShowPhoto7(strImageFullName);// 位置7处得图像;
		}
		if(i == 8)
		{
			ShowHideWin(1, 8);
			//GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
			OnShowPhoto8(strImageFullName);// 位置8处得图像;
		}
		if(i == 9)
		{
			ShowHideWin(1, 9);
			//GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
			OnShowPhoto9(strImageFullName);// 位置9处得图像;
		}
		if(i == 10)
		{
			ShowHideWin(1, 10);
			//GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
			OnShowPhoto10(strImageFullName);// 位置10处得图像;
		}
		if(i == 11)
		{
			ShowHideWin(1, 11);
			//GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
			OnShowPhoto11(strImageFullName);// 位置11处得图像;
		}
		if(i == 12)
		{
			ShowHideWin(11, 12);
			//GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
			OnShowPhoto12(strImageFullName);// 位置12处得图像;
		}

	}
	UpdateData(0);

	return 0;
}

/********************************************************************
// 此函数是进行检索,将满足要求的图像返回,然后使用函数在界面上显示.
********************************************************************/
int CCTestDlg::ReturnImageName(CString strQuery)
{
	//CString strQueryTag;
	int nTagsFileIndex; // 用来标记图像位置，便于将图像名称保存出来;
	int nTagNumber;//用来计数标注有查询词strQueryTag的图像的个数;
	//最后输出的nTagNumber即为这个查询词strQueryTag在所有图像中被标记的次数;
	//CString strTagsFileName;

	CString strKeyReadName;
	CString strKeyReadValue;
	// strKeyImageName  is 从所有的图像名称中找出标有strQueryTag的图像名称,此处的图像名称是包含路径,比如,C:\\ImageData\\Flickr\\actor\\0001_2124494179.jpg.
	CString strKeyImageName; 
	CString strKeyImageIndex;
	CString strKeyWriteIndex;
	CString strQueryTag;
	CString strSaveImageFile;
	//CString strWriteImageName;
	int nTotalImageNum;
	int nFirstImage;
	//nTotalImageNum = 269648;
	nTotalImageNum = 70000; // 最后的图像,也就是图像的总个数;
	nFirstImage = 1; // 开始图像
	nTagNumber = 70000;

	//DeleteFile(".\\ReturnImages\\ReturnImages.txt"); // 在检索下一个概念时又会产生一个ini文件,因此将前一个删掉.
	// 不要删掉,要保存成strQueryRetImages.txt的形式;

	//nTagsFileIndex = 269648;// 使用的图像的总的个数;

	//strTagsFileName.Format(".\\tags\\%s.txt",AllImageTags); // 所有图像的tags保存在AllImageTags中;
	//strQueryTag.Format(",%s,",strQuery);
	//strSaveImageFile.Format(".\\ReturnImages\\%sRetImages.txt",strQuery);

	strSaveImageFile.Format(".\\AllImageName\\%s_RetImages.txt",qryImg);

	//for(nTagsFileIndex=nFirstImage;nTagsFileIndex++)
	{
		//strKeyReadName = "";  //第几行;
		//strKeyReadValue = "";// 第几行的值,即第几行的图像的标签;
		//strKeyReadName.Format("TAGS%d",nTagsFileIndex);
		//GetPrivateProfileString("ImageTags",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\AllImageTags\\AllImageTags.txt");
		//      //GetPrivateProfileString("IMAGETAGS",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\waterfallsTags.txt");		

		//if(strKeyReadValue.Find(strQueryTag)!=(-1))	// for example,查找 ,beach, 的形式，否则, xxxbeach的形式就算找到beach了.
		{
			//// 添加代码,将含有标签strQueryTag的图像的名字找出来用于界面显示.
			//nTagNumber += 1; // 要返回的图像个数;
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
// 此函数可以进行检索,将满足要求的图像返回,然后使用函数在界面上显示;
// 也可以是直接读取算法的检索结果文件，然后返回检索结果图像的个数;
// 两种方式,用户自己选择并添加自己的检索函数接口;
********************************************************************/
int CCTestDlg::RetImgsNumber(CString strQuery)
{
	// 只读取检索返回的结果文件来显示图像;
	
	CString strRetImgsResults;
	CString strKeyReadName;
	CString strKeyReadValue;


	int nTotalImageNum = 0;
	int nFirstImage = 0;
	int nTagsFileIndex = 1;

	//nTotalImageNum = 269648; // 最后的图像,也就是图像的总个数;
	
	strRetImgsResults = "";
	strRetImgsResults.Format(".\\AllImageName\\%s_RetImages.txt",strQuery);

	for(nTagsFileIndex=1;;nTagsFileIndex++)
	{
		strKeyReadName = "";  //第几行;
		strKeyReadValue = "";// 第几行的值,即第几行的图像的标签;
		strKeyReadName.Format("ReturnImages%d",nTagsFileIndex);
		GetPrivateProfileString("IMAGENAME",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,strRetImgsResults);
		//      //GetPrivateProfileString("IMAGETAGS",strKeyReadName,"Game Over",strKeyReadValue.GetBuffer(10000),10000,".\\waterfallsTags.txt");		

		// 判断是否到文件最后位置;
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
// 保存用户对图像进行的标注;
// n  保存标记结果到ini文件中时用来作为作为图像的行数index使用,如label110;
// nEachPachNum  作为循环条件;
******************************************************************************/
int CCTestDlg::SaveLabel(int n , int nEachPachNum)
{
	CString strKeyWriteName;  // 如label110;
	CString strkeyWriteValue; // 保存当前页的每幅图像的标注结果.
	CString strFileName;


	int i = 0;
	int nLabelResult = -1;  // 初始化为未标注,既没有选择"是"也没有选择"否";
	strFileName = "";
	strFileName.Format(".\\NewImageLabels\\%sLabels.txt",strQuery);

	for(i=1;i<=nEachPachNum;i++)  //nEachPachNum为每一页的图像个数;
	{
		strKeyWriteName = "";
		strkeyWriteValue = "";

		if(i == 1)
		{
			nLabelResult = m_RadioCancel1;// 位置1处得图像;
		}
		if(i == 2)
		{
			nLabelResult = m_RadioCancel2;// 位置2处得图像;
		}
		if(i == 3)
		{
			nLabelResult = m_RadioCancel3;// 位置3处得图像;
		}
		if(i == 4)
		{
			nLabelResult = m_RadioCancel4;// 位置4处得图像;
		}
		if(i == 5)
		{
			nLabelResult = m_RadioCancel5;// 位置5处得图像;
		}
		if(i == 6)
		{
			nLabelResult = m_RadioCancel6;// 位置6处得图像;
		}
		if(i == 7)
		{
			nLabelResult = m_RadioCancel7;// 位置7处得图像;
		}
		if(i == 8)
		{
			nLabelResult = m_RadioCancel8;// 位置8处得图像;
		}
		if(i == 9)
		{
			nLabelResult = m_RadioCancel9;// 位置9处得图像;
		}
		if(i == 10)
		{
			nLabelResult = m_RadioCancel10;// 位置10处得图像;
		}
		if(i == 11)
		{
			nLabelResult = m_RadioCancel11;// 位置11处得图像;
		}
		if(i == 12)
		{
			nLabelResult = m_RadioCancel12;// 位置12处得图像;
		}

		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%d",nLabelResult);
		/*
		if(nLabelResult == 1)  // 1 表示选中 "是";
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","1 ");    // 这样表示有点问题;

		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","1");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		else if(nLabelResult == 0)  // 0 表示选中 "否";
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","0 ");
		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","0");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		else     // 啥也没选中,没有做标注的标记为2;
		{
		//sprintf(szLabelResults + (i-1)*2,"%s","2 ");
		strKeyWriteName.Format("labels%d",(n-1)*12+i);
		strkeyWriteValue.Format("%s","2");
		//MessageBox(strkeyWriteValue,NULL,MB_OK);
		}
		*/	
		WritePrivateProfileString("ImageLabels",strKeyWriteName,strkeyWriteValue,strFileName); // 保存在当前NewImageLabels路径下;
	}



	return 0;
}


//此函数是将12个图像显示框隐藏或显示,0表示隐藏，1表示显示;
void CCTestDlg::ShowHideWin(int nFlag, int a)
{

	if (nFlag==0)  // 隐藏显示框;
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
	else  //显示显示框;
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
	m_RadioCancel1 = 1;// 1 表示被标记 "是".
}

void CCTestDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_RadioCancel1 = 0; // 1 表示被标记 "否".
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
	// TODO: 在此添加控件通知处理程序代码;

	for (int c=1;c<=12;c++)
	{
		ShowHideWin(0, c);
	}


	CCTestDlg::OnOK();
}

// 点击这个函数添加一个图像并显示在上面的图像空间中;
void CCTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码;
	CString    strOriVideoPath;
	char       szShowPage[20]; // 当前页
	char       szTotalNum[20]; // 共多少页,图像个数;

	CString szFilters="Data Files (*.*)|*.*|All Files (*.*)|*.*||";
	CFileDialog fileDlg(TRUE,NULL,"*.*",OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,szFilters,this);
	CString filename;
	if (fileDlg.DoModal()==IDOK)
	{
		filename = fileDlg.GetPathName();

		strOriVideoPath.Format("%s",filename);// 取得视频的路径+名字;

		OnShowQryImg(strOriVideoPath);

		//MessageBox(strOriVideoPath,"OK",0);

		string str(strOriVideoPath.GetBuffer());
		int nFindstart = str.find_last_of('\\');
		int nFindend = str.find(".jpg");
		string strqry = str.substr(nFindstart+1,nFindend-nFindstart-1);

		qryImg.Format("%s",strqry.c_str());

		//MessageBox(qryImg,"OK",0);

		// 清除上一次的检索显示结果;
		// 将上一次查询的图像个数等清空;
		sprintf(szTotalNum,"%s"," ");
		GetDlgItem(IDC_SHOW_TOTALNUM)->SetWindowText(szTotalNum);
		sprintf(szShowPage,"%s"," ");
		GetDlgItem(IDC_SHOW_PAGE)->SetWindowText(szShowPage);
		// 并将上一次的图像检索结果清空;
		for (int c=1;c<=12;c++)
		{
			ShowHideWin(0, c);
		}

		UpdateData(0);

	}

}
