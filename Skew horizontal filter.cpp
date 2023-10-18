#include <iostream>
#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"
#include <cstring>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void Load();
void Filter();
void Save();

int main(){
    Load();
    Filter();
    Save();
}
void Load(){
    char imagename[100];
    cout<< "Enter the source image file name: ";
    cin>> imagename;
    strcat(imagename, ".bmp"); /*to add the extension to the image name*/
    readGSBMP (imagename, image);
}

void Filter() {
    cout << "enter degree : \n";
    double deg; cin >> deg;
    deg = (deg * 22) / (180 * 7);
    int s_shrunk = int((256 * 256) / ((256.0 / tan(deg) + 256.0)));
    double x = 256.0 - s_shrunk;
    double y = (256.0 - s_shrunk) / 256.0;
/* white pixels*/
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image3[i][j] = 255;
            image2[i][j] = 255;
        }
    }
/* shrink the image*/
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < s_shrunk; ++j) {
            image2[i][j] = image[i][(j * 255) / s_shrunk];
        }
    }
/* skew*/
    for (int i = 0; i < SIZE; i++) {
        for (int j = int(x); j < int(x) + s_shrunk; j++) {
            image3[i][j] = image2[i][(j-int(x))];
        }
        x -= y;
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image3[i][j];
        }
    }
}

void Save(){
    char imagename[100];
    cout << "Enter the target image file name: ";
    cin >> imagename;
    strcat (imagename, ".bmp"); /*to add the extension to the image name*/
    writeGSBMP(imagename, image);
}
