#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertion(int data)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node* p=head;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void display(struct Node* head)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    int input;
    while(1)
    {
    printf("\nenter the data to insert: ");
    scanf("%d",&input);
    insertion(input);
    display(head);
    }
}