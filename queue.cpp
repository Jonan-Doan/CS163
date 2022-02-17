#include"queue.h"
// constructor
queue::queue()
{
	rear=NULL;
	reciever_address= NULL;
}
//destructor
queue::~queue()
{
 	if(reciever_address)
	{
		delete [] reciever_address;
	}
	reciever_address= NULL;
	q_node * ptr = rear->next;
	do
	{
		delete ptr;		
		ptr = ptr->next;
	}while (ptr!= rear->next);
}

// adding a stack of packages and address of the package to the queue
int queue::enqueue(char address_toadd[], const packages & to_add)
{
	if (!address_toadd) return 0;
	reciever_address = new char [strlen(address_toadd)+1];
	strcpy(reciever_address, address_toadd);

	if(!rear)
	{
		rear= new q_node;
		rear->next = rear;
	}
	else
	{
		q_node * temp = rear->next;
		rear->next = new q_node;
		rear = rear->next;
		rear->next = temp;
	}
	rear->address = address_toadd;
	rear->entry.push(to_add); 
	return 1;
}
// removing the content from a queue
int queue::dequeue()
{
	if(!rear) return 0;
	if(rear->next == rear)
	{
		rear->entry.pop();
		delete rear;
		rear = NULL;
	}
	else
	{
		q_node * temp = rear->next;
		rear->next = temp->next;
		temp->entry.pop();
		delete temp;
	}
}
// display the conent of the queue
int queue::display_all_queue() const
{
	q_node * ptr = rear->next;
	do
	{
		ptr->entry.display_all_stack();	
		ptr = ptr->next;
	}while (ptr!= rear->next);
}
	
