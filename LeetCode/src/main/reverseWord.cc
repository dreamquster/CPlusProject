#include <cstdlib>
#include "method_declare.h"

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void reverseRangeString(char* s, int from, int to) {
    int len = to - from;
    for (int i = 0; 0 < len && i <= len/2; ++i) {
        swap(&s[from+i], &s[to-i]);
    }
}

void compactSpace(char* s) {
    char* p = s;
    char* sp = s;
    bool inWord = false;
    bool first = true;
    while ('\0' != *p) {
        if (' ' == *p) {
            inWord = false;
        } else {
            if (!inWord) {
                if (first) {
                    first = false;
                } else {
                    *sp = ' ';
                    ++sp;
                }
                inWord = true;
            }
            *sp = *p;
            ++sp;
        }
        ++p;
    }
    if (NULL != sp && '\0' != *sp) {
        *sp = '\0';
    }
}

void reverseWords(char* s) {
    compactSpace(s);
    int slen = strlen(s);
    reverseRangeString(s, 0, slen - 1);
    int wordStart = 0;
    for (int i = 0; i < slen; ++i) {
        if (' ' == s[i]) {
            reverseRangeString(s, wordStart, i - 1);
            wordStart = i + 1;
        }
    }
    if (wordStart < slen) {
        reverseRangeString(s, wordStart, slen - 1);
    }
}

