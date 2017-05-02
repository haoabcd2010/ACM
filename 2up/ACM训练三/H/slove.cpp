/*
//EEE
#include <stdio.h>
#include <string.h>

char ch[10][1200];

int main()
{
    strcpy(ch[0],"01");

    for (int i=1;i<10;i++)
    {
        int k=0;
        int len=strlen(ch[i-1]);
        for (int j=0;j<len;j++)
        {
            if (ch[i-1][j]=='0')
            {
                ch[i][k++]='1';
                ch[i][k++]='0';
            }
            else
            {
                ch[i][k++]='0';
                ch[i][k++]='1';
            }
        }
        ch[i][k]='\0';
    }
    for (int i=0;i<10;i++)
    {

        int sum=0;
        int len =strlen(ch[i]);
        for (int j=0;j<len-1;j++)
        {
            if (ch[i][j]=='0'&&ch[i][j+1]=='0')
                sum++;
        }
        //printf("%s\n",ch[i]);
        printf("%d\n",sum);
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char num[1005][500];
char str[500];

char *add(char s[])
{
    memset(str,0,sizeof(str));

    int i;
    int len=strlen(s);
    for (i=0;i<len;i++)
        s[i]-='0';
    reverse(s,s+len);

    for (i=0;i<len;i++)
    {
        str[i]+=s[i]*2;
        if (i==0) str[i]++;

        if (str[i]>=10)
        {
            str[i]-=10;
            str[i+1]++;
        }

    }
    while (str[i]!=0) i++;
    str[i]='\0';
    for (int j=0;j<i;j++) str[j]+='0';
    for (int j=0;j<len;j++) s[j]+='0';
    reverse(str,str+i);
    reverse(s,s+len);
    return str;
}

char *de(char s[])
{
    memset(str,0,sizeof(str));

    int i;
    int len=strlen(s);
    for (i=0;i<len;i++)
        s[i]-='0';
    reverse(s,s+len);

    int k=0,flag=0;
    for (i=0;i<len;i++)
    {
        str[i]+=s[i]*2;
        if (str[i]>=10)
        {
            str[i]-=10;
            str[i+1]++;
        }

        if (flag==0&&str[i]==0)//减1，看这个数最后有几个 0
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
    return str;
}


int main()
{
    int n;
    int i;
    int xx=0;

    strcpy(num[1],"0");

    for (i=2;i<=1000;i++)
    {
        if (i%2==0)
        {
            add(num[i-1]);
            strcpy(num[i],str);
        }

        else
        {
            de(num[i-1]);
            strcpy(num[i],str);
        }
    }
    while (scanf("%d",&n)!=EOF)
    {
        printf("%s\n",num[n]);
    }
    return 0;
}
