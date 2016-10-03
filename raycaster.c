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

  double centerX = 0;
  double centerY = 0;

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  double camWidth, camHeight;

  objectList list = NULL;
  list = parseFile(argv[3], list, &camWidth, &camHeight);

  double pixWidth = camWidth / width;
  double pixHeight = camHeight / height;

  printf("\nScene : width = %d\theight = %d\n", width, height);
  printf("\nCamera : width = %lf\theight = %lf\n\n", camWidth, camHeight);
  printObjects(list);

  int x,y;

  for(y = 0; y < height ; y++){
    for(x = 0; x < width ; x++){
      double* Ro = getVector(0, 0, 0);
      double Rx = centerX - (camWidth/2) + pixWidth * (x+0.5);
      double Ry = centerY - (camHeight/2) + pixHeight * (y+0.5);
      double* Rd = getVector(Rx, Ry, 1);
      normalize(Rd);
      double bestT = INFINITY;
      while (list != NULL) {
        double t=0;

        //Intersection
      }
    }
  }

  //FILE* outputFile = fopen(argv[4], "w");


  return 0;
}
