#include <fstream>
#include <string.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
ifstream f("missing.in");
ofstream g("missing.out");
int n,m,i,j,dictionar[100001][30],actual,dist[30],cuvprezent,k,nr,finally;
char cuvant[41];
vector <string> lungime[41];
vector <int> contorlungime[41];
deque <int> q;
deque <int>::iterator it;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>cuvant;
        for(j=0;j<strlen(cuvant);j++)
            dictionar[i][cuvant[j]-'a']++;
        lungime[strlen(cuvant)].push_back(cuvant);
        contorlungime[strlen(cuvant)].push_back(i);
    }
    for(i=1;i<=m;i++)
    {
        f>>cuvant;
        f.get();
        actual=strlen(cuvant)+1;
        if(!lungime[actual].size()) g<<"-1"<<'\n';
        else
        {
            for(j=0;j<strlen(cuvant);j++)
            {
                int litera=cuvant[j]-'a';
                dist[litera]++;
                q.push_back(litera);
            }
            sort(q.begin(),q.end());
            it=unique(q.begin(),q.end());
            q.resize(distance(q.begin(),it));
            finally=-1;
            for(j=0;j<contorlungime[actual].size()&&finally==-1;j++)
            {
                cuvprezent=contorlungime[actual][j];
                int nr=0;
                for(k=0;k<q.size()&&nr<2;k++)
                {
                    if(dist[q[k]]<dictionar[cuvprezent][q[k]]) nr+=dictionar[cuvprezent][q[k]]-dist[q[k]];
                    else if(dist[q[k]]>dictionar[cuvprezent][q[k]]) nr=5;
                }
                if(nr==1||nr==0) finally=j;
            }
            if(finally!=-1) g<<lungime[actual][finally]<<'\n';
            else g<<"-1"<<'\n';
            while(q.size())
            {
                dist[q.front()]=0;
                q.pop_front();
            }
        }
    }
    return 0;
}
