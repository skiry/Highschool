#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int no,yes,a[1001],ok,l,b,B,aria;
char s[4];
void deil(int nr)
{
    if(a[nr]==2&&a[nr+1]==1) {ok=1;l=nr;}
    if(!ok)
    {
        cout<<"? "<<nr<<" 0"<<'\n';
        fflush(stdout);
        cin>>s;
        if(!strcmp(s,"NO"))
        {
            no=nr;
            a[nr]=1;
            if(!yes) deil(nr/2);
            else deil((yes+no)/2);
        }
        else
        {
            yes=nr;
            a[nr]=2;
            if(!no) deil(1000);
            else deil((yes+no)/2);
        }
    }
}
void deib(int nr)
{
    if(a[nr]==4&&a[nr+1]==3) {ok=1;b=nr;}
    if(!ok)
    {
        cout<<"? "<<nr<<" "<<2*l<<'\n';
        fflush(stdout);
        cin>>s;
        if(!strcmp(s,"NO"))
        {
            no=nr;
            a[nr]=3;
            if(!yes) deib(nr/2);
            else deib((yes+no)/2);
        }
        else
        {
            yes=nr;
            a[nr]=4;
            if(!no) deib(1000);
            else deib((yes+no)/2);
        }
    }
}
void deibm(int nr)
{
    if(a[nr]==6&&a[nr+1]==5) {ok=1;B=nr-2*l;}
    if(!ok)
    {
        cout<<"? 0 "<<nr<<'\n';
        fflush(stdout);
        cin>>s;
        if(!strcmp(s,"NO"))
        {
            no=nr;
            a[nr]=5;
            if(!yes) deibm(nr/2);
            else deibm((yes+no)/2);
        }
        else
        {
            yes=nr;
            a[nr]=6;
            if(!no) deibm(1000);
            else deibm((yes+no)/2);
        }
    }
}
int main()
{

    /*a=4*l*l;
    for(int i=l+1;!b;i++)
    {
        cout<<"? "<<i<<" "<<2*l<<'\n';
        fflush(stdout);
        cin>>s;
        if(!strcmp(s,"NO")) b=i-1;
    }
    for(int i=2*l+1;!B;i++)
    {
        cout<<"? 0 "<<i<<'\n';
        fflush(stdout);
        cin>>s;
        if(!strcmp(s,"NO")) B=i-1,B-=2*l;
    }
    a+=B*b;
    cout<<"! "<<a;*/
    deil(500);
    yes=l;
    no=1000;
    ok=0;
    deib((yes+no)/2);
    yes=2*l;
    no=1000;
    ok=0;
    deibm((yes+no)/2);
    aria=4*l*l+B*b;
    cout<<"! "<<aria;
    return 0;
}
