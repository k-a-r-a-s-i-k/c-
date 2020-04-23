/*Користувач вводить текст. А потім вводить 2 індекси. Скопіювати в новий масив все, що находиться між цими індексами (включаючи їх).*/

#include <iostream>
using namespace std;
int main()
{
	const int SIZE = 100;
	char text[SIZE];
	cout << "Enter text\n";
	cin.getline(text, SIZE);
	size_t start, end;
	cout << "Enter the first ind:::";
	cin >> start;
	cout << "Enter the second ind:::";
	cin >> end;
	size_t newSize = end - start + 2;
	char* newText = new char[newSize];
	strncpy_s(newText, newSize, text + start, end - start + 1);
	cout << "New text is\n" << newText << endl;
	delete[] newText;
	newText = nullptr;

	system("pause");
	return 0;
}