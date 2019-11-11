// this code is forked from https://github.com/bitdust/tiny-AES128-C/

#ifndef _AES_H_
#define _AES_H_

// #include <cstdint>
#include <stdint.h>

// CBC enables AES128 encryption in CBC-mode of operation and handles 0-padding.
// ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.
#define CBC 1
#define ECB 1


// typedef unsigned char uint8_t;



#ifdef ECB

void AES128_ECB_encrypt(uint8_t *input, const uint8_t *key, uint8_t *output);

void AES128_ECB_decrypt(uint8_t *input, const uint8_t *key, uint8_t *output);

void AES128_ECB_encrypt_buffer(uint8_t *output, uint8_t *input, uint32_t length, const uint8_t *key);

void AES128_ECB_decrypt_buffer(uint8_t *output, uint8_t *input, uint32_t length, const uint8_t *key);

#endif

#ifdef CBC

void AES128_CBC_encrypt_buffer(uint8_t *output, uint8_t *input, uint32_t length, const uint8_t *key, const uint8_t *iv);

void AES128_CBC_decrypt_buffer(uint8_t *output, uint8_t *input, uint32_t length, const uint8_t *key, const uint8_t *iv);

#endif


#endif //_AES_H_