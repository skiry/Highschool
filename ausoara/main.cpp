#include <fstream>
#include <vector>
using namespace std;
ifstream f("ausoara.in");
ofstream g("ausoara.out");
int n,m,i,j,a[3][1001],k;
struct scm
{
    int val,ser;
};
vector <int> r;
vector <int> r2;
scm rez[1001][1001];
int main()
{
    f>>n;
    if(n==1)
    {
        f>>m;g<<m<<" ";
        for(i=1;i<=m;i++) f>>a[1][i],g<<a[1][i]<<" ";
    }
    else
    {
        for(i=1;i<=2;i++)
        {
            f>>a[i][0];
            for(j=1;j<=a[i][0];j++) f>>a[i][j];
        }
        for(i=1;i<=a[1][0];i++)
            for(j=1;j<=a[2][0];j++)
            if(a[1][i]==a[2][j]) rez[i][j].val=1+rez[i-1][j-1].val;
            else rez[i][j].val=max(rez[i-1][j].val,rez[i][j-1].val);
        for(i=a[1][0],j=a[2][0];i&&j;)
            {
                if(a[1][i]==a[2][j]) {r.push_back(a[1][i]);i--;j--;}
                else if(a[1][i]!=a[2][j]&&rez[i-1][j].val>=rez[i][j-1].val) i--;
                else j--;
            }
        for(i=0;i<r.size()/2;i++)
            swap(r[i],r[r.size()-1-i]);
        for(k=3;k<=n;k++)
        {
            if(k%2)
            {
            f>>a[1][0];
            for(j=1;j<=a[1][0];j++) f>>a[1][j];
            for(i=1;i<=a[1][0];i++)
                for(j=1;j<=r.size();j++)
                    {if(a[1][i]==r[j-1])
                    {
                        if(rez[i-1][j-1].ser==k) rez[i][j].val=1+rez[i-1][j-1].val;
                        else rez[i][j].val=1;}
                    else
                    {
                        if(rez[i-1][j].ser!=k&&rez[i][j-1].ser==k) rez[i][j].val=rez[i][j-1].val;
                        else if(rez[i-1][j].ser==k&&rez[i][j-1].ser!=k) rez[i][j].val=rez[i-1][j].val;
                        else if(rez[i-1][j].ser==k&&rez[i][j-1].ser==k) rez[i][j].val=max(rez[i-1][j].val,rez[i][j-1].val);
                    }
                    rez[i][j].ser=k;}
            for(i=a[1][0],j=r.size();i&&j;)
            {
                if(a[1][i]==r[j-1]) {r2.push_back(a[1][i]);i--,j--;}
                else if(a[1][i]!=r[j-1]&&rez[i-1][j].val>=rez[i][j-1].val) i--;
                else j--;
            }
            for(i=0;i<r2.size()/2;i++)
            swap(r2[i],r2[r2.size()-1-i]);
            r.erase(r.begin(),r.begin()+r.size());}
            else
            {
            f>>a[1][0];
            for(j=1;j<=a[1][0];j++) f>>a[1][j];
            for(i=1;i<=a[1][0];i++)
                for(j=1;j<=r2.size();j++)
                    {if(a[1][i]==r2[j-1])
                    {
                        if(rez[i-1][j-1].ser==k) rez[i][j].val=1+rez[i-1][j-1].val;
                        else rez[i][j].val=1;}
                    else
                    {
                        if(rez[i-1][j].ser!=k&&rez[i][j-1].ser==k) rez[i][j].val=rez[i][j-1].val;
                        else if(rez[i-1][j].ser==k&&rez[i][j-1].ser!=k) rez[i][j].val=rez[i-1][j].val;
                        else if(rez[i-1][j].ser==k&&rez[i][j-1].ser==k) rez[i][j].val=max(rez[i-1][j].val,rez[i][j-1].val);
                    }
                    rez[i][j].ser=k;}
            for(i=a[1][0],j=r2.size();i&&j;)
            {
                if(a[1][i]==r2[j-1]) {r.push_back(a[1][i]);i--,j--;}
                else if(a[1][i]!=r2[j-1]&&rez[i-1][j].val>=rez[i][j-1].val) i--;
                else j--;
            }
            for(i=0;i<r.size()/2;i++)
            swap(r[i],r[r.size()-1-i]);
            r2.erase(r2.begin(),r2.begin()+r2.size());
            }
        }
    if(r.size()) {g<<r.size()<<" ";for(i=0;i<r.size();i++) g<<r[i]<<" ";}
    else {g<<r2.size()<<" ";for(i=0;i<r2.size();i++) g<<r2[i]<<" ";}
    }
    return 0;
}
