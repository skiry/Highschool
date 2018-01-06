/*
    Algoritmul Bellman-Ford.
    Implementarea algoritmului nu difera cu mult de cautarea în lãtime ( bfs )
    Diferenþele sunt
    când scoþi din coadã marchezi nodul ca vizitat
    actualizezi distanþa pânã la vecini chiar daca vecinul e vizitat
    pentru a determina dacã exista cicluri negative se foloseºte un vector cu numarul de aparþii a fiecarui nod. Daca numarul de apariþii depaseºte nr de noduri atunci avem ciclu negativ

*/
/// In dist[i] ai distanta de la 1 la i
/// Bag un nod in coada DOAR DACA NU ESTE VIZITAT
/// La fiecare nod i din coada verific daca dist[i]+cost[i][j] este mai mica decat dist[j]
/// Si daca este asa, updatez dist[j] si il bag in coada daca este nevizitat, altfel nu
/// ATENTIE : Cand lucrezi la un nod, la inceput il devizitezi !!!
#include<fstream>
#define INFINIT 9999999
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    int capat, cost;
    nod *next;
};

nod *G[50002];//graful memorat prin listã de adiacenþã
int n, m,
    d[50002],// d[i] - distanþa minimã de la nodul 1 la nodul i
    v[50002];// vector de vizitaþi

void AddArc(int x, int y, int c)//adaug arc de la x la y de cost c
{
    nod *p = new nod;
    p->capat = y;
    p->cost = c;
    p->next = G[x];
    G[x] = p;
}

void citire()
{
    int i;
    f>>n>>m;
    for(i = 1; i <= m ; i++)
    {
        int x, y, c;
        f>>x>>y>>c;
        AddArc(x, y, c);
    }
}

int bmf(int start)// Bellman-Ford. Funcþia returneazã 0 dacã exitã ciclu negativ ºi 1 dacã nu existã
{
    int aparitii[50002], // aparitii[i] - numarul de apariþii ale nodului i in coadã
        i , j, c;
    nod *st, *dr;//coada

    for(i = 1; i <= n; i++)
    {
        d[i] = INFINIT;
        v[i] = 0;
        aparitii[i]=0;
    }
    st=dr=new nod;
    st->capat=start;
    st->next=NULL;

    d[start] = 0;
    v[start] = 1;
    aparitii[i]++;

    while(st)
    {
        i = st->capat; // i - nodul actual
        v[i] = 0;
        for( nod *p = G[i] ; p!=NULL; p=p->next )
        {
            j = p->capat; // j - nod vecin cu i
            c = p->cost;  // c - costul arcului de la i la j

            if( d[j] > d[i]+c) // dacã costul drumului trebuie actualizat
            {
                d[j] = d[i]+c; // actualizez distanþa indiferent dacã j e vizitat sau nu

                if( v[j]==0 ) // doar dacã j este nevizitat îl adaug în coadã
                {
                    v[j]=1;// ºi il marchez ca vizitat
                    if(aparitii[j] > n) // dacã nr de aparþii a lui j depãseºte n atunci avem ciclu negativ
                        return 0;
                    aparitii[j]++;

                    nod *t=new nod; // adaug pe j în coadã
                    t->capat=j;
                    t->next=NULL;
                    dr->next=t;
                    dr=dr->next;
                }
            }
        }
        nod *t=st;//sterg primul emement din coadã
        st=st->next;
        delete t;
    }

    return 1; // dacã am ajuns la acest punct atunci înseamnã cã nu existã cicluri negative
}

int main()
{
    citire();

    if(bmf(1)==0)
        g<<"Ciclu negativ!";
    else
        for(int i = 2 ; i<=n ; i++ )// afiºez distanþele minime
            g<<d[i]<<" ";
            g<<6/8;
    return 0;
}
