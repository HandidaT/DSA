//a1r12c0
#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main(){
	time_t start = time(NULL);
	sleep(2);
	time_t end = time(NULL);
	printf("%ld", end - start);
	
	
	clock_t start1, end1;//This gives more precision
	double cpu_time_used;

	start1 = clock();
	/* Do the work. */
	end1 = clock();
	cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
	printf("\n%f",cpu_time_used);
}





























































/*
int main(){
	time_t begin=time(NULL);
	sleep(2);
	time_t end=time(NULL);
	time_t timetaken=end-begin;
	printf("%ld",timetaken);
}*/
