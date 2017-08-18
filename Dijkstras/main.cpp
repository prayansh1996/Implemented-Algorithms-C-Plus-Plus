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
#define pb push_back
#define mp make_pair
#define fromeq(x,y,i) for(LL i=x; i<=y; i++)
#define from(x,y,i) for(LL i=x; i<y; i++)
#define rep(x,y) for(LL i=x; i<y; i++)
#define out(arr,len) for(int i=0; i<len; i++) cout<<arr[i]<<" ";
#define LL long long int
#define all(c) c.begin(), c.end()
#define sz(s) s.size()
//UNDIRECTED GRAPH
using namespace std;
//{
typedef vector<long long> vi;
typedef vector< vector<long long> > vii;
typedef pair<LL,LL> pi;
typedef vector< pair<long long, long long> > vp;
typedef vector< vector< pair<long long, long long> > > vip;
const LL inf = 1LL << 60;
const LL nlyinf = 1LL << 55;

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
    {   cout<<V[i]<<" ";}
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

void add(vip& G, LL a, LL b, LL weight) {
    G[a].push_back(mp(b,weight));
    G[b].push_back(mp(a,weight));
}

void makeGraph(vip& G) {
    add(G,0,1,4);
    add(G,0,7,8);
    add(G,1,2,8);
    add(G,1,7,11);
    add(G,7,8,7);
    add(G,7,6,1);
    add(G,2,8,2);
    add(G,2,5,4);
    add(G,2,3,7);
    add(G,8,6,6);
    add(G,6,5,2);
    add(G,3,5,14);
    add(G,3,4,9);
    add(G,5,4,10);
}

int main()
{
    vip G(9,vp());
    makeGraph(G);
    cout<<G;
}
