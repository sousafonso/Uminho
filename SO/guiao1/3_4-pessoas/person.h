#include <fcntl.h>

#define FILENAME "file_pessoas"

#define DEBUG 1

typedef struct person {
    char name[100];
    int age;
} Person;

int new_person(char* name, int age);

int list_persons(int N);

int change_age(char* name, int age);

int change_age_v2(int position, int age);

