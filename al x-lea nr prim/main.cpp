#include <iostream>

using namespace std;
int i,x,n;
int ePrim(int x)
{
    if(x%2==0) return 0;
    for(int d=3;d*d<=x;d+=2) if(x%d==0) return 0;
    return 1;
}
int main()
{
    int i=1,m=0,s;
    cin>>n;
    while(m<n)
        {
            if(ePrim(i))
               {
                   m++;
                   s=i;
                }
            i++;
        }
    cout<<s;
    return 0;
}
