#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int POS(const int x, const int y, const int w)
{
	return (x * CANAIS) + (CANAIS * w * y);
}
void savePPM_P3(ppm *img)
{

	printf("P3\n%d %d %d\n", img->w, img->h, 256);
	//	unsigned char *temp = malloc(CANAIS*img->w*img->h*sizeof(unsigned char));
	//	free(temp);
	for (int y = 0; y < img->h; y++)
	{

		for (int x = 0; x < img->w; x++)
		{
			int pos = POS(x, y, img->w);
			int r = (int)255 * img->pixels[pos];
			int g = (int)255 * img->pixels[pos + 1];
			int b = (int)255 * img->pixels[pos + 2];
			printf("%d %d %d\n", r%254, g%254, b%254);

			//printf("# %f %f %f \n", img->pixels[pos], img->pixels[pos + 1], img->pixels[pos + 2]);
		}
	}
};
int randI(unsigned int *seed)
{
	*seed = (rand_a * *seed + rand_c) % rand_m;
	return *seed;
}

float randF(unsigned int *seed)
{
	return -(float)randI(seed) / rand_m;
}

int main()
{
	const int w = 1200, h = 1020;
	ppm img = {w, h};
	img.pixels = malloc(CANAIS * w * h * sizeof(tipo));	
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			unsigned int seed =( (y<<(y+x))% rand_m)+ ((x<<(y+x))% rand_m);

			// float r = (float)x/w;
			// float g = (float)y/h;
			float r = randF(&seed);
			float g = randF(&seed);
			float b = randF(&seed);
			int pos = POS(x, y, w);
			img.pixels[pos] = r;
			img.pixels[pos + 1] = g;
			img.pixels[pos + 2] = b;
		}
	savePPM_P3(&img);
	free(img.pixels);

	return 0;
}
