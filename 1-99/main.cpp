#include <iostream>

using namespace std;
int a[100],n,s,s1,s2,s3,s4,i,j,cmax;
int main()
{cout<<"Nr de elevi = ";
cin>>n;
for(i=1;i<=n;i++) {cout<<"Elevul "<<i<<" a luat nota ";
cin>>a[i];}
for(i=1;i<=n;i++) if(a[i]<5) s1++;
for(i=1;i<=n;i++) if(a[i]>5) {s2++;
s3=s3+a[i];}
for(i=1;i<=n;i++) if(a[i]==7) s4++;
cmax=a[1];
for(i=2;i<=n;i++) if(a[i]>cmax) cmax=a[i];
j=s3/s2;
cout<<"Au fost obtinute "<<s1<<" note mai mici decat 5, media aritmetica a numerelor peste 5 este "<<j<<" , au fost "<<s4<<" note de 7 si cea mai mare nota este "<<cmax;


    return 0;
}
