#ifndef __RAY_CASTER
#define __RAY_CASTER

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct object{
  int kind; // 0 = sphere, 1 = plane
  double color[3];
  double center[3];
  union {
    struct {
      double radius;
    } sphere;
    struct {
      double normal[3];
    } plane;
  };
  struct object* next;
} *objectList;

void printObjects(objectList list);


#endif
