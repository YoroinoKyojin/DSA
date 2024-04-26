#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node* next; 
}; 
 
struct node *front = NULL, *rear = NULL; 
 
void enqueue(int item) { 
    struct node* tmp; 
    tmp = (struct node*)malloc(sizeof(struct node)); 
    if (tmp == NULL) { 
        printf("Memory unavailable\n"); 
        return; 
    } 
    tmp->data = item; 
DSA Day 7 March 7, 2024 
75 | Page 
 
    tmp->next = NULL; 
    if (front == NULL) { 
        front = tmp; 
    } else { 
        rear->next = tmp; 
    } 
    rear = tmp; 
} 
 
int dequeue() { 
    struct node* tmp; 
    int item; 
    if (front == NULL) { 
        printf("Queue Underflow\n"); 
        printf("Exiting program\n"); 
        exit(1); 
    } 
    tmp = front; 
    item = tmp->data; 
    front = front->next; 
    free(tmp); 
    return item; 
} 
 
int isEmpty() { 
    return (front == NULL); 
} 
 
void display() { 
    struct node* tmp = front; 
    if (isEmpty()) { 
        printf("Queue is empty\n"); 
        return; 
    } 
    printf("Queue elements: "); 
    while (tmp != NULL) { 
        printf("%d ", tmp->data); 
        tmp = tmp->next; 
    } 
    printf("\n"); 
} 
 
void bfs(int matrix[8][8], int* visited, int src) { 
    enqueue(src); 
    visited[src] = 1; 
    while (!isEmpty()) { 
        int node = dequeue(); 
        display(); 
        printf("Visiting node: %d\n", node); 
        printf("Visited array: "); 
        for (int i = 0; i < 8; i++) { 
            printf("%d ", visited[i]); 
        } 
        printf("\n"); 
        for (int i = 0; matrix[node][i] != -1 && i < 8; i++) { 
            if (visited[matrix[node][i]] == -1) { 
                enqueue(matrix[node][i]); 
                visited[matrix[node][i]] = 1; 
            } 
        } 
    } 
} 
 
int main() { 
    int matrix[8][8] = { 
        {1, 3, -1, -1, -1, -1, -1, -1}, 
        {2, 0, -1, -1, -1, -1, -1, -1}, 
        {1, -1, -1, -1, -1, -1, -1, -1}, 
        {0, 4, 5, -1, -1, -1, -1, -1}, 
        {3, 5, 6, -1, -1, -1, -1, -1}, 
        {3, 4, 6, 7, -1, -1, -1, -1}, 
        {4, 5, 7, -1, -1, -1, -1, -1}, 
        {5, 6, -1, -1, -1, -1, -1, -1} 
    }; 
 
    int visited[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; 
    bfs(matrix, visited, 0); 
DSA Day 7 March 7, 2024 
76 | Page 
 
 
    return 0; 
} 