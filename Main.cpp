/***********************************************************************************
 * End Semester Project                                                            *
 * The Checkers v1.0                                                               *
 * Members ==> | Mohammad Uzair | Fatima Hassan | Muhammad Mubeen | M. Asad Ali  | *
 * Class ==> BSCS-5A                                                               *
 ***********************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "Coder.h"

int choice;							//for user choice in menu
/* initializing the board array with pieces as a global array
  -1 for boxes which can not be used
   1 for pieces of player1
   2 for pieces of player2
   0 for unsed usable boxes */
int boxes[8][8] = { {-1, 1,-1, 1,-1, 1,-1, 1 }, 
					{ 1,-1, 1,-1, 1,-1, 1,-1 }, 
					{-1, 1,-1, 1,-1, 1,-1, 1 }, 
					{ 0,-1, 0,-1, 0,-1, 0,-1 }, 
					{-1, 0,-1, 0,-1, 0,-1, 0 }, 
					{ 2,-1, 2,-1, 2,-1, 2,-1 }, 
					{-1, 2,-1, 2,-1, 2,-1, 2 }, 
					{ 2,-1, 2,-1, 2,-1, 2,-1 } };

void main()
{	
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );	
	SetConsoleTitle( TEXT( "The Checkers" ) );

	system("mode 168,64");									//for adjusting the console screen
	system("color 3f");
	int tossCoin;
    int printMenu=1;										//flag used for returning to menu screen
	welcome();						     					//printing the welcome screen
	while(printMenu){
		choice=menu();								   		//print menu	
		if(choice == 0)
			menu();											//print menu
		else if(choice==2 ){
			instruction();									//print instruction
			continue;}               
		else if(choice==3 ){           
			position(55,42);
			exit(0);}										//quit the game
		else if(choice==4 ){
			board();										//print board
			pieces();										//print pieces
			playerTurn(1);}									//set first turn to player1
		else if(choice==5 ){
			tossCoin = toss();								//starting the toss 
			board();										//printing the game board
			pieces();										//printing the pieces on board	
			if(tossCoin==1)
				playerTurn(1);								//set first turn to player1
			else if(tossCoin==2)
				playerTurn(2);								//set first turn to player2
			}
		else 
			menu();											//print menu
	}
}
//function definition position --> sets the position of cursor
void position(int x, int y){
	COORD axis;
	axis.X = x;                                        //set x co-ordinate of screen                    
	axis.Y = y;                                        //set y co-ordinate of screen
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), axis);
}

//function definition menu
int menu(){
	SetConsoleTitle( TEXT( "Menu - The Checkers" ) );
	system("CLS");                                      //clear the screen
	int option;
	/* Start printing box for menu */
	position(43,5);                                    
	for (int i = 0; i < 62; i++)
		printf("\x16");                                			                              
	puts("");
	for (int row = 0; row < 40; row++)
		printf("\t\t\t\t\t   \x19                                                            \x19\n");
	position(43, 45);
	for (int i = 0; i < 62; i++)
		printf("\x16");
	/* End printing box for menu */    
	position(55, 9);	printf("##     ## ######## ##    ## ##     ##\n");
	position(55, 10);	printf("###   ### ##       ###   ## ##     ##\n");
	position(55, 11);	printf("#### #### ##       ####  ## ##     ##\n");
	position(55, 12);	printf("## ### ## ######   ## ## ## ##     ##\n");
	position(55, 13);	printf("##     ## ##       ##  #### ##     ##\n");
	position(55, 14);	printf("##     ## ##       ##   ### ##     ##\n");
	position(55, 15);	printf("##     ## ######## ##    ##  #######\n");

	char options[4][18] = { { "1. Start game" }, { "2. Instruction" }, { "3. Quit" }, { "Choose option : " } };
	for (int row = 0; row < 4; row++){
		position(55, 20 + 6 * row);                   //set position with difference of six rows
		for (int col = 0; col < 18; col++){
			printf("%c", options[row][col]);          //print options
		}
	}
	scanf_s("%d", &option);                           //read user input for options
	//if user enters 1 then print game mods and ask user to select game mod.
	if (option == 1){
		position(58, 22);
		printf("(a) Player VS Computer\n");
		position(58, 24);
		printf("(b) Player VS Player\n");
		
		char select;
		position(73,38);
		printf(" ");
		position(73,38);
		scanf_s(" %c", &select);                         //read user input for game mod
		getchar();

		if(select=='a' || select=='A')
			return 4;                                    //if user enters 'A' then return 4 as user choice to main func.
		else if(select=='b' || select=='B')
			return 5;                                    //if user enters 'B' then return 5 as user choice to main func.
		else if (select == '2')
			return 2;									 //if user enters '2' then return 2 as user choice to main func.
		else if (select == '3')
			return 3;				                     //if user enters '3' then return 3 as user choice to main func.
		else
			return 0;                                    //if user enters invalid input, return 0 as user choice
	}
	else if (option == 2)
		return 2;				//return 2 as user choice
	else if (option == 3)
		return 3;				//return 3 as user choice
	else
		return 0;               //if user enters invalid input, return 0 as user choice
}

/*function definition welcome screen*/
void welcome(){
	SetConsoleTitle( TEXT( "Welcome To The Checkers" ) );
	system("CLS");
	system("color 3f");														//sperowLocfying color of the Welcome screen
	char coder[2][14] = {{"Developed By:"},{"7H3 c0d3rz"}};
	char names[6][20]=	{{"  \x11 Team Members \x10"},
						 {"-------------------"},
						 {"\x10  Mohammad Uzair \x11"},
						 {"\x10  Fatima Hassan  \x11"},
						 {"\x10 Muhammad Mubeen \x11"},
						 {"\x10   M. Asad Ali   \x11"}};
	char welcome[7][124]={{" ###       ###   ##########   ###        ########     ########      ###   ###    ##########       ###########    ######## "},
	                      {" ###       ###   ###          ###       ###    ###   ###    ###    ##### #####   ###                  ###       ###    ###"},
	                      {" ###       ###   ###          ###       ###          ###    ###   ### ##### ###  ###                  ###       ###    ###"} ,
	                      {" ###  ###  ###   ########     ###       ###          ###    ###   ###  ###  ###  ########             ###       ###    ###"},
	                      {" ### ##### ###   ###          ###       ###          ###    ###   ###       ###  ###                  ###       ###    ###"},
	                      {"  ##### #####    ###          ###       ###    ###   ###    ###   ###       ###  ###                  ###       ###    ###"},
	                      {"   ###   ###     ##########   ########## ########     ########    ###       ###  ##########           ###        ########"}};
	
	/* Start printing the welcome screen with animation */
	for(int row=0;row<7;row++){
		position(16,2+row);								
		for(int col=0;col<124;col++)
			printf("%c",welcome[row][col]);	
		_sleep(200);
	}
	/* End printing the welcome screen with animation */
	printf("\n\n\n");
	_sleep(300);

	printf("\t  /###           /   /                 \t\t         # ###      /                              /                                          \n");
	printf("\t /  ############/  #/                  \t\t       /  /###  / #/                             #/                                           \n");
	printf("\t/     #########    ##                  \t\t      /  /  ###/  ##                             ##                                           \n");
	printf("\t#     /  #         ##                  \t\t     /  ##   ##   ##                             ##                                           \n");
	printf("\t ##  /  ##         ##                  \t\t    /  ###        ##                             ##                                           \n");
	printf("\t    /  ###         ##  /##      /##    \t\t   ##   ##        ##  /##      /##       /###    ##  /##       /##    ###  /###       /###    \n");
	printf("\t   ##   ##         ## / ###    / ###   \t\t   ##   ##        ## / ###    / ###     / ###  / ## / ###     / ###    ###/ #### /   / #### / \n");
	printf("\t   ##   ##         ##/   ###  /   ###  \t\t   ##   ##        ##/   ###  /   ###   /   ###/  ##/   /     /   ###    ##   ###/   ##  ###/  \n");
	printf("\t   ##   ##         ##     ## ##    ### \t\t   ##   ##        ##     ## ##    ### ##         ##   /     ##    ###   ##         ####       \n");
	printf("\t   ##   ##         ##     ## ########  \t\t   ##   ##        ##     ## ########  ##         ##  /      ########    ##           ###      \n");
    printf("\t    ##  ##         ##     ## #######   \t\t    ##  ##        ##     ## #######   ##         ## ##      #######     ##             ###    \n");
	printf("\t     ## #      /   ##     ## ##        \t\t     ## #      /  ##     ## ##        ##         ######     ##          ##               ###  \n");
	printf("\t      ###     /    ##     ## ####    / \t\t      ###     /   ##     ## ####    / ###     /  ##  ###    ####    /   ##          /###  ##  \n");
	printf("\t       ######/     ##     ##  ######/  \t\t       ######/    ##     ##  ######/   ######/   ##   ### /  ######/    ###        / #### /   \n");
	printf("\t         ###       ##    ##    #####   \t\t         ###      ##    ##    #####     #####    ##    ##/    #####     ###           ###/    \n");
	/* Start printing the developers box */
    printf("\n\n\n\t\t\t\t\t\t\t");								
	for (int i=0; i<45; i++)
		printf("\xc2");
	puts("");

	for(int i=0;i<18;i++){
		printf("\t\t\t\t\t\t\t\xc3                                           \xb4\n");
		if (i==3){
			printf("\t\t\t\t\t\t\t\xc3");
			for (int j=0; j<43; j++)
				printf("\x16");
			puts("\xb4");
		}
	}
	printf("\t\t\t\t\t\t\t");
	for(int i=0; i<45;i++)
		printf("\x16");
	/* End printing the developers box */
	puts("");
	/* Start printing team name and team members names */
	for (int row=0; row<2; row++){
		position(64+15*row,31+row);
		for(int col=0; col<14 ; col++){
			printf("%c", coder[row][col]);
			_sleep(25);
		}
		printf("\n");
	}
	for(int row=0;row<6;row++){
		position(68,36+2*row);
		for(int col=0;col<20;col++){		
			printf("%c",names[row][col]);
			_sleep(20);
		}
	}
	/* End printing team name and team members names */
	_sleep(3000);
}

