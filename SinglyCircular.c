#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////
//Linear Data Structure  //github.com/VirajsShinde

//Linked List --> Singly->Circular.c  

////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE; 
typedef struct node ** PPNODE;

int iSize = 0;

////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;

        iSize++;
    }
    else
    {
        newn->next = *first;
        *first = newn;

        (*last)->next = *first;

        iSize++;
    }
}

/////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;

        iSize++;
    }
    else
    {
        (*last)->next = newn;
        (*last) = newn;

        (*last)->next = *first;

        iSize++;
    }
}

/////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = *first;

    if((*first) && (*last) == NULL)
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*first) == (*last))
    {
        free(*first);

        *first = NULL;
        *last = NULL;

        iSize--;
    }
    else
    {
        (*first) = (*first)->next;

        free(temp); 

        (*last)->next = *first;

        iSize--;
    }
}

//////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first,PPNODE last)
{
   PNODE temp = *first;

    if((*first) && (*last) == NULL)
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*first) == (*last))
    {
        free(*first);

        *first = NULL;
        *last = NULL;

        iSize--;
    }
    else
    {
        while(temp->next != (*last))
        {
            temp = temp->next;
        }
        free(temp->next);

        *last = temp;

        (*last)->next = *first;

        iSize--;
    }
}

////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE first,PPNODE last,int iNo,int iPos)
{
    PNODE temp = *first;
   
    if((iPos < 1) || (iPos > iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iSize+1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iSize++;
    }
}

////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE first,PPNODE last,int iPos)
{
    if((iPos < 1) || (iPos > iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iSize+1)
    {
        DeleteLast(first,last);
    }
    else
    {
        PNODE temp1 = *first;
        PNODE temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;

        free(temp2);

        iSize--;
    }
}

/////////////////////////////////////////////////////////////////////////

void Display(PNODE first,PNODE last)
{
    printf("Elements of Linked List are : \n");

    PNODE temp = first;

    for(int iCnt = 1; iCnt <= iSize; iCnt++)
    {
        printf("| %d |->",temp->data);
        temp = temp->next;
    }
    printf("| NULL | \n");
}

////////////////////////////////////////////////////////////////////////

void Options()
{
    printf("-------------------------------------------------------------------\n");

        printf("Please Select Desire Option : \n");
        printf("1 : Insert First \n");
        printf("2 : Insert Last \n");
        printf("3 : Insert At given Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At given Position\n");
        printf("7 : Display the contents of Linked List\n");
        printf("8 : Count Number of Nodes from Linked List\n");
        printf("9 : Options\n");
        printf("10 : EXIT\n");
        printf("-------------------------------------------------------------------\n");
}

////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    PNODE Head = NULL;
    PNODE Tail = NULL;

    int iChioce = 0, iPos = 0, iNo = 0;

    printf("\n Welcome --DS--> Singly->Circular.c | github.com/VirajsShinde\n");

    Options();

    while(1)
    {
        printf("Enter Number : ");
        scanf("%d",&iChioce);

        switch(iChioce)
        {
            case 1: 
                printf("Enter the data that you want to insert first : \n");
                scanf("%d",&iNo);

                InsertFirst(&Head,&Tail,iNo);
                Display(Head,Tail);
                break;
            
            case 2:
                printf("Enter the data that you want to insert last : \n");
                scanf("%d",&iNo);

                InsertLast(&Head,&Tail,iNo);
                Display(Head,Tail);
                break;

            case 3:
                printf("Enter the data that you want to insert at position : \n");
                scanf("%d",&iNo);
                printf("Enter the Position : \n");
                scanf("%d",&iPos);

                InsertAtPosition(&Head,&Tail,iNo,iPos);
                Display(Head,Tail);
                break;

            case 4:
                DeleteFirst(&Head,&Tail);
                Display(Head,Tail);
                break;

            case 5:
                DeleteLast(&Head,&Tail);
                Display(Head,Tail);
                break;

            case 6:
                printf("Enter the Position : \n");
                    scanf("%d",&iPos);
                    
                    DeleteAtPosition(&Head,&Tail,iPos);
                    Display(Head,Tail);
                    break;

            case 7:
                Display(Head,Tail);
                break;

            case 8:
                printf("Number of Elemnets are : %d\n",iSize);
                break;

            case 9:
                Options();
                break;

            case 10:
                printf("Thank you for using this application\n");
                printf("--------------------------------------------------------------------\n");
                return 0;

            default:
                printf("Invalid Position\n");
                break;
        }
        printf("\n");
        printf("--------------------------------------------------------------------\n");
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////