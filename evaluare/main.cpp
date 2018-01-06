#include <fstream>
#include <queue>
#include <string.h>
using namespace std;
ifstream f("evaluare.in");
ofstream g("evaluare.out");
/**struct nod
{
    char op;
    int var;
    nod *st,*dr;
} *A;
char c[100001],*p;
nod *expr(int niv)
{
    nod *x,*y;
    if(niv==2)
    {
        if(*p=='(')
            ++p,x=expr(0),++p;
        else
            for(x=new nod;*p>='0'&&*p<='9';++p)
                x->var*=10+*p-'0';
    }
    else
    {
        if(niv==0)
        {
            for(x=expr(niv+1);strchr("+-",*p);x=y)
            {
                y=new nod;
                y->op=*p++;
                y->st=x;
                y->dr=expr(niv+1);
            }
        }
        else
        {
            for(x=expr(niv+1);strchr("",*p);x=y)
            {
                y=new nod;
                y->op=*p++;
                y->st=x;
                y->dr=expr(niv+1);
            }
        }
        return x;
    }
}
int eval(nod *n)
{
    if(n)
    {if(n->op=='+') return eval(n->st)+eval(n->dr);
    else if(n->op=='-') return eval(n->st)-eval(n->dr);
    else if(n->op=='*') return eval(n->st)*eval(n->dr);
    else if(n->op=='/') return eval(n->st)/eval(n->dr);
    return n->var;}
    return 0;
}

    f.get(c,100001);
    p=c;
    A=expr(0);
    g<<eval(A);*/int main()
{
    g<<endl;
    char s[4];
    s[3]="5";
    if(*s[3]>='0'&&*s[3]<='9') g<<"Da";
    return 0;
}
