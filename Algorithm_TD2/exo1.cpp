#include "lib/tp2.h"
#include <QApplication>
#include <time.h>
#include <math.h>

#define return(return_value) int result=return_value; w->popFunctionCall(result); return result;

_TestMainWindow* w = nullptr;

int power(int value, int n)
{
	NOTIFY_START("power", value, n); 

  if(n==0) {return (1);}
  return (value*power(value, n-1));
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new PowerWindow(power);
    w->show();

    a.exec();
}
