#include <fstream>
#include <deque>
#include <vector>
using namespace std;
ifstream f("colors.in");
ofstream g("colors.out");
int n,i,rez=1,nr;
char p;
deque <char> q;
deque <char> in;
vector <int> viz;
int contopire(int a,int b)
{
    if(q[a]!='Z'&&q[b]!='Z')
    {g<<"c1"<<q[a]<<" "<<q[b]<<endl;
        if(q[a]=='V'&&q[b]=='V') q[b]='G';
        else if(q[a]=='G'&&q[b]=='G') q[b]='V';
        q[a]='Z';
        g<<"c2"<<q[a]<<" "<<q[b]<<endl;
        return 1;
    }
    return 0;
}
void backt()
{
    nr++;g<<nr<<" "<<q[0]<<endl;
    if(nr==n&&q[0]=='V') rez++;
    for(i=1;i<n;i++)
        if(!viz[i])
    {
        int j=i-1;
        while(contopire(i,j)==0&&j>=0) j--;
        g<<i<<" "<<" "<<j<<endl;
        viz[i]=1;
        //g<<q[i]<<" "<<q[j]<<endl;
        backt();
        viz[i]=0;
        g<<q[i]<<" "<<q[j]<<"  "<<in[i]<<" "<<in[j]<<endl;
        q[j]=in[j];
        q[i]=in[i];
    }
    nr--;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>p,q.push_back(p),in.push_back(p),viz.push_back(0);
    //backt();
    for(i=1;i<n-1;i++) rez*=i,rez%=666013;
    i=rez/2;
    rez*=(n-1);
    rez%=666013;
    g<<rez/2-i;
    return 0;
}
