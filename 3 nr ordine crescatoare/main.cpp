#include <iostream>

using namespace std;
int a,b,c;
int main()
{cout<<"a= "; cin>>a;
cout<<"b= "; cin>>b;
cout<<"c= "; cin>>c;
if (a<b&&a<c&&b<c) cout<<"Ordinea este aceeasi cum ati introdus-o dumneavoastra ! "<<a<<" "<<b<<" "<<c<<endl;
else if (a<b&&a<c&&c<b) cout<<"Ordinea crescatoare este : "<<a<<" "<<c<<" "<<b<<endl;
else if (c<a&&c<b&&a<b) cout<<"Ordinea crescatoare este : "<<c<<" "<<a<<" "<<b<<endl;
else if (b<a&&b<c&&a<c) cout<<"Ordinea crescatoare este : "<<b<<" "<<a<<" "<<c<<endl;
else if (b<a&&b<c&&c<a) cout<<"Ordinea crescatoare este : "<<b<<" "<<c<<" "<<a<<endl;
else if (c<a&&c<b&&b<c) cout<<"Ordinea crescatoare este : "<<c<<" "<<b<<" "<<a<<endl;
    return 0;
}
