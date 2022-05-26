#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>

using namespace std;

class task1
{
public:

   static void start()
   {
      const auto container = new deque<float>();

      fill(container);

      review(container);

      container->clear();

      fill(container);

      review(container);

      const auto second_container = new deque<float>();

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

   static void fill(deque<float>* container)
   {
      for (int i = 0; i < 10; i++)
      {
         container->push_front(get_rand_number());
      }
   }

   static float get_rand_number()
   {
      return rand() % 1000000 + 1;
   }

   // Print container using iterator
   static void review(const deque<float>* container)
   {
      cout << "First container:" << endl;
      for (auto item = container->begin(); item != container->end(); ++item)
      {
         cout << "[item] = " << *item << endl;
      }
   }

   static void erase_range(deque<float>* container, const int start, const int end)
   {
      auto first_pos = find_pos(container, start);
      auto second_pos = find_pos(container, end);

      container->erase(first_pos, second_pos);
   }

   static deque<float>::iterator find_pos(deque<float>* container, const int index)
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