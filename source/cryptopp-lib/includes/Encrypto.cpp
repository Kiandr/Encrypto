#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <windows.h>
#include <cstdio>

#include <cstdlib>
using std::exit;

#include <string>
using std::string;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptlib.h"
using CryptoPP::Exception;

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
using CryptoPP::CBC_Mode;
using CryptoPP::ECB_Mode;


#include "secblock.h"
using CryptoPP::SecByteBlock;


#include "aes.h"
using CryptoPP::AES;

#include "base64.h"
using CryptoPP::SimpleProxyFilter;
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;
using CryptoPP::Base64URLEncoder;
using CryptoPP::Base64URLDecoder;

#include "pch.h"
#include "integer.h"

string UriEncode(const string & sSrc)
{
   const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
   const unsigned char * pSrc = (const unsigned char *)sSrc.c_str();
   const int SRC_LEN = sSrc.length();
   unsigned char * const pStart = new unsigned char[SRC_LEN * 3];
   unsigned char * pEnd = pStart;
   const unsigned char * const SRC_END = pSrc + SRC_LEN;

   for (; pSrc < SRC_END; ++pSrc)
   {
      if (*pSrc) 
         *pEnd++ = *pSrc;
      else
      {
         // escape this char
         *pEnd++ = '%';
         *pEnd++ = DEC2HEX[*pSrc >> 4];
         *pEnd++ = DEC2HEX[*pSrc & 0x0F];
      }
   }

   string sResult((char *)pStart, (char *)pEnd);
   delete [] pStart;
   return sResult;
}


int main(int argc, char* argv[])
{
    AutoSeededRandomPool prng;

    string cipher, encoded, recovered;
    string plain = "businessPartnerId=22;sourceCompanyCode=22;sourceProduct=Sage100;fein=22;ts=2016-12-24T00:36:35.284Z;ec=0;";
    unsigned char key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
    std::cout<<"The Key is->"<<key<< endl;;

    // Build Aes
    cout << "plain text: " << plain << endl;
	Cryptopp::Integer i;
  //  ECB_Mode< AES >::Encryption e;
  //  e.SetKey( key, sizeof(key));
//    StringSource ss1(plain, true,new StreamTransformationFilter( e,new StringSink( cipher ), StreamTransformationFilter::PKCS_PADDING));

	return 0;
}

