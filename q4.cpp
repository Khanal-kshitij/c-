#include <iostream>
using namespace std;
string str1= "Hello World";
string str2 = "Hello C++";
void AddressChars(){
    int len1= str1.length();
    for (int i=0; i<len1;i++){
        cout << "Address of char" << " "<< str1[i] << " is" << " " << i  << endl;
    }
}
void StringConcatenate(){
    cout << "Concatenated string is " << str1 + str2;
}
void CompareStrings(){
    if(str1==str2){
        cout << "strings are equal"<<endl;
    }
    else
    {
        cout<<"strings are not equal"<<endl;
    }
    
}
void LenStrPointers(){
    char *ptrstart = &str1[0];
    char *ptrend= &str1[0] + (str1.size()-1); //points to last char in string, remember char is just one byte
    int result = ptrend-ptrstart+1;
    cout << "Length of string: "<< str1<<" is "<<result;
}
void Lower2Upper(){
    string str_buffer=str1;
    int len=str_buffer.length();
    for (int i=0; i<len;i++){
        if (str_buffer[i] >= 'a' && str_buffer[i]<='z'){
            str_buffer[i] = str_buffer[i] - ('a' - 'A');
        }
    }
    cout << "Characters of string "<<str1<<" converted to uppercase "<<str_buffer;    
}
void Rev_string(){
    int n = str1.size();
    string str_buff=str1;
    for (int i = 0; i < n / 2; i++) {
        char temp = str_buff[i];
        str_buff[i] = str_buff[n - 1 - i];
        str_buff[n - 1 - i] = temp;
    }

    cout << "Reversed String: " << str_buff << endl;
}

int main()
{
int choice;
cout << "Enter 1 to show address of each character in a string" << endl;
cout <<"Enter 2 to concatenate two strings" << endl;
cout <<"Enter 3 to compare two strings" << endl;
cout <<"Enter 4 to calculate length of string(using pointers)" <<endl;
cout <<"Enter 5 to convert all lowercase characters to uppercase" << endl;
cout << "Enter 6 to reverse the string" << endl;
cin >> choice;
if (choice==1){
    AddressChars();
}
else if (choice==2)
{
    StringConcatenate();
}
else if (choice==3)

{
   CompareStrings();
}
else if (choice==4){
    LenStrPointers();
}
else if (choice==5){
    Lower2Upper();
}
else{
    Rev_string();
}
}

