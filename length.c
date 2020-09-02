#include <stdio.h>
#include<conio.h>
/* Link list node */
struct link 
{ 
    int data; 
    struct link* next; 
}; 
  

void insert(struct link** head_ref, int new_data) 
{ 
   
    struct link* new_node = 
            (struct link*) malloc(sizeof(struct link)); 
  
   
    new_node->data  = new_data; 
  
   
    new_node->next = (*head_ref); 
  
    
    (*head_ref)    = new_node; 
} 
  


  

int main() 
{ 

    int t=1;
    struct link* start = NULL; 
    int n;
  
  
     while(t){
         
     printf("Enter the element to be inserted");
     scanf("%d",&n);
    insert(&start, n); 
    printf("Dou u want to add more elements if yes press 1 else press 0");
    scanf("%d",&t);
     }
    
      int count = 0;  
    struct link* current = start;  
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
 
    printf("count of nodes is %d", count); 
    return 0; 
} 
 
