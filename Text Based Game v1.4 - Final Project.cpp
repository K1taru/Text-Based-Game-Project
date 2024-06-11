//Author: Jay Garcia BSCPE - CPE11S1
//Created: 11/10/2023 - 
//Text Based Game v1.4 - Final Project

#include <iostream>
#include <windows.h>
using namespace std;

#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHTBLUE 9

string name, race, sex;
string arrStatus[4] = {"Alive", "Alive", "Injured", "Dying"};
int arrColor[4] = {WHITE, GREEN, YELLOW, RED};
int gameAttempt, checkPoint, cS, HP=100, mainChoice, secondaryChoice;



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

void activateSkill(int textColor, int delayTime, string skill)
{
	stringColor(textColor);
	cout<<"''" <<skill <<"''";
	stringColor(WHITE);
	cout<<" < skill activated >";
	Sleep(delayTime);
}

void updateHP(int HP)
{
	if(HP == 100) cS = 0;
	else if(HP >=70) cS = 1;
	else if(HP >=30) cS = 2;
	else cS = 3;
}

void printAttributes(int delayTime)
{
	system("CLS");
	cout<<"|||||||||||||||||||||||||||||||||";
	cout<<"\n   Name: " <<name; 
	cout<<"\n   Race: " <<race;
	cout<<"\n   Sex: " <<sex;
	
	cout<<"\n   Health: ";
	stringColor(arrColor[cS]);
	cout<<HP;
	stringColor(WHITE);

	cout<<"  Status: ";
	cout<<arrStatus[cS];

	cout<<"\n|||||||||||||||||||||||||||||||||";
	Sleep(delayTime);
}

void printLoading(int textColor, int times, int speed, string text, int delayTime)
{
	stringColor(textColor);
	for(int i=0;i<times;i++)
	{
		cout<<text <<' ';
		for(int j=0;j<3;j++) {
			Sleep(speed);
			cout<<". ";
		}
	Sleep(speed);
	system("CLS");
	}
	Sleep(delayTime);
}

void printLoadingandStats(int textColor, int times, int speed, string text, int delayTime)
{
	for(int i=0;i<times;i++) {
		printAttributes(0);
		cout<<"\n\n";
			
		stringColor(textColor);
		cout<<text <<' ';
		for(int j=0;j<3;j++) {
			Sleep(speed);
			cout<<". ";
		}
	Sleep(speed);
	system("CLS");
	}
	Sleep(delayTime);
}

void getUserInput(const string& promptUser, string& userInput)
{
	printString(WHITE, 10, 300, promptUser);
	getline(cin,userInput);
}

