#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
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

pair<vi,vi> bfs(vii& G, LL source)
{
    LL N = G.size();
    vi colour(N,WHITE);
    vi d(N, inf);
    vi p(N, -1);

    colour[source] = GRAY;
    d[source] = 0;
    std::queue<LL> Q;
    Q.push(source);
    while(Q.empty() == false) {
        LL parent = Q.front();
        Q.pop();
        for(LL i=0; i<G[parent].size(); i++) {
            LL child = G[parent][i];
            if (colour[child] == WHITE) {
                colour[child] = GRAY;
                d[child] = d[parent] + 1;
                p[child] = parent;
                Q.push(child);
            }
        }
        colour[parent] = BLACK;
    }
    return make_pair(d,p);
}

int main()
{
    LL n = 9;
    vii G(n); //Graph
    makeGraph(G);
    cout<<G;

    pair<vi,vi> res = bfs(G,1);
    vi d = res.first;
    vi p = res.second;
    LL N = G.size();
    cout<<"Node  d[node]    p[node]\n";
    for(LL i=1; i<N; i++) {
        cout<<"  "<<i<<":\t"<<d[i]<<"         "<<p[i]<<endl;
    }

    return 0;
}
