#include<iostream>
#include "windows.h"
#include <tchar.h>
#include "../inc/reg.h"
#include "../inc/env.h"
using namespace std;



int main()
{
    HMD_CreateCMD();
    char ch;
    int ret;
    while(1)
    {
        cout<<"1.�����Ҽ�CMDѡ��"<<endl;
        cout<<"2.����MinGW\\bin��������"<<endl;
        cout<<"3.����Python����ӻ�������"<<endl;
        ch = getchar();
        switch (ch)
        {
        case '1':
        {
            ret = HMD_CreateCMD();
            if(ret!=1)
            {
                cout<<"����ʧ�ܣ����Թ���Ա�������"<<endl;
            }
            else
            {
                cout<<"�����ɹ�"<<endl;
            }
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
           
        }
           break;  
        case '3':
            
            break;
        case '4':
            exit(0);
            break;
        default:
        getchar();
            break;
        }
        getchar();
        getchar();
    }
    return 0;
}