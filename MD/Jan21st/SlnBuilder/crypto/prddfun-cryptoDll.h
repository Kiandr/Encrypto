/*--------------------------------------------------------------------

    File        :   prddfun-cryptoDll.h
    Purpose     :   cryptographic encoding of a string for Direct Deposit
                    Application
    Copyright (c) 2016 Sage Software, Inc.  All rights reserved.

--------------------------------------------------------------------*/
#ifndef PRDDFUN_CRYPTODLL_H
#define PRDDFUN_CRYPTODLL_H

// Encrypt a url using a given key, into a given buffer
//
// Parameters:
// _buffer a pointer to a buffer of length _LenOfbuffer, into which the result will be placed.
// _LenOfbuffer the length of _buffer. If this is too small an empty string will be returned.
// _stemURLapply a pointer to the stem of the url into which the encrypted data will be placed
// _url a pointer to the url to be encrypted
// _Key a pointer to an array of bytes containing the secret key, that is being used for encryption
// _KeySize the length of _Key

__declspec(dllexport) char *CryptoEncrypt(char *_buffer, int _LenOfbuffer, const char *_stemURLapply, const char *_url, const unsigned char *_Key, int _KeySize);

#endif
