#include "lib/mainwindow.h"
#include <QApplication>
#include <time.h>

MainWindow* w=nullptr;

void bubbleSort(Array& toSort){
  for(int i=toSort.size()-1; i>0; i--){
    for(int j=0; j<i; j++) {
      if(toSort.get(j+1) < toSort.get(j)) {
        toSort.swap(j+1, j);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Array::instruction_duration = 200;
  w = new MainWindow(bubbleSort, 15);
  w->show();

  return a.exec();
}
