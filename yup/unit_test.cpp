/*
 * Name        : unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test to test your Temperature Class.
 */
#include <iostream>
#include <sstream>
#include <streambuf>
#include <vector>
#include "temperature.h"
using std::cout;
using std::endl;
using std::vector;

// For testing (DO NOT ALTER)
template <typename T>
void Test(bool test, string more_info = "", T yours = T(),
          T expected = T());
void UnitTest();
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 53;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // Any of your code to test can be put below this comment

  // To help test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << "BEGIN UNIT TEST (There are 19 Tests)\n" << string(50, '-') << endl;
  // Tests
  Temperature temp1;
  Test(temp1.kelvin() == 0, "Default Constructor / kelvin()", temp1.kelvin(), 0.0);
  temp1.set_kelvin(50);
  Test(temp1.kelvin() == 50, "set_kelvin(50) / GetTempAsCelsius()", temp1.kelvin(), 50.0);
  temp1.SetTempFromCelsius(5);
  Test(
      temp1.GetTempAsFahrenheit() >= 40.99
          && temp1.GetTempAsFahrenheit() <= 41.01,
      "SetTempFromCelsius(5) / GetTempAsFarenheit()", temp1.GetTempAsFahrenheit(), 41.0);
  temp1.SetTempFromFahrenheit(5);
  Test(temp1.kelvin() >= 258.149 && temp1.kelvin() <= 258.151,
       "SetTempFromFahrenheit(5) / kelvin()", temp1.kelvin(), 258.15);

  std::streambuf* old_cout = cout.rdbuf();
  std::ostringstream capture_cout;
  cout.rdbuf(capture_cout.rdbuf());
  temp1.Output();
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "258.15 Kelvin", "Output()", capture_cout.str(), string("258.15 Kelvin"));
  capture_cout.str("");
  
  Temperature temp2(50);
  Test(
      temp2.GetTempAsFahrenheit() >= -369.68
          && temp2.GetTempAsFahrenheit() <= -369.66,
      "Constructor(50) / GetTempAsFahrenheit()", temp2.GetTempAsFahrenheit(), -369.67);

  cout.rdbuf(capture_cout.rdbuf());
  temp2.Output('C');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-223.15 Celsius", "Output('C')", capture_cout.str(), string("-223.15 Celsius"));
  capture_cout.str("");
  
  Temperature temp3(5, 'F');
  Test(temp3.kelvin() >= 258.14 && temp3.kelvin() <= 258.16,
       "Constructor(5, 'F') / kelvin()", temp3.kelvin(), 258.15);
  Temperature temp4(5, 'f');
  Test(temp4.kelvin() >= 258.14 && temp4.kelvin() <= 258.16,
       "Constructor(5, 'f') / kelvin()", temp4.kelvin(), 258.15);
  Temperature temp5(5, 'C');
  Test(temp5.kelvin() >= 278.14 && temp5.kelvin() <= 278.16,
       "Constructor(5, 'C') / kelvin()", temp5.kelvin(), 278.15);
  Temperature temp6(5, 'c');
  Test(temp6.kelvin() >= 278.14 && temp6.kelvin() <= 278.16,
       "Constructor(5, 'c') / kelvin()", temp6.kelvin(), 278.15);
  Temperature temp7(5, 'K');
  Test(temp7.kelvin() == 5, "Constructor(5, 'K') / kelvin()", temp7.kelvin(), 5.0);
  Temperature temp8(5, '5');
  Test(temp8.kelvin() == 5, "Constructor(5, '5') / kelvin()", temp8.kelvin(), 5.0);

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('c');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-268.15 Celsius", "Output('c')", capture_cout.str(), string("-268.15 Celsius"));
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('K');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "5.00 Kelvin", "Output('K')", capture_cout.str(), string("5.00 Kelvin"));
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('k');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "5.00 Kelvin", "Output('k')", capture_cout.str(), string("5.00 Kelvin"));
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('F');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-450.67 Fahrenheit", "Output('F')", capture_cout.str(), string("-450.67 Fahrenheit"));
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('f');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "-450.67 Fahrenheit", "Output('f')", capture_cout.str(), string("-450.67 Fahrenheit"));
  capture_cout.str("");

  cout.rdbuf(capture_cout.rdbuf());
  temp8.Output('1');
  cout.rdbuf(old_cout);
  Test(capture_cout.str() == "Invalid Unit", "Output('1')", capture_cout.str(), string("Invalid Unit"));
  capture_cout.str("");

  cout << string(50, '-') << endl;
  cout << "END UNIT TEST" << endl;
}

// For testing (DO NOT ALTER)
template <typename T>
void Test(bool test, string more_info, T yours, T expected) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test && yours != T()) {
      cout << "Expected: " << std::boolalpha << expected << endl;
      cout << "Yours   : " << std::boolalpha << yours  << endl << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}
