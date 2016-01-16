/* No need to include this if you went the module definition
 * route, but you will need to add the function prototype.
 */
#include "mylib.h"

int main(void)
{
	char _url[] = "businessPartnerId=123;sourceCompanyCode=123;sourceProduct=Sage300;fein=123;ts=2016-01-14T00:21:52.252Z;ec=50;companyName=kian;address1=kian;address2=kian;city=kian;state=AK;zip=Kian;";
//	char _url[] = "test";
    char _buffer[500];
	CryptoEncrypt(_buffer, sizeof(_buffer),_url, sizeof(_url));
	

	printf("%s\n",_buffer);
	
    return (0);
}