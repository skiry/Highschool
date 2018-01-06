#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("suma4.in");
ofstream g("suma4.out");
struct tatic
{
    int x,y;
};
struct matrice
{
    int nr,viz,rez;
    tatic t;
};
int n,i,j,nr,nr1,afisare[58],afis=1;
matrice a[58][3364];
void drum(int i,int j)
{
    nr=nr-i*i;
    afisare[afis++]=nr+j;
    if(a[i][j].t.x) drum(a[i][j].t.x,a[i][j].t.y);
    //g<<i<<" "<<j<<endl;
}
int main()
{
    f>>n;///maxim 57 de piramide
    for(i=1;nr<n;i++)
    {
        for(j=1;j<=i*i;j++)
            f>>a[i][j].nr;
        nr+=i*i;
        nr1++;
    }
    g<<nr1<<endl;
    a[1][1].rez=a[1][1].nr;
    for(i=1;i<nr1;i++)
    {
        int add=0;
        for(j=1;j<=i*i;j++)
            {
                if(!a[i+1][j+add].viz)
                {
                    a[i+1][j+add].viz=1;
                    a[i+1][j+add].rez=a[i][j].rez+a[i+1][j+add].nr;
                    a[i+1][j+add].t.x=i;
                    a[i+1][j+add].t.y=j;
                }
                else if(a[i+1][j+add].rez<a[i][j].rez+a[i+1][j+add].nr)
                {
                    a[i+1][j+add].rez=a[i][j].rez+a[i+1][j+add].nr;
                    a[i+1][j+add].t.x=i;
                    a[i+1][j+add].t.y=j;
                }

                if(!a[i+1][j+add+1].viz)
                {
                    a[i+1][j+add+1].viz=1;
                    a[i+1][j+add+1].rez=a[i][j].rez+a[i+1][j+add+1].nr;
                    a[i+1][j+add+1].t.x=i;
                    a[i+1][j+add+1].t.y=j;
                }
                else if(a[i+1][j+add+1].rez<a[i][j].rez+a[i+1][j+add+1].nr)
                {
                    a[i+1][j+add+1].rez=a[i][j].rez+a[i+1][j+add+1].nr;
                    a[i+1][j+add+1].t.x=i;
                    a[i+1][j+add+1].t.y=j;
                }

                 if(!a[i+1][j+add+1+i].viz)
                {
                    a[i+1][j+add+1+i].viz=1;
                    a[i+1][j+add+1+i].rez=a[i][j].rez+a[i+1][j+add+1+i].nr;
                    a[i+1][j+add+1+i].t.x=i;
                    a[i+1][j+add+1+i].t.y=j;
                }
                else if(a[i+1][j+add+1+i].rez<a[i][j].rez+a[i+1][j+add+1+i].nr)
                {
                    a[i+1][j+add+1+i].rez=a[i][j].rez+a[i+1][j+add+1+i].nr;
                    a[i+1][j+add+1+i].t.x=i;
                    a[i+1][j+add+1+i].t.y=j;
                }

                if(!a[i+1][j+add+2+i].viz)
                {
                    a[i+1][j+add+2+i].viz=1;
                    a[i+1][j+add+2+i].rez=a[i][j].rez+a[i+1][j+add+2+i].nr;
                    a[i+1][j+add+2+i].t.x=i;
                    a[i+1][j+add+2+i].t.y=j;
                }
                else if(a[i+1][j+add+2+i].rez<a[i][j].rez+a[i+1][j+add+1+i].nr)
                {
                    a[i+1][j+add+2+i].rez=a[i][j].rez+a[i+1][j+add+2+i].nr;
                    a[i+1][j+add+2+i].t.x=i;
                    a[i+1][j+add+2+i].t.y=j;
                }

                if(j%i==0) add++;
            }
    }
    int maxim=999999,contor;
    for(j=1;j<=nr1*nr1;j++)
        if(a[nr1][j].rez<maxim) maxim=a[nr1][j].rez,contor=j;
    g<<maxim<<endl;
    drum(nr1,contor);
    for(i=nr1;i>=1;i--)
        g<<afisare[i]<<" ";
    /*for(i=1;i<=nr1;i++){
        for(j=1;j<=i*i;j++)
        g<<a[i][j].t.x<<" "<<a[i][j].t.y<<endl;g<<endl;}*/
    return 0;
}
