#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#define LL long long
using namespace std;

void bsort(vector<LL>& arr) {
    for(LL i=arr.size()-1; i>=0; i--) {
        for(LL j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                LL temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    srand(24);
    vector<LL> time;
    for(LL n=30000; n<=30000; n+=5000)
    {
        vector<LL> V(n,0);
        //Average Case: generate(V.begin(), V.end(), rand);
        //Best Case:
        /*for(LL i=0; i<n; i++) {
            V[i] = i;
        }*/
        //Worst Case: use n-i instrad of i
        starttime = getTime();
        bsort(V);
        endtime = getTime();
        time.push_back(endtime-starttime);
        cout<<"Sorted: "<<(is_sorted(V.begin(), V.end()) == 1? "True":"False")<<endl;
    }
    LL n=0;
    for(int i=0; i<time.size(); i++) {
        cout<<"["<<n<<","<<time[i]<<"], ";
        n += 5000;
    }
    return 0;
}

