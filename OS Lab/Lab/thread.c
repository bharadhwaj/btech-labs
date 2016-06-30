#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t m[5];

void* fn(void *arg)
{
	int *n=(int*)arg,value;
	printf("\n Philosopher %d is thinking. . .\n",*n+1);
	if(*n%2!=0)
	{
		sem_wait(&m[*n]);
		printf("\n Philosopher %d took left fork\n",*n+1);

		sem_wait(&m[(*n+1)%5]);
		printf("\n Philosopher %d took right fork\n",*n+1);

		printf("\n Philosopher %d is eating. . .\n",*n+1);
		sleep(1);

		printf("\n Philosopher %d put right fork\n",*n+1);
		sem_post(&m[(*n+1)%5]);

		printf("\n Philosopher %d put left fork\n",*n+1);
		sem_post(&m[*n]);
	}
	else
	{
		sem_wait(&m[(*n+1)%5]);
		printf("\n Philosopher %d took right fork\n",*n+1);

		sem_wait(&m[*n]);
		printf("\n Philosopher %d took left fork\n",*n+1);

		printf("\n Philosopher %d is eating. . .\n",*n+1);
		sleep(1);

		printf("\n Philosopher %d put left fork\n",*n+1);
		sem_post(&m[*n]);

		printf("\n Philosopher %d put right fork\n",*n+1);
		sem_post(&m[(*n+1)%5]);
	}
		
	return NULL;
}

main()
{
	pthread_t tid[5];
	void *status;
	int i,a[5];

	for(i=0;i<5;i++)
	{
		a[i]=i;
		sem_init(&m[i],0,1);
		pthread_create(&tid[i],NULL,fn,&a[i]);
	}
	
	for(i=0;i<5;i++)
		pthread_join(tid[i],&status);
		
	return 0;
}