void getUserChoice(const string& promptUser,int& userChoice, int choiceCount)
{
	do {
		printString(WHITE, 3, 0, promptUser);
		cin>>userChoice;
	} while (userChoice<1 || userChoice>choiceCount);
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

int main()
{		//user_is_Playing()
	while(true)
	{		// printDisclaimer()
		printString(WHITE, 0, 2000, "Text Based Game v1.0 - Final Project");
		printString(WHITE, 5, 500, "\n\nDisclaimer: ");
		printString(WHITE, 30, 500, "\nThis program is for educational purposes and has been submitted as a subject requirement for CPE-001.");
		printString(WHITE, 30, 500, "\nThe program has been created by John Michael Garcia of CPE11S1 and has been submitted to professor Dennis Nava, MIT.");
		printString(WHITE, 30, 1000, "\nThe game will commence in any moment, please enjoy!");
		printString(WHITE, 3, 500, "\n\nPress any key to start . . . ");
		cin.get();
		system("CLS");	
		Sleep(1200);
			// introductory Story
		printString(WHITE, 20, 1000, "In the olden days of the peaceful and serene realm of the Kingdom of Theaipi.");
		printString(WHITE, 20, 1000, "\nPeople whom resides the great Kingdom lived in peace and habited in the prosperous lands.");
		printString(WHITE, 20, 1000, "\nNot until when the demon lord named Cafacitius waged war against the Kingdom of Theaipi and caused bloodshed.");
		printString(WHITE, 20, 1000, "\nResulted the Kingdom's forces to decline, The King asked the highest order, the church for an aid.");
		printString(WHITE, 20, 1000, "\nThere exist a forbidden spell which summons an entity from another world that only the pontifex knows.");
		printString(WHITE, 20, 50, "\nThe Pontifex, having no other options, casted the forbidden spell, ");
		printString(PURPLE, 20, 2000, "''Rennaisance''.\n");
		printString(WHITE, 3, 500, "\nPress any key to contiue . . . ");
		cin.get();
		system("CLS");
		printLoading(WHITE, 2, 400, "", 2000);
			// player gets involved
		printString(WHITE, 5, 1000, "January 1st, year 2100 of the Common Era(CE),\n");
		printString(WHITE, 20, 1000, "\nYou enjoy the new year celebration while you are observing the fireworks above the sky,");
		printString(WHITE, 20, 1000, "\nYou noticed that there was an allignment of constellation and brightly shining towards you.");
		printString(WHITE, 3, 500, "\nPress any key to contiue . . . ");
		cin.get();
		system("CLS");
		printLoading(PURPLE, 4, 200, "ilithios", 2000);
			// transfer to another world
		printString(WHITE, 5, 1000, "1 Ianouariou, Etos 700 tou Theaipi Imerologiou(TC),\n");
		printString(WHITE, 20, 1000, "\nChairomai! pou to metafrazeis! me periergeia!\n\n  ");
		activateSkill(AQUA, 3000, "MULTI-TONGUE");
		printString(WHITE, 3, 500, "\nPress any key to contiue . . . ");
		cin.get();
		system("CLS");
		printString(WHITE, 5, 1000, "January 1st, year 700 of the Theaipian Calendar(TC),");
		printString(WHITE, 20, 3000, "\n\nThe spell worked your highest!, everyone!, the summoner has arrived!");
		system("CLS");
		printString(YELLOW, 5, 800, "< SYSTEM >: " );
		printString(WHITE, 5, 3000, "Welcome Summoner.");
		system("CLS");
			// createCharacter()
		getUserInput("Enter Summoner's Name: ", name);
		getUserInput("Enter Summoner's Race: ", race);
		getUserInput("Enter Summoner's Sex: ", sex);
		Sleep(100);
		system("CLS");
		printLoading(WHITE, 3, 300, "Creating Character", 2000);
		
			//Story proper
		
		while(checkPoint !=6 ) {	
			switch (checkPoint)
			{
				case 0:
					printAttributes(0);
					printString(WHITE, 25, 1000, "\n\nYou woke up after loosing consciousness,");
					printString(WHITE, 20, 1000, "\nThe next thing you realized is that you we're standing in the middle of an enormous magical circle,");
					printString(WHITE, 20, 2000, "\nYou also realized that you are in an unfamilliar place, and the people around you are unfamilliar.");
					printString(WHITE, 3, 3000, "\nPress any key to continue . . . ");
					cin.get();
					printString(WHITE, 20, 1000, "\nSomeone wearing a gold-accented white robe approaches you,");
					printString(WHITE, 20, 1000, "\nPontifex: I know you might be wondering what is going on around you,"); 
					printString(WHITE, 25, 1000, "\nPontifex: I am the great Pontifex of the holy chuch, and right now, you are in the Kingdom of Theaipi.");
					
					printString(YELLOW, 0, 500, "\n\nActions:");
					printString(WHITE, 0, 500, "\n (1) - Ask the Pontifex why you are inside the magical circle.");
					printString(WHITE, 0, 1000, "\n (2) - Proceed to leave and escape the place.\n");
					getUserChoice("\tEnter your choice: ", mainChoice, 2);
					
					if(mainChoice == 1)
					{
						printString(WHITE, 20, 1000, "\nPontifex: Right now, you are inside the grand cathedral of this kingdom,");
					}
					
					else if(mainChoice == 2)
					{
						printString(WHITE, 3, 2000, "\n < You have been blocked by the holy knights if the highest order > ");
						printString(WHITE, 20, 1000, "\nPontifex: It's no use, right now, this is the safest place you would ever find.");
					}
					
					printString(WHITE, 20, 1000, "\nPontifex: I presume you came from another world, yes?");
					printString(WHITE, 20, 1000, "\nPontifex: To be blunt, right now the demon lord Cafacitious waged war against us,");
					printString(WHITE, 20, 0, "\nPontifex: The magic circle below you is the forbidden spell ");
					printString(PURPLE, 20, 1000, "''Rennaisance''.");
					printString(WHITE, 20, 1000, "\nPontifex: An ancient spell that can only be used 700 years.");
					printString(WHITE, 20, 1000, "\nPontifex: The entity that was called by the spell is what we refer to as the summoner.");
					printString(WHITE, 20, 1000, "\nPontifex: Even if the summoner faces its death, the summoner will be resurrected right on the center.");
					printString(WHITE, 20, 1000, "\nPontifex: So summoner, please do save our kingdom, and we shall grant you the throne of this Kingdom in return.");
					
					printString(YELLOW, 0, 500, "\n\nActions:");
					printString(WHITE, 0, 500, "\n (1) - Very well.");
					printString(WHITE, 0, 500, "\n (2) - Sure.");
					printString(WHITE, 0, 1000, "\n (3) - I'm willing to.");
					getUserChoice("\n\tEnter your choice: ", mainChoice, 3);
					
					if(mainChoice>0 && mainChoice<4) {
					printString(WHITE, 3, 2000, "\n   < Check Point Saved > ");
					}
					system("CLS");
					printAttributes(1000);
					checkPoint++;
					
				case 1:
					printString(WHITE, 20, 1000, "\n\nYou are inside the grand cathedral, Dicathen.");
					printString(WHITE, 20, 1000, "\nHoly Priestess: Greetings summoner, thank you for your service in protecting thy kingdom of Theaipi. ");
					
					printString(WHITE, 20, 500, "\n\nActions:");
					printString(WHITE, 0, 500, "\n (1) - Go outside the grand cathedral");
					printString(WHITE, 0, 500, "\n (2) - Pray and ask for blessings for ");
					printString(WHITE, 0, 1000, "\n (3) - Ask the priestress about the cathedral");
					
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
// Dicathen, Alacrya, and Epheotus
// Asura, augmenter, mage
