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

	std::string GetNameSearch(std::string subscriberName)
	{
		bool is_found = false;
		for (int i = 0; i < contactName.size(); ++i)
		{

			if (contactName[i] == subscriberName)
			{

				subscriberName = numberPhone[i];
				return subscriberName;
				is_found = true;
				break;

			}			
		}

		if (!is_found)
		{

			subscriberName = "Nothing found";
			return subscriberName;

		}
	}

};

class Phone
{
private:




public:

	std::string subscriberName;

	void Call(AddressBook subscriberBook)
	{

		std::cout << "Enter the phone number or name of the person you want to call: ";
		std::cin >> subscriberName;

		if (subscriberName[0] == '+')
		{

			std::cout << subscriberName << std::endl;

		}
		else if (subscriberName[0] != '+')
		{
			
			std::cout << "CALL: " << subscriberBook.GetNameSearch(subscriberName) << std::endl;

		}
		else
		{

			std::cout << "Incorrect phone number entered" << std::endl;

		}
	}

	void SMS(AddressBook subscriberBook)
	{

		std::string message;

		std::cout << "Enter the phone number or name of the contact to whom you want to send the message: " << std::endl;
		std::cin >> subscriberName;

		if (subscriberName[0] == '+')
		{

			std::cout << "SMS to number: " << subscriberName << std::endl;
			std::cout << "Enter message text: ";
			std::cin >> message;
			std::cout << std::endl;

		}
		else if (subscriberName[0] != '+')
		{

			subscriberName = subscriberBook.GetNameSearch(subscriberName);
			std::cout << "SMS to number: " << subscriberName << std::endl;
			std::cout << "Enter message text: ";
			std::cin >> message;
			std::cout << std::endl;

		}
		else
		{

			std::cout << "Incorrect phone number entered" << std::endl;

		}


	}


};
int main() {

	AddressBook subscriberBook;
	Phone communique;
	
	std::string command;	
	
	do
	{

		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "add")
		{
			subscriberBook.SetAddContactName();
			subscriberBook.SetAddNumberPhone();
		}
		else if (command == "call")
		{

			communique.Call(subscriberBook);

		}
		else if (command == "sms")
		{

			communique.SMS(subscriberBook);

		}

	} while (command != "exit");	
}