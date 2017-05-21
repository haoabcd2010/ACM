#include <bits/stdc++.h>
using namespace std;
#define MX 35

int equ,var;        // equ �з��� var ��δ֪��
int mat[MX][MX];    // �������
bool free_x[MX];    //�Ƿ����ɱ�Ԫ
int x[MX];          // x ��

void Debug(void)
{
    int i, j;
    cout<<"<---Debug--->"<<endl;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"<---Debug--->"<<endl;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int Gauss(int equ,int var)
{
    int i,j,k,col;
    for (k=0,col=0; k<equ && col <var ; k++,col++)
    {
        int m_index = k;
        for (i=k+1;i<equ;i++)
            if (abs(mat[i][col])>abs(mat[m_index][col])) m_index = i;
        if (m_index != k)
        {
            for (j=col;j<var+1;j++)
                swap(mat[k][j],mat[m_index][j]);
        }
        if (mat[k][col]==0) // ˵����������ȫΪ 0
        {
            k--;
            continue;
        }
        for (i=k+1;i<equ;i++)
        {
            if (mat[i][col]==0) continue;
            int LCM = lcm( abs(mat[k][col]),abs(mat[i][col]) );
            int ta = LCM / abs(mat[k][col]);
            int tb = LCM / abs(mat[i][col]);
            if (mat[k][col]*mat[i][col]<0) ta=-ta;
            for (j=col;j<var+1;j++)
                mat[i][j] = mat[i][j]*tb - mat[k][j]*ta;
        }
    }
    // �޽����� (0, 0, ..., a) (a!=0)
    for (i=k;i<equ;i++)
        if (mat[i][col]!=0) return -1;
    if (k<var) // ������ (0,0,0,0,...,0) ����
    {
        for (i=0;i<var;i++) free_x[i]=1;
        int f_n,n_index;
        for (i=k-1;i>=0;i--)
        {
            f_n = 0;
            for (j=0;j<var;j++)
            {
                if (mat[i][j]!=0&&free_x[j]) f_n++,n_index=j;
            }
            if (f_n>1) continue; //�д��� 1 �Ĳ�ȷ����,����
            int tmp = mat[i][var];
            for (j=0;j<var;j++)
                if (!free_x[j])
                    tmp -= x[j]*mat[i][j];
            x[n_index] = tmp / mat[i][n_index];
            free_x[n_index]=0;
        }
        return var-k; //�������ɱ�Ԫ����
    }
    for (i=var-1;i>=0;i--)
    {
        int tmp = mat[i][var];
        for (j=i+1;j<var;j++)
            tmp -= mat[i][j]*x[i];
        if (tmp%mat[i][i]!=0) return -2;
        x[i]=tmp%mat[i][i];
    }
    return 0;
}

int main()
{
    while (~scanf("%d%d",&equ,&var)!=EOF)
    {
        for (int i=0;i<equ;i++)
        for (int j=0;j<var+1;j++)
                scanf("%d",&mat[i][j]);
        int ret = Gauss(equ,var);
        if (ret == -1)
        {
            printf("�޽�\n");
        }
        else if (ret == -2)
        {
            printf("��������\n");
        }
        else if (ret == 0)
        {
            printf("��Ψһ��(����):\n");
            for (int i=0;i<var;i++)
                printf("x%d: %d\t",i+1,x[i]);
            printf("\n");
        }
        else if (ret > 0)
        {
            printf("�����⣬���ɱ�Ԫ %d ��\n",ret);
            for (int i=0;i<var;i++)
                if (free_x[i])
                    printf("x%d:��ȱ��\t",i+1);
                else
                    printf("x%d: %d\t",i+1,x[i]);
            printf("\n");
        }
    }

    return 0;
}
/*
3 3
1 2 4 6
2 6 3 9
1 2 3 6

3 2
2 -4 -2
4 -5 2
5 -9 1

3 5
1 1 1 1 1 10
1 1 1 0 1 8
1 1 0 1 1 3

1 1 1  1 1 10
0 0 -1 1 0 -7
0 0 0 -1 0 -2
*/
