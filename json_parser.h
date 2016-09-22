#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int nextC(FILE* json);

void expectC(FILE* json, int c);

void skipSpace(FILE* json);

void parseFile(FILE* json);

void getString(FILE* json);
