#include <iostream>

#include <string>

#include <sstream>

#include <fstream>

using namespace std;



struct Node

{

  int population;

  string place;

};



const int arrSize = 3144;

Node* arr [arrSize];

int count = 0;

ifstream file("countyPop.dat");

string line;



void swap(Node &x, Node &y)

{

  Node temp = x;

  x = y;

  y = temp;

}



void quicksort(int low, int high)

{

  int pivot, i, j;

  if (low < high)

    {

      pivot = low;  i = low; j = high;

      while (i < j)

        {

          while (arr[i] <= arr[pivot] && i <= high)i++;

          while (arr[j] > arr[pivot] && j >= low)j--;

          if (i < j)swap(arr[i], arr[j]);

        }

      swap(arr[j],arr[pivot]);

      quicksort(low, j - 1);

      quicksort(j + 1, high);

    }

}



void display()

{

  for(int i = 0; i < 10; i++)

  {

      cout << arr[i]->population << " " << arr[i]->place << endl;

  }

  for(int i = count; i > count - 10; i--)

  {

      cout << arr[i]->population << " " << arr[i]->place << endl;

  }

}



int main()

{

  while(getline(file, line))

  {

      stringstream subline(line);

      int population;

      string place;

      while(subline >> population)

        {

          getline(subline, place);

          Node* temp = new Node;

          temp->population = population;

          temp->place = place;

          arr[count] = temp;

          count++;

        }

  }

  display();

  quicksort(0, count);

  display();

  return 0;

}
