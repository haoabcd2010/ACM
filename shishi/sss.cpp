#include  <stdlib.h>
#include  <windows.h>

int main()
{
    int iResult = ::MessageBox(NULL,TEXT("ȷ�Ϲػ�"),TEXT("�ػ�"),MB_OKCANCEL|MB_ICONQUESTION );
    if(1 ==iResult)
    {
        system("shutdown -s -t 0");
    }
    return 0;
}
