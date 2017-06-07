#include <bits/stdc++.h>
using namespace std;
#define MX 5005

char s1[MX],s2[MX];
char data1[MX],data2[MX];
char tmp[MX];

void input(char *a,char *b)
{
    gets(tmp);
    while (gets(tmp))
    {
        if (strcmp(tmp,"END")==0) break;
        strcat(a,tmp);
        strcat(a,"\n");
    }
    int t=0;
    int len = strlen(a);
    for (int i=0;i<len;i++)
    {
        if (a[i]!=' '&&a[i]!='\t'&&a[i]!='\n')
            b[t++]=a[i];
    }
    b[t++]='\0';
}

int main()
{
    int T;
    cin>>T;
    getchar();
    while (T--)
    {
        s1[0]='\0';
        s2[0]='\0';
        input(s1,data1);
        input(s2,data2);
        if (strcmp(s1,s2)==0)
            printf("Accepted\n");
        else if (strcmp(data1,data2)==0)
            printf("Presentation Error\n");
        else
            printf("Wrong Answer\n");
    }
    return 0;
}
