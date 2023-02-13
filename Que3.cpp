#include <iostream>
#include <string>
using namespace std;

string ones[] = { "", "one", "two", "three", "four", "five", "six", "seven",
                  "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                  "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                  "nineteen" };
string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty",
                  "seventy", "eighty", "ninety" };

string spellOutNumber(int number) {
  string result;
  if (number < 20) {
    result = ones[number];
  } else if (number < 100) {
    result = tens[number / 10] + "-" + ones[number % 10];
  } else if (number < 1000) {
    result = ones[number / 100] + " hundred " + spellOutNumber(number % 100);
  } else if (number < 10000) {
    result = ones[number / 1000] + " thousand " + spellOutNumber(number % 1000);
  }
  return result;
}

int main() {
  int number;
  cout << "Enter a number: ";
  cin >> number;
  cout << spellOutNumber(number) << endl;
  return 0;
}