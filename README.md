# C CLI Password Manager

A simple yet secure **Command Line Interface (CLI) Password Manager** built in C. This program allows you to store, retrieve, modify, and delete passwords securely using encryption and hidden file storage.

## Features
✅ **Add Passwords** - Securely store passwords for different websites.  
✅ **Retrieve Passwords** - Access stored passwords with ease.  
✅ **Modify Passwords** - Update existing passwords securely.  
✅ **Delete Passwords** - Remove passwords when no longer needed.  
✅ **Hidden Storage** - Stores passwords in a hidden file for extra security.  
✅ **Simple CLI Interface** - Lightweight and easy to use.

## Installation & Usage

### **1. Clone the Repository**
```sh
git clone https://github.com/Aswathi-Biju/password-manager-cli.git
cd password-manager-cli
```

### **2. Compile the Program**
Use GCC to compile the code:
```sh
gcc -o password_manager password_manager.c -lcrypto
```

### **3. Run the Program**
```sh
./password_manager
```

### **4. Features & Commands**
Once the program runs, you will see the following menu:
```
Password Manager
1. Add Password
2. Retrieve Password
3. Modify Password
4. Delete Password
5. Exit
Enter your choice:
```

- **Option 1:** Enter the website and password to store.
- **Option 2:** Retrieve and display stored passwords.
- **Option 3:** Modify an existing password.
- **Option 4:** Delete a saved password.
- **Option 5:** Exit the program.

## Security Features
🔒 **Hidden Storage**: Passwords are stored in a hidden file to prevent accidental access.  
🔒 **Basic Encryption**: Uses simple encryption techniques to obfuscate passwords.  

## Future Enhancements
📌 GUI Version using Python or C++.  
📌 Multi-user support with authentication.  
📌 Cloud sync for password storage.

## Contributing
Feel free to fork this repository and submit pull requests to improve security and add more features.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any queries, reach out to me via:
📧 Email: aswathibiju2028@cs.sjcetpalai.ac.in
🐙 GitHub: Aswathi-Biju
🚀 **Happy Coding & Stay Secure!**