/*function definition for instructions*/
int instruction(){
	SetConsoleTitle( TEXT( "Instructions - The Checkers" ) );
	system("CLS");                             //clear the screen
	char instruct[13][107]={{"                                          Instructions"},
						 {"\x10 Movement \x11 Basic movement is to move a checker one space diagonally forward"},
						 {"You can not move a checker backwards until it becomes a King,"},
						 {"\x10 Jumping \x11 If one of your opponent's checkers is on a forward diagonal next to one of your checkers."},
						 {"and the next space beyond the opponent's checker is empty"},
						 {"then your checker must jump the opponent's checker and land in the space beyond."},
						 {"Your opponent's checker is captured and removed from the board. After making one jump,"},
						 {"your checker might have another jump available from its new position. Your checker must take that jump ."},
						 {"It must continue to jump until there are no more jumps available. Both men and kings are allowed"},
						 {"to make multiple jumps. "},
						 {"\x10 Crowning \x11 When one of your checkers reaches the opposite side of the board, it is crowned "},
						 {"and becomes a King. Your turn ends there. A King can move backward as well as forward along the diagonals."},
						 {"It can only move a distance of one space. "}};

	/* Start printing box for instructions */
	position(20,5);
	for(int i=0; i<113;i++)
		printf("\x16");
	puts("");
	for(int row=0;row<40;row++)
		printf("\t\t    \x19                                                                                                               \x19\n");
	position(20,45);
	for(int i=0; i<113;i++)
		printf("\x16");
	/* End printing box for instructions */

	//Start printing instructions with animation
	for(int row=0;row<13;row++){
		position(23,7+3*row);
		for(int col=0;col<107;col++){
			printf("%c",instruct[row][col]);
			_sleep(5);
		}
	}
	position(25,47);
	system("PAUSE");
	return 0;
}

//defining the toss function
int toss(){
	SetConsoleTitle( TEXT( "Toss - The Checkers" ) );
	system("CLS");                                       //clear screen
	int toss,result;
	puts("\n\n\n\n");
	printf("\t\t\t\t\t\t  :::::::::::       ::::::::       ::::::::       :::::::: \n");
	printf("\t\t\t\t\t\t     :+:          :+:    :+:     :+:    :+:     :+:    :+: \n");
	printf("\t\t\t\t\t\t    +:+          +:+    +:+     +:+            +:+         \n");
	printf("\t\t\t\t\t\t   +#+          +#+    +:+     +#++:++#++     +#++:++#++   \n");
	printf("\t\t\t\t\t\t  +#+          +#+    +#+            +#+            +#+    \n");
	printf("\t\t\t\t\t\t #+#          #+#    #+#     #+#    #+#     #+#    #+#     \n");
	printf("\t\t\t\t\t\t###           ########       ########       ########       ");

	srand(time(NULL));									//randomizing the toss
	toss = 1+rand()%2;
	/* Start printing box for toss */
	position(39,15);
	for(int i=0; i<72;i++){
		printf("\x16");
		for (int j=72;j<i;j++){
			position(39,16);
			printf("\x19 \t\t\t\t\t\t\t\t      \x19");
		}
	}
	puts("");
	for(int row=0;row<28;row++)
		printf("\t\t\t\t       \x19\t\t                                                      \x19\n"); 
	position(39,43);
	for(int i=0; i<72;i++)
		printf("\x16");
	/* End printing box for toss */

	if (toss == 1){		
		position(57,17);		printf("___  _    ____ _   _ ____ ____    .\n");
		position(57,18);		printf("|__] |    |__|  \\_/  |___ |__/   /| \n");
		position(57,19);		printf("|    |___ |  |   |   |___ |  \\   _|_\n");                    
		position(63,23);		printf("\x10 Head \x11  or  \x10 Tail \x11");
		result = tossSelect();                         //call tossSelect function as player1
		
		if(result==1)
			return 1;
		else if(result==2)
			return 2;
	}
	else if (toss == 2){
		position(56,17);		printf("___  _    ____ _   _ ____ ____    ___\n");
		position(56,18);		printf("|__] |    |__|  \\_/  |___ |__/   '___\\\n");
		position(56,19);		printf("|    |___ |  |   |   |___ |  \\   |____\n");		
		position(63,23);		printf("\x10 Head \x11  or  \x10 Tail \x11");
		result = tossSelect();                         //call tossSelect function as player2
		
		//if player 2 calls the function then, result will be reversed to know the correct result
		if(result==1)                                 
			return 2;
		if(result==2)
			return 1;
	}
}

int tossSelect(){
    int result;
	char select[5];
	position(72,25);
	fgets(select,5,stdin);

	if(strcmp(select, "head") == 0 ||strcmp(select, "Head") == 0 || strcmp(select, "HEAD") == 0 ){
		result = tossResult('H');							      //store tossResult in result
		return result;
	}
		
	else if(strcmp(select, "tail") == 0 ||strcmp(select, "Tail") == 0 || strcmp(select, "TAIL") == 0){
		result =  tossResult('T');								  //store tossResult in result
		return result;
	}
	else {
		position(67,27);
		printf("[Invalid Input]");
		_sleep(500);
		system("CLS");
		toss();
	}
}	

int tossResult(char select){
	int posX = 57,random,print;
	random = 1 + rand()%2;
	
	if (random == 1) 
		print=20;
	else
		print=19;

	for (int i=1; i<20; i++){
		_sleep(100);
		position(posX,29);		printf("########    ###    #### ##       \t ");
		position(posX,30);		printf("   ##      ## ##    ##  ##       \t ");
		position(posX,31);		printf("   ##    ##     ##  ##  ##       \t ");
		position(posX,32);		printf("   ##    #########  ##  ##       \t ");
		position(posX,33);		printf("   ##    ##     ## #### ########\t ");
		
		if(print!=i){                            //if print=20 (random=2) then head is printed at the end.
			_sleep(100);
			position(posX,29);		printf("##     ## ########    ###    ########  ");
			position(posX,30);		printf("##     ## ##         ## ##   ##     ## ");
			position(posX,31);		printf("######### ######   ##     ## ##     ## ");
			position(posX,32);		printf("##     ## ##       ######### ##     ## ");
			position(posX,33);		printf("##     ## ######## ##     ## ########  "); 
		}
	}
    //winning condition
	if ((select == 'H' && random==1)||(select == 'T' && random==2)){    
		position(65,36);
		printf("You won the Toss");
		position(62,38);
		system("pause");
		getchar();
		return 1;                     
	}
	//losing condition
	else{
		position(65,36);
		printf("You loss the Toss");
		position(62,38);
		system("pause");
		getchar();
		return 2;
	}
}		

