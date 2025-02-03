# 🔐 CeasarJaw

## 📜 Description
This C++ program provides encryption and decryption functionalities using a simple shift cipher (Caesar cipher). It allows users to:
✅ Encrypt text 📝
✅ Decrypt text 🔑
✅ Determine the shift key 🔎
✅ Attempt decryption without a known key 💡

## ✨ Features
- 🔏 **Encryption (Crypt)**: Encrypts a given text using a specified key.
- 🔓 **Decryption (UnCrypt)**: Decrypts an encrypted text using a specified key.
- 🕵️ **Determine Shift Key**: Finds the encryption key by comparing original and encrypted text.
- 🎭 **Brute-Force Decryption**: Attempts decryption by trying all possible shift keys.

## 🚀 Usage
Run the program and select an option:
1️⃣ **Encrypt Text**: Enter a switch key and the text to encrypt.
2️⃣ **Decrypt Text**: Enter a switch key and the text to decrypt.
3️⃣ **Find Shift Key**: Provide an encrypted and decrypted text to determine the shift key.
4️⃣ **Brute-Force Decryption**: Enter an encrypted text and see all possible decrypted results.

## 🛠️ Compilation & Execution
To compile the program using g++, run:
```sh
g++ -o cryptography_tool main.cpp
```
To execute:
```sh
./cryptography_tool
```

## 📝 Example
### 🔏 Encrypting a message
```
Enter Switch Key: 3
Please enter text: Hello123
Encrypted: Khoor456
```

### 🔓 Decrypting a message
```
Enter Switch Key: 3
Please enter text: Khoor456
Decrypted: Hello123
```

### 🔑 Determining the shift key
```
Please enter Crypt Text: Khoor456
Please enter UnCrypt Text: Hello123
Switch Key: 3
```

## 🤝 Contributions
Feel free to fork the repository and contribute improvements via pull requests. 🚀

## 📜 License
This project is open-source and free to use. 🎉

