#pragma once

#include <iostream>

class CDijkstra
{
public:
	CDijkstra(int **gr, int tN, int S, int F);
	~CDijkstra(void);
private:
	int min(int ar[]);
	int N;
	int *Active;
};