//function definition board
void board(){
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
	system("CLS");
	system("color 3f");                           //set text color to white and background color to sky blue
	countPiecesp1();                                     
	countPiecesp2();
	
	int posX = 8, posY = 2, col = 0, row=0;		
	/* start printing black and white board */
 	for (row = 0; row<8; row++){
		for (col = 0; col<4; col++){		
				if(row%2==0){
					for(int i=0;i<7;i++){	
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
						position(posX+(col*22), (posY+i)+(row*7));
						printf("           ");
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );   //to stop color											
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x00);
						position(posX+(col*22)+11, (posY+i)+(row*7));
						printf("           ");
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );   //to stop color
					}
					
				}
				else if(row%2==1){
					for(int i=0;i<7;i++){	
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x00);
						position(posX+(col*22), (posY+i)+(row*7));
						printf("           ");
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );   //to stop color
					
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
						position(posX+(col*22)+11, (posY+i)+(row*7));
						printf("           ");
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );   //to stop color
					}
					
				}
		}
	} /* End printing black and white board */
	
	posX =7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
		for(int i=0;i<85;i+=11){
			position(posX+i, 0);						
			printf("      %d       ",(i/11)+1);                                   //print column numbers above the board
		}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
	moveBox();											
}

//function definition move Box
void moveBox(){	
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);
	/* Start printing box for saving moves */	
	for(int x=0;x<=2;x++){
		for (int y = 10; y<=57; y++){
			position(105,y);
			printf("                        \xb3                        ");
		}
	}
	for (int x = 105; x<=153; x++){
		position(x, 13);
		printf("\x16");
		position(x, 57);
		printf("\x16");
	}
	/* End printing box for saving moves */
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
	position(111,11);
	printf("Player 1 moves");
	if(choice==5){                               //for player vs player mod
		position(135,11);
		printf("Player 2 moves");
	}
	if(choice==4){                              //for player vs computer mod
		position(134,11);
		printf("Computer's moves");
	}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
}

//function definition move store
void moveStore(int turn, char row, int col,char newRow, int newCol ){	
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
		static int posMove1 = 15;                           //set y co-ordinate of first stored move of player 1
		static int posMove2 = 15;                           //set y co-ordinate of first stored move of player 2
		if(turn==1){
			position(115,posMove1);
			posMove1++;
			printf("%c%d %c%d", row, col, newRow, newCol);           //print moves of player 1
		}
		else if(turn==2){
			position(139,posMove2);
			posMove2++;
			printf("%c%d %c%d", row, col, newRow, newCol);           //print moves of player 2
		}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
}

//function definition pieces
void pieces(){
	
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &info );		
	
	int posX = 24, posY = 5, col = 0, row=0;		//starting positions of pieces on the board
	for (row = 0; row<8; row++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
		position(6, posY);						
		printf("%c",row+65);                    //print row names
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
		
		for (col = 0; col<8; col++){		
			posX = posX + ((col - 1)*11);
			if (boxes[row][col] == 1){			                          //start printing red pieces(player1) from here
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				position(posX-4, posY-2);
				printf("   ===");
				position(posX-4, posY-1);
				printf(" //   \\\\");
				position(posX-4, posY);
				printf("||  R  ||");
				position(posX-4, posY+1);
				printf(" \\\\   //");
				position(posX-4, posY+2);
				printf("   ===");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
			}
			else if (boxes[row][col] == 2){								//start printing white pieces(player2) from here
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				position(posX-4, posY-2);
				printf("   ===");
				position(posX-4, posY-1);
				printf(" //   \\\\");
				position(posX-4, posY);
				printf("||  W  ||");
				position(posX-4, posY+1);
				printf(" \\\\   //");
				position(posX-4, posY+2);
				printf("   ===");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
			}
			else if (boxes[row][col] == 3){							//start printing red-king pieces(player1) from here
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
				position(posX-4, posY-2);
				printf("   ===");
				position(posX-4, posY-1);
				printf(" //   \\\\");
				position(posX-4, posY);
				printf("|| R K ||");
				position(posX-4, posY+1);
				printf(" \\\\   //");
				position(posX-4, posY+2);
				printf("   ===");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );	
			}
			else if (boxes[row][col] == 4){							//start printing white-king pieces(player2) from here
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				position(posX-4, posY-2);
				printf("   ===");
				position(posX-4, posY-1);
				printf(" //   \\\\");
				position(posX-4, posY);
				printf("|| W K ||");
				position(posX-4, posY+1);
				printf(" \\\\   //");
				position(posX-4, posY+2);
				printf("   ===");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );
			}
			else if(boxes[row][col] == 0){							//start printing empty spaces from here
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				position(posX-4, posY-2);
				printf("         ");
				position(posX-4, posY-1);
				printf("         ");
				position(posX-4, posY);
				printf("         ");
				position(posX-4, posY+1);
				printf("         ");
				position(posX-4, posY+2);
				printf("         ");				
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), info.wAttributes );	
			}
			posX = 24;									//resetting the horizontal position to first column
		}
		posY += 7;										//increasing the vertical position
	}

}

//definition of player turn
void playerTurn(int player){
	SetConsoleTitle( TEXT( "The Checkers" ) );
	bool valid=0;										//flag value for move validity 
	int row, col, newRow, newCol;						//for storing the moves entered by player
	char oldRowChar,newRowChar;

	while(valid!=1){
		position(105, 6);
		if(player==1)	
			printf("Player1 Your Move [Row][Column] [newRow][newCol]:");
		if(player==2)	
			printf("Player2 Your Move [Row][Column] [newRow][newCol]:");
		if(player==3)	
			printf("Computer's   Move [Row][Column] [newRow][newCol]:");

		position(127, 8);
		printf("__ __        ");
		position(127, 8);
		
		if(player==1){
				bool Moves;
				Moves = noMoves(1);
				if(Moves==1){
					if(choice==4){
						win(3);
					}
					else if(choice==5){
						win(2);
						}
					}
			}
		else if(player==2){
				bool Moves;
				Moves = noMoves(2);
				if(Moves==1){
					win(1);
			}		
		}

		//starting the timer for 2 player game
		if(choice==5){
			bool time = timer(player);
			if(time==0){
				if(player==1)
					win(2);
				else if(player==2)
					win(1);
			}
		}
		
		//Taking input from player
		if(player==1 || player==2){
			
			scanf_s(" %c ", &oldRowChar);					
			scanf_s("%d ", &col);					
			scanf_s(" %c",&newRowChar);
			scanf_s("%d", &newCol);
		    getchar();								//to get the enter key
		
			row=convert(oldRowChar);				//converting char value of row to int
			newRow=convert(newRowChar);
			col--;									//to set values according to array
			newCol--;

			// checking the validity of moves
			if(!((newRowChar>=65 && newRowChar<=72) || (newRowChar>=97 && newRowChar<=104))){
				while ( getchar() != '\n' );		//flushing the input buffer 
				continue;
			}
			else if(!((oldRowChar>=65 && oldRowChar<=72) || (oldRowChar>=97 && oldRowChar<=104))){
				while ( getchar() != '\n' );		//flushing the input buffer
				continue;
			}
			else if(!((col>=0 && col<=8) && (newCol>=0 && newCol<=8))){
				while ( getchar() != '\n' );		//flushing the input buffer
				continue;
			}
		}

///////////////////////////////////
//---COMPUTER DECIDES THE MOVE---//
///////////////////////////////////
	else{
		int compPieces[12][3]={0};			//to store location of computer Pieces
		int rowLoc=0;
		bool search = 1;					//if search is 1 then search if 0 stop search

//storing the location of computer pieces
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(boxes[i][j]==2 || boxes[i][j]==4){
					compPieces[rowLoc][0]=i;					//row of piece stored in 0 index
					compPieces[rowLoc][1]=j;					//col of piece stored in 1 index
					if(boxes[i][j]==4){							//type of piece(simple or king) stored in 2 index
						compPieces[rowLoc][2]=1;				//1 for king and 0 if not a king piece
					}				
					rowLoc++;
				}
			}
		}

//computer looking for a double check
rowLoc=0;
while(!(compPieces[rowLoc][0]==0 && compPieces[rowLoc][1]==0) && rowLoc<12){		//searching the array elements
				
				/*KING moves*/
				if(compPieces[rowLoc][2]==1){
					//double check down right
					if((compPieces[rowLoc][0]+4<8 && compPieces[rowLoc][1]-4>=0) && boxes[compPieces[rowLoc][0]+4][compPieces[rowLoc][1]-4]==0 && boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-3]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+4;
						newCol=compPieces[rowLoc][1]-4;
						search=0;
						if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
							break;
						}
					}
					//double check down left
					else if((compPieces[rowLoc][0]+4<0 && compPieces[rowLoc][1]+4<8) && boxes[compPieces[rowLoc][0]+4][compPieces[rowLoc][1]+4]==0 && boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+3]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+4;
						newCol=compPieces[rowLoc][1]+4;
						search=0;
						if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
							break;
						}
					}
					//double check same column up
					if(compPieces[rowLoc][0]+4<8 && boxes[compPieces[rowLoc][0]+4][compPieces[rowLoc][1]]==0){
						//same column from right
						if(boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+1]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0]+4;
							newCol=compPieces[rowLoc][1];
							search=0;
							if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
								break;
							}
						}
						//same column from right
						if(boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-1]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0]+4;
							newCol=compPieces[rowLoc][1];
							search=0;
							if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
								break;
							}
						}
					}
					//double check same row
					if(boxes[compPieces[rowLoc][0]][compPieces[rowLoc][1]-4]==0){
						//double check left from down
						if(boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-3]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0];
							newCol=compPieces[rowLoc][1]-4;
							search=0;
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}
						}
						//double check left from up
						else if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-3]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0];
							newCol=compPieces[rowLoc][1]-4;
							search=0;
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}						}
					}
					else if(boxes[compPieces[rowLoc][0]][compPieces[rowLoc][1]+4]==0){
						//double check right from down
						if(boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+3]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0];
							newCol=compPieces[rowLoc][1]+4;
							search=0;
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}
						}
						//double check right from up
						else if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+3]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0];
							newCol=compPieces[rowLoc][1]+4;
							search=0;
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}
						}
					}
				}
				
				/*SIMPLE piece moves*/
				if(compPieces[rowLoc][2]==1 || compPieces[rowLoc][2]==0){	
					//double check up left
					if((compPieces[rowLoc][0]-4>=0 && compPieces[rowLoc][1]-4>=0) && boxes[compPieces[rowLoc][0]-4][compPieces[rowLoc][1]-4]==0 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-4;
						newCol=compPieces[rowLoc][1]-4;
						search=0;
						if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
							break;
						}
					}
					//double check up right
					else if((compPieces[rowLoc][0]-4>=0 && compPieces[rowLoc][1]+4<8) && boxes[compPieces[rowLoc][0]-4][compPieces[rowLoc][1]+4]==0 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+3]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-4;
						newCol=compPieces[rowLoc][1]+4;
						search=0;
						if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
							break;
						}
					}
					//double check same column up
					else if(compPieces[rowLoc][0]-4>=0 && boxes[compPieces[rowLoc][0]-4][compPieces[rowLoc][1]]==0){
						//same column from right
						if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==3) && (boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0]-4;
							newCol=compPieces[rowLoc][1];
							search=0;	
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}
						}
						//same column from right
						if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3) && (boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-1]==3)){
							row=compPieces[rowLoc][0];
							col=compPieces[rowLoc][1];
							newRow=compPieces[rowLoc][0]-4;
							newCol=compPieces[rowLoc][1];
							search=0;
							if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
								break;
							}
						}
				}	
			}
			rowLoc++;
	}

