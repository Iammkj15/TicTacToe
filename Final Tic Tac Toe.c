//PF LAB PROJECT BY Muhammad Muzammil(22k4267) AND Heo Juseong(22k4576)

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Color Codes
#define COLOR_OFF   "\e[m"
#define COLOR_BLUE  "\e[1;34m"
#define COLOR_GREEN  "\e[1;32m"

int checkwin(char square[4][4]);
void board(char square[4][4], char name1[], char name2[]);
void score(int, int, char [], char[]);
int twoplayerMode(char square[4][4], char original[4][4]);
int singleplayerMode(char square[4][4], char original[4][4]);
int random(char square[4][4]);


int main(){
	char square[4][4] = { 
					  {'0', '0', '0', '0'},
                      {'0', '-', '-', '-'},
                      {'0', '-', '-', '-'},
                      {'0', '-', '-', '-'} };
    char original[4][4] = { 
					  {'0', '0', '0', '0'},
                      {'0', '-', '-', '-'},
                      {'0', '-', '-', '-'},
                      {'0', '-', '-', '-'} };
	int choice,option,check=0,check2=0;
	
	do{
	check=0;
	system("cls");
	system("color 0F");

	printf("\t\t\t\t\t ===================================\n");
	printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("    [Tic Tac Toe]    ");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");
    printf("\t\t\t\t\t ===================================\n");
	
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    Select Mode: ");
	printf("\n\n\t\t\t\t\t      1. Single Player Mode\n\t\t\t\t\t      2. Two Player Mode\n\t\t\t\t\t      (Enter '0' to EXIT the game.)\n\t\t\t\t\t    ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			singleplayerMode(square, original);
			break;
		
		case 2:
			twoplayerMode(square, original);
			break;
		
		case 0:
			break;
		
		default:
			printf("Invalid Entry, Try Again.\n");
			check=1;
		}	
		if (choice == 0){
			break;
		}
		
	}while(1);
}


int twoplayerMode(char square[4][4], char original[4][4]){
    int player = 1, i, choice, l1, l2, a, win1=0, win2=0, exit, j, k;
    char name1[100], name2[100], name[100];

    char mark;
    
    printf("\n");
    printf("\t\t\t\t\t Enter the name of first player: ");
    scanf("%s", name1);
    printf("\t\t\t\t\t Enter the name of second player: ");
    scanf("%s", name2);
    l1= strlen(name1);
    l2= strlen(name2);
    do {
    	
		do
	    {
	        board(square, name1, name2);
	        player = (player % 2) ? 1 : 2;
	        if(player == 1){
	        	for (a=0 ; a<l1 ; a++){
	        		name[a] = name1[a];
				}
			}
			else if ( player == 2){
				for (a=0 ; a<l2 ; a++){
	        		name[a] = name2[a];
				}
			}
			fflush(stdin);
	        printf("\t\t\t\t\t\t%s, Enter a position:  ", name);
	        scanf("%d", &choice);
	
	        mark = (player == 1) ? 'X' : 'O';
	
	        if (choice == 1 && square[1][1] == '-')
	            square[1][1] = mark;
	
	        else if (choice == 2 && square[1][2] == '-')
	            square[1][2] = mark;
	
	        else if (choice == 3 && square[1][3] == '-')
	            square[1][3] = mark;
	
	        else if (choice == 4 && square[2][1] == '-')
	            square[2][1] = mark;
	
	        else if (choice == 5 && square[2][2] == '-')
	            square[2][2] = mark;
	
	        else if (choice == 6 && square[2][3] == '-')
	            square[2][3] = mark;
	
	        else if (choice == 7 && square[3][1] == '-')
	            square[3][1] = mark;
	
	        else if (choice == 8 && square[3][2] == '-')
	            square[3][2] = mark;
	
	        else if (choice == 9 && square[3][3] == '-')
	            square[3][3] = mark;
	
	        else
	        {
	            printf("\n\t\t\t\t\t\t   Invalid move ");
	
	            player--;
	            getch();
	        }
	        i = checkwin(square);
	
	        player++;
	    }while (i ==  - 1);
	
	    board(square, name1, name2);
	
	    if (i == 1){
	    	printf(COLOR_GREEN "\t\t\t\t\t\t   \a%s win " COLOR_OFF, name1);
	    	win1++;
		}
	        
	    else if (i == 2){
	    	printf(COLOR_GREEN "\t\t\t\t\t\t   \a%s win " COLOR_OFF, name2);
	    	win2++;
		}
	    else 
	        printf(COLOR_BLUE "\t\t\t\t\t\t   \aGame draw" COLOR_OFF);
	
	
	    getch();
	    
		score(win1, win2, name1, name2);
		
		for (j = 0 ; j < 4 ; j ++){
    		for (k=0 ; k<4 ; k++){
    			square[j][k] = original[j][k];
			}
		}
		printf("\n\t\t\t\t  Enter '1' to CONTINUE or '0' to END the game: ");
		scanf("%d", &exit);
	} while (exit == 1);
	
    return 0;
}


