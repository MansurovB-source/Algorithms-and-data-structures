# include <iostream>

using namespace std;

int x0; 
int y0; 
int point;
int table[520][520];
int n;

void ShapeType(int x, int y, int type){
    if(type == 1){
        point++;
        table[x][y] = table[x][y + 1] = table[x + 1][y] = point;
    }
    else if(type == 2){
        point++;
        table[x][y] = table[x][y + 1] = table[x + 1][y + 1] = point;
    }
    else if(type == 3){
        point++;
        table[x][y + 1] = table[x + 1][y] = table[x + 1][y + 1] = point;
    }
    else if(type == 4){
        point++;
        table[x][y] = table[x + 1][y] = table[x + 1][y + 1] = point;
    }
}

void draw(int x, int y, int det, int type){
    if(det == 1){
        if((x0 == x) && (y0 == y)){
            ShapeType(x,y,3);
        }
        else if((x0 == x) && (y0 == y + 1)){
            ShapeType(x,y,4);
        }
        else if((x0 == x + 1) && (y0 == y)){
            ShapeType(x,y,2);
        }
        else if((x0 == x + 1) && (y0 == y + 1)){
            point++;
            table[x][y] = table[x][y + 1] = table[x + 1][y] = point;
        }
        else if(type == 1){
            ShapeType(x,y,1);
        }
        else if(type == 2){
            ShapeType(x,y,2);
        }
        else if(type == 3){
            ShapeType(x,y,3);
        }
        else if(type == 4){
            ShapeType(x,y,4);
        }
    }
    else {
        int d2 = det / 2;
        if(type == 0){
            /// 1
            if((x <= x0) && (x0 <= x + d2) && (y <= y0) && (y0 <= y + d2)){
                draw(x, y, d2, 0);
                draw(x, y + d2 + 1, d2, 2);
                draw(x + d2 + 1, y + d2 + 1, d2, 3);
                draw(x + d2 + 1, y, d2, 4);
                point++;
                table[x + d2 + 1][y + d2] = point;
                table[x + d2 + 1][y + d2 + 1] = point;
                table[x + d2][y + d2 + 1] = point;
            }
                /// 2
            else if((x <= x0) && (x0 <= x + d2) && (y + d2 + 1<= y0) && (y0 <= y + det)){
                draw(x, y, d2, 1);
                draw(x, y + d2 + 1, d2, 0);
                draw(x + d2 + 1, y + d2 + 1, d2, 3);
                draw(x + d2 + 1, y, d2, 4);
                point++;
                table[x + d2][y + d2] = point;
                table[x + d2 + 1][y + d2] = point;
                table[x + d2 + 1][y + d2 + 1] = point;
            }
                /// 3
            else if((x + d2 + 1 <= x0) && (x0 <= x + det) && (y + d2 + 1 <= y0) && (y0 <= y + det)){
                draw(x, y, d2, 1);
                draw(x, y + d2 + 1, d2, 2);
                draw(x + d2 + 1, y + d2 + 1, d2, 0);
                draw(x + d2 + 1, y, d2, 4);
                point++;
                table[x + d2][y + d2] = point;
                table[x + d2 + 1][y + d2] = point;
                table[x + d2][y + d2 + 1] = point;
            }
                /// 4
            else if((x + d2 + 1 <= x0) && (x0 <= x + det) && (y <= y0) && (y0 <= y + d2)){
                draw(x, y, d2, 1);
                draw(x, y + d2 + 1, d2, 2);
                draw(x + d2 + 1, y + d2 + 1, d2, 3);
                draw(x + d2 + 1, y, d2, 0);
                point++;
                table[x + d2][y + d2] = point;
                table[x + d2][y + d2 + 1] = point;
                table[x + d2 + 1][y + d2 + 1] = point;
            }
        }
        else if(type == 1){
            /// term 3
            draw(x, y, d2, 1);
            draw(x, y + d2 + 1, d2, 2);
            draw(x + d2 + 1, y + d2 + 1, d2, 1);
            draw(x + d2 + 1, y, d2, 4);
            point++;
            table[x + d2][y + d2] = point;
            table[x + d2 + 1][y + d2] = point;
            table[x + d2][y + d2 + 1] = point;
        }
        else if(type == 2){
            /// term 4
            draw(x, y, d2, 1);
            draw(x, y + d2 + 1, d2, 2);
            draw(x + d2 + 1, y + d2 + 1, d2, 3);
            draw(x + d2 + 1, y, d2, 2);
            point++;
            table[x + d2][y + d2] = point;
            table[x + d2][y + d2 + 1] = point;
            table[x + d2 + 1][y + d2 + 1] = point;
        }
        else if(type == 3){
            /// term 1
            draw(x, y, d2, 3);
            draw(x, y + d2 + 1, d2, 2);
            draw(x + d2 + 1, y + d2 + 1, d2, 3);
            draw(x + d2 + 1, y, d2, 4);
            point++;
            table[x + d2 + 1][y + d2] = point;
            table[x + d2 + 1][y + d2 + 1] = point;
            table[x + d2][y + d2 + 1] = point;
        }
        else if(type == 4){
            /// term 2
            draw(x, y, d2, 1);
            draw(x, y + d2 + 1, d2, 4);
            draw(x + d2 + 1, y + d2 + 1, d2, 3);
            draw(x + d2 + 1, y, d2, 4);
            point++;
            table[x + d2][y + d2] = point;
            table[x + d2 + 1][y + d2] = point;
            table[x + d2 + 1][y + d2 + 1] = point;
        }
    }
}





int main(){
    cin >> n >> x0 >> y0;
    point = 0;
    n = (1 << n);
    draw(1, 1, n - 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}