//computer looking for a single check
	rowLoc=0;
	if(search==1){
		
		while(!(compPieces[rowLoc][0]==0 && compPieces[rowLoc][1]==0) && rowLoc<12){
				/*KING moves*/
				if(compPieces[rowLoc][2]==1){
					//single check down left
					if((compPieces[rowLoc][0]+2<8 && compPieces[rowLoc][1]-2>=0) && boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+2;
						newCol=compPieces[rowLoc][1]-2;
						search=0;
						if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
							break;
						}
					}
					//single check down right
					else if((compPieces[rowLoc][0]+2<8 && compPieces[rowLoc][1]+2<8) && boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+2;
						newCol=compPieces[rowLoc][1]+2;
						search=0;
						if(!(((boxes[newRow+1][newCol-1]==1 || boxes[newRow+1][newCol-1]==3) && boxes[newRow-1][newCol+1]==0) || (boxes[newRow+1][newCol+1]==1 || boxes[newRow+1][newCol+1]==3) && boxes[newRow-1][newCol-1]==0)){
							break;
						}
					}	
				}
				/*SIMPLE piece moves*/
				if(compPieces[rowLoc][2]==1 || compPieces[rowLoc][2]==0){
					//single check up left
					if((compPieces[rowLoc][0]-2>=0 && compPieces[rowLoc][1]-2>=0) && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-2;
						newCol=compPieces[rowLoc][1]-2;
						search=0;
						if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
							break;
						}
					}
					//single check up right
					else if((compPieces[rowLoc][0]-2>=0 && compPieces[rowLoc][1]+2<8) && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==0 && (boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==3)){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-2;
						newCol=compPieces[rowLoc][1]+2;
						search=0;
						if(!(((boxes[newRow-1][newCol-1]==1 || boxes[newRow-1][newCol-1]==3) && boxes[newRow+1][newCol+1]==0) || (boxes[newRow-1][newCol+1]==1 || boxes[newRow-1][newCol+1]==3) && boxes[newRow+1][newCol-1]==0)){
							break;
						}
					}
				}		
		rowLoc++;
		}
}

//Computer tries to save the piece in danger
	//by using the piece in danger
	if(search==1){
		rowLoc=0;				
		while(!(compPieces[rowLoc][0]==0 && compPieces[rowLoc][1]==0)&&rowLoc<12){
			
			//simple piece
	
		if(compPieces[rowLoc][2]==1 || compPieces[rowLoc][2]==0){
				//moving to top row
				if(compPieces[rowLoc][0]==1 && compPieces[rowLoc][1]<7){
					if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3){
						row = compPieces[rowLoc][0];
						col = compPieces[rowLoc][1];
						newRow = compPieces[rowLoc][0]-1;
						newCol = compPieces[rowLoc][1]+1;
						search=0;
						break;
					}				
				}
				//moving up right
				if(compPieces[rowLoc][0]>=2 && compPieces[rowLoc][1]<=5){
					if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==3){
						if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==0){
							if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]!=1 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]!=3){
								if((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]!=1 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]!=3)||boxes[compPieces[rowLoc][0]][compPieces[rowLoc][1]+2]!=0){
									row = compPieces[rowLoc][0];
									col = compPieces[rowLoc][1];
									newRow = compPieces[rowLoc][0]-1;
									newCol = compPieces[rowLoc][1]+1;
									search=0;
									break;		
								}
							}
						}
					}
				}
				//moving up left
				if(compPieces[rowLoc][0]>=2 && compPieces[rowLoc][1]>=2){
					if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==3){
						if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==0){
							if(boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]!=1 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]!=3){
								if((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]!=1 && boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]!=3)||boxes[compPieces[rowLoc][0]][compPieces[rowLoc][1]-2]!=0){
									row = compPieces[rowLoc][0];
									col = compPieces[rowLoc][1];
									newRow = compPieces[rowLoc][0]-1;
									newCol = compPieces[rowLoc][1]-1;
									search=0;
									break;		
								}
							}
						}
					}
				}
			}
		rowLoc++;
	}

}
	
	//by using other piece
	if(search==1){
		rowLoc=0;				
		while(!(compPieces[rowLoc][0]==0 && compPieces[rowLoc][1]==0)&&rowLoc<12){
			//king piece
			if(compPieces[rowLoc][2]==1){
			//moving down right
				if(boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==0){
					if(compPieces[rowLoc][0]<=4 && compPieces[rowLoc][1]<=4){
						if(((boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==2 || boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]+2]==4) &&(boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]+3]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]+1;
							newCol = compPieces[rowLoc][1]+1;
							search=0;
							break;	
						}
					}
					if(compPieces[rowLoc][0]<=4 && compPieces[rowLoc][1]>=1){
						if(((boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]]==2 || boxes[compPieces[rowLoc][0]+2][compPieces[rowLoc][1]]==4) &&(boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]+3][compPieces[rowLoc][1]-1]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]+1;
							newCol = compPieces[rowLoc][1]+1;
							search=0;
							break;
						}
					}
					
				}
				//moving down left
				if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==0){
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]>=3){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]-1;
							search=0;
							break;	
						}
					}
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]<=6){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]-1;
							search=0;
							break;
						}
					}
					
				}


			}
			//simple piece
			if(compPieces[rowLoc][2]==1 || compPieces[rowLoc][2]==0){
			//moving top right
				if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==0){
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]<=4){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]+2]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+3]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+3]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]+1;
							search=0;
							break;	
						}
					}
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]>=1){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-1]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-1]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]+1;
							search=0;
							break;
						}
					}
					
				}
				//moving top left
				if(boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==0){
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]>=3){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]-2]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]-3]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]-1;
							search=0;
							break;	
						}
					}
					if(compPieces[rowLoc][0]>=3 && compPieces[rowLoc][1]<=6){
						if(((boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==2 || boxes[compPieces[rowLoc][0]-2][compPieces[rowLoc][1]]==4) &&(boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==1 || boxes[compPieces[rowLoc][0]-3][compPieces[rowLoc][1]+1]==3))){
							row = compPieces[rowLoc][0];
							col = compPieces[rowLoc][1];
							newRow = compPieces[rowLoc][0]-1;
							newCol = compPieces[rowLoc][1]-1;
							search=0;
							break;
						}
					}
					
				}

		
		}
		rowLoc++;
	}

}

