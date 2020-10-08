#include <QApplication>
#include <time.h>

#include "lib/tp1.h"


MainWindow* w=nullptr;

void quickSort(Array& toSort){
  int size = 0;
  for (int i = 0; i < toSort.size()-1 && toSort.get(i) != -1; i++) {
    size++;
  }
  int pivot = toSort.get(size/2);
  Array& lowerArray = w->newArray(size);
  Array& greaterArray= w->newArray(size);
  int lowerSize = 0;
  int greaterSize = 0;
  for(int i=0; i < size; i++) {
    if(toSort[i] < pivot) {
      lowerArray.set(lowerSize, toSort.get(i));
        lowerSize++;
    } else {
      greaterArray.set(greaterSize, toSort.get(i));
      greaterSize++;
    }
  }
  lowerArray.size();
  if(lowerSize > 1) {
    quickSort(lowerArray);
  }
  if (greaterSize > 1) {
    quickSort(greaterArray);
  }
  int i;
  for(i = 0; i < lowerSize; i++) {
    toSort.set(i, lowerArray.get(i));
  }
  toSort.set(i, pivot);
  i++;
  for(int j = 0; j < greaterSize; j++) {
    toSort.set(i, greaterArray.get(j));
    i++;
  }
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  uint elementCount=20;
  MainWindow::instruction_duration = 50;
  w = new TestMainWindow(quickSort, elementCount);
  w->show();

	return a.exec();
}
