#include <iostream>
using namespace std;
#include <chrono>
using namespace chrono;

int main(){
	int a,b = 1;
	int c = 0;
	double total_time;
    for (int j = 0; j < 10; j++){
    auto t0  = steady_clock::now();  // начало измерения времени
	for(int i = 0; i < 1'000'000'000; i++){
		c = a+b;
	}
	auto t1 = steady_clock::now();  // конец измерения времени
	auto delta = duration_cast<milliseconds>(t1 - t0);  // время в миллисекундах
	cout << "Time (milliseconds): " << delta.count()/1'000'000'000.0 << endl;
	total_time += delta.count()/1'000'000'000.0;
}
cout << total_time/10.0;
}