//if no checking option computer make a simple move
if(search==1){
		rowLoc=0;				
		while(!(compPieces[rowLoc][0]==0 && compPieces[rowLoc][1]==0)&&rowLoc<12){
			/*KING moves*/
			if(compPieces[rowLoc][2]==1){
				//move down left	
				if(boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]-1]==0){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+1;
						newCol=compPieces[rowLoc][1]-1;
						search=0;
					
						if((boxes[newRow+1][newCol-1]!=3) && (boxes[newRow+1][newCol+1]!=3 || boxes[newRow-1][newCol-1]!=0 || boxes[newRow-1][newCol-1]!=1 || boxes[newRow-1][newCol-1]!=3) && !((boxes[row+1][col+1]==2||boxes[row+1][col+1]==4) && (boxes[row+2][col+2]==1 ||boxes[row+2][col+2]==3))){
							break;
						}
					}
				//move down right
				    if(boxes[compPieces[rowLoc][0]+1][compPieces[rowLoc][1]+1]==0 ){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]+1;
						newCol=compPieces[rowLoc][1]+1;
						search=0;
						
						if( (boxes[newRow+1][newCol+1]!=3) && (boxes[newRow+1][newCol-1]!=3 || boxes[newRow-1][newCol+1]!=0 || boxes[newRow-1][newCol+1]!=1 || boxes[newRow-1][newCol+1]!=3) && !((boxes[row+1][col-1]==2||boxes[row+1][col-1]==4) && (boxes[row+2][col-2]==1 ||boxes[row+2][col-2]==3))){
							break;
						}
					}	
				
			}
			/*SIMPLE piece moves*/
			if((compPieces[rowLoc][2]==1 || compPieces[rowLoc][2]==0 ) ){	
					//move up right
					if(compPieces[rowLoc][0]-1>=0 && compPieces[rowLoc][1]-1<=8 && boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]+1]==0){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-1;
						newCol=compPieces[rowLoc][1]+1;
						search=0;
						if( (((boxes[newRow-1][newCol+1]!=1 && boxes[newRow-1][newCol+1]!=3) && (boxes[newRow-1][newCol-1]!=1 && boxes[newRow-1][newCol-1]!=3 || boxes[newRow+1][newCol+1]!=0) && !((boxes[row-1][col-1]==2||boxes[row-1][col-1]==4) && (boxes[row-2][col-2]==1 ||boxes[row-2][col-2]==3))))){
							break;
						}
					}
					
				
					//move up left
					 if(compPieces[rowLoc][0]-1>=0 && compPieces[rowLoc][1]-1>=0  && boxes[compPieces[rowLoc][0]-1][compPieces[rowLoc][1]-1]==0 ){
						row=compPieces[rowLoc][0];
						col=compPieces[rowLoc][1];
						newRow=compPieces[rowLoc][0]-1;
						newCol=compPieces[rowLoc][1]-1;
						search=0;
						if( (boxes[newRow-1][newCol-1]!=1 && boxes[newRow-1][newCol-1]!=3) && (boxes[newRow-1][newCol+1]!=1 && boxes[newRow-1][newCol+1]!=3 || boxes[newRow+1][newCol-1]!=0) && !((boxes[row-1][col+1]==2||boxes[row-1][col+1]==4) && (boxes[row-2][col+2]==1 ||boxes[row-2][col+2]==3))){
							break;
						}
					}
						
			}
		rowLoc++;	
		}
	}
		oldRowChar=row+97;		//changing in character for storing moves
		newRowChar=newRow+97;

		if(search!=0)			//computer looses if no moves are available
			win(1);
	}
