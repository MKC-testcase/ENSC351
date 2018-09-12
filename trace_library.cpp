#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string filePname; //this will set aside 64 characters for the filename to be set
ofstream fileoutput;

void trace_start(char* filename)
{
    string filetemp;
	filePname = filename;	// this is assuming that the filename is actually comes in all at once
	filetemp = filePname+".txt";
	fileoutput.open(filetemp); //replace the example with actual filename
	// may want to check if file is empty and, empty if there is anything in file
	if (fileoutput.fail())
	{
		fileoutput<< "[";
		fileoutput.close();
	}
	else 
	{
		cout<< "Unable to open file";
		fileoutput.close();
	}
}


void trace_end()
{
    string filetemp;
	filetemp = filePname + ".txt";
	fileoutput.open(filetemp, std::ios_base::app);
	if (fileoutput.fail())
	{
		fileoutput<< "]";
		fileoutput.close();
	}
	else 
	{
		cout<< "Unable to open file";
		fileoutput.close();
	}
}


/*
void trace_event_start(char*  name, char* categories, char* arguments)
{
	
}

void trace_event_end(char* arguements)
{
	
}
*/
