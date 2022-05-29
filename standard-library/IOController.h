#pragma once
#include<fstream>
#include<iostream>
#include <string>

#include "Employee.h"
#include "LinkedList.h"
#include "List.h"
#include "Manipulator.h"

using namespace std;

class io_controller
{
public:
   static void save(List<string>* lines, const string& filename)
   {
      // ios::app - save without rewriting
      fstream fout(filename, ios::app);

      if (fout.is_open())
      {
         for (int i = 0; i < lines->getSize(); i++)
         {
            fout << lines->get(i) << SEP;
         }
      }

      cout << "File UPDATED. Current file size: " << fout.tellg() << endl;

      fout.close();
   }

   static void save(const string& line, const string& filename)
   {
      // ios::app - save without rewriting
      fstream fout(filename, ios::app);

      if (fout.is_open())
      {
         fout << line << SEP;
      }

      cout << "File UPDATED. Current file size: " << fout.tellg() << endl;

      fout.close();
   }

   static void rewrite(List<string>* lines, const string& filename)
   {
      // ios::out - save with rewriting
      fstream fout(filename, ios::out);

      if (fout.is_open())
      {
         for (int i = 0; i < lines->getSize(); i++)
         {
            fout << lines->get(i) << SEP;
         }
      }

      cout << "File REWRITED. Current file size: " << fout.tellg() << endl;

      fout.close();
   }

   static List<string>* retrieve(const string& filename)
   {
      const auto lines = new LinkedList<string>();

      fstream fin(filename);

      if (fin.is_open())
      {
         string line;
         while (fin >> line)
         {
            lines->add(line);
         }
      }

      cout << "File data RETRIEVED. Current file size: " << get_file_size(filename) << endl;

      fin.close();

      return lines;
   }

   static void remove(const int index, const string& filename)
   {
      const auto lines = retrieve(filename);

      lines->remove(index);

      rewrite(lines, filename);
   }

   static void update(const int index, const employee* object, const string& filename)
   {
      const auto lines = retrieve(filename);

      lines->edit(index, object->to_string());

      rewrite(lines, filename);
   }

private:

   // Append all lines into one string
   static string append(List<string>* lines)
   {
      string new_file;
      for (int i = 0; i < lines->getSize(); i++)
      {
         new_file += lines->get(i) + "\n";
      }

      return new_file;
   }

   static long long get_file_size(const string& filename)
   {
      ifstream file(filename, ios::binary | ios::ate);
      return file.tellg();
   }
};