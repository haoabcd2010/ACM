#include <stdio.h>
#include <string.h>

int main()
{
    char word[27]={"VWXYZABCDEFGHIJKLMNOPQRSTU"};
    char star[10]={"STAR"};
    char end_[10]={"END"};
    char end_in[20]={"ENDOFINPUT"};

    char ch1[250];
    char ch2[250];
    char ch3[250];
    while (gets(ch1))
    {
        if (strcmp(ch1,end_in)==0) break;
        gets(ch2);
        int len =strlen(ch2);
        int i;
        for (i=0;i<len;i++)
        {
            if (ch2[i]<='Z'&&ch2[i]>='A')
                ch3[i]=word[ch2[i]-'A'];
            else
                ch3[i]=ch2[i];
        }
        ch3[i]='\0';
        gets(ch1);
        if (strcmp(ch1,end_)==0)
            puts(ch3);
    }
    return 0;
}
