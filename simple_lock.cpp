#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int linecounter = 0;
int index = 0;
int temp = 0;
thread threads[10];
bool check2 = false;
bool lineup[10] = {true};
void counter()
{
	linecounter = linecounter + 1;
}

void wait(int i)
{
	bool check = true;
	index++;
	while (check == true)
	{
		if (index == 9)
		{
			check = false;
		}
	}
	threads[i] = thread(counter);
	cout << "threads used" << i << endl;
}

void wait_2(int i)
{
	index++;
	while (lineup[i] == true)
	{
		if (index == 9)
		{
			check2 = true;
		}

		if (check2 = true)
		{
			lineup[temp] = false;
			temp++;
		}
	}
	threads[temp] = thread(counter);
	cout << "threads used" << i << endl;
}

int main() {
	int i = 0;
	int k = 0;
	/////////////////

	mutex mtx;
	//below should be the use of the thread all rushing
	//towards the door at the same time
	for (int i = 0; i < 10; i++)
	{
		threads[i] = thread(wait,i);
	}
	for (int k = 0; k < 10; k++)
	{
		threads[k].join();
	}
	// this piece of code code below is for the spinning array
	
	/*
	linecounter = 0;
	index = 0;
	for (int k = 0; k < 10; k++)
	{
		threads[k] = thread(wait_2, k);
		
	}
	k = 0;
	for (int k = 0; k < 10; k++)
	{
		threads[k].join();
	}
	*/
	return 0;
}
	/*
	// this last piece of code is for the ticket lock that is supposed
	// to implement
	for (int i = 0; i < 10; i++)
	{
		mtx.lock();
		threads[i] = thread(counter);
		mtx.unlock();
	}
	for (int k = 0; k < 10; k++)
	{
		threads[k].join();
	}
}
*/
