#pragma once
#include "Employee.h"
#include <iostream>

#include "IOController.h"
#include "List.h"

using namespace std;

class employee_mapper
{
public:

   employee_mapper()
   {
      this->connection_ = io_controller();
   }

   /* Optional method. You can use only [io_controller::save] */
   static employee* create()
   {
      int id;
      string name;
      int age;
      int experience;

      cout << "Enter Employee`s id: "; cin >> id;
      cout << "Enter Employee`s name: "; cin >> name;
      cout << "Enter Employee`s age: "; cin >> age;
      cout << "Enter Employee`s experience: "; cin >> experience;

      const auto object = new employee();
      object->set_id(id);
      object->set_name(name);
      object->set_age(age);
      object->set_experience(experience);

      io_controller::save(object->to_string(), "db.txt");

      return object;
   }

   // Mapping data, retrieved from the file, to list of objects
   static List<employee*>* map_all(const string& path = "db.txt")
   {
      const auto data = io_controller::retrieve(path);
      const auto result = new LinkedList<employee*>();

      while (data->getSize() != 0)
      {
         result->add(map(split(data->get(0), ":")));
         data->remove(0);
      }

      return result;
   }



private:

   io_controller connection_;

   static string find_one(const string& str, const string& delimiter)
   {
      return str.substr(0, str.find(delimiter));
   }

   static List<string>* split(string str, const string& delimiter)
   {
      const auto elements = new LinkedList<string>();

      while (str.find(delimiter) != -1)
      {
         string element = find_one(str, delimiter);
         elements->add(element);

         str = str.substr(element.length() + 1);
      }

      return elements;
   }

   static employee* map(List<string>* data)
   {
      const auto object = new employee();

      object->set_id(stoi(data->get(0)));
      object->set_name(data->get(1));
      object->set_age(stoi(data->get(2)));
      object->set_experience(stoi(data->get(3)));

      return object;
   }

};