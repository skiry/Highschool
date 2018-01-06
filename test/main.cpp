#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i;
char s[100001];
int eval();
int termen();
int factor();
int main()
{
    f.getline(s,100001);
    g<<eval();
}
int eval()
{
    int r;
    r=termen();
    while(s[i]=='+'||s[i]=='-')
    if(s[i]=='+')
    {
        ++i;
        r+=termen();
    }
    else
    {
        ++i;
        r-=termen();
    }
    return r;
}
int termen()
{
    int r;
    r=factor();
    while(s[i]=='*'||s[i]=='/')
    if(s[i]=='*')
    {
        ++i;
        r*=factor();
    }
    else
    {
        ++i;
        r/=factor();
    }
    return r;
}
int factor()
{
    int r=0;
    if(s[i]=='(')
    {
        ++i;
        r=eval();
        ++i;
    }
    else while(s[i]>='0'&&s[i]<='9')
    {
        r*=10;
        r+=s[i]-'0';
        ++i;
    }
    return r;
}
