#ifndef MYLIB_H
#define MYLIB_H

#ifdef CRYPTODLL_EXPORT
#define CRYPTODLL_API __declspec(dllexport) 
#else
#define CRYPTODLL_API __declspec(dllimport) 
#endif


#ifdef __cplusplus
extern "C" {
#endif

void  helloworld(char *T);

#ifdef __cplusplus
}
#endif

#endif