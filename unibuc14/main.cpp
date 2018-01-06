#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,cnt=1;
char s[1000001];
int main()
{
    f>>n;
    strcat(s,"1221");
    while(1<<(2*cnt)<n)
    {
        for(int j=1;j<=2;j++)
        for(int i=0;i<(1<<(2*cnt));++i)
        {
            if(s[i]=='1') strcat(s,"2");
            else strcat(s,"1");
        }
        for(int i=0;i<(1<<(2*cnt));++i)
        {
            if(s[i]=='1') strcat(s,"1");
            else strcat(s,"2");
        }
        ++cnt;
    }
    for(int i=0;i<n;i++) g<<s[i];
    return 0;
}
