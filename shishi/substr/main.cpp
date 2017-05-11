#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s = "Golden Global   View,disk * desk";
    string t = s.substr(0,1);
    printf("%s\n",t.data());
    return 0;
}
