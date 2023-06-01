#include <iostream>

struct Task
{
private:
	char* name;
	int priority;
	char* desc;
	char* date;
public:
	Task()
	{
		name = nullptr;
		priority = 0;
		desc = nullptr;
		date = nullptr;
	}
	void Set()
	{
		char temp[50];
		std::cout << "Enter name: ";
		std::cin.ignore();
		std::cin.getline(temp, 50);
		if (name != nullptr) delete[] name;
		name = new char[strlen(temp) + 1];
		strcpy_s(name, strlen(temp) + 1, temp);
		std::cout << "Enter desc: ";
		std::cin.getline(temp, 50);
		if (desc != nullptr) delete[] desc;
		desc = new char[strlen(temp) + 1];
		strcpy_s(desc, strlen(temp) + 1, temp);
		std::cout << "Enter priority: ";
		std::cin >> priority;
		std::cout << "Enter Date: ";
		std::cin.ignore();
		std::cin.getline(temp, 50);
		if (date != nullptr) delete[] date;
		date = new char[strlen(temp) + 1];
		strcpy_s(date, strlen(temp) + 1, temp);
		system("CLS");
	}
	void SetName(char* a)
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(a) + 1];
		strcpy_s(name, strlen(a) + 1, a);
	}
	void SetDesc(char* a)
	{
		if (desc != nullptr) delete[] desc;
		desc = new char[strlen(a) + 1];
		strcpy_s(desc, strlen(a) + 1, a);
	}
	void SetPrior(int a)
	{
		priority = a;
	}
	void SetDate(char* a)
	{
		if (date != nullptr) delete[] date;
		date = new char[strlen(a) + 1];
		strcpy_s(date, strlen(a) + 1, a);
	}
	int GetPrior()
	{
		return priority;
	}
	char* GetDate()
	{
		return date;
	}
	char* GetName()
	{
		return name;
	}
	char* GetDesc()
	{
		return desc;
	}
	void Print()
	{
		std::cout << "Name: " << name << "\nDesc: " << desc << "\nPrior: " << priority << "\nDate: " << date << '\n';
	}
	~Task()
	{
		delete[] name;
		delete[] desc;
		delete[] date;
	}
};

Task* book = new Task[10];

void date(int* arr, char* another_temp)
{
	arr[0] = (another_temp[3] - 48) * 10 + another_temp[4] - 48;
	arr[1] = (another_temp[0] - 48) * 10 + another_temp[1] - 48;
	arr[2] = (another_temp[6] - 48) * 1000 + (another_temp[7] - 48) * 100 + (another_temp[8] - 48) * 10 + (another_temp[7] - 48);
}

void print_day_one(int* date_1, int* date_2, char* another_temp, int SIZE)
{
	date(date_1, another_temp);
	for (int i = 0; i < SIZE; i++)
	{
		another_temp = book[i].GetDate();
		date(date_2, another_temp);
		if (date_2[0] == date_1[0] && date_2[1] == date_1[1] && date_2[2] == date_1[2])
		{
			book[i].Print();
		}
	}
}

void print_week(int* date_1, int* date_2, char* another_temp, char* a_another_temp, int SIZE)
{
	date(date_1, another_temp);
	for (int i = 0; i < SIZE; i++)
	{
		a_another_temp = book[i].GetDate();
		date(date_2, a_another_temp);
		for (int j = 0; j < 7; j++)
		{
			if (date_2[0] == date_1[0])
			{
				book[i].Print();
				break;
			}
			if (date_1[0] > 31)
			{
				date_1[0] = 1;
				date_1[1]++;
			}
			if (date_1[1] > 12)
			{
				date_1[1] = 1;
				date_1[2]++;
			}
			date_1[0]++;
		}
	}
}

void print_month(int* date_1, int* date_2, char* another_temp, char* a_another_temp, int SIZE)
{
	date(date_1, another_temp);
	for (int i = 0; i < SIZE; i++)
	{
		a_another_temp = book[i].GetDate();
		date(date_2, a_another_temp);
		for (int j = 0; j < 31; j++)
		{
			if (date_2[0] == date_1[0])
			{
				book[i].Print();
				break;
			}
			if (date_1[0] > 31)
			{
				date_1[0] = 1;
				date_1[1]++;
			}
			if (date_1[1] > 12)
			{
				date_1[1] = 1;
				date_1[2]++;
			}
			date_1[0]++;
		}
	}
}

