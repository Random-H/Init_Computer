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
        cout<<"1.�����Ҽ�CMDѡ��"<<endl;
        cout<<"2.����MinGW\\bin��������"<<endl;
        cout<<"3.����Python����ӻ�������"<<endl;
        ch = getchar();
        switch (ch)
        {
        case '1':
            ret = HMD_CreateCMD();
            if(ret!=1)
            {
                cout<<"����ʧ�ܣ����Թ���Ա�������"<<endl;
            }
            else
            {
                cout<<"�����ɹ�"<<endl;
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