//Author: Jay Garcia BSCPE - CPE11S1
//Created: 11/10/2023 - 
//Text Based Game v1.0 - Final Project

#include <iostream>
#include <windows.h>
using namespace std;

string name, race, sex;
int HP=100, MP=100, gameAttempt;

void stringColor(int textColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,textColor);
}

void printString(int textColor, int printTime, int delayTime, string text)
{	
	stringColor(textColor);
	for(int i=0;i<text.length();i++)
	{	
		cout<<text[i];
		Sleep(printTime);
	}
	Sleep(delayTime);
}

void getUserInput(const string& promptUser, string& userInput)
{
	printString(7, 10, 300, promptUser);
	getline(cin,userInput);
}

bool userPlaying()
{
	string gameStatus, exitCode;
	while (true)
	{
		printString(7, 0, 1000,"Text Based Game v1.0 - Final Project");
		getUserInput("\nStart New Game(Y/N)?: ", gameStatus);
		gameStatus[0] = tolower(gameStatus[0]);
		
		if(gameStatus[0] == 'y')
		{
			gameAttempt++;
			system("CLS");
			return true;
		}
				
		else if(gameStatus[0] == 'n')
		{
			getUserInput("Are you sure to exit the program(Y/N)? ", exitCode);
			exitCode[0] = tolower(exitCode[0]);
			
			if(exitCode[0] == 'y')
			{
				if(gameAttempt == 0)
				{
				system("CLS");
				Sleep(3000);
				printString(7, 60, 1000,"Without the presence of the summoner, the abbys have taken over the land of Mir");
				printString(7, 60, 3000,"\nThe era of the abbyss shall rise once again... ");
				}
				else {
					printString(7, 40, 3000,"Thank you for your time, Summoner. ");
				}
				return false;
			}
			else if(exitCode[0] == 'n') {
				system("CLS");
			}
		}
	}
}

void printDisclaimer()
{
	printString(7, 0, 3000,"Text Based Game v1.0 - Final Project");
	printString(7, 5, 500,"\n\nDisclaimer: ");
	printString(7, 30, 500,"\nThis program is for educational purposes and has been submitted as a subject requirement for CPE-001.");
	printString(7, 30, 500,"\nThe program has been created by John Michael Garcia of CPE11S1 and has been submitted to professor Dennis Nava, MIT.");
	printString(7, 30, 500,"\nThe game will commence in any moment, please enjoy!");
	printString(7, 5, 500,"\n\nPress any key to start . . . ");
	cin.get();
	system("CLS");	
	Sleep(500);
}

void createCharacter()
{
	getUserInput("Enter Character's Name: ", name);
	getUserInput("Enter Character's Race: ", race);
	getUserInput("Enter Character's Sex: ", sex);
	Sleep(100);
	system("CLS");
	
	for(int i=0;i<3;i++)
	{
		cout<<"Creating Character ";
		for(int j=0;j<3;j++)
		{
			Sleep(300);
			cout<<". ";
		}
		Sleep(300);
		system("CLS");
	}
	Sleep(2000);
}

int attributeColor(int value) {
	if(value == 100) return 7;
	else if(value >=70) return 2;
	else if(value >=30) return 6;
	else return 4;
}

void printStats(int HP, int MP)
{
	cout<<"||||||||||||||||||||||||||||||";
	cout<<"\n   Name: " <<name;
	cout<<"\n   Race: " <<race;
	cout<<"\n   Sex: " <<sex;
	
	cout<<"\n   Health: ";
	stringColor(attributeColor(HP));
	cout<<HP;
	stringColor(7);

	cout<<"    Mana: ";
	stringColor(attributeColor(MP));
	cout<<MP;
	stringColor(7);

	cout<<"\n||||||||||||||||||||||||||||||";
	Sleep(1000);
}

void updateStats(int& attribute, char sign, int value)
{
	switch (sign) {
		case '+':
			attribute += value;
			break;
		case '-':
			attribute -= value;
			break;
	}
}

int main()
{
	while(userPlaying()) 
	{
		printDisclaimer();
		createCharacter();
		
		printString(7, 60, 1000,"Once upon a time in the land of Mir.");
		printString(7, 60, 1000,"\nThere was a summoner that set foot to the great lands of Mir.");
		printString(7, 60, 1000,"\nAnd was given a task to save the world from the hands of the abbys.");
		system("CLS");
	}
	
	return 0;
}

//Plague that infected the population for example hillicurls
//The blood of the main character is very crucial in order to purify the hillicurls, the plague
//The plot twist is that the main character is residing in the kingdom
//The MC did not realized that while he was still young, he accidentally did something
	//that resulted into a threath for many poeple,
//Then the MC did the right thing and fixed the threth that he once declared when he was young
//The king of the kingdom can be the villain the the story
//before the plague even stated, the greedy king started the plague in order to gain the power of the MC from its blood
//The king itself annihilated the MC's bloodline but because of the goddess, blessing, the MC was granted a holy
	//power that is present in his blood
//A side character that is like Myne (rising shield)
//Something ancient ruins where something very important event will occur once the blood of the MC is offered.
//And that ancient ruins was built by the ancestors of the MC.
//
//
	



