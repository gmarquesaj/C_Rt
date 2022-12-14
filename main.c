#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int POS(const int x, const int y, const int w)
{
	return (x * CANAIS) + (CANAIS * w * y);
}
void savePPM_P3(ppm *img)
{
	//	unsigned char *temp = malloc(CANAIS*img->w*img->h*sizeof(unsigned char));
	//	free(temp);
	FILE *imgF = fopen("imagem.ppm", "w");
	fprintf(imgF, "P3\n%d %d %d\n", img->w, img->h, 256);
	for (int y = 0; y < img->h; y++)
	{
		for (int x = 0; x < img->w; x++)
		{
			int pos = POS(x, y, img->w);
			int r = (int)255 * img->pixels[pos];
			int g = (int)255 * img->pixels[pos + 1];
			int b = (int)255 * img->pixels[pos + 2];
			fprintf(imgF, "%d %d %d\n", r % 254, g % 254, b % 254);
		}
	}
	fclose(imgF);
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
	ppm img = {w, h, malloc(CANAIS * w * h * sizeof(float))};

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
#if 0
			float r = (float)x / w;
			float g = (float)y / h;
			float b = 0.5f;
#else
			unsigned int seed = ((y << (y + x)) % rand_m) /* + ((x<<(y+x))% rand_m) */;
			float r = randF(&seed);
			float g = randF(&seed);
			float b = randF(&seed);
#endif
			int pos = POS(x, y, w);
			img.pixels[pos] = r;
			img.pixels[pos + 1] = g;
			img.pixels[pos + 2] = b;
		}
	savePPM_P3(&img);
	free(img.pixels);

	return 0;
}
