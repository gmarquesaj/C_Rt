
#define CANAIS 3
#define rand_a (1103515245)
#define rand_c (12345)
#define rand_m (1 << 31)

//AGRUPA 3 OU 2 FLOATS,PODENDO SER USADO COMO COR,POSIÇÃO OU DIREÇAO
typedef struct
{
	float x, y, z;
} vec3;
typedef struct
{
	float x, y;
} vec2;


//AGRUPA INFORMAÇÕES A RESPEITO DA IMAGEM
typedef struct
{
	const int w, h;
	float *pixels;
} ppm;
enum tipoMat
{
	DIFUSO,
	METALICO,
	TRANSLUCIDO,
	FAIXAS,
	LUZ,
	DISPERSAO
};


//AGRUPA INFORMAÇOES A RESPEITO DO MATERIAL
typedef struct
{
	int tipo;
	vec3 cor;
	double k, rugosidade, especular, indiceRefracao;
} material;


// TRIANGULO POSSUI INFORMAÇOES DE POSIÇÃO ,NORMAIS e COORDENADAS DE TEXTURAS DOS 3 VERTICES
typedef struct
{
	vec3 vtPos[3];
	vec2 vtTextCoord[3];
	vec3 vtNormal[3];
	material *mat;
} tri;


// RAIO POSSUI ORIGEM E DIREÇÃO
typedef struct
{
	vec3 o, d;
} ray;


// INFORMAÇOES DE CONTATO
typedef struct
{
	int contato, frente;
	double t0;
	ray *r;
	tri *obj;
	vec3 normal, normalParaFora, hitpos;
	vec2 uv;
} infoContato;


// DELCARAÇAO DE FUNÇOES AINDA NAO IMPLEMENTADAS
vec3 corEm(material *mat, double u, double v)
{
	// AINDA NAO IMPLEMENTADA
	return (vec3){0.0, 0.0, 0.0};
};
int espalhamento(material *mat, infoContato *info)
{
	// AINDA NAO IMPLEMENTADA
	return 0;
}