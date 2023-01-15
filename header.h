#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

class process {
private:
	int id;
	int burstTime;
	int arrival;
	vector <pair<int, int>> process_exc;
public:
	process() {
		id = ID;
		ID++;
	}
	void get_data() {
		cout << "please enter the burst time:";
		cin >> this->burstTime;
		cout << "please enter the arrival time:";
		cin >> this->arrival;
	}
	bool operator< (process& other) {
		return (this->arrival < other.arrival);
	}
	bool operator<= (const process& other) {
		return (this->arrival < other.arrival);
	}
	void print() {
		cout << "ID: " << id << endl;
		cout << "burst time: " << burstTime << "  arrival time: " << arrival << endl;
	}
	int getArrival()const { return arrival; }
	int getBurst() const { return burstTime; }
	int getId()const { return id; }

	void setArrival(int val) { arrival = val; }
	void setBurst(int val) { burstTime = val; }
	static int ID;

};
class Queue {
private:
	int layer;
	int qTime;
	queue<process> q;
public:
	Queue(int layer) {
		this->layer = layer;
		if (layer == 1)
			qTime = 8;
		else if (layer == 2)
			qTime = 16;
	}
	void push(process p) {
		q.push(p);
	}
	void excute() {
		if (q.empty()) throw ("the queue is empty !!!!");
	}

};

struct Compare {
	bool operator()(process const& p1, process const& p2) {
		return p1.getArrival() > p2.getArrival();
	}
};