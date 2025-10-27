#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct timeval t1, t2;
  int elapsedTime = 0;
  FILE *fptr;
  gettimeofday(&t1, NULL);
  char s[20];
  int prev;
  int counter = 0;
  while (1) {
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec);
    if (elapsedTime % 5 == 0) {
      if (prev != elapsedTime) {
        prev = elapsedTime;
        counter++;
        printf("%d\n", counter);
        fptr = fopen("./config.txt", "w");

        if (fptr == NULL) {
          printf("ERROR: cannot open file\n");
          return 1;
        }
        sprintf(s, "%d", elapsedTime);
        fprintf(fptr, s);
        fclose(fptr);
      }
    }
    if (elapsedTime == 10) {
      break;
    }
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec);
  printf("%d s.\n", elapsedTime);

  return 0;
}
