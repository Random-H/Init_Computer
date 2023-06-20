#include <iostream>
#include <conio.h> // 引用conio库
using namespace std;
int HMD_RegCreateKey(char *path,char *name,char *data);
int HMD_DeleteKey(char *path,char *name);
int HMD_CreateCMD();
int HMD_DeleteCMD();
int addEnvPath(char *path, string word,string envValue);
void option();