//-------------------------------------------------------------------------------------------------------------------------------------------
		int speed = 1500;			//slowing down the computer move
		if(player==1){
			//for player1 simple piece
			if(boxes[row][col]==1 && boxes[newRow][newCol]==0){					
					valid = moveDown(boxes[row][col],row,col,newRow,newCol);	//player1 call move down function
					if(valid==1){
						checkKing();						//checking for king
						pieces();							//refreshing the board
						if(countPiecesp2()==0){				//checking if player has won
							win(1);
						}
						else{
							moveStore(1,oldRowChar,col+1,newRowChar,newCol+1);	
							if(choice==5){
								playerTurn(2);					//calling opponent turn
							}
							else{
								_sleep(speed);
								playerTurn(3);					//calling computer turn turn
							}
						}	
					}
					else{
						continue;
					}
			}
			//for player 1 king piece
			else if(boxes[row][col]==3){
					//if moving down
					if(newRow>row){
							valid = moveDown(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for king
								pieces();							//refreshing the board
								if(countPiecesp2()==0){
									win(1);
								}
								else{
									moveStore(1,oldRowChar,col+1,newRowChar,newCol+1);
									if(choice==5){
									playerTurn(2);					//calling opponent turn
									}
									else{
									_sleep(speed);
									playerTurn(3);					//calling computer turn turn
									}	
								}	
							}
							else{
								continue;
							}
					}
					//if moving up
					else if(newRow<row){
							valid = moveUp(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for king
								pieces();							//refreshing the board
								if(countPiecesp2()==0){
									win(1);
								}
								else{
									moveStore(1,oldRowChar,col+1,newRowChar,newCol+1);
									if(choice==5){
									playerTurn(2);					//calling opponent turn
									}
									else{
									_sleep(speed);
									playerTurn(3);					//calling computer turn turn
									}
								}	
							}
							else{
								continue;
							}
					}
					else if(newRow==row){
							valid = backFor(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for queen
								pieces();							//refreshing the board
								if(countPiecesp2()==0){
									win(1);
								}
								else{
									moveStore(1,oldRowChar,col+1,newRowChar,newCol+1);
									if(choice==5){
									playerTurn(2);					//calling opponent turn
									}
									else{
									_sleep(speed);
									playerTurn(3);					//calling computer turn turn
									}
								}	
							}
							else{
								playerTurn(1);
							}
					}
			}
			else{
				playerTurn(1);
			}
	}
	if(player==2 || player==3){
			//for player2 simple piece
			if(boxes[row][col]==2 && boxes[newRow][newCol]==0){					
					valid = moveUp(boxes[row][col],row,col,newRow,newCol);	//player1 call move down function
					if(valid==1){
						checkKing();						//checking for king
						pieces();							//refreshing the board
						if(countPiecesp1()==0){				//checking if player has won
							if (player==2)
								win(2);
							else
								win(3);
						}
						else{
							if(player==3){
							position(126,8);
							printf(" %c%d %c%d",oldRowChar,col+1,newRowChar,newCol+1);
							_sleep(speed);
							}
							moveStore(2,oldRowChar,col+1,newRowChar,newCol+1);	
							playerTurn(1);					//calling opponent turn
						}	
					}
					else{
						continue;
					}
			}
			//for player 2 king piece
			else if(boxes[row][col]==4){
					////if moving sideways
						if(newRow==row){
							valid = backFor(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for queen
								pieces();							//refreshing the board
								if(countPiecesp1()==0){
									if (player==2)
										win(2);
									else
										win(3);
								}
								else{
									if(player==3){
									position(126,8);
									printf(" %c%d %c%d",oldRowChar,col+1,newRowChar,newCol+1);
									_sleep(speed);
									}
									moveStore(2,oldRowChar,col+1,newRowChar,newCol+1);
									playerTurn(1);					//calling opponent turn
								}	
							}
							else{
								playerTurn(2);
							}
					}

					//if moving down
					if(newRow>row){
							valid = moveDown(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for king
								pieces();							//refreshing the board
								if(countPiecesp1()==0){
									if (player==2)
										win(2);
									else
										win(3);
								}
								else{
									if(player==3){
									position(126,8);
									printf(" %c%d %c%d",oldRowChar,col+1,newRowChar,newCol+1);
									_sleep(speed);
									}
									moveStore(2,oldRowChar,col+1,newRowChar,newCol+1);
									playerTurn(1);					//calling opponent turn
								}	
							}
							else{
								continue;
							}
					}
					//if moving up
					else if(newRow<row){
							valid = moveUp(boxes[row][col],row,col,newRow,newCol);
							if(valid==1){
								checkKing();						//checking for king
								pieces();							//refreshing the board
								if(countPiecesp1()==0){
									if (player==2)
										win(2);
									else
										win(3);
								}
								else{
									if(player==3){
									position(126,8);
									printf(" %c%d %c%d",oldRowChar,col+1,newRowChar,newCol+1);
									_sleep(speed);
									}
									moveStore(2,oldRowChar,col+1,newRowChar,newCol+1);
									playerTurn(1);					//calling opponent turn
								}	
							}
							else{
								continue;
							}
						}
					}
			
			else{
				playerTurn(2);
			}
}}}
//defining the move down function
bool moveDown(int type,int row,int col,int newRow,int newCol){
	/*checking for a valid move*/
		
	//false move if new place is not empty
	if(boxes[newRow][newCol]!=0){
		return 0;
	}

	//false move if player piece is not placed at input position 
	else if(boxes[row][col]==-1 || boxes[row][col]==0 ){					
		return 0;
	}

	//valid move if new place is in diagnol 
	else if ((newRow == row + 1) && (newCol == col - 1 || newCol == col + 1)){	
		boxes[newRow][newCol] = boxes[row][col];
		boxes[row][col] = 0;
		return 1;
	}

	//checker by player if checks opponent piece in diagnol
	else if ((newRow == row + 2) && (newCol == col - 2 || newCol == col + 2)){
			if ((boxes[newRow - 1][newCol - 1] == type-1 || boxes[newRow - 1][newCol - 1] == type-3 || boxes[newRow - 1][newCol - 1] == type+1 || boxes[newRow - 1][newCol - 1] == type+3) && (boxes[newRow - 1][newCol - 1] !=0) && newCol>col){
				boxes[newRow - 1][newCol - 1] = 0;
				boxes[newRow][newCol] = boxes[row][col];
				boxes[row][col] = 0;
				return 1;
			}
			else if ((boxes[newRow - 1][newCol + 1] == type-1 || boxes[newRow - 1][newCol + 1] == type-3 || boxes[newRow - 1][newCol + 1] == type+1 || boxes[newRow - 1][newCol + 1] == type+3) && (boxes[newRow - 1][newCol + 1] !=0) && newCol<col){
				boxes[newRow - 1][newCol + 1] = 0;
				boxes[newRow][newCol] = boxes[row][col];
				boxes[row][col] = 0;
				return 1;
			}
	}

	//double checker by player
	else if((newRow == row + 4) && (newCol == col - 4 || newCol == col + 4 || newCol==col)){	
			if(newCol == col + 4){
					if(((boxes[row+1][col+1]==type-1 || boxes[row+1][col+1]==type+1 ||  boxes[row+1][col+1]==type+3 || boxes[row+1][col+1]==type-3) && boxes[row+1][col+1]!=0) && boxes[row+2][col+2]==0 && ((boxes[row+3][col+3]==type-1 || boxes[row+3][col+3]==type+1 || boxes[row+3][col+3]==type+3 ||  boxes[row+3][col+3]==type-3) && boxes[row+3][col+3]!=0)){
						boxes[row+1][col+1]   = 0;
						boxes[row+3][col+3]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else if(newCol == col - 4){
					if(((boxes[row+1][col-1]==type-1 || boxes[row+1][col-1]==type+1 || boxes[row+1][col-1]==type-3 || boxes[row+1][col-1]==type+3)&&boxes[row+1][col-1]!=0) && boxes[row+2][col-2]==0 && ((boxes[row+3][col-3]==type-1 || boxes[row+3][col-3]==type+1 || boxes[row+3][col-3]==type-3 || boxes[row+3][col-3]==type+3)&&boxes[row+3][col-3]!=0)){
						boxes[row+1][col-1]   = 0;
						boxes[row+3][col-3]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else if(newCol == col){
					if(boxes[row+1][col+1]!=0 && (boxes[row+1][col+1]==type-1 || boxes[row+1][col+1]==type-3 || boxes[row+1][col+1]==type+3 || boxes[row+1][col+1]==type+1) && ((boxes[row+3][col+1]==type-1 || boxes[row+3][col+1]==type-3 ||  boxes[row+3][col+1]==type+3 || boxes[row+3][col+1]==type+1)&&boxes[row+3][col+1]!=0) && boxes[row+2][col+2]==0){
						boxes[row+1][col+1]   = 0;
						boxes[row+3][col+1]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else if(boxes[row+1][col-1]!=0 && (boxes[row+1][col-1]==type-1 || boxes[row+1][col-1]==type+3 || boxes[row+1][col-1]==type-3 || boxes[row+1][col-1]==type+1)  && (boxes[row+3][col-1]!=0 && (boxes[row+3][col-1]==type-1 || boxes[row+3][col-1]==type+3 || boxes[row+3][col-1]==type-3 || boxes[row+3][col-1]==type+1) && boxes[row+2][col-2]==0)){
						boxes[row+1][col-1]   = 0;
						boxes[row+3][col-1]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else{
				return 0;
			}
	}
	else{
		return 0;
	}
}

//defining the move up function
bool moveUp(int type, int row,int col,int newRow,int newCol){
	/*checking for a valid move*/
		
	//false move if new place is not empty
	if(boxes[newRow][newCol]!=0){
		return 0;
	}

	//false move if player piece is not placed at input position
	else if(boxes[row][col]==-1 || boxes[row][col]==0 ){					
		return 0;
	}

	//valid move if new place is in diagnol 
	else if ((newRow == row - 1) && (newCol == col - 1 || newCol == col + 1)){
		boxes[newRow][newCol] = boxes[row][col];
		boxes[row][col] = 0;
		return 1;
	}

	//checker by player if checks opponent piece in diagnol
	else if ((newRow == row - 2) && (newCol == col - 2 || newCol == col + 2)){
			if (boxes[newRow + 1][newCol - 1] !=0 && (boxes[newRow + 1][newCol - 1] == type-1 || boxes[newRow + 1][newCol - 1] == type-3 || boxes[newRow + 1][newCol - 1] == type+1) && newCol>col){
				boxes[newRow + 1][newCol - 1] = 0;
				boxes[newRow][newCol] = boxes[row][col];
				boxes[row][col] = 0;
				return 1;
			}
			else if (boxes[newRow + 1][newCol + 1] !=0 &&(boxes[newRow + 1][newCol + 1] == type-1 || boxes[newRow + 1][newCol + 1] == type-3 || boxes[newRow + 1][newCol + 1] == type+1) && newCol<col){
				boxes[newRow + 1][newCol + 1] = 0;
				boxes[newRow][newCol] = boxes[+row][col];
				boxes[row][col] = 0;
				return 1;
			}
	}

	//double checker by player
	else if((newRow == row - 4) && (newCol == col - 4 || newCol == col + 4 || newCol==col)){
			if(newCol == col + 4){
					if(boxes[row-1][col+1]!=0 && (boxes[row-1][col+1]==type-1 || boxes[row-1][col+1]==type+1 || boxes[row-1][col+1]==type+3 || boxes[row-1][col+1]==type-3) && boxes[row-2][col+2]==0 && (boxes[row-3][col+3]==type-1 || boxes[row-3][col+3]==type-3 || boxes[row-3][col+3]==type+3 || boxes[row-3][col+3]==type+1)){
						boxes[row-1][col+1]   = 0;
						boxes[row-3][col+3]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else if(newCol == col - 4){
					if(boxes[row-1][col-1]!=0 && (boxes[row-1][col-1]==type-1 || boxes[row-1][col-1]==type+1 || boxes[row-1][col-1]==type+3 || boxes[row-1][col-1]==type-3) && boxes[row-2][col-2]==0 && (boxes[row-3][col-3]==type-1 || boxes[row-3][col-3]==type+3 || boxes[row-3][col-3]==type-3 || boxes[row-3][col-3]==type+1)){
						boxes[row-1][col-1]   = 0;
						boxes[row-3][col-3]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else if(newCol == col){
				if((boxes[row-1][col-1]!=0 && (boxes[row-1][col-1]==type-1 || boxes[row-1][col-1]==type-3 ||boxes[row-1][col-1]==type+3 || boxes[row-1][col-1]==type+1)) && boxes[row-2][col-2]==0 && (boxes[row-3][col-1]==type-1 || boxes[row-3][col-1]==type-3 || boxes[row-3][col-1]==type+3 || boxes[row-3][col-1]==type+1)){
						boxes[row-1][col-1]   = 0;
						boxes[row-3][col-1]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
				else if((boxes[row-1][col+1]!=0 && (boxes[row-1][col+1]==type-1 || boxes[row-1][col+1]==type-3 || boxes[row-1][col+1]==type+3 || boxes[row-1][col+1]==type+1)) && (boxes[row-3][col+1]!=0 && (boxes[row-3][col+1]==type-1 || boxes[row-3][col+1]==type+1 || boxes[row-3][col+1]==type-3 ||boxes[row-3][col+1]==type+3) && boxes[row-2][col+2]==0)){
						boxes[row-1][col+1]   = 0;
						boxes[row-3][col+1]   = 0;
						boxes[newRow][newCol] = boxes[row][col];
						boxes[row][col]		  = 0;
						return 1;
					}
					else{
						return 0;
					}
			}
			else{
				return 0;
			}
	}
	else{
		return 0;
	}
}

bool backFor(int type, int row,int col,int newRow,int newCol){
	//forward backword double check by king
	
	if(newCol == col - 4 || newCol == col + 4){
		if(newCol == col + 4){
				//right up
				if((row!= 0 && row!=1) && boxes[row-2][col+2]==0 && boxes[row-1][col+1]!=0 && (boxes[row-1][col+1]==type-1 || boxes[row-1][col+1]==type+1 || boxes[row-1][col+1]==type-3 || boxes[row-1][col+1]==type+3)  && (boxes[row-1][col+3]==type-1 || boxes[row-1][col+3]==type+1 || boxes[row-1][col+3]==type-3) && ( boxes[row-1][col+3]!= 0 )){
					boxes[row-1][col+1]=0;
					boxes[row-1][col+3]=0;
					boxes[newRow][newCol]=boxes[row][col];
					boxes[row][col]=0;
					return 1;
				}
				//right down
				else if((row!= 6 && row!=7) && boxes[row+2][col+2]==0 && boxes[row+1][col+1]!=0 && (boxes[row+1][col+1]==type-1 || boxes[row+1][col+1]==type+1 || boxes[row+1][col+1]==type-3 || boxes[row+1][col+1]==type+3)  && (boxes[row+1][col+3]==type-1 || boxes[row+1][col+3]==type+1 || boxes[row+1][col+3]==type-3) && (boxes[row+1][col+3]!=0)){
					boxes[row+1][col+1]=0;
					boxes[row+1][col+3]=0;
					boxes[newRow][newCol]=boxes[row][col];
					boxes[row][col]=0;
					return 1;
				}
				else{
					return 0;
				}
			}
		else if(newCol == col - 4){
				//left up
				if((row!= 0 && row!=1) && boxes[row-2][col-2]==0 && (boxes[row-1][col-1]!=0) && (boxes[row-1][col-1]==type-1 || boxes[row-1][col-1]==type+1 || boxes[row-1][col-1]==type-3 || boxes[row-1][col-1]==type+3)  && (boxes[row-1][col-3]==type-1 || boxes[row-1][col-3]==type+1 || boxes[row-1][col-3]==type-3) && (boxes[row-1][col-3]!=0)){
					boxes[row-1][col-1]=0;
					boxes[row-1][col-3]=0;
					boxes[newRow][newCol]=boxes[row][col];
					boxes[row][col]=0;
					return 1;
				}
				//left down
				else if((row!= 6 && row!=7) && boxes[row+2][col-2]==0 && (boxes[row+1][col-1]!=0) && (boxes[row+1][col-1]==type-1 || boxes[row+1][col-1]==type+1 || boxes[row+1][col-1]==type-3 || boxes[row+1][col-1]==type+3)  && (boxes[row+1][col-3]==type-1 || boxes[row+1][col-3]==type+1 || boxes[row+1][col-3]==type-3) && (boxes[row+1][col-3]!=0)){
					boxes[row+1][col-1]=0;
					boxes[row+1][col-3]=0;
					boxes[newRow][newCol]=boxes[row][col];
					boxes[row][col]=0;
					return 1;
				}
				else{
					return 0;
				}
			
			}
	}
	else
		return 0;
}
//function for checking new kings
void checkKing(){
	for(int i=0;i<8;i++){
		if(boxes[7][i]==1)           //red piece becomes king if it reaches to last row
			boxes[7][i]=3;
		if(boxes[0][i]==2)           //white piece becomes king if it reaches to first row
			boxes[0][i]=4;
	}
}
//function for counting pieces of player 1
int countPiecesp1(){
	int posX=105;
	int count=0;
	/* start counting pieces of player 1 */
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(boxes[i][j]==1 || boxes[i][j]==3)        
				count++;
		}	
	} /* End counting pieces of player 1 */
	position(posX,2);
	printf("------------------------");
	position(posX,3);
	printf("|  Red  Pieces =  %02d   |",count);
	position(posX,4);
	printf("------------------------");
	return count;
}
//function for counting pieces of player 2
int countPiecesp2(){
	int posX=130;
	int count=0;
	/* start counting pieces of player 2 */
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(boxes[i][j]==2 || boxes[i][j]==4)
				count++;
		}			
	} /* End counting pieces of player 1 */
	position(posX,2);
	printf(" -----------------------");
	position(posX,3);
	printf(" |  White Pieces =  %02d |",count);
	position(posX,4);
	printf(" -----------------------");
	return count;
}
//function to print result
void win(int result){
	/* Start Printing Win box */
	position(39,15);
	for(int i=0; i<72;i++){
		printf("\x16");
		for (int j=72;j<i;j++){
			position(39,16);
			printf("\x19 \t\t\t\t\t\t\t\t      \x19");
		}
	}
	puts("");
	for(int row=0;row<28;row++){
		position(39,16+row);
		printf("\x19\t\t                                                      \x19\n");
	}
	position(39,43);
	for(int i=0; i<72;i++)
		printf("\x16");
	/* End Printing Win box */
	if (result == 1){
		position(57,22);
		printf("___  _    ____ _   _ ____ ____    .\n");
		position(57,23);
		printf("|__] |    |__|  \\_/  |___ |__/   /| \n");
		position(57,24);
		printf("|    |___ |  |   |   |___ |  \\   _|_\n");
	}
	else if (result == 2){
		position(56,22);
		printf("___  _    ____ _   _ ____ ____    ___\n");
		position(56,23);
		printf("|__] |    |__|  \\_/  |___ |__/   '___\\\n");
		position(56,24);
		printf("|    |___ |  |   |   |___ |  \\   |____\n");	
	}
	else {
		position(56,22);
		printf("____ ____ _  _ ___  _  _ ___ ____ ____ ");
		position(56,23);
		printf("|    |  | |\\/| |__] |  |  |  |___ |__/ ");
		position(56,24);
		printf("|___ |__| |  | |    |__|  |  |___ |  \\ ");
	}
                                       
	position(57,30);	printf("##      ##  ####  ##    ##   ######  \n");
	position(57,31);	printf("##  ##  ##   ##   ###   ##  ##    ## \n");
	position(57,32);	printf("##  ##  ##   ##   ####  ##  ##       \n");
	position(57,33);	printf("##  ##  ##   ##   ## ## ##   ######  \n");
	position(57,34);	printf("##  ##  ##   ##   ##  ####        ## \n");
	position(57,35);	printf("##  ##  ##   ##   ##   ###  ##    ## \n");
	position(57,36);	printf("###/  \\###  ####  ##    ##   ###### \n"); 
	position(57,40);	exit(0);
}
//function to convert the row names into integers(row numbers) entered by user
int convert(char val){
	
	switch(val){
	case 'A':case 'a':
			return 0;
			break;
	case 'B':case 'b':
			return 1;
			break;
	case 'C':case 'c':
			return 2;
			break;
	case 'D':case 'd':
			return 3;
			break;
	case 'E':case 'e':
			return 4;
			break;
	case 'F':case 'f':
			return 5;
			break;
	case 'G':case 'g':
			return 6;
			break;
	case 'H':case 'h':
			return 7;
			break;
	}
}

bool timer(int player){
	
	static int p1TimeSec=59;
	static int p2TimeSec=59;
	static int p1TimeMin=14;
	static int p2TimeMin=14;
    
	static int first=1;
	if(first==1){                                       //condition for printing this only once
	position(105,13);
	printf("  Time left :: 15 : 00    ");
	position(130,13);
	printf("  Time left :: 15 : 00   ");
	first++;
	}
    while ( ! _kbhit()){			                   //Check for keyboard hit
        	_sleep(1000);
			//start time for player1
			if(player==1){                             
				if(p1TimeSec==0){
					p1TimeMin--;
					p1TimeSec=60;
				}

				position(105,13);
				printf("  Time left :: %02d : %02d   ",p1TimeMin,p1TimeSec--);            //print player1 time
				position(127, 8);
				if(p1TimeMin<=0 && p1TimeSec==0){
					return 0;                                            //return 0 if player1 time ends
				}
			}
			//start time for player2
			if(player==2){
				if(p2TimeSec==0){
					p2TimeMin--;
					p2TimeSec=60;
				}
				position(130,13);
				printf("  Time left :: %d : %d   ",p2TimeMin,p2TimeSec--);           //print player2 time
				position(127, 8);
				if(p2TimeMin<=0 && p2TimeSec==0){
					return 0;                                         //return 0 if player2 time ends
				}
			}
		}
	return 1;                                                        //return 1 if both players have remaining time
}

bool noMoves(int player){
	int rowLoc=0;
	
	//storing piece locations
	int pieces[12][3]={0};
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(boxes[i][j]==player || boxes[i][j]==player+2){
				pieces[rowLoc][0]=i;
				pieces[rowLoc][1]=j;
				if(boxes[i][j]==player+2){
					pieces[rowLoc][2]=1;
				}
			rowLoc++;
			}
		}
	}

if(player==1){

//double check availablity check
rowLoc=0;
while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){		//searching the array elements
	/*KING moves*/
	if(pieces[rowLoc][2]==1){
		//double check up left
		if((pieces[rowLoc][0]-4>=0 && pieces[rowLoc][1]-4>=0) && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]-4]==0 && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-3]==2 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-3]==4)){
			return 0;
		}
		//double check up right
		else if((pieces[rowLoc][0]-4>=0 && pieces[rowLoc][1]+4<8) && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]+4]==0 && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+3]==2 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+3]==4)){			
			return 0;
		}
	}
	//double check same column up
	if(pieces[rowLoc][0]-4>=0 && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]]==0){
		//same column from right
		if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+1]==4)){
			return 0;
		}
		//same column from left
		if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-1]==4)){
			return 0;					
		}
	}
	//double check same row
		//to left
		if(boxes[pieces[rowLoc][0]][pieces[rowLoc][1]-4]==0){
			//double check left from up
			if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-3]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-3]==4)){
				return 0;
			}
			//double check left from down
			if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-3]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-3]==4)){
					return 0;
			}
		}
		//to right
		if(boxes[pieces[rowLoc][0]][pieces[rowLoc][1]+4]==0){
			//double check right from up
			if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+3]==2 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+3]==4)){
				return 0;
			}
			//double check right from down
			if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+3]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+3]==4)){
					return 0;
			}
		}
		rowLoc++;
	}
	/*SIMPLE piece moves*/
	while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){		//searching the array elements
		if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){	
					//double check up left
					if((pieces[rowLoc][0]+4>=0 && pieces[rowLoc][1]-4>=0) && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]-4]==0 && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-3]==2 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-3]==4)){
						return 0;
					}
					//double check up right
					else if((pieces[rowLoc][0]+4>=0 && pieces[rowLoc][1]+4<8) && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]+4]==0 && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+3]==2 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+3]==4)){
						return 0;
					}
					//double check same column up
					else if(pieces[rowLoc][0]+4>=0 && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]]==0){
						//same column from right
						if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==4) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+1]==2 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+1]==4)){
							return 0;
						}
						//same column from right
						if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==4) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-1]==2 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-1]==4)){
							return 0;
						}
				}	
			}
			rowLoc++;
	}
