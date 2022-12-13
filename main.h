#define tipo float
#define CANAIS 3
#define rand_a (1103515245)
#define rand_c (12345)
#define rand_m (1 << 31)
typedef struct
{
	float x, y, z;
} vecCANAIS;

typedef struct
{
	vecCANAIS v1, v2, vCANAIS, n1, n2, nCANAIS;
} tri;
typedef struct
{
	const int w, h;
	float *pixels;
} ppm;