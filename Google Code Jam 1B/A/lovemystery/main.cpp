#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[10001];
int t,i,s;
int main() {
    f>>t;
    for(i=1;i<=t;i++)
        {
        f>>a;
        for(int j=0;j<strlen(a);j++)
            if(a[j]>a[strlen(a)-j-1]) s+=a[j]-a[strlen(a)-j-1];
            g<<s;s=0;g<<endl;
    }
    return 0;
}
