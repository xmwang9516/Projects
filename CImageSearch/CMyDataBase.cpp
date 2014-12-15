// CMyDataBase.cpp: implementation of the CCMyDataBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CTest.h"
#include "CMyDataBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCMyDataBase::CCMyDataBase()
{

}

CCMyDataBase::~CCMyDataBase()
{

}

int CCMyDataBase::dbExecute(char *pchSQL, char **ppchReturn)
{
	ReleaseBuffer();
	
	_CommandPtr pCmd;
	_RecordsetPtr pRs = NULL;
	HRESULT hr;
	_variant_t	paramval;
	int  nLen = 0 ;
	int  nRec = 0;
	int n = 1;
	long lCount = 0;
	
	if ( strlen(pchSQL) <= 0 )
		return -1;
	
	try 
	{
		hr = pCmd.CreateInstance(__uuidof(Command));
		if(FAILED(hr))
			throw 0;
		pCmd->ActiveConnection = m_pCon;
		pCmd->CommandType = adCmdText;
		pCmd->CommandText = _bstr_t(pchSQL);
		
		pRs = pCmd->Execute(NULL, NULL, adCmdText);
		
		if (pRs == NULL )
		{
			return -1;
		}
		
		
		if(ppchReturn == NULL)
			return 0;
		
		if((pRs->adoEOF)&&(pRs->BOF))
			return 0;
		
		pRs->MoveFirst();
		
		m_pchOut = (char*)malloc(2048);
		lCount = pRs->Fields->Count;
		
		while(!(pRs->adoEOF))
		{
			for(long i =0l ;i<lCount;i++)
			{
				paramval.Clear();
				paramval = pRs->Fields->GetItem(i)->Value;
				if(paramval.vt != VT_NULL)
					nLen += sprintf(m_pchOut+nLen,"%s",(char*)_bstr_t(paramval));
				m_pchOut[nLen] = '\0';
				nLen++;
				nRec++;
				if(nLen > n*1024)
				{
					n++;
					m_pchOut = (char*)realloc(m_pchOut,1024+n*1024);
				}
			}
			pRs->MoveNext();
		}
		m_pchOut[nLen] = '\0';
	}
	catch (...) 
	{
		return nRec;
	}
	*ppchReturn = m_pchOut;
	
	return nRec;

}

void CCMyDataBase::ReleaseBuffer()
{
	if(m_pchOut!=NULL)
	{
		free(m_pchOut);
		m_pchOut = NULL;
	}
}

int CCMyDataBase::InsertDataBase(CString strEntryTime, CString strName, CString strIDNumber, CString strSex, CString strNation, CString strBirthDay, CString strAddress, char *pPhotoData, int nFileLen)
{
	char pchSQL[516];
	//	_CommandPtr pCmd;
	_RecordsetPtr pRs = NULL;
	//	HRESULT hr;
	_variant_t	paramval;
	
	pRs.CreateInstance(__uuidof(Recordset));
    sprintf(pchSQL,"SELECT * FROM IDCard");
	
	try
	{
		pRs->Open(pchSQL,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		
		pRs->AddNew();
		
		pRs->PutCollect("TimeofReadCard",_variant_t(strEntryTime));//读卡时间
		
        pRs->PutCollect("name",_variant_t(strName));		
        
		pRs->PutCollect("idnumber",_variant_t(strIDNumber));
		
		pRs->PutCollect("sex",_variant_t(strSex));
		
		pRs->PutCollect("nation",_variant_t(strNation));
		
		pRs->PutCollect("birthday",_variant_t(strBirthDay));
		
		pRs->PutCollect("address",_variant_t(strAddress));
		
		VARIANT pvList;
		//SetPictureToVariant(pvList,(unsigned char *)pPhotoData,nFileLen);    //m_pBMPBuffer,是LoadShowBMPFile得到的;
		
		pRs->Fields->Item["PhotoInfo"]->AppendChunk(pvList);        //BMP图像文件
        pRs->Update();
	}
	catch (...) 
	{
		return 1;
	}
	
	//DisconnectDatabase();
	
	return 0; 

	return 0;
}
