#include "Security.h"
#include <iostream>

using namespace std;

Security::Security() {
 userName = "";
  cout << "\nPassword Requirements:\n8 characters long\nMust contain at least one uppercase letter\nMust contain at least one lowercase letter\nMust contain at least one digit(0-9)\nMust contain at least one special character from the set:'!@#$%^&*()\n\nType in password: ";
    string passTemp;
      getline(cin, passTemp);
    bool temp = checkNewPass(passTemp);
  
      while(!temp) {
        cout << "\nPassword Requirement not met, please try again.\n";
        cout << "\nPassword Requirements:\n8 characters long\nMust contain at least one uppercase letter\nMust contain at least one lowercase letter\nMust contain at least one digit(0-9)\nMust contain at least one special character from the set:'!@#$%^&*()\n\nType in password: ";
        getline(cin, passTemp);
        temp = checkNewPass(passTemp);
      }
    cout << "\nPassword accepted";
  
}

  

  bool Security::isUpper(string check) {
    string temp;
    for(int i = 0; i < check.length(); i++) {
      temp += toupper(check[i]);
    }
    if(temp == check) {
      return true;
    }
    return false;
  }

 bool Security::isLower(string check) {
    string temp;
    for(int i = 0; i < check.length(); i++) {
      temp += tolower(check[i]);
    }
    if(temp == check) {
      return true;
    }
    return false;
  }

bool Security::isSpecial(string check) {
  for(int o = 0; o < check.length(); o++) {
    char temp = check[o];
  string specialChar = "!@#$%^&*()";
    for(int i = 0; i < specialChar.length(); i++) {
      if(temp == specialChar[i]) {
        return true;
      }
    }
  }
  return false;
}

bool Security::isNum(string check) {
  for(int o = 0; o < check.length(); o++) {
    char temp = check[o];
  string specialChar = "0123456789";
    for(int i = 0; i < specialChar.length(); i++) {
      if(temp == specialChar[i]) {
        return true;
      }
    }
  }
  return false;
}
  
  

  bool Security::checkNewPass(string newPass) {
    bool length = false;
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool specialchar = false;
     if(newPass.length() < 8) {
        length = false;
          cout << "\nNot 8 characters long";
      }
    for(int i = 0; i < newPass.length(); i++) {
      string charTemp = newPass.substr(i,1);
          if(isLower(charTemp)) {
          lower = true;
             break;
        } 
    }
    if(!lower) {
      cout << "\nNo LowerCase.";
    }

    for(int i = 0; i < newPass.length(); i ++) {
      string charTemp = newPass.substr(i,1);
        if(isUpper(charTemp)) {
            upper = true;
            break;
        } 
    }
    if(!upper) {
      cout << "\nNo Uppercase.";
    }

    for(int i = 0; i < newPass.length(); i++) {
      string charTemp = newPass.substr(i,1);
        if(isSpecial(charTemp)) {
            specialchar = true;
            break;
          } 
    }
    if(!specialchar) {
      cout << "\nNo Special Character";
    }

    for(int i = 0; i < newPass.length(); i++) {
      string charTemp = newPass.substr(i,1);
        if(isNum(charTemp)) {
          digit = true;
          break;
        } 
    }
    if(!digit) {
      cout << "\nNo Digit";
    }

        if(upper) {
        if(lower) {
          if(digit) {
            if(specialchar) {
              return true;
            }
            
          }
        }
      }
      return false;
  }

Security::Security(string user, string pass) {
  passWord = pass;
  userName = user;
}

  string Security::getPassWord() {
    return passWord;
  }
  
  string Security::getUserName() {
    return userName;
  }

  void Security::setPassWord(string pass) {
    passWord = pass;
  }