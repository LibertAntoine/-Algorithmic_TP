#include <QApplication>
#include <time.h>

#include "lib/tp1.h"


MainWindow* w=nullptr;

void merge(Array& Arr1, Array& Arr2, Array& result);

void merge(Array& Arr1, Array& Arr2, Array& result)
{
  int i1=0, i2=0, i=0;
  for( ; i1 < Arr1.size() && i2 < Arr2.size(); i++){
    if(Arr1.get(i1)<Arr2.get(i2)){
      result.set(i,Arr1.get(i1));
      i1++;
    } else {
      result.set(i, Arr2.get(i2));
      i2++;
    }
  }
  for(i1 ; i1 < Arr1.size(); i++, i1++){
    result.set(i,Arr1.get(i1));
  }
  for(i2 ; i2 < Arr2.size(); i++, i2++){
    result.set(i,Arr2.get(i2));
  }
}

void mergeSort(Array& toSort)
{
  if(toSort.size() > 1){
    int middle = toSort.size()/2;
    Array& Arr1 = w->newArray(middle);
    Array& Arr2 = w->newArray(toSort.size() - middle);
    for(int i=0; i < middle; i++){
        Arr1.set(i, toSort.get(i));
    }
    for(int i=0; i < toSort.size()-middle; i++){
        Arr2.set(i, toSort.get(middle+i));
    }
    if(Arr1.size() > 1) {
        mergeSort(Arr1);
    }
    if(Arr2.size() > 1) {
        mergeSort(Arr2);
    }
    merge(Arr1, Arr2, toSort);
  }
}


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  uint elementCount=20;
  MainWindow::instruction_duration = 50;
  w = new TestMainWindow(mergeSort, elementCount);
  w->show();

  return a.exec();
}
