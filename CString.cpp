//
// Created by Jules Dupont on 26/09/2024.
//

#include <cassert>
#include <iostream>

int mylen(const char s[]);

int mycmp(const char s1[], const char s2[]);

bool isPalindrome(const char s[]);

void inverse(char s[]);

int main() {
    char dog[4] = {'d', 'o', 'g', '\0'};
    char blabla[8] = {'b', 'l', 'a', 'b', 'l', 'a', '\0', 'o'};
    char empty[4] = {'\0', 'o', 'g', 'd'};

    assert(mylen(dog) == 3);
    assert(mylen(blabla) == 6);
    assert(mylen(empty) == 0);

    char dogToo[4] = {'d', 'o', 'g', '\0'};
    char blobli[8] = {'b', 'l', 'o', 'b', 'l', 'i', '\0', 'o'};
    assert(mycmp(dog, dogToo) == 0);
    assert(mycmp(blabla, blobli) == -1);

    assert(isPalindrome(dog) == false);
    char dod[4] = {'d', 'o', 'd', '\0'};
    assert(isPalindrome(dod) == true);
    char yakak[7] = {'y', 'a', 'k', 'a', 'k', '\0', 'a'};
    assert(isPalindrome(yakak) == false);
    char kayak[7] = {'k', 'a', 'y', 'a', 'k', '\0', 'a'};
    assert(isPalindrome(kayak) == true);

    char god[4] = {'g', 'o', 'd', '\0'};
    inverse(dog);
    assert(mycmp(dog, god) == 0);

    char albalb[7] = {'a', 'l', 'b', 'a', 'l', 'b', '\0'};
    inverse(blabla);
    assert(mycmp(blabla, albalb) == 0);

    return 0;
}

int mylen(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

int mycmp(const char s1[], const char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        ++i;
    }
    // Handle the case where s1 and s2 have different lengths, given the convention that bla < blab
    if (s1[i] != '\0') {
        return 1;
    }
    if (s2[i] != '\0') {
        return -1;
    }
    return 0;
}

bool isPalindrome(const char s[]) {
    int len = mylen(s);
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }

    return true;
}

void inverse(char s[]) {
    int len = mylen(s);
    char reversed[len + 1];
    for (int i = 0; i < len; ++i) {
        reversed[i] = s[len - i - 1];
    }
    reversed[len] = '\0';

    strcpy(s, reversed);
}
