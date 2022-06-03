#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX_Score 800
                                                                              //***** ATTENTION HERE ******// 
int height= 20, width=40, x,y, fruitX, fruitY, flag, gameEnd, score, level = 1;          //x is height from the top and
int tailX[100], tailY[100]; //this is for Snakes Body...                      //y is width from the left...
int piece = 0; //for counting the body length...                     //~~ so_dont_mix_it_up_with_x-axis_and_y-axis_concept ~~


                //(y,x) is coordinate of snake' body
                //(fruitY, fruitX) is coordinate of fruit.

void setup()
{
    x = height/2;            // setting the snakes head at center at the begining ....
    y = width/2;

    label1:
    srand(time(NULL));
    fruitX = rand()%20;       //generating random co-ordinate for fruit at the begining,,,,
    if (fruitX == 20)
    {
        goto label1;
    }
    
    label2:
    srand(time(NULL));
    fruitY = rand()%40;
    if (fruitY == 40)
    {
        goto label2;
    }

    gameEnd=0;  //initalizing game and score in the begining...
    score=0;
    piece = 0;
}

void main_Logic()
{
    int prevX, prevY, prev2X, prev2Y;     // these are for replacing the head with body and generate a new head
    prevX = tailX[0];
    prevY = tailY[0];         
    tailX[0] = x;           //snake's head co-ordinate is preserved in 1st array box
    tailY[0] = y;

    for (int i = 1; i < piece; i++)
    {
        prev2X = tailX[i];           //preserving the coordinate of body..
        prev2Y = tailY[i];
        tailX[i] = prevX;            //placing the body in theplace of head
        tailY[i] = prevY;
        prevX = prev2X;             //new head coordinate is formed
        prevY = prev2Y;
    }
    

    switch (flag)                  //flag's value is obtaind from input function..
    {  
    case 1:
        y++;       //for input 'd' flag 1 and result will be increament in width coordinate....i.e. move towards right
        break;
    case 2:        //for input 'a' flag 2 and result will be decrement in width coordinate....i.e. move towards left
        y--;
        break;
    case 4:        
        x++;  //for input 's' flag 4 and result will be increament in height (from the top) coordinate....i.e. move towards down
        break;
    case 3:
        x--;  //for input 'a' flag 3 and result will be decreament in height (from the top) coordinate....i.e. move towards up 
        break;

    case 5:
        gameEnd = 1;
        break;
    }

    if (y==0 || y==width || x==0 || x==height )
    {
        gameEnd = 1;          //if head touch the border game will end..
    }

    for (int i = 0; i < piece; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameEnd = 1;
        }
        
    }
    

    if (x==fruitX && y==fruitY)
    {
        //if head co-ordinate became similar with fruit co-ordinate.... then,
        //another random co-ordinate for fruit will be generated..

        label3:
        srand(time(NULL));
        fruitX = rand()%20;
        if (fruitX == 20)
        {
            goto label3;
        }
    
        label4:
        srand(time(NULL));
        fruitY = rand()%40;
        if (fruitY == 40)
        {
            goto label4;
        }

        score= score + 10;
        piece++;       //if head touch the food then  score and body_length will increase by one.
    }
}

void input()
{
    if (kbhit())          //for checkng if any button on the keyboard is pressed or not
    {
        switch (getch())  //for storing the inputs..
        {
        case 'd' :
            flag = 1;
            break; 
        case 'a' :
            flag = 2;
            break;
        case 'w' :
            flag = 3;
            break;
        case 's' :
            flag = 4;
            break;
        case 'x' :
            flag = 5;
            break;
        }

        //for different input flag value will be different...flag value will be used in main_logic() function..
    }
}

void draw()
{
    system("cls");
    int i, j, k, ch;
    
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (i==0 || i==height || j==0 || j==width )
            {
                printf("*");           //* will be used as border and game_window
            }
            else
            {
                 if (i==x && j==y)
                {
                    printf("O");         //snaked body will be represented by 0..
                }
                else if (i==fruitX && j==fruitY)
                {
                    printf("#");         // fruit will be shown by @...
                }
                else
                {
                    ch = 0;
                    for (int k = 0; k < piece; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");        // the body added will print o using this portion 
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                    printf(" ");    //if any of them isn't present, print space...
                                    //that will be the empty portion of the game_window..
                } 
            }  
        }
        printf("\n");
    } 
}

void level_and_speed()
{
    int level_Input;

    if (score ==50 && level ==1 || score ==150 && level ==2 || score ==300 && level ==3 || score ==500 && level ==4)
    {
        level++;
        printf("!!! Congratulation !!! \nYOU HAVE REACHED AT LEVEL %d \nBE CAREFULL SPEED WILL BE INCREASED\n", level);
        printf("\nBe ready.... starting in 10 seconds");
        sleep(10);
        printf("\nStarting...");
        sleep(2);
    }
    
    switch (level)
        {
        case 1:
            for (int i = 0; i < 10000; i++)
            {
                for (int j = 0; j < 10000; j++)
                {
                } 
            }
            break;

        case 2:
            for (int i = 0; i < 10000; i++)
            {
                for (int j = 0; j < 5000; j++)
                {
                } 
            }
            break;

        case 3:
            for (int i = 0; i < 10000; i++)
            {
                for (int j = 0; j < 1000; j++)
                {
                } 
            }
            break;

        case 4:
            for (int i = 0; i < 1000; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                } 
            }
            break;

        case 5:
            break;
        
        default:
            break;
        }
}

int main()
{
    char ip;
    //int ready = 0;
    
    while (1)
    {
        system("cls");
        printf("\n\n\n\t\tWELCOME TO\n\n\n\t**** SayanSRK's SNAKE HUNT ****\n\n");
        printf("Loading....\n");
        sleep(3);
        printf("Setting Up The Game For You........\n");
        sleep(2);
        setup();     //setting up the game....

        printf("\n\n Game is startng from level 1 ....\n");
        sleep(3);

        while (gameEnd != 1)   //infiite loop untill game_End = 1..... 
        {
            draw();                  //Follow these steps untill the GameEnd becomes zero..
            input();                 //Order is VERY VERY IMPORTANT here...
            main_Logic();            //take input ... then apply logic .... then print the window according to it..
            level_and_speed();        //for level wise speed control for the game..

            if (score == MAX_Score)
            {
                printf("\n!!!! CONGRATULATION !!!\nYou Have Successfully Passed All Levels Of This Game and\n\n  ~~~~~~ YOUR SCORE IS  -  %d ~~~~~~\n", score);
                printf("\n\nExcellent Game Playing by You...\n");
                sleep(10);

                system("cls");
                printf("\n\n\t******* Game Credits *******\n"); sleep(3);
                printf("\n\tFOUNDER : Sayan Kumar Bhowmick"); sleep(3);
                printf("\n\tSOFTWARE DESIGNED BY : SayanSRK"); sleep(3);
                printf("\n\tGRAPHICS DESIGNED BY : SayanSRK\n\n "); sleep(3);
                printf("\t**** A SayanSRK Creation ****"); sleep (5);

                goto end;

            }
            
        }

        printf("\n!!!! GAME OVER !!!\n   ~~~~~~ YOUR SCORE IS  -  %d ~~~~~~\n", score);  //display score and the gameover msg 
        printf("\nYOU HAVE FINISHED AT LEVEL %d ......... Keep Trying Better..\n", level);
        printf("\nPress y To Play Again : ");
        scanf("%c", &ip);

        switch (ip)
        {
        case 'y':
            continue;
        
        default:
            goto end;
            break;
        }
    }

    printf("\tThanx for Playing...");
    end:
    return 0;
}

