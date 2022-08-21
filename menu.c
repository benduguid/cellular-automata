#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "cellular.h"
#include <stdbool.h>

int ruleArray[8] = {0,0,0,1,1,1,1,0}; //Default

//Function to run the menu
int main(){

  printf("\n\n\t\tWelcome to our 1D Cellular Automata Program!\n\n\n");
  int choice;

  //Infinitely loops and to exit you can select 3rd option
  while(1){

    //Display choices to user
    printf("1. Cool Presets\n");
    printf("2. Pick your own rule\n");
    printf("3. Random rule\n");
    printf("4. Run the automaton\n");
    printf("5. Exit\n\n\n");
    printf("Enter your choice :  ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        chooseRule(); //Lets user chooce which ruleset to use
        break;
      case 2:
        UserChoice(); //They enter their own rule
        break;
      case 3:
        RandomRule(); //Randomises the rule the program uses.
        break;
      case 4:
        start(ruleArray, 50); //Calls start() in cellular.c
        break;
      case 5:
        printf("\nExiting\n");
        exit(0); //exits program
      }
    }
  return 0;
}

//Function to set ruleset (7 options)
void chooseRule(){
  bool flag=false;
  int num=0;

  printf("Options: \n30\n60\n90\n161\n220\n222\n250\n");  //Print options to users
  int rule30[] =  {0,0,0,1,1,1,1,0};
  int rule60[] =  {0,0,1,1,1,1,0,0};
  int rule90[] =  {0,1,0,1,1,0,1,0};
  int rule161[] = {1,0,1,0,0,0,0,1};
  int rule220[] = {1,1,0,1,1,1,1,0};
  int rule222[] = {1,1,0,1,1,1,1,0};
  int rule250[] = {1,1,1,1,1,0,1,0};

  //Loops until valid ruleset is chosen
    do{
      printf("Enter number: ");
      scanf("%d", &num);

      //For example if 30 if chosen it will place every digit in the 30array
      //into the usable ruleArray
      if(num == 30){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule30[i];
        }
        flag=true;
      }else if(num == 60){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule60[i];
        }
        flag=true;
      }else if(num == 90){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule90[i];
        }
        flag=true;
      }else if(num == 161){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule161[i];
        }
        flag=true;
      }else if(num == 220){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule220[i];
        }
        flag=true;
      }else if(num == 222){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule222[i];
        }
        flag=true;
      }else if(num == 250){
        for(int i=0; i<8; i++){
          ruleArray[i]=rule250[i];
        }
        flag=true;
      }
    }while(flag==false);
}

void UserChoice(){

  char *key;
  char *value = ":";
  int test = getInt("Enter an integer (1-256): \n");
  int counter = 0;

  static const char filename[] = "rules.txt";
  FILE *file = fopen ( filename, "r" );
  if ( file != NULL )
  {
    char line [ 15 ]; /* or other suitable maximum line size */
    while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
    {
      counter++;
      // Key points to the index
      key = strtok(line, value);
      // Key points to the rule
      key = strtok(NULL, value);

      if(counter==test)
        break;
    }
    fclose ( file );
  }

  for(int i=0; i<8; i++){
    ruleArray[i]=key[i]-'0';
  }
}

int getInt(char *prompt){
    int num=0;
    char input[100];
    printf("%s", prompt);
    while(num > 256 || num < 1){
        fgets(input, 100, stdin);
        num = atoi(input);
    };
    printf("You entererd - %d\n", num);
    return num;
}

//Function to generate a random rule
int RandomRule(){
        //initialising random number generator
 srand(time(NULL));
          //for loop for each member of array
 for (int i = 0; i < 8; ++i)
 {
  int random = rand() % 2;
  ruleArray[i]=random;
}
return SUCCESS;
}
