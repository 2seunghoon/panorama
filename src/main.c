#include <math.h>
#include <string.h>
#include "image.h"
#include "test.h"
#include "args.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
int main(int argc, char** argv)
{
    char* in = "data/dog.jpg";
    //char* out = "result";

    int option;
    scanf("%d", &option); getchar();
    // 1. get_pixel, set_pixel
    if (option == 1) {

        test_get_pixel(in);
        test_set_pixel(in);

    }
    // 2. copy image
    else if (option == 2) {
        test_copy(in);
    }
    // 3. gray scale
    else if (option == 3) {
        image im = load_image(in);
        image g = rgb_to_grayscale(im);
        save_image(g, "gray");
        free_image(im);
        free_image(g);

    }
    // 4. shifting image colors
    else if (option == 4) {
        /*image im = load_image(in);
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        save_image(im, "overflow");*/
        test_shift();
    }
    // 5. clamping image values
    else if (option == 5) {
        image im = load_image(in);
        shift_image(im, 0, .4);
        shift_image(im, 1, .4);
        shift_image(im, 2, .4);
        save_image(im, "before_clamping");

        clamp_image(im);
        save_image(im, "after_clamping");
    }
    // 6. RGB to HSV
    else if (option == 6) {
        test_rgb_to_hsv();
    }
    // 7. HSV to RGB
    else if (option == 7) {
        test_hsv_to_rgb();
    }
    else if (option == 8) {
        image im = load_image("data/dog.jpg");
        rgb_to_hsv(im);
        shift_image(im, 1, .2);
        clamp_image(im);
        hsv_to_rgb(im);
        save_image(im, "dog_saturated");
    }
    else if (option == 9) {
        test_nn_resize();
    }
    else if (option == 10) {

        test_bl_resize();

        test_multiple_resize();

    }
    else if (option == 11) {
        test_convolution();
    }
    else if (option == 12) {

        test_highpass_filter();
        test_emboss_filter();
        test_sharpen_filter();

    }
    else if (option == 13) {
        //test_gaussian_filter();
        test_gaussian_blur();
    }
    else if (option == 14) {

        test_hybrid_image();
        test_frequency_image();

    }
    else if (option == 15) {
        test_sobel();
    }
    else if (option == 16) {
        image im = load_image("data/dog.jpg");
        image new_image = colorize_sobel(im);
        save_image(new_image, "test_colorized");
    }
    // detect corners
    else if (option == 17) {
        
        //test_structure();  test step 1
        //test_cornerness();  test step 2
        image im = load_image("data/Rainier1.png");
        //image gt = load_image("figs/corners.jpg");
        //image im = load_image("corners.jpg");
        detect_and_draw_corners(im, 2, 50, 3);
        //test_corner(im, gt);
        save_image(im, "corners");
    }
    // patch matching
    else if (option == 18) {
        image a = load_image("data/Rainier1.png");
        image b = load_image("data/Rainier2.png");
        image m = find_and_draw_matches(a, b, 2, 50, 3);
        save_image(m, "matches");
    }
    else if (option == 19) {
        // easy panorama
        image im1 = load_image("data/Rainier1.png");
        image im2 = load_image("data/Rainier2.png");
        image pan = panorama_image(im1, im2, 2,50,3,2,10000,30);
        save_image(pan, "easy_panorama");
    }
    else if (option == 20) {
        // multi panorama

        image im1 = load_image("data/Rainier1.png");
        image im2 = load_image("data/Rainier2.png");
        image im3 = load_image("data/Rainier3.png");
        image im4 = load_image("data/Rainier4.png");
        image im5 = load_image("data/Rainier5.png");
        image im6 = load_image("data/Rainier6.png");
        image pan = panorama_image(im1, im2, 2, 5, 3, 2, 10000, 30);
        save_image(pan, "rainier_panorama_1");
        image pan2 = panorama_image(pan, im5, 2, 5, 3, 2, 10000, 30);
        save_image(pan2, "rainier_panorama_2");
        image pan3 = panorama_image(pan2, im6, 2, 5, 3, 2, 10000, 30);
        save_image(pan3, "rainier_panorama_3");
        image pan4 = panorama_image(pan3, im3, 2, 5, 3, 2, 10000, 30);
        save_image(pan4, "rainier_panorama_4");
        image pan5 = panorama_image(pan4, im4, 2, 5, 3, 2, 10000, 30);
        save_image(pan5, "rainier_panorama_5");

    }
    else if (option == 21) {
    // cylinder panorama
        image im1 = load_image("data/field1.jpg");
        image im2 = load_image("data/field2.jpg");
        image im3 = load_image("data/field3.jpg");
        image im4 = load_image("data/field4.jpg");
        image im5 = load_image("data/field5.jpg");
        image im6 = load_image("data/field6.jpg");
        image im7 = load_image("data/field7.jpg");
        image im8 = load_image("data/field8.jpg");

        image im1 = cylindrical_project(im1, 1200);
        image im2 = cylindrical_project(im2, 1200);
        image im3 = cylindrical_project(im3, 1200);
        image im4 = cylindrical_project(im4, 1200);
        image im5 = cylindrical_project(im5, 1200);
        image im6 = cylindrical_project(im6, 1200);
        image im7 = cylindrical_project(im7, 1200);
        image im8 = cylindrical_project(im8, 1200);
        save_image(im1, "cylindrical_projection");

        image pan = panorama_image(im5, im6,2,2,3,3, 50000, 30);
        save_image(pan, "field_panorama_1");
        image pan2 = panorama_image(pan, im7, 2, 2, 3, 3, 50000, 30);
        save_image(pan2, "field_panorama_2");
        image pan3 = panorama_image(pan2, im8, 2, 2, 3, 3, 50000, 30);
        save_image(pan3, "field_panorama_3");
        image pan4 = panorama_image(pan3, im4, 2, 2, 3, 3, 50000, 30);
        save_image(pan4, "field_panorama_4");
        image pan5 = panorama_image(pan4, im3, 2, 2, 3, 3, 50000, 30);
        save_image(pan5, "field_panorama_5");
        image pan21 = panorama_image(im2, im1, 2, 2, 3, 3, 50000, 30);
        image pan6 = panorama_image(im3, pan21, 2, 2, 3, 3, 50000, 30);
        save_image(pan6, "field_panorama_6");
        image final_image = panorama_image(pan5, pan6, 2, 2, 3, 3, 50000, 30);
        save_image(final_image, "field_panorama_all");
       }
    return 0;
}
