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
	int flag = 0;


	printf("Enter no.of processes: ");
	scanf("%d", &nproc);

	printf("Enter burst time of each process: ");
	for (i = 0; i < nproc;  i++){
		scanf("%d", &bursttime[i]);
		waiting[i] = -1;
	}

	printf("Enter time quantum : ");
	scanf("%d", &timequantum);
	
	printf("Executing processes:\n");
	printf("Process           Time\n");
	printf("----------------------\n");
	for(i = 0; 1; i = (i + 1)%nproc){
		if(waiting[i] == -1){
			waiting[i] = clock;
			waitingtotal += clock;
		}
		//clock += 1;
		if(bursttime[i] == 0){}
			
		else if(bursttime[i] < timequantum){
			printf("%2d              %3d-%d \n", i+1, clock, clock+bursttime[i]);
			clock += bursttime[i];
			bursttime[i] = 0;
		}
		else{
			printf("%2d              %3d-%d \n", i+1, clock, clock+timequantum);
			clock += timequantum;
			bursttime[i] -= timequantum;
		}

		flag = 0;
		for(j = 0; j < nproc; j++)
			if(bursttime[j] != 0)
				flag = 1;

		if(flag)
			continue;
		else
			break;
	}


	printf("Waitiing times:\n");
	for(i = 0; i < nproc; i++)
		printf("Process%d : %d\n", i+1, waiting[i]);
	
	printf("\nAverage waiting time = %.2f\n", (float)waitingtotal/nproc);

	return 0;
}

