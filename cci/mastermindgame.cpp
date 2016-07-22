#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

enum color {
    kRed = 0x0001,
    kBlue = 0x0020,
    kGreen = 0x0400,
    kYellow = 0x8000
};

union game {
    int c;
    char carray[4];
};

int main() {
    int colorarray[4] = {kRed, kBlue, kGreen, kYellow};
    int hsol = 0;
    game hgame;
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        hgame.carray[i] = colorarray[rand() % 4];
    }

    game guess;
    
    for (int i = 0; i < 4; i++) {
        guess.carray[i] = colorarray[rand() % 4];
    }

    for (int i = 0; i < 4; i++) {
        if (hgame.carray[i] & guess.carray[i]) {
            cout<<"Hit for color["<<i<<endl;
        }
    }
}
    

