#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int s1[20001][50],s2[20001][50],i,j;
int main()
{
    int n=20000;
    for(i=1;i<=n;i++)
        f.getline(s1[i],50);
     for(i=1;i<=n;i++)
    {
        int ok=0;
        f.getline(s2[i],50);
        for(j=0;j<strlen(s1);j++)
            if(s1[i][j]!=s2[i][j]) ok=1;
        if(ok) g<<i-20000<<endl;
    }

    return 0;
}
