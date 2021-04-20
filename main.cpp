#include <iostream>
#include <fstream>
#include <cstring>
#define DMAX 176

using namespace std;

ifstream f("alee.in");
ofstream g("alee.out");

void bordare(int L[][DMAX],int n) {
    for(int i=0;i<=n+1;i++)
        L[0][i]=L[n+1][i]=L[i][0]=L[i][n+1]=-1;
}

struct pozitie {
int lin,col;
}p1,p2,p,v,c[DMAX*DMAX];

int main()
{
    int dx[]={0,1,0,-1},dy[]={1,0,-1,0},n,NrC,x,y,NrDir=4,prim=0,ultim=0,a[DMAX][DMAX];
    f >> n >> NrC;
    memset(a,0,sizeof(a));
    for(int i=1;i<=NrC;i++) {
        f >> x >> y;
        a[x][y]=-1;
    }

    f >> p1.lin >> p1.col >> p2.lin >> p2.col;
    a[p1.lin][p1.col]=1;
    c[0]=p1;
    while(prim<=ultim and a[p2.lin][p2.col]==0) {
        p=c[prim];
        prim++;
        for(int k=0;k<NrDir;k++){
            v.lin=p.lin+dx[k];
	        v.col=p.col+dy[k];
	        if(a[v.lin][v.col]==0) {
	            a[v.lin][v.col]=a[p.lin][p.col]+1;
	            ultim++;
	            c[ultim]=v;
	        }
        }
    }
    g << a[p2.lin][p2.col];
    return 0;

}
