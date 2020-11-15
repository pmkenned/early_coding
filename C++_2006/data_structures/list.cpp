#include <iostream>
#include <assert>

using namespace std;

template <class ItemType>
struct ListNode
{
   ItemType data;
   ListNode<ItemType> *next;
};

template <class ItemType>
class List
{
public:
   List();				//constructor - initialize private variables
   ~List();				//destructor - free used memory
   void insert(const ItemType);		//insert new node at current location
   void remove();			//remove the current node
   void next();				//set current to the next node in the list
   void prev();				//set current to the previous node in the list
   void reset();			//set current to the first node in the list
   void clear();			//remove all nodes in the list
   int length() const;			//return the amount of nodes in the list
   bool IsEmpty() const;		//returns true if the list doesn't have any nodes
   bool IsFull() const;			//returns true if there is no system memory for additional nodes
   ItemType value() const;		//returns the value of the current node
private:
   ListNode<ItemType> *list;		//points to the list header
   ListNode<ItemType> *prevcurrent;
   int len;
};

template <class ItemType>
List<ItemType>::List()
{
   list = new ListNode<ItemType>;	//create a new ListNode in memory
   list->next = NULL;			//the header is the only node in the list
   prevcurrent = list;			//set current to the header, since there are no nodes
   len = 0;
}

template <class ItemType>
void List<ItemType>::clear()
{
   ListNode<ItemType> *tmp;			//point to the node to be deleted
   ListNode<ItemType> *traverse = list->next;	//used to visit each node in the list. The header node is not deleted, so we start with the first actual node.
   while(traverse != NULL)			//while the list is not empty
   {
      tmp = traverse;				//store the current node.
      traverse = traverse->next;		//visit the next node
      delete tmp;				//free the memory taken up by the current node
   }
   prevcurrent = list;				//set current to the header node
   len = 0;
}

template <class ItemType>
List<ItemType>::~List()
{
   clear();		//delete all list nodes
   delete list;		//delete the header "dummy" node
}

template <class ItemType>
void List<ItemType>::insert(const ItemType item)
{
   assert(!IsFull());						//abort if there is no memory to create a new node
   ListNode<ItemType> *NewNode = new ListNode<ItemType>;	//create a new node in memory
   NewNode->data = item;					//set the node's value
   NewNode->next = prevcurrent->next;				//referenced node will follow new node in order
   prevcurrent->next = NewNode;					//The node that preceded the old node now precedes the new one. The new node is now referenced.
   len++;							//increment length
}

template <class ItemType>
void List<ItemType>::remove()
{
   if(len != 0) //don't delete the header node
   {
      prevcurrent->next = prevcurrent->next->next;	//logically remove it from the list
      delete (prevcurrent->next);			//free up memory
      len--;						//decrement length
   }
}

template <class ItemType>
void List<ItemType>::next()
{
   prevcurrent = prevcurrent->next;
}

template <class ItemType>
void List<ItemType>::prev()
{
   if (len > 1)					//run only if there is an element behind the current
   {
      ListNode *tmp = list;
      while(tmp->next != prevcurrent)
      tmp = tmp->next;
      revcurrent = tmp;
   }
}

template <class ItemType>
void List<ItemType>::reset()
{
   prevcurrent = list;
}

template <class ItemType>
int List<ItemType>::length() const
{
   return len;
}

template <class ItemType>
bool List<ItemType>::IsEmpty() const
{
   return (len == 0);
}


template <class ItemType>
bool List<ItemType>::IsFull() const
{
   ListNode<ItemType> *tmp = new ListNode<ItemType>;
   if(tmp == NULL)
      return true;
   else
   {
      delete tmp;
      return false;
   }
}

template <class ItemType>
ItemType List<ItemType>::value() const
{
   return prevcurrent->next->data;
}

int main()
{
  List<int> list1;
  list1.insert(6);
  cout << list1.value() << endl;
  return 0;
}