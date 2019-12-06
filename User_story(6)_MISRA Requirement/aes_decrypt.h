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
#ifndef AES_128_DECRYPT_H
#define AES_128_DECRYPT_H


#define AES_BLOCK_SIZE      16U
#define AES_ROUNDS          10U  /* 12, 14 */
#define AES_ROUND_KEY_SIZE  176U /* AES-128 has 10 rounds, and there is a AddRoundKey before first round. (10+1)x16=176. */

/**
 * @purpose:            Decryption. The length of plain and cipher should be one block (16 bytes).
 *                      The ciphertext and plaintext may point to the same memory
 * @par[in]roundkeys:   round keys
 * @par[in]ciphertext:  cipher text
 * @par[out]plaintext:  plain text
 */
void aes_decrypt_128( const uint8_t *roundkeys, const uint8_t *ciphertext, uint8_t *plaintext);
#endif
