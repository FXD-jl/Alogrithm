#include <cstring>
#include<Eigen/SVD>


void write_to(char *words, int index, char w) {
  int length = strlen(words);
  if (index >= length) {
    words[length] = w;
  } else
    words[index] = w;
}
