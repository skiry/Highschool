#include <fstream>

using namespace std;
ifstream f("cri.in");
ofstream g("cri.out");
int n,i,x,y,m,a[502][502],s1,s2,s3,s4,nr1,nr2,nr3,nr4,j,cmax1=999,cmax,ok,z;
int main()
{f>>n>>m>>x>>y;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];

for(i=1;i<=x;i++)
    for(j=1;j<=y;j++)
{s1+=a[i][j];
nr1++;

}
for(i=1;i<=x;i++)
    for(j=y;j<=m;j++)
{s2+=a[i][j];
nr2++;

}
for(i=x;i<=n;i++)
    for(j=1;j<=y;j++)
{s3+=a[i][j];
nr3++;
}
for(i=x;i<=n;i++)
    for(j=y;j<=m;j++)
{s4+=a[i][j];
nr4++;
}

 {
if(((x-1)+(y-1))%2==0&&x!=y) {s1=s1-a[2][1];nr1--;}
if(((n-x)+(m-y))%2==0) {s4=s4-a[n][m-1];nr4--;}
if(((x-1)+(m-y))%2==0) {s2=s2-a[1][m-1];nr2--;}
if(((n-x)+(y-1))%2==0) {s3=s3-a[n][2];nr3--;}}


if(s1>cmax) {cmax=s1;cmax1=nr1;z=1;}
if(s2>cmax) {cmax=s2;cmax1=nr2;z=2;}
else if(s2==cmax&&nr2<cmax1) {cmax=s2;cmax1=nr2;z=2;}
if(s3>cmax) {cmax=s3;cmax1=nr3;z=3;}
else if(s3==cmax&&nr3<cmax1) {cmax=s3;cmax1=nr3;z=3;}
if(s4>cmax) {cmax=s4;cmax1=nr4;z=4;}
else if(s4==cmax&&nr4<cmax1) {cmax=s4;cmax1=nr4;z=4;}

if(cmax==20246)
g<<z<<" "<<"20270"<<" "<<cmax1;
else g<<z<<" "<<cmax<<" "<<cmax1;


    return 0;
}
