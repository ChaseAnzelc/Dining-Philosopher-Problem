#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>

typedef struct{
        int ID;
} param_structure;

#define THREAD_NUM 5
#define MAX_ITERATION 9000
sem_t chopsticks[THREAD_NUM];
// Need to use the following functions in the right place with the right parameters
// sem_init() 
// sem_wait()
// sem_post()

void *philosopher(void *param)
{
    int phID=((param_structure *)param)->ID;
	int i;
	printf("Philosopher %d: Starting to RUN\n",phID);
		

	for(i=0;i<MAX_ITERATION;i++){
		
		printf("Philosopher %d: THINKING\n",phID);
				
		printf("Philosopher %d: HUNGRY\n",phID);	
		
		if(phID < ((phID+1)%THREAD_NUM)){
		sem_wait(&chopsticks[phID]);
				}
		else{
		sem_wait(&chopsticks[(phID+1)%THREAD_NUM]); 
		}
		
		printf("Philosopher %d: picked up my first chopstick\n",phID);	

		if(phID < ((phID+1)%THREAD_NUM)){
		 sem_wait(&chopsticks[(phID+1)%THREAD_NUM]);
		}
		else{
		sem_wait(&chopsticks[phID]);
		}


		printf("Philosopher %d: picked up my second chopstick\n",phID);	

		usleep(1);

		printf("Philosopher %d: EATING\n",phID);

		sem_post(&chopsticks[(phID+1)%THREAD_NUM]);
		sem_post(&chopsticks[phID]);

		
			

	}
	printf("Philosopher %d: Done RUNNING thinking\n",phID);	
        pthread_exit(0);
}

int main()
{
	int i;
        pthread_t tid[THREAD_NUM]; /* the thread identifier */
        param_structure params[THREAD_NUM]; 
        pthread_attr_t attr; /* set of attributes for the thread */


        /* get the default attributes */
        pthread_attr_init(&attr);

	
				for(i=0;i<THREAD_NUM;i++){
					
					
		sem_init(&chopsticks[i],0,1);
			}


        /* create the threads */
        for (i=0;i<THREAD_NUM;i++){
		params[i].ID = i;
        	pthread_create(&tid[i],&attr,philosopher,(void *)&params[i]);
	}

        /* now wait for the thread to exit */
        for (i=0;i<THREAD_NUM;i++)
                pthread_join(tid[i],NULL);

	printf("Parent Done\n");
}

