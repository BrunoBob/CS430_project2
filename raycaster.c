#include "json_parser.h"
#include "raycaster.h"

void printObjects(objectList list){
  while(list != NULL){
    printf("Object of kind %d\n", list->kind);
    list = list->next;
  }
}

int main(int argc, char *argv[]){
  objectList list = NULL;
  list = parseFile(argv[1], list);
  printObjects(list);
  if(list == NULL) exit(1);
  return 0;
}
