#include <math.h>
struct f2{float a,b;};

static inline void add(struct f2* a, struct f2 b){
	a->a += b.a;
	a->b += b.b;
}

static inline struct f2 p(unsigned char a, unsigned *n){
	float s = n[0] + n[1],
	      x = (float) n[0] / s,
		  y = (float) n[1] / s,
		  X = log2f(x),
		  Y = log2f(y);
	n[a] ++;
	return (struct f2){x * X + y * Y, a ? Y : X};
}

static inline struct f2 cp(unsigned short a, unsigned char prd, unsigned* n, unsigned step){
	if (prd == 0)
		return p(a & 1, n);
	struct f2 x = cp(a, prd-1, n, step/3);
	struct f2 y = cp(a, prd-1, n+(1+((a>>prd)&1))*step, step/3);
	return x.a > y.a ? x : y;
}

struct f2 s2p7(unsigned char* a, unsigned len, unsigned* n){
	struct f2 r = {0, 0};
	for(unsigned i=0; i<len-1; i++){
		add(&r, cp(a[i], 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>7, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>6, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>5, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>4, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>3, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>2, 7, n, 1458));
		add(&r, cp(*(unsigned short*)(a+i)>>1, 7, n, 1458));
	}
	return (struct f2){-r.a/(len-1), -r.b/(len-1)};
}

struct f2 s2p15(unsigned char* a, unsigned len, unsigned* n){
	struct f2 r = {0, 0};
	for(unsigned i=0; i<len-3; i++){
		add(&r, cp(*(unsigned short*)(a+i), 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>15, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>14, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>13, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>12, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>11, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>10, 15, n, 9565938));
		add(&r, cp(*(unsigned*)(a+i)>>19, 15, n, 9565938));
	}
	return (struct f2){-r.a/(len-3), -r.b/(len-3)};
}