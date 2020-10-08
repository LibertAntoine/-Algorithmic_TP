#include "lib/tp2.h"
#include <QApplication>
#include <time.h>

#define return(return_value) int result=return_value; w->popFunctionCall(result); return result;

_TestMainWindow* w = nullptr;

int search(int value, Array& toSort, int size){

	NOTIFY_START("search", toSort, size);

    if(toSort[size-1]==value) { 
    	return size-1;
    }
    return (search(value, toSort, size-1));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new SearchWindow(search);
    w->show();

    a.exec();
}



