
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using std::ofstream;
using namespace std;
//defining the path for gpio definitions
#define gpio_path "/sys/class/gpio/"
enum GPIO_DIRECTION {INPUT,OUTPUT};
enum GPIO_SETVALUE {LOW=0, HIGH=1};
//defining enum which constrains the variables 
 //enum used to constrain ony to input or output
class GPIO
{
private: 

int number,i;
string gpio_dir,name;
string filename,a,c,j,b,path,dir,val,value,high,low,input,output;
public:
GPIO(int number);
//a method to set the gpio number

//a method to set the gpio direction  
virtual int setdirection(GPIO_DIRECTION dir);
//method to set the pin high or low
virtual int setpin(GPIO_SETVALUE val);
//method for opening the file operations and writing the required values
virtual int writein(string filename,string  value);
virtual int  write(string filename,int  value); 
virtual ~GPIO();
};

GPIO::GPIO(int number)
{
	this->number=number;
	std::ostringstream s;
	//convertinf to stream to take the string as output
	s<<"gpio"<<number;
	//again converting stream to string 
	this->name=string(s.str());
	j=string(gpio_path);
	this->path=j + this->name;
	write("j/export",this->number);
//to append values we'll convert the string to a stream

//we need to append the /gpio[numnber] string to main string
//so what we'll need is a /gpio/gpio[number
}

int  GPIO::setdirection(GPIO_DIRECTION dir)
{

	switch(dir)
	{
	case INPUT: return this->writein("path/direction","in");
	break;
	case OUTPUT: return this->writein("path/direction","out");
	break;
	}
	return -1;

}
int  GPIO::setpin(GPIO_SETVALUE val)
{
	switch(val)
	{
	case HIGH: return this->writein("path/value","1");
	break;
	case LOW: return this->writein("path/value","0");
	break;
	}	
	return -1;
}
int  GPIO::write(string filename , int  value)
{//open the file and append the value to it 
//creating the ofstream for file opertions

ofstream ds;
ds.open(filename.c_str());
ds<<value;
ds.close();
return 0;
}

int GPIO:: writein(string filename , string  value)
{//open the file and append the value to it 
//creating the ofstream for file opertions

ofstream ls;
ls.open(filename.c_str());
ls<<value;
ls.close();
return 0;
}


GPIO::~GPIO(){
//DO NOTHING 
}
int i;
int main ()
//we've made the gpio class and the format is like GPIO nameGPIO[number]
{
GPIO first(49);

//
first.setdirection(OUTPUT);

for (i=0;i<10;i++)
{
first.setpin(HIGH);
}
}

