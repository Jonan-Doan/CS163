#include "stack.h"
struct q_node
{
	stack entry;// object for the stack that will hold onto the entry of the stack that is being pushed
	char * address;//pointer that will hold onto the address of the package
	q_node * next; // pointer to next q_node pointer
};
class queue
{
	public:
		queue();//default constructor
		~queue();//default destructor
		int display_all_queue() const; //display the content of the queue
		int enqueue(char address_toadd[], const packages & to_add);// add a new package to the queue node
		int dequeue();//remove the package from the queue
	private:
		q_node * rear;// rear pointer for the queue
	      	char * reciever_address;// pointer that will hold onto the address of the package

};
