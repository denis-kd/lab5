// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
#include "time.h"
#include "conio.h"
#include <queue>
using namespace std;

int A[5][5], vis[5] = {0};

void BFS(int n)
{
	queue <int> Q;
	Q.push(n);
	vis[n] = 1;
	while(!Q.empty()) {
		n = Q.front();
		printf("%d ", n);
		Q.pop();
		for(int i = 0; i < 5; i++) {
			if((A[n][i] == 1) && !vis[i]) {
				Q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	DWORD Start = 0, End = 0;
	int i = 0, j = 0, r = 0;
	for(; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			if(i != j) {
				A[i][j] = rand() % 2;
				A[j][i] = A[i][j];
			}
			else {
				A[i][j] = 0;
			}
		}
	}
	i = 0; j = 0;
	for(; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
	BFS(0);
	getch();
	return 0;
}
