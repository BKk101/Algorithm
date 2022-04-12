#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case, temp;
    vector <int> input;
    cin>>Case;
    for(int i=0;i<Case;i++){
        cin>>temp;
        input.push_back(temp);
        cin>>temp;
        input.push_back(temp);
    }
    for(int i=0;i<Case;i++){
        cout<<input[2*i] + input[2*i+1]<<endl;
    }
    return 0;
}
