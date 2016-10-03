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

static inline double* getVector(double x, double y, double z){
  double* v = malloc(3*sizeof(double));
  v[0] = x;
  v[1] = y;
  v[2] = z;
  return v;
}

static inline double sqr(double v) {
  return v*v;
}

static inline void normalize(double* v) {
  double len = sqrt(sqr(v[0]) + sqr(v[1]) + sqr(v[2]));
  v[0] /= len;
  v[1] /= len;
  v[2] /= len;
}


#endif
