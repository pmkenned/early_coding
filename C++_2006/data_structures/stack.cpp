#include <iostream>
#include <assert>

using namespace std;

template <class ItemType>
struct StackNode
{
   ItemType data;
   StackNode<ItemType> *next;
};

template <class ItemType>
class Stack
{
public:
   Stack();			//class constructor - initialize private variables
   ~Stack();			//class destructor - free up used memory
   void push(const ItemType);	//add a new node to the top of the stack
   ItemType pop();		//remove the top node and return its contents
   ItemType get_top() const;	//return the top node without popping it
   void clear();		//delete all nodes in the stack
   bool IsEmpty() const;	//return true if the stack has no elements
   bool IsFull() const;		//return true if there is no free memory for new nodes
   int count() const;		//return the amount of nodes on the stack
private:
   StackNode<ItemType> *top;	//pointer to the top node in stack
   int counter;			//maintain the amount of nodes in the stack
};

template <class ItemType>
Stack<ItemType>::Stack()
{
   counter = 0;
   top = NULL;
}

template <class ItemType>
Stack<ItemType>::~Stack()
{
   clear();
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType item)
{
   assert(!IsFull());					//abort if there is not enough memory to create a new node
   StackNode<ItemType> *tmp = new StackNode<ItemType>;	//create a new node on top of the others with value item
   tmp->data = item;
   tmp->next = top;
   top = tmp;						//set the original top node to follow the new one
   counter++;						//increment the amount of nodes in the stack
}

template <class ItemType>
ItemType Stack<ItemType>::pop()
{
   assert(!IsEmpty());			//abort if the stack is empty, no node to pop
   ItemType item = top->data;		//maintain top value, to be returned later
   StackNode<ItemType> *tmp = top;	//create a temporary reference to the top node
   top = top->next;			//set top to be the next node
   delete tmp;				//delete the top node
   counter--;				//decrement the amount of nodes in the stack
   return item;				//return the original top value
}

template <class ItemType>
ItemType Stack<ItemType>::get_top() const
{
   assert(!IsEmpty());
   return top->data;
}

template <class ItemType>
void Stack<ItemType>::clear()
{
   StackNode<ItemType> *tmp;
   while(top != NULL)		//loop through every node in the stack
   {
      tmp = top;		//reference the top node
      top = top->next;		//set top to the next node
      delete tmp;		//delete the original top node
   }
}

template <class ItemType>
bool Stack<ItemType>::IsEmpty() const
{
   return (top == NULL);
}

template <class ItemType>
bool Stack<ItemType>::IsFull() const
{
   StackNode<ItemType> *tmp = new StackNode<ItemType>;
   if(tmp == NULL)
      return true;
   else
   {
      delete tmp;
      return false;
   }
}

template <class ItemType>
int Stack<ItemType>::count() const
{
   return counter;
}

int main()
{
  Stack<int> stack1;
  stack1.push(5);
  int a = stack1.pop();
  cout << a << endl;
  return 0;
}