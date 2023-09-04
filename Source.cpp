#include <iostream>

struct Employee
{
private:
	char* Name = nullptr;
	char* Surname = nullptr;
	char* Phone = nullptr;
	double Salary = 0.0;
public:
	void Add_Employee()
	{
		char* temp = new char[50];
		std::cout << "Enter name: ";
		std::cin.ignore();
		std::cin.getline(temp, 50);
		if (Name != nullptr)
		{
			delete[] Name;
		}
		Name = new char(strlen(temp) + 1);
		strcpy_s(Name, strlen(temp) + 1, temp);
		std::cout << "Enter surname: ";
		std::cin.getline(temp, 50);
		if (Surname != nullptr)
		{
			delete[] Surname;
		}
		Surname = new char(strlen(temp) + 1);
		strcpy_s(Surname, strlen(temp) + 1, temp);
		std::cout << "Enter phone: ";
		std::cin.getline(temp, 50);
		if (Phone != nullptr)
		{
			delete[] Phone;
		}
		Phone = new char(strlen(temp) + 1);
		strcpy_s(Phone, strlen(temp) + 1, temp);
		std::cout << "Enter salary: ";
		std::cin >> Salary;
		system("CLS");
	}
	void Add_Employee(char* name, char* surname, char* phone, double salary)
	{
		if (Name != nullptr)
		{
			delete[] name;
		}
		Name = new char(strlen(name) + 1);
		strcpy_s(Name, strlen(name) + 1, name);
		if (Surname != nullptr)
		{
			delete[] Surname;
		}
		Surname = new char(strlen(surname) + 1);
		strcpy_s(Surname, strlen(surname) + 1, surname);
		if (Phone != nullptr)
		{
			delete[] phone;
		}
		Phone = new char(strlen(phone) + 1);
		strcpy_s(Phone, strlen(phone) + 1, Phone);
		Salary = salary;
	}
	void Print()
	{
		std::cout << "Name: " << Name << '\n'
			<< "Surname: " << Surname << '\n'
			<< "Phone: " << Phone << '\n'
			<< "Salary: " << Salary << '\n';
	}
	char* Get_Surname()
	{
		return Surname;
	}
	double Get_Salary()
	{
		return Salary;
	}
	char* Get_Name()
	{
		return Name;
	}
};

int main()
{
	char* surname = new char[50];
	int size = 0;
	Employee* list = nullptr;
	Employee* temp = nullptr;
	int ans;
	do
	{
		std::cout << "1-Add Employee\n"
			<< "2-Print\n"
			<< "3-Find Surname\n"
			<< "4-Find salary\n"
			<< "5-Delete\n"
			<< "0-Exit\n"
			<< "--> ";
		std::cin >> ans;
		switch (ans)
		{
		default:
			system("CLS");
			std::cout << "Wrong input try again\n";
			break;
		case 1:
			system("CLS");
			if (list != nullptr)
			{
				temp = new Employee[size];
				for (int i = 0; i < size; i++)
				{
					temp[i] = list[i];
				}
				delete[] list;
				size++;
				list = new Employee[size];
				for (int i = 0; i < size - 1; i++)
				{
					list[i] = temp[i];
				}
				delete[] temp;
				list[size - 1].Add_Employee();
			}
			else
			{
				size++;
				list = new Employee[size];
				list[size - 1].Add_Employee();
			}
			break;
		case 2:
			system("CLS");
			for (int i = 0; i < size; i++)
			{
				list[i].Print();
			}
			break;
		case 3:
			system("CLS");
			std::cout << "Enter surname: ";
			surname == nullptr;
			std::cin.ignore();
			std::cin.getline(surname, 50);
			for (int i = 0; i < size; i++)
			{
				if (!strcmp(list[i].Get_Surname(), surname))
				{
					list[i].Print();
					break;
				}
				if (i == size - 1)
				{
					std::cout << "Not found\n";
				}
			}
			break;
		case 4:
			system("CLS");
			double min, max;
			std::cout << "Enter min: ";
			std::cin >> min;
			std::cout << "Enter max: ";
			std::cin >> max;
			for (int i = 0; i < size; i++)
			{
				if (list[i].Get_Salary() >= min && list[i].Get_Salary() <= max)
				{
					list[i].Print();
				}
			}
			break;
		case 5:
			char* temp = new char[50];
			system("CLS");
			std::cout << "Enter name: ";
			std::cin.ignore();
			std::cin.getline(temp, 50);
			int i;
			for (i = 0; i < size; i++)
			{
				if (!strcmp(list[i].Get_Name(), temp))
				{
					break;
				}
			}
			std::cout << "You sure you want to delete this Employee ";
			list[i].Print();
			std::cout << "\nY/N\n-->";
			char a;
			std::cin >> a;
			if (a == 'Y')
			{
				Employee* t = new Employee[size-1];
				for (int i = 0; i < size-1; i++)
				{
					t[i] = list[i];
				}
				delete[] list;
				size--;
				list = new Employee[size];
				for (int i = 0; i < size; i++)
				{
					list[i] = t[i];
				}
				delete[] temp;
			}
			if (a == 'N')
			{
				std::cout << "Employee will not be deleted\n";
			}
		}
	} while (ans != 0);
}