#include <fstream>
#include <string.h>
using namespace std;
ifstream f("blis.in");
ofstream g("blis.out");
int k,i,j,t[1001],a[1001][1001],d[1001];
unsigned long nr=0,maxim=0;
char v[1001];
int main()
{
    f>>k;
    f.get();
    f.getline(v,100001);
    for(i=1;i<=strlen(v)-k;i++)
      {nr=0;
          for(int j=i;j<=i+k-1;j++)
          nr=(nr<<1)|(v[j]-'0');

        if(nr>maxim) maxim=nr;
    }
    for(i=0;i<strlen(v);i++)
        t[i+1]=v[i]-'0';
    g<<maxim<<endl;
    int n=strlen(v);
    a[0][1] = 100001;
	d[0] = 1;
	a[1][1] = t[1];
	d[1] = 1;

	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= d[i - 1]; j++)
			a[i][j] = a[i - 1][j];
		d[i] = d[i - 1];
		a[i][d[i] + 1] = 100001;
		int x = 0;
		for (j = i; (j >= 1) && (j >= i - k + 1); j--)
		{
			x = x | (t[j] << (i - j));
			int p=1;
			while(p<=d[j-1]&&x>a[j-1][p]) p++;
			if (p <= d[j-1])
			{
				if (x < a[i][p])
					a[i][p] = x;
			}
			else
			{
				if (p > d[i])
				{
					d[i] = p;
					a[i][p] = x;
				}
				else if (x < a[i][p]) a[i][p] = x;
			}
		}
	}
	g<<d[n];
    return 0;
}
