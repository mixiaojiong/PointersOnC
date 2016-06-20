#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN  27
char arr[KEY_LEN];
char chacter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int prepare_key(char *key);
void encrypt(char *data, char const *key);
void decrypt(char *data, char const *key);

int main(void) {
    char test[] = "trailblazers";
    prepare_key(test);
    char data[] = "ATTACK AT DAWN";
    encrypt(data, arr);
    printf("%s\n", data);
    decrypt(data, arr);
    printf("%s\n", data);
}

int prepare_key(char *key) {
    if (!*key) {
        return 0;
    }
    int num = 0;
    while(*key) {
        if (!isalpha(*key)) {
            return 0;
        }
        *key = toupper(*key);
        if (strchr(arr, *key) == NULL) {
            arr[num++] = *key;
        }
        key++;
    }
    int i = 0;
    while(i < 26) {
        if (strchr(arr, chacter[i]) == NULL) {
            arr[num++] = chacter[i];
        }
        i++;
    }
    arr[num] = '\0';
    printf("%s\n", arr);
    return 1;
}
void encrypt(char *data, char const *key) {
    int ch;
    while (*data) {
        if (isalpha(*data)) {
            ch = toupper(*data);
            *data = key[ch - 'A'];
        }
        data++;
    }
}
void decrypt(char *data, char const *key) {
    int ch;
    while (*data) {
        if (isalpha(*data)) {
            ch = toupper(*data);
           *data = chacter[strchr(key, ch) - key];
        }
        data++;
    }
}