int singleplayerMode(char square[4][4], char original[4][4]){
    int player = 1, i, choice, l, a, win1=0, win2=0, j, k, exit;
    char name[100], name1[100], name2[]="Computer";
    char mark;
    
    printf("\n");
	printf("\t\t\t\t\t  Enter the name of player: ");
    scanf("%s", name1);
    l= strlen(name1);
    do {

	    do
	    {
	        board(square, name1, name2);
	        player = (player % 2 == 1) ? 1 : 2;
	        if(player == 1){
					fflush(stdin);
					printf("\n\t\t\t\t\t\t Your turn: ");
			        scanf("%d", &choice);
			
			        mark = 'X';
			
			        if (choice == 1 && square[1][1] == '-')
			            square[1][1] = mark;
			
			        else if (choice == 2 && square[1][2] == '-')
			            square[1][2] = mark;
			
			        else if (choice == 3 && square[1][3] == '-')
			            square[1][3] = mark;
			
			        else if (choice == 4 && square[2][1] == '-')
			            square[2][1] = mark;
			
			        else if (choice == 5 && square[2][2] == '-')
			            square[2][2] = mark;
			
			        else if (choice == 6 && square[2][3] == '-')
			            square[2][3] = mark;
			
			        else if (choice == 7 && square[3][1] == '-')
			            square[3][1] = mark;
			
			        else if (choice == 8 && square[3][2] == '-')
			            square[3][2] = mark;
			
			        else if (choice == 9 && square[3][3] == '-')
			            square[3][3] = mark;
			
			        else
			        {
			            printf("\n\t\t\t\t\t\t   Invalid move ");
			            player--;
			            getch();
			        }
		    	
			}
			else if ( player == 2){
				choice = random(square);
				mark = 'O';
		
		        if (choice == 1 && square[1][1] == '-')
		            square[1][1] = mark;
		
		        else if (choice == 2 && square[1][2] == '-')
		            square[1][2] = mark;
		
		        else if (choice == 3 && square[1][3] == '-')
		            square[1][3] = mark;
		
		        else if (choice == 4 && square[2][1] == '-')
		            square[2][1] = mark;
		
		        else if (choice == 5 && square[2][2] == '-')
		            square[2][2] = mark;
		
		        else if (choice == 6 && square[2][3] == '-')
		            square[2][3] = mark;
		
		        else if (choice == 7 && square[3][1] == '-')
		            square[3][1] = mark;
		
		        else if (choice == 8 && square[3][2] == '-')
		            square[3][2] = mark;
		
		        else if (choice == 9 && square[3][3] == '-')
		            square[3][3] = mark;
			}
			
	        i = checkwin(square);
	        player++;
	        
	    }while (i ==  - 1);
	
	    board(square, name1, name2);
	
	    if (i == 1){
	    	printf(COLOR_GREEN "\t\t\t\t\t\t   \a%s wins " COLOR_OFF, name1);
	    	win1++;
		}
	        
	    else if (i == 2){
	    	printf(COLOR_GREEN "\t\t\t\t\t\t   \a%s wins " COLOR_OFF, name2);
	    	win2++;
		}
	    else 
	        printf(COLOR_BLUE "\t\t\t\t\t\t    \aGame drawed" COLOR_OFF);
	
	
	    getch();
	    
		score(win1, win2, name1, name2);
		
		for (j = 0 ; j < 4 ; j ++){
	    		for (k=0 ; k<4 ; k++){
	    			square[j][k] = original[j][k];
				}
			}
			printf("\n\t\t\t\t\tEnter '1' to CONTINUE or '0' to END the game: ");
			scanf("%d", &exit);
		
	} while (exit == 1);
    return 0;
}


