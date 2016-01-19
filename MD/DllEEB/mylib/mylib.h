#ifndef MYLIB_H
#define MYLIB_H
/*
#if defined(BUILDING_MYLIB)
#define MYLIB_API __declspec(dllexport) __stdcall
#else
#define MYLIB_API __declspec(dllimport) __stdcall
#endif
*/
//#ifdef __cplusplus
//extern "C" {
//#endif
 __declspec(dllexport)  void CryptoEncryptTestUnit(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl, const unsigned char  *_Key, int _myArraySize, int Index);
 __declspec(dllexport)  void CryptoEncryptTestUnit(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl, const unsigned char  *_Key, int _myArraySize, int Index);
 //__declspec(dllexport)  char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl);
__declspec(dllexport)  char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,const char *_url,int _lenOfurl, const unsigned char  *_Key,int _myArraySize);


//#ifdef __cplusplus
//}
//#endif

#endif