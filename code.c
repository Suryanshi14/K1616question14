#include<stdio.h>
#include<unistd.h>

#include<stdlib.h>
#include<malloc.h>
#include<pthread.h>
#include<semaphore.h>
struct Process {
	int priority,time,Atime,Btime;
	clock_t arrival;
	int flag,completed,p;
	sem_t se;
	struct Process *next;
};
int i=0,z=1;
float WT=0,TAT=0;
clock_t start;
struct Process *front=NULL,*temp,*rear=NULL;
typedef struct Process node;
void pop() {
	node *start=rear;
	printf("\nArrival Time :%d",start->next->Atime);
}
void push() {
	temp=(node *)malloc(sizeof(node));
	printf("\nEnter Priority of %d Process :",(i+1));
	scanf("%d",&temp->priority);
	printf("Enter Arrival Time :");
	scanf("%d",&temp->Atime);
	int p=temp->priority;
	printf("Enter Burst Time :");
	scanf("%d",&temp->time);
	temp->Btime=temp->time;
	sem_init(&temp->se,0,0);
	int t=temp->Atime;
	temp->flag=1;
	temp->p=1;
	node *start=front;
	if ((start->Atime > t) || (start->Atime==t && start->priority > temp->priority)){
        	temp->next = front;
        	front=temp;
    	}
    	else {
        	while (start->next != NULL && start->next->Atime <= t) {
            		if(start->next->Atime==t && temp->priority<start->next->priority) {
            			break;
					}
					else
					start = start->next;
            		
        	}
        temp->next = start->next;
        start->next = temp;
    }
}
void main() {
	int n,l=1;
	pthread_t p[10];
	printf("\nEnter No.of Processes :");
	scanf("%d",&n);
	while(i<n) {
		printf("*");
		if(front==NULL) {
			front=(node *)malloc(sizeof(node));
			printf("Enter Priority of %d Process :",(i+1));
			scanf("%d",&front->priority);
			printf("Enter Arrival Time :");
			scanf("%d",&front->Atime);
			printf("Enter Burst Time :");
			scanf("%d",&front->time);
			front->flag=1;
			front->p=1;
			front->Btime=front->time;
			sem_init(&front->se,0,0);
			front->next=NULL;
		}
		else {
			push();
		}
		i++;
	}
	
	for(i=0;i<n;i++) {
		pthread_join(p[i],NULL);
	}
	printf("Average Waiting Time :%f\nAverage Turn Around Time :%f",(float)WT/n,(float)TAT/n);
}
