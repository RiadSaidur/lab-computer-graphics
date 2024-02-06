#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
int  WX1 = 150, WY1 = 150, WX2 = 400, WY2 = 350;

class coordinate{
public:
    int x, y, code[4];
    coordinate(){
        for(int i = 0; i < 4; i++){
            code[i] = 0;
        }
    }
    ~coordinate(){}
    void setCode(){
        if(x < WX1){
            code[3] = 1;
        }if(x > WX2){
            code[2] = 1;
        }if(y < WY1){
            code[1] = 1;
        }if(y > WY2){
            code[0] = 1;
        }
    }
};

void drawWindow(){
    line(WX1, WY1, WX2, WY1);
    line(WX1, WY1, WX1, WY2);
    line(WX1, WY2, WX2, WY2);
    line(WX2, WY1, WX2, WY2);
}


int visibilityCheck(coordinate a, coordinate b){
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += (a.code[i] + b.code[i]);
    }
    if(sum == 0){
        return 0;
    }else{
        sum = 0;
        for(int i = 0; i < 4; i++){
            sum += (a.code[i] & b.code[i]);
        }
        if(sum != 0){
            return -1;
        }else{
            return 1;
        }
    }
}

coordinate clipIt(coordinate a, coordinate b){
    int x, y;
    float m;
    coordinate newCord;
    if(a.code[2] || a.code[3]){
        x = a.code[2]? WX2 : WX1;
        m = abs(a.y - b.y) * 1.0 / abs(a.x - b.x);
        newCord.y = a.y + (m * (x - a.x));
        newCord.x = x;
        for(int i = 0; i < 4; i++){
            newCord.code[i] = a.code[i];
        }
        if(newCord.y >= WY1 && newCord.y <= WY2){
            return newCord;
        }
    }
    if(a.code[0] || a.code[1]){
        y = a.code[0]? WY1 : WY2;
        m = abs(a.y - b.y) * 1.0 / abs(a.x - b.x);
        newCord.x = a.x + ((y - a.y) * 1.0 / m);
        newCord.y = y;
        for(int i = 0; i < 4; i++){
            newCord.code[i] = a.code[i];
        }
        return newCord;
    }
    return a;
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    while(1){
        drawWindow();
        coordinate a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        a.setCode();
        b.setCode();
        int r = visibilityCheck(a, b);
        line(a.x, a.y, b.x, b.y);
        if(r == 0){
            printf("Visible!\n");
        }else if(r == -1){
            printf("Not visible.\n");
        }else if(r == 1){
            coordinate newA = clipIt(a, b), newB = clipIt(b, a);
            delay(1000);
            cleardevice();
            drawWindow();
            line(newA.x, newA.y, newB.x, newB.y);
            printf("Clipping candidate.\n");
        }
        delay(2000);
        cleardevice();
    }
    getch();
    closegraph();
    return 0;
}
