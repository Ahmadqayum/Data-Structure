#include<iostream>
using namespace std;

class Node
{
    private:
        int info;
        Node *left,*right;
    public:
        Node(int val)
        {
            info = val;
            left = right = NULL;
        }
        friend class BST;
};
class BST
{
    public:
    Node *root;
        BST()
        {
            root = NULL;
        }

        Node *insertion(Node *temp,int val)
        {
            Node *newNode = new Node(val);
            if(temp == NULL)
            {
                temp = newNode;
                
                return temp;
            }
            else 
            {
                if(val > temp->info)
                {
                    temp->right = insertion(temp->right,val);
                    
                }
                else if(val < temp->info)
                {
                    temp->left = insertion(temp->left,val);
                    
                }
            }
            return temp;
        }

        void Insert(int val)
        {
            root = insertion(root,val);
        }

        Node *deletion(Node *temp,int val)
        {
            if(temp == NULL)
            {
                return nullptr;
            }
            else 
            {
                if(val > temp->info)
                {
                    temp->right = deletion(temp->right,val);
                }
                else if(val < temp->info)
                {
                    temp->left = deletion(temp->left,val);
                }

                else 
                {
                    if(temp->left != NULL)
                    {
                        Node *current = temp;
                        temp = temp->left;
                        delete current;
                        
                    }
                    else if(temp->right != NULL)
                    {
                        Node *current = temp;
                        temp = temp->right;
                        delete current;
                        
                    }
                    else if(temp->left == NULL && temp->right == NULL)
                    {
                        delete temp;
                        temp = nullptr;
                        
                    }
                }
                return temp;
            }
            
        }

        void DeleteNode(int val)
        {
            root = deletion(root,val);
        }


        Node *inorderTraversal(Node *temp)
        {
            if(temp == NULL)
            {
                return nullptr;
            }
            else 
            {
                inorderTraversal(temp->left);
                cout<<temp->info<<" ";
                inorderTraversal(temp->right);
            }
        }

        void inorder()
        {
            inorderTraversal(root);
        }

        Node *SearchValue(Node *temp,int val)
        {
            if(temp == NULL)
            {
                return nullptr;
            }
            else 
            {
                if(val > temp->info)
                {
                    if(val == temp->info)
                    {
                        cout<<"value founded : "<<temp->info<<endl;
                    }  
                    else 
                    {
                        temp->right = SearchValue(temp->right,val);
                    }
                }
                else if(val < temp->info)
                {
                    if(val == temp->info)
                    {
                        cout<<"value founded : "<<temp->info<<endl;
                    }  
                    else 
                    {
                        temp->left = SearchValue(temp->left,val);
                    }
                }
                else if(val == temp->info)
                {
                    cout<<"value founded : "<<temp->info<<endl;
                }
                else 
                {
                    return temp;
                }
            }
        }

};
int main()
{
    BST b1;
    int option;
    int insertValue,deleteValue,searchValue;
    while(true)
    {
        cout<<"1)-insert a value.\n2)-delete Value.\n3)-display the BST.\n4)-Search a value.\n5)-Quit.\n";
        cin>>option;
        if(option == 1)
        {
            cout<<"Enter the value to insert : ";
            cin>>insertValue;
            b1.Insert(insertValue);
        }
        else if(option == 2)
        {
            cout<<"Enter the value to delete : ";
            cin>>deleteValue;
            b1.DeleteNode(deleteValue);
        }
        else if(option == 3) // displaying the bst in the inorder traversal way.
        {
            cout<<endl;
            cout<<"INORDER TRAVERSAL : "<<endl;
            b1.inorder();
            cout<<endl;
        }
        else if(option == 4)
        {
            cout<<"Enter the value to search : ";
            cin>>searchValue;
            b1.SearchValue(b1.root,searchValue);
        }
        else if(option == 5)
        {
            break;
        }
    }

}