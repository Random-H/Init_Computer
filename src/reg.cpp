#include "../inc/reg.h"
#include <iostream>
#include "windows.h"
using namespace std;
#include <tchar.h>

HKEY hKEY;
DWORD dwDisposition;

int HMD_RegCreateKey(char *path,char *name,char *data)
{
    LPCTSTR data_Set = _T(path);
    int b = RegCreateKeyEx(HKEY_CLASSES_ROOT, data_Set, 0, NULL, 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, NULL, &hKEY, &dwDisposition);
    int a= RegSetValueEx(hKEY,name,0,REG_SZ,(BYTE *)data,sizeof(data));//修改默认值
    RegCloseKey(hKEY);
    if(a&&b)
        return 1;
    else
        return 0;
    
}

int HMD_DeleteKey(char *path,char *name)
{
    LPCTSTR data_Set = _T(path);
    int ret0 = RegOpenKeyEx(HKEY_CLASSES_ROOT, data_Set, NULL, KEY_READ, &hKEY);//打开主键
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
    HMD_RegCreateKey("Directory\\Background\\shell\\cmd_","","Cmd");
    HMD_RegCreateKey("Directory\\Background\\shell\\cmd_","Icon","cmd.exe");
    HMD_RegCreateKey("Directory\\Background\\shell\\cmd_\\command","","cmd.exe");
}

int HMD_DeleteCMD()
{
    HMD_DeleteKey("Directory\\Background\\shell\\cmd_","command");
    HMD_DeleteKey("Directory\\Background\\shell","cmd_");
}



