#include <iostream>
#include <string.h>
using namespace std;
int n,s,i;
char c[20];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        if(!strcmp(c,"Icosahedron")) s+=20;
        else if(!strcmp(c,"Dodecahedron")) s+=12;
        else if(!strcmp(c,"Octahedron")) s+=8;
        else if(!strcmp(c,"Cube")) s+=6;
        else if(!strcmp(c,"Tetrahedron")) s+=4;
    }
    cout<<s;
    return 0;
}
