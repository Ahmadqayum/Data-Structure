#include<iostream>
using namespace std;

class Hashing
{
    private:
        int info;
        int size;
        int *arr;
        bool valueFound;
    public:
        Hashing(int size)
        {
            this->size = size;
            arr = new int[size];
            valueFound = false;
            for(int i=0;i<size;i++)
            {
                arr[i] = 0;
            }
        }

        void Insert(int val)
        {
            int index = val % size;
            while(arr[index] != 0)
            {
                index = (index + 1) % size;
            }   

            arr[index] = val;     
        }

        void display()
        {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void Searching(int val)
        {
            for(int i=0;i<size;i++)
            {
                if(val == arr[i])
                {
                    cout<<"Value Found : "<<val<<" in the Array on index : "<<"["<<i<<"]"<<endl;
                    valueFound = true;
                }
                else 
                {
                    valueFound = false;
                }
            }
            if(!valueFound)
            {
                cout<<"There is no value found in the array"<<endl;
            }
        }

        void DeleteValue(int val)
        {
            for(int i=0;i<size;i++)
            {
                if(val == arr[i])
                {
                    arr[i] = 0;
                }
            }
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
