//
// Created by Jules Dupont on 07/10/2024.
//

#ifndef IMAGE_H
#define IMAGE_H

#include "Vec3.h"

using Color = Vec3;

static constexpr int WIDTH = 384;
static constexpr int HEIGHT = 256;

struct Image {
    int width = WIDTH;
    int height = HEIGHT;

    Color colors[WIDTH * HEIGHT]{};

    Color& operator()(int x, int y) { return colors[y*WIDTH + x]; }
    const Color& operator()(int x, int y) const { return colors[y*WIDTH + x]; }
};

inline void writeColor(std::ostream& stream, const Color& color) {
    int red = int(255.0 * color.x);
    int green = int(255.0 * color.y);
    int blue = int(255.0 * color.z);

    stream << red << ' ' << green << ' ' << blue << '\n';
}

inline void writeImagePPM(const Image& image) {
    std::ofstream file_stream{ "Img.ppm" };
    file_stream << "P3\n" << image.width << " " << image.height << "\n255\n";

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            writeColor(file_stream, image(i,j));
        }
    }
}

#endif //IMAGE_H
