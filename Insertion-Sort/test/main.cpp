#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#define LL long long
using namespace std;

static std::mt19937 rnd;
static uint32_t rndInt(uint32_t min, uint32_t max) {
    return std::uniform_int_distribution<uint32_t>(min,max)(rnd);
}

int main()
{
    for(int i=0; i<1000; i++) {
        cout<<rndInt(0,10000)<<endl;
    }
    return 0;
}
