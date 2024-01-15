#include <iostream>
#include <vector>
#include <string>

class AddressBook
{
private:

		std::vector <std::string> contactName;
		std::vector <std::string> numberPhone;

public:

	std::string volContactName;
	std::string volNumberPhone;

	void SetAddContactName()
	{
		std::cout << "Enter the subscriber's name: ";
		std::cin >> volContactName;

		contactName.push_back(volContactName);

	}

	void SetAddNumberPhone()
	{

		int number;
		std::cout << "Enter the subscriber's phone number(10 digits): ";
		std::cin >> number;

		volNumberPhone = "+7" + std::to_string(number);
		
		numberPhone.push_back(volNumberPhone);

	}
};

class Phone
{
private:




public:


};
int main() {

	AddressBook subscriber;

	std::string command;
	

	do
	{

		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "add")
		{
			subscriber.SetAddContactName();
			subscriber.SetAddNumberPhone();
		}
		else if (command == "call")
		{



		}
		else if (command == "sms")
		{



		}

	} while (command != "exit");
	
	
}