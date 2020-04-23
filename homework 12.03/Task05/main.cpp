/*Користувач вводить текст. Потім вводить слово, яке хоче видалити. Видалити всі копії цього слова в масиві і вивести його на екран.*/

#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 100;
	const int WORDSIZE = 20;
	char text[SIZE] = "";
	cout << "Enter text\n";
	cin.getline(text, SIZE);
	char word[WORDSIZE] = "";
	cout << "Enter word you want to delete\n";
	cin.getline(word, 20);
	int sizeWord = strlen(word);
	int sizeText = strlen(text);
	if (strstr(text, word) != 0)
	{
		int indexWord = strstr(text, word) - text;
		int count = 1;
		for (size_t i = 0; i <= sizeText; i++)
		{
			if (strstr(text + indexWord + 1, word) != 0)
			{
				count++;
				indexWord = strstr(text + indexWord + 1, word) - text;
			}
			else
			{
				break;
			}
		}
		size_t newSize = sizeText - (sizeWord * count) + 1;
		char* temporaryText = new char[newSize];
		indexWord = strstr(text, word) - text;
		size_t indexText = 0, indexTempText = 0;
		while (indexTempText != newSize - 1)
		{
			while (indexTempText != newSize - 1)
			{
				if (indexText != indexWord)
				{
					temporaryText[indexTempText] = text[indexText];
					indexText++;
					indexTempText++;
				}
				else
				{
					indexText += sizeWord;
					break;
				}
			}
			if (strstr(text + indexWord + 1, word) != 0)
			{
				indexWord = strstr(text + indexWord + 1, word) - text;
			}
		}
		temporaryText[newSize - 1] = 0;
		strcpy_s(text, SIZE, temporaryText);
		cout << "Your new text\n" << text << endl;
		delete[] temporaryText;
		temporaryText = nullptr;
	}
	else
		cout << "There isnt word like "<<word<<"\n";
	system("pause");
	return 0;
}