#include "lib/mainwindow.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

void binarySearchAll(Array& array, int toSearch, int &indexMin, int &indexMax)
{
  int start = 0;
  int end = array.size() - 1;
  int middle;
  while(start < end)
  {
    middle = (start+end)/2;
    if(toSearch == array[middle]){
      indexMax = middle;
      indexMin = middle;
      break;
    }
    else if(toSearch < array[middle]) {
      end = middle - 1;
    }
    else if(toSearch > array[middle]) {
      start = middle + 1;
    }
  }
  while(indexMax != array.size() - 1 && array[indexMax+1] == toSearch) {
    indexMax++;
  }
  while(indexMin != 0 && array[indexMin-1] == toSearch) {
    indexMin--;
  }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
