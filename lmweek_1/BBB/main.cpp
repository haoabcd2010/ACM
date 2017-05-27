#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
#define MX 1005

string str[MX];

int main()
{
    int n=0;
    map<string,int> cp;
    while (cin>>str[n]&&str[n][0]!='#')
    {
        char temp[100];
        int i;
        for (i=0;i<str[n].length();i++)
            temp[i]=tolower(str[n][i]);
        sort(temp,temp+i);
        temp[i]='\0';
        cp[temp]++;
        n++;
    }
    sort(str,str+n);
    for (int i=0;i<n;i++)
    {
        char temp[100];
        int j;
        for (j=0;j<str[i].length();j++)
            temp[j]=tolower(str[i][j]);
        sort(temp,temp+j);
        temp[j]='\0';
        if (cp[temp]>=2) continue;
        cout<<str[i]<<endl;
    }
    return 0;
}
