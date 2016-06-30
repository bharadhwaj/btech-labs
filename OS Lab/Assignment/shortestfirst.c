#include <stdio.h>
#define MAX 256

int main()
{
	int nproc, i, j;
	int bursttime[MAX];
	int waiting[MAX];
	int waitingtotal = 0;
	int clock = 0;
	int timequantum = 0;
	int flag = 1;
	int minburst, selectedproc;


	printf("Enter no.of processes: ");
	scanf("%d", &nproc);

	printf("Enter burst time of each process: ");
	for (i = 0; i < nproc;  i++){
		scanf("%d", &bursttime[i]);
		waiting[i] = -1;
	}

	
	printf("Executing processes:\n");
	printf("Process           Time\n");
	printf("----------------------\n");
	while(flag){
		minburst = 9999;
		selectedproc = -1;
		for(i = 0; i < nproc; i++){
			if(bursttime[i] != 0){
				if(minburst > bursttime[i]){
					minburst = bursttime[i];
					selectedproc = i;
				}
			}
		}
		waiting[selectedproc] = clock;
		waitingtotal += clock;
		//clock += 1;
		printf("%2d              %3d-%d \n", selectedproc+1, clock, clock+bursttime[selectedproc]);
		clock += bursttime[selectedproc];
		bursttime[selectedproc] = 0;

		flag = 0;
		for(j = 0; j < nproc; j++)
			if(bursttime[j] != 0)
				flag = 1;

	}


	printf("Waitiing times:\n");
	for(i = 0; i < nproc; i++)
		printf("Process%d : %d\n", i+1, waiting[i]);
	
	printf("\nAverage waiting time = %.2f\n", (float)waitingtotal/nproc);

	return 0;
}

