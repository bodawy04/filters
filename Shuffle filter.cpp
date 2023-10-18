#include <iostream>
#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"
#include <cstring>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int x;

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
    cout << "New order of quarters ?";
    int arr[4];
    for (int i = 0; i < 4; ++i){
        cin >> arr[i];
    }


    int dx[4] = {0, 0, SIZE / 2, SIZE / 2};
    int dy[4] = {0, SIZE / 2, 0, SIZE / 2};
    for (int i = 0; i < SIZE/2; ++i) {
        for (int j = 0; j < SIZE/2; ++j) {
            x = image[i+ dx[arr[0]-1]][j + dy[arr[0]-1]];
            image2[i][j] = x;
        }
    }

    for (int i = 0; i < SIZE/2; ++i) {
        for (int j = SIZE/2; j < SIZE; ++j) {
            x = image[i+ dx[arr[1]-1]][j-128 + dy[arr[1]-1]];
            image2[i][j] = x;
        }
    }

    for (int i = SIZE/2; i < SIZE; ++i) {
        for (int j = 0; j < SIZE/2; ++j) {
            x = image[i-128+ dx[arr[2]-1]][j + dy[arr[2]-1]];
            image2[i][j] = x;
        }
    }

    for (int i = SIZE/2; i < SIZE; ++i) {
        for (int j = SIZE/2; j < SIZE; ++j) {
            x = image[i-128+ dx[arr[3]-1]][j-128 + dy[arr[3]-1]];
            image2[i][j] = x;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image2[i][j];
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
