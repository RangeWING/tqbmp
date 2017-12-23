# tqbmp
Tiny BMP library shortcut using qdbmp (C)
> qdbmp: http://qdbmp.sourceforge.net

This library loads the entire BMP image onto the array in BMPImage structure. It is not efficient, but simple for the education. Yes, this library is developed for education.

이 라이브러리는 전체 BMP 이미지를 BMPImage 구조체의 배열에 로드합니다. 비효율적이지만, 교육용으로 간단한 사용을 위해 개발되었습니다.

## structures
 * RGB  
```
typedef struct RGB {
    uint8_t r, g, b;
} RGB;
```
	
 * BMPImage  
```
typedef struct BMPImage {
    uint w, h;
    BMP *bmp;
    struct RGB **rgb;
    uint8_t **pixel;
} BMPImage;
```  

    * `uint w, h`: width and height of image	(이미지의 가로, 세로)
	* `BMP *bmp`: BMP data of qdbmp
	* `struct RGB **rgb`: RGB data
	* `uint8_t **pixel`: Grayscale data	(흑백)
	
	

## functions
 * `BMPImage *openBMP(const char *bmpfile)` : 
 * `BMPImage *newBMP(uint w, uint h)`:
 * `void freeBMP(BMPImage *img)`:
 * `void closeBMP(BMPImage *img)`:
 * `void setRGB(BMPImage *img)`:
 * `void setPixel(BMPImage *img)`:
 * `int writeBMP(BMPImage *img, const char *bmpfile)`:
 * `void getBMPsize(BMP *bmp, uint *w, uint *h)`:
 * `int getBMPImage(BMPImage *img, const char *bmpfile)`:
 * `int _initImage(BMPImage *img, BMP *bmp)`:
 * `uint32_t getRGB(BMPImage *img, uint i, uint j, uint8_t *r, uint8_t *g, uint8_t *b)`:
 * `uint8_t getPixel(BMPImage *img, uint i, uint j, uint8_t *p)`:
 
 
 