#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,j,t,base,nr[10];
unsigned long long x,i,start,y;
char sir[9999999];
int prim(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i == 0) return i;
    }
    return 1;
}
int baseto10(int a,int base)
{
    long numar=0;
    int nrr=0;int q=a;
    while(a)
    {
        numar+=(pow(base,nrr)*(a%10));
        //g<<numar<<" "<<numar<<"  ";
        a/=10;
        nrr++;
        //g<<endl<<endl;
    }
    return numar;
}
int main()
{
    f>>t;
    f>>n>>j;
    start=pow(10,n-1);
    g<<start<<" ";
    g<<"Case #1:"<<endl;
    for(i=1;i<=j;i++)
        {
            itoa(start,sir,2);
            x=atoi(sir);

            while(x%10==0)
                {
                    start++;
                    itoa(start,sir,2);
                    x=atoi(sir);
                }

            base=3;
            //g<<start<<" START WA "<<x;
            if(prim(x) != 1) ///daca DA, NU e prim
                {
                    nr[2]=prim(x);
                    //g<<x<<"X "<<prim(x)<<" "<<baseto10(x,2)<<"  ";
                    //g<<" "<<nr[2]<<" "<<nr[10];
                    //itoa(start,sir,base);      ///transform in baza 3
                    y=baseto10(x,base);
                    while(prim(y) != 1 && base <= 10)  ///verific daca baza BASE e prima si sunt mai jos de 10
                        {
                            //g<<y<<"prim  "<<prim(y)<<"  baza"<<base<<endl;
                            nr[base]=prim(y);
                            base++;
                            //itoa(start,sir,base);
                            y=baseto10(x,base);
                            //g<<y<<endl;
                         }
                }
            if(base == 11)
                {
                    itoa(start,sir,2);
                    y=atoi(sir);
                    g<<y<<" ";
                    for(int k=2;k<=10;k++) g<<nr[k]<<" ";
                    g<<endl;
                }
            else i--;
            start++;
            //g<<endl<<endl;
        }
        //g<<baseto10(100011,2);
        //g<<" "<<pow(5,0);
        return 0;
}
