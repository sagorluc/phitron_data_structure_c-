#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int node_id;
    node *left_side;
    node *right_side;
    node *parent;

};
class binary_tree
{

public:

    node *head;

    //constructor
    binary_tree()
    {
        head = NULL;
    }

    node *create_new_node(int id)
    {
        node *newnode = new node;

        newnode->node_id = id;
        newnode->left_side = NULL;
        newnode->right_side = NULL;
        newnode->parent = NULL;

        return newnode;
    }

    void insert_id(int id)
    {
        node *newnode = create_new_node(id);

        if(head == NULL)
        {
            head = newnode;
            return;
        }

        queue<node*>q;
        q.push(head);

        while(!q.empty())
        {
            node *tmp = q.front();
            q.pop();

            if(tmp->left_side != NULL)
            {
                q.push(tmp->left_side);
            }
            else
            {
                tmp->left_side = newnode;
                newnode->parent = tmp;
                return;
            }
            if(tmp->right_side != NULL)
            {
                q.push(tmp->right_side);
            }
            else
            {
                tmp->right_side = newnode;
                newnode->parent = tmp;
                return;
            }

        }

    }

    int find_max(int a, int b)
    {
        if(a >= b)
            return a;
        else
            return b;
    }

    int height(node *tmp)
    {

        if(tmp == NULL)
            return -1;

        return find_max(height(tmp->left_side), height(tmp->right_side)) + 1;
    }

    void DFS_inorder(node *tmp)
    {
        if(tmp == NULL)
            return;

        DFS_inorder(tmp->left_side);
        cout<<tmp->node_id<<" ";
        DFS_inorder(tmp->right_side);
    }

//    bool perfect_binary_tree(node *root,int lavel = 0)
//    {
//        if(root == NULL)
//            return true;
//
//        if(root->left_side == NULL && root->right_side == NULL)
//            return(lavel + 1);
//
//
//        if(root->left_side == NULL || root->right_side == NULL)
//             return false;
//
//        return perfect_binary_tree(root->left_side,lavel + 1) && perfect_binary_tree(root->right_side,lavel + 1);
//
//
//    }
//
//    bool isperfact(node *root)
//    {
//        if(root == NULL)
//            return true;
//
//        int d = height(root);
//        return perfect_binary_tree(root, d);
//
//    }
    bool isPerfectBinaryTree(node *root)
    {
        // An empty tree is perfect
        if (root == NULL)
            return true;

        // Get the height of left and right sub-trees
        int lh = height(root->left_side);
        int rh = height(root->right_side);


        // If this node is perfect
        // check left and right subtrees recursively
        // else return false
        if(lh==rh)
        {
            if (isPerfectBinaryTree(root->left_side) &&  isPerfectBinaryTree(root->right_side))
            {
                return true;
            }
        }

        return false;
    }

};
int main()
{
    binary_tree bt;

    bt.insert_id(0);
    bt.insert_id(1);
    bt.insert_id(2);
    bt.insert_id(3);
    bt.insert_id(4);
    bt.insert_id(5);
    bt.insert_id(6);
    bt.DFS_inorder(bt.head);
    cout<<"\nthe height is : "<<bt.height(bt.head);
    cout<<" parfect : "<<bt.isPerfectBinaryTree(bt.head);



    return 0;
}


