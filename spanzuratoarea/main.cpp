#include <iostream>
#include <string.h>
using namespace std;
char a[100],b[100],l;
int i,nr,ok,ok1;
int main()
{
   cin.get(a,100);
   for(i=0;i<strlen(a);i++) b[i]='*';
   cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
   cout<<b<<endl<<"Numarul de incercari = ";
   cin>>nr;
   i=1;
   while(i<=nr)
   {
       ok=ok1=0;
       cout<<"Cuvantul tau este : "<<b<<". Introdu o litera : ";
       cin>>l;
       for(int j=0;j<strlen(a);j++)
       {
           if(a[j]==l) b[j]=l, ok=1;
           if(b[j]=='*') ok1++;
       }
       if(!ok) cout<<"Din pacate ai gresit. Mai ai "<<nr-i<<" incercari!"<<endl, i++;
       if(i==nr) cout<<"Cuvantul era "<<a;
       if(!ok1) cout<<endl<<"BRAVO!!! Cuvantul era "<<a, i=nr+1;
   }
    return 0;
}
