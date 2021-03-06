#include <bits/stdc++.h>

using namespace std;

const int ENCRYPT_CMD_LEN = 97;
const int CHECKSUM_ENCRYPT = 100;
char c_original[ENCRYPT_CMD_LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,./<>?;:\'\"[]\\{}|=-+_)(*&^%$#@!~` ";
char c_encrypt[ENCRYPT_CMD_LEN] = "yr(GRMJ1#\'Fme]Kc3<0`{QCBa,$pDx2[h;g8_./unU|+fELqYN~}7l>=dzX?WkjTVH%@b6s9viIo4:v5Aw&O*tP!\\S^)Z\" -";


bool is_prime(int number) {
    int squareRoot = sqrt(number);
    for (unsigned int i = 2; i < squareRoot; i++) {
        if (number % i == 0) {
            return number;
        }
    }
    return true;
}

class SecurityAlgorithm {
  private:
    std::string cipherText;
    std::string plainText;
  public:
    SecurityAlgorithm(std::string plainText) {
        plainText = plainText;
    }

    std::string encrypt_monoalphabetic(std::string);
    std::string decrypt_monoalphabetic(std::string);
    std::string encrypt_ceasar(std::string, int);
    std::string decrypt_ceasar(std::string, int);
    std::string init_rsa(int, int, int& e, int& d);
    friend std::string encrypt_rsa(std::string, int, int);
    friend std::string decypt_rsa(std::string, int, int, int);
}

std::string SecurityAlgorithm::encrypt_monoalphabetic(std::string plainText) {
    for (unsigned int i = 0; i < plainText.length(); i++) {
        for (unsigned int j = 0; j < ENCRYPT_CMD_LEN; j++) {
            if (plainText[i] == c_original[j]) {
                plainText[i] = c_encrypt[j];
                break;
            }
        }
    }
    return plainText;
}

std::string SecurityAlgorithm::decrypt_monoalphabetic(std::string cipherText) {
    for (unsigned int i = 0; i < cipherText.length(); i++) {
        for (unsigned int j = 0; j < ENCRYPT_CMD_LEN; j++) {
            if (cipherText[i] == c_encrypt[j]) {
                cipherText[i] == c_original[j];
                break;
            }
        }
    }
    return cipherText;
}

std::string SecurityAlgorithm::encrypt_ceasar(std::string plainText, int additiveMultiplicative) {
    for (unsigned int i = 0; i < plainText.length(); i++) {
        plainText[i] = plainText[i] * 7 + additiveMultiplicative;
    }
    return plainText;
}

std::string SecurityAlgorithm::decrypt_ceasar(std::string cipherText, int additiveMultiplicative) {
    for (unsigned int i = 0; i < cipherText.length(); i++) {
        cipherText[i] = (cipherText[i] - additiveMultiplicative) / 7;
    }
    return cipherText;
}

std::string SecurityAlgorithm::init_rsa(int firstPrime, int seccondPrime, int& e, int& d) {
    long int eArray[50], dArray[50];

    if (firstPrime != seccondPrime) {
        if (is_prime(firstPrime) && is_prime(seccondPrime)) {
            int multiplyOne;
            int multiplyTwo;
            int k = 0;

            multiplyOne = firstPrime * seccondPrime;
            multiplyTwo = (firstPrime - 1) * (seccondPrime - 1);

            for (unsigned int i = 1; i < multiplyTwo; i++) {
                if (k == 99) break;
                if (is_prime(i) && i != firstPrime && i != seccondPrime) {
                    eArray[k] = i;
                    e = i;
                    long int temp = 1;
                    do {
                        temp += multiplyTwo;
                        if (temp % e[k] == 0) dArray[k] = temp / eArray[k];
                    } while (dArray[k] > 0);
                }
            }
        }
    }
    d = dArray[k];
}

std::string SecurityAlgorithm::encrypt_rsa(std::string plainText, int e, int multiplyOne) {
    this.plainText = plainText;
    return plainText;
}

std::string SecurityAlgorithm::decypt_rsa(std::string cipherText, int d, int firstPrime, int seccondPrime) {
    this.cipherText = cipherText
        return cipherText;
}


int main() {
  return 0;
}
