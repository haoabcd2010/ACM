#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100005;
char node[30][30];
char key[maxn], plain[maxn], ans[maxn];

//void init(){
//    for(int i=25;i>=0;i--){
//        int ad=0;
//        for(int j=25-i;j<26;j++){
//            node[i][j]='A'+ad;
//            ad++;
//        }
//        for(int j=0;j<())
//    }
//}

char trans(char s,int t)
{
    return (s-'A'+t-'A'+1)%26+'A';
}

int main()
{
    while(scanf("%s", key)!=EOF && key[0]!='0')
    {
        scanf("%s", plain);
        int lkey=strlen(key), lplain=strlen(plain);
        for(int i=0;i<lplain;i++)
        {
            printf("%c", trans(key[i%lkey],plain[i]));
        }
        printf("\n");
    }
    return 0;
}
