# include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


node* normal_list(void);

node* dynamically_create_list(void);

void print_list(node* head);

node *new_node(int value);

node* insert_head(node**head, node *node_to_insert);

void insert_after_node(node* node_to_insert_after, node* new_node);

node* search_list(node* head, int value);

void delete_node(node*found, node* head);

void delete_list(node* head);


int main(void)
{
    node* list = normal_list();

    print_list(list);

    node* found = search_list(list, 10);

    if (found == NULL)
    {
        printf("not found \n");
        return 1;
    }

    else
    {
        printf("found : %i \n", found->data);

    }


    insert_after_node(found, new_node(11));

    print_list(list);

    delete_node(found, list);
    
    print_list(list);
    
    //this is what prints out:
    //~/practice/ $ ./list
    //10 - 9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1 - end of list
    //found : 10 
    //10 - 11 - 9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1 - end of list
    //0 - 11 - 9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1 - end of list
    
    //valgrind says:
   // ==379== Invalid read of size 4
    //==379==    at 0x400803: print_list (list.c:107)
    //==379==    by 0x400766: main (list.c:57)
    delete_list(list);

}

node* normal_list(void)
{
    node* head = NULL;
    node* temp;

    for (int i = 0; i < 10; i++)
    {
        temp = new_node(i+1);
        insert_head(&head, temp);
    }
    return head;
}



node* dynamically_create_list(void)
{
    node* head = NULL;
    node* temp;
    int amount;

    printf("how many items are there in your list?: ");
    scanf("%i", &amount);
    printf("\n");

    for (int i = 0; i < amount; i++)
    {
        int value;
        printf("number: ");
        scanf("%i", &value);

        temp = new_node(value);
        insert_head(&head, temp);

    }
    return head;

}
void print_list(node* head)
{
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }

    printf("end of list");

    printf("\n");
}


node *new_node(int value)
{
    node* result = malloc(sizeof(node));

    if (result != NULL)
    {
        result->data = value;
        result->next = NULL;
    }
    return result;

}

node* insert_head(node**head, node *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;


}

void insert_after_node(node* node_to_insert_after, node* new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

node* search_list(node* head, int value)
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }

        temp = temp->next;
    }
    return NULL;
}





void delete_list(node* head)
{
    node* temp;

    while (head != NULL)
    {
       temp = head->next;
       free(head);
       head = temp;
    }

}






void delete_node(node*found, node* head)
{
    node* temp = head;

    while (temp != NULL)
    {
        if (head == found)
        {
            temp = head->next;
            free(head);
            head = temp;
        }

        if (temp->next == found)
        {
            temp->next = temp->next->next;
            free(found);
        }

        temp = temp->next;
    }
}


