
//
//  imagen.cpp
//  Ejercicios
//
//  Created by Homero Marin on 2/24/18.
//  Copyright © 2018 Homero Marin. All rights reserved.
//

#include <iostream>
#include <algorithm>

class Size {
public:
    Size() {
        width = 0;
        height = 0;
    }
    Size(int w, int h) {
        width = w;
        height = h;
    }
    int width;
    int height;
};
class ImageSolution {
public:
    ImageSolution(Size imgSize, Size scrnSize) {
        imageSize = imgSize;
        imageRatio = (double)imgSize.width / imgSize.height;
        screenSize = scrnSize;
    }
    double imageRatio;
    Size imageSize;
    Size screenSize;
    Size maxSizeWithinScreen() {
        Size maxSize;
        if (imageRatio > 1) {
            maxSize = Size(screenSize.width, screenSize.width / imageRatio);
        }
        else if (imageRatio == 1){
            int minDim = std::min(screenSize.width, screenSize.height);
            maxSize = Size(minDim, minDim);
        }
        else {
            maxSize = Size(screenSize.height * imageRatio, screenSize.height);
        }
        return maxSize;
    }
};