//computer looking for a single check
	rowLoc=0;
		while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){
				/*KING MOVES*/
				if(pieces[rowLoc][2]==1){
					//single check up left
					if((pieces[rowLoc][0]-2>=0 && pieces[rowLoc][1]-2>=0) && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==3)){
						return 0;
					}
					//single check up right
					else if((pieces[rowLoc][0]-2>=0 && pieces[rowLoc][1]+2<8) && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==3)){
						return 0;
					}
					/*Simple moves*/
				if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){
					//single check down left
					if((pieces[rowLoc][0]+2<8 && pieces[rowLoc][1]-2>=0) && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==3)){
						return 0;
					}
					//single check down right
					else if((pieces[rowLoc][0]+2<8 && pieces[rowLoc][1]+2<8) && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==3)){
						return 0;
					}	
				}
				}		
		rowLoc++;
		}
		rowLoc=0;
		while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){
			/*King Moves*/
			if(pieces[rowLoc][2]==1){
				//moving up
				if(boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==0 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==0){
					return 0;
				}
			}
			/*simple piece moves*/
			if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){
				//moving down
				if(boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==0 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==0){
					return 0;
				}
			}
		rowLoc++;
		}
		return 1;
	}

if(player==2){

//double check availablity check
rowLoc=0;
while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){		//searching the array elements
	
	/*King moves*/
		if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){	
					//double check up left
					if((pieces[rowLoc][0]+4>=0 && pieces[rowLoc][1]-4>=0) && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]-4]==0 && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-3]==1 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-3]==3)){
						return 0;
					}
					//double check up right
					else if((pieces[rowLoc][0]+4>=0 && pieces[rowLoc][1]+4<8) && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]+4]==0 && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+3]==1 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+3]==3)){
						return 0;
					}
					//double check same column up
					else if(pieces[rowLoc][0]+4>=0 && boxes[pieces[rowLoc][0]+4][pieces[rowLoc][1]]==0){
						//same column from right
						if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]+1]==3)){
							return 0;
						}
						//same column from right
						if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+3][pieces[rowLoc][1]-1]==3)){
							return 0;
						}
				}	
			}
	/*KING moves*/
	if(pieces[rowLoc][2]==1){
		//double check up left
		if((pieces[rowLoc][0]-4>=0 && pieces[rowLoc][1]-4>=0) && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]-4]==0 && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-3]==1 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-3]==3)){
			return 0;
		}
		//double check up right
		else if((pieces[rowLoc][0]-4>=0 && pieces[rowLoc][1]+4<8) && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]+4]==0 && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+3]==1 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+3]==3)){			
			return 0;
		}
	}
	//double check same column up
	if(pieces[rowLoc][0]-4>=0 && boxes[pieces[rowLoc][0]-4][pieces[rowLoc][1]]==0){
		//same column from right
		if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]+1]==3)){
			return 0;
		}
		//same column from left
		if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-3][pieces[rowLoc][1]-1]==3)){
			return 0;					
		}
	}
	//double check same row
		//to left
		if(boxes[pieces[rowLoc][0]][pieces[rowLoc][1]-4]==0){
			//double check left from up
			if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-3]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-3]==3)){
				return 0;
			}
			//double check left from down
			if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==3) && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-3]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-3]==3)){
					return 0;
			}
		}
		//to right
		if(boxes[pieces[rowLoc][0]][pieces[rowLoc][1]+4]==0){
			//double check right from up
			if(boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+3]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+3]==3)){
				return 0;
			}
			//double check right from down
			if(boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==3) && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+3]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+3]==3)){
					return 0;
			}
		}
		rowLoc++;
	}
	

