#include <iostream>
#include <assert>

using namespace std;

template <class ItemType>
struct TreeNode
{
   ItemType data;
   TreeNode<ItemType> *left;
   TreeNode<ItemType> *right;
   TreeNode<ItemType> *parent;
};

template <class ItemType>
class BinaryTree
{
public:
   BinaryTree();				//create empty tree with default root node which has no value. set current to main root node.
   BinaryTree(TreeNode<ItemType>*,int);		//create new tree with passed node as the new main root. set current to main root. if the second parameter is 						// 0, the new object simply points to the node of the original tree. If the second parameter is 1, a new copy 						// of the subtree is created, which the object points to.
   ~BinaryTree();
   void insert(const ItemType&,int);		//insert new node as child of current. 0=left 1=right
   void remove(TreeNode<ItemType>*);		//delete node and its subtree

   ItemType value() const; //return value of current

   //navigate the tree
   void left();
   void right();
   void parent();
   void reset(); //go to main_root
   void SetCurrent(TreeNode<ItemType>*);

   //return subtree (node) pointers
   TreeNode<ItemType>* pointer_left() const;
   TreeNode<ItemType>* pointer_right() const;
   TreeNode<ItemType>* pointer_parent() const;
   TreeNode<ItemType>* pointer_current() const;

   //return values of children and parent without leaving current node
   ItemType peek_left() const;
   ItemType peek_right() const;
   ItemType peek_parent() const;

   //print the tree or a subtree. only works if ItemType is supported by << operator
   void DisplayInorder(TreeNode<ItemType>*) const;
   void DisplayPreorder(TreeNode<ItemType>*) const;
   void DisplayPostorder(TreeNode<ItemType>*) const;

   //delete all nodes in the tree
   void clear();

   //
   bool IsEmpty() const;
   bool IsFull() const;

private:
   TreeNode<ItemType>* current;
   TreeNode<ItemType>* main_root;
   TreeNode<ItemType>* CopyTree(TreeNode<ItemType>*,TreeNode<ItemType>*) const;		//create a new copy of a subtree if passed to the constructor
   bool subtree;									//does it reference a part of a larger object?
};

template <class ItemType>
BinaryTree<ItemType>::BinaryTree()
{
   //create a root node with no value
   main_root = NULL;
   current = NULL;
   subtree = false;
}

template <class ItemType>
BinaryTree<ItemType>::BinaryTree(TreeNode<ItemType>* root, int op)
{
   if(op = 0)
   {
      main_root = root;
      current = root;
      subtree = true;
   }
   else
   {
      main_root = CopyTree(root,NULL);
      current = main_root;
      subtree = false;
   }
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::CopyTree(TreeNode<ItemType> *root, TreeNode<ItemType> *parent) const
{
   if(root == NULL)					//base case - if the node doesn't exist, return NULL.
      return NULL;
   TreeNode<ItemType>* tmp = new TreeNode<ItemType>;	//make a new location in memory
   tmp->data = root->data;				//make a copy of the node's data
   tmp->parent = parent;				//set the new node's parent
   tmp->left = CopyTree(root->left,tmp);		//copy the left subtree of the current node. pass the current node as the subtree's parent
   tmp->right = CopyTree(root->right,tmp);		//do the same with the right subtree
   return tmp;						//return a pointer to the newly created node.
}

template <class ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
   if(!subtree)
      clear(); //delete all nodes
}

template <class ItemType>
void BinaryTree<ItemType>::insert(const ItemType &item,int pos) //insert as child of current 0=left 1=right. if item already exists, replace it
{
   assert(!IsFull());
   //if the tree has no nodes, make a root node, disregard pos.
   if(main_root == NULL)
   {
      main_root = new TreeNode<ItemType>;
      main_root->data = item;
      main_root->left = NULL;
      main_root->right = NULL;
      main_root->parent = NULL;
      current = main_root;
      return;						//node created, exit the function
   }

   if(pos == 0)						//new node is a left child of current
   {
      if(current->left != NULL)				//if child already exists, replace value
         (current->left)->data = item;
      else
      {
         current->left = new TreeNode<ItemType>;
         current->left->data = item;
         current->left->left = NULL;
         current->left->right = NULL;
         current->left->parent = current;
      }
   }
   else							//new node is a right child of current
   {
      if(current->right != NULL)			//if child already exists, replace value
         (current->right)->data = item;
      else
      {
         current->right = new TreeNode<ItemType>;
         current->right->data = item;
         current->right->left = NULL;
         current->right->right = NULL;
         current->right->parent = current;
      }
   }
}

