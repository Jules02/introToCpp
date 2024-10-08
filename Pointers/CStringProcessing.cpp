//
// Created by Jules Dupont on 08/10/2024.
//

#include <iostream>

#include "CStringProcessing.h"

int mylen(const char* s) {
  int len = 0;
  while (*(s+len) != '\0') { len++; }
  return len;
}

void inverse(char* s) {
  int len = mylen(s);
  int i = 0, j = len-1;
  while (i < j) {
    char t = *(s+i);
    *(s+i) = *(s+j);
    *(s+j) = t;
    ++i; --j;
  }
}

char* concatenate(char *s1, char *s2) {
  int len1 = mylen(s1); int len2 = mylen(s2);
  int len = len1 + len2;
  char* ptr = new char[len+1];
  for (int i = 0; i < len1; i++) { *(ptr+i) = *(s1+i); }
  for (int j = 0; j < len2; j++) { *(ptr+len1+j) = *(s2+j); }
  *(ptr+len) = '\0';
  return ptr;
}

int main() {
  char str[] = "hello";
  std::cout << "The string '" << str << "' has length " << mylen(str) << std::endl;

  inverse(str);
  std::cout << "Its inverse is '" << str << "'." << std::endl;

  char *str2 = concatenate(str, str);
  std::cout << str2 << std::endl;
  delete[] str2;
  return 0;
}