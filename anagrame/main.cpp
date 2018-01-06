#include <fstream>
#include <deque>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,n,nr,c[150],ver[150],j;
char a[100];
deque <char> q;
int valid(int k)
{
    for(int j='a';j<='z';j++)
        {//g<<c[j]<<" "<<ver[j]<<"  ";
            if(c[j]!=ver[j]) {//g<<c[j]<<" "<<ver[j]<<" "<<endl;
                    return j;}

        }
        return 1;
}
void backt(int k)
{
    ver[a[k-1]]++;
    if(k==n+1)
        {
            if(valid(k)==1){nr++;//g<<c[valid(k)]<<" "<<ver[valid(k)]<<endl;
            for(int j='a';j<='z';j++)
        {//g<<c[j]<<" "<<ver[j]<<"  ";
            g<<c[j]<<" "<<ver[j];

        }for(int j=0;j<q.size();j++) g<<q[j]<<" ";g<<endl;}}
    else{
        for(int i=0;i<n;i++)
        {
            q.push_back(a[i]);
            backt(k+1);
            q.pop_front();
        }
    }
    ver[a[k]]--;
}
int main()
{
    f.get(a,100);
    n=strlen(a);
    for(i=0;i<n;i++)
        c[(int)a[i]]++;
    backt(1);
    g<<endl;
    g<<nr;
    return 0;
}
