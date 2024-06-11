//Author: Jay Garcia BSCPE - CPE11S1
//Created: 11/10/2023 - 
//Text Based Game v1.2 - Final Project

#include <iostream>
#include <windows.h>
using namespace std;

#define GREEN 2
#define RED 4
#define YELLOW 6
#define WHITE 7

string name, race, sex;
int HP=100, MP=100;
int gameAttempt, checkPoint;

void stringColor(int textColor);
void printString(int textColor, int printTime, int delayTime, string text);
int  attributeColor(int value);
void printStats(int HP, int MP, int sleepTime);
void printLoading(int delayTime, string text, bool pStats, int sleepTime);
void getUserInput(const string& promptUser, string& userInput);
bool user_is_Playing();

int main()
{
	while(user_is_Playing())
	{		// printDisclaimer()
		printString(WHITE, 0, 2000, "Text Based Game v1.0 - Final Project");
		printString(WHITE, 5, 500, "\n\nDisclaimer: ");
		printString(WHITE, 30, 500, "\nThis program is for educational purposes and has been submitted as a subject requirement for CPE-001.");
		printString(WHITE, 30, 500, "\nThe program has been created by John Michael Garcia of CPE11S1 and has been submitted to professor Dennis Nava, MIT.");
		printString(WHITE, 30, 500, "\nThe game will commence in any moment, please enjoy!");
		printString(WHITE, 5, 500, "\n\nPress any key to start . . . ");
		cin.get();
		system("CLS");	
		Sleep(500);
			// Introductory Story
		printString(WHITE, 60, 1000, "Once upon a time in the land of Mir.");
		printString(WHITE, 60, 1000, "\nThere was a summoner that set foot to the great lands of Mir.");
		printString(WHITE, 60, 1000, "\nAnd was given a task to save the world from the hands of the abbys.");
			// createCharacter()
		getUserInput("Enter Character's Name: ", name);
		getUserInput("Enter Character's Race: ", race);
		getUserInput("Enter Character's Sex: ", sex);
		Sleep(100);
		system("CLS");
		printLoading(2000, "Creating Character", false, 0);
		
			//Story proper
		
		while(checkPoint !=6 ) {	
			switch (checkPoint)
			{
				case 0:
					cout<<"yes";
					break;
				
				case 1:
					cout<<"no";
					break;
				
				case 2:
					cout<<"yes no";
					break;
				
				case 3:
					cout<<"yes no";
					break;
				
				case 4:
					cout<<"yes no";
					break;
				
				case 5:
					cout<<"yes no";
					break;
			}	
		}
		
		
	}
	
	return 0;
}

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

int attributeColor(int value)
{
	if(value == 100) return WHITE;
	else if(value >=70) return GREEN;
	else if(value >=30) return YELLOW;
	else return RED;
}

void printStats(int HP, int MP, int sleepTime)
{
	
	system("CLS");
	cout<<"||||||||||||||||||||||||||||||";
	cout<<"\n   Name: " <<name; 
	cout<<"\n   Race: " <<race;
	cout<<"\n   Sex: " <<sex;
	
	cout<<"\n   Health: ";
	stringColor(attributeColor(HP));
	cout<<HP;
	stringColor(WHITE);

	cout<<"    Mana: ";
	stringColor(attributeColor(MP));
	cout<<MP;
	stringColor(WHITE);

	cout<<"\n||||||||||||||||||||||||||||||";
	Sleep(sleepTime);
}

void printLoading(int delayTime, string text, bool pStats, int sleepTime)
{
	for(int i=0;i<3;i++) {
		if(pStats == true) {
			printStats(HP, MP, sleepTime);
			cout<<"\n\n";
		}
		
		cout<<text <<' ';
		for(int j=0;j<3;j++) {
			Sleep(300);
			cout<<". ";
		}
		Sleep(300);
		system("CLS");
	}
	Sleep(delayTime);
}

void getUserInput(const string& promptUser, string& userInput)
{
	printString(WHITE, 10, 300, promptUser);
	getline(cin,userInput);
}

bool user_is_Playing()
{
	string gameStatus, exitCode;
	while (true)
	{
		printString(WHITE, 0, 1000,"Text Based Game v1.0 - Final Project");
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
			
			if(exitCode[0] == 'y') {
				if(gameAttempt == 0)
				{
				system("CLS");
				Sleep(3000);
				printString(WHITE, 60, 1000, "Without the presence of the summoner, the abbys have taken over the land of Mir");
				printString(WHITE, 60, 3000, "\nThe era of the abbyss shall rise once again... ");
				}
				else {
					system("CLS");
					printString(WHITE, 40, 3000, "Thank you for your time, Summoner. ");
				}
				return false;
			}
			else if(exitCode[0] == 'n') {
				system("CLS");
			}
		}
	}
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
