#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int linecounter = 0;

void counter()
{
	linecounter = linecounter + 1;
}

int main() {
	int i = 0;
	int k = 0;
	bool lineup[1000] = { false };
	/////////////////
	thread threads[1000];
	mutex mtx;
	//below should be the use of the thread all rushing
	//towards the door at the same time
	for(int i=0; i<1000; i++)
	{
		threads[i] = thread(counter);
	}
	for (int k = 0; k < 1000; k++)
	{
		threads[i].join();
	}
	// this piece of code code below is for the spinning array
	linecounter = 0;
	bool in = lineup[0];
	while (lineup[k+1] == false)
	{
		lineup[k] = true;
		threads[k] = thread(counter);
		k++;
		threads[k].join();
	}
	return 0;

	// this last piece of code is for the ticket lock that is supposed
	// to implement
	for (int i = 0; i < 1000; i++)
	{
		mtx.lock();
		threads[i] = thread(counter);
		mtx.unlock();
	}
	for (int k = 0; k < 1000; k++)
	{
		threads[k].join();
	}
}
