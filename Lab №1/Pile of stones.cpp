
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
    int n;
    int w;
    vector<int> stones(n + 1);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w;
        stones[i] = w;
    }

    int result = INT_MAX;

    for (int i = 0; i < 1 << n; i++) {
        int first = 0;
        int second = 0;
        int cpI = i;
        for (int j = 0; j < n; j++) {
            if (cpI % 2 == 0) {
                second += stones[j];
                // cout << "1 " << stones[j] << endl;
            } else {
                first += stones[j];
                //cout << "2 " << stones[j] << endl;
            }

            cpI = cpI / 2;
        }
        //cout << second << " " << first << endl;
        // cout << "==========" << endl;
        result = min(result, abs(first - second));
    }
    cout << result;

}