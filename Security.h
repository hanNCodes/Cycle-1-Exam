#include<string>
using namespace std;

class Security {
  private:
    string passWord;
    string userName;

  public:
  //no argument constructor
  Security();
  //paramarized constructor
  Security(string, string);
    //mutators
    void setPassWord(string);
    //getters
    string getPassWord();
    string getUserName();
    //check 
    bool checkNewPass(string);
    bool isUpper(string);
    bool isLower(string);
    bool isSpecial(string);
    bool isNum(string);
};