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
        cout<<"1.增加右键CMD选项"<<endl;
        cout<<"2.增加MinGW\\bin环境变量"<<endl;
        cout<<"3.下载Python并添加环境变量"<<endl;
        ch = getchar();
        switch (ch)
        {
        case '1':
        {
            ret = HMD_CreateCMD();
            if(ret!=1)
            {
                cout<<"创建失败，请以管理员身份运行"<<endl;
            }
            else
            {
                cout<<"创建成功"<<endl;
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
            cout<<"文件目录:"<<now_folder<<endl;
            cout<<"输入MinGW64路径"<<endl;
            cin>>folder;
            cout<<"当前："<<now_folder<<endl;
            cout<<"目标："<<folder<<endl;
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