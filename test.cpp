#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
string formatNum(int num);

int main(){
	cout << "integer to transfer: " << endl;
	int num  = 0;
	cin >> num;
	cout << formatNum(num) << endl;
	return 0;
}
/*
	covert digit by digit to a character
	track the amount of digits have been processed, 
		
		if digit_counter % 3 == 0  
			res += ",";

	concatenate each character into a string
	right shift the number by one digit
	reverse the resulting string
	 
*/

string formatNum(int num){
	int digit_counter = 0;
	string res = "";
	while( num > 0){
		if ( digit_counter != 0 && digit_counter%3 == 0){
			res += ",";
		}
		digit_counter++;
		res += (char)(num%10 + '0' ); 
		num /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}