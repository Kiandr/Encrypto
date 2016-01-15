// main c file: 
/*#include "stdio.h"
#include "prddfunCrypto.h"



int main(){
static char _buffer[500];
static char _url[]="http:\\google.com";

Encrypt(_buffer,sizeof(_buffer), _url);

return 0;
};*/


/* No need to include this if you went the module definition
 * route, but you will need to add the function prototype.
 */
#include "mylib.h"
#include <stdio.h>
int main(void)
{
    helloworld();
    return (0);
}