int main()
{
	int SIZE = 0;
	int index = 0;
	Task* temp = new Task[10];
	Task* tmp = new Task[1];
	char char_temp[50];
	char* another_temp = new char[50];
	int ans;
	int t = 0;
	int date_1[3], date_2[3];
	char* a_another_temp = new char[50];
	do
	{
		std::cout << "1-Add\n2-Delete\n3-Edit\n4-Find\n5-Print\n0-Exit\n-->";
		std::cin >> ans;
		switch (ans)
		{
		case 1:
			if (SIZE == 0)
			{
				SIZE++;
				book[SIZE - 1].Set();
			}
			else
			{
				SIZE++;
				for (int i = 0; i < SIZE - 1; i++)
				{
					temp[i] = book[i];
				}
				temp[SIZE - 1].Set();
				for (int i = 0; i < SIZE; i++)
				{
					book[i] = temp[i];
				}
			}
			break;
		case 2:
			std::cout << "Enter delete index: ";
			std::cin >> index;
			for (int i = 0; i < SIZE; i++)
			{
				temp[i] = book[i];
			}
			for (int i = 0; i < SIZE; i++)
			{
				if (index != i)
				{
					book[t] = temp[i];
					t++;
				}
			}
			SIZE--;
			break;
		case 3:
			std::cout << "Enter Edit index: ";
			std::cin >> index;
			std::cout << "What you want to edit\n1-Name\n2-Desc\n3-Prior\n4-Date\n-->";
			std::cin >> ans;
			switch (ans)
			{
			case 1:
				std::cout << "Enter name: ";
				std::cin.ignore();
				std::cin.getline(char_temp, 50);
				book[index].SetName(char_temp);
			case 2:
				std::cout << "Enter desc: ";
				std::cin.ignore();
				std::cin.getline(char_temp, 50);
				book[index].SetDesc(char_temp);
			case 3:
				int a;
				std::cout << "Enter Prior: ";
				std::cin >> a;
				book[index].SetPrior(a);
			case 4:
				char temp[50];
				std::cout << "Enter Date: ";
				std::cin.ignore();
				std::cin.getline(temp, 50);
				book[index].SetDate(temp);
			}
			break;
		case 4:
			std::cout << "How you want to find\n1-Name\n2-Desc\n3-Prior\n4-Date\n-->";
			std::cin >> ans;
			switch (ans)
			{
			case 1:
				std::cout << "Enter name: ";
				std::cin.ignore();
				std::cin.getline(char_temp, 50);
				for (int i = 0; i < SIZE; i++)
				{
					if (!strcmp(book[i].GetName(), char_temp))
					{
						std::cout << "Found on spot " << i << '\n';
					}
				}
				break;
			case 2:
				std::cout << "Enter Desc: ";
				std::cin.ignore();
				std::cin.getline(char_temp, 50);
				for (int i = 0; i < SIZE; i++)
				{
					if (!strcmp(book[i].GetDesc(), char_temp))
					{
						std::cout << "Found on spot " << i << '\n';
					}
				}
				break;
			case 3:
				int a;
				std::cout << "Enter Prior: ";
				std::cin >> a;
				for (int i = 0; i < SIZE; i++)
				{
					if (book[i].GetPrior() == a)
					{
						std::cout << "Found on spot " << i << '\n';
					}
				}
				break;
			case 4:
				std::cout << "Enter Date: ";
				std::cin.ignore();
				std::cin.getline(char_temp, 50);
				for (int i = 0; i < SIZE; i++)
				{
					if (!strcmp(book[i].GetDate(), char_temp))
					{
						std::cout << "Found on spot " << i << '\n';
					}
				}
			}
			break;
		case 5:
			std::cout << "Do you want to sort\n1-yes\n2-no\n-->";
			std::cin >> ans;
			switch (ans)
			{
			case 1:
				std::cout << "1-Prior\n2-Date\n-->";
				std::cin >> ans;
				switch (ans)
				{
				case 1:
					std::cout << "Enter prior: ";
					std::cin >> ans;
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < SIZE - 1; j++)
						{
							if (book[i].GetPrior() >= book[i + 1].GetPrior())
							{
								tmp[0] = book[j];
								book[j] = book[j + 1];
								book[j + 1] = tmp[0];
							}
						}
					}
					std::cout << "Do you want to print tasks on\n1-Day\n2-week\n3-month\n4-show all\n-->";
					std::cin >> ans;
					std::cout << "Enter date: ";
					std::cin.ignore();
					std::cin.getline(another_temp, 50);
					switch (ans)
					{
					case 1:
						print_day_one(date_1, date_2, another_temp, SIZE);
						break;
					case 2:
						print_week(date_1, date_2, another_temp, a_another_temp, SIZE);
						break;
					case 3:
						print_month(date_1, date_2, another_temp, a_another_temp, SIZE);
						break;
					case 4:
						for (int i = 0; i < SIZE; i++)
						{
							book[i].Print();
						}
						break;

					}
					break;
				case 2:
					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < SIZE - 1; j++)
						{
							another_temp = book[j].GetDate();
							date(date_2, another_temp);
							another_temp = book[j + 1].GetDate();
							date(date_1, another_temp);
							if (date_2[2] > date_1[2] || date_2[1] > date_1[1] && date_2[2] == date_1[2] || date_2[0] > date_1[0] && date_2[1] == date_1[1] && date_2[2] == date_1[2])
							{
								tmp[0] = book[j];
								book[j] = book[j + 1];
								book[j + 1] = tmp[0];
							}
						}
					}
					std::cout << "Do you want to print tasks on\n1-Day\n2-week\n3-month\n4-show all\n-->";
					std::cin >> ans;
					std::cout << "Enter date: ";
					std::cin.ignore();
					std::cin.getline(another_temp, 50);
					switch (ans)
					{
					case 1:
						print_day_one(date_1, date_2, another_temp, SIZE);
						break;
					case 2:
						print_week(date_1, date_2, another_temp, a_another_temp, SIZE);
						break;
					case 3:
						print_month(date_1, date_2, another_temp, a_another_temp, SIZE);
						break;
					case 4:
						for (int i = 0; i < SIZE; i++)
						{
							book[i].Print();
						}
						break;

					}
					break;
				}
			case 2:
				
				std::cout << "Do you want to print tasks on\n1-Day\n2-week\n3-month\n4-show all\n-->";
				std::cin >> ans;
				std::cout << "Enter date: ";
				std::cin.ignore();
				std::cin.getline(another_temp, 50);
				switch (ans)
				{
				case 1:
					print_day_one(date_1, date_2, another_temp, SIZE);
					break;
				case 2:
					print_week(date_1, date_2, another_temp, a_another_temp, SIZE);
					break;
				case 3:
					print_month(date_1, date_2, another_temp, a_another_temp, SIZE);
					break;
				case 4:
					for (int i = 0; i < SIZE; i++)
					{
						book[i].Print();
					}
					break;
				}

				break;
			}


		}
	} while (ans != 0);
	delete[] book;
}