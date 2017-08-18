#include <iostream>
#define LL long long
using namespace std;

LL match(string& pattern, string& text)
{
    LL p = pattern.size(), t = text.size();
    for(LL i=0; i<t-p; i++) {
        LL j;
        for(j=0; j<p; j++) {
            if(pattern[j] != text[i+j]) {
                break;
            }
        }
        if(j==p) {
            return i+1;
        }
    }
    return -1;
}

int main()
{
    string pattern = "abcdef", text = "abcdabcpqrstabcdefghij";
    cout<<"Text:\t "<<text;
    cout<<"\nPattern: "<<pattern;
    cout<<"\n\nMatched at: "<<match(pattern, text)<<endl;
    return 0;
}
