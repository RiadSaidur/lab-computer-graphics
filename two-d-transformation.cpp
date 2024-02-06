#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int X1, Y1, X2, Y2, X3, Y3;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void translate(int v);
void rotation(int angle);

int main(){
    int gd = DETECT, gm, xcenter, ycenter, radius;
    initgraph(&gd, &gm, "");

    cout << "Enter the co-ordinates of Triangle: ";
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    drawTriangle(X1 , Y1 , X2 , Y2 , X3 , Y3 );

    int angle, translateValue;
    cout << "Enter the translation value: ";
    cin >> translateValue;
    translate(translateValue);

    cout << "Enter the angle of rotation: ";
    cin >> angle;
    rotation(angle);
    getch();

    closegraph();
    
    return 0;
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translate(int v){
    drawTriangle(X1 + v, Y1 + v, X2 + v, Y2 + v, X3 + v, Y3 + v);
}

void rotation(int angle){
    float a = angle * (3.1416 / 180);
    int nX1 = abs(X1 * cos(a) - Y1 * sin(a));
    int nY1 = abs(X1 * sin(a) + Y1 * cos(a));
    int nX2 = abs(X2 * cos(a) - Y2 * sin(a));
    int nY2 = abs(X2 * sin(a) + Y2 * cos(a));
    int nX3 = abs(X3 * cos(a) - Y3 * sin(a));
    int nY3 = abs(X3 * sin(a) + Y3 * cos(a));
    drawTriangle(nX1 , nY1 , nX2 , nY2 , nX3 , nY3 );
}

