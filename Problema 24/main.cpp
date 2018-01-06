#include <iostream>
#include <string.h>
using namespace std;
char a[250],i;
int main()
{
    cin.getline(a,250);
    for(i=1;i<strlen(a);i++)
        if(a[i]>='a'&&a[i]<='z'&&a[i]==a[i-1]) cout<<a[i]<<a[i]<<'\n';
    return 0;
}
