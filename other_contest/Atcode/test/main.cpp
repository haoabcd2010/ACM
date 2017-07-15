#include <bits/stdc++.h>
using namespace std;
#define MX 105

char str[MX];
int word[30];
int sp[MX];

int main()
{
    scanf("%s",str);
    int len = strlen(str);
    for (int i=0;i<len;i++)
        word[str[i]-'a']++;
    int malp=0;
    for (int i=1;i<26;i++)
        if (word[i]>word[malp])
            malp=i;

    int xxx=0,index;
    for (int i=0;i<len;i++)
    {
        if
    }

    int ans =0;
    while (1)
    {
        int ok=0;
        for ()
    }

    return 0;
}
