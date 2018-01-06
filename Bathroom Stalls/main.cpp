#include <fstream>
#include <queue>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
struct coada
{
    long long ls,ld,st,dr;
}el;
struct cmp
{
    bool operator() (const coada &a, const coada &b)
    {
        long long suma1=(a.st+a.dr)/2;
        long long suma2=(b.st+b.dr)/2;
        long long dif1=suma1-a.ls-1;
        long long dif2=a.ld-suma1-1;
        long long dif3=suma2-b.ls-1;
        long long dif4=b.ld-suma2-1;
        long long minim1=min(dif1,dif2);
        long long minim2=min(dif3,dif4);
        if(minim1!=minim2) return minim1<minim2;
        else return max(dif1,dif2)<max(dif3,dif4);
    }
};
long long nr,i,n,k,t,j;
priority_queue < coada, vector <coada>, cmp> q;
int main()
{
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n>>k;
        cout<<"Case #"<<j<<": ";
        if(k>=n/2+5) cout<<"0 0";///FALSE
        else
        {
            while(q.size()) q.pop();
            el.ls=0;
            el.ld=n+1;
            el.st=1;
            el.dr=n;
            q.push(el);
            for(nr=1;nr<k;nr++)
            {
                coada actual=q.top();
                if(actual.st<actual.dr)
                {
                    long long partial=(actual.st+actual.dr)/2;
                    el.ls=actual.ls;
                    el.ld=partial;
                    el.st=actual.st;
                    el.dr=partial-1;
                    q.push(el);
                    el.ls=partial;
                    el.ld=actual.ld;
                    el.st=partial+1;
                    el.dr=actual.dr;
                    q.push(el);
                }
                q.pop();
            }
            long long s=(q.top().st+q.top().dr)/2;
            long long diff1=s-q.top().ls-1;
            long long diff2=q.top().ld-s-1;
            if(diff1<diff2) cout<<diff2<<" "<<diff1;
            else cout<<diff1<<" "<<diff2;
        }
            cout<<'\n';
    }
    return 0;
}
