#include "header.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;


priority_queue <process,vector<process> , Compare> q1 , q2 , q3;
const int qTime1 = 8, qTime2 = 16;
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

void excution() {
	vector<process> finshed;
	int n = q1.size();
	int time = 0;
	while (finshed.size() < n) {
		int cnt = 0;
		for (int i = 0; i < 60; i++) {
			if (q1.empty()) {
				time++;
				continue;
			}
			auto fr = q1.top();
			q1.pop();
			fr.decreament();

			q1.push(fr);
			if (fr.getBurst() == 0) {
				cnt = 0;
				finshed.push_back(fr);
				q1.pop();
				// add to the chart
			}
			else if (cnt == qTime1) {
				cnt = 0;
				q1.pop();
				q2.push(fr);
			}
			cnt++;
			time++;
		}
		cnt = 0;

		for (int i = 0; i < 25; i++) {
			if (q2.empty()) {
				time++;
				continue;
			}

			auto fr = q2.top();
			q2.pop();
			fr.decreament();
			q2.push(fr);
			if (fr.getBurst() == 0) {
				cnt = 0;
				finshed.push_back(fr);
				q2.pop();
				// add to the chart
			}
			else if (cnt == qTime2) {
				cnt = 0;
				q2.pop();
				q3.push(fr);
			}
			cnt++;
			time++;
		}

		cnt = 0;
		for (int i = 0; i < 15; i++) {
			if (q3.empty()) {
				time++;
				continue;
			}

			auto fr = q3.top();
			q3.pop();
			fr.decreament();
			q3.push(fr);
			if (fr.getBurst() == 0) {
				q3.pop();
				finshed.push_back(fr);
				// add to the chart 
			}
			time++;
		}
	}

	for (auto x : finshed) {
		x.print();
	}
}
int process::ID = 0;

int main() {
	getProcesses();
	excution();
	return 0;
}
