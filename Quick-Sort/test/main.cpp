#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#define LL long long
using namespace std;

int main()
{
    vector<int> V = {1,2,3,4,5};
    iter_swap(V.begin(), V.end()-1);
    cout<<V[0]<<V[V.size()-1];
    return 0;
}
