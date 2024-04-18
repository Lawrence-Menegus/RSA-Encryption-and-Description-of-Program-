# RSA-Encryption-and-Description-of-Program-

<p> This C++ program implements the RSA algorithm for encrypting plaintext into ciphertext and decrypting ciphertext back into plaintext. RSA (Rivest-Shamir-Adleman) is a widely-used public-key encryption scheme developed in 1977. It relies on the mathematical properties of prime numbers and modular arithmetic for secure communication.</p>

## Features:

<p> Key Generation: The program generates public and private keys necessary for encryption and decryption. It chooses two distinct prime numbers, calculates their product (n), and computes the totient (phi) of n. It then selects a public exponent (e) such that 1 < e < φ(n) and gcd(e, φ(n)) = 1. The private exponent (d) is calculated as the modular multiplicative inverse of e modulo φ(n) </p>                                                                                                                                                          <p> Encryption: Given a plaintext message, each character is converted to its ASCII value and encrypted separately using the public key (e, n). The ciphertext is obtained by raising each ASCII value to the power of e modulo n. </p> 
                                                                                            
<p> Decryption: The ciphertext is decrypted using the private key (d, n). Each ciphertext value is raised to the power of d modulo n to obtain the original ASCII value, which is then converted back to the corresponding character .</p>

  
## Usage:

<p> Compile the program using a C++ compiler.
Run the executable.
Enter the plaintext message to be encrypted.
Provide the private key (d) for decryption.
The program displays the encrypted message and decrypts it back to the original plaintext. </p>


## Example:

### When prompted: 
<p> Original Message: "HELLO"</p>
<p>Public Key (e, n): (7, 187)</p>
<p>Private Key (d, n): (23, 187)</p>
  
<p> Encrypted Message: 30 86 32 32 13 9 </p>

<p> Enter the private key (d) for decryption: 23 </p>
<p> Original Message Sent: "HELLO" </p>
