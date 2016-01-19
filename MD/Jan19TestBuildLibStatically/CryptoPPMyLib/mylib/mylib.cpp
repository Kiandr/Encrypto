// ECB.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "mylib.h"
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
#include "\..\..\..\DD\pr\base\cryptopp-lib\includes\osrng.h"
using CryptoPP::AutoSeededRandomPool;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\cryptlib.h"
//using CryptoPP::Exception;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\des.h"
using CryptoPP::DES_EDE2;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\modes.h"

using CryptoPP::ECB_Mode;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\secblock.h"
using CryptoPP::SecByteBlock;
#include"\..\..\..\..\DD\pr\base\cryptopp-lib\includes\filters.h"
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\aes.h"
using CryptoPP::AES;
#include "..\..\..\..\DD\pr\base\cryptopp-lib\includes\base64.h"
using CryptoPP::SimpleProxyFilter;
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;
using CryptoPP::Base64URLEncoder;
using CryptoPP::Base64URLDecoder;
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\pch.h"

#include <fstream>
#include <cctype>
#include <iomanip>
#include <sstream>

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

void Hello(char*buffer)
{


};
char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl)
{

	// this is a tool that is being used to log
	ofstream myfile;
    myfile.open ("example.txt");
//	myfile<<"This is the URL given to be Encrypted\n";
//	myfile << _url;
//	myfile <<"\n";
	//string plain(_url,_lenOfurl);
	//string plain;
	//	 plain.copy(_url,_lenOfurl,0);
	string cipher = "";
	string   encoded, recovered;
    
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	size_t myArraySize = sizeof(key);
	string plain = "businessPartnerId=123;sourceCompanyCode=123;sourceProduct=Sage300;fein=123;ts=2016-01-14T00:21:52.252Z;ec=50;companyName=kian;address1=kian;address2=kian;city=kian;state=AK;zip=Kian;";	
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";

	ECB_Mode< AES >::Encryption e;
    e.SetKey( key, sizeof(key) );

    // The StreamTransformationFilter adds padding
    //  as required. ECB and CBC Mode must be padded
    //  to the block size of the cipher.
    StringSource ss1( plain, true, 
        new StreamTransformationFilter( e,
            new StringSink( cipher ),
			StreamTransformationFilter::PKCS_PADDING
        ) // StreamTransformationFilter      
    ); // StringSource

	 // Base64Eecoder	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);


//int B = Sage300prefix.length();
// myfile << "buffer->\n";
//myfile << Sage300prefix;
 //myfile << "encoded->\n";
//myfile << encoded;
Sage300prefix.append(encoded);
//Sage300prefix = Sage300prefix+UriEncode(encoded);
	int L = Sage300prefix.length();
  size_t length = Sage300prefix.copy(_buffer,L,0);
 _buffer[length+1]='\0';
 // cout << "buffer contains: " << _buffer << '\n';



  myfile << _buffer;
 // myfile << "THis is the Length of buffer "<<L;
 // myfile <<"This is the B"<<B;
  myfile.close();


	return (_buffer);
};