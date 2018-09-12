#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

string filePname; //this will set aside 64 characters for the filename to be set
ofstream fileoutput;


struct singleE
{
	char* nameE;
	char* cat;
	char ph;
	int pid;
	int tid;
	int ts;
};

singleE buffer[10000];
int i = 0;

void trace_start(char* filename)
{
    string filetemp;
	filePname = filename;	// this is assuming that the filename is actually comes in all at once
	filetemp = filePname+".txt";
	fileoutput.open(filetemp); //replace the example with actual filename
	// may want to check if file is empty and, empty if there is anything in file
	if (fileoutput.fail())
	{
		fileoutput.close();
		cout<<"file didn't open properly";
	}
	fileoutput<< "[ ";
}


void trace_end()
{
	//will need to iterate through the stack of singleEs to actually make the file content
	//then output to fileoutput using a while loop as long as buffer not empty
	// do this later
	fileoutput<< "]";
	fileoutput.close();
}



void trace_event_start(char*  name, char* categories, char* arguments)
{	
	singleE part;
	part.nameE= name;
	part.cat = categories;
	part.ph = 'B';
	part.pid = 1;
	part.tid = 1;
	part.ts = 5; //will need to retrieve this value from the the computer clock
	buffer[i] = part;
	i++;
}

void trace_event_end(char* arguements)
{
	int k = i;
	while(i != 0)
	{
		singleE temp = buffer[i];
		if (temp.ph == 'E')
		{
			i--;
			continue;
		}
		singleE part2;
    	part2.nameE= temp.nameE;
    	part2.cat = temp.cat;
    	part2.ph = 'E';
	    part2.pid = temp.pid;
	    part2.tid = temp.tid;
	    part2.ts = 5; //will need to retrieve this value from the the computer clock
	    i = k;
	    buffer[i] = part2;
	    i++;
		break;
	}

}
