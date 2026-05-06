#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getUserChoice();
int getComputerChoice();
int decideWinner(int,int);
int printResult(int);

int main()
{
    srand(time(0));

    int choice;
    while(1)
    {
        int count = 0; 
        while(count != 5)
        {
            int userchoice = getUserChoice();
            int compchoice = getComputerChoice();
            int winner = decideWinner(userchoice,compchoice);
            count = count + printResult(winner);
            
        }
        

        printf("\n\nPlay Again[1.Yes|2.No]:");
        scanf("%d",&choice);
        if(choice == 1)
        {
            continue;
        }
        else{
            break;
        }
    }
}

int getUserChoice()
{
/*Print menu
Take input
Validate (1–3)
Return choice*/

    int user;
    while(1)
    {
        printf("\n\n1.Rock\n2.Paper\n3.Scissor");
        printf("\nEnter choice:");
        scanf("%d",&user);
        printf("\n");
        if(user < 1 || user > 3)
        {
            printf("Invalid choice!\n");
            continue;
        }
        else
            break;
    }

    return user;
}

int getComputerChoice()
{
/*Generate random number (1–3)
Return it */
    
    int computer;
    computer = rand() % 3 + 1;
    return computer;
}

int decideWinner(int user, int computer)
{
/*Return:
0 → Draw
1 → User wins
-1 → Computer wins */

    if(user == computer)
    {
        return 0;
    }
    else if(user == 1 && computer == 2)
    {
        return -1;
    }
    else if(user == 1 && computer == 3)
    {  
        return 1;
    }
    else if(user == 2 && computer == 3)
    {
        return -1;
    }
    else if(user == 2 && computer == 1)
    {
        return 1;
    }
    else if(user == 3 && computer == 1)
    {
        return -1;
    }
    else if(user == 3 && computer == 2)
    {
        return 1;
    }
    else{
        printf("Invalid Input!");
        return 0;
    }
}

int printResult(int result)
{
/*Print choices
Print winner message*/

    int count = 0,Uwin = 0,Cwin = 0;
    if(result == 0)
    {
        printf("\nROUND DRAW!!!");
    }
    else if(result == 1)
    {
        printf("\nUSER WINS!!!");
        Uwin++;
    }
    else if(result == -1)
    {
        printf("\nCOMPUTER WINS");
        Cwin++;
    }

    printf("\n\n===SCORES===\n");
    printf("Computer:%d\n",Cwin);
    printf("User:%d",Uwin);

    count = Cwin + Uwin;
    
    return count;
}