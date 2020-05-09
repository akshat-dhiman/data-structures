#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *ptr;
struct node *graph_insert(struct node *adj[], int val, int n){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (adj[n] == NULL){
        adj[n] = new_node;
        ptr = adj[n];
    }
    else{
        ptr->next = new_node;
        ptr = new_node;
    }
    return adj;
}

void display_graph(struct node *adj[], int nodes_no){
    struct node *ptr;
    for(int i=0;i<nodes_no;i++){
        ptr = adj[i];
        while(ptr != NULL){
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

// a proper traversal technique. display func is just to display the enterd nodes not traversal.
void breadth_first_search(int adj_matrix[][20], int nodes_no){
  /* in breadth first search, we use adjacency matrix instead of list because in matrix the node relation is in order n it is easy to
  mark visited nodes(required in bfs) while in list the neighbours r present in linked list in any order.*/
    int queue[nodes_no], front = -1, rear = -1, visited[nodes_no];
    queue[++rear] = 0; // starting with 0th row of adjacency matrix. next, we'll put neighbours of 0th node from 0th row of matrix in queue.
    for(int i=0;i<nodes_no;i++)
        visited[i] = 0;
    visited[rear] = 1;
    while(front < rear){
        for(int i=0;i<nodes_no;i++){
            if (visited[i] == 0 && adj_matrix[queue[front+1]][i] == 1){   // front+1 is the node going to be dequeued from the queue.
                queue[++rear] = i;       // gotta add the node no i.e. column to the queue
                visited[i] = 1;
            }
        }
        front++;     // node dequeued.
        printf("\t%c", queue[front] + 65);
    }
}

void depth_first_search(int adj_matrix[][20], int nodes_no){
    int stk[nodes_no], top = -1, visited[nodes_no], i;
    for(i=0;i<nodes_no;i++)
        visited[i] = 0;
    stk[++top] = 0;
    visited[top] = 1;
    printf("\t%c", stk[top] + 65);
    while(top > -1){
        for(i=0;i<nodes_no;i++){
            if(adj_matrix[stk[top]][i] == 1 && visited[i] == 0){
                stk[++top] = i;
                visited[i] = 1;
                printf("\t%c", stk[top] + 65);
                break;
            }
        }
        if (i == nodes_no)
            top--;
    }
}

void delete_graph(struct node *adj[], int nodes_no){
    struct node *ptr, *preptr;
    for(int i=0;i<nodes_no;i++){
        ptr = adj[i];
        while(ptr != NULL){
            preptr = ptr;
            ptr = ptr->next;
            free(preptr);
        }
    }
    printf("\nGraph deleted successfully.");
}

int main(){
    int nodes_no, neighbour_no, val;
    printf("Enter the number of elements in the graph:");
    scanf("%d", &nodes_no);
    struct node *adj[nodes_no];
    for(int i=0;i<nodes_no;i++){
        adj[i] = NULL;
        printf("\nEnter no. of neighbours of node %d:", i+1);
        scanf("%d", &neighbour_no);
        printf("\nEnter their values :");
        for(int j=0;j<neighbour_no;j++){
            scanf("%d", &val);
            graph_insert(adj, val, i);
        }
    }
    printf("\nThe Graph:");
    display_graph(adj, nodes_no);
    delete_graph(adj, nodes_no);
    int adj_matrix[nodes_no][nodes_no];    //adjacency matrix
    printf("\nEnter the adjacency matrix of above graph:\n");
    for(int i=0;i<nodes_no;i++){
            for(int j=0;j<nodes_no;j++){
                scanf("%d", &adj_matrix[i][j]);
            }
    }
    printf("\nBreadth First Search Traversal of the graph:\n");
    breadth_first_search(adj_matrix, nodes_no);
    printf("\nDepth First Search Traversal of the graph:\n");
    depth_first_search(adj_matrix, nodes_no);
    return 0;
}
