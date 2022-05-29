#pragma once
#include<iostream>
#include<string>

using namespace std;

class employee {

public:

   employee() {

      this->name_ = "undefined";
      this->age_ = -1;
      this->experience_ = -1;
   }

   employee(const string& name, const int age, const int experience) {

      this->name_ = name;
      this->age_ = age;
      this->experience_ = experience;
   }

   employee(const employee& object) {

      this->name_ = object.get_name();
      this->age_ = object.get_age();
      this->experience_ = object.get_experience();
   }

   ~employee() {
   }

   void set_name(const string& name) {
      this->name_ = name;
   }

   string get_name() const
   {
      return this->name_;
   }

   void set_age(const int age) {
      this->age_ = age;
   }

   int get_age() const
   {
      return this->age_;
   }

   void set_experience(const int experience) {
      this->experience_ = experience;
   }

   int get_experience() const
   {
      return this->experience_;
   }

   string to_formated_string() const
   {
      string dump =
         "Employee: {\n";
      dump += "  name: " + this->name_ + ",\n";
      dump += "  age: " + std::to_string(this->age_) + ",\n";
      dump += "  experience: " + std::to_string(this->experience_) + ",\n";
      dump += "}";

      return dump;
   }

   string to_string() const
   {
      string dump = this->name_ + ":";
      dump += std::to_string(this->age_) + ":";
      dump += std::to_string(this->experience_) + ":";
      dump += "\n";

      return dump;
   }

private:

   string name_;
   int age_;
   int experience_;

};