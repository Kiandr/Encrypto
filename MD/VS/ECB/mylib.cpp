// ECB.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "shellapi.h"
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
#include "\..\..\..\..\DD\pr\base\cryptopp-lib\includes\integer.h"


string urlEncode(string str){
    string new_str = "";
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



  char  *CryptoEncrypt(char *_url)
{
	CryptoPP::Integer i;
	//char _url[] = "businessPartnerId=1234;sourceCompanyCode=123;sourceProduct=Sage300;fein=123;ts=2016-01-20T00:21:52.252Z;ec=50;companyName=kian;address1=kian;address2=kian;city=kian;state=AK;zip=Kian;";	
	int _urlLen = (unsigned)strlen(_url);
	string plain(_url,_urlLen);
	//string plain = "businessPartnerId=123;sourceCompanyCode=123;sourceProduct=Sage300;fein=123;ts=2016-01-14T00:21:52.252Z;ec=50;companyName=kian;address1=kian;address2=kian;city=kian;state=AK;zip=Kian;";	
	string cipher = "";
	string   encoded, recovered;
	 const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	// char key[] = {0x35,0x101,0x45,0x114,0x65,0x119,0x114,0x117,0x55,0x33,0x63,0x95,0x65,0x99,0x114,0x117,0x109,0x53,0x103,0x95,0x115,0x87,0x101,0x80,0x54,0x103,0x69,0x74,0x85,0x53,0x56,0x0};
	
	size_t myArraySize = sizeof(key);
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
    // Build Encyption 
	
	

//	byte key[AES::DEFAULT_KEYLENGTH];
	//prng.GenerateBlock(key, sizeof(key));

	//string plain = "ECB Mode Test";
//	string cipher, encoded, recovered;

	/*********************************\
	\*********************************/

	// Pretty print key
	encoded.clear();
	/*StringSource(key, sizeof(key), true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	cout << "key: " << encoded << endl;
*/

		ECB_Mode< AES >::Encryption e;
		e.SetKey(key, myArraySize );


	/*****************************************\
   \*****De-Composing the String Source******/
cipher.clear();
StringSink *_SSObject = new StringSink( cipher );

StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);


	// Use encryption and Padding
     StringSource ss1( plain, true,_STFilter); 




	 // Base64Eecoder	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);

Sage300prefix = Sage300prefix+urlEncode(encoded);
/*
cout<<Sage300prefix<<endl;

	ofstream myfile;
  myfile.open ("example.txt");
  myfile << Sage300prefix;
  myfile.close();
*/


return (char*)Sage300prefix.c_str();
}