#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void midpointEllipse(int a, int b, int xc, int yc);
void draw4Symmetry(int xc, int yc, int x, int y);

int main(){
    int gd = DETECT, gm, a, b, xc, yc;

    cout << "Enter the radius of major axis: ";
    cin >> a;
    cout << "Enter the radius of minor axis: ";
    cin >> b;
    cout << "Enter the center co-ordinate of Ellipse (xc, yc): ";
    cin >> xc >> yc;

    initgraph(&gd, &gm, "");

    midpointEllipse(a, b, xc, yc);
    getch();

    closegraph();
    
    return 0;
}
void midpointEllipse(int a, int b, int xc, int yc){
    int x = 0, y = b;
    int aa = a * a, bb = b * b, aa2 = aa * 2, bb2 = bb * 2;
    int fx = 0, fy = aa2 * b;
    int p = round(bb - aa * b + (.25 * aa));
    while(fx < fy){
        draw4Symmetry(xc, yc, x, y);
        x++;
        fx += bb2;
        if(p < 0){
            p += (fx + bb);
        }else{
            y--;
            fy -= aa2;
            p += (fx + bb - fy);
        }
    }
    draw4Symmetry(xc, yc, x, y);
    p = (bb * (x + .5) * (x + .5)) + (aa * (y - 1) * (y - 1)) - (aa * bb);
    while(y > 0){
        y--;
        fy = fy - aa2;
        if( p >= 0){
            p -= fy + aa;
        }else{
            x++;
            fx += bb2;
            p += fx - fy + aa;
        }
        draw4Symmetry(xc, yc, x, y);
    }
}
// 4 point symmetry of a circle
void draw4Symmetry(int xc, int yc, int x, int y){
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

