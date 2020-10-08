#include "lib/mainwindow.h"
#include <QApplication>
#include <time.h>

void insertionSort(Array& toSort) 
{
  for(int i=0 ; i < toSort.size() ; i++){
    for(int j=i ; j<toSort.size() ; j++) {
      if(toSort.get(j)<toSort.get(i)) {
        toSort.swap(i, j);
      }
    }
  }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w(insertionSort, 10);
	w.show();

	return a.exec();
}
