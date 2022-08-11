
#include <iostream>
#include <string>

using namespace std;

string reverse_string_iter(string str){
  string rs=str;
  for(unsigned int i=0, j=str.length(); i<j; i++){
    rs[j-i-1] = str[i];
  }
  return rs;
}


string reverse_string_recur(string str){
  if (str == ""){
    return("");
  } else {
    return(reverse_string_recur(str.substr(1)) + str.at(0));
  }
}


int main() {
  string s = "Hello World!";
  cout<<"s: "<<s<<endl;
  string r = reverse_string_iter(s);
  cout<<"r: "<<r<<endl;
  string rc = reverse_string_recur(s);
  cout<<"rc: "<<rc<<endl;
}