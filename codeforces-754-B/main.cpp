#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[6][6];
int ok=0;
int main()
{
    for(int i=1;i<=4;i++)
        f.get(a[i],5),f.get();
//for(int i=0;i<=5;i++)
  //      for(int j=0;j<=5;j++)
    //    if(a[i][j]!='.'||a[i][j]!='x'||a[i][j]!='o')
       //     a[i][j]=0;
    for(int i=1;i<=4;i++)
        for(int j=0;j<=3;j++)
            if(a[i][j]=='x')
    {
        if(a[i+1][j]=='.'&&a[i+2][j]=='x') ok=1;
        if(a[i+1][j+1]=='.'&&a[i+2][j+2]=='x') ok=1;
        if(a[i][j+1]=='.'&&a[i][j+2]=='x') ok=1;
        if(a[i+1][j-1]=='.'&&a[i+2][j-2]=='x') ok=1;
        if(a[i][j-1]=='.'&&a[i][j-2]=='x') ok=1;
        if(a[i-1][j]=='.'&&a[i-2][j]=='x') ok=1;
        if(a[i-1][j+1]=='.'&&a[i-2][j+2]=='x') ok=1;
        if(a[i-1][j-1]=='.'&&a[i-2][j-2]=='x') ok=1;
    }
    if(ok) g<<"YES";
    else g<<"NO";

}
