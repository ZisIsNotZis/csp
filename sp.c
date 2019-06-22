#include <math.h>

static inline float sum(float* a, unsigned char len){
	float r = 0;
	for(unsigned char i=0; i<len; i++)
		r += a[i];
	return r;
}

static inline float p(unsigned char k, unsigned* n, unsigned char a){
	float r = log2f(n[0]) - sum((float*)n+k, k-1) / n[0];
	n[0] ++;
	n[a] ++;
	*(float*)(n+k-1+a) = log2f(n[a]) * n[a];
	return r;
}

static inline float cp(unsigned char k, unsigned char prd, unsigned step, unsigned* n, unsigned char* a){
	if (prd == 0)
		return p(k, n, a[0]);
	return fminf(cp(k, prd-1, step/k, n, a+1),
				 cp(k, prd-1, step/k, n+a[0]*step, a+1));
}

static inline float sp(unsigned char k, unsigned char prd, unsigned len, unsigned* n, unsigned char* a){
	float r = 0;
	unsigned step = (2u * k - 1) * pow(k, prd-1);
	for(unsigned i=0; i<len-prd; i++)
		r += cp(k, prd, step, n, a+i);
	return r / (len-prd);
}

float s2p0(unsigned len, unsigned* n, unsigned char* a){return sp(3, 0, len, n, a);}
float s2p1(unsigned len, unsigned* n, unsigned char* a){return sp(3, 1, len, n, a);}
float s2p2(unsigned len, unsigned* n, unsigned char* a){return sp(3, 2, len, n, a);}
float s2p3(unsigned len, unsigned* n, unsigned char* a){return sp(3, 3, len, n, a);}
float s2p4(unsigned len, unsigned* n, unsigned char* a){return sp(3, 4, len, n, a);}
float s2p5(unsigned len, unsigned* n, unsigned char* a){return sp(3, 5, len, n, a);}
float s2p6(unsigned len, unsigned* n, unsigned char* a){return sp(3, 6, len, n, a);}
float s2p7(unsigned len, unsigned* n, unsigned char* a){return sp(3, 7, len, n, a);}
float s2p8(unsigned len, unsigned* n, unsigned char* a){return sp(3, 8, len, n, a);}
float s2p9(unsigned len, unsigned* n, unsigned char* a){return sp(3, 9, len, n, a);}
float s2p10(unsigned len, unsigned* n, unsigned char* a){return sp(3, 10, len, n, a);}
float s2p11(unsigned len, unsigned* n, unsigned char* a){return sp(3, 11, len, n, a);}
float s2p12(unsigned len, unsigned* n, unsigned char* a){return sp(3, 12, len, n, a);}
float s2p13(unsigned len, unsigned* n, unsigned char* a){return sp(3, 13, len, n, a);}
float s2p14(unsigned len, unsigned* n, unsigned char* a){return sp(3, 14, len, n, a);}
float s2p15(unsigned len, unsigned* n, unsigned char* a){return sp(3, 15, len, n, a);}
float s2p16(unsigned len, unsigned* n, unsigned char* a){return sp(3, 16, len, n, a);}