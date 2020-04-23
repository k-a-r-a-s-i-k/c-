/*Користувач вводить текст. Потім вводить слово, яке хоче замінити.
Потім вводить слово, на яке хоче замінити. Замінити всі копії першого слова відповідно новим словом і вивести на екран (нове слово може бути і менше і більше по довжині).*/

#include <iostream>
using namespace std;
int main()
{
	const int SIZE = 100;
	const int WORDSIZE = 20;
	char text[SIZE];
	cout << "Enter word\n";
	cin.getline(text, SIZE);
	char word1[WORDSIZE];
	char word2[WORDSIZE];
	cout << "Enter word you want to change\n";
	cin.getline(word1, 20);
	cout << "Enter for what word you want to change\n";
	cin.getline(word2, 20);
	if (strstr(text, word1) != 0)
	{
		int sizeWord1 = strlen(word1);
		int sizeWord2 = strlen(word2);
		int sizeText = strlen(text);
		int indexWord = strstr(text, word1) - text;
		int count = 1;
		for (size_t i = 0; i <= sizeText; i++)
		{
			if (strstr(text + indexWord + 1, word1) != 0)
			{
				count++;
				indexWord = strstr(text + indexWord + 1, word1) - text;
			}
			else
			{
				break;
			}
		}
		size_t newSize = sizeText - (sizeWord1 * count) + (sizeWord2 * count) + 1;
		char* temporaryText = new char[newSize];
		indexWord = strstr(text, word1) - text;
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
					for (size_t i = 0; i < sizeWord2; i++)
					{
						temporaryText[indexTempText] = word2[i];
						indexTempText++;
					}
					indexText += sizeWord1;
					break;
				}
			}
			if (strstr(text + indexWord + 1, word1) != 0)
			{
				indexWord = strstr(text + indexWord + 1, word1) - text;
			}
		}
		temporaryText[newSize - 1] = 0;
		strcpy_s(text, SIZE, temporaryText);
		cout << "Your new text\n" << text << endl;
		delete[] temporaryText;
		temporaryText = nullptr;
	}
	else
		cout << "There isnt word like " << word1 << "\n";

	system("pause");
	return 0;
}
