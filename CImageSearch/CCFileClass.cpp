#include "stdafx.h"
#include "CCFileClass.h"






/*****************************************************************************
     function definition
*****************************************************************************/

// get files name list given the path;
// path like, F:\\DataSet\\retrievalResuts_videos_ranking;
void   CCFileClass::getFileName(string path,int layer,vector<string>&  filename)
{
	int                  nFileNum = 0;   //指示要查找的file个数;
	struct _finddata_t   filefind;   
	string               curr = path + "\\*.*";   
	int                  done = 0;
	int                  handle = 0;   

	if((handle=_findfirst(curr.c_str(),&filefind))==-1)
		return; 

	while(!(done=_findnext(handle,&filefind)))   
	{   
		if(!strcmp(filefind.name,".."))
		{
			continue;
		}
		if((_A_SUBDIR==filefind.attrib))   // 是目录;
		{           
			if (layer !=0)
			{
				curr = path + "\\" + filefind.name; 

				getFileName(curr,layer+1,filename);
			}
			
		}   
		else     // 不是目录,是文件;
		{   
			if (layer != 1)
			{
				nFileNum = filename.size() + 1;

				filename.resize(nFileNum);

				filename[nFileNum-1] = path + "\\" + filefind.name;
			}
			
		}   
	}           
	_findclose(handle);      
}



// delete files given the path;
void  CCFileClass::delFile(vector<string> delfilename)
{
	for (int i=0;i<delfilename.size();i++)
	{	
		DeleteFile(delfilename[i].c_str());
	}
}

//  new a file;
int   CCFileClass::createDirectory(string path)
{
	int nRet = 0;

	nRet = CreateDirectory(path.c_str(),NULL);

	return nRet;
}

void  CCFileClass::readFileData(string inputPath,vector<string>& value)
{
	char szLine[10000]; // large enough;

	ifstream  finename(inputPath.c_str());
	
	while (!finename.eof())
	{
		memset(szLine,0,sizeof(szLine));
		
		finename.getline(szLine,sizeof(szLine));

		if (strcmp(szLine,"") != 0)
		{
			value.push_back(szLine);
		}
		/*else
		{
			value.push_back("No Message");
		}*/
	}

	finename.close();
}

void  CCFileClass::writeFileData(string outputPath,vector<string> value)
{
	char szLine[10000]; // large enough;

	ofstream  finename(outputPath.c_str());

	for (int i=0;i<value.size();i++)
	{
		if (i == value.size()-1)
		{
			finename << value[i] ;
		}
		else
		{
			finename << value[i] << "\n";
		}
		
	}

	finename.close();
}

// tf = false, 覆盖已有的文件;
bool  CCFileClass::copyFile(string srcPath, string desPath,bool tf)
{
	CopyFile(srcPath.c_str(),desPath.c_str(),tf);

	return  true;
}

// 剪切文件;
bool  CCFileClass::moveFile(string srcPath, string desPath)
{
	MoveFile(srcPath.c_str(),desPath.c_str());
	
	return true;
}