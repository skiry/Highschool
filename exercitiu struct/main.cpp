#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;
char s[101], d[202], ca;
unsigned int i, n, j;
int x=rand() % 100;
ifstream f("date.in");
ofstream g("date.out");
int main() {
    f>>s;
    f>>ca;
    if (ca=='C') {
        for (i=0; i<strlen(s); i++) {
            if (strchr("aeiou",s[i])) {
                d[j]='p';
                j++;
            }
            d[j]=s[i];
            j++;
        }
    }
    else {
        for (i=0; i<strlen(s); i++) {
            if (s[i]=='p' && strchr("aeiou",s[i+1]))
                i++;
            d[j]=s[i];
            j++;
        }
    }
    g<<d;g<<x;
    return 0;
}
