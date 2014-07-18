#include "Dijkstra.h"


CDijkstra::CDijkstra(int **gr, int tN, int S, int F)
{
	N = tN;
	int *Label = new int [N];
	Active = new int [N];
	int i(0), j(0);
	for (i = 0; i < N; i++)
	{
		Label[i] = 32000;
		Active[i] = 0;
	}

	Active[S] = 1;
	Label[S] = 0;
	i = S;
	do 
	{
		for (j = 0; j < N; j++)
		{
			if ((gr[i][j] != 0) && (Label[j] > Label[i] + gr[i][j]))
			{
				Active[j] = 1;
				Label[j] = Label[i] + gr[i][j];
			}
		}
		Active[i] = 0;
		i = min(Label);

	} while (i != -1);



	delete [] Label;
	delete [] Active;
}


CDijkstra::~CDijkstra(void)
{
	
}

int CDijkstra::min(int ar[])
{
	int min(32001), minPos(-1);
	for (int i(0); i < N; i++)
	{
		if ((ar[i] < min) && (Active[i] == 1))
		{
			min = ar[i];
			minPos = i;
		}
	}
	return minPos;
}
