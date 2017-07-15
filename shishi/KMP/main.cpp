#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 10005

int n,m;
char S[MX];
char T[MX];
int fail[MX];

void get_fail()
{
    int i=0,j=-1;
    fail[0]=-1;
    while (i<m)
    {
        if (j==-1||T[i]==T[j])
        {
            i++,j++;
            fail[i]=j;
        }
        else j = fail[j];
    }
}

int KMP()
{
    get_fail();
    int i=-1,j=-1;
    int ret =0;
    while (i<n&&j<m)
    {
        if (j==-1||S[i]==T[j])
        {
            i++,j++;

        }
        else j = fail[j];
        if (j==m)
        {
            ret++;
            j=fail[j];
        }
    }
    return ret;
}

int main()
{
    scanf("%s",S); // Ä£Ê½´®
    scanf("%s",T); // Æ¥Åä´®
    n = strlen(S);
    m = strlen(T);
    int index = KMP();
    printf("%d\n",index);
    return 0;
}
