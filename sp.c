#include <math.h>
struct f2{float a,b;};

static inline float sum(float* a, unsigned char len){
	float r = 0;
	for(unsigned char i=0; i<len; i++)
		r += a[i];
	return r;
}

static inline struct f2 p(unsigned char a, unsigned* n, unsigned char k){
	struct f2 r = {log2f(n[0])-sum((float*)n+k,k-1)/n[0], log2f((float)n[0]/n[a])};
	n[0] ++;
	n[a] ++;
	*(float*)(n+k-1+a) = log2f(n[a]) * n[a];
	return r;
}

static inline struct f2 cp(unsigned char* a, unsigned char prd, unsigned* n, unsigned step, unsigned char k){
	if (prd == 0)
		return p(*a, n, k);
	struct f2 x = cp(a+1, prd-1, n, step/k, k);
	struct f2 y = cp(a+1, prd-1, n+*a*step, step/k, k);
	return x.a > y.a ? x : y;
}

float sp(unsigned char* a, unsigned len, unsigned char prd, unsigned* n, unsigned char k){
	float r = 0;
	unsigned step = (2u * k - 1) * pow(k, prd-1);
	for(unsigned i=0; i<len-prd; i++)
		r += cp(a+i, prd, n, step, k).b;
	return r / (len-prd);
}