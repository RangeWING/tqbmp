# tqbmp
Tiny BMP library shortcut based on qdbmp (C)
> qdbmp: http://qdbmp.sourceforge.net

This library loads the entire BMP image onto the array in BMPImage structure. It is not efficient, but simple for the education. Yes, this library is developed for education.

이 라이브러리는 전체 BMP 이미지를 BMPImage 구조체의 배열에 로드합니다. 비효율적이지만, 교육용으로 간단한 사용을 위해 개발되었습니다.

## structures and types
 * RGB  
```
typedef struct RGB {
    uint8_t color[3];
} RGB;

enum {RED, GREEN, BLUE};
```

You can use the colors like `color[RED]`, or also `color[0]`, equivalently.  
RED, GREEN, BLUE are same as 0, 1, 2, respectively.  
RGB의 각 색상을 `color[RED]`, 혹은 `color[0]`과 같이 쓸 수 있습니다.  
RED, GREEN. BLUE는 각각 0, 1, 2번 인덱스와 동일합니다.
	
 * BMPImage  
```
typedef struct BMPImage {
    uint w, h;			// width and height of image	(이미지의 가로, 세로) 
    BMP *bmp;			// BMP data of qdbmp  
    struct RGB **rgb;	// RGB data. rgb[y][x] is the RGB value of (x,y). 
    uint8_t **pixel;	// Grayscale data. pixel[y][x] is the grayscale value of (x,y). 	(흑백)
} BMPImage;
```
  * 픽셀 값을 x, y 순서가 아닌 y, x 순서로 참조하여야 하는 것을 주의하세요.

 * uint  
`typedef unsigned long uint;` 
	

## functions
### User functions
 * `BMPImage *openBMP(const char *bmpfile)`
   * open a BMP file and returns the pointer of BMPImage. Use it just like fopen(). 
   * BMP 파일을 엽니다. fopen()과 비슷합니다.
 * `BMPImage *newBMP(uint w, uint h)`
   * make a new BMP image of size w×h.
   * 가로 w, 세로 h 크기의 BMP 이미지를 만듭니다.
 * `void closeBMP(BMPImage *img)`
   * deallocate (free) all of its members and **also itself**. Use this if you made BMPImage with `openBMP()` or `newBMP()`.
   * img의 모든 멤버의 할당을 해제하고 img 자체도 해제합니다. `openBMP()`나 `newBMP()`를 이용하여 BMPImage를 만들었다면 이 함수를 사용하세요.
 * `int getBMPImage(BMPImage *img, const char *bmpfile)`
   * get a BMP file and stores it to img.
   * BMP 파일을 읽어서 img에 저장합니다.
 * `void freeBMP(BMPImage *img)`
   * deallocate (free) all of its members. Use this if you made BMPImage with `getBMPImage()`.
   * img의 모든 멤버의 할당을 해제합니다. `getBMPImage()`를 이용하여 BMPImage를 만들었다면 이 함수를 사용하세요.
 * `void setRGB(BMPImage *img)`
   * update all of its RGB values changed in the ARRAY (rgb) to BMP instance.
   * 변경한 rgb 배열의 RGB 값을 BMP에 반영합니다.
 * `void setPixel(BMPImage *img)`
   * update all of its PIXEL(grayscale) values changed in the ARRAY (pixel) to BMP instance.
   * 변경한 pixel 배열의 흑백 값을 BMP에 반영합니다.
 * `int writeBMP(BMPImage *img, const char *bmpfile)`
   * write the image to the file.
   * 이미지를 file에 씁니다.

### Internal functions
 * `void getBMPsize(BMP *bmp, uint *w, uint *h)`: get the size of BMP.
 * `int _initImage(BMPImage *img, BMP *bmp)`: initiates the BMPImage structure by allocating all of its members.
 * `uint32_t getRGB(BMPImage *img, uint i, uint j, uint8_t *r, uint8_t *g, uint8_t *b)`: get the RGB value from the BMP directly.
 * `uint8_t getPixel(BMPImage *img, uint i, uint j, uint8_t *p)`: get the grayscale value from the BMP directly.
 
## Example (1)
```
uint w, h, i, j;
uint8_t p;
BMPImage *img, *newimg;

img = openBMP("test.bmp");
w = img->w;
h = img->h;

newimg = newBMP(w, h);
for (i = 0; i < h; i++) {
  for (j = 0; j < w; j++) {
    p = img->pixel[i][j];
    newimg->pixel[i][j] = 255 - p; // reverse the value
  }
}

setPixel(newimg);	// update the BMP with grayscale value
writeBMP(newimg, "test_new.bmp");

closeBMP(img);
closeBMP(newimg);
```

 
## Example (2)
```
uint w, h, i, j;
RGB p;
BMPImage *img, *newimg;

img = openBMP("test.bmp");
w = img->w;
h = img->h;

newimg = newBMP(w, h);
for (i = 0; i < h; i++) {
  for (j = 0; j < w; j++) {
    p = img->rgb[i][j];
	p.color[RED] = 255 - p.color[RED];
	p.color[GREEN] = 255 - p.color[GREEN];
	p.color[BLUE] = 255 - p.color[BLUE];
	
    newimg->rgb[i][j] = p;
  }
}

setRGB(newimg);	// update the BMP with RGB value
writeBMP(newimg, "test_new.bmp");

closeBMP(img);
closeBMP(newimg);
```
 
 
 