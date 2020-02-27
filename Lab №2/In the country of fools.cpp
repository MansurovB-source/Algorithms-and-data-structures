// 1604 - In the country of fools

#include <iostream>
#include <vector>

using namespace std;

struct sign {
    int n;
    int id;
};


int main() {
    int n;
    cin >> n;
    vector<sign> signs(10000);
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int max_n = 0;
    int min_n = 0;
    for (int i = 0; i < n; i++) {
        cin >> signs[i].n;
        signs[i].id = i + 1;
        sum += signs[i].n;
        if (signs[i].n >= max) {
            max = signs[i].n;
            max_n = i;
        }
        if (signs[i].n < min && i != max_n) {
            min = signs[i].n;
            min_n = i;
        }
    }

    while (sum > 0) {
        if (signs[max_n].n > 0) {
            cout << signs[max_n].id << " ";
            signs[max_n].n--;
            sum--;
        }
        if (signs[min_n].n > 0) {
            cout << signs[min_n].id << " ";
            signs[min_n].n--;
            sum--;
        }

        max = INT_MIN;
        min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (signs[i].n > 0) {
                if (signs[i].n >= max) {
                    max = signs[i].n;
                    max_n = i;
                }
                if (signs[i].n < min) {
                    min = signs[i].n;
                    min_n = i;
                }
            }
        }
    }

    return 0;
}