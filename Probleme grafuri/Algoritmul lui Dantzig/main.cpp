#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,x,y,z,sel[100],d[100],b[100][100],k,sos,st[100],p,vmin;
int minim(int &k)
{
    int i,j,vmin=9999;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(sel[i]&&!sel[j])
				if(d[i]+a[i][j]<vmin)
				{
					vmin=d[i]+a[i][j];
					k=j;
				}
				return vmin;
}
void dantzig()
{
    int i,j;
	for(i=1;i<n;i++)
	{
		vmin=minim(k);
		if(vmin!=9999)
		{
			sel[k]=1;
			d[k]=vmin;
			for(j=1;j<=n;j++)
				if(sel[j]&&(d[j]+a[j][k]==vmin)) b[j][k]=a[j][k];

		}
	}
}
void drum(int k)
{
    int i,j;
	for(i=1;i<=n;i++)
		if(b[st[k-1]][i]<9999 && !sel[i])
		{
			if(i!=sos)
			{
				sel[i]=1;
				st[k]=i;
				drum(k+1);
				sel[i]=0;
			}
			else
			{
			    for(j=1;j<k;j++) g<<st[j]<<" ";
				g<<sos<<" de cost "<<d[sos];g<<endl;
			}
		}
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j) a[i][j]=b[i][j]=9999;
            else a[i][j]=b[i][j]=0;
    for(i=1;i<=m;i++)
            f>>x>>y>>z,a[x][y]=z;
    f>>p;
    for(i=2;i<=n;i++)
        d[i]=a[p][i];
	sel[p]=1;
	d[p]=0;
	dantzig();
	for(sos=1;sos<=n;sos++)
		if(p!=sos)
		{
		    for(i=1;i<=n;i++) sel[i]=0;
			sel[p]=1;
			st[1]=p;
			drum(2);
        }


    return 0;
}
