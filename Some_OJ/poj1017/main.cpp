/*
#include <stdio.h>
using namespace std;

int box[7];
int main()
{
    while (1)
    {
        int all=0;
        for (int i=1;i<=6;i++)
        {
            scanf("%d",&num[i]);
            all+=num[i];
        }
        if (all==0) break;

        int ans = 0;

        ans+=num[6]; //6

        ans+=num[5];
        num[1]-=num[5]*11; // 5

        ans += num[4]; // 4
        if (num[4]*5<=num[2])
        {
            num[2]-=num[4]*5;
        }
        else
        {
            int use = num[2]/5;
            num[2] -= use*5;
            int re = num[4]-use;
            num[1] -= re*20-num[2]*4;
            num[2]=0;
        }

        ans += num[3]/4; // 3
        int t = num[3]%4;
        if (t) ans++;
        if (t>0&&num[2]>0)
        {
            if (t==1)
            {
                if (num[2]>5)
                {
                    num[2]-=5;
                    num[1]-=7;
                }
                else
                {
                    num[1]-=27-num[2]*4;
                    num[2]=0;
                }

            }
            if (t==2)
            {
                if (num[2]>3)
                {
                    num[2]-=3;
                    num[1]-=6;
                }
                else
                {
                    num[1]-=18-num[2]*4;
                    num[2]=0;
                }
            }
            if (t==3)
            {
                num[2]-=1;
                num[1]-=5;
            }
        }

        if (num[2]>0) // 2
        {
            ans += num[2]/9;
            t = num[2]%9;
            if (t) t++;
            num[1] -= 36-t*4;
        }

        if (num[1]>0) // 1
        {
            ans += num[1]/36 + (num[1]%36==0?0:1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
#include <stdio.h>
using namespace std;

int box[7];
int main()
{
    while (1)
    {
        int all=0;
        for (int i=1;i<=6;i++)
        {
            scanf("%d",&box[i]);
            all+=box[i];
        }
        if (all==0) break;

        int ans = box[4]+box[5]+box[6];
        int x2 = 5*box[4];
        int x1 = 11*box[5];
        if (x2>box[2])
        {
            x1+=(x2-box[2])*4;
            x2=box[2];
        }

        int t=box[3]%4;
        if (t) ans++;
        ans += box[3]/4;
        if (t==1) x2+=5,x1+=7;
        if (t==2) x2+=3,x1+=6;
        if (t==3) x2+=1,x1+=5;
        if (x2>box[2])
        {
            x1+=(x2-box[2])*4;
            x2=box[2];
        }

        if (x2<box[2])
        {
            int re = box[2]-x2;
            int t =re%9;
            if (t)
            {
                x1+=(9-t)*4;
                ans++;
            }
            ans +=re/9;
        }

        if (x1<box[1])
        {
            int re = box[1]-x1;
            int t = re%36;
            ans += re/36;
            if (t) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

