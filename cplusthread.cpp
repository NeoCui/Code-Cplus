#include<iostream>
#include<thread>

using namespace std;

#define NUM_THREADS 5

void thread_task(){
	cout<<"Hello Thread: "<<this_thread::get_id()<<endl;
}

int main(int argc, char** argv){
	thread t(thread_task);
	t.join();
	return EXIT_SUCCESS;
	//return 0;
}
