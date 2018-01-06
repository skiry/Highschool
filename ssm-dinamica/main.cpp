#include <fstream>
#include <vector>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int n,i,best,poz,minim,maxim,ind,fin,el;
vector <int> s;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>el;
        s.push_back(el);
        if(i>1) s[i-1]+=s[i-2];
    }
    minim=s[0];
    ind=0;
    for(i=1;i<n;i++)
    {
        if(s[i]-minim>maxim) maxim=s[i]-minim,poz=ind,fin=i;
        if(s[i]<minim) minim=s[i],ind=i+1;
    }
    g<<maxim<<" "<<poz+1<<" "<<fin+1;
    return 0;
}
