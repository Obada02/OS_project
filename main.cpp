#include "header.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

priority_queue <process,vector<process> , Compare> q1;
int process::ID = 0;


void printLine() {
	for (int i = 0; i < 80; i++)
		cout << "-";
	cout << endl;
}

void getProcesses() {
	int n;
	cout << "how manny processes you want:";
	cin >> n;
	while (n--) {
		process temp;
		cout << "please enter the Info. for the process #" << temp.getId() << endl;
		temp.get_data();
		q1.push(temp);
		printLine();
	}
}
void CPU() {

}

int main() {
	getProcesses();
	while (!q1.empty()) {
		auto fr = q1.top();
		q1.pop();
		fr.print();
		printLine();
	}
	return 0;
}
