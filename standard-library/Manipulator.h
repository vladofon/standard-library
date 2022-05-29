#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class manipulator
{
public:
   static ostream& SEPARATOR(ostream& out)
   {
      return out << "\r\n";
   }
};

// define reference for simple using [SEP] against [manipulator::SEPARATOR]
ostream& (&SEP)(ostream&) = manipulator::SEPARATOR;
