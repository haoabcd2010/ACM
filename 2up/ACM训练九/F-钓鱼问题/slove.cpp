#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int f_i[30];//��ʼ����ֵ
int temp_i[30];//���������
int d_i[30];//�����ݼ�ֵ
int t_i[30];//������ķ�ʱ��
int n,h;

int spend[30][30];//��ÿһ����������ʱ�䣬spend[][0]�Ǵ�������������������ֵ
int Diao(int k)
{
    memset(spend[k],0,sizeof(spend[k]));
    int i,res=0,time=h*60;
    for (i=1;i<=k;i++)
        temp_i[i]=f_i[i];
    for (i=1;i<k;i++)//·�ϵĺķѶ�ȥ��
        time-=t_i[i]*5;
    while (time>0)
    {
        int max_=-999999,max_p;
        for (i=1;i<=k;i++)//ÿ���ҵ�����
        {
            if (temp_i[i]>max_)
            {
                max_=temp_i[i];
                max_p=i;
            }
        }
        if (max_>0)//�����Ե���
        {
            res+=max_;
            temp_i[max_p]-=d_i[max_p];
            spend[k][max_p]+=5;
            time-=5;
        }
        else
        {
            spend[k][1]+=time;
            break;
        }
    }
    spend[k][0]=res;//0λ�÷�����ֵ
    return 0;
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
        scanf("%d",&h);
        int i;
        for (i=1;i<=n;i++)
            scanf("%d",&f_i[i]);
        for (i=1;i<=n;i++)
            scanf("%d",&d_i[i]);
        for (i=1;i<n;i++)
            scanf("%d",&t_i[i]);
        for (i=1;i<=n;i++)//��ÿһ�����������ɵ����ֵ
            Diao(i);
        int ans=0,pos;
        for (i=1;i<=n;i++)
        {
            if (spend[i][0]>ans)
            {
                ans=spend[i][0];
                pos=i;
            }
            else if (spend[i][0]==ans)//���ڣ���Ҫ��˭��ǰ��ĳ������ľ�
            {
                for (int j=1;j<=n;j++)
                {
                    if (spend[i][j]>spend[pos][j])
                    {
                        pos=i;
                        break;
                    }
                    else if (spend[i][j]<spend[pos][j])
                        break;
                }
            }
        }
        for (i=1;i<n;i++)
            printf("%d, ",spend[pos][i]);
        printf("%d\n",spend[pos][i]);
        printf("Number of fish expected: %d\n\n",ans);

    }
    return 0;
}


