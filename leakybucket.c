#include <stdio.h>
#include <stdlib.h>

#define capacity 50

void main() {
    int timeLimit = 10;
    int bucketCapacity = 0, outputRate = 5;
    
    while(timeLimit < 20) {
        int newPacket;
        printf("\nenter new packet size: ");
        scanf("%d", &newPacket);
        
        if(newPacket < capacity) {
            bucketCapacity = bucketCapacity + newPacket;
            printf("\nbucket capacity currently: %d", bucketCapacity);
            bucketCapacity = bucketCapacity - outputRate;
            printf("\nbucket capacity after output: %d", bucketCapacity);
            timeLimit++;
        } 
        else if(newPacket > capacity || (newPacket + bucketCapacity) > capacity) {
            printf("\nnew packet cannot be added to bucket");
            bucketCapacity = bucketCapacity - outputRate;
            printf("\nbucket capacity after output: %d", bucketCapacity);
        } 
        else if(bucketCapacity < 0) {
            bucketCapacity = 0;
            printf("\nbucket capacity after output: %d", bucketCapacity);
            timeLimit++;
            exit(0);
        }
    }
}