/*Користувач вводить текст. А потім вводить 2 індекси. Видалити з масиву все, що находиться між цими індексами і вивести на екран.*/

#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int SIZE = 100;
	char text[SIZE] = "";
	cout << "Enter text\n";
	cin.getline(text, SIZE);
	size_t start, end;
	cout << "Enter first ind:::";
	cin >> start;
	cout << "Enter second ind:::";
	cin >> end;
	size_t newSize = strlen(text) - (end - start) + 1;
	char* Textt = new char[newSize];
	strncpy_s(Textt, newSize, text, start);
	strcat_s(Textt, newSize, text + end + 1);
	for (size_t i = 0; i < SIZE; i++)
	{
		text[i] = '\0';
	}
	strcpy_s(text, SIZE, Textt);
	cout << "Its new text\n" << text << endl;
	delete[] temporaryText;
	Textt = nullptr;
	system("pause");
	return 0;
}