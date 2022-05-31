#pragma once
#include<iostream>
#include<string>

using namespace std;

class employee {

public:

   employee() {

      this->id_ = -1;
      this->name_ = "undefined";
      this->age_ = -1;
      this->experience_ = -1;
   }

   employee(const int id, const string& name, const int age, const int experience) {
      this->id_ = id;
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

   bool operator < (const employee& obj) const
   {
      return (id_ < obj.get_id());
   }

   int get_id() const
   {
      return this->id_;
   }

   void set_id(const int id)
   {
      this->id_ = id;
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
      dump += "  id: " + std::to_string(this->id_) + ",\n";
      dump += "  name: " + this->name_ + ",\n";
      dump += "  age: " + std::to_string(this->age_) + ",\n";
      dump += "  experience: " + std::to_string(this->experience_) + ",\n";
      dump += "}";

      return dump;
   }

   string to_string() const
   {
      string dump = std::to_string(this->id_) + ":";
      dump += this->name_ + ":";
      dump += std::to_string(this->age_) + ":";
      dump += std::to_string(this->experience_) + ":";
      dump += "\n";

      return dump;
   }

private:

   int id_;
   string name_;
   int experience_;
   int age_;

};