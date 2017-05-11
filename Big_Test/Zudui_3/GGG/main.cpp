#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
#define MX 10005

int next[MX];
void get_next(string &T)
{
    int i=0,j=-1;
    next[0]=-1;
    while (i<T.size())
    {
        if (j==-1||T[i]==T[j])
        {
            i++;j++;
            if (T[i]!=T[j]) next[i]=j;
            else next[i]=next[j];
        }
        else j = next[j];
    }
}

int KMP(string &s,string &t)
{
    get_next(t);
    int i=-1,j=-1;
    int lens = s.size();
    int lent = t.size();
    while (i<lens&&j<lent)
    {
        if (j==-1||s[i]==t[j])
        {
            i++;j++;
        }
        else
            j = next[j];
    }
    if (j==lent)
        return i-lent;
    return -1;
}

string find_(string &s,string &t)
{
    int index  = KMP(s,t);
    if (index == -1) return "";
    index += t.size()+1;
    if (s[index]=='"')
    {
        string re;
        re +='"';
        int res = index+1;
        while(s[res]!='"')
        {
            re+=s[res++];
        }
        re+='"';
        return re;
    }
    else
    {
        string re;
        re+='{';
        int k=1;
        int res = index+1;
        while (k)
        {
            if (s[res]=='{') k++;
            if (s[res]=='}') k--;
            re+=s[res++];
        }
        return re;
    }
    return "";
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string str;
        cin>>str;
        int n;
        cin>>n;
        while (n--)
        {
            string s,t;
            s = str;
            cin>>t;
            string x;
            for (int i=0;i<=t.size();i++)
            {
                if (t[i]=='.'||i==t.size())
                {
                    s = find_(s,x);
                    x="";
                    if (s=="")
                    {
                        printf("Error!\n");
                        break;
                    }
                }
                else x+=t[i];
            }
            if (s!="")
                cout<<s<<endl;
        }
    }
    return 0;
}

/*
1
{"hm":"Edward","stu":{"stu01":"Alice","stu02":{"hello":"world","wow":"haha"}}}
10
*/
