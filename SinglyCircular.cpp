#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//Linear Data Structure  //github.com/VirajsShinde

//Linked List --> Singly->Circular.cpp (C++)  

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

class SinglyLL
{
    public:
            PNODE first;
            PNODE last;

            int iCount;

    SinglyLL();

    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPosition(int iNo,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int iPos);

    void Display();
    void Options();
};

/////////////////////////////////////////////////////////////////////////////////////

SinglyLL :: SinglyLL()
{
    first = NULL;
    last = NULL;

    iCount = 0;
}

//////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if((first == NULL) && (last == NULL)) 
    {
        first = last = newn;

        last->next = first;
        
        iCount++;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;

        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if((first == NULL) && (last == NULL)) 
    {
        first = newn;

        last->next = first;

        iCount++;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;

        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteFirst()
{
    if((first == NULL) && (last == NULL)) 
    {
        cout<<"Linked List is Empty"<<"\n";
        return;
    }
    else if((first) == (last))
    {
        delete first;

        first = NULL;
        last = NULL;

        iCount--;
    }
    else
    {
        PNODE temp = first;

        first = first->next;

        delete temp;

        last->next = first;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteLast()
{
    if((first == NULL) && (last == NULL)) 
    {
        cout<<"Linked List is Empty"<<"\n";
        return;
    }
    else if((first) == (last))
    {
        delete first;

        first = NULL;
        last = NULL;

        iCount--;
    }
    else
    {
        PNODE temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete temp->next;

        last = temp;

        last->next = first;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertAtPosition(int iNo,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Inavalid Position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;

        PNODE temp = first;
        
        newn->data = iNo;
        newn->next = NULL;
                
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;

        temp->next = newn;

        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////

void SinglyLL :: DeleteAtPosition(int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = first;
        PNODE temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;

        free(temp2);

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    
    PNODE temp = first;

    int iCnt = 1;

    while(iCnt <= iCount)
    {
        cout<<"| "<<temp->data<<" |->";
        
        temp = temp->next;
        iCnt++;
    }
    cout<<"| NULL |"<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: Options()
{
    cout<<"-------------------------------------------------------------------"<<"\n";

        cout<<"Please Select Desire Option : "<<"\n";
        cout<<"1 : Insert First"<<"\n";
        cout<<"2 : Insert Last"<<"\n";
        cout<<"3 : Insert At given Position"<<"\n";
        cout<<"4 : Delete First"<<"\n";
        cout<<"5 : Delete Last"<<"\n";
        cout<<"6 : Delete At given Position"<<"\n";
        cout<<"7 : Display the contents of Linked List"<<"\n";
        cout<<"8 : Count Number of Nodes from Linked List"<<"\n";
        cout<<"9 : Options"<<"\n";
        cout<<"10 : EXIT"<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";

}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL sObj1;
    
    int iChioce = 0, iPos = 0, iRet = 0, iNo = 0;

    cout<<"\n Welcome --DS--> Singly->Circular.cpp | github.com/VirajsShinde"<<"\n";

    sObj1.Options();

    while(1)
    {
        cout<<"Enter Option :"<<"\n";
        cin>>iChioce;

        switch(iChioce) 
        {
            case 1:
                cout<<"Enter the data that you want to insert First"<<"\n";
                cin>>iNo;

                sObj1.InsertFirst(iNo);
                sObj1.Display();
                break;

            case 2:
                cout<<"Enter the data that you want to insert Last"<<"\n";
                cin>>iNo;

                sObj1.InsertLast(iNo);
                sObj1.Display();
                break;

            case 3:
                cout<<"Enter the data that you want to insert first"<<"\n";
                cin>>iNo;

                cout<<"Enter the Position : "<<"\n";
                cin>>iPos;

                sObj1.InsertAtPosition(iNo,iPos);
                sObj1.Display();
                break;

            case 4:
                sObj1.DeleteFirst();
                sObj1.Display();
                break;

            case 5:
                sObj1.DeleteLast();
                sObj1.Display();
                break;

            case 6:
                cout<<"Enter the Position"<<"\n";
                cin>>iPos;

                sObj1.DeleteAtPosition(iPos);
                sObj1.Display();
                break;

            case 7:
                sObj1.Display();
                break;

            case 8:
                cout<<"Number of Nodes are : "<<sObj1.iCount<<"\n\n";
                sObj1.Display();
                break;
            
            case 9:
                sObj1.Options();
                break;
                
            case 10:
                cout<<"Thank you for using this application"<<"\n";
                cout<<"-------------------------------------------------------------------"<<"\n";
                return 0;

            default:
                cout<<"Invalid Position"<<"\n";
                break;
        }
        cout<<"----------------------------------------------------------------------"<<"\n";
    }
    return 0;
}