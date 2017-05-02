#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char str[20];
void de(char s[])
{
    memset(str,0,sizeof(str));

    int i;
    int len=strlen(s);
    for (i=0;i<len;i++)
        s[i]-='0';
    reverse(s,s+len-1);

    int k=0,flag=0;
    for (i=0;i<len;i++)
    {
        str[i]+=s[i]*2;
        if (str[i]>=10)
        {
            str[i]-=10;
            str[i+1]++;
        }

        if (flag==0&&str[i]==0)//看这个数最后有几个 0
        {
            k++;
        }
        if (str[i]!=0) flag=1;

    }
    while (str[i]!=0) i++;
    str[i]='\0';

    str[k]--;
    while (k--) str[k]=9;//减 1

    for (int j=0;j<i;j++) str[j]+='0';
    for (int j=0;j<len;j++) s[j]+='0';
    reverse(str,str+i);
    reverse(s,s+len);
}

int main()
{
    char s[20]={"161"};
    de(s);
    printf("%s\n",str);
    return 0;
}
