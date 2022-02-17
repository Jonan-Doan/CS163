#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//Jonan Doan
//The purpose of this program to allow the user if they want to add a new package to the delivery list, remove a package to the delivery list, if they want to display the package. if they want to add
//a new package to the delivery list the program will add the stack of package along with the addres of the package to the queue node.If they want to remove a package, the program will delete the stack of packages
//first then delete the queue node that is holding the information. If they want to display the package, the program will display the content of the stack and then display the queue.


//This class purpose is to organize the packages information
class packages
{
	public:
	      packages();//constructor
	      ~packages();//default destructor
	      int create_entry(char sender_name [], char phone [], char id[]);// transfer information that the user had typed in a static array in main
	      // and transfer it into a dynamic array
	      int add_packages(const packages & new_packages);// the function purpose is to transfer all of the dynamic memory and transfer it into the object new_packages
	      int display_packages() const;//This function display the conent of the packages (sender_name, phone, id).
	private:
	      char * sender_name;//Holds the name of the person sending the packages
	      char * phone;//Holds the phone number of the sender
	      char * id;//holds the id number of the package
};

