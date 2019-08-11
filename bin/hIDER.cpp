
/*

BASIC C++ FILE HIDER v1.1


**With Installer**








*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <experimental/string_view>
#include <thread>
#include <string>
#include <windows.h>
#include <process.h>
#include <unistd.h>
#include <io.h>
#include <sys/stat.h>


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

void RunThreadFunc1(void *This){
	MessageBox( hWnd, "Please Put all the game shortcut to this folder and press OK..", "Alert!", NULL);
}


void clr_scrn(){
	system("cls");
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
int main(int argc, char* argv[]){
	string pass = "admin";
	string input = "";
	int counter = 0;
	system("cls");
	if(std::experimental::string_view(argv[1]) == "run"){
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
	        return 0;
		}
		else{
			cout << "Starting Internet Explorer ;)";
			char *text = "start iexplore";
			system(text);
			return 0;
		}
	}
	else if(std::experimental::string_view(argv[1]) == "edit_pass"){
		///// Editing a password ///////////////
		string pass = "";
		cout << "Edit Password:";
		cin >> pass;
		ofstream myfile;
		myfile.open ("bin\\data.bin");
		myfile << pass;
		myfile.close();
		system("pause");
	}
	else if(std::experimental::string_view(argv[1]) == "first_install"){
		FILE *fptr = fopen("bin\\data.bin", "r");
		bool wrng_pass = false;
	    if (fptr == NULL){		
			///// INSTALLATION CODE ////////////
			cout << "Installing..\nPlease wait.." << endl;
			system("MD \"C:\\Windows\\Temp\\Internet Explorer\"");
			clr_scrn();
			cout << "Installing..\nPlease wait.." << endl;
			system("start explorer \"%USERPROFILE%\\Desktop\\Internet Explorer\"");
			MessageBox( hWnd, "Please Put all the game shortcut to this folder and press OK..", "Last Step!", NULL);
			system("taskkill /IM explorer.exe");
			system("MD \"%USERPROFILE%\\Desktop\\Internet Explorer\"");
			system("attrib +h \"%USERPROFILE%\\Desktop\\Internet Explorer\"");
			system("attrib +h \"C:\\Windows\\Temp\\Internet Explorer\"");
			system("move \"C:\\Users\\Dy\\Desktop\\Internet Explorer\\*.*\" \"C:\\Windows\\Temp\\Internet Explorer\"");
			clr_scrn();
			cout << "Initializing..";
			system("powershell Set-ExecutionPolicy -Scope CurrentUser Unrestricted\n./install.ps1");
			clr_scrn();
			system("bin\\hIDER.exe edit_pass");
		}
		else{
			int counter = 0;
			string line;
			string last_pass;
			ifstream myfile ("bin\\data.bin");
			if (myfile.is_open()){
				while ( getline (myfile,line) ){
					last_pass = line;
					break;
				}
				myfile.close();
			}
			while(counter != 3){
				cout << "Enter the password: ";
				string in;
				cin >> in;
				if(in == last_pass){
					cout << "C++ Game Launcher v1.1" << endl;
					cout << "1.Add A Game to the launcher\n2.Change the Password\nChoice:";
					int ch;
					cin >> ch;
					switch(ch){
						case 1:{					
							system("start explorer \"%USERPROFILE%\\Desktop\\Internet Explorer\"");
							MessageBox( hWnd, "Please Put all the game shortcut to this folder and press OK..", "Alert!", NULL);
							system("move \"C:\\Users\\Dy\\Desktop\\Internet Explorer\\*.*\" \"C:\\Windows\\Temp\\Internet Explorer\"");
							clr_scrn();
							system("taskkill /IM explorer.exe");
							counter = 3;
							break;
						}
						case 2:{
							counter = 0;
							while(counter != 3){
								string in1;
								clr_scrn();
								cout << "Validate Last Pass\nEnter Current Password:";
								cin >> in1;
								if(in1 == last_pass){
									system("bin\\hIDER.exe edit_pass");
									counter = 3;
									break;
								}
								else{
									clr_scrn();
									cout << "ERROR! WRONG PASSWORD!!\n" << 4-counter << "Tries Left!" << endl;
									system("pause");
									counter++;
									if(counter == 3) wrng_pass = true;
								}
							}
							break;
						}
					}
				}
				else{
					clr_scrn();
					cout << "ERROR! WRONG PASSWORD!!\n" << 4-counter << "Tries Left!" << endl;
					system("pause");
					counter++;
				}
			}
			if(wrng_pass){
				clr_scrn();
				cout << "ERROR! WRONG PASSWORD!!\n";
				cout << "Exiting App..." << endl;
				_sleep(3000);
			}

		}
	}
	else{
		cout << "Dont Open me u lil pervert!! >:(" << endl;
		system("pause");
	}

}
