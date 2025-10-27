#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct timeval t1, t2;
  int elapsedTime = 0;
  char s[20];
  int prev;
  FILE *fptr;
  gettimeofday(&t1, NULL);
  
  while (1) {
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec);
    if (elapsedTime % 2 == 0) {
      if (prev != elapsedTime) {
        prev = elapsedTime;
        printf("hello");
        fptr = fopen("./config.txt", "w");

        if (fptr == NULL) {
          printf("ERROR: cannot open file\n");
          return 1;
        }
        sprintf(s, "%d", elapsedTime);
        fprintf(fptr, strcat(s, " seconds"));
        fclose(fptr);
      }
    }
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec);
  printf("%d s.\n", elapsedTime);

  return 0;
}
