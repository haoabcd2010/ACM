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
    while((RGBVS[0]-1)&&(RGBVS[1]-1)&&(RGBVS[2]-1))        //循环直到某种颜色的顶点数为1
    {
        int Next1=Memory[Cur].next;                        //当前顶点的下一个顶点
        int Next2=Memory[Next1].next;                      //当前顶点的下下个顶点
        if(Memory[Cur].colour!=Memory[Next2].colour)       //在相邻顶点颜色不同的条件下,只需P与Next2颜色不同即得P,Next1,Next2颜色均不同
        {
            printf("%d %d\n",Cur+1,Next2+1);               //选取分割线(P,Next2)
            Memory[Cur].next=Next2;                        //删除顶点Next1
            --RGBVS[Memory[Next1].colour];                 //相应颜色的顶点数减少
        }
        Cur=Memory[Cur].next;
    }
    while(RGBVS[Memory[Cur].colour]-1)                     //找到颜色唯一的顶点
    {
        Cur=Memory[Cur].next;
    }
    while(1)
    {
        int Next1=Memory[Cur].next;                        //当前顶点的下一个顶点
        int Next2=Memory[Next1].next;                      //当前顶点的下下个顶点
        if(Cur==Memory[Next2].next) { break; }             //循环直到多边形成为三角形
        printf("%d %d\n",Cur+1,Next2+1);                   //选取分割线(P,Next2)
        Memory[Cur].next=Next2;                            //删除顶点Next1
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
