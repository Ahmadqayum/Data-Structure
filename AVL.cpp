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
        friend class AVL;
};
class AVL 
{
    private:
        Node *root;
    public:
        AVL()
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
        }
};
int main()
{
    
}