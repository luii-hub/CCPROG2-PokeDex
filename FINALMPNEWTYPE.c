/*********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and applying the concepts
learned. We have constructed the functions and their respective algorithms and corresponding code by ourselves. The
program was run, tested, and debugged by our own efforts. We further certify that We have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.

RANA, Luis Miguel, DLSU ID# 12179124
TORIO, Ysobella, DLSU ID# 12172030
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> 
#include <windows.h> 
#include <unistd.h> 
#include "PokeDex.h"

/* --- Main Function --- */
int main()
{
    system("cls");

    //Greet Trainer
    PokeBall();
    KeyContinue();
    printf("Accessing data...   "YELLOW"(3)"RESET"\n");
    sleep(1);
    system("cls");
    printf("Accessing data...   "YELLOW"(2)\n"RESET);
    sleep(1);
    system("cls");
    printf("Accessing data...   "YELLOW"(1)\n"RESET);
    sleep(1);
    system("cls");

    //System Variables and Initializations
    struct details entry[MAX];
    for(int i = 0; i < MAX; i++)
    {
        entry[i].defeated = 0;
        entry[i].defeated = 0;
    }
    char ResearchAddOns[5][21];
    int storedEntries = 0;
    int addOnCounter = 0;
    //User Input
    char cMainMenu; 

    /* Keep Pokedex running until User terminates the program (E) */
    do
    { /* Main Menu */
        printf(CYAN"\n------------------- MAIN MENU -------------------\n\n" RESET);
        printf(YELLOW "[M]" RESET "anage Data\n" YELLOW "[R]" RESET "esearch Tasks\n" YELLOW "[E]" RESET "xit PokeDex\n");
        printf(CYAN"\n-------------------------------------------------\n\n" RESET);
        printf("Console: ");
        scanf(" %c", &cMainMenu);
        cMainMenu = tolower(cMainMenu);

        while(cMainMenu != 'm' && cMainMenu != 'r' && cMainMenu != 'e')
        {
            printf(RED "\nInvalid input. Please try again.\n" RESET);
            printf("Console: ");
            scanf(" %c", &cMainMenu);
            cMainMenu = tolower(cMainMenu);
        }
        switch(cMainMenu)
        {
            /* Run Manage Data Menu */
            case 'm':
                manageData(entry, &storedEntries, &addOnCounter);
                break;
            /* Run Research Task Menu */
            case 'r':
                researchTasks(entry, &storedEntries, &addOnCounter, ResearchAddOns);
                break;
            /* Terminate Program */
            case 'e':
                system("cls");
                printf(CYAN"Closing the PokeDex in 3\n");
                sleep(1);
                system("cls");
                printf(YELLOW"Closing the PokeDex in 2\n");
                sleep(1);
                system("cls");
                printf(RED"Closing the PokeDex in 1\n"RESET);
                sleep(1);
                system("cls");
                return 0;
            break;
        }
    }while(cMainMenu != 'e');
    return 0;
}
