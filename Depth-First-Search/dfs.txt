#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#define LL long long
#define pb push_back

using namespace std;
typedef vector<long long> vi;
typedef vector< vector<long long> > vii;
typedef vector< vector< vector<long long> > > viii;
const LL inf = 1LL << 60;
//{
template <class T> ostream& operator<<(ostream &out, vector< vector<T> > &V)
{
    for(LL i=0; i<V.size(); i++)
    {   cout<<i<<": ";
        cout<<V[i]<<"\n";
    }
    return out;
}


template <class T> ostream& operator<<(ostream &out, vector<T> &V)
{
    for(LL i=0; i<V.size(); i++)
    {
        if(V[i] >= inf) {
            cout<<"inf ";
        } else {
            cout<<V[i]<<" ";
        }
    }
    cout<<endl;
    return out;
}
//}

void makeGraph(vii& G) {
    G[1].pb(2);
    G[1].pb(7);
    G[2].pb(4);
    G[3].pb(2);
    G[3].pb(5);
    G[4].pb(3);
    G[4].pb(6);
    G[5].pb(4);
    G[6].pb(5);
    G[7].pb(8);
}

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void dfs_visit(vii& G, LL parent, LL& time, vi& d, vi& f, vi& p, vi& colour)
{
    time++;
    d[parent] = time;
    for(LL i=0; i<G[parent].size(); i++) {
        LL child = G[parent][i];
        if(colour[child] == WHITE) {
            colour[child] = GRAY;
            p[child] = parent;
            dfs_visit(G,child,time,d,f,p,colour);
        }
    }
    time++;
    f[parent] = time;
    return;
}

vii dfs(vii& G, LL source)
{
    LL N = G.size();
    vi colour(N,WHITE);
    vi d(N, inf);
    vi f(N, inf);
    vi p(N, -1);

    colour[source] = GRAY;
    LL time = 0;
    d[source] = time;
    dfs_visit(G,source,time,d,f,p,colour);

    vii res(3);
    res[0] = d;
    res[1] = f;
    res[2] = p;
    return res;
}

int main()
{
    LL n = 9;
    vii G(n); //Graph
    makeGraph(G);
    cout<<G;

    vii res = dfs(G,1);
    vi d = res[0];
    vi p = res[2];
    vi f = res[1];
    cout<<"Node  d[node]    p[node]     f[node]\n";
    for(LL i=1; i<n; i++) {
        cout<<"  "<<i<<":\t"<<d[i]<<"\t "<<p[i]<<"           "<<f[i]<<endl;
    }

    return 0;
}