int checkwin(char square[4][4]){
    if (square[1][1] == square[1][2] && square[1][2] == square[1][3] && (square[1][1] == 'X'))
        return 1;

    else if (square[2][1] == square[2][2] && square[2][2] == square [2][3] && (square[2][1] == 'X'))
        return 1;

    else if (square[3][1] == square[3][2] && square[3][2] == square[3][3] && (square[3][1] == 'X'))
        return 1;

    else if (square[1][1] == square[2][1] && square[2][1] == square[3][1] && (square[1][1] == 'X'))
        return 1;

    else if (square[1][2] == square[2][2] && square[2][2] == square[3][2] && (square[1][2] == 'X'))
        return 1;

    else if (square[1][3] == square[2][3] && square[2][3] == square[3][3] && (square[1][3] == 'X'))
        return 1;

    else if (square[1][1] == square[2][2] && square[2][2] == square[3][3] && (square[1][1] == 'X'))
        return 1;

    else if (square[1][3] == square[2][2] && square[1][3] == square[3][1] && (square[1][3] == 'X'))
        return 1;
    
	else if (square[1][1] == square[1][2] && square[1][2] == square[1][3] && (square[1][1] == 'O'))
        return 2;

    else if (square[2][1] == square[2][2] && square[2][2] == square[2][3] && (square[2][1] == 'O'))
        return 2;

    else if (square[3][1] == square[3][2] && square[3][2] == square[3][3] && (square[3][1] == 'O'))
        return 2;

    else if (square[1][1] == square[2][1] && square[2][1] == square[3][1] && (square[1][1] == 'O'))
        return 2;

    else if (square[1][2] == square[2][2] && square[2][2] == square[3][2] && (square[1][2] == 'O'))
        return 2;

    else if (square[1][3] == square[2][3] && square[2][3] == square[3][3] && (square[1][3] == 'O'))
        return 2;

    else if (square[1][1] == square[2][2] && square[2][2] == square[3][3] && (square[1][1] == 'O'))
        return 2;

    else if (square[1][3] == square[2][2] && square[1][3] == square[3][1] && (square[1][3] == 'O'))
        return 2;

    else if (square[1][1] != '-' && square[1][2] != '-' && square[1][3] != '-' &&
        square[2][1] != '-' && square[2][2] != '-' && square[2][3] != '-' && square[3][1]
        != '-' && square[3][2] != '-' && square[3][3] != '-')

        return 0;
    else
        return  - 1;
}


void board(char square[4][4], char name1[100], char name2[]){

	system("cls");
	system("color F0");
    printf("\n\n   \n");
    printf("\t\t\t\t\t\t      Tic Tac Toe");
    printf("\n   \n\n");

    printf("\t\t\t\t\t      %s (X)  -  %s (O)\n\n", name1,  name2);
    printf("\n");
    printf("\t\t\t\t\t\t _______________________ \n");
    printf("\t\t\t\t\t\t|1      |2      |3      |\n");
    printf("\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", square[1][1], square[1][2], square[1][3]);

    printf("\t\t\t\t\t\t|_______|_______|_______|\n");
    printf("\t\t\t\t\t\t|4      |5      |6      |\n");

    printf("\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", square[2][1], square[2][2], square[2][3]);

    printf("\t\t\t\t\t\t|_______|_______|_______|\n");
    printf("\t\t\t\t\t\t|7      |8      |9      |\n");

    printf("\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", square[3][1], square[3][2], square[3][3]);

    printf("\t\t\t\t\t\t|_______|_______|_______|\n");
    
    printf("  \n\n");
}


void score(int win1, int win2, char name1[100], char name2[100]){

	system("cls");
	system("color F4");
	printf("\n\n   \n");
	printf("\t\t\t\t\t ====================================\n");
	printf("\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("    [Score Board]    ");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");
    printf("\t\t\t\t\t ====================================\n");
    printf("\t\t\t\t\t       %-12s        %-12s               \n", name1, name2);
	printf("\t\t\t\t\t ____________________________________\n");
	printf("\t\t\t\t\t|                  |                 |\n");
    printf("\t\t\t\t\t|         %d        |        %d        |\n", win1, win2);
    printf("\t\t\t\t\t|__________________|_________________|\n");
    printf("\t\t\t\t\t ====================================\n");
    printf("  \n\n");
}


int random(char square[4][4]){
    int lower = 1, upper = 9;
    srand(time(0));
    int choice;
    while(1) {
    	choice = (rand() % (upper - lower + 1)) + lower;
    	if (choice == 1 && square[1][1] == '-')
	        return choice;
	
	    else if (choice == 2 && square[1][2] == '-')
	        return choice;
	
	    else if (choice == 3 && square[1][3] == '-')
	        return choice;
	
	    else if (choice == 4 && square[2][1] == '-')
	        return choice;
	
	    else if (choice == 5 && square[2][2] == '-')
	        return choice;
	
	    else if (choice == 6 && square[2][3] == '-')
	        return choice;
	
	    else if (choice == 7 && square[3][1] == '-')
	        return choice;
	
	    else if (choice == 8 && square[3][2] == '-')
	        return choice;
	
	    else if (choice == 9 && square[3][3] == '-')
	        return choice;
	}
    
}
