#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void main()
{
  Car cars[6] = {
      {"Car 1", "Brand A", 10000.50},
      {"Car 2", "Brand B", 15000.75},
      {"Car 3", "Brand C", 20000.00},
      {"Car 4", "Brand D", 25000.25},
      {"Car 5", "Brand E", 30000.50},
      {"Car 6", "Brand F", 35000.75}};
  List *list;
  Car *carFind;

  list = createList();

  if (insert(list, cars[0], 'e'))
    printf("One car was added on list on end\n");

  if (insert(list, cars[1], 's'))
    printf("One car was added on list on start\n");

  if (insert(list, cars[3], 'o'))
    printf("One car was added on list orderned\n");

  if (removeItem(list, cars[1]))
    printf("Item Removed\n");

  if (searchByPosition(list, 1, &carFind))
    printf("Car %s finded\n", carFind->name);

  if (searchByCarName(list, "Car 1", &carFind))
    printf("Car %s finded\n", carFind->name);

  int size = sizeList(list);

  printf("Size: %d\n", size);

  printList(list);

  int full = fullList(list);
  if (full)
    printf("List is fully filled\n");
  else
    printf("List have space\n");

  int empty = emptyList(list);
  if (empty)
    printf("List is empty\n");
  else
    printf("List have space\n");

  cleanList(list);

  return;
}