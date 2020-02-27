# include <bits/stdc++.h>

using namespace std;

const double PI =3.141592653589793238463;

struct point{
    double x, y, angle, distant;
    int id;
    void solve(){
        if(x > 0){
            if(y > 0) angle = (atan(y / x) * 180.) / PI;
            else if(y == 0) angle = 0.;
            else angle = ((atan(x / -y) * 180.) / PI) + 270.;
        }
        else if(x == 0){
            if(y > 0) angle = 90.;
            else angle = 270.;
        }
        else {
            if(y > 0) angle = (atan(-x / y) * 180. / PI) + 90.;
            else if(y == 0) angle = 180.;
            else angle = (atan(-y / -x) * 180. / PI) + 180.;
        }
        distant = (x * x) + (y * y);
    }
}
points[30100];
bool compare(point a, point b){
    if(a.angle < b.angle) return 1;
    if((a.angle == b.angle) && (a.distant < b.distant)) return 1;
    return 0;
}
int get_start_point(int n){
    double mx_angle = 360. - points[n].angle + points[1].angle;
    int mx_id = 1;
    for(int i = 2; i <= n; i++){
        if(mx_angle < points[i].angle - points[i - 1].angle){
            mx_id = i;
            mx_angle = points[i].angle - points[i - 1].angle;
        }
    }
    return mx_id;
}
int main(){
    int n;
    cin >> n >> points[0].x >> points[0].y;
    n--;
    for(int i = 1; i <= n; i++){
        cin >> points[i].x >> points[i].y;
        points[i].id = i + 1;
        points[i].x -= points[0].x;
        points[i].y -= points[0].y;
        points[i].solve();
    }
    sort(points + 1, points + 1 + n, compare);
    cout << n + 1 << "\n1\n";
    int id = get_start_point(n);
    for(int i = id; i <= n; i++){
        cout << points[i].id << '\n';
    }
    for(int i = 1; i < id; i++){
        cout << points[i].id << '\n';
    }
}