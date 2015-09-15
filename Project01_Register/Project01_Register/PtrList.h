#pragma once

template <class T>
class PtrList
{
public:
	PtrList(int maxSize = 10) : maxSize(maxSize), size(0) {
		data = new T*[maxSize];
	}

	virtual ~PtrList() {
		for (auto i = data; i < data + size; ++i) {
			delete i;
		}
		delete[] data;
	}

	// Dont allow copying
	PtrList(const PtrList& rhs) = delete;
	PtrList& operator=(const PtrList& rhs) = delete;

	const T& operator[](int i) const {
		return *data[i];
	}

	void push_back(T* item){
		if (size >= maxSize) {

		}
		data[size++] = item;
	}

	void pop_back(T* item){
		for (T* i = data; i != data + size; ++i) {
			if (i == item) {
				delete data[i];
				data[i] = nullptr;
			}
		}
	}

private:
	T** data;
	int maxSize;
	int size;
};
