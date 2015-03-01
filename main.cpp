#include "ggpio.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int i;
string output,high,low;
int main ()
//we've made the gpio class and the format is like GPIO nameGPIO[number]
{
GPIO first(49);

//
first.setdirection(output);

for (i=0;i<10;i++)
{
first.setpin(high);
usleep(500000);
first.setpin(low);
usleep(500000);

}

}
