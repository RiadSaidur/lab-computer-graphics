#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

void bresenhamAlgorithm(int x1, int y1, int x2, int y2);
int main(){
    
    int graphDriver = DETECT, graphMode;
    initgraph(&graphDriver, &graphMode, NULL);
    
    int x1, x2, y1, y2;
    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;

    bresenhamAlgorithm(x1, y1, x2, y2);
    getch();

    closegraph();
    
    return 0;
}

void bresenhamAlgorithm(int x1, int y1, int x2, int y2){
    int dx, dy, moves, x, y, p;
    float m, xinc, yinc;

    x = x1, y = y1;

    dx = abs(x1 - x2);
    dy = abs(y1 - y2);

    m = dy * 1.0 / dx;

    if(m == 1){ // for slope = 1
        moves = max(dx, dy);
        for(int i = 0; i < moves; i++, x++, y++){
            putpixel(x, y, WHITE);
        }
    }else if(m < 1){ // for slope < 1
        p = 2 * dy - dx;
        for(int i = x; i <= x2; i++){
            putpixel(i, y, WHITE);
            if(p < 0){
                p += (2 * dy);
            }else{
                p += (2 * dy - dx);
                y++;
            }
        }
    }else{ // for slope > 1
        p = 2 * dx - dy;
        for(int i = y; i <= y2; i++){
            putpixel(x, i, WHITE);
            if(p < 0){
                p += (2 * dx);
            }else{
                p += (2 * dx - dy);
                x++;
            }
        }
    }
}
