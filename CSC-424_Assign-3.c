#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function to generate a random symmetric key
void generateSymmetricKey(unsigned char *key, int key_size) {
    RAND_bytes(key, key_size);
}

// Function to encrypt data using AES with a symmetric key
void encryptAES(const char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char*)plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

    EVP_CIPHER_CTX_free(ctx);
}

// Function to decrypt data using AES with a symmetric key
void decryptAES(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
    int len;
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);

    EVP_CIPHER_CTX_free(ctx);

    return;
}

// Function to sign a message hash using a private key
void signMessageHash(unsigned char *hash, int hash_len, EVP_PKEY *private_key, unsigned char *signature) {
    // Implement signing here using private_key and store the result in signature
}

// Function to verify a message hash using a public key and signature
int verifyMessageHash(unsigned char *hash, int hash_len, EVP_PKEY *public_key, unsigned char *signature) {
    // Implement verification here using public_key and return 1 if verified, 0 otherwise
}

int main() {
    // Sender Side

    // Assume these are provided or generated: sender_private_key, receiver_public_key
    EVP_PKEY *sender_private_key, *receiver_public_key;

    // Message to be sent
    char message[] = "Hello, secure world!";

    // Step 1: Hash the message
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    unsigned int decrypted_message_len;
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(md_ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(md_ctx, message, strlen(message));
    EVP_DigestFinal_ex(md_ctx, hash, &hash_len);
    EVP_MD_CTX_free(md_ctx);

    // Step 2: Encrypt the hash using the sender's private key
    unsigned char signature[EVP_PKEY_size(sender_private_key)];
    signMessageHash(hash, hash_len, sender_private_key, signature);

    // Step 3: Generate a symmetric key
    unsigned char symmetric_key[32]; // Assuming AES-256
    generateSymmetricKey(symmetric_key, sizeof(symmetric_key));

    // Step 4: Encrypt the message with AES using the symmetric key
    unsigned char ciphertext[1024]; // Adjust size as needed
    encryptAES(message, strlen(message), (unsigned char*)symmetric_key, ciphertext);

    // Step 5: Encrypt the key generated in step 3 using the receiver's public key
    unsigned char encrypted_key[256]; // Adjust size as needed
    encryptAES(symmetric_key, sizeof(symmetric_key), (unsigned char*)receiver_public_key, encrypted_key);

    // Combine steps 4, 2, and 5 for the final message
    // Assuming you have a structure or format for the final message
    // Concatenate ciphertext, signature, and encrypted_key as needed

    // Receiver Side

    // Assume these are provided: receiver_private_key, sender_public_key
    EVP_PKEY *receiver_private_key, *sender_public_key;

    // Assume you have received the final message and extracted ciphertext, signature, and encrypted_key

    // Step 1: Decrypt the symmetric key in step 5 using the receiver's private key
    unsigned char decrypted_key[32]; // Assuming AES-256
    decryptAES(encrypted_key, sizeof(encrypted_key), (unsigned char*)(const char*)receiver_private_key, decrypted_key);

    // Step 2: Decrypt the message in step 4 using the symmetric key obtained in step 1
    unsigned char decrypted_message[1024]; // Adjust size as needed
    decryptAES(ciphertext, sizeof(ciphertext), (unsigned char*)decrypted_key, decrypted_message);

    // Step 3: Decrypt the signature in step 5 using the sender's public key
    if (verifyMessageHash(hash, hash_len, sender_public_key, signature)) {
        // Step 4: Hash the message from step 2
        unsigned char received_hash[EVP_MAX_MD_SIZE];
        unsigned int received_hash_len;
        EVP_MD_CTX *received_md_ctx = EVP_MD_CTX_new();
        EVP_DigestInit_ex(received_md_ctx, EVP_sha256(), NULL);
        EVP_DigestUpdate(received_md_ctx, decrypted_message, decrypted_message_len);
        EVP_DigestFinal_ex(received_md_ctx, received_hash, &received_hash_len);
        EVP_MD_CTX_free(received_md_ctx);

        // Step 5: Compare the hashes from steps 3 and 4
        if (memcmp(hash, received_hash, hash_len) == 0) {
            printf("Message authenticated.\n");
            // Print or use the decrypted_message as needed
        } else {
            printf("Message authentication failed.\n");
        }
    } else {
        printf("Signature verification failed.\n");
    }
    
    return 0;
}
