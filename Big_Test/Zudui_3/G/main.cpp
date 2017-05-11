#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, string> eon;

void split(string s, string pre)
{
    int len=s.size();
    string key, val;
    int l, r;
    for(int i=0; i<len; i++)
    {
        //ÕÒkey
        if(s[i]=='"')
        {
            for(int j=i+1; j<len; j++)
            {
                if(s[j]=='"')
                {
                    string tmp(s, i+1, j-i-1);
                    key=tmp;
                    i=j;
                    break;
                }
            }
            //ÕÒval
            int j=i+2;
            val="";
            if(s[j]=='"')
            {
                for(int k=j+1; k<len; k++)
                {
                    if(s[k]=='"')
                    {
                        string tmp(s, j+1, k-j-1);
                        val=tmp;
                        i=k;
                        break;
                    }
                    else val+=s[i];
                }
            }
            else if(s[j]=='{')
            {
                int cnt=0;
                for(int k=j; k<len; k++)
                {
                    val+=s[k];
                    if(s[k]=='{')cnt++;
                    if(s[k]=='}')cnt--;
                    if(cnt==0)
                    {
                        string tmp(s, j, k-j+1);
                        val=tmp;
                        i=k;
                        break;
                    }
                }
            }
            eon[pre+key]=val;
        }
    }
}

int main()
{
    int n, q;
    string res, key, ans;
    scanf("%d", &n);
    while(n--)
    {
        cin>>res;
        split(res, "");
        scanf("%d", &q);
        while(q--)
        {
            cin>>key;
            int len=key.size();
            int l;
            string skey, val, pre="";
            for(int i=0;i<len;i++){
                if(key[i]=='"'){
                    for(int j=i+1;j<len;j++){
                        if(key[j]=='"'){
                            string tmp(key, i+1, j-i-1);
                            skey=tmp;
                            i=j+1;
                            break;
                        }
                    }
                }
                skey=pre+skey;
                if(eon[skey]==""){
                    val="Error!";break;
                }
                else{
                    val=eon[skey];
                    pre=skey+".";
                    split(val, pre);
                }
            }
            cout<<val<<endl;
        }
        eon.clear();
    }
    return 0;
}
