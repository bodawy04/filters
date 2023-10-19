void mirrorImage() {
    char c1, c2;

    cout << "Choose whether you want to mirror the image horizontally (enter 'h') or vertically (enter 'v')" << endl;
    cin >> c1;
    if (c1 == 'v') {
        cout << "Choose either the left part (l) or the right part (r)" << endl;
        cin >> c2;
        if (c2 == 'l') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image1[i][j];
                    //check if first half
                    if (j < SIZE / 2)
                        image1[i][SIZE - j] = temp;
                }
            }
        }
        if (c2 == 'r') {
            for (int i = 0; i < SIZE; i++) {
                // half size of vertical mirror
                for (int j = 0; j < SIZE / 2; j++) {
                    image1[i][j] = image1[i][SIZE - j];

                }
            }
        }

    }
    if (c1 == 'h') {
        cout << "Choose either the upper part (enter 'u') or the lower part (enter 'l')" << endl;
        cin >> c2;
        if (c2 == 'u') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int temp = image1[i][j];
                    image1[SIZE - i][j] = temp;
                }
            }
        }
        if (c2 == 'l') {
            // half size of horizontal mirror
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image1[i][j] = image1[SIZE - i][j];
                }
            }
        }

    }
}

void detectImageEdges() {
    unsigned char edged[SIZE][SIZE];
    //convert image to black and white
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            //convert to black and white
            if (image1[i][j] > 127)
                image1[i][j] = 255;
            else
                image1[i][j] = 0;
        }
    }
    for (int i = 1; i < SIZE - 1; i += 1) {
        for (int j = 1; j < SIZE - 1; j += 1) {
            //check detection of current pixel against before/after pixels
            if (image1[i][j] == image1[i][j + 1] && image1[i][j] == image1[i][j - 1])
                edged[i][j] = 255;
            else
                edged[i][j] = 0;
        }
    }
}

void cropImage() {
    int x,y;
    cout<<"Enter vertical cropping value: ";
    cin>>x;
    cout<<"Enter horizontal cropping value: ";
    cin>>y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < SIZE; j++) {
            image1[i][j] = 255;

        }
    }
    for (int i = SIZE-x; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image1[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < y; j++) {
            image1[i][j] = 255;

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE-y; j < SIZE; j++) {
            image1[i][j] = 255;
        }
    }
}
