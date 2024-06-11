//Author: Jay Garcia BSCPE - CPE11S1
//Created: 11/10/2023 - 12/15/2023
//Text Based Game v1.5 - Final Project

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
string arrStatus[5] = {"Alive", "Alive", "Injured", "Dying", "Dead"};
int arrColor[5] = {WHITE, GREEN, YELLOW, RED, RED};
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
	else if(HP >=1)cS = 3;
	else {
		system("CLS");
		printString(RED, 60, 3000, " < YOU DIED >");
		cS = 4;
	}
}

void printAttributes(int delayTime)
{
	stringColor(WHITE);
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
				printString(WHITE, 60, 1000, "Without the presence of the summoner, demon lord Cafacitious has completely take over the Kingdom of Theaipi.");
				printString(WHITE, 60, 3000, "\nThe Cafacitiusian era shall rise and rule over the new kingdom.");
				}
				else {
					system("CLS");
					printString(WHITE, 40, 3000, "Thank you for your time, Summoner. (see you next season)");
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
{
	while(user_is_Playing())
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
		printString(WHITE, 3, 500, "\n\nPress any key to contiue . . . ");
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
						printString(WHITE, 20, 1000, "\n\nPontifex: It's no use, right now, this is the safest place you would ever find.");
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
					checkPoint++;
					
				case 1:
					printAttributes(1000);
					printString(WHITE, 20, 1000, "\n\nYou are inside the grand cathedral, Dicathen.");
					printString(WHITE, 20, 1000, "\nHoly Priestess: Greetings summoner, thank you for your service in protecting thy kingdom of Theaipi. ");
					
					printString(WHITE, 20, 500, "\n\nActions:");
					printString(WHITE, 0, 500, "\n (1) - Ask the priestress about the cathedral");
					printString(WHITE, 0, 500, "\n (2) - Pray and ask for blessings from the Theaipian god");
					printString(WHITE, 0, 1000, "\n (3) - Go outside the grand cathedral");
					getUserChoice("\n\tEnter your choice: ", mainChoice, 3);
					
					if(mainChoice == 1)
					{
						printString(WHITE, 20, 1000, "\n < you approached and asked the preistess >");
						printString(WHITE, 20, 1000, "\n\nPreistess: The grand cathedral is where the late summoner, Arthur Theiapi rests,");
						printString(WHITE, 20, 1000, "\nPreistess: The catheral was built after the sages war which ended the Navarian era,");
						printString(WHITE, 20, 1000, "\nPreistess: It was also the beginning of the Theaipian era where the late summoner ruled as the new King,");
						printString(WHITE, 20, 1000, "\nPreistess: The cathedral then became the most sacred place even greater than the Dicathen Castle,");
						printString(WHITE, 20, 1000, "\nPreistess: That is the origin of the great cathedral of Dicathen.");
						printString(WHITE, 3, 1000, "\n\nPress any key to continue . . . ");
						fflush(stdin);
						cin.get();
						system("CLS");
					}
					
					if(mainChoice == 2)
					{
						system("CLS");
						printAttributes(500);
						printString(WHITE, 20, 2000, "\n\n < you bow your head and proceeds to pray >");
						system("CLS");
						updateHP(HP=100);
						printAttributes(0);
						printString(WHITE, 0, 1000, "\n\n < you bow your head and proceeds to pray >");
						system("CLS");	
					}
					
					else if(mainChoice == 3)
					{
						system("CLS");
						checkPoint++;
					}
					break;
				
				case 2:
					printAttributes(1000);
					printString(WHITE, 20, 1000, "\n\nYou are now outside,");
					printString(WHITE, 20, 1000, "\nYou saw three of the largest buildings in front of the cathedral,");
					printString(WHITE, 20, 1000, "\nWhere would you like to go next?");
					
					printString(WHITE, 20, 500, "\n\nActions:");
					printString(WHITE, 0, 500, "\n (1) - Enter the Epheotus Guild");
					printString(WHITE, 0, 500, "\n (2) - Visit the Baronian's Inn");
					printString(WHITE, 0, 500, "\n (3) - Enter the Theaipi grand weaponry");
					printString(WHITE, 0, 1000, "\n (4) - Return inside the cathedral");
					getUserChoice("\n\tEnter your choice: ", mainChoice, 4);
					
					if(mainChoice == 1)
					{	
						printString(WHITE, 20, 1000, "\n < you entered the Epheotus Guild >");
						printString(WHITE, 20, 1000, "\n\nReceptionist: Welcome to the Epheotus guild traveller, how can I help you?");
						printString(WHITE, 20, 1000, "\n\n < you notice that everyone seems suspicious of you >");
						
						printString(WHITE, 20, 500, "\n\nActions:");
						printString(WHITE, 0, 500, "\n (1) - Ignore the malicious looks of others");
						printString(WHITE, 0, 500, "\n (2) - Introduce yourself as the summoner");
						printString(WHITE, 0, 1000, "\n (3) - Pick a fight to them");
						getUserChoice("\n\tEnter your choice: ", secondaryChoice, 3);
						
						if(secondaryChoice == 1)
						{
							printString(WHITE, 20, 1000, "\nYou: I would like something to eat please,");
							printString(WHITE, 20, 1000, "\nReceptionist: Please be informed that we can only serve food to those registered adventurers.");
							printString(WHITE, 20, 2000, "\nReceptionist: Register to Epheotus Guild and climb the ranks first before such requests.");
							secondaryChoice +=2;
						}
						
						if(secondaryChoice == 2)
						{
							printString(WHITE, 20, 1000, "\n < you introduced as the summoner >");
							printString(WHITE, 20, 1000, "\n\nEveryone was shocked to what you have said");
							printString(WHITE, 20, 1000, "\n\n < you show the sign of your rebirth >");
							printString(WHITE, 20, 1000, "\n\nReceptionist: I'm terribly sorry for the tone of my voice lord summoner,");
							printString(WHITE, 20, 1000, "\nReceptionist: Please let me escort you to the finest weponry of Theaipi kingdom.");
							printString(WHITE, 20, 1000, "\n\n < you we're escorted back outside and wen't to the Theiapi grand weaponry > ");
							printString(WHITE, 3, 1000, "\n\nPress any key to continue . . . ");
							fflush(stdin);
							cin.get();
							mainChoice+=2;
							system("CLS");
						}
						
						if(secondaryChoice == 3)
						{
							printString(WHITE, 20, 1000, "\n\n < you attracted the attention of some adventurers > ");
							printString(WHITE, 20, 1000, "\n\nAdventurer: it seems like someone needs some beating!");
							printString(WHITE, 20, 1000, "\n\n < a group of adventurers teamed up >");
							
							for(int i=0;i<5;i++)
							{
								printLoadingandStats(WHITE, 1, 200, "Getting beaten", 0);
								updateHP(HP-=10);
							}
							
							if(HP>0)
							{
								printAttributes(1000);
								printString(WHITE, 20, 2000, "\n\n < you left the guild in shame >");	
							}
							
							else if(HP<=0) {
								updateHP(HP=25);
								checkPoint--;
							}
						}	
					}
					
					if(mainChoice == 2)
					{
						printString(WHITE, 20, 1000, "\n < The Baronian's Inn is currently closed >");
						printString(WHITE, 20, 2000, "\n\nSummoner: I guess I'll try to come here next time.");
						printString(WHITE, 20, 500, "\n\nActions:");
						printString(WHITE, 0, 500, "\n (1) - Return outside");
						getUserChoice("\n\tEnter your choice: ", secondaryChoice, 1);
						
						if(secondaryChoice == 1 ) system("CLS");
					}
					
					if(mainChoice == 3)
					{
						printAttributes(1000);
						printString(WHITE, 20, 1000, "\n\n < you entered the Theaipi grand weponry > ");
						printString(WHITE, 20, 1000, "\n\nKnight Captain: Welcome, I presume you are the summoner of this era?");
						printString(WHITE, 20, 0, "\nKnight Captain: Please follow me, I will lead you to the ");
						printString(AQUA, 20, 2000, "Summoner's Secret Chamber.");
						printString(WHITE, 20, 1000, "\n\n < you follow the lead of the Knight Captain > ");
						printString(WHITE, 20, 1000, "\n\nKnight Captain: This is the weapons chamber exclusively for the summoner,");
						printString(WHITE, 20, 1500, "\nKnight Captain: Please do feel free to suit yourself");
						printString(WHITE, 3, 1000, "\n\nPress any key to equip your weapons . . . ");
						fflush(stdin);
						cin.get();
						system("CLS");
						
						printAttributes(1000);
						printString(YELLOW, 0, 500, "\n\n < [L] - Godslayer Spear equipped > ");
						activateSkill(AQUA, 1000, "\nPearcing Spear (passive)");
						printString(YELLOW, 0, 500, "\n\n < [L] - War Dragon Breastplate equipped > ");
						activateSkill(AQUA, 1000, "\nHeavenly Protection (passive)");
						printString(YELLOW, 0, 500, "\n\n < [L] - Heavenly Connection Armlet equipped > ");
						activateSkill(AQUA, 1000, "\nDouble Strike (passive)");
						printString(YELLOW, 0, 500, "\n\n < [L] - Heavenly Divinity Robe equipped > ");
						activateSkill(AQUA, 2000, "\nMagic Wall (passive)");
						
						printString(WHITE, 20, 2000, "\n\n < you gained powerful skills >");
						printString(WHITE, 20, 2000, "\n\n < your journey as the summoner will soon begin >");
						printString(WHITE, 3, 1000, "\n\nPress any key to continue . . . ");
						fflush(stdin);
						cin.get();
						system("CLS");
						checkPoint++;
					}
					
					if(mainChoice == 4)
					{
						checkPoint--;
					}
					break;
				
				case 3:
					Sleep(2000);
					printString(WHITE, 30, 1500, "\nYou will be training along with the finest knights of the kingdom of Theaipi,");
					printString(WHITE, 30, 1500, "\nUntil you get strong enough to defeat the demon lord Cafacitius, you will strive to get stronger,");
					printString(WHITE, 30, 1500, "\nAnd sooner, to save the poeple, and mark a new beginning of an era.");
					system("CLS");
					Sleep(1000);
					printString(WHITE, 30, 1500, "Until we meet again, Summoner.");
					system("CLS");
					checkPoint++;
					break;
				
				case 4:
					checkPoint++; // chapter 2, future sequel
					break;
				
				case 5:
					checkPoint++;
					break;
			}	
		}
	}
	return 0;
}