template <class ItemType>
void BinaryTree<ItemType>::remove(TreeNode<ItemType>* root)
{
   if(root == NULL)			//base case - if the root doesn't exist, do nothing
      return;
   remove(root->left);			//perform the remove operation on the nodes left subtree first
   remove(root->right);			//perform the remove operation on the nodes right subtree first
   if(root->parent == NULL)		//if the main root is being deleted, main_root must be set to NULL
      main_root = NULL;
   else
   {
      if(root->parent->left == root)	//make sure the parent of the subtree's root points to NULL, since the node no longer exists
         root->parent->left = NULL;
      else
         root->parent->right = NULL;
   }
   current = root->parent;		//set current to the parent of the subtree removed.
   delete root;
}

template <class ItemType>
ItemType BinaryTree<ItemType>::value() const
{
   return current->data;
}

template <class ItemType>
void BinaryTree<ItemType>::left()
{
   current = current->left;
}

template <class ItemType>
void BinaryTree<ItemType>::right()
{
   current = current->right;
}

template <class ItemType>
void BinaryTree<ItemType>::parent()
{
   current = current->parent;
}

template <class ItemType>
void BinaryTree<ItemType>::reset()
{
   current = main_root;
}

template <class ItemType>
void BinaryTree<ItemType>::SetCurrent(TreeNode<ItemType>* root)
{
   current = root;
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::pointer_left() const
{
   return current->left;
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::pointer_right() const
{
   return current->right;
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::pointer_parent() const
{
   return current->parent;
}

template <class ItemType>
TreeNode<ItemType>* BinaryTree<ItemType>::pointer_current() const
{
   return current;
}

template <class ItemType>
ItemType BinaryTree<ItemType>::peek_left() const
{
   assert(current->left != NULL);
   return current->left->data;
}

template <class ItemType>
ItemType BinaryTree<ItemType>::peek_right() const
{
   assert(current->right != NULL);
   return current->right->data;
}

template <class ItemType>
ItemType BinaryTree<ItemType>::peek_parent() const
{
   assert(current->parent != NULL);
   return current->parent->data;
}

template <class ItemType>
void BinaryTree<ItemType>::DisplayInorder(TreeNode<ItemType>* root) const
{
   if (root == NULL)
      return;

   DisplayInorder(root->left);
   cout << root->data;
   DisplayInorder(root->right);
}

template <class ItemType>
void BinaryTree<ItemType>::DisplayPreorder(TreeNode<ItemType>* root) const
{
   if (root == NULL)
      return;

   cout << root->data;
   DisplayInorder(root->left);
   DisplayInorder(root->right);
}

template <class ItemType>
void BinaryTree<ItemType>::DisplayPostorder(TreeNode<ItemType>* root) const
{
   if (root == NULL)
      return;

   DisplayInorder(root->left);
   DisplayInorder(root->right);
   cout << root->data;
}

template <class ItemType>
void BinaryTree<ItemType>::clear()
{
   remove(main_root); //use the remove function on the main root
   main_root = NULL; //since there are no more items, set main_root to NULL
   current = NULL;
}

template <class ItemType>
bool BinaryTree<ItemType>::IsEmpty() const
{
   return (main_root == NULL);
}

template <class ItemType>
bool BinaryTree<ItemType>::IsFull() const
{
   TreeNode<ItemType> *tmp = new TreeNode<ItemType>;
   if(tmp == NULL)
      return true;
   else
   {
      delete tmp;
      return false;
   }
}

template <class ItemType>
int LeafCount(TreeNode<ItemType>* root)
{
   if(root == NULL) //base case - if the node doesn't exist, return 0 (don't count it)
      return 0;
   if((root->left == NULL) && (root->right == NULL))		//if the node has no children return 1 (it is a leaf)
      return 1;
   return LeafCount(root->left) + LeafCount(root->right);	//add the leaf nodes in the left and right subtrees
}

template <class ItemType>
int NodeCount(TreeNode<ItemType>* root)
{
   if(root == NULL) //base case - if the return 0 if node doesn't exist (don't count it)
      return 0;
   else
      return 1 + NodeCount(root->left) + NodeCount(root->right); //return 1 for the current node, and add the amount of nodes in the left and right subtree
}

int main()
{
  BinaryTree<int> binary_tree1;
  return 0;
}