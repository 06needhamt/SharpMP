#include "omp.h"
#include <stdio.h>

extern "C" {
	__declspec(dllexport) int dllFunc() {
		#pragma omp parallel
		printf("thread %d\n", omp_get_thread_num());
		return 0;
	}
}