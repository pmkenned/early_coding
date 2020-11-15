#include <iostream>
#include <assert>

using namespace std;

template <class ItemType>
struct QueNode
{
   ItemType data;
   QueNode<ItemType> *next;
};

template <class ItemType>
class Queue
{
public:
   Queue(); //class constructor - initialize variables
   ~Queue(); //class destructor - return memory used by queue elements
   void enqueue(const ItemType); //add an item to the back of the queue
   void clear();
   ItemType dequeue(); //remove the first item from the queue and return its value
   ItemType first() const; //return the value of the first item in the queue without modification to the structure
   bool IsEmpty() const; //returns true if there are no elements in the queue
   bool IsFull() const; //returns true if there is no system memory for a new queue node
   int length() const; //returns the amount of elements in the queue
private:
   QueNode<ItemType> *front;
   QueNode<ItemType> *back;
   int len;
};

template <class ItemType>
Queue<ItemType>::Queue()
{
   front = NULL;
   back = NULL;
   len = 0;
}

template <class ItemType>
Queue<ItemType>::~Queue()
{
   clear();
}

template <class ItemType>
void Queue<ItemType>::enqueue(const ItemType item)
{
   assert(!IsFull()); //abort if there is no more memory for a new node
   if(len != 0) //if the queue is not empty
   {
      back->next = new QueNode<ItemType>; //create a new node
      back = back->next; //set the new node as the back node
      back->data = item;       back->next = NULL;    }
   else
   {
      back = new QueNode<ItemType>; //create a new node
      back->data = item;       back->next = NULL;       front = back; //set front to reference the new node. Since there it is the only node in the queue, it is considered to be both the back and front.
   }
   len++; //increment the amount of elements in the queue
}

template <class ItemType>
void Queue<ItemType>::clear()
{
  while( IsEmpty() == false )
    dequeue();
}

template <class ItemType>
ItemType Queue<ItemType>::dequeue()
{
   assert(!IsEmpty()); //abort if the queue is empty, no node to dequeue
   ItemType item = front->data; //store the value of the first node, to be returned at the end
   QueNode<ItemType> *tmp = front; //temporary pointer to the first node.
   front = front->next; //set the second node in the queue as the new front
   delete tmp; //delete the original first node
   if(front == NULL) //if the queue is empty, update the back pointer
      back = NULL;
   len--; //decrement the amount of nodes in the queue
   return item; //return the value of the original first element
}

template <class ItemType>
ItemType Queue<ItemType>::first() const
{
   assert(!IsEmpty()); //abort if the queue is empty
   return front->data;
}

template <class ItemType>
bool Queue<ItemType>::IsEmpty() const
{
   return (front == NULL);
}

template <class ItemType>
bool Queue<ItemType>::IsFull() const
{
   QueNode<ItemType> *tmp = new QueNode<ItemType>;
   if(tmp == NULL)
      return true;
   else
   {
      delete tmp;
      return false;
   }
}

template <class ItemType>
int Queue<ItemType>::length() const
{
   return len;
}

int main()
{
  Queue<int> queue1;
  queue1.enqueue(5);
  cout << queue1.dequeue() << endl;

  return 0;
}