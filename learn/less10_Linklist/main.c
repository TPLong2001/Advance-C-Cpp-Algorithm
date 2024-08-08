#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* next;
}node;



node *createNode(int value); 

void push_back(node** array, int value);            // them 1 node vao phia sau
void insert(node **array, int value, int pos);      // them 1 node vao mot vi tri bat ky
void pop_back(node **array);                        // xoa 1 node o phia sau
int size(node *array);                              // lay kich thuoc cua list
void delete_list(node **array, int pos);            // xoa 1 node tai mot vi tri bat ky
void clear_list(node **array);                      // thu hồi toàn bộ list


int get(node *array, int pos);                      // lay gia tri cua 1 node bat ky
bool empty(node *array);                            // kiem tra list co rong hay khong




node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp = createNode(value);     // khoi tao node
                                        // temp = 0xa1
    if (*array == NULL)                 // list rỗng
    {

        *array = temp;
    }
    else                                // if array has some node
    {
        node* p = *array;               // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL)         // which mean the current node is not the last node
        {
            p = p->next;                // check next node until it a last node

        }

        p->next = temp;                 // change it next member point to address of new node have just create
    }
}

void insert(node **array, int value, int pos)
{
    node* temp = createNode(value);
    if (*array == NULL)                 // list rỗng
    {
        *array = temp;
    }
    else if(pos == 0)
    {
        temp->next = *array;
        *array = temp;
    }
    else if(pos > 0)
    {
        node* p = *array;
        int i = 0;

        while ((p->next != NULL)&&((pos - 1) != i))     // free the last node in the list
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void pop_back(node** array)
{
    if (*array == NULL)                 // list rỗng
    {
        printf("Error: List is empty!\n");
    }
    else{
        node* p, * temp;
        p = *array;
        while (p->next->next != NULL)     // free the last node in the list
        {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        free(temp);
    }
}

int size(node *array){
    node* p = array;
    int i = 1;
    if (p == NULL)                 // list rỗng
    {
        return 0;
    }

    while(p->next != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

void delete_list(node **array, int pos)            // xoa 1 node tai mot vi tri bat ky
{
    node* p,* temp;
    p = *array;
    if (*array == NULL)                 // list rỗng
    {
        printf("Error: List is empty!\n");
    }
    else if(pos == 0)
    {
        *array = p->next;
        free(p);
    }
    else if(pos > 0)
    {
        int i = 0;

        while ((p->next != NULL)&&((pos - 1) != i))     // free the last node in the list
        {
            p = p->next;
            i++;
        }

        if (pos != i)
        {
            printf("Error: List has not element %d\n",pos);
        }
        else{
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }

    }
}

void clear_list(node **array)                     // thu hồi toàn bộ list
{
    while(*array != NULL)
    {
        node* p = *array;
        *array = (*array)->next;
        free(p);
    }
}

int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

bool empty(node *array)                            // kiem tra list co rong hay khong
{
    if(array == NULL)
        return 1;
    return 0;
}



int main()
{
    node* arr = NULL;       //list: 2-7-4-5-3-10
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    insert(&arr,1,0);
    delete_list(&arr,0);


    printf("Size test: %d\n",size(arr));
    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));

    clear_list(&arr);
    if(empty(arr)){
        printf("List is empty!\n");
    }

	return 0;
}

