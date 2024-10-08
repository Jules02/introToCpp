//
// Created by Jules Dupont on 08/10/2024.
//

#include <iostream>

#include "CStringProcessing.h"

int mylen(const char* s) {
  int len = 0;
  while (s[len] != '\0') { len++; }
  return len;
}

void inverse(char* s) {
  int len = mylen(s);
  int i = 0, j = len-1;
  while (i < j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
    ++i; --j;
  }
}

int main() {
  char str[] = "hello";
  std::cout << "The string '" << str << "' has length " << mylen(str) << std::endl;

  inverse(str);
  std::cout << "Its inverse is '" << str << "'." << std::endl;
  return 0;
}