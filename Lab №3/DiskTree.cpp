#include <iostream>
#include <map>
#include <sstream>

using namespace std;

struct Directory {
    map<string, Directory*> sub_directory;
};

Directory roots[5001];
int root_dir_num = 1, n;

Directory *new_dir(Directory* parent, const string& child_dir) {
    auto &d = parent ->sub_directory[child_dir];
    cout << d << " " << &d;
    return d;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str, substr;
        cin >> str;
        Directory *dir = &roots[0];
        stringstream s(str);

        while(getline(s, substr, '\\')) {
            dir = new_dir(dir, substr);
        }
    }

    return 0;
}