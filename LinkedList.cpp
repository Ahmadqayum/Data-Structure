#include<iostream>
using namespace std;

class Node
{
    private:
        int info;
        Node *next;
    public:
        Node(int value)
        {
            info = value;
            next = NULL;
        }
        friend class LinkedList;
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList()
        {
            head = NULL;
        }
        void add(int value)
        {
            Node *newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
            }
            else 
            {
                Node *current = head;
                while(current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        void Deleting(int value)
        {
            if(head != NULL && head->info == value)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node *current = head;
            Node *previous = NULL;
            while(current->next != NULL)
            {
                previous->next = current->next;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }

        void display()
        {
            Node *current = head;
            while(current != NULL)
            {
                cout<<current->info<<" ";
                current = current->next;
            }
            cout<<endl;
        }
};  

int main()
{
    LinkedList l1;
    int option,insertNumber,deleteNumber;
    while(true)
    {
        cout<<"1)-Add.\n2)-Delete.\n3)-Display.\n4)-Quit\n";
        cout<<"Your Choice : ";
        cin>>option;
        if(option == 1)
        {
            cout<<"Enter the number You want to insert : ";
            cin>>insertNumber;
            l1.add(insertNumber);
        }
        else if(option == 2)
        {
            cout<<"Enter the number You want to delete : ";
            cin>>deleteNumber;
            l1.Deleting(deleteNumber);
        }
        else if(option == 3)
        {
            l1.display();
        }
        else if(option == 4)
        {
            break;
        }
    }
}