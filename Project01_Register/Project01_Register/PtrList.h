#pragma once


template <class T>
class PtrList {
public:

	PtrList( int maxSize = 10 ) : maxSize( maxSize ), size( 0 ) {
		this->data = new T*[maxSize];
	}

	// Don't allow copying
	PtrList( const PtrList& rhs ) = delete;

	PtrList&			operator=( const PtrList& rhs ) = delete;

	T*					operator[]( int i ) const { return data[i]; }

	T**					begin() const { return &data[0]; }

	T**					end() const { return &data[size]; }

	int					getSize() const { return size; }


	void push_back( T* item ) {
		if ( size >= maxSize ) {
			// Let's expand our array
			maxSize = maxSize * 2 + 1;
			auto newData = new T*[maxSize];

			// We dont need to kill our old data, just change our pointers. <3 Pointers <3
			for ( int i = 0; i < size; ++i ) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}

		data[size++] = item;
	}

	void pop_back( const T* item ) {
		for ( int i = 0; i < size; ++i ) {
			if ( data[i] == item ) {
				delete data[i];
				data[i] = nullptr;
			}
		}
	}

	~PtrList() {
		for ( int i = 0; i < size; ++i ) {
			if ( data[i] != nullptr )
				delete data[i];
		}
		delete[] data;
	}

	typedef typename T** iterator_t;

private:
	T**					data;
	int					maxSize;
	int					size;
};
