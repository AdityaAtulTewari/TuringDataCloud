//
// Created by A-man-T on 1/2/18.
//

//Header Guard
#ifndef INFARR_H
#define INFARR_H

typedef struct infarr
{
  int (*compare)(void*, void*);
  //array
  void*[] arr;

} infarr;
//Create an array
void createInfarr(unsigned int len, int (*compare)(void*, void*));

//Insert something
void insertInfarr(void* data, infarr* iputin);

//sort el array
void sortInfarr(infarr* array);

//Remove somethhick
void removeElement(infarr* inoputin, unsigned int location);

//print wut is in the array
void printContained(infarr* arryshow);

//show wut is at sum adress
void printElement(infarr* arryname, unsigned int location);

// Destroy ze array
void destroyInfarr(infarr* grumpycat);

#endif