
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/crypto.h>
#include <openssl/err.h>	
#include <openssl/ssl.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <taskLib.h>
#include "openSSLEncryptionDecryption.h"
#include <errnoLib.h>
#define DEBUG
#define ERROR		(-1)
#define OK		0



#define ITERATIONS 1

FILE *pFileInput, *pFileOutput;
int encryptBytesWritten = 0;
int encryptTextLen = 0;
int decryptBytesWritten = 0;
int decryptTextLen = 0;
unsigned char *inBuffer;
unsigned char *encryptedBuffer;
unsigned char *decryptedBuffer;
unsigned int inRead;

/**
 * Comparison of content after Encrypt and Decrypt of passed file
 * @param *iputfp file pointer to be open
 * @return OK or ERROR
 */
int encryptFile(FILE *iputfp) {
	//Get file size
	fseek(iputfp, 0L, SEEK_END);
	int fsize = ftell(iputfp);
	//set back to normal
	fseek(iputfp, 0L, SEEK_SET);
	unsigned char ckey[] = "thikeyisforencryption";
	unsigned char ivec[] = "thiskeyisfortheinputs";
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	int blockSize = EVP_MAX_BLOCK_LENGTH;
	int mallocFSize = fsize + (blockSize - (fsize % blockSize));
	inBuffer = (unsigned char *) malloc(mallocFSize);
	encryptedBuffer = (unsigned char *) malloc(mallocFSize);
	inRead = fread(inBuffer, sizeof(char), fsize, iputfp);
#ifdef DEBUG
	printf(" block size %d\n",blockSize);
	printf(" mallocFSize: %i\n", mallocFSize);
	printf("inRead %d\n", inRead);
#endif

	for (int i = 0; i < ITERATIONS; i++) {
		//Set up Encryption 
		if (!EVP_EncryptInit(&ctx, EVP_aes_128_cbc(), ckey, ivec)) {
			/*ERROR*/
			printf("Error in Encryption Init %s\n", strerror(errnoGet()));
		}

		//Update Encryption 
		if (!EVP_EncryptUpdate(&ctx, encryptedBuffer, &encryptBytesWritten,
				inBuffer, inRead)) {
			/*ERROR*/
			printf("Error in Encryption Update %s\n", strerror(errnoGet()));

		}
		encryptTextLen += encryptBytesWritten;
#ifdef DEBUG
		printf("Input len: %d, encryptTextLen: %d\n", mallocFSize, encryptTextLen);
#endif
		//Encryption Final 
		if (!EVP_EncryptFinal(&ctx, encryptedBuffer + encryptBytesWritten,
				&encryptBytesWritten)) {
			/*ERROR*/
			printf("Error in Encryption Final %s\n", strerror(errnoGet()));
		}
		encryptTextLen += encryptBytesWritten;
#ifdef DEBUG
		printf("Input len: %d, encryptTextLen: %d\n", mallocFSize, encryptTextLen);
#endif
		EVP_CIPHER_CTX_cleanup(&ctx);

}
	return OK;
}


int decryptFile()
{
		unsigned char ckey[] = "thikeyisforencryption";
		unsigned char ivec[] = "thiskeyisfortheinputs";
		EVP_CIPHER_CTX dtx;
		EVP_CIPHER_CTX_init(&dtx);
		for (int i = 0; i < ITERATIONS; i++) 
		{
			//Assign the Malloc for Decrypt based on the Encrypt size + padding
			decryptedBuffer = (unsigned char *) malloc(
					encryptTextLen);

			if (!EVP_DecryptInit(&dtx, EVP_aes_128_cbc(), ckey, ivec))
			{
				/*ERROR*/
				printf("Error in Decryption Init %s\n", strerror(errnoGet()));
			}

			if (!EVP_DecryptUpdate(&dtx, decryptedBuffer, &decryptBytesWritten,
					encryptedBuffer, encryptTextLen)) 
			{
				/*ERROR*/
				printf("Error in Decryption Update %s\n", strerror(errno));
			}
			decryptTextLen += decryptBytesWritten;
	#ifdef DEBUG
			//  printf("Input len: %d, decryptTextLen: %d\n", mallocFSize, decryptTextLen);
	#endif		  

			if (!EVP_DecryptFinal(&dtx, decryptedBuffer + decryptBytesWritten,
					&decryptBytesWritten)) 
			{
				/*ERROR*/
				ERR_print_errors_fp(stderr);
				printf("Error in Decryption Final %s\n", strerror(errnoGet()));
			}
			decryptTextLen += decryptBytesWritten;
	#ifdef DEBUG
			printf("Decrypt Input len: %d, decryptTextLen: %d\n", encryptTextLen, decryptTextLen);
	#endif	
			EVP_CIPHER_CTX_cleanup(&dtx);

			if (0 == memcmp(inBuffer, decryptedBuffer, (inRead))) 
			{
	#ifdef DEBUG
				printf("Success for Iteration %d \n", i);
	#endif
			}
			
			FILE *f_decrypt = fopen("/bd0/decrypt.txt", "wb");
			if(f_decrypt == NULL)
			{
			    printf("ERROR - Failed to open file for writing\n");
			    return(ERROR);
			}

			// Write Buffer
			while(fwrite(decryptedBuffer, 1, inRead, f_decrypt) !=inRead)
			{
			    printf("ERROR - Failed to write %i bytes to file\n", inRead);
			    return(ERROR);
			}
			fclose(f_decrypt);	
		}

		// Close File
		
		free(decryptedBuffer);
		free(inBuffer);
		free(encryptedBuffer);
		return OK;
}
	  
int Test() 

{
	FILE *fd;
	fd =fopen("/bd0/test.txt", "rb");
	encryptFile(fd);
	decryptFile();
	fclose(fd);
	return(OK);
}

