/*���������� ������� ����� � �����. ������� �� ����� ������� �������, �� �� ����� �������� � �����.*/

#include <iostream>
using namespace std;
int main()
{
	const int SIZE = 100;
	char text[SIZE];
	cout << "Enter text\n";
	cin.getline(text, SIZE);
	int amountSymbol = strlen(text);
	int amountFree = SIZE - amountSymbol - 1;
	cout << "You can enter " << amountFree << " more\n";
	system("pause");
	return 0;
}