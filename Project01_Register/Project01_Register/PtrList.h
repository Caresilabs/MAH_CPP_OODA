#pragma once

template <class T>
class PtrList
{
public:
	PtrList(int maxSize = 10) : maxSize(maxSize), size(0) {
		data = new T*[maxSize];
	}

	virtual ~PtrList() {
		for (int i = 0; i < size; ++i) {
			if (data[i] != nullptr)
				delete data[i];
		}
		delete[] data;
	}

	// Dont allow copying
	PtrList(const PtrList& rhs) = delete;
	PtrList& operator=(const PtrList& rhs) = delete;

	T* operator[](int i) const {
		return data[i]; // cannot return null;
	}

	int getSize() const {
		return size;
	}

	void push_back(T* item) {
		if (size >= maxSize) {
			maxSize = maxSize * 2 + 1;
			auto newData = new T*[maxSize];
			for (int i = 0; i < size; ++i) {
				newData[i] = data[i];
				//delete data[i];
			}
			delete[] data;
			data = newData;
		}

		data[size++] = item;
	}

	void pop_back(const T* item) {
		for (int i = 0; i < size; ++i) {
			if (data[i] == item) {
				delete data[i];
				data[i] = nullptr;
			}
		}
	}

	T** begin() const {
		return &data[0];
	}

	T** end() const {
		return &data[size];
	}

	

private:
	T**					data;
	int					maxSize;
	int					size;
};
