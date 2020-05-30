#include "Base64.h"
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

int base64_encode(char *str,int str_len,char *encode,int *encode_len){
    BIO *bmem,*b64;
    BUF_MEM *bptr;
    b64=BIO_new(BIO_f_base64());
    BIO_set_flags(b64,BIO_FLAGS_BASE64_NO_NL);
    bmem=BIO_new(BIO_s_mem());
    b64=BIO_push(b64,bmem);
    BIO_write(b64,str,str_len); //encode
    BIO_flush(b64);
    BIO_get_mem_ptr(b64,&bptr);
	char *buffer = new char[bptr->length + 1];
	memcpy(buffer, bptr->data, bptr->length);
	buffer[bptr->length] = 0;
	if (encode == NULL)
		*encode_len = bptr->length;
	else
		memcpy(encode, buffer, bptr->length);
	delete[] buffer;
    BIO_free_all(b64);
    return 0;
}
int base64_decode(char *str,int str_len,char *decode,int* decode_buffer_len){
    int len=0;
    BIO *b64,*bmem;
	char * buffer = new char[str_len+1];
	memset(buffer, 0, str_len);

    b64=BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);//默认OpenSSL的base64编解码会每64个字节做换行操作，这里取消换行
    bmem=BIO_new_mem_buf(str,str_len);
    bmem=BIO_push(b64,bmem);
    len=BIO_read(bmem,buffer,str_len);
    buffer[len]=0;
	if (decode == NULL)
		*decode_buffer_len = len;
	else
		memcpy(decode, buffer, len);
	delete[] buffer;
    BIO_free_all(bmem);
    return 0;
}


