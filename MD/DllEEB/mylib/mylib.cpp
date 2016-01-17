// ECB.cpp : Defines the exported functions for the DLL application.
//
# _USE_CRT_SECURE_NO_WARNINGS
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
#include <string.h>



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

void CryptoEncryptTestUnit(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl, int Index)
{
	
  FILE * pFile;
  pFile = fopen ("myLog.txt","w+");
  if (pFile!=NULL)
  {
    pFile = fopen("myLog.txt",  "wb");
	fclose (pFile);
  }
  
  
  
  
  ofstream myfile;
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
	
	

	Sage300prefix = Sage300prefix+UriEncode(encoded);

	
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
	
	

	Sage300prefix = Sage300prefix+UriEncode(encoded);

	
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
	
	
	
	
	
	
	
	
	
	
	
	default:
	myfile.close();
	break; 

}


};
char  * CryptoEncrypt(char *_buffer, int _LenOfbuffer,char *_url,int _lenOfurl)
{
	/*************************************************STEP 1 Iinitialize Vars ***************************************************************************************/
	// Rebuilding A new Logic that has to be deployed for lingae detection problem 
	// String holder of original URL /-Encryption and -/ Encoding is left on this. 
	string plain(_url,_lenOfurl);
	string Sage300prefix = "https://pgmorww11v.paigroup.corp/DDP.Web/Home/Sage300/?key=";
	string cipher = "";
	string   encoded, recovered;
	const byte key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	size_t myArraySize = sizeof(key);
	/*************************************************STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with***************/
	encoded.clear();
	ECB_Mode< AES >::Encryption e;
	e.SetKey(key, myArraySize );
	/**************************************************STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt **************************/
	// Build CNC AES Padding Encyption using Crypto++ filters 
	cipher.clear();
	StringSink *_SSObject = new StringSink( cipher );
	StreamTransformationFilter *_STFilter  = new StreamTransformationFilter( e,_SSObject,StreamTransformationFilter::PKCS_PADDING);
	// Use encryption and Padding
    StringSource ss1( plain, true,_STFilter); 
	/**************************************************STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address **********************/
	// Base64Eecoder	
	StringSource ss2( cipher, true,
		new Base64Encoder(
			new StringSink( encoded )
    ) // HexEncoder // Base64Encoder
	);
	/**************************************************STEP 5 Add Http Address of Sage 100 server front of the meant **************************************************************/
	Sage300prefix = Sage300prefix+UriEncode(encoded);
	/**************************************************STEP 6 Filing the buffer peoperly ******************************************************************************************/
	memset (_buffer,0,_LenOfbuffer);
	int L = Sage300prefix.length();
	size_t length = Sage300prefix.copy(_buffer,L,0);
	_buffer[L+1]='\0';
	
	/**************************************************STEP 7 Return the address of _buffer to the Dll Tester To Avoid Multi Threading MD C runtime Linking issues********************/
	return (_buffer);
	
	
	
	
	
	
	
	
	/*
	
	
	
    // Build Encyption 
	
	
	

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
*/

	
};