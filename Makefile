all: sp.c
	gcc sp.c -Wall -Wextra -Ofast -s -march=native -shared -fPIC -osp.so	
