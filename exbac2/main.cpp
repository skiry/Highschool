#include <bits/stdc++.h>

using namespace std;
char s[100],*p;
int main()
{
    cin.getline(s,100);
    p=strtok(s," ");
    while(p)
    {
        p[0]-=32;
        p[strlen(p)-1]-=32;
        cout<<p<<" ";
        p=strtok(NULL," ");
    }
    return 0;
}
