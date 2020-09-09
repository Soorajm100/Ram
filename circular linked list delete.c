#include <stdio.h>


struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;

    void insert(int x)
    {
       
           
    struct node* temp = (struct node*) malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node* temp1=head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;

        }
    }

    void createcircular()
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
    }


    void destroy(int k)
    {
        if(k!=1)
        {
            struct node* temp=head;
            int c=1;
            while(c<k-1)
            {
                temp=temp->next;
                c++;
            }
            temp->next=temp->next->next;
        }
        else
        {
            struct node* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            head=temp->next->next;
            temp->next=temp->next->next;
        }
    }

    void print()
    {
        struct node* temp=head;
        printf("%d",temp->data);
        temp=temp->next;
        while(temp!=head)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }


int main()
{
    int t,n;
   while(t){
       
   printf("enter the element to be inserted into the circular linked list");
   scanf("%d",&n);
    insert(n);
    printf("Enter 1 to continue to insert else enter 0 to stop");
    scanf("%d",&t);
   }
    createcircular();
    disp();
    int k;
    printf("enter position you want to delete: \n");
    scanf("%d",&k);
    destroy(k);
    print();
    return 0;
}
