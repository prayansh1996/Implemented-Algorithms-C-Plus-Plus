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
#define n2 10

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
    {   cout<<V[i]<<"\n";}
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
void print(LL,LL,LL);

LL rec=0, mem=0;

LL recurse(vector<char>& V,vi& freq, LL l, LL r, LL depth = 0) { //For first iteration, l = 0, r = index of last element, depth = 0

    if(l > r) {
        return 0;
    } //print(depth,l,r);
    rec++;
    if(l == r) {
        return (depth+1)*freq[l];
    }

    LL ans = inf;
    for(LL i=l; i<=r; i++) {
        LL sum = (depth+1)*freq[i];
        sum += recurse(V,freq,l,i-1,depth+1) + recurse(V,freq,i+1,r,depth+1);
        ans = min(ans, sum);
    }
    return ans;
}

void print(LL depth, LL l, LL r) {
    cout<<endl<<"\\_";
    while(depth--) {
        cout<<".";
    }
    cout<<l<<" "<<r;
}

LL memoize(LL OST[n2][n2][n2], vector<char>& V, vi& freq, LL l, LL r, LL depth = 0) { //For first iteration, l = 0, r = index of last element, depth = 0

    if(l > r) {
        return 0;
    }
    //print(depth,l,r);
    mem++;
    if(OST[depth][l][r] != -1) {
        return OST[depth][l][r];
    }

    if(l == r) {
        OST[depth][l][r] = (depth+1)*freq[l];
        return OST[depth][l][r];
    }

    LL ans = inf;
    for(LL i=l; i<=r; i++) {
        LL sum = (depth+1)*freq[i];
        sum += memoize(OST,V,freq,l,i-1,depth+1) + memoize(OST,V,freq,i+1,r,depth+1);
        ans = min(ans, sum);
    }
    OST[depth][l][r] = ans;
    return ans;
}
//Memoization:

int main() {
    vector<char> V = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    vi freq = {34,8,50,7,61,23,45,123,12,87};
    LL n = freq.size()-1;
    LL OST[n2][n2][n2];
    fromeq(0,n,i) {
        fromeq(0,n,j) {
            fromeq(0,n,k) {
                OST[i][j][k] = -1;
            }
        }
    }
    //cout<<OST[0][0][4];
    cout<<recurse(V,freq,0,n,0)<<" ";cout<<rec<<endl;
    cout<<memoize(OST,V,freq,0,n,0)<<" ";cout<<mem<<endl;

    fromeq(0,n,i) {
        fromeq(0,n,j) {
            fromeq(0,n,k) {
                cout<<OST[i][j][k];
                cout<<"\t";
            } cout<<endl;
        } cout<<endl<<endl;
    }

    return 0;
}
