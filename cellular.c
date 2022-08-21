/*
 * 1D Cellular Automata
 * Ben Duguid
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cellular.h"
#include <stdbool.h> // required, defines the 'bool' data type in C

int ruleset[8]; //Ruleset 60
//int currentGen[GENLENGTH]; //i.e. Parent generation

//Ruleset gets passed in to set it globally
int start(int ruleArray[], int generationMax){

  Grid *grid = (Grid*)malloc(sizeof(Grid));

  //Initialise currentGen to be all zeros
  for(int i=0; i<GENLENGTH; i++){
    grid->parent[i] = 0;
  }
  //printf("The generation is - ");
  grid->parent[GENLENGTH/2]=1;  //Sets middle value to be 1 and rest will be 0
  displayGen(grid); //Displays first gen

  //Assigning ruleset chosen to be the ruleset used
  for(int i=0; i<8; i++){
    ruleset[i]=ruleArray[i];
  }
  int generation = 0; //initialise generation

  while(generation!=generationMax){
    generate(grid); //Calls generate functions
    displayGen(grid); //Displays generation after generation until
    generation++;  //increment generation
  }
  free(grid); //Free grid memory

  return 0;
}

//Function to display the generation currenty in currentGen
void displayGen(Grid *grid){
  char* displayArray[GENLENGTH]; //Char array to display the automata as a nicer looking display

  FILE * fPointer;
  fPointer = fopen("automata.txt", "a");

  //Displaying a char array with *'s makes it much nicer to look at
  for(int i=0; i<GENLENGTH; i++){
    if(grid->parent[i]==0){
      displayArray[i] = " ";
    }else if(grid->parent[i]==1){
      displayArray[i] = "*";
    }
  }

  for(int i=0; i<GENLENGTH; i++){
    fprintf(fPointer, "%s",displayArray[i]);
    printf("%s",displayArray[i]);
  }
  fprintf(fPointer, "\n");
  printf("\n");
  fclose(fPointer);
}

//Function to generate the next generation
void generate(Grid *grid){

  Cell *cell = (Cell*)malloc(sizeof(Cell));
  //Create empty array ready for next generation (child)
  //For every spot in the binary number / array, call the rules function to find its child
  for(int i = 0; i<GENLENGTH; i++){
    cell->left = grid->parent[i-1]; //Left neighbour
    cell->me = grid->parent[i];  //The cell itself
    cell->right = grid->parent[i+1]; //right neighbour
    grid->child[i] = rules(cell);
  }
  
  //Setting nextGen to be the currentGen
  for(int i=0; i<GENLENGTH; i++){
    grid->parent[i]=grid->child[i];
  }
  free(cell);
}

/*
 * Returns next cell
 */
int rules(Cell *cell){
  int num = (4*cell->left)+(2*cell->me)+cell->right;
  return ruleset[7-num];
}
