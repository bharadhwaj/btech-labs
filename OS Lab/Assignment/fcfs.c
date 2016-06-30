#include <stdio.h>
#define MAX 256

int main()
{
	int nproc, i;
	int bursttime[MAX];
	int waiting[MAX];
	int waitingtotal = 0;
	int clock = 0;

	printf("Enter no.of processes: ");
	scanf("%d", &nproc);

	printf("Enter burst time of each process: ");
	for (i = 0; i < nproc;  i++)
		scanf("%d", &bursttime[i]);
	
	printf("Executing processes:\n");
	printf("Process           Time\n");
	printf("----------------------\n");
	for(i = 0; i < nproc; i++){
		waiting[i] = clock;
		waitingtotal += clock;
		clock += 1;
		printf("%2d              %3d-%d \n", i+1, clock, clock+bursttime[i]);
		clock += bursttime[i];
	}

	printf("Waitiing times:\n");
	for(i = 0; i < nproc; i++)
		printf("Process%d : %d\n", i+1, waiting[i]);
	
	printf("\nAverage waiting time = %.2f\n", (float)waitingtotal/nproc);

	return 0;
}

