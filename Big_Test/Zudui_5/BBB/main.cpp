#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define LL long long

char ch[8];
int op[100005];
int nu[100005];

bool judge (LL x)
{
    return x>=1000000000 || x<=-1000000000;
}

void run()
{
    int t,f;
    scanf ("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int xxx;
        scanf ("%d",&xxx);
        stack <int> Q;
        Q.push(xxx);
        f=0;
        int l=0;
        for (int k=1;k<op[0];k++)
        {
            switch(op[k])
            {
                case 1: Q.push(nu[l++]); break;
                case 2: if (!Q.empty()) Q.pop(); else f=1; break;
                case 3: if (!Q.empty()) {LL x=Q.top();x=-x;Q.pop();Q.push(x);}else f=1;break;
                case 4: if (!Q.empty()) Q.push(Q.top()); else f=1;break;
                case 5: if (Q.size() >= 2)
                        {
                            LL x = Q.top();Q.pop();
                            LL y = Q.top();Q.pop();
                            Q.push(y); Q.push(x);
                        }
                        else f=1;
                        break;
                case 6: if (Q.size() >= 2)
                        {
                            LL x = Q.top();Q.pop();
                            LL y = Q.top();Q.pop();
                            Q.push(x+y);
                            if (judge(x+y))
                                f=1;
                        }
                        else f=1;
                        break;
                case 7: if (Q.size() >= 2)
                        {
                            LL x = Q.top();Q.pop();
                            LL y = Q.top();Q.pop();
                            Q.push(y-x);
                            if (judge(y-x))
                                f=1;
                        }
                        else f=1;
                        break;
                case 8: if (Q.size() >= 2)
                        {
                            LL x = Q.top();Q.pop();
                            LL y = Q.top();Q.pop();
                            Q.push(x*y);
                            if (judge(x*y))
                                f=1;
                        }
                        else f=1;
                        break;
                case 9: if (Q.size() >= 2)
                        {
                            LL x = Q.top();Q.pop();
                            LL y = Q.top();Q.pop();
                            if (!x || judge(y/x))
                            {
                                f=1;
                                break;
                            }
                            Q.push(y/x);
                        }
                        else f=1;
                        break;
                case 10: if (Q.size() >= 2)
                        {
                            int x = Q.top();Q.pop();
                            int y = Q.top();Q.pop();
                            if (!x || judge(y%x))
                            {
                                f=1;
                                break;
                            }
                            Q.push(y%x);
                        }
                        else f=1;
                        break;
            }
            if (f)
            {
                printf ("ERROR\n");
                break;
            }
        }
        if (!f)
        {
            if (Q.size() != 1)
            {
                printf ("ERROR\n");
            }
            else
            {
                cout<<Q.top()<<endl;
            }
        }
    }
}

int main()
{
    int i=1,l=0;
    while (scanf("%s",ch))
    {
        if (!strcmp(ch,"QUIT"))
        {
            break;
        }
        else if (!strcmp(ch,"END"))
        {
            op[0]=i;
            i=1;
            l=0;
            run();
            printf ("\n");
        }
        else
        {
            switch(ch[0])
            {
                case 'N': scanf("%d",&nu[l++]);op[i++]=1;break;
                case 'P':op[i++]=2;break;
                case 'I':op[i++]=3;break;
                case 'D':op[i++]= ch[1]=='U'?4:9; break;
                case 'S':op[i++]= ch[1]=='W'?5:7; break;
                case 'A':op[i++]=6;break;
                case 'M':op[i++]= ch[1]=='U'?8:10;break;
            }
        }
    }
    return 0;
}
