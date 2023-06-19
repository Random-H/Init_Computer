#include<iostream>
#include "windows.h"
#include <tchar.h>
#include "../inc/reg.h"
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
            ret = HMD_CreateCMD();
            if(ret!=1)
            {
                cout<<"创建失败，请以管理员身份运行"<<endl;
            }
            else
            {
                cout<<"创建成功"<<endl;
            }
            break;
        case '2':
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}