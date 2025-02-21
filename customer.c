#include <stdio.h>
#include <string.h>

#define MAX 100  

int main() {
    int queue[MAX], front = 0, rear = 0, callID = 101, n, i;
    char names[MAX][50];

    printf("Enter the number of calls: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Enter caller name: ");
        scanf("%s", names[rear]);
        queue[rear] = callID++;  
        printf("New Call Added: Call %d from %s\n", queue[rear], names[rear]);
        rear++;
    }

    
    printf("\nProcessing Calls:\n");
    while (front < rear) {
        printf("Processing Call: %d from %s\n", queue[front], names[front]);
        front++;

        
        if (front < rear) {
            printf("Remaining Calls: ");
            for (i = front; i < rear; i++) {
                printf("%d from %s  ", queue[i], names[i]);
            }
            printf("\n");
        } else {
            printf("No remaining calls.\n");
        }
    }

    return 0;
}

