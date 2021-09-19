/*
Nama      : Ananda Sapta Awedhana
NPM       : 140810190063
Kelas     : A
Deskripsi : Program Shift Cipher
*/

#include <iostream>
using namespace std;
 
string encrypt(string text, int key)
{
    string result = ""; //placeholder result
    for (int i = 0; i < text.length(); i++)
    {
        // huruf kapital
        if (isupper(text[i]))
            result += char(int(text[i] + key - 65) % 26 + 65);
        // huruf kecil
        else
            result += char(int(text[i] + key - 97) % 26 + 97);
    }
    return result;
}

string decrypt(string text, int key)
{
    string result = ""; //placeholder result
    for(int i = 0; i < text.size(); i++)
    {
        result += (text[i] - 'A' - key + 26) % 26 + 'A';
    }
    return result;
}

int main()
{
    char menu;
    string text;
    int key;

    while(true) {
        cout << "Masukkan input Anda         : ";
        cin >> text;

        cout << "Masukkan angka untuk kunci  : ";
        cin >> key;

        cout << endl;

        cout << "Plaintext                   : " << text;
        cout << "\nKunci                       : " << key;
        cout << "\nCiphertext                  : " << encrypt(text, key);
        cout << "\nHasil Dekripsi              : " << decrypt(encrypt(text, key), key);
        
        cout << "\nApakah mau diulang? (Y/N)   : ";
        cin >> menu;
        if (menu == 'y' || menu == 'Y')
        {
            cout << endl;
            continue;
        }
        else 
            break;
    }
    return 0;
}