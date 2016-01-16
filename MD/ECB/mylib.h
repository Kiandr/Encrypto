#ifndef MYLIB_H
#define MYLIB_H

#if defined(BUILDING_MYLIB)
#define MYLIB_API __declspec(dllexport) __stdcall
#else
#define MYLIB_API __declspec(dllimport) __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif

 __declspec(dllexport) int  helloworld(char *T);

#ifdef __cplusplus
}
#endif

#endif