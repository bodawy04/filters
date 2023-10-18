#include <iostream>
#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"
#include <cstring>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int x,y;

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
    cout<< "Enter the number 1 if you want to enlarge the top left corner of the image \n"
           "Enter the number 2 if you want to enlarge the top right corner of the image \n"
           "Enter the number 3 if you want to enlarge the bottom left corner of the image\n"
           "Enter the number 4 if you want to enlarge the bottom right corner of the image\n"
           ": ";
    cin>> x;
    strcat(imagename, ".bmp"); /*to add the extension to the image name*/
    readGSBMP (imagename, image);
}

void Filter() {
    int dx[4] = {0, 0, SIZE / 2, SIZE / 2}; /* directional array for all adjacent pixels*/
    int dy[4] = {0, SIZE / 2, 0, SIZE / 2}; /* directional array for all adjacent pixels*/

    for (int i = 0; i < SIZE/2 ; i++) {
        for (int j = 0; j < SIZE/2 ; j++) {
            y = image[i + dx[x - 1]][j + dy[x - 1]];
            image2[i * 2][j * 2] = y;
            image2[i * 2 + 1][j * 2] = y;
            image2[i * 2][j * 2 + 1] = y;
            image2[i * 2 + 1][j * 2 + 1] = y;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image2[i][j]; /*to create a new image with the desired enlarged quarter*/
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
