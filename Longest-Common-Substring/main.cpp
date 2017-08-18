#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long int
using namespace std;

typedef vector<long long> vi;
typedef vector< vector<long long> > vii;

template <class T> void print(vector< vector<T> >& M, string& s1, string& s2) {
    for(LL i=0; i<s2.size(); i++) {
        cout<<"\t"<<s2[i];
    } cout<<endl;
    for(LL i=0; i<M.size(); i++) {
        cout<<s1[i]<<"\t";
        for(LL j=0; j<M[0].size(); j++) {
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}

LL lcs(string& s1, string& s2)
{
    vii V(s1.size()+1, vi(s2.size()+1, 0));
    vector< vector<char> > P(s1.size(), vector<char>(s2.size(),'.'));
    LL ix=0, jx=0;

    for(LL i=1; i<=s1.size(); i++) {
        ix=i-1;
        for(LL j=1; j<=s2.size(); j++) {
            jx=j-1;
            if(s1[ix]==s2[jx]) {
                V[i][j] = V[i-1][j-1] + 1;
                P[ix][jx] = '\\';
            } else {
                V[i][j] = max(V[i-1][j], V[i][j-1]);
                if(V[i][j] == V[i-1][j]) {
                    P[ix][jx] = '|';
                } else if(V[i][j] == V[i][j-1]) {
                    P[ix][jx] = '-';
                }
            }
        }
    }
    print(P, s1, s2);
    cout<<endl<<endl;
    return V[s1.size()][s2.size()];
}

int main()
{
    string a="ABPQRCDE", b="APBQRSE";
    cout<<"LCS is "<<lcs(a,b)<<endl<<endl;
    return 0;
}
