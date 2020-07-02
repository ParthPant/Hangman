#include <stdio.h> //Header file declaration
#include <ctype.h>
#include <string.h> //<string.h> for strcmp();,strlen(); functions use*
#include <stdlib.h>

#ifdef __linux__
#define CLEAR_SCREEN system("clear")
#endif

#ifdef _WIN32
#define CLEAR_SCREEN system("cls")
#endif

void showHangman(int); //function prototype

void clear (void) //function to clear the input stream
{    
  while ( getchar() != '\n' );
}

int main(void)
{
    char hangmanWord[100], tempWord[100];
    char hangmanOutput[100];
    int wrongTry = 6, matchFound = 0;
    int counter = 0, position = 0, winner, length, i;
    char alphabetFromUser;

    CLEAR_SCREEN;
    printf("\n\n Enter any word in small case and hit >>ENTER<<");
    printf("\n\n\t Enter HERE ==>  ");
    scanf("%s", hangmanWord);

    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
    printf("\n\n\tHIT >>ENTER<<");
    length = strlen(hangmanWord);
    clear();
    getchar();
    
    CLEAR_SCREEN;

    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");
    printf("\n\n\tHIT >>ENTER<< ");

    getchar();

    CLEAR_SCREEN;

    printf("\n\t||===== ");
    printf("\n\t||    | ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n", length);
    for (i = 0; i < length; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for (i = 0; i < length; i++)
    {
        printf(" ");
        printf("%c", hangmanOutput[i]);
    }
    while (wrongTry != 0)
    {
        matchFound = 0;
        printf("\n\n   enter your guesses!!");
        printf("\n\n\t Enter HERE ==> ");
        scanf("%c", &alphabetFromUser);
        if (!isalnum(alphabetFromUser))
        {
            CLEAR_SCREEN;
            printf("\n\n\t Wrong input TRY AGAIN ");
            matchFound = 2;
        }
        if (matchFound != 2)
        {
            for (counter = 0; counter < length; counter++)
            {
                if (alphabetFromUser == hangmanWord[counter])
                {
                    matchFound = 1;
                } //end of if()
            }     //end of for()

            if (matchFound == 0)
            {
                printf("\n\t :( You have %d tries left ", --wrongTry);
                showHangman(wrongTry);
                getchar();
            } //end of if()

            else
            {
                for (counter = 0; counter < length; counter++)
                {
                    matchFound = 0;
                    if (alphabetFromUser == hangmanWord[counter])
                    {
                        position = counter;
                        matchFound = 1;
                    } //end of if
                    if (matchFound == 1)
                    {
                        CLEAR_SCREEN;
                        for (i = 0; i < length; i++)
                        {
                            if (i == position)
                            {
                                hangmanOutput[i] = alphabetFromUser;
                            }
                            else if (hangmanOutput[i] != '_')
                            {
                                continue;
                            }
                            else
                            {
                                hangmanOutput[i] = '_';
                            }
                        }
                        tempWord[position] = alphabetFromUser;
                        tempWord[length] = '\0';
                        winner = strcmp(tempWord, hangmanWord);

                        if (winner == 0)
                        {
                            CLEAR_SCREEN;
                            printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                            printf("\n\n\t The Word was %s ", hangmanWord);
                            printf("\n\n\n\n\t\tEASY HUH???\n\n");
                            getchar();
                            return 0;
                        }
                    }
                }
            }
        }

        printf("\n\n\t");
        showHangman(wrongTry);
        for (i = 0; i < length; i++)
        {
            printf(" ");
            printf("%c", hangmanOutput[i]);
        }

        getchar();
    }

    if (wrongTry <= 0)
    {
        printf("\n\n\t The Word was %s ", hangmanWord);
        printf("\n\n\t The man is dead you LOOSER!!!!!");
        printf("\n\n\t Better luck next!!!");
    }
    getchar();
    return 0;
}

void showHangman(int choice) 
{

    switch (choice)
    {

    case 0:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||   / %c", '\\');
        printf("\n\t||      ");
        break;
    case 1:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||     %c", '\\');
        printf("\n\t||      ");
        break;
    case 2:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 3:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 4:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO ", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 5:
        CLEAR_SCREEN;
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||    O ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    }
    return;
}