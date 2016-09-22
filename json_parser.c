#include "json_parser.h"

int next_c(FILE* json){
  int c = fgetc(json);
  //DEBUG
  return c;
}

void expect_c(FILE* json, int c){

}
