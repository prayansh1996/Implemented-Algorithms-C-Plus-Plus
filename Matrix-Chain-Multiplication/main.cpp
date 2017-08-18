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

typedef vector<long long> vi;
typedef vector< vector<long long> > vii;
typedef pair<LL,LL> pi;
const LL inf = 1LL << 60;

void print(vii M) {
    for(LL i=1; i<M.size(); i++) {
        for(LL j=0; j<M[0].size(); j++) {
            if(j < i) {
                cout<<"\t";
            } else {
                cout<<M[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}

LL MCM(LL n, vi V) {
    vii M(n+1,vi(n+1,inf));
    fromeq(0,n,i) {
        M[i][i] = 0;
    }
    LL count = 0;
    for(LL l = 1; l<=n; l++) {  //No of matrices to be multiplied, i.e range of j
        LL depth = n-l; //Range till which i will go
        for(LL i=1; i<=depth; i++) {
            LL j=i+l;
            for(LL k=i; k<j; k++) {
                M[i][j] = min(M[i][j], M[i][k] + M[k+1][j] + V[i-1]*V[k]*V[j]);
                count++;
            }
        }
    }
    cout<<count;
    //print(M);
    return M[1][n];
}

int main() {
    vi V = {11,36,5,4,2,78,54,2};
    LL n = V.size()-1; //No. of matrices
    cout<<"Minimum no. of multiplications needed: "<<MCM(n,V);
    return 0;
}
