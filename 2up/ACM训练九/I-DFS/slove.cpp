#include<stdio.h>
#include<string.h>

int N,RGBVS[3];                                            //Red Green Blue Vertice Sum

struct VERTICE
{
    int colour;
    int next;
}Memory[1005];

void DivideAndConquer()
{
    int Cur=0;
    while((RGBVS[0]-1)&&(RGBVS[1]-1)&&(RGBVS[2]-1))        //ѭ��ֱ��ĳ����ɫ�Ķ�����Ϊ1
    {
        int Next1=Memory[Cur].next;                        //��ǰ�������һ������
        int Next2=Memory[Next1].next;                      //��ǰ��������¸�����
        if(Memory[Cur].colour!=Memory[Next2].colour)       //�����ڶ�����ɫ��ͬ��������,ֻ��P��Next2��ɫ��ͬ����P,Next1,Next2��ɫ����ͬ
        {
            printf("%d %d\n",Cur+1,Next2+1);               //ѡȡ�ָ���(P,Next2)
            Memory[Cur].next=Next2;                        //ɾ������Next1
            --RGBVS[Memory[Next1].colour];                 //��Ӧ��ɫ�Ķ���������
        }
        Cur=Memory[Cur].next;
    }
    while(RGBVS[Memory[Cur].colour]-1)                     //�ҵ���ɫΨһ�Ķ���
    {
        Cur=Memory[Cur].next;
    }
    while(1)
    {
        int Next1=Memory[Cur].next;                        //��ǰ�������һ������
        int Next2=Memory[Next1].next;                      //��ǰ��������¸�����
        if(Cur==Memory[Next2].next) { break; }             //ѭ��ֱ������γ�Ϊ������
        printf("%d %d\n",Cur+1,Next2+1);                   //ѡȡ�ָ���(P,Next2)
        Memory[Cur].next=Next2;                            //ɾ������Next1
    }
}

void ReaData()
{
    char Polygon[1005];
    scanf("%s",Polygon);
    memset(RGBVS,0,sizeof(RGBVS));
    for(int i=0;Polygon[i];++i)
    {
        if(Polygon[i]=='R')      { Memory[i].colour=0; ++RGBVS[0]; }
        else if(Polygon[i]=='G') { Memory[i].colour=1; ++RGBVS[1]; }
        else if(Polygon[i]=='B') { Memory[i].colour=2; ++RGBVS[2]; }
        Memory[i].next=(i+1==N?0:i+1);
    }
}

int main()
{
    while(scanf("%d%*c",&N)==1)
    {
        ReaData();
        printf("%d\n",N-3);
        DivideAndConquer();
    }
    return 0;
}
