
/***************************************************
������ IDA* + ������ ���������˵������� ��������
***************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define size 3          //����涨������

int move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//�� �� �� ��  �û�˳��
char op[4]={'u','l','r','d'};

int map[size][size],map2[size*size],limit,path[100];
int flag,length;

// ʮ������ �ı�
//int goal[16][2]= {{size-1,size-1},{0,0},{0,1},{0,2},
//                  {0,3},{1,0},{1,1},{1,2},
//                  {1,3},{2,0},{2,1},{2,2},
//                  {2,3},{3,0},{3,1},{3,2}};//��������Ӧ��λ�ö��ձ�

// ������ �ı�
int goal[9][2]= {{size-1,size-1},{0,0},{0,1},{0,2},
                                 {1,0},{1,1},{1,2},
                                 {2,0},{2,1}};      //��������Ӧ��λ�ö��ձ�

int nixu(int a[size*size])
{
    int i,j,ni,w,x,y;  //w����0��λ�� �±꣬x y ����0����������
    ni=0;
    for(i=0;i<size*size;i++)  //��size*size=16
    {
        if(a[i]==0)  //�ҵ�0��λ��
            continue;//w=i;

        for(j=i+1;j<size*size;j++)  //ע�⣡��ÿһ������������еı�һȦ ����С��i�ĸ������
        {
            if (a[j]==0)continue;
            if(a[i]>a[j])
                ni++;
        }
    }
    //x=w/size;
    //y=w%size;
    //ni+=abs(x-(size-1))+abs(y-(size-1));  //������0��ƫ����
    if(ni%2==0)
        return 1;
    else
        return 0;
}

int hv(int a[][size])//���ۺ����������پ��룬С����ʵ���ܲ���
{
    int i,j,cost=0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            int w=map[i][j];
            cost+=abs(i-goal[w][0])+abs(j-goal[w][1]);
        }
    }
    return cost;
}

void swap(int*a,int*b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void dfs(int sx,int sy,int len,int pre_move)//sx,sy�ǿո��λ��
{
    int i,nx,ny;

    if(flag)
        return;

    int dv=hv(map); //���ڵ������پ�����

    if (len==limit)
    {
        if(dv==0)  //�ɹ��� �˳�
        {
            flag=1;
            length=len;
            return;
        }
        else
            return;  //����Ԥ�賤�� ����
    }
    else if(len<limit)
    {
        if(dv==0)  //����Ԥ�賤�� �ɹ����˳�
        {
            flag=1;
            length=len;
            return;
        }
    }

    for(i=0;i<4;i++)
    {
        if(i+pre_move== 3&& len>0)//������һ���ƶ������෴���Եڶ����Ժ����
            continue;
        nx=sx+move[i][0];  //�ƶ����Ĳ� ��������
        ny=sy+move[i][1];

        if( 0<=nx && nx<size && 0<=ny && ny<size )  //�ж��ƶ�����
        {
            swap(&map[sx][sy],&map[nx][ny]);
            int p=hv(map);   //�ƶ���� �����پ���p=16

            if(p+len<=limit&&!flag)  //p+len<=limit&&!flag��֦�ж����
            {
                path[len]=i;
                dfs(nx,ny,len+1,i);  //�統ǰ���ɹ��� �ݹ����dfs
                if(flag)
                    return;
            }
            swap(&map[sx][sy],&map[nx][ny]);  //�����������һ��
        }
    }
}

int main()
{
    int pp;
    int i,j,k,sx,sy;
    char str[30];

    while(gets(str))
    {
        int slen = strlen(str);
        j=0;
        for(i=0;i<slen;i++)
        {
            if (str[i]==' ')
                continue;
            if (str[i]=='x')
                map2[j]=0;
            else
                map2[j]=str[i]-'0';
            j++;
        }

        for(i=0;i<size*size;i++)  //��map ��map2��ֵmap�Ƕ�ά���飬map2��һά����
        {
            if(map2[i]==0)
            {
                map[i/size][i%size]=0;
                sx=i/size;
                sy=i%size;
            }
            else
            {
                map[i/size][i%size]=map2[i];
            }
        }
        flag=0,length=0;
        memset(path,-1,sizeof(path));  //�Ѷ���path[100]���飬��path����-1
        if(nixu(map2)==1)                     //��״̬�ɴ�
        {
            limit=hv(map);  //ȫ���������پ���֮��
            while (!flag)
            {
                dfs(sx,sy,0,-1);
                if(!flag)
                  limit++; //�õ�������С����
            }
            if(flag)
            {
                for(i=0;i<length;i++)
                printf("%c",op[path[i]]);  //����path���URLD·��
                printf("\n");
            }
        }
        else if(!nixu(map2)||!flag)
            printf("unsolvable\n");
    }
    return 0;
}

