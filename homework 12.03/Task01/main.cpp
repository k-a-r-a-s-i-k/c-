/*Є рядок «Пароль», значення якого «28Gd». Користувач вводить пароль. Якщо паролі співпадають, то його «впускає в систему».*/

#include <iostream>
using namespace std;
int main()
{
	const int SIZE = 5;
	const char password[SIZE] = "28Gd";
	char userPassword[SIZE];
	cout << "Enter password:::";
	cin.getline(userPassword, SIZE);
	if (strcmp(password, userPassword) == 0)
		cout << "Password is correct\n";
	else
		cout << "Password is incorect\n";
	system("pause");
	return 0;
}