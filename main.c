// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <omp.h>
#include <cstdio>
#define N 50
int prime[N];
int tidarray[N];

int main() {
	int quo, rem, n, k;
	n = 3;
	prime[0] = 2;
	prime[1] = n;
	k = 1;
	int tid = 1;
#pragma omp parallel for shared(tid)
	tid = omp_get_thread_num();
	if (tid == 2) {
		printf("asd");
	}
	for (int j = 2; j < N; j++) {
		n = n + 2;
		quo = n / prime[k];
		rem = n % prime[k];
		if (rem != 0) {
			if (quo <= prime[k]) {
				prime[j] = n;
				tidarray[j] = tid;
				k = 1;
			}
			else {
				k++;
				j--;
				n = n - 2;
			}
		}
		else
		{
			j--;
		}
	}

	for (int j = 0; j < N; j++) {
		printf("prime:%d Thread id:%d\n", prime[j], tidarray[j]);
	}

	std::getchar();
}

