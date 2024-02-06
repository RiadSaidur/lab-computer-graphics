#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void bresenhamCircle(int xc, int yc, int r);
void drawCircle(int xc, int yc, int x, int y);

int main(){
    int gd = DETECT, gm, xcenter, ycenter, radius;
    initgraph(&gd, &gm, NULL);

    cout << "Enter the center co-ordinates (x, y): ";
    cin >> xcenter >> ycenter;

    cout << "Enter the radius: ";
    cin >> radius;

    bresenhamCircle(xcenter, ycenter, radius);

    getch();
    closegraph();

    return 0;
}

void bresenhamCircle(int xc, int yc, int r){
    int x = 0, y = r, d = 3 - 2 * r;

    drawCircle(xc, yc, x, y);

    while (y >= x){
        x++;

        if (d > 0){
            y--;
            d += (4 * (x - y) + 10);
        }
        else{
            d += (4 * x + 6);
        }

        drawCircle(xc, yc, x, y);
    }
}

// 8 point symmetry of a circle
void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}
