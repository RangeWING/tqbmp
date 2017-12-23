# tqbmp
Tiny BMP library shortcut using qdbmp (C)
> qdbmp: http://qdbmp.sourceforge.net

## struct
 * RGB  
	<code>
	typedef struct RGB {
		uint8_t r, g, b;
	} RGB;
	</code>
	
 * BMPImage  
	<pre><code>
	typedef struct BMPImage {
		uint w, h;
		BMP *bmp;
		struct RGB **rgb;
		uint8_t **pixel;
	} BMPImage;
	</code></pre>
	
	

## function
<code>
	void getBMPsize(BMP *bmp, uint *w, uint *h);
	BMPImage *openBMP(const char *bmpfile);
	BMPImage *newBMP(uint w, uint h);
	int getBMPImage(BMPImage *img, const char *bmpfile);
	int _initImage(BMPImage *img, BMP *bmp);
	uint32_t getRGB(BMPImage *img, uint i, uint j, uint8_t *r, uint8_t *g, uint8_t *b);
	void setRGB(BMPImage *img);
	uint8_t getPixel(BMPImage *img, uint i, uint j, uint8_t *p);
	void setPixel(BMPImage *img);
	int writeBMP(BMPImage *img, const char *bmpfile);
	void freeBMP(BMPImage *img);
	void closeBMP(BMPImage *img);
</code>