//
// Created by Jules Dupont on 01/10/2024.
//

#include "Vec3.h"
#include <iostream>
#include <fstream>

int main() {
    Image monImage;

    for (int i = 0; i < monImage.height; ++i) {
        for (int j = 0; j < monImage.width; ++j) {
            float RGBColor = static_cast<float>(i) / static_cast<float>(monImage.height);
            monImage(j, i) = Color{RGBColor, 0.0, 1.0};
        }
    }

    writeImagePPM(monImage);


    return 0;
}

