#include <iostream>
#include <cmath>
#include <ctype.h>
#include <iomanip>
using namespace std;

int sizes(int number_choise) {
	cout << "������� �������: " << number_choise << "\n\n";
	cout << "int: " << sizeof(int) << "\n";
	cout << "short int: " << sizeof(short int) << "\n";
	cout << "long int: " << sizeof(long int) << "\n";
	cout << "float: " << sizeof(float) << "\n";
	cout << "double: " << sizeof(double) << "\n";
	cout << "long double: " << sizeof(long double) << "\n";
	cout << "char: " << sizeof(char) << "\n";
	cout << "bool: " << sizeof(bool) << "\n";
	return 0;
}


int bin_Int(int number_choise) {
	cout << "������� �������: " << number_choise << "\n\n";
	unsigned int bytes = 32, masks = 1 << bytes - 1, int_num;
	int A1[32] = {};
	cout << "������� ����� �����\n";

	while (!(cin >> int_num)) {
		cout << "������, ������ ������������ ��� ������\n";
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	while (int_num != 0) {

		for (int i = 0; i < bytes; i++) 
		{
			putchar(int_num & masks ? '1' : '0');
			A1[i] = (int_num & masks ? 1 : 0);
			int_num <<= 1;
			cout << (i == 0 || i % 8 == 0 ? " " : "");
		}

		cout << "\n�������� ������� �������� ������������� ����\n"
			"[1]��\n"
			"[2]���\n";

		int choises, a1, a2, temp, s = 0;

		while (!(cin >> choises)) {
			cout << "������, ������ ������������ ��� ������\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (choises == 1) {
			cout << "����� �������� �������� �������? ";
			cin >> a1 >> a2;
			if (a1 < a2) {
				temp = A1[a1 - 1];
				A1[a1 - 1] = A1[a2 - 1];
				A1[a2 - 1] = temp;
			}
			else {
				temp = A1[a2 - 1];
				A1[a2 - 1] = A1[a1 - 1];
				A1[a1 - 1] = temp;
			}

			for (int i = 0; i < bytes; i++) {
				cout << A1[i];
				cout << (i == 0 || i % 8 == 0 ? " " : "");
			}

			cout << "\n";

			for (int i = 0; i < bytes; i++) {
				s = s + (A1[i] * pow(2, (bytes - 1 - i)));
			}

			cout << "���������� �����: " << s << "\n";
		}
		cout << "������� �����: ";
		cout << "\n";
		
		while (!(cin >> int_num)) {
			cout << "������, ������ ������������ ��� ������\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}


	}
	return 0;
}

int bin_Float(int number_choise) {
	cout << "������� �������: " << number_choise << "\n\n";
	union
	{
		int int_Float;
		float float_Num;
	};
	unsigned int bites = sizeof(int) * 8, mask = 1 << bites - 1;
	int A1[32] = {};
	cout << "������� ������������ �����\n";
	cin >> float_Num;

	while (!(cin >> float_Num)) {
		cout << "������, ������ ������������ ��� ������\n";
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	while (float_Num != 0) {

		for (int i = 0; i < bites; i++)
		{
			putchar(int_Float & mask ? '1' : '0');
			A1[i] = (int_Float & mask ? 1 : 0);
			int_Float <<= 1;
			if (i == 0 || i == 1 || i == 8)
				putchar(' ');
		}

		cout << "\n�������� ������� �������� ������������� ����\n"
			"[1]��\n"
			"[2]���\n";

		int choises, a1, a2, temp;
		float s = 0;

		while (!(cin >> choises)) {
			cout << "������, ������ ������������ ��� ������\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (choises == 1) {
			cout << "����� �������� �������� �������? ";
			cin >> a1 >> a2;
			if (a1 < a2) {
				temp = A1[a1 - 1];
				A1[a1 - 1] = A1[a2 - 1];
				A1[a2 - 1] = temp;
			}
			else {
				temp = A1[a2 - 1];
				A1[a2 - 1] = A1[a1 - 1];
				A1[a1 - 1] = temp;
			}

			for (int i = 0; i < bites; i++) {
				cout << A1[i];
				cout << (i == 0 || i == 1 || i == 8 ? " " : "");
			}

			cout << "\n";

			for (int i = 0; i < bites; i++) {
				s = s + (A1[i] * pow(2, (bites - 1 - i)));
			}

			cout << "���������� �����: " << s << "\n";
		}
		cout << "������� �����: ";
		cout << "\n";

		while (!(cin >> float_Num)) {
			cout << "������, ������ ������������ ��� ������\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
	return 0;
}




int main()
{
	double number = 1;
	setlocale(LC_ALL, "RU");
	while (number != 0) {
		cout << "������� ����� �������:\n"
			"[1]����� ����������� ����� ������.\n"
			"[2]����� �������� ������ ������ ����� � ������������� ������.\n"
			"[3]����� �������� ������ ������������� ����� � ������������� ������.\n"
			"[0]����� �� ���������.\n";
		cout << "������� �: ";
		while (!(cin >> number)) {
			cout << "������, ������ ������������ ��� ������\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		int number_choise = floor(number);
		cout << "������� �������: " << number_choise;
		cout << "\n";
		if (number_choise == 1 || number_choise == 2 || number_choise == 3 || number_choise == 0) {

			switch (number_choise) {

			case(1):
			{
				system("cls");
				sizes(number_choise);
				system("pause");
				break;
			}
			case(2):
			{
				system("cls");
				bin_Int(number_choise);
				system("pause");
				break;
			}
			case(3):
			{
				system("cls");
				bin_Float(number_choise);
				system("pause");
				break;
			}
			}
		}
		else
		{
			cout << "������� ����� �� ��������� ���� 0 - 3\n\n";
			system("pause");
		}
		system("cls");
	}
}



	
