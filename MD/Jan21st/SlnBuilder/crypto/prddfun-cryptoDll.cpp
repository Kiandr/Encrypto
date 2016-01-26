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

// For testing - TODO remove at some point 
void CryptoEncryptTestUnit(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl, const unsigned char  *_Key, int _myArraySize, int Index)
{
	cout<<"This was a typo!";
  FILE * pFile;
  pFile = fopen ("myLog.txt","w+");
  if (pFile!=NULL)
  {
    pFile = fopen("myLog.txt",  "wb");
	fclose (pFile);
  }
  
  
  
  
  ofstream myfile; 
  ofstream myfileReader;
 // myfile.open ("myLog.txt");

switch (Index){
	
	
	case 1: 
	{
	myfile.open ("myLog.txt");
	myfile << "---------------------------------BeginTestCase1:STEP 1 Iinitialize Vars-------------------------------\n";
	
	
	myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "cipher = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "encoded = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "recovered = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "key = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "myArraySize = ";
	myfile << myArraySize;
	myfile << "\n";
	myfile <<"---------------------END OF CASE 1------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
	
	
	
	
	case 2: 
	{
	myfile.open ("myLog.txt");
	myfile << "-----------BeginTestCase2: 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	

	
	
	myfile << "\n";
	myfile <<"---------------------END OF CASE 2------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
	
	
	case 3: 
	{
	myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase3: Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt ----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	myfile << "[cipher.clear();]=";
	myfile << cipher;
	myfile << "\n";
	
	
	StringSink *_SSObject = new StringSink( cipher );
	myfile << "[StringSink *_SSObject = new StringSink( cipher );]=";
	myfile << _SSObject;
	myfile << "\n";
	
	
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);

	myfile << "[StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);]=";
	myfile << _STFilter;
	myfile << "\n";
	

	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	
	
	myfile << "[StringSource ss1( plain, true,_STFilter); ]=";
	myfile <<  "IT IS A VOID FUNCTION";
	myfile << "\n";
	
	
	
	/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/

	
	
	myfile << "\n";
	myfile <<"---------------------END OF CASE 3------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
		
	
	
		case 4: 
	{
	myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase4: Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address ----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	myfile << "[cipher.clear();]=";
	myfile << cipher;
	myfile << "\n";
	
	
	StringSink *_SSObject = new StringSink( cipher );
	myfile << "[StringSink *_SSObject = new StringSink( cipher );]=";
	myfile << _SSObject;
	myfile << "\n";
	
	
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);

	myfile << "[StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);]=";
	myfile << _STFilter;
	myfile << "\n";
	

	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	
	
	myfile << "[StringSource ss1( plain, true,_STFilter); ]=";
	myfile <<  "IT IS A VOID FUNCTION";
	myfile << "\n";
	
	
	
		/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	
	
		myfile << "[cipher before StringSource ss2 compilation]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded before StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	
	myfile << "[cipher after StringSource ss2 compilation  ]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded after StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/

	
	
	myfile << "\n";
	myfile <<"---------------------END OF CASE 4------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
	
	
	
	
		case 5: 
	{
	myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase5: Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address ----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	myfile << "[cipher.clear();]=";
	myfile << cipher;
	myfile << "\n";
	
	
	StringSink *_SSObject = new StringSink( cipher );
	myfile << "[StringSink *_SSObject = new StringSink( cipher );]=";
	myfile << _SSObject;
	myfile << "\n";
	
	
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);

	myfile << "[StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);]=";
	myfile << _STFilter;
	myfile << "\n";
	

	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	
	
	myfile << "[StringSource ss1( plain, true,_STFilter); ]=";
	myfile <<  "IT IS A VOID FUNCTION";
	myfile << "\n";
	
	
	
		/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	
	
		myfile << "[cipher before StringSource ss2 compilation]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded before StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	
	myfile << "[cipher after StringSource ss2 compilation  ]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded after StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/

	
	myfile << "[Sage300prefix before Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded before Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	

	Sage300prefix = Sage300prefix+urlEncode(encoded);

	
	myfile << "[Sage300prefix after Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded after Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
		

	/**************************************************STEP 6 Filing the buffer peoperly ******************************************************************************************/

	
	
	myfile << "\n";
	myfile <<"---------------------END OF CASE 5------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
	
	
	
			case 6: 
	{
	myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase5: Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address ----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	myfile << "[cipher.clear();]=";
	myfile << cipher;
	myfile << "\n";
	
	
	StringSink *_SSObject = new StringSink( cipher );
	myfile << "[StringSink *_SSObject = new StringSink( cipher );]=";
	myfile << _SSObject;
	myfile << "\n";
	
	
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);

	myfile << "[StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);]=";
	myfile << _STFilter;
	myfile << "\n";
	

	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	
	
	myfile << "[StringSource ss1( plain, true,_STFilter); ]=";
	myfile <<  "IT IS A VOID FUNCTION";
	myfile << "\n";
	
	
	
		/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	
	
		myfile << "[cipher before StringSource ss2 compilation]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded before StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	
	myfile << "[cipher after StringSource ss2 compilation  ]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded after StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/

	
	myfile << "[Sage300prefix before Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded before Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	

	Sage300prefix = Sage300prefix+urlEncode(encoded);

	
	myfile << "[Sage300prefix after Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded after Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
		

	/**************************************************STEP 6 Filing the buffer peoperly ******************************************************************************************/
	
	myfile << "[buffer befor  memset (_buffer,0,_LenOfbuffer); ]=";
	myfile <<  _buffer;
	myfile << "\n";
	
	myfile << "[_LenOfbuffer befor  memset (_buffer,0,_LenOfbuffer);]=" ;
	myfile <<  _LenOfbuffer;
	myfile << "\n";
	
	
	memset (_buffer,0,_LenOfbuffer);
	
	myfile << "[buffer after  memset (_buffer,0,_LenOfbuffer); ]=";
	myfile <<  _buffer;
	myfile << "\n";
	
	myfile << "[_LenOfbuffer after  memset (_buffer,0,_LenOfbuffer);]=" ;
	myfile <<  _LenOfbuffer;
	myfile << "\n";
	
	
	
	
	int L = Sage300prefix.length();
	
	myfile << "[Sage300prefix.length()]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	myfile << "[L]=" ;
	myfile <<  L;
	myfile << "\n";
	
	
	
	myfile << "[size_t length before Sage300prefix.copy(_buffer,L,0 ]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	size_t length = Sage300prefix.copy(_buffer,L,0);
	
	myfile << "[size_t length after Sage300prefix.copy(_buffer,L,0 ]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	
	
	myfile << "[ _buffer befor  _buffer[L+1]='\0';]=" ;
	myfile <<  _buffer;
	myfile << "\n";
	
	_buffer[L+1]='\0';
	
	myfile << "[ _buffer after  _buffer[L+1]='\0';]=" ;
	myfile <<  _buffer;
	myfile << "\n";
	
	/**************************************************STEP 7 Return the address of _buffer to the Dll Tester To Avoid Multi Threading MD C runtime Linking issues********************/

	
	
	myfile << "\n";
	myfile <<"---------------------END OF CASE 6------------------------------------------------------------------------\n";
	myfile.close();
	break;
	}
	
	case 7:
	{
		myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase  8: Testing Case 8 ----------\n";
	
		myfile << "[_buffer] =";
	myfile << _buffer;
	myfile << "\n";
	myfile << "[_LenOfbuffer] = ";
	myfile << _LenOfbuffer;
	myfile << "\n";
	myfile << "[_url]=";
	myfile << _url;
	myfile << "\n";
	myfile << "[_lenOfurl]=";
	myfile << _lenOfurl;
	myfile << "\n";
	
	
	
	string plain(_url,_lenOfurl-1);
	myfile << "[string plain(_url,_lenOfurl)]=";
	myfile << plain;
	myfile << "\n";
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	myfile << "[string Sage300prefix)]=\n";
	myfile << Sage300prefix;
	myfile << "\n";
	
	
	string cipher = "";
	string   encoded, recovered;
	myfile << "[cipher] = ";
	myfile << cipher;
	myfile << "\n";
	myfile << "[encoded] = ";
	myfile << encoded;
	myfile << "\n";
	myfile << "[recovered] = ";
	myfile << recovered;
	myfile << "\n";
	
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	myfile << "[key] = ";
	myfile << key;
	myfile << "\n";
	
	size_t myArraySize = sizeof(key);
	myfile << "[myArraySize] = ";
	myfile << myArraySize;
	myfile << "\n";
	
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	
	encoded.clear();
	myfile << "[encoded.clear()]=";
	myfile << encoded;
	myfile << "\n";
	
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	
	myfile << "[ECB_Mode< AES >::Encryption e;]=";
	//myfile << e.SetKey(key, myArraySize );
	myfile << "\n";
	
	
	myfile << "[void.void(key, void )]= ";
	myfile << key;
	myfile << "\n";
	
	myfile << "[void.void(void, myArraySize )]=";
	myfile << myArraySize;
	myfile << "\n";
	
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	myfile << "[cipher.clear();]=";
	myfile << cipher;
	myfile << "\n";
	
	
	StringSink *_SSObject = new StringSink( cipher );
	myfile << "[StringSink *_SSObject = new StringSink( cipher );]=";
	myfile << _SSObject;
	myfile << "\n";
	
	
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);

	myfile << "[StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);]=";
	myfile << _STFilter;
	myfile << "\n";
	

	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	
	
	myfile << "[StringSource ss1( plain, true,_STFilter); ]=";
	myfile <<  "IT IS A VOID FUNCTION";
	myfile << "\n";
	
	
	
		/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	
	
		myfile << "[cipher before StringSource ss2 compilation]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded before StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	
	myfile << "[cipher after StringSource ss2 compilation  ]=";
	myfile <<  cipher;
	myfile << "\n";
	
	myfile << "[encoded after StringSource ss2 compilation]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	
	
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/

	
	myfile << "[Sage300prefix before Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded before Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
	
	

	Sage300prefix = Sage300prefix+urlEncode(encoded);

	
	myfile << "[Sage300prefix after Sage300prefix+UriEncode(encoded); ]=";
	myfile <<  Sage300prefix;
	myfile << "\n";
	
	myfile << "[encoded after Sage300prefix+UriEncode(encoded)]=" ;
	myfile <<  encoded;
	myfile << "\n";
		

	/**************************************************STEP 6 Filing the buffer peoperly ******************************************************************************************/
	
	myfile << "[buffer befor  memset (_buffer,0,_LenOfbuffer); ]=";
	myfile <<  _buffer;
	myfile << "\n";
	
	myfile << "[_LenOfbuffer befor  memset (_buffer,0,_LenOfbuffer);]=" ;
	myfile <<  _LenOfbuffer;
	myfile << "\n";
	
	
	memset (_buffer,0,_LenOfbuffer);
	
	myfile << "[buffer after  memset (_buffer,0,_LenOfbuffer); ]=";
	myfile <<  _buffer;
	myfile << "\n";
	
	myfile << "[_LenOfbuffer after  memset (_buffer,0,_LenOfbuffer);]=" ;
	myfile <<  _LenOfbuffer;
	myfile << "\n";
	
	
	
	
	int L = Sage300prefix.length();
	
	myfile << "[Sage300prefix.length()]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	myfile << "[L]=" ;
	myfile <<  L;
	myfile << "\n";
	
	
	
	myfile << "[size_t length before Sage300prefix.copy(_buffer,L,0 ]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	size_t length = Sage300prefix.copy(_buffer,L,0);
	
	myfile << "[size_t length after Sage300prefix.copy(_buffer,L,0 ]=" ;
	myfile <<  Sage300prefix.length();
	myfile << "\n";
	
	
	
	myfile << "[ _buffer befor  _buffer[L+1]='\0';]=" ;
	myfile <<  _buffer;
	myfile << "\n";
	
	_buffer[L+1]='\0';
	
	myfile << "[ _buffer after  _buffer[L+1]='\0';]=" ;
	myfile <<  _buffer;
	myfile << "\n";
	
	/**************************************************STEP 8 RReading URL Encoded from An Other Algorithm********************/
/*
	string EncryptedRight; 
	myfileReader.open ("C:\GitHub\Encrypto\EncryptedOriginal.txt");
	if (myfile.is_open())
	{
		if (  (myfile,EncryptedRight) )
		{
		cout << EncryptedRight << '\n';
		}
	myfileReader.close();
	}
	
	myfile << "[EncryptedRight]=" ;
	myfile <<  EncryptedRight;
	myfile << "\n";
	*/
	cout<<"Closing the file;";
	myfile << "\n";
	myfile <<"---------------------END OF CASE 7------------------------------------------------------------------------\n";
	myfile.close();
	break;

	}
	
	case 8: {
		
	myfile.open ("myLog.txt");
	myfile << "-----------  BeginTestCase  8: Testing Case 8 ----------\n";	
		
		/*************************************************STEP 1 Iinitialize Vars ***************************************************************************************/
	// Rebuilding A new Logic that has to be deployed for lingae detection problem 
	// String holder of original URL /-Encryption and -/ Encoding is left on this. 
	string plain(_url,_lenOfurl);
	//string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	string cipher = "";
	string   encoded, recovered;
	string UriEncoded = "";
	//const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	//size_t myArraySize = sizeof(key);
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	encoded.clear();
	ECB_Mode< AES >::Encryption e;
	e.SetKey(_Key, _myArraySize );
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
/*	cipher.clear();
	StringSink *_SSObject = new StringSink( cipher );
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);
	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	*/
		// Use encryption and Padding
     StringSource ss1( plain, true, 
         new StreamTransformationFilter( e,
             new StringSink( cipher ),
			 StreamTransformationFilter::PKCS_PADDING
         ) // StreamTransformationFilter      
     ); // StringSource

	/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/
	// Sage300prefix = urlEncode(encoded);
	 UriEncoded = urlEncode(encoded);
	/**************************************************STEP 6 Filing the buffer peoperly ******************************************************************************************/
	memset (_buffer,0,_LenOfbuffer);
	int L = UriEncoded.length();
	memcpy(_buffer,UriEncoded.c_str(),L);
	_buffer[L+1]='\0';
		
	myfile << _buffer;		
		
			cout<<"Closing the file;";
	myfile << "\n";
	myfile <<"---------------------END OF CASE 7------------------------------------------------------------------------\n";
	myfile.close();
	break;
		
	}
	
	
	

	
	
	
	default:
	myfile.close();
	break; 

}


};

// SEE HEADER
char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,const char *_url,int _lenOfurl, const byte *_Key,int _myArraySize)
{
    // Turning a c-style string to c++ string
	string plain(_url,_lenOfurl);
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	string cipher = "";
	string encoded;
	string UriEncoded = "";
	// Generate an AES ECB Encryption Key from const unsigned char key[]. Its a Secret Key hard coded in view that Sage 100 works 
	encoded.clear();
	ECB_Mode< AES >::Encryption encr;
	encr.SetKey(_Key, _myArraySize );
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
	UriEncoded = Sage300prefix + urlEncode (encoded);
    
	// Filling the buffer as NUL character terminated string
    // We know the pointers are not NULL, and if the buffer is too small it will return an empty string, so we can ignore the return code
    (void) strcpy_s(_buffer, _LenOfbuffer, UriEncoded.c_str());
	
	// Return the address of _buffer to the Dll Tester To Avoid Multi Threading MD C runtime Linking issues
	return (_buffer);
};