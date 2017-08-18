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

LL MCM(vi& V) {
    vii M(V.size()+1,vi(V.size()+1,inf)), S(V.size()+1,vi(V.size()+1,0));
    LL count = 0;
    LL n = V.size()+1;
    for(LL i=1; i<n; i++) {
        M[i][i] = V[i-1];
        S[i][i] = V[i-1];
         count++;
    }
    for(LL i=1; i<n; i++) {
        for(LL j=i+1; j<n; j++) {
            S[i][j] = S[i][j-1] + V[j-1];
        }
    }

    for(LL l=1; l<=n; l++) {    //No of matrices to be multiplied, i.e range of j
        LL depth = n-l;         //Range till which i will go
        for(LL i=1; i<depth; i++) {
            LL j=i+l;
            for(LL k=i; k<=j; k++) {
                M[i][j] = min(M[i][j], (k<=i ? 0:M[i][k-1]) + (k>=j ? 0:M[k+1][j]) + S[i][j]);
                count++;
            }
        }
    }

    return count;
}

int main() {
    //vi V = {11,36,5,4,2,78,54,2};
    for(LL n=1; n<120; n++) {
        vi V(n,0);
        if(MCM(V) != ((n*n*n + 3*n*n + 2*n)/6.0)) {
            cout<<n<<endl;
        }
    }
    return 0;
}
