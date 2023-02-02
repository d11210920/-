#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Stack {
public:
	Node* head;
	int cnt;

	Stack() {
		head = NULL;
		cnt = 0;
	}

	void push(int x) {
		Node* newNode = new Node();
		newNode->data = x;
		if (head == NULL) head = newNode;
		else {
			Node* tmp = head;
			newNode->next = tmp;
			head = newNode;
		}
		cnt++;
	}
	int pop() {
		if (head == NULL) return 0;
		else {
			Node* tmp = head;
			int ret = head->data;
			head = head->next;
			cnt--;
			return ret;
		}
	}
	bool empty() {
		if (cnt == 0) return true;
		else return false;
	}
	int top() {
		if (head == NULL) return 0;
		else return head->data;
	}
};

int main() {
	int N;
	cin >> N;
	Stack s;
	int arr[N + 1];
	vector<int> nge(N + 1, -1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			nge[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= N; i++) {
		cout << nge[i] << " ";
	}

	return 0;
}
