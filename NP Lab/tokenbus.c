// Program to implement Token Bus

#include<stdio.h>
#include<string.h>

#define MAX 256

struct frame {
	int source, destination;
	int ack;
	char data[MAX];
};

typedef struct frame frame;

void main() {
	
	int i, j, n, c;
 	printf("\n Enter the number of nodes in the bus: ");
 	scanf("%d", &n);
 	frame packet[n];
 	printf("\n Enter the logical arrangement: ");
 	for(i = 0;i < n; i++)
  		scanf("%d", &packet[i].source);
 	for(i = 0; ;i = (i+1)%n) {
  		printf("\n\n Node %d has token.",packet[i].source);
  		printf("\n Want to send data? (1 - Yes / 0 - No): ");
  		scanf("%d", &c);
  		if(c == 0)
   			continue;
  		else {
 	 		printf("\n Enter the destination node: ");
  			scanf("%d", &packet[i].destination);
  			if(packet[i].source == packet[i].destination) {
   				printf("\n Source and destination are the same node %d.",packet[i].destination);
   				break;
  			}
  			printf("\n Enter the data to send: ");
  			scanf("%s", packet[i].data);
  			j = (i+1) % n;
  			while(1) {
			   	if(packet[j].source == packet[i].source && packet[i].ack == 1) {
					printf("\n Node %d releases token.", packet[i].source);
    				break;
   				}
   				else if(packet[j].source == packet[i].source && packet[i].ack != 1) {
					printf("\n Node %d is not available. \n", packet[i].destination);
					i--;
    				break;
   				}
   				else if(packet[j].source == packet[i].destination) {
    				printf("\n Node %d receives data: '%s'", packet[i].destination, packet[i].data);
    				packet[i].ack = 1;
   				}
   				else 
    				printf("\n Node %d forwards data.", packet[j].source);
   				j=(j+1)%n;
  			} 
 		} 
	}
}
