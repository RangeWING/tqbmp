#include "bmplib.h"

/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image library shortcut using qdbmp
* Only for KAIST 2017 Winter YOUTH Camp
*/

uint32_t getRGB(BMPImage *img, uint i, uint j, uint8_t *r, uint8_t *g, uint8_t *b) {
	BMP_GetPixelRGB(img->bmp, i, j, r, g, b);
	return (*r << 16) | (*g << 8) | *b;
}
void setRGB(BMPImage *img, uint i, uint j, uint8_t r, uint8_t g, uint8_t b) {
	BMP_SetPixelRGB(img->bmp, i, j, r, g, b);
}

uint8_t getPixel(BMPImage *img, uint i, uint j, uint8_t *p) {
	uint8_t r, g, b;
	BMP_GetPixelRGB(img->bmp, i, j, &r, &g, &b);
	*p = (r + g + b) / 3;
	return *p;
}
void setPixel(BMPImage *img, uint i, uint j, uint8_t p) {
	BMP_SetPixelRGB(img->bmp, i, j, p, p, p);
}
void freeBMP(BMPImage *img) {
	uint h = img->h; 
	uint i;

	for (i = 0; i < h; i++) {
		free(img->pixel[i]);
		free(img->rgb[i]);
	}
	free(img->pixel);
	free(img->rgb);
	BMP_Free(img->bmp);
}

void closeBMP(BMPImage *img) {
	freeBMP(img);
	free(img);
}


void getBMPsize(BMP *bmp, uint *w, uint *h) {
	*w = BMP_GetWidth(bmp);
	*h = BMP_GetHeight(bmp);
}

BMPImage *openBMP(const char *bmpfile) {
	BMPImage *img = malloc(sizeof(BMPImage));
	return getBMPImage(img, bmpfile) ? NULL : img;
}

int getBMPImage(BMPImage *img, const char *bmpfile) {
	BMP *bmp = BMP_ReadFile(bmpfile);
	checkBMP(-1);

	getBMPsize(bmp, &img->w, &img->h);

	uint i, j;
	uint8_t r, g, b;
	uint w = img->w, h = img->h;

	img->bmp = bmp;
	img->pixel = malloc(sizeof(uint *) * h);
	img->rgb = malloc(sizeof(struct RGB *) * h);

	for (i = 0; i < h; i++) {
		img->pixel[i] = malloc(sizeof(uint) * w);
		img->rgb[i] = malloc(sizeof(struct RGB) * w);
		for (j = 0; j < w; j++) {
			BMP_GetPixelRGB(bmp, i, j, &r, &g, &b);
			img->pixel[i][j] = (r + g + b) / 3;
			img->rgb[i][j].r = r;
			img->rgb[i][j].g = g;
			img->rgb[i][j].b = b;
		}
	}
	return 0;
}