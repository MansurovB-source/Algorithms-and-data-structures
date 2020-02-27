#include <iostream>

using namespace std;

int main() {
    int t;
    int n;
    int k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int sum = 0;
        cin >> n >> k;
        int cnt = n / k;
        int mod = n % k;

        for (int i = 0; i < mod; i++) {
            n -= cnt + 1;
            sum += n * (cnt + 1);
        }
        for (int i = 0; i < (k - mod); i++) {
            n -= cnt;
            sum += n * cnt;
        }
        cout << sum << endl;
    }
    return 0;
}

