#ifndef MYLIB_H
#define MYLIB_H
/*
#if defined(BUILDING_MYLIB)
#define MYLIB_API __declspec(dllexport) __stdcall
#else
#define MYLIB_API __declspec(dllimport) __stdcall
#endif
*/
#ifdef __cplusplus
extern "C" {
#endif
 __declspec(dllexport)  void Hello(char *buffer);
__declspec(dllexport)  char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,const char *_url,int _lenOfurl, const unsigned char  *_Key,int _myArraySize);
__declspec(dllexport)  void CryptoEncryptUnitTest(char *_buffer, int _LenOfbuffer,const char *_url,int _lenOfurl, const unsigned char  *_Key,int _myArraySize, int prt);



#ifdef __cplusplus
}
#endif

#endif