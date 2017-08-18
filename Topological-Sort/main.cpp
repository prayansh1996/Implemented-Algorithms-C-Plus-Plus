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
//{
typedef vector<long long> vi;
typedef vector< vector<long long> > vii;
typedef vector< vector< vector<long long> > > viii;
typedef pair<LL,LL> pi;
const LL inf = 1LL << 60;
const LL nlyinf = 1LL << 55;

struct comparator
{
  bool operator()(const pair<LL,LL>& l, const pair<LL,LL>& r) const
  {
     //swap only if they're unequal to avoid infinite recursion
     if (l.first != l.second)
     {
         //swap elements, considering your special case
          if (l.first == r.second && l.second == r.first)
             return l < pair<LL,LL>(r.second, r.first); //call again!
     }

    //actual comparison is done here
    if ( l.first != r.first )
       return l.first < r.first;
    else
       return l.second < r.second;
  }
};

template <class T> ostream& operator<<(ostream &out, vector<T> &V)
{
    for(LL i=0; i<V.size(); i++)
    {
        if(V[i] >= nlyinf) {
            cout<<"inf ";
        } else {
            cout<<V[i]<<" ";
        }
    }
    cout<<endl;
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

template <class T> ostream& operator<<(ostream &out, pair<T,T>& p)
{
    cout<<"["<<p.first<<","<<p.second<<"] ";
    return out;
}

template <class T> void print(vector<T> &V, LL n)
{
    for(LL i=0; i<n; i++)
    {   cout<<V[i]<<" ";}
    cout<<endl;
}

template <> void print<LL>(vector<LL> &V, LL n)
{
    for(LL i=0; i<n; i++) {
        if(V[i] >= nlyinf) {
            cout<<"inf";
        } else {
            cout<<V[i];
        }
        cout<<" ";
    }
    cout<<endl;
}
//}
void printDependencyList(unordered_map<LL, unordered_set<LL> >& M)
{
    for(auto ix: M) {
        cout<<ix.first<<": ";
        for(auto jx: ix.second) {
            cout<<jx<<" ";
        }
        cout<<endl;
    }
}

void makeGraph(vii& G) {
    G[1].pb(2);
    G[1].pb(5);
    G[1].pb(7);
    G[3].pb(7);
    G[4].pb(2);
    G[4].pb(6);
    G[4].pb(7);
    G[5].pb(4);
    G[5].pb(7);
}

void makeDependencies(vii& G, unordered_map< LL, unordered_set<LL> >& M)
{
    //If M[4] has 1,2,3 we can say that 1,2 and 3 link to 4
    //If M[4] has length 0, no nodes link to 4
    //If M has no element named 4, it doesn;t exist in graph
    for(LL i=1; i<G.size(); i++) {
        for(LL j=0; j<G[i].size(); j++) {
            M[G[i][j]].insert(i);
        }
    }
}

bool compare(unordered_set<LL>& A, unordered_set<LL>& S)
{
    bool equals = true;
    for(auto it: A) {
        if(S.find(it) == S.end()) {
            equals = false;
        }
    }
    return equals;
}

void dfs(vii& G, unordered_map<LL, unordered_set<LL> >& M, LL node,  vi& V, unordered_set<LL>& S)
{
    //If all the nodes that link to the current node haven't been visited
    if(compare(M[node],S) == false) {
        return;
    }

    //DFS
    V.push_back(node);
    S.insert(node);
    for(LL i=0; i<G[node].size(); i++) {
        dfs(G,M,G[node][i],V,S);
    }
}

vector<LL> topologicalSort(vii& G, unordered_map<LL, unordered_set<LL> >& M)
{
    vi V;
    unordered_set<LL> S; //Set of nodes visited
    for(LL i=1; i<G.size(); i++) {
        if(M[i].size() == 0) {  //If no node link to current node
            dfs(G, M, i, V, S);
        }
    }
    return V;
}

int main()
{
    LL n = 8;
    vii G(n); //Graph
    makeGraph(G);
    unordered_map< LL, unordered_set<LL> >  M; //Links to each node
    makeDependencies(G,M);
    vi V = topologicalSort(G,M);
    cout<<V;
    return 0;
}
