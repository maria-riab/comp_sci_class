#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


node* list(void); //make list

node* new_node(int value); //new node

node* insert_head(node* head, node* node_to_insert); // insert at head of list

void print_list(node* head); //print list

node* search_list_return_node(node* head, int data_point); // search list and return node if found

node* insert_after_node(node* head, node* before_insert, node* node_to_insert); // insert after particular node

node* delete_node(node* head, node* data_to_delete);// delete particular node

node* delete_list(node*head);// delete whole list


int main (void)
{
    node* head = list();
    print_list(head);

    node* head2 = insert_head(head, new_node(15));

    print_list(head2);

    int search = printf("what number do you want to find?: ");
    scanf("%i", &search);
    node* found = search_list_return_node(head2, search);
    if (found == NULL)
    {
        printf("not found \n");
    }
    else
    {
        printf("found - %i \n", found->data);
    }

    node* head3 = insert_after_node(head2, found, new_node(found->data + 1));
    print_list(head3);

    node* head4 = delete_node(head3,found);
    print_list(head4);
    
    node* deleted = delete_list(head4);
    printf("the list is deleted, there is only %p \n", deleted);

}

// make list
node* list(void)
{
    node* head = NULL;
    node* temp;

    for (int i = 0; i < 15; i++)
    {
        temp = new_node(i);
        temp->next = head;

        head = temp;
    }
    return head;

}

//new node
node* new_node(int value)
{
    node* result = malloc(sizeof(node));
    if (result != NULL)
    {
        result->data = value;
        result->next = NULL;
    }
    return result;
}

//add to head of list
node* insert_head(node* head, node* node_to_insert)
{
    node_to_insert->next = head;
    head = node_to_insert;
    return head;
}

//print list
void print_list(node* head)
{
    node* temp = head;

    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("end of list");
    printf("\n");
}

//search list
node* search_list_return_node(node* head, int data_point)
{
    node* trav = head;
    if (data_point == head->data)
    {
        return head;
    }

    while (trav != NULL)
    {

        if (data_point == trav-> data)
        {
            return trav;
        }
        trav = trav->next;

    }
    return NULL;
}

// inserting after a node
node* insert_after_node(node* head, node* before_insert, node* node_to_insert)
{
    node_to_insert->next = before_insert->next;
    before_insert->next = node_to_insert;
    return head;
}

//delete node
node* delete_node(node* head, node* data_to_delete)
{
    node* temp = head;
    if (data_to_delete == head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    while (temp != NULL)
    {
        if (temp->next == data_to_delete)
        {
            temp->next = temp->next->next;
            free(data_to_delete);
        }

        temp = temp->next;
    }
    return head;

}

//delete list
node* delete_list(node*head)
{
    node* temp;

    while (head != NULL)
    {
       temp = head->next;
       free(head);
       head = temp;
    }

    return NULL;
}
