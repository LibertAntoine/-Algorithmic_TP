#include "lib/tp2.h"
#include <QApplication>
#include <time.h>

#define return(return_value) int result=return_value; w->popFunctionCall(result); return result;

_TestMainWindow* w = nullptr;

void allEvens(Array& evens, Array& array, int evenSize, int arraySize){

	NOTIFY_START("allEvens", evens, array, evenSize, arraySize); // notify the call of this function to the MainWindow

	// recursiv evens search
  if(arraySize == 0){ 
    return;
  }
  if(array[arraySize - 1] %2 == 0) { 
    evens[evenSize] = array[arraySize - 1];
    evenSize++;
  }
  return allEvens(evens, array, evenSize, --arraySize);
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
  w = new AllEvensWindow(allEvens);
  w->show();

  a.exec();
}



