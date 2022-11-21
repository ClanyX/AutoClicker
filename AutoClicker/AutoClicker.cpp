#include <iostream>
#include <Windows.h>
using namespace std;

int speed = 0;

void menu()
{
	cout << "Press 'I' to enable and 'O' to disable autoclicker\nIf you want change speed press 'R'\n";
}

void clicker()
{
	bool click = false; //sets click to false

	while (true)
	{
		//change click speed
		if (GetAsyncKeyState('R')) {
			cout << "Write speed of click : ";
			cin >> speed;
			cout << "Press 'I' to enable and 'O' to disable autoclicker\nIf you want change speed press 'R'\n";
		}

		if (GetAsyncKeyState('I')) //if X is pressed click = true
		{
			click = true;
		}
		else if (GetAsyncKeyState('O')) //if 'Z' is pressed click = false
		{
			click = false;
		}
		if (click == true) // if click = true it will press the mouse button down and up really fast
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(speed); //you can adjust the speed of the click here
		}
	}
}

int main()
{
	cout << "Write speed of click : ";
	cin >> speed;
	menu();
	clicker();

	return 0;
}