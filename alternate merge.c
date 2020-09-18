/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link* next;
}*x=NULL,*y=NULL;
int main()
{
    int n,m;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);
    struct link* p2=(struct link*)malloc(sizeof(struct link));
    struct link* header1=(struct link*)malloc(sizeof(struct link));
    struct link* header2=(struct link*)malloc(sizeof(struct link));
    for(int i=0;i<n;i++)
    {
        struct link* t1=(struct link*)malloc(sizeof(struct link));
        t1->data=i;
        t1->next=x;
        x=t1;
    }
    for(int j=m;j>0;j--)
    {
        struct link* t2=(struct link*)malloc(sizeof(struct link));
        t2->data=j*j;
        t2->next=y;
        y=t2;
    }

    header1=x;
    header2=y;
    printf("\nx= ");
    for(p2=header1;p2!=NULL;p2=p2->next)
    {
        printf("%d ",p2->data);
    }
    printf("\ny= ");
    for(p2=header2;p2!=NULL;p2=p2->next)
    {
        printf("%d ",p2->data);
    }

    struct link* z=(struct link*)malloc(sizeof(struct link));
    struct link* ptr1=(struct link*)malloc(sizeof(struct link));
    struct link* ptr2=(struct link*)malloc(sizeof(struct link));;
    struct link* header3=(struct link*)malloc(sizeof(struct link));
    header3=x;
    z=header3;
    if(m<=n)
    {
        for(int i=0;i<m;i++)
        {

            ptr1=x->next;
            ptr2=y->next;
            z->next=y;
            z=y;
            z->next=ptr1;
            x=ptr1;
            z=ptr1;
            y=ptr2;

        }
        printf("\nz= ");
        for(p2=header3;p2!=NULL;p2=p2->next)
        {
            printf("%d ",p2->data);
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {

            ptr1=x->next;
            ptr2=y->next;
            z->next=y;
            z=y;
            z->next=ptr1;
            if(z->next==NULL)
            {
                z->next=ptr2;
            }
            x=ptr1;
            z=ptr1;
            y=ptr2;

        }
        printf("\nz= ");
        for(p2=header3;p2!=NULL;p2=p2->next)
        {
            printf("%d ",p2->data);
        }
    }
    return 0;
}
