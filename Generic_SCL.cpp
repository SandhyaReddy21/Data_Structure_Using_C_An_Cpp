#include <iostream>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class SinglyCL
{
    private : 

        struct node<T> * Head;
        struct node<T> * Tail;
        int iSize;

    public : 

        SinglyCL();
        ~SinglyCL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);
        int Count();
        void Display();
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    cout << "\nInside Constructor \n";
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}


template <class T>
SinglyCL<T> :: ~SinglyCL()
{
    cout << "\nInside Destructor \n";
    struct node<T> *temp = NULL;
    for(int i = 1; i <= iSize; i++)
    {
        temp = Head;
        Head = Head -> next;
        delete temp;
    }
}

template <class T>
void SinglyCL<T> :: InsertFirst(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn -> data = No;
    newn -> next = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
    iSize++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn -> data = No;
    newn -> next = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail -> next = newn;
        Tail = Tail -> next;
    }
    Tail -> next = Head;
    iSize++;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T No, T Pos)
{
    struct node<T> *newn = new struct node<T>;
    struct node<T> *temp = Head;
    newn -> data = No;
    newn -> next = NULL;

    if((Pos < 1) || (Pos > iSize + 1))
    {
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iSize + 1)
    {
        InsertLast(No);
    }

    else
    {
        for(int i = 1; i < Pos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iSize++;
    } 

}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if(iSize == 0)
    {
        return;
    }

    else if(iSize == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
        iSize--;
    }

    else
    {
        Head = Head -> next;
        delete (Tail -> next);
        Tail -> next = Head;
        iSize--;
    }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> *temp = Head;

    if(iSize == 0)
    {
        return;
    }
    else if(iSize == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
        iSize--;
    }
    else
    {
        for(int i = 1; i < iSize - 1; i++)
        {
            temp = temp -> next;
        }
        delete Tail;
        Tail = temp;
        Tail -> next = Head;
        iSize--;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(T Pos)
{
    struct node<T> *temp = Head;
    struct node<T> *target = NULL;

    if((Pos < 1) || (Pos > iSize))
    {
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst();
    }

    else if(Pos == iSize)
    {
        DeleteLast();
    }

    else
    {
        for(int i = 1; i < Pos - 1; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete target;
        iSize--;
    }
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iSize;
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct node<T> * temp = Head;
    for(int i = 1; i <= iSize; i++)
    {
        cout << temp -> data << " <=>\t";
        temp = temp -> next;
    }
    cout << "NULL\n";
}


int main()
{
    SinglyCL <char> obj1;
    SinglyCL<int>*obj2 = new SinglyCL<int>();

    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    cout << "\nAdding Node At First Position : \n";
    obj1.InsertFirst('B');
    obj1.InsertFirst('A');
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";

    cout << "\nAdding Node At Last Position : \n";
    obj1.InsertLast('D');
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";

    cout << "\nAdding Node At Given Position 3 : \n";
    obj1.InsertAtPos('C', 3);
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";

    cout << "\n Removing First Node From Linkedlist : \n";
    obj1.DeleteFirst();
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";

    cout << "\n Removing Last Node From Linkedlist : \n";
    obj1.DeleteLast();
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";

    cout << "\nRemoving Node At Given Position 2 : \n";
    obj1.DeleteAtPos(2);
    obj1.Display();
    cout << "\nLength Of Linked List is : " << obj1.Count() << "\n";
    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    cout << "\nAdding Node At First Position : \n";
    obj2 -> InsertFirst(20);
    obj2 -> InsertFirst(10);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nAdding Node At Last Position : \n";
    obj2 -> InsertLast(40);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nAdding Node At Given Position 3 : \n";
    obj2 -> InsertAtPos(30, 3);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n Removing First Node From Linkedlist : \n";
    obj2 -> DeleteFirst();
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n Removing Last Node From Linkedlist : \n";
    obj2 -> DeleteLast();
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nRemoving Node At Given Position 2 : \n";
    obj2 -> DeleteAtPos(2);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    delete obj2;

    return 0;

}
