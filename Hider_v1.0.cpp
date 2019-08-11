
/*

BASIC C++ FILE HIDER










*/


#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <windows.h>
#include <process.h>


HWND hWnd;

using namespace std;

HANDLE ThreadHandle;

void RunThreadFunc(void *This) {
        _sleep(2000);
        int m = MessageBox( hWnd, "Enjoy Your Games!!\n\nGame Launcher Will Expire in 30 seconds.", "Alert!", MB_TOPMOST  );
        switch(m){
            case IDOK:
            	char *move = "move \"C:\\Windows\\Temp\\Internet Explorer\\*.*\" \"C:\\Users\\Dy\\Desktop\\Internet Explorer\"";
				system(move);
				char *text = "start explorer C:\\Users\\Dy\\Desktop\\Internet Explorer";
				system(text);
                break;
        }
}

/*
//// Noting to do with this code just saving it in case ///////


 void timer_code()
{
	int exit_code;
	_sleep(3000);
	system("move \"C:\\Users\\Dy\\Desktop\\Internet Explorer\\*.*\" \"C:\\Windows\\Temp\\Internet Explorer\"");
	_sleep(2000);
	system("taskkill /IM explorer.exe");
}
void alert	()
{
    _sleep(2000);
	MessageBox( NULL, "Enjoy Your Games!!\n\nThis Window Will Expire in 30 seconds.", "Alert!", NULL);
}

*/
main(){
	string pass = "admin";
	string input = "";
	int counter = 0;
	system("cls");
	cout << "Enter the password; ";
	while(counter != pass.length()){
		char ch = getch();
		input += ch;
		system("cls");
		cout << "Enter the password; ";
		counter++;
	}
	if(pass == input){
		ShowWindow (GetConsoleWindow(), SW_HIDE);
		ThreadHandle = (HANDLE) _beginthread(RunThreadFunc, 0, NULL);
        cout << "HELLO" << endl;
        _sleep(30000);
        cout << "HELLO" << endl;
        system("move \"C:\\Users\\Dy\\Desktop\\Internet Explorer\\*.*\" \"C:\\Windows\\Temp\\Internet Explorer\"");
        _sleep(2000);
        system("taskkill /IM explorer.exe");
        MessageBox( hWnd, "Game Launcher Expired Please Login Again..", "Alert!", NULL);

	}
	else{
		cout << "Starting Internet Explorer ;)";
		char *text = "start iexplore";
		system(text);
	}
}
