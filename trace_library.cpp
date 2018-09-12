#include <iostream>
#include <fstream>
#include <string>
char filePname[64]; //this will set aside 64 characters for the filename to be set
ofstream fileoutput;

void trace_start(char* filename)
{
	filePname = filename;	// this is assuming that the filename is actually comes in all at once
	string file = filePname;
	file = file+".txt";
	fileoutput.open(file); //replace the example with actual filename
	// may want to check if file is empty and, empty if there is anything in file
	if (fileoutput.fail())
	{
		fileoutput<< "[ ";
		myfile.close();
	}
	else 
	{
		cout<< "Unable to open file"
		myfile.close();
	}
}


void trace_end()
{
	string file = filePname;
	file = file + ".txt";
	fileoutput.open(file, std::ios_base::app);
	if (fileoutput.fail())
	{
		fileoutput<< "]";
		myfile.close();
	}
	else 
	{
		cout<< "Unable to open file"
		myfile.close();
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
