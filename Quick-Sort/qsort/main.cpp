#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#define LL long long
using namespace std;

mt19937 rnd;
uniform_int_distribution<uint64_t> dist(0,1e4);
LL gen() {
    return dist(rnd);
}

template <class T> ostream& operator<<(ostream &out, vector<T> &V)
{
    for(LL i=0; i<V.size(); i++) {
        cout<<V[i]<<" ";
    }
    cout<<endl;
    return out;
}


void qsort(vector<LL>& V, LL start, LL end) { //Both inclusive
    if(start >= end) {
        return;
    }
    LL pindex = gen()%(end-start+1) + start;
    cout<<pindex<<":\t"<<V;
    //Swap pindex and end
    iter_swap(V.begin()+pindex, V.begin()+end);

    //Partition using pindex as pivot
    LL idx=start-1;
    for(LL i=start; i<end; i++) {
        if(V[i] < V[end]) {
            idx++;
            iter_swap(V.begin()+i, V.begin()+idx);
        }
    }

    //put pivot back
    idx++;
    iter_swap(V.begin()+idx, V.begin()+end);
    cout<<start<<" "<<end<<" "<<pindex<<":  "<<V<<endl;
    //subcalls

    qsort(V, start, idx-1);
    cout<<"here";
    qsort(V, idx+1, end);
}

int main() {
    vector<LL> V = {1,4,2,3,7,2,3};
    qsort(V,0,V.size()-1);
    for(LL i=0; i<V.size(); i++) {
        cout<<V[i]<<" ";
    }
    return 0;
}


/*int main()
{
    vector<LL> time;

    for(LL n=1; n<=30; n+=5)
    {
        vector<LL> V(n,0);
        //Average Case:
        generate(V.begin(), V.end(), gen);
        //Best Case:
        /*for(LL i=0; i<n; i++) {
            V[i] = i;
        }
        //Worst Case: use n-i instrad of i
        starttime = getTime();
        for(LL i=0; i<V.size(); i++) {
            cout<<V[i]<<" ";
        }cout<<endl;
        qsort(V, 0, V.size()-1);
        for(LL i=0; i<V.size(); i++) {
            cout<<V[i]<<" ";
        }cout<<endl;
        endtime = getTime();
        time.push_back(endtime-starttime);
        cout<<"Size: "<<n-1<<"\tSorted: "<<(is_sorted(V.begin(), V.end()) == 1? "True\t":"False\t"); printTime(); cout<<endl<<endl;
    }

    return 0;
}
*/
