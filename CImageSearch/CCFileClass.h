#include "stdafx.h"
#include "stdlib.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h> 
#include <io.h>   

using namespace std;

/*****************************************************************************
    Class definition
*****************************************************************************/

class  CCFileClass
{
    public:
	   void      getFileName(string path,int layer,vector<string>& filename);
	   void      delFile(vector<string> delfilename);
	   int       createDirectory(string path);
	   void      readFileData(string inputPath,vector<string>& value);
	   void      writeFileData(string outputPath,vector<string> value);
	   // �����ļ�;
	   bool      copyFile(string srcPath, string desPath,bool tf);
	   // �����ļ�;
	   bool  CCFileClass::moveFile(string srcPath, string desPath);


};






