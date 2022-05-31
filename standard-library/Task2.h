#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>

#include "Employee.h"
#include "EmployeeMapper.h"
#include "IOController.h"
#include "LinkedList.h"

using namespace std;

class task2
{
public:

   static void start()
   {
      const auto container = new deque<string>();

      fill(container);

      review(container);

      container->clear();

      fill(container);

      review(container);

      const auto second_container = new deque<string>();

      fill(second_container);

      erase_range(container, 0, 5);

      sort(container->begin(), container->end());
      sort(second_container->begin(), second_container->end());

      merge(
         container->begin(),
         container->end(),
         second_container->begin(),
         second_container->end(),
         inserter(*container, container->end())
      );

      review(container);
   }

private:

   static void fill(deque<string>* container)
   {
      const auto employees = new LinkedList<string>();
      employees->add((new employee(1, "first", 1, 1))->to_string());
      employees->add((new employee(2, "second", 2, 2))->to_string());
      employees->add((new employee(3, "third", 3, 3))->to_string());

      io_controller::save(employees, "db.txt");

      const auto saved = employee_mapper::map_all("db.txt");

      for (int i = 0; i < saved->getSize(); i++)
      {
         container->push_front(saved->get(i)->to_formated_string());
      }
   }

   // Print container using iterator
   static void review(const deque<string>* container)
   {
      cout << "First container:" << endl;
      for (auto item = container->begin(); item != container->end(); ++item)
      {
         cout << "[item] = " << *item << endl;
      }
   }

   static void erase_range(deque<string>* container, const int start, const int end)
   {
      auto first_pos = find_pos(container, start);
      auto second_pos = find_pos(container, end);

      container->erase(first_pos, second_pos);
   }

   static deque<string>::iterator find_pos(deque<string>* container, const int index)
   {
      auto position = container->begin();

      int counter = 0;
      while (counter != index)
      {
         position++;
         counter++;
      }

      return position;
   }
};
