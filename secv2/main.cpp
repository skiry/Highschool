#include <fstream>
#include <vector>
#include <deque>
using namespace std;
ifstream f("secv2.in");
ofstream g("secv2.out");
int n,k,i,ind,el,maxim,poz,fin;
struct vmin
{
    int v,cnt,ind;
};
vmin p;
vector <int> s;
deque <vmin> minim;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>el;
        s.push_back(el);
        if(i>1) s[i-1]+=s[i-2];
    }
    for(i=0;i<k;i++)
        if(!minim.size()||s[i]<minim[0].v)
        {
            if(minim.size()) while(minim.size()) minim.pop_front();
            p.v=s[i];
            p.ind=i+1;
            minim.push_back(p);
        }
    minim[0].cnt=k-i-1;
    for(i=k;i<n;i++)
    {
        if(minim.size()>1)
        {
            for(int j=minim.size()-1;j;j--)
                minim[j].cnt++;
            if(minim[0].cnt==k) minim.pop_front();
        }
        if(minim[minim.size()-1].v>s[i])
        {
            p.v=s[i];
            p.ind=i+1;
            p.cnt=0;
            minim.push_back(p);
        }
        if(s[i]-minim[0].v>maxim) maxim=s[i]-minim[0].v,poz=minim[0].ind,fin=i;
    }
    g<<poz+1<<" "<<fin+1<<" "<<maxim;
    return 0;
}
