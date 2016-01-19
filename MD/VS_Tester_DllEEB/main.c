/* No need to include this if you went the module definition
 * route, but you will need to add the function prototype.
 */
#include "mylib.h"
#include "stdio.h"
int main(void)
{
	
	unsigned char key[] = {35,101,45,114,65,119,114,117,55,33,63,95,65,99,114,117,109,53,103,95,115,87,101,80,54,103,69,74,85,53,56,0};
	
	char _url[] = "businessPartnerId=1234;sourceCompanyCode=123;sourceProduct=Sage300;fein=123;ts=2016-01-20T00:21:52.252Z;ec=50;companyName=Davoudi;address1=kian;address2=kian;city=kian;state=AK;zip=Kian;";
//	char _url[] = "test";
    char _buffer[500];
	int prt ;
	//CryptoEncryptTestUnit(_buffer, sizeof(_buffer),_url, sizeof(_url), key, sizeof(key),0);
	printf("Enter a number");
	scanf("%d",&prt);
	CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url), key, sizeof(key));
	while ((prt<9) && (prt>0))	
	{
	
	// Test Case 1: 
	CryptoEncryptTestUnit(_buffer, sizeof(_buffer),_url, sizeof(_url), key, sizeof(key),prt);
	
	// Test Case 2: 
	// Uncomment to test initialization test. STEP 2 Generate an AES ECB Encryption Key from const bute key[] ** Its a Secret Key that Sage 100 works with
///	CryptoEncryptTestUnit(_buffer, sizeof(_buffer),_url, sizeof(_url), 2);
	
	// Test Case 3: 
	// Uncomment to test initialization test. STEP 3 Strign Source uses the Plain text and the 'e' and the PKCS padding mechanisim to encrypt
//	CryptoEncryptTestUnit(_buffer, sizeof(_buffer),_url, sizeof(_url), 3);
	
	// Test Case 4: 
	// Uncomment to test initialization test. STEP 4 Base62Encode they cipher and put into Encoded string*****Then UriEncode this and http address 
//	CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url), 4);
	
	// Test Case 5:
	// Uncomment to test initialization test. STEP 5 Add Http Address of Sage 100 server front of the meant 	
//	CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url), 5);
	
	// Test Case 6: 
	// Uncomment to test initialization test. STEP 6 Filing the buffer peoperly 	
//	CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url), 6);
	
	
	// The Rgression Test Case 6: 
//CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url));
	

//	printf("%s\n",_buffer);

	printf("Enter an other key:");
	scanf("%d",&prt);
  }
	printf("Closing Unit Test: ");
    return (0);
}