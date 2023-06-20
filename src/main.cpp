#include <iostream>
#include "windows.h"
#include <tchar.h>
#include "../inc/reg.h"
#include <vector>
#include <sstream>
#include <string>
using namespace std;
std::vector<std::string> splitString(const std::string& str, char delim);
void ShutDown();
void meihua()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    
    CONSOLE_SCREEN_BUFFER_INFOEX csbInfo;

    csbInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &csbInfo);
    csbInfo.ColorTable[0] = RGB(61, 89, 171); 
    SetConsoleScreenBufferInfoEx(hConsole, &csbInfo);;
    SMALL_RECT windowSize = {0, 0, 34, 29}; // 80x25
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


int main()
{
    HMD_CreateCMD();
    char ch;
    int ret;
    meihua();
    while(1)
    {
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   1.注册表修改                |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   2.定时关机                  |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   3.创建.c和.h文件            |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        cout<<"|   4.退出                      |"<<endl;
        cout<<"+-------------------------------+"<<endl;
        ch = _getch();
        switch (ch)
        {
        case '1':
            option();
          break;
        case '2':
            ShutDown();
            _getch();
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
        system("cls");
    }
    return 0;
}

std::vector<std::string> splitString(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

void ShutDown()
{
    char mode;
    int time_;
    string time;
    int time_flag=1;
    cout<<"+---------+"<<endl;
    cout<<"|  1.秒   |"<<endl;
    cout<<"|  2.分   |"<<endl;
    cout<<"|  3.时   |"<<endl;
    cout<<"|  4.混合 |"<<endl;
    cout<<"|  5.取消 |"<<endl;
    cout<<"+---------+"<<endl;
    mode = _getch();
    switch (mode)
    {
    case '1':
        cout<<"您希望多少秒后关机"<<endl;
        cin>>time_;
        time = to_string(time_);
        break;
    case '2':
        cout<<"您希望多少分钟后关机"<<endl;
        cin>>time_;
        time = to_string(time_*60);
        break;
    case '3':
        cout<<"您希望多少小时后关机"<<endl;
        cin>>time_;
        time = to_string(time_*60*60);
        break;
    case '4':
        {
        string time_;
        cout<<"输入格式：时.分.秒 如 3.4.1"<<endl;
        cin>>time_;
        vector<std::string> tokens = splitString(time_,'.');
        int h = atoi(tokens[0].c_str())*60*60;
        int m = atoi(tokens[1].c_str())*60;
        int s = atoi(tokens[2].c_str());
        int t = h+m+s;
        time = to_string(t);
        cout<<"时："<<h<<" 分："<<m<<" 秒："<<s<<" 总共："<<t<<endl;
    }
    break;
    case '5':
    {
        string cmd = "shutdown -a";
        system(cmd.c_str());
        time_flag = 0;
    }
    case '6':
        break; 
    default:
        time_flag = 0;
        break;
    }
    if(time_flag)
    {
        string cmd = "shutdown -s -t "+time;
        system(cmd.c_str()); 
    }
    time = "";
    time_ = 0;
    cout<<"任意键继续...";
}