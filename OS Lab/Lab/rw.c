#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t reader,writer;
int i=0,d;

void *write(void *args)
{
	int *n=(int*)args;
	while(i<8)
	{
		sem_wait(&writer);
		d=i+1;
		printf("\nwriter %d writes %d\n",*n,d);
		i++;
		sem_post(&reader);
	}
}

void *read(void *args)
{
	int *n=(int*)args;
	while(i<8)
	{
		sem_wait(&reader);
		printf("\nreader %d reads %d\n",*n,d);
		sem_post(&writer);
	}
}

main()
{
	sem_init(&reader,0,0);
	sem_init(&writer,0,1);
	int a[3];

	pthread_t w[3];
	pthread_t r[3];
	void *status;
	int i;
	for(i=0;i<3;i++)
	{
		a[i]=i+1;
		pthread_create(&w[i],NULL,write,&a[i]);
		pthread_create(&r[i],NULL,read,&a[i]);
	}
	
	for(i=0;i<3;i++)
	{
		pthread_join(w[i],status);
		pthread_join(r[i],status);
	}
}
