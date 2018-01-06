#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/**void randChar()
{
char symbol = rand()%126+33;
cout<<symbol<<"\b";
}
void randCharEnd()
{
char symbol = rand()%126+33;
cout<<symbol;
}
int spaceMaker(int a)
{
for(int i =0; i<=a; i++)
cout<<" ";
}
int timeWaster (int a)
{
a = a * 10;
for(int i=0; i<= a; i++)
cout<<" \b";
}
int main()
{int z=10;
system("COLOR 0A");
srand((unsigned)time(NULL));
int lineFeedCtr =0;
int charCtr;
int clearCtr = 0;
char randChar2;
int ctr;
int spaceCtr = 0;
cout<<"E";
timeWaster(20);
cout<<"N";
timeWaster(5);
cout<<"T";
timeWaster(200);
cout<<"E";
timeWaster(200);
cout<<"R ";
timeWaster(200);

cout<<"T";
timeWaster(200);
cout<<"H";
timeWaster(200);
cout<<"E ";
timeWaster(200);
cout<<"M";
timeWaster(200);
cout<<"A";
timeWaster(200);
cout<<"T";
timeWaster(200);
cout<<"R";
timeWaster(200);
cout<<"I";
timeWaster(200);
cout<<"X ";
timeWaster(300);

cout<<"N";
timeWaster(200);
cout<<"O";
timeWaster(200);
cout<<"W";
timeWaster(200);
cout<<".";
timeWaster(300);
cout<<".";
timeWaster(300);
cout<<".";
timeWaster(300);
cout<<".\b\b\b";
timeWaster(1000);


while(z>0)
{
ctr = 0;
charCtr = rand()%10+5;
spaceCtr = rand()%75;
if(clearCtr>=280)
{
clearCtr = 0;
}
while(ctr <= charCtr)
{
spaceMaker(spaceCtr);
ctr++;
randChar2 = static_cast<char>(rand()%126+33);
cout<<randChar2<<endl;
clearCtr++;
for(int b=0; b<=200;b++)
cout<<" \b";
}z--;
}
cout<<"\5"<<" "<<"5";
system("PAUSE");**/
int main()
{



cout<<"\A"<<" "<<"105";
return 0;
}
