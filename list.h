#include<iostream>
using namespace std;
template<typename T>
class list {
	T* data;
	int size, n, it, sum;
	int find_idx(const T& val) const {
		for (int i = 0;i <= n;i++) {
			if (val == data[i])
				return i;
		}
		return -1;
	}
public:
	list(int s = 100) {
		size = s;
		data = new T[size];
		n = -1;
		it = -1;
		sum = 0;
	}
	~list() {
		delete[]data;
	}
	void insert(const T& val) {
		if (full()) {
			throw("List is full");
		}
		n++;
		data[n] = val;
		sum += val.getScore();
	}
	bool find(const T& val) const {
		return (find_idx(val) >= 0);
	}
	bool update(const T& old_val, const T& new_val) {
		int idx = find_idx(old_val);
		if (idx >= 0) {
			data[idx] = new_val;
			return true;
		}
		return false;
	}
	bool erase(const T& val) {
		int idx = find_idx(val);
		if (idx >= 0) {
			data[idx] = data[n];
			n--;
			return true;
		}
		return false;
	}
	bool empty() const {
		return n == -1;
	}
	bool full() const {
		return n == size - 1;
	}
	void make_empty() {
		n = -1;
	}
	int length()const {
		return n + 1;
	}
	void reset() {
		it = -1;
	}
	bool is_last() const {
		return it == n;
	}
	T get_next() {
		if (is_last()) {
			throw("Last Element Reached");
		}
		it++;
		return data[it];
	}
	void operator=(const list<T>& rhs) {
		delete[]data;
		size = rhs.size;
		data = new T[size];
		n = rhs.n;
		it = -1;
		for (int i = 0;i < size;i++) {
			data[i] = rhs.data[i];
		}
	}
	list(const list<T>& rhs) {
		size = rhs.size;
		data = new T[size];
		n = rhs.n;
		it = -1;
		for (int i = 0;i < size;i++) {
			data[i] = rhs.data[i];
		}
	}
	int getSum() const {
		return sum;
	}
};
