#ifndef BMP_LIB_H
#define BMP_LIB_H

/*
	* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
	* BMP image library shortcut using qdbmp
*/

#include <stdlib.h>
#include <stdint.h>
#include <qdbmp.h>

#define checkBMP(k) BMP_CHECK_ERROR(stdout, k);

typedef unsigned int uint;
 
typedef struct RGB {
	uint8_t r, g, b;
} RGB;

typedef struct BMPImage {
	uint w, h;
	BMP *bmp;
	struct RGB **rgb;
	uint8_t **pixel;
} BMPImage;

void getBMPsize(BMP *bmp, uint *w, uint *h);
BMPImage *openBMP(const char *bmpfile);
BMPImage *newBMP(uint w, uint h);
int getBMPImage(BMPImage *img, const char *bmpfile);
int _initImage(BMPImage *img, BMP *bmp);
uint32_t getRGB(BMPImage *img, uint i, uint j, uint8_t *r, uint8_t *g, uint8_t *b);
void setRGB(BMPImage *img, uint i, uint j, uint8_t r, uint8_t g, uint8_t b);
uint8_t getPixel(BMPImage *img, uint i, uint j, uint8_t *p);
void setPixel(BMPImage *img, uint i, uint j, uint8_t p);
int writeBMP(BMPImage *img, const char *bmpfile);
void freeBMP(BMPImage *img);
void closeBMP(BMPImage *img);


#endif