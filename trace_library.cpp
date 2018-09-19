#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;
void printsingleE();

ofstream fileoutput;
//make sure to include the chrono library to allow the program to tell the computer clock
//also have to research how to use chrono

struct singleE
{
	string nameE;
	string cat
	string ph;
	int pid;
	int tid;
	int ts;
};

singleE buffer[10000];
int i = 0;

void trace_start(string filename)
{
	fileoutput.open(filename); //replace the example with actual filename
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
	printsingleE();
	fileoutput<< "]";
	fileoutput.close();
}

void trace_event_start(string  name, string categories, string arguments)
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

void trace_event_end(string arguements)
{
	singleE part2;
    part2.ph = 'E';
	part2.pid = 1;
	part2.tid = 1;
	part2.ts = 5; //will need to retrieve this value from the the computer clock
	buffer[i] = part2;
	i++;
}

void printsingleE()
{
	int k = 0;
	while(k<10000)
	{
		singleE temp = buffer[k];
		if(temp.ph == 'B')
		{
			fileoutput<<"{\"name\": \""<<temp.nameE<<"\",\"cat\": \""<<temp.cat<<"\",";
			fileoutput<<"\"ph\":\""<<temp.ph<<"\", \"pid\":"<<temp.pid<<",";
			fileoutput<<"\"tid\":"<<temp.tid<<", \"ts\":"<<temp.ts<<"},"<<endl;
		}
		else if(temp.ph == 'E')
		{
			fileoutput<<"{\"ph\":\""<<temp.ph<<"\", \"pid\":"<<temp.pid<<",";
			fileoutput<<"\"tid\":"<<temp.tid<<", \"ts\":"<<temp.ts<<"}";
			if(k!=9999)
			{
				fileoutput<<",";
			}
			fileoutput<<endl;
		}
		k++;
	}
	i = 0;
}
int main()
{
	
	trace_start("output.txt")
	trace_event_start("Hello", "greeting", "bah humbug")
	void trace_event_end("bah humbug")
	trace_end()
	return 0;
}
