#include "../inc/reg.h"
#include "windows.h"
#include <fstream>//�ļ���дͷ�ļ�
#include <tchar.h>

HKEY hKEY;
DWORD dwDisposition;

int HMD_RegCreateKey(char *path,char *name,char *data)
{
    LPCTSTR data_Set = _T(path);
    int b = RegCreateKeyEx(HKEY_CLASSES_ROOT, data_Set, 0, NULL, 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, NULL, &hKEY, &dwDisposition);
    int a= RegSetValueEx(hKEY,name,0,REG_SZ,(BYTE *)data,sizeof(data));//�޸�Ĭ��ֵ
    RegCloseKey(hKEY);
    if(!a&&!b)
        return 1;
    else
        return 0;
    
}

int HMD_DeleteKey(char *path,char *name)
{
    LPCTSTR data_Set = _T(path);
    int ret0 = RegOpenKeyEx(HKEY_CLASSES_ROOT, data_Set, NULL, KEY_READ, &hKEY);//������
    if(ret0!=0)
    {
        return 0;
    }
    else
    {
        RegDeleteKey(hKEY,name);
        RegCloseKey(hKEY);
        return 1;
    } 
}

int HMD_CreateCMD()
{
    int a = HMD_RegCreateKey("Directory\\Background\\shell\\cmd_","","Cmd");
    int b = HMD_RegCreateKey("Directory\\Background\\shell\\cmd_","Icon","cmd.exe");
    int c = HMD_RegCreateKey("Directory\\Background\\shell\\cmd_\\command","","cmd.exe");
    if(a&&b&&c)
        return 1;
    return 0; 
}

int HMD_DeleteCMD()
{
    int a = HMD_DeleteKey("Directory\\Background\\shell\\cmd_","command");
    int b = HMD_DeleteKey("Directory\\Background\\shell","cmd_");
    if(a&&b)
        return 1;
    return 0; 
}



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
        cout<<"����"<<envValue<<"�Ѵ���"<<endl;
        return 2;
    }
    string new_str = old_str +";"+envValue;

    string txt = word+".txt";
    ofstream out(txt);
    if (out.is_open()) 
    {
        out << new_str;
        out.close();
        cout<<"�ѱ���"<<word<<"�µ�����"<<endl;

    }
    cout<<"��ǰ����:"<<new_str<<endl;
    cout<<"���ݳ���:"<<new_str.length()<<endl;
    int a= RegSetValueEx(hKey,_T(word.c_str()),0,REG_SZ,(BYTE *)new_str.c_str(),sizeof(szValue));
    cout<<"�޸�״̬:"<<a<<endl;
    RegCloseKey(hKey);
    return 0;
}

void option()
{
    char ch;
    do
    {
       system("cls");
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   1.�����Ҽ�CMDѡ��           |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   2.����MinGW\\bin��������     |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   3.��ӱ���������������      |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   4.������һ��                |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   5.�˳�                      |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        ch = _getch();
        switch (ch)
        {
        case '1':
        {
            int ret = HMD_CreateCMD();
            if(ret!=1)
            {
                cout<<"����ʧ�ܣ����Թ���Ա�������"<<endl;
            }
            else
            {
                cout<<"�����ɹ�"<<endl;
            }
            _getch();
        }
        break;
        case '2':
        {
            char buffer[256];
            GetCurrentDirectoryA(256, buffer);
            string folder;
            string now_folder = string(buffer);
            string file_folder = "\\tool\\MinGW64";
            int re = now_folder.find("\\bin");
            now_folder = now_folder.replace(re,file_folder.length(),file_folder);
            cout<<"�ļ�Ŀ¼:"<<now_folder<<endl;
            cout<<"����MinGW64·��"<<endl;
            cin>>folder;
            cout<<"��ǰ��"<<now_folder<<endl;
            cout<<"Ŀ�꣺"<<folder<<endl;
            string cmd = "xcopy "+now_folder+" "+folder+" /s/e/h/y";
            system(cmd.c_str());
            //xcopy "C:\Users\HMD\Desktop\Init\tool" "C:\Users\HMD\Desktop\rt" /s/e/h/y
            addEnvPath("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", "Path","c:\\soft1\\");
            _getch();
        }
            break;
        case '3':
        {
            char buffer[256];
            GetCurrentDirectoryA(256, buffer);
            string now_folder = string(buffer);
            //xcopy "C:\Users\HMD\Desktop\Init\tool" "C:\Users\HMD\Desktop\rt" /s/e/h/y
            addEnvPath("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", "Path",now_folder+"HMD.exe");
            _getch();
        }
            break;
        case '4':
            break;
        case '5':
            exit(1);
            default:
        break;
        }
    } 
    while (ch != '4');
}