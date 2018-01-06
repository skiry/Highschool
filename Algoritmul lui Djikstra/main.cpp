#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s[100],t[100],c,x,y,p,vf;
void drum(int i)
{if(t[i])
	drum(t[i]);
 g<<i<<" ";
}
int main()
{
   f>>n>>m;
   for(i=1;i<=m;i++)
    f>>x>>y>>c,a[x][y]=a[y][x]=c;

   f>>p;
   for(i=1;i<=n;i++) if(i!=p) s[i]=1;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j&&!a[i][j])
                a[i][j]=99999;

   for(i=1;i<=n;i++)
    if(a[p][i]!=99999&&a[p][i]) t[i]=p;

   for(i=1;i<n;i++)
   {
       m=99999;
       for(j=1;j<=n;j++)
        if(s[j]&&a[p][j]<m) m=a[p][j],vf=j;
       s[vf]=0;
       for(j=1;j<=n;j++)
        if(s[j]&&a[p][j]>(a[p][vf]+a[vf][j]))
        a[p][j]=a[p][vf]+a[vf][j],t[j]=vf;
   }



   for(i=1;i<=n;i++)
    if(i!=p&&t[i])
    g<<"Drumul de la "<<p<<" la "<<i<<" este: ",drum(i),g<<" si are lungimea "<<a[p][i]<<endl;
   else g<<"Nu exista drum de la "<<p<<" la "<<i<<endl;
   g<<"   ";for(i=1;i<=11;i++)
    g<<i<<" ";
    g<<endl<<endl;

for(i=1;i<=11;i++){g<<i<<"  ";
    for(j=1;j<=11;j++)

    g<<(i*j)%12<<" ";g<<endl;}
    return 0;
}
