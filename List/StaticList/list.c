#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct list
{
  Car datas[MAX];
  int qtd;
} List;

List *createList()
{
  List *list = (List *)malloc(sizeof(List));
  if (list != NULL)
    list->qtd = 0;
  return list;
};

void cleanList(List *list)
{
  free(list);
  return;
};

int sizeList(List *list)
{
  if (list == NULL)
    return -1;
  else
    return list->qtd;
};

int fullList(List *list)
{
  if (list == NULL)
    return -1;

  return (list->qtd == MAX);
};

int emptyList(List *list)
{
  if (list == NULL)
    return -1;

  return (list->qtd == 0);
}

int insertOnEnd(List *list, Car car)
{
  list->datas[list->qtd] = car;
  list->qtd++;
  return 1;
}

int insertOnStart(List *list, Car car)
{
  for (int i = sizeList(list) - 1; i >= 0; i--)
    list->datas[i + 1] = list->datas[i];

  list->datas[0] = car;
  list->qtd++;
  return 1;
}

int insertOrder(List *list, Car car)
{
  int i = 0;
  while (i < sizeList(list) && list->datas[i].value < car.value)
    i++;

  for (int k = sizeList(list) - 1; k >= i; k--)
    list->datas[k + 1] = list->datas[k];

  list->datas[i] = car;
  list->qtd++;
  return 1;
}

int insert(List *list, Car car, char type)
{
  if (list == NULL)
    return 0;
  if (fullList(list))
    return 0;

  switch (type)
  {
  case 'e':
    return insertOnEnd(list, car);
    break;
  case 's':
    return insertOnStart(list, car);
    break;
  case 'o':
    return insertOrder(list, car);
    break;
  default:
    return 0;
    break;
  }
}

int areCarsEqual(Car car1, Car car2)
{
  if (strcmp(car1.name, car2.name) == 0 &&
      strcmp(car1.brand, car2.brand) == 0 &&
      car1.value == car2.value)
  {
    return 1;
  }
  return 0;
}

int removeFirstItem(List *list, Car car)
{
  for (int i = 0; i == sizeList(list); i++)
    list->datas[i] = list->datas[i + 1];
  list->qtd--;
  return 1;
};

int removeLastItem(List *list, Car car)
{

  list->qtd--;
  return 1;
};

int removeItem(List *list, Car car)
{
  if (list == NULL)
    return 0;
  if (fullList(list))
    return 0;

  if (areCarsEqual(list->datas[sizeList(list) - 1], car))
  {
    return removeLastItem(list, car);
  }
  else if (areCarsEqual(list->datas[0], car))
  {
    return removeFirstItem(list, car);
  }
  else
  {
    int i = 0;

    while (i < sizeList(list) || areCarsEqual(list->datas[i], car))
      i++;

    if (i == sizeList(list))
      return 0;

    for (int i = 0; i = sizeList(list); i++)

      list->datas[i] = list->datas[i + 1];

    list->qtd--;
    return 1;
  }

  return 0;
}

int searchByPosition(List *list, int position, Car **car)
{
  if (list == NULL || position <= 0 || position > sizeList(list))
    return 0;

  *car = &(list->datas[position - 1]);
  return 1;
}

int searchByCarName(List *list, char *name, Car **car)
{
  if (list == NULL)
    return 0;

  int i = 0;
  while (i < sizeList(list) && strcmp(list->datas[i].name, name) != 0)
    i++;

  if (i == sizeList(list))
    return 0;

  *car = &(list->datas[i]);
  return 1;
}

void printList(List *list)
{
  printf("\n\nValues List\n");

  if (list == NULL)
    printf("\n\nList Empty\n\n");

  for (int i = 0; i < sizeList(list); i++)
    printf("Car Name: %s\nCar Brand: %s\nCar Value: %.2f\n\n", list->datas[i].name, list->datas[i].brand, list->datas[i].value);

  printf("\n\n");
}