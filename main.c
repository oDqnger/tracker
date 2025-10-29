#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// edit these paths by adding in the file location in the ""
#define FILE_LOC ""
// file location to store the time spent for a session
#define FILE_LOC_1 ""
// file location for storing the total amount o f time spent in ur computer.

int main() {
  struct timeval t1, t2;
  int elapsedTime = 0;
  char s[20];
  int prev;
  FILE *fptr = fopen(FILE_LOC, "r");
  if (fptr == NULL) {
    printf("ERROR: cannot open file\n");
    return 1;
  }
  
  char data[20];
  fgets(data, 20, fptr);
  fclose(fptr);

  FILE *fptr2 = fopen(FILE_LOC_1, "a");
  if (fptr2 == NULL) {
    printf("ERROR: cannot open file\n");
    return 1;
  }
  fprintf(fptr2, data);
  fclose(fptr2);

  fptr2 = NULL;

  gettimeofday(&t1, NULL);
  
  while (1) {
    gettimeofday(&t2, NULL);
    elapsedTime = t2.tv_sec - t1.tv_sec;
    if (elapsedTime % 60 == 0) {
      if (prev != elapsedTime) {
        prev = elapsedTime;
        fptr = fopen(FILE_LOC, "w");

        if (fptr == NULL) {
          printf("ERROR: cannot open file\n");
          return 1;
        }
        sprintf(s, "%d", (int) elapsedTime / 60);
        fprintf(fptr, strcat(s, " minutes\n"));
        fclose(fptr);
      }
    }
    usleep(100000);
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec);
  printf("%d s.\n", elapsedTime);

  return 0;
}
