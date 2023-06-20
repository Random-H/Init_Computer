#include "windows.h"
#include "../inc/env.h"
#include <tchar.h>
#include <fstream>//文件读写头文件

int addEnvPath(char *path, string word,string envValue) {

    HKEY hKey;
    LSTATUS result = RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T(path),
     0, KEY_QUERY_VALUE|KEY_READ|KEY_WRITE, &hKey);
    if (result != ERROR_SUCCESS) {
        cerr << "Error opening registry key." << endl;
        return 1;
    }
    char szValue[2048] = {0};
	DWORD dwSize = sizeof(szValue);
	DWORD dwType = REG_SZ;
	if (RegQueryValueEx(hKey,_T(word.c_str()), 0, &dwType, (LPBYTE)&szValue, &dwSize) != ERROR_SUCCESS)
	{	

	}
    
    string old_str = szValue;
    if(old_str.find(envValue)!=string::npos)
    {
        cout<<"变量"<<envValue<<"已存在"<<endl;
        return 2;
    }
    string new_str = old_str +";"+envValue;

    string txt = word+".txt";
    ofstream out(txt);
    if (out.is_open()) 
    {
        out << new_str;
        out.close();
        cout<<"已备份"<<word<<"下的数据"<<endl;

    }
    cout<<"当前数据:"<<new_str<<endl;
    cout<<"数据长度:"<<new_str.length()<<endl;
    int a= RegSetValueEx(hKey,_T(word.c_str()),0,REG_SZ,(BYTE *)new_str.c_str(),sizeof(szValue));
    cout<<"修改状态:"<<a<<endl;
    RegCloseKey(hKey);
    return 0;
}
 