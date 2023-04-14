#include<iostream>
#include<time.h>
#define size 10
using namespace std;
struct Queue {
	int a[size];
	int front;
	int rear;
};
void createQueue(Queue& q) {
	q.front = -1;//front is pos of first value
	q.rear = -1;//rear is pos of last value
}
int isEmpty(Queue q) {
	if (q.front == -1) return 1;
	else return 0;
}
int enQueue(Queue& q, int x) {
	int f, r;
	if (q.rear - q.front + 1 == size) return 0;// case 1 Queue is full
	else {
		if (isEmpty(q)==1) //case 2 Queue is empty 
		{
			q.front = 0;
			q.rear = 0;
		}
		if (q.rear == size - 1)// case 3 Queue is full virtually
		{
			f = q.front;
			r = q.rear;
			for (int i = f; i <= r; i++) q.a[i - f] = q.a[i];
			q.front = 0;
			q.rear = r - f;
		}
		q.a[q.rear] = x;
		//q.rear++;
		q.rear++;
		return 1;
	}
}
int deQueue(Queue& q, int &x) {
	if (isEmpty(q) == 0) {
		x = q.a[q.front];
		q.front++;
		if (q.front > q.rear) {
			q.front = -1;
			q.rear = -1;
		}
		return 1;
	}
	else {
		cout << "Queue is empty...";
		return 0;
	}
}
int frontPos(Queue q) {
	if (isEmpty(q) == 0) {
		return q.a[q.front];
	}
}
void print(Queue q) {
	for (int i = 0; i < size; i++) {
		cout << frontPos(q) << " ";
		q.front++;
	}
}
int main() {
	Queue qs;
	createQueue(qs);
	srand(time(NULL));
	/*for (int i = 0; i < size; i++) {
		cout<<enQueue(qs, rand() % 100)<<"\n";
		print(qs);
		cout << endl;
	}*/
	//cout << qs.rear << " --()-- " << qs.front << endl;
	while (qs.rear - qs.front + 1 < size) {
		cout << enQueue(qs, rand() % 100) << "\n";
		cout << qs.rear << " --()-- " << qs.front << endl;
		print(qs);
		cout << endl;
	}
	cout << qs.rear << " --()-- " << qs.front << endl;
	cout << endl;
	print(qs);
	int x;
	deQueue(qs, x);
	cout <<"\n" << x << "\n";
	print(qs);
	//system("pause");
	return 0;
}

