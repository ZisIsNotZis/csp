all: sp s2p

sp: sp.c
	gcc sp.c -Wall -Wextra -Ofast -s -march=native -shared -osp.so

s2p: s2p.c
	gcc s2p.c -Wall -Wextra -Ofast -s -march=native -shared -os2p.so
