#include<iostream>
using namespace std;

class Hashing
{
    private:
        int size;
        int *arr;
        int *ptr;
        bool valueFound;
    public:
        Hashing(int s)
        {
            size = s;
            arr = new int[size];
            ptr = arr;
            for(int i=0;i<size;i++)
            {
                *ptr = 0;
                ptr++;
            }
            ptr = arr;
            valueFound = false;
        }

        void Insert(int val)
        {
            int index = val % size;
            while(*(ptr + index) != 0)
            {
                index = (index + 1) % size;
                
            }
            *(ptr + index) = val;
        }

        void DeleteValue(int val)
        {
            ptr = arr;
            for(int i=0;i<size;i++)
            {
                if(*ptr == val)
                {
                    *ptr = 0;
                }
                ptr++;
            }
            ptr = arr;
        }

        void display()
        {
            ptr = arr;
            for(int i=0;i<size;i++)
            {
                cout<<*ptr<<" ";
                ptr++;
            }
            ptr = arr;
        }

        void Searching(int val)
        {
            for(int i=0;i<size;i++)
            {
                if(val == *ptr)
                {
                    cout<<"Value Found : "<<*ptr<<" in the Array on index : "<<"["<<i<<"]"<<endl;
                    valueFound = true;
                }
                else 
                {
                    valueFound = false; 
                }
                ptr++;
            }
            if(!valueFound)
            {
                cout<<"There is no value found in the array"<<endl;
            }
            ptr = arr;
        }
};

int main()
{   
    Hashing h1(25);
    int option;
    int insertValue,SearchValue,deleteValue;
    while(true)
    {
        cout<<"1)-Insert.\n2)-Search Value.\n3)-Delete value.\n4)-Display.\n5)-Quit\n";
        cin>>option;
        if(option == 1)
        {
            cout<<"Enter the value to insert : ";
            cin>>insertValue;
            h1.Insert(insertValue);
            cout<<"-------------------"<<endl;
        }
        else if(option == 2)
        {
            cout<<"Enter the value for searching : ";
            cin>>SearchValue;
            h1.Searching(SearchValue);
            cout<<"-------------------"<<endl;
        }
        else if(option == 3)
        {
            cout<<"Enter the value to delete : ";
            cin>>deleteValue;
            h1.DeleteValue(deleteValue);
            cout<<"Value deleted!"<<endl;
            cout<<"---------------------"<<endl;
        }
        else if(option == 4)
        {
            cout<<"Hashing Array : "<<endl;
            h1.display();
            cout<<"-------------------"<<endl;
        }
        else if(option == 5)
        {
            break;
        }
    }
}