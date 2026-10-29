#include <klib.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t n = 0; 

  while (*s){
    n++;
    s++;
  }
  return n;
}

char *strcpy(char *dst, const char *src) {
  char *ret = dst;
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
  return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *ret = dst; 
  for(;n > 0 ;n--){
    if (*src != '\0'){
      *dst = *src; 
      dst ++; 
      src ++; 
    }else{
      *dst = '\0';  
      dst ++;
    }
  }
  return ret;
}

char *strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst) dst++; 
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    if (*s1 != *s2) return (unsigned char)*s1 - (unsigned char)*s2;
    s1 ++;
    s2 ++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  for (; n > 0; n--) {
    if (*s1 != *s2) {
      return (unsigned char)*s1 - (unsigned char)*s2;
    }
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  void *ret = s;
  for (; n > 0; n --) {
    *(unsigned char *)s = c;
    s = (unsigned char *)s + 1;
  }
  return ret;
}

void *memmove(void *dst, const void *src, size_t n) {
  if (n == 0 || dst == src) return dst;

  const unsigned char *p1 = src;
  unsigned char *p2 = dst;
  if ((uintptr_t)dst > (uintptr_t)src) {
    p1 += n;
    p2 += n;
    for (; n > 0; n --) {
      p1 --;
      p2 --;
      *p2 = *p1;
    }
  } else {
    for (; n > 0; n --) {
      *p2 = *p1;
      p1 ++;
      p2 ++;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *dst = out;
  const unsigned char *src = in;
  for (; n > 0; n --) {
    *dst = *src;
    dst ++;
    src ++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  for (;n > 0; n --){
    if (*p1 != *p2) return (unsigned char)*p1 - (unsigned char)*p2;
    p1 ++;
    p2 ++;
  }
  return 0;
}

char *strchr(const char *s, int c) {
  do {
    if (*s == c) return (char *)s;
    if (*s == '\0') break;
    s ++;
  } while (1);
  return NULL;
}

char *strrchr(const char *s, int c) {
  const char *p = s + strlen(s);
  do {
    if (*p == c) return (char *)p;
    if (s == p) break;
    p --;
  } while (1);
  return NULL;
}

#endif
