#include <bits/stdc++.h>

using namespace std;
char sir[256],sir2[20],*p,cuv[10];
int lcuvant,poz ;
int main()
{
    cin.get(sir,255);
    p=strtok(sir,"*");
    strcpy(cuv,p);
    poz=0;
    strcpy(sir+poz,sir+poz+strlen(p)-1);
    while(p)
    {
        if(!strcmp(cuv,p))
        strcpy(sir+poz,sir+poz+strlen(p)-1);
        cout<<p<<" "<<sir<<endl;
        poz+=1+strlen(p);
        p=strtok(NULL,"*");
    }
    cout<<sir;
    return 0;
}
