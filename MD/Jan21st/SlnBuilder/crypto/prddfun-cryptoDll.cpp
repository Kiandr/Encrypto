// prddfun-cryptoDll.cpp : Defines the exported functions for the DLL application.
/*--------------------------------------------------------------------

    File        :   prddfun-cryptoDll.cpp
    Purpose     :   implement cryptographic encoding of a string using
                    the crypto++ library

    Copyright (c) 2016 Sage Software, Inc.  All rights reserved.

--------------------------------------------------------------------*/

// Defines the entry point for the DLL application.
// This can be removed once we are able to link this directly into view
#include "WINDOWS.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#include "prddfun-cryptoDll.h"

#include <fstream>
using namespace std;

/*********** Standard C++ Libraries**************\
\************************************************/
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
using std::exit;
#include <cstdio>
using std::cout;
using std::cerr;
using std::endl;


//:::::::: Crypto ++ Libs ::://
#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;
#include "cryptlib.h"
//using CryptoPP::Exception;
#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
#include "des.h"
using CryptoPP::DES_EDE2;
#include "modes.h"

using CryptoPP::ECB_Mode;
#include "secblock.h"
using CryptoPP::SecByteBlock;
#include"filters.h"
#include "aes.h"
using CryptoPP::AES;
#include "base64.h"
using CryptoPP::SimpleProxyFilter;
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;
using CryptoPP::Base64URLEncoder;
using CryptoPP::Base64URLDecoder;
#include "pch.h"

// Other standard headers
#include <fstream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string.h>

// Encode the given string to "URL ENCODING" algorithm so it could be passed as a url over the internet.
// Based up on a couple of algorithms googled from internet.
string urlEncode(string str){
    string new_str = "/?key=";
    char c;
    int ic;
    const char* chars = str.c_str();
    char bufHex[10];
    int len = strlen(chars);

    for(int i=0;i<len;i++){
        c = chars[i];
        ic = c;
        // uncomment this if you want to encode spaces with +
        /*if (c==' ') new_str += '+';
        else */if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') new_str += c;
        else {
            sprintf(bufHex,"%X",c);
            if(ic < 16)
                new_str += "%0";
            else
                new_str += "%";
            new_str += bufHex;
        }
    }
    return new_str;
 }

// SEE HEADER
char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer, const char *_stemURLapply, const char *_url, const byte *_Key, int _KeySize)
{
    // Turning a c-style string to c++ string
    string plain(_url);
    string cipher = "";
    string encoded;
    string UriEncoded = "";

    // Generate an AES ECB Encryption Key from const unsigned char key[]. Its a Secret Key hard coded in view that Sage 100 works
    encoded.clear();
    ECB_Mode< AES >::Encryption encr;
    encr.SetKey(_Key, _KeySize );

    // String Source uses the Plain text and the 'encr' and the PKCS padding mechanisim to encrypt
    // Build ECB AES Encryption algorithm using Crypto++ filters
    // PKCS_PADDING Padding
    // It is extremly important to use PKCS to fit with Sage 100
    StringSource ss1( plain, true,
        new StreamTransformationFilter( encr,
            new StringSink( cipher ),
         StreamTransformationFilter::PKCS_PADDING
        ) // StreamTransformationFilter
    ); // StringSource

    // Base64 Encoder and URI encode, so we can pass it over the internet
    StringSource ss2( cipher, true,
        new Base64Encoder(
            new StringSink( encoded )
        ) // HexEncoder // Base64Encoder
    );
    UriEncoded = _stemURLapply + urlEncode (encoded);

    // Filling the buffer as NUL character terminated string
    // We know the pointers are not NULL, and if the buffer is too small it will return an empty string, so we can ignore the return code
    (void) strcpy_s(_buffer, _LenOfbuffer, UriEncoded.c_str());

    // Return the address of _buffer to the Dll Tester To Avoid Multi Threading MD C runtime Linking issues
    return (_buffer);
};
