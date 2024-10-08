//
// Created by Jules Dupont on 07/10/2024.
//

#include "Image.h"

int main() {

    Image monImage;

    for (int i = 0; i < monImage.height; ++i) {
        for (int j = 0; j < monImage.width; ++j) {
            float RGBColor = static_cast<float>(i) / static_cast<float>(monImage.height);
            monImage(j, i) = Color{RGBColor, 1.0F, 1.0F};
        }
    }

    writeImagePPM(monImage);

    return 0;
}
