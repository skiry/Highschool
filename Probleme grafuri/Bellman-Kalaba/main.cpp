#include<fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],c[100][100];
int pasi,p1,n,m,x,i;
unsigned char t[100][100];
void citire()
{
	int i,j,x,y,z;
	f>>n>>m;  //numarul de noduri
	//initializam matricea costurilor si matricea grafului partial
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
            if(i!=j) a[i][j]=-1;
       else a[i][i]=0;
    for(i=1;i<=m;i++)
	{
		f>>x>>y>>z;
		a[x][y]=z;
	}
}
void initializari()
{
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++) { c[i][j]=-1; t[i][j]=0; }
	for(j=1;j<=n;j++)
	{
		c[j][1]=a[j][x];
		if(c[j][1]!=-1) t[j][1]=j;
	}
}
void kalaba()
{
	int i,j,ok,k;
	k=2;
	do{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]!=-1 && c[j][k-1]!=-1)
					if(c[i][k]<c[j][k-1]+a[i][j])
					{    c[i][k]=c[j][k-1]+a[i][j]; t[i][k]=j;	}
		ok=1;
		for(i=1;i<=n;i++)
			if(c[i][k-1]!=c[i][k]) { ok=0; break; }
		k++;
	}while(!ok);
}
void drum(int x,int y)
{
	g<<x<<" ";
	if(y!=1) drum(t[x][y],y-1);
}
void scrie()
{
    int ok=0;
    for(i=1;i<=n;i++)
        if(i!=x)
	if(c[i][pasi]!=-1)
	{
		while(c[i][pasi]==c[i][pasi-1]) pasi--,ok=1;
		if(!ok) ///daca vrei drumurile de la toate nodurile,scoate randul asta.
        {g<<"drum maxim "<<i<<" -> "<<x<<" prin "<<pasi<<"arce\n";
		g<<"costul "<<c[i][pasi]<<endl;
		drum(i,pasi); g<<x<<endl;}
	}
	else g<<"nu exista\n";
}
int main()
{
	citire();
    f>>x;
    f>>pasi;
	initializari(); kalaba(); scrie();
	return 0;
}
