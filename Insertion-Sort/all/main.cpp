#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#define LL long long
using namespace std;

template <class T> ostream& operator<<(ostream &out, vector<T> &V)
{
    for(LL i=0; i<V.size(); i++)
    {
        if(V[i] >= 1e10) {
            cout<<"inf ";
        } else {
            cout<<V[i]<<" ";
        }
    }
    cout<<endl;
    return out;
}

void isort(vector<LL>& arr) {
    for(LL i=1; i<arr.size(); i++) {
        if(arr[i] < arr[i-1]) {
            LL temp = arr[i];
            LL j=-1;
            for(j=i-1; j>=0 && temp < arr[j]; j--) {
                arr[j+1] = arr[j];
            }
            arr[j] = temp;
        }
    }
}

mt19937 rnd;
uniform_int_distribution<uint64_t> dist(0,1e4);
LL gen() {
    return dist(rnd);
}

int main()
{
    vector<LL> time;

    for(LL n=1000; n<=3000; n+=5000)
    {
        vector<LL> V(n,0);
        //Average Case:
        generate(V.begin(), V.end(), gen);
        /*for(LL i=0; i<n; i++) {
            V[i] = dist(rnd);
            cout<<V[i]<<endl;
        }
        //Best Case:
        /*for(LL i=0; i<n; i++) {
            V[i] = i;
        }*/
        //Worst Case: use n-i instrad of i
        starttime = getTime();
        //isort(V);
        std::sort(V.begin(),V.end());
        endtime = getTime();
        time.push_back(endtime-starttime);
        cout<<"Sorted: "<<(is_sorted(V.begin(), V.end()) == 1? "True":"False")<<endl;
        cout<<V;
        //cout<<rand()<<" ";
    }
    LL n=0;
    for(int i=0; i<time.size(); i++) {
        cout<<"["<<n<<","<<time[i]<<"], ";
        n += 5000;
    }
    return 0;
}

