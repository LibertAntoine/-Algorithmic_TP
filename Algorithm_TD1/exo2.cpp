#include "lib/mainwindow.h"
#include <QApplication>
#include <time.h>

MainWindow* w=nullptr;

void insertionSort(Array& toSort)
{
  Array& Arr=w->newArray(toSort.size());
  Arr.set(0, toSort.get(0));
  for(int i=1; i<toSort.size(); i++) {
    int j=i;
    while(j>0 && Arr.get(j-1)>toSort.get(i)) {
      j--;
    }
    Arr.insert(j, toSort.get(i));
  }
  toSort=Arr;
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  uint elementCount=20;
  w = new MainWindow(insertionSort, elementCount);
  w->show();

  return a.exec();
}
