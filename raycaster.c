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

double planeIntersection(double* Ro, double* Rd, double* position, double* normal){
  double t = 0;
  normalize(normal); //Just in case
  double denom = dotProduct(normal, Rd);
  if(sqrt(sqr(denom)) > 0.00001){
    t = (-dotProduct(subVector(Ro, position), normal)) / denom;
  }
  return t;
}

double sphereIntersection(double* Ro, double* Rd, double* position, double radius){
  double t;

  double* RoSubPosition = subVector(Ro, position);
  double b = 2 * dotProduct(Rd, RoSubPosition);
  double c = dotProduct(RoSubPosition, RoSubPosition) - radius;

  double sqrtDelta = sqrt(sqr(b) - 4 * c);

  t = (-b - sqrtDelta) / 2;

  if(t < 0){
    t = (-b + sqrtDelta) / 2;
  }

  return t;
}

int main(int argc, char *argv[]){
  if(argc < 5){
    fprintf(stderr, "Error: Expected ./raycaster width height input.json output.ppm");
    exit(ERROR_RAYCAST);
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
      //printf("Rd : %lf  %lf  %lf\n", Rd[0], Rd[1], Rd[2]);
      normalize(Rd);
      //printf("Rd : %lf  %lf  %lf\n", Rd[0], Rd[1], Rd[2]);
      double bestT = INFINITY;
      objectList tempList = list;
      while (tempList != NULL) {
        double t=0;

        switch (tempList->kind) {
          case 0:
            t = sphereIntersection(Ro, Rd, tempList->position, tempList->sphere.radius);
            break;
          case 1:
            t = planeIntersection(Ro, Rd, tempList->position, tempList->plane.normal);
            break;
          default:
            fprintf(stderr, "Error: Object of kind unknow (How is it even possible ?)");
            exit(ERROR_RAYCAST);
        }

        if(t > 0 && t < bestT){
          bestT = t;
        }
        tempList = tempList->next;
      }
      if(bestT > 0 && bestT != INFINITY){
        printf("#");
      }
      else{
        printf(".");
      }
    }
    printf("\n");
  }

  //FILE* outputFile = fopen(argv[4], "w");


  return 0;
}
