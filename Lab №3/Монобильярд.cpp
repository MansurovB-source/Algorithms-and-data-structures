#include <iostream>

using namespace std;

int main() {
    int n;
    int x[100001];
    int stack[100001];
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    bool flag = true;
    int pos = 0;
    int sz = 0;
    int s_pos = 0;
    
    while(flag && pos < n) {
        if(sz > 0 && stack[sz - 1] == x[pos]) {
            sz--;
            pos++;
        } else if(s_pos < n) {
            stack[sz] = ++s_pos;
            sz++;
        } else {
            flag = false;
        }
    }
    if(flag == true) {
        cout << "Not a proof" << endl;
    } else {
        cout << "Cheater" << endl;
    }
    return 0;
}