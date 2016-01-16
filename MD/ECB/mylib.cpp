#include "mylib.h"


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

  int  helloworld(char *T)
{
	
    cout<<T<<endl;
    return 42;
}