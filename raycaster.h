#ifndef __RAY_CASTER
#define __RAY_CASTER

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct object{
  int kind; // 0 = sphere, 1 = plane
  double* color;
  double* position;
  union {
    struct {
      double radius;
    } sphere;
    struct {
      double* normal;
    } plane;
  };
  struct object* next;
} *objectList;

void printObjects(objectList list);


#endif
