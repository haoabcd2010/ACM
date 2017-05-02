#include  <stdlib.h>
#include  <windows.h>

int main()
{
    int iResult = ::MessageBox(NULL,TEXT("确认关机"),TEXT("关机"),MB_OKCANCEL|MB_ICONQUESTION );
    if(1 ==iResult)
    {
        system("shutdown -s -t 0");
    }
    return 0;
}
