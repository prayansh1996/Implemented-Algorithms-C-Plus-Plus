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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fromeq(x,y,i) for(LL i=x; i<=y; i++)
#define from(x,y,i) for(LL i=x; i<y; i++)
#define rep(x,y) for(LL i=x; i<y; i++)
#define out(arr,len) for(int i=0; i<len; i++) cout<<arr[i]<<" ";
#define LL long long int
#define LD long double
#define all(c) c.begin(), c.end()
#define sz(s) s.size()
#define endl '\n'

using namespace std;
typedef vector<long long> vi;
typedef vector< vector<long long> > vii;
typedef vector< vector< pair<long long, long long> > > vip;
typedef vector< vector< vector<long long> > > viii;
const LL inf = 1LL << 60;
//{
template <class T> ostream& operator<<(ostream &out, pair<T,T>& p)
{
    cout<<"["<<p.first<<","<<p.second<<"] ";
    return out;
}

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
            cout<<V[i]<<" ";//.first<<":"<<V[i].second<<" ";
        }
    }
    cout<<endl;
    return out;
}
//}

void makeGraph(vip& G) {
    G[1].pb({2,10});
    G[1].pb({7,9});
    G[2].pb({4,8});
    G[3].pb({2,7});
    G[3].pb({5,6});
    G[4].pb({3,5});
    G[4].pb({6,4});
    G[5].pb({4,3});
    G[6].pb({5,2});
    G[7].pb({8,1});
}

LL n = 9;
vip G(n); //Graph

bool comparator(const pair<LL,LL>& l, const pair<LL,LL>& r) {
    return G[l.first][l.second].second < G[r.first][r.second].second;
}

vii kruskalsMST(vip& G)
{
    LL n = G.size();
    vii mst(n,vi());
    vi sets(n,0); //Sets
    for(LL i=0; i<n; i++) { sets[i] = i;}

    //Sort all edges in inc order of weights
    vector< pair<LL,LL> > sortedEdges;
    for(LL i=0; i<G.size(); i++) {
        if(G[i].size() != 0) {
            for(LL j=0; j<G[i].size(); j++) {
                pair<LL,LL> p = make_pair(i,j);
                sortedEdges.pb(p);
            }
        }
    }
    sort(all(sortedEdges), comparator);

    //Pick the smallest weight and do a union
    for(LL k=0; k<sortedEdges.size(); k++) {
        pair<LL,LL> p = sortedEdges[k];
        LL i=p.first, j=p.second;
        if(sets[i] != sets[j]) {
            sets[j] = sets[i];
            mst[i].pb(G[i][j].first);
        }
    }
    return mst;
}

int main()
{
    makeGraph(G);
    vii mst = kruskalsMST(G);
    cout<<mst;
    return 0;
}
