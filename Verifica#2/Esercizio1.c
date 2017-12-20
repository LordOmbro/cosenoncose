#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 30

typedef char str[MAX_LEN];
typedef enum {false,true} bool;

typedef struct DATO {

} tipodato;

typedef struct EL {
	tipodato dato;
	struct EL *next;
} tipoelemento;

typedef tipoelemento *tipolista;
