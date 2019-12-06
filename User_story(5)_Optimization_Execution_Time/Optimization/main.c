/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in May 2016
 *
 */

#include <stdio.h>

//#include <avr/io.h>

#include "aes_decrypt.h"
#include "aes_encrypt.h"
#include "aes_schedule.h"


int main(int argc, char *argv[]) {

	register uint8_t i;

	/* 128 bit key */
	 uint8_t key[] = {
		//0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 
		//0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98,
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 

	};

	 uint8_t plaintext[] = {
		//0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
		//0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
	};

 
	 uint8_t ciphertext[AES_BLOCK_SIZE];
	
	uint8_t roundkeys[AES_ROUND_KEY_SIZE];

	// key schedule
	aes_key_schedule_128(key, roundkeys);

	// encryption
	
	aes_encrypt_128(roundkeys, plaintext, ciphertext);
	aes_decrypt_128(roundkeys, ciphertext, ciphertext);

	for (i = 0; i < AES_BLOCK_SIZE; i++) {
		if ( ciphertext[i] != plaintext[i] ) { break; }
	}

	// decryption	
	return 0;
}
