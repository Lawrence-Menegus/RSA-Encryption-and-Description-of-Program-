// Lawrence Menegus 
// Math 220 Discrete Math 
// Discription: This program encrypts plaintext to ciphertext and  decrypts a ciphertext to plaintext using the RSA Algorthm
// Explaination of RSA Algorthm:   RSA encryption is a public-key encryption scheme that allows secure transmission of messages
// over the internet. It was developed by Ron Rivest, Adi Shamir, and Leonard Adleman in 1971.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// Function to calculate the modular multiplicative inverse using the extended Euclidean algorithm
int modInverse(int a, int m)
{
    int mod = m;
    int t, q;
    int x0 = 0, x1 = 1;

    while (a > 1)
    {
        q = a / m;
        t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
    {
        x1 += mod;
    }

    return x1;
}

// Function to calculate modular exponentiation (base^exp mod mod)
long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            // Multiply result by base and take modulo mod
            result = (result * base) % mod;
        }

        // Square base and take modulo mod
        base = (base * base) % mod;

        // Halve the exponent
        exp = exp / 2;
    }
    return result;
}

int main()
{
    int p = 17;
    int q = 11;
    cout << "Primes numbers are 17 and 11" << endl;

    // Calculate n, the product of two prime numbers
    int n = p * q;

    // Calculate the totient (phi) of n
    int phi = (p - 1) * (q - 1);

    // You can choose a suitable encryption exponent (commonly 7)
    int e = 7;

    // Calculate the private key (d) using the modInverse function
    int d = modInverse(e, phi);

    cout << endl;
    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;
    cout << endl;

    // Clear the newline character from the input buffer
    cout << "Message you want to encrypt: ";
    string msg;
    getline(cin, msg);

    vector<int> cipher(msg.size());
    for (int i = 0; i < msg.size(); i++)
    {

        // Use ASCII value of the character
        int m = static_cast<int>(msg[i]);

        // Encrypt each character in the message using the public key
        cipher[i] = modPow(m, e, n);

    }

    cout << endl;
    cout << "Encrypted Message: ";
    for (int i = 0; i < cipher.size(); i++) 
    {
        cout << cipher[i] << " ";
    }

    cout << endl;
    cout << "Enter the private key (d) for decryption: ";
    int user_d;
    cin >> user_d;

    string decrypted_msg;
    for (int i = 0; i < cipher.size(); i++)
    {
        int c = cipher[i];

        // Decrypt each character in the cipher using the user-provided private key
        int decrypted_char = modPow(c, user_d, n);
        decrypted_msg += static_cast<char>(decrypted_char);
    }

    cout << "Original Message Sent: " << decrypted_msg << endl;

    string j; 
    cin >> j; 
    cout << endl;
    cout << "Claim: RSA Algorthm Works" << endl;
    cout << endl;
    cout << "Proof: ";
    cout << "Key Generation:" << endl;
    cout << "Choose two distinct prime numbers : p = 17 and q = 11. " << endl;
    cout << "Calculate n = p * q = 17 * 11 = 187. " << endl;
    cout << "Calculate the totient(φ) of n : φ(n) = (p - 1)(q - 1) = (17 - 1)(11 - 1) = 16 * 10 = 160." << endl;
    cout << "Choose a public exponent e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1. A common choice is e = 7 because it is relatively prime to 160" << endl;
    cout << "Calculate the private exponent d, which is the modular multiplicative inverse of e modulo φ(n)" << endl;
    cout << "You can use the modInverse function from your code to calculate d.In this case, d ≡ 23 (mod 160)" << endl;
    cout << endl;
    cout << "Encryption:" << endl;
    cout << "Let's say you want to encrypt the message HELLO. First, convert each character to its ASCII value: " << endl;
    cout << "H : 72 " << endl;
    cout << "E : 69 " << endl;
    cout << "L : 76 " << endl;
    cout << "L : 76 " << endl;
    cout << "O : 79 " << endl;
    cout << endl;
    cout << "Encrypt each ASCII value separately using the public key(e, n) : " << endl;
    cout << "Encrypted H: c1 ≡ 72^7 (mod 187) = 30 " << endl;
    cout << "Encrypted E: c2 ≡ 69^7 (mod 187) = 86 " << endl;
    cout << "Encrypted L (first): c3 ≡ 76^7 (mod 187) = 32 " << endl;
    cout << "Encrypted L (second) : c4 ≡ 76 ^ 7 (mod 160) = 48 " << endl;
    cout << "Encrypted O: c5 ≡ 79^7 (mod 187) = 139" << endl;
    cout << "The encrypted message is the sequence of these ciphertext values: 30 86 32 32 13 9" << endl;
    cout << endl;
    cout << "Decryption : " << endl;
    cout << "To decrypt the message, you'll use the private key (d, n): " << endl;
    cout << "Decrypted H : m1 ≡ 83 ^ 23 (mod 187) = 72 " << endl;
    cout << "Decrypted E : m2 ≡ 131 ^ 23 (mod 187) = 69 " << endl;
    cout << "Decrypted L (first) : m3 ≡ 46 ^ 23 (mod 187) = 76 " << endl;
    cout << "Decrypted L (second) : m4 ≡ 46 ^ 23 (mod 187) = 76 " << endl;
    cout << "Decrypted O : m5 ≡ 102 ^ 23 (mod 187) = 79 " << endl;
    cout << endl;
    cout << "Convert the decrypted ASCII values back to characters : " << endl;
    cout << "Decrypted H : 'H' " << endl;
    cout << "Decrypted E : 'E' " << endl;
    cout << "Decrypted L(first) : 'L' " << endl;
    cout << "Decrypted L(second) : 'L' " << endl;
    cout << "Decrypted O : 'O' " << endl;
    cout << " The original message is HELLO." << endl;

}