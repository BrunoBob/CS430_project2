#include "json_parser.h"
#include "raycaster.h"

void printObjects(objectList list){
  while(list != NULL){
    if(list->kind == 0){
      printf("Object of kind : sphere\n");
      printf("Color : %lf  %lf  %lf\n", list->color[0], list->color[1], list->color[2]);
      printf("Position : %lf  %lf  %lf\n", list->position[0], list->position[1], list->position[2]);
      printf("Radius : %lf\n", list->sphere.radius);
    }
    else{
      printf("Object of kind : plane\n");
      printf("Color : %lf  %lf  %lf\n", list->color[0], list->color[1], list->color[2]);
      printf("Position : %lf  %lf  %lf\n", list->position[0], list->position[1], list->position[2]);
      printf("Normal : %lf  %lf  %lf\n", list->plane.normal[0], list->plane.normal[1], list->plane.normal[2]);
    }
    printf("\n");
    list = list->next;
  }
}

int main(int argc, char *argv[]){
  if(argc < 5){
    fprintf(stderr, "Error: Expected ./raycaster width height input.json output.ppm");
    exit(10);
  }

  double width = atof(argv[1]);
  double height = atof(argv[2]);

  objectList list = NULL;
  list = parseFile(argv[3], list, &width, &height);

  printf("Camera : width = %lf\theight = %lf\n", width, height);
  printObjects(list);

  FILE* outputFile = fopen(argv[4], "w");


  return 0;
}
