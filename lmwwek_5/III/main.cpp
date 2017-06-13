#include <iostream>
#include <set>
#include <queue>
#include <stdio.h>
using namespace std;

int n;
queue<int> Q;
set<int> lef;
set<int> rig;

void balance()
{
    if (lef.size()+1<rig.size())
    {
        int temp = *rig.begin();
        rig.erase(temp);
        lef.insert(temp);
    }
    if (rig.size()+1<lef.size())
    {
        int temp = *(--lef.end());
        rig.insert(temp);
        lef.erase(temp);
    }
}

int main()
{
    scanf("%d",&n);
    while (n--)
    {
        int op;
        scanf("%d",&op);

        if (op==1)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
            if (lef.size()==0&&rig.size()==0)
            {
                lef.insert(x);
            }
            else if (lef.size()>0)
            {
                int temp = *(--lef.end());
                if (x<temp) lef.insert(x);
                else rig.insert(x);
            }
            else if (rig.size()>0)
            {
                int temp = *rig.begin();
                if (x<temp) lef.insert(x);
                else rig.insert(x);
            }
        }
        else if (op==2)
        {
            int x = Q.front();
            Q.pop();
            set<int>::iterator it = lef.find(x);
            if (it!=lef.end()) //Èç¹ûÕÒµ½
                lef.erase(x);
            else
                rig.erase(x);
        }
        else if (op==3)
        {
            set<int>::iterator it;
            if (lef.size()>rig.size())
            {
                it = lef.end();
                it--;
                printf("%d\n",*it);
            }
            else
            {
                it = rig.begin();
                printf("%d\n",*it);
            }
        }
        balance();
    }
    return 0;
}
