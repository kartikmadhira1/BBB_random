#include <iostream>
#include <sstream>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr3"
//define funtions here
using namespace std;
void led (string filename, string value);

int main(int argc, char* argv[])
{
if (argc!=2)
{
cout<<"bhadve galat kar raha \n"<<endl;
cout<<"too many arguements\n"<<endl;
return 0;
}
if (argv[1]==string("on"))
{
led("/trigger","none");
led("/brightness","1");
}
}

void led(string filename, string value)
{
//opening a file, instead of the FILE pointer, fstream is the library
fstream fs;
//making the LED PATH a string
string path(LED_PATH);
//opening the file with path string and filename
fs.open((path+filename).c_str(),fstream::out); //c_str gives out a string out                                              //and  :: gives scope to output
fs<<value;
fs.close();
}

