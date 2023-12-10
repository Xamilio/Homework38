#include <iostream>
using namespace std;

class Contact
	{
	int HomeNumber;
	int WorkNumber;
	int OwnNumber;
	char* Name;
	char* LastName;
	char* SurName;
	public:
		Contact() 
		{ 
			Name = nullptr;
			LastName = nullptr;
			SurName = nullptr;
			HomeNumber = 0;
			WorkNumber = 0;
			OwnNumber = 0;
		}
		Contact(int homen, int workn, int ownn)
		{
			SetNum(homen, workn, ownn);
		}
		Contact(const char* name, const char* lastname, const char* surname)
		{
			SetFIO(name, lastname, surname);
		}
		Contact(const char* name, const char* lastname, const char* surname, int homen, int workn, int ownn)
		{
			SetFIO(name, lastname, surname);
			SetNum(homen, workn, ownn);
		}
		inline void SetNum(int homen, int workn, int ownn)
		{
			if (homen < 0)
			{
				cout << "Error";
			}
			else
			{
				HomeNumber = homen;
			}

			if (workn < 0) 
			{
				cout << "Error";
			}
			else
			{
				WorkNumber = workn;
			}
			if (ownn < 0)
			{
				cout << "Error";
			}
			else
			{
				OwnNumber = ownn;
			}
		}
		inline void SetFIO(const char* name, const char* lastname, const char* surname)
		{
			if (Name == nullptr) 
			{
				delete[] Name;
			}
			Name = new char[strlen(name) + 1];
			strcpy_s(Name, strlen(name) + 1, name);
			if (LastName == nullptr)
			{
				delete[] LastName;
			}
			LastName = new char[strlen(lastname) + 1];
			strcpy_s(LastName, strlen(lastname) + 1, lastname);
			if (SurName == nullptr)
			{
				delete[] SurName;
			}
			SurName = new char[strlen(surname) + 1];
			strcpy_s(SurName, strlen(surname) + 1, surname);
		}
		int Get()
		{
			
		}
		void OutPut()
		{
			cout << "\nФИО: ";
			if (LastName == nullptr) cout << " ";
			else cout << LastName << " ";

			if (Name == nullptr) cout <<  " ";
			else cout << Name << " ";

			if (SurName == nullptr) cout << " ";
			else cout << SurName << " " << endl;

			cout << "Домашний номер: " << HomeNumber << endl;
			cout << "Рабочий номер: " << WorkNumber << endl;
			cout << "Личный номер: " << OwnNumber << endl;
			
		}
		~Contact ()
		{
			if (Name == nullptr)
			{
				delete[] Name;
			}
			if (LastName == nullptr)
			{
				delete[] LastName;
			}
			if (SurName == nullptr)
			{
				delete[] SurName;
			}
		}
};		


int main()
{
	setlocale(LC_ALL, "");
	int homen;
	int workn;
	int ownn;
	char name[100];
	char lastname[100];
	char surname[100];
	cout << "Введите Номера телефона" << endl;
	cout << "Домашный: ";
	cin >> homen;
	cout << "Рабочий: ";
	cin >> workn;
	cout << "Личный: ";
	cin >> ownn;
	cout << "ФИО" << endl;
	cout << "Фамилия: ";
	cin >> lastname;
	cout << "Имя: ";
	cin >> name;
	cout << "Отчество: ";
	cin >> surname;
	Contact obj(name, lastname, surname, homen, workn, ownn);
	obj.OutPut();
	obj.~Contact();
}



