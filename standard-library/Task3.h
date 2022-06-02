#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>

#include "Employee.h"
#include "EmployeeMapper.h"
#include "IOController.h"
#include "LinkedList.h"


class task3 {
public:
   static void start()
   {
      const auto container = new deque<employee*>();

      fill(container);

      review(container);

      cout << "Find element by id [id=2]:" << endl;
      cout << find(container, 2)->to_formated_string() << endl;

      cout << "Copy found elements to new collection:" << endl;
      auto second_container = new stack<employee*>();
      second_container->push(find(container, 2));

      sort(container->rbegin(), container->rend());

      review(container);
      review(second_container);

      auto third_container = stack_to_deque(second_container);
      merge(third_container, container);

      review(third_container);

      if (find(third_container, 2)->get_id() != -1) {
         cout << "Element was found in third container!" << endl;
      }
      else {
         cout << "Element with id [2] not found!" << endl;
      }

      cout << "Count of elements with [id=2]:" << find_all(third_container, 2) << endl;
   }

private:

   static void fill(deque<employee*>* container)
   {
      const auto employees = new LinkedList<string>();
      employees->add((new employee(1, "first", 1, 1))->to_string());
      employees->add((new employee(2, "second", 2, 2))->to_string());
      employees->add((new employee(3, "third", 3, 3))->to_string());

      io_controller::save(employees, "db.txt");

      const auto saved = employee_mapper::map_all("db.txt");

      for (int i = 0; i < saved->getSize(); i++)
      {
         container->push_front(saved->get(i));
      }
   }

   // Print container using iterator
   static void review(deque<employee*>* container)
   {
      cout << "First container:" << endl;
      for (auto item = container->begin(); item != container->end(); ++item)
      {
         cout << "[item] = " << (*item)->to_formated_string() << endl;
      }
   }

   static void review(stack<employee*>* container)
   {
      cout << "First container:" << endl;
      while (!container->empty())
      {
         cout << "[item] = " << container->top()->to_formated_string() << endl;
         container->pop();
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

   static employee* find(deque<employee*>* container, const int id)
   {
      for (auto item : *container) {
         if (item->get_id() == id) return item;
      }

      return new employee();
   }

   static int find_all(deque<employee*>* container, const int id)
   {
      int counter = 0;
      for (auto item : *container) {
         if (item->get_id() == id) {
            counter++;
         }
      }

      return counter;
   }

   static deque<employee*>* stack_to_deque(stack<employee*>* container)
   {
      auto result = new deque<employee*>();

      while (!container->empty())
      {
         result->push_front(container->top());
         container->pop();
      }

      return result;
   }

   static void merge(deque<employee*>* right, deque<employee*>* left)
   {
      for (auto element : *left)
      {
         right->push_front(element);
      }
   }
};