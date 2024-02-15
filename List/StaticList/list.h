#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct car
{
  char name[30];
  char brand[30];
  float value;
} Car;

typedef struct list List;

List *createList();
void cleanList(List *list);

int sizeList(List *list);

int fullList(List *list);

int emptyList(List *list);

int insert(List *list, Car car, char type);

int removeItem(List *list, Car car);

int searchByPosition(List *list, int position, Car **car);

int searchByCarName(List *list, char *name, Car **car);

void printList(List *list);