//computer looking for a single check
	rowLoc=0;
		while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){
				/*KING MOVES*/
				if(pieces[rowLoc][2]==1){
					//single check up left
					if((pieces[rowLoc][0]-2>=0 && pieces[rowLoc][1]-2>=0) && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==3)){
						return 0;
					}
					//single check up right
					else if((pieces[rowLoc][0]-2>=0 && pieces[rowLoc][1]+2<8) && boxes[pieces[rowLoc][0]-2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==3)){
						return 0;
					}
					/*Simple moves*/
				if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){
					//single check down left
					if((pieces[rowLoc][0]+2<8 && pieces[rowLoc][1]-2>=0) && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]-2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==3)){
						return 0;
					}
					//single check down right
					else if((pieces[rowLoc][0]+2<8 && pieces[rowLoc][1]+2<8) && boxes[pieces[rowLoc][0]+2][pieces[rowLoc][1]+2]==0 && (boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==1 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==3)){
						return 0;
					}	
				}
			}		
		rowLoc++;
		}
		rowLoc=0;
		while(!(pieces[rowLoc][0]==0 && pieces[rowLoc][1]==0) && rowLoc<12){
			/*King Moves*/
			if(pieces[rowLoc][2]==1 || pieces[rowLoc][2]==0){
				//moving up
				if(boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]+1]==0 || boxes[pieces[rowLoc][0]-1][pieces[rowLoc][1]-1]==0){
					return 0;
				}
			}
			/*simple piece moves*/
			if(pieces[rowLoc][2]==1){
				//moving down
				if(boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]+1]==0 || boxes[pieces[rowLoc][0]+1][pieces[rowLoc][1]-1]==0){
					return 0;
				}
			}
		rowLoc++;
		}
		return 1;
	}
}
