#include <stdio.h>

#define maxn 100005

struct Num
{
    int ok;//���޻���
    int w;//�ܼ�ֵ
    int l,r;
}num[4*maxn];
int n;

int Init(int k,int l,int r)
{
    num[k].ok=0;
    num[k].l=l;
    num[k].r=r;
    if (l==r)
    {
        num[k].w=1;
        return num[k].w;
    }
    int mid=(l+r)/2;
    num[k].w=(Init(2*k,l,mid)+Init(2*k+1,mid+1,r));
    return num[k].w;
}

void updata(int l,int r,int z,int k)
{
    if (l==num[k].l&&r==num[k].r)
    {
        if (l!=r)//���������
        {
            num[k].ok=z;//˵���л��ۣ���������ܺ͸��˵��ǣ�����Ľڵ�δ��
            num[k].w=z*(r-l+1);
        }
        else num[k].w=z;//�����Ҷ�ڵ�
        return ;
    }
    int mid=(num[k].l+num[k].r)/2;

    if (num[k].ok!=0)//�������ڵ������δ�ģ�ֻ�ĵ��ӽڵ�
    {
        updata(num[k].l,mid,num[k].ok,2*k);
        updata(mid+1,num[k].r,num[k].ok,2*k+1);
        num[k].ok=0;
    }

    if (l>mid) updata(l,r,z,2*k+1);
    else if (r<=mid) updata(l,r,z,2*k);
    else
    {
        updata(l,mid,z,2*k);
        updata(mid+1,r,z,2*k+1);
    }
    num[k].w=num[2*k].w+num[2*k+1].w;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        Init(1,1,n);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int a,b,z;
            scanf("%d%d%d",&a,&b,&z);
            updata(a,b,z,1);
            //printf("total value %d\n",num[1].w);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas,num[1].w);
    }
    return 0;
}
