#include <iostream>
#include <fstream>
#include <string>
char filePname[64]; //this will set aside 64 characters for the filename to be set
ofstream fileoutput;

void trace_start(char* filename)
{
	fileoutput.open("/*example.txt*/") //replace the example with actual filename
}

/*
void trace_end()
{
	
}

void trace_event_start(char*  name, char* categories, char* arguments)
{
	
}

void trace_event_end(char* arguements)
{
	
}
*/
