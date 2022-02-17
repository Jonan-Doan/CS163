#include"stack.h"
stack::stack()
{
	head = NULL; // initialize head of the node to NULL
}
stack::~stack()
{
	node *temp = NULL;// set temp of the video node to NULL

	// This while loop will deallocate all memory of the video LLL 
	while(head)
	{
		temp = head->next;
		delete [] head->entries;
		delete head;
		head = temp;
	}
}
// add a new packages's description on top of the stack
int stack::push (const packages & new_packages)
{
	if(!head)
	{
		head = new node;
		head->entries = new packages[MAX];
		head->next = NULL;
		top_index = 0;
	}
	else if(top_index==MAX)
	{
		node * temp = new node;
		temp->entries = new packages[MAX];
		temp->next = head;
		head= temp;
		top_index=0;
	}
	if(head->entries[top_index].add_packages(new_packages))
	{
		++top_index;
	}
	else return 0;
	return 1;
}
// pop a package's description off the stack
int stack::pop(void)
{
	if(!head) return 0;
	node * hold = head->next;
	if(!top_index)
	{
		if(head->entries)
		{
			delete head->entries;
		}
		delete head;
		head = hold;
		top_index = MAX;
		if(!head)
		{
			top_index= MAX;
		}
		else
		{
			top_index= 0;
		}
		--top_index;
		return 1;
	}
}
// peek if there is no node or if the stack is full
int stack::peek (packages & at_top) const
{
	if(!head) return 0;
	if(top_index== 0)	
	{
		if(head->next==NULL)
		{
			return 0;
		}
	}
	else
	{
		return 1;
	}
}
//display the content of a stack
int stack::display_all_stack(void) const
{
	if(!head) return 0;
	else
	{
		node *temp = head;
		while(temp != NULL)
		{
			for(int i= 0;i<MAX; ++i)
			{
			 temp->entries[i].display_packages();
			}
			 temp = temp->next;
		}
	}
}
/*
int stack::copy(const stack & to_copy)
{
	if(!to_copy.head) return 0;
	top_index= to_copy.top_index;
	node *temp = to_copy.head;
	node *dest = new node;
	dest->entries=new packages[MAX];
	head= dest;
	while(temp != NULL)
	{
		for(int i= 0;i<MAX; ++i)
		{
			dest->entries[i].add_packages(temp->entries[i]);
		}
		
		 temp = temp->next;
		 if(!temp)
		 {
			 dest->next = new node;
			 dest= dest->next;
			 dest->entries= new packages[MAX];
		 }
	}
}
*/	
