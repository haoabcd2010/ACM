/*
#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    set<string> s;
    char str[5050];
    while (gets(str))
    {
        char delim[50]=" :\".~!@#$%^&*()_+-={}[]:;.,<>?/\\.";
        char *p;
        p = strtok(str,delim);
        while (p)
        {
            if (p[0]>='A'&&p[0]<='Z') p[0]+=32;
            s.insert(p);
            p = strtok(NULL,delim);
        }
    }
    for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
        cout<<*it<<endl;
    return 0;
}
*/

#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

int main()
{
    string str;
    set<string,greater<string> > s;
    while(cin>>str)
    {
        for(int i=0;i<(int)str.length();i++)
        {
            if(isalpha(str[i]))
                str[i]=tolower(str[i]);
            else
                str[i]=' ';
        }
        string buf;
        stringstream ss(str);//������s������ ss��
        while(ss>>buf)
        s.insert(buf);//�����ﵼ����׼��string��,���뼯�Ϻ��Զ�ȡ���ظ����ʣ����������С�
    }
    for(set<string>::iterator it=s.begin();it!=s.end();it++)
        cout<<*it<<endl;
    return 0;
}
