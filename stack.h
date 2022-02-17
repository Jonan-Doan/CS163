#include"packages.h"
struct node
{
	packages * entries;
	node * next;//node pointer to the next
};
const int MAX = 5;//size of the array

class stack
{
	public:
		stack();//default constructor
		~stack();//default destructor
		int display_all_stack(void) const;// display all the content of the stack
		int peek (packages & at_top) const;// peek if the stack is empty or if the stack is full
		int push (const packages & to_add); // add a new package onto the stack
		int pop(void);//delete a package from the stack
	private:
		node * head;//node pointer to the head
		int top_index = 0;// index of the stack
};
	
