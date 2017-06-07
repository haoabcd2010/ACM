#include <bits/stdc++.h>
using namespace std;
#define MX 1005

char str[MX];
void rever(char *a,char *b)
{
    while (a!=b)
    {
        swap(*a,*b);
        if (a!=b)a++;
        if (b!=a)b--;
    }
}

int main()
{
    int T;
    cin>>T;
    getchar();
    while (T--)
    {
        gets(str);
        int len = strlen(str);

        if (len!=0)
        {
            int i=0;
            while (str[i]==' ') i++;
            int l=i;
            for (i=i;i<=len;i++)
            {
                if (str[i]!=' '&&i!=len) continue;
                else
                {
                    rever(&str[l],&str[i-1]);
                    while (str[i]==' ') i++;
                    l=i;
                }
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
