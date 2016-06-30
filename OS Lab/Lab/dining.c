#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
 
sem_t mutex;
sem_t S[N];
 
int ate[N];
int thought[N];
 	
void *philospher(void *num);
void take_fork(int);
void think(int);
void test(int);
 
int state[N];
int phil_num[N]={0,1,2,3,4};
 
int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    printf("OUTPUT\n");
    for(i=0;i<N;i++){
        sem_init(&S[i],0,0);
        ate[i] = 0;
        thought[i] = 0;
       }
    for(i=0;i<N;i++)
    {
        pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);
        printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);
}
 
void *philospher(void *num)
{
    while(1)
    {
    int *i = num;
    	if (ate[*i] && thought[*i]){
    		printf("*Philosopher %d left the table\n", (*i)+1);
    		return;
    	}
        
        sleep(1);
        take_fork(*i);
        sleep(0);
        think(*i);
    }
}
 
void take_fork(int ph_num)
{
	if(ate[ph_num])
		return;
    sem_wait(&mutex);
    state[ph_num] = HUNGRY;
    test(ph_num);
    sem_post(&mutex);
    sem_wait(&S[ph_num]);
    sleep(1);
}
 
void test(int ph_num)
{
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[ph_num] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
        printf("Philosopher %d is Eating\n",ph_num+1);
        ate[ph_num] = 1;
        sem_post(&S[ph_num]);
    }
}
 
void think(int ph_num)
{
	if(thought[ph_num])
		return;
		
    sem_wait(&mutex);
    state[ph_num] = THINKING;
    printf("Philosopher %d puts fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
    printf("Philosopher %d is thinking\n",ph_num+1);
    thought[ph_num] = 1;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}	
