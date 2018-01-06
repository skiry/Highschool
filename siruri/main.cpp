#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("siruri.in");
ofstream g("siruri.out");
int n,m,i,j,el,k,p,q,maxim,ind,fin,it;
vector <int> a;
vector <int> b;
int main()
{
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>el;
        a.push_back(el);
        if(i>0) a[i-1]-=el;
    }
    f>>m;
    for(i=0;i<m;i++)
    {
        f>>el;
        b.push_back(el);
        if(i>0) b[i-1]-=el;
    }
    //for(i=0;i<n-1;i++) g<<a[i]<<" ";g<<endl;
    //for(i=0;i<m-1;i++) g<<b[i]<<" ";
    for(i=0;i<n-1;i++)
    {
        it=m;
        for(j=0;j<m-1&&it==m;j++) if(b[j]==(a[i]*(-1))) it=j;
        k=0;
        if(it!=m)
        {
            p=i;
            q=it;
            for(j=it;a[i]==b[j]*(-1)&&j<m-1&&i<n-1;j++,i++) k++;
            if(k>maxim) maxim=k,ind=p,fin=q;
        }
    }
    g<<maxim+1<<" "<<ind+1<<" "<<fin+1;
    return 0;
}
