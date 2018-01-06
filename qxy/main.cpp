/**#include <fstream>

using namespace std;
ifstream f("qxy.in");
ofstream g("qxy.out");
int n,a[10001],i,j,nr;
struct intrebari
{
    int x,y,z,w,nr1;
};

intrebari q[100001];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    f>>nr;
    for(i=1;i<=nr;i++)
        f>>q[i].x>>q[i].y>>q[i].z>>q[i].w;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=nr;j++)
            if(i>=q[j].x&&i<=q[j].y&&a[i]>=q[j].z&&a[i]<=q[j].w)
                q[j].nr1++;
    }
    for(i=1;i<=nr;i++)
        g<<q[i].nr1<<endl;
    return 0;
}*/

#include<fstream>
#include<math.h>
#define Nmax 10005
#define Vmax 1005
#define Kmax 105
using namespace std;
ifstream f("qxy.in");
ofstream g("qxy.out");
int N,Q,V[Kmax][Vmax],W[Nmax],L,k,a,b,c,d,B1,B2,S=0;
void citire()
{
    f>>N;
    for(int i=1;i<=N;++i) f>>W[i];
    k=sqrt(N);
    k++;
    int p=0,nr=0;
    for(int i=1;i<=N;i+=k)
    {
        p++;
        for(int j=0;j<=1005;++j)
        {
            nr=0;
            for(int h=i;h<i+k&&h<=N;h++) if(j>=W[h]) nr++;
            V[p][j]=V[p-1][j]+nr;
        }
    }
}
int getleft(int B,int x)
{
    int nr=0;
    for(int i=x;i<=B*k&&i<=N;i++) if(W[i]>=c&&W[i]<=d) nr++;
    return nr;
}
int getright(int B,int x)
{
    int nr=0;
    for(int i=x;i>=(B-1)*k+1&&i>=0;i--) if(W[i]>=c&&W[i]<=d) nr++;
    return nr;
}
int main()
{
    citire();
    f>>Q;
    for(int i=1;i<=Q;++i)
    {
        f>>a>>b>>c>>d;
        S=0;
        B1=(a-1)/k+1;
        B2=(b-1)/k+1;
        if(B1==B2) { for(int i=a;i<=b;++i) if(W[i]>=c&&W[i]<=d) S++; }
        else
        {
        S+=getleft(B1,a);
        S+=getright(B2,b);
        B1++; B2--;
        if(B1<=B2) S+=V[B2][d]+V[B1-1][c-1]-V[B2][c-1]-V[B1-1][d];
        }
        g<<S<<'\n';
    }
    return 0;
}
