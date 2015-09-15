#pragma once

template <class T>
class PtrList
{
public:
	
						PtrList(int maxSize = 10) : maxSize(maxSize), size(0) { this->data = new T*[maxSize]; }

						// Dont allow copying
						PtrList(const PtrList& rhs) = delete;

	PtrList&			operator=(const PtrList& rhs) = delete;

	T*					operator[](int i) const { return data[i]; }

	int					getSize() const { return size; }

	T**					begin() const { return &data[0]; }

	T**					end() const { return &data[size]; }


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

	~PtrList() {
		for (int i = 0; i < size; ++i) {
			if (data[i] != nullptr)
				delete data[i];
		}
		delete[] data;
	}

private:
	T**					data;
	int					maxSize;
	int					size;
};
