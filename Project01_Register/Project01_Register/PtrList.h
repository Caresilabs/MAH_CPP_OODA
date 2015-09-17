#pragma once


template <class T>
class PtrList {
public:

	PtrList( int maxSize = 10 ) : maxSize( maxSize ), size( 0 ), count( 0 ) {
		this->data = new T*[maxSize] { nullptr };
	}

	PtrList( const PtrList<T>& rhs ) : maxSize( rhs.maxSize ), size( rhs.size ), count( 0 ) {
		data = new T*[maxSize] { nullptr };
		for ( int i = 0; i < size; ++i ) {
			if ( rhs.data[i] != nullptr ) {
				data[i] = new T( *rhs.data[i] );
			} else {
				data[i] = nullptr;
			}
		}
	}

	PtrList& operator=( const PtrList& rhs ) {
		maxSize = rhs.maxSize;
		auto newData = new T*[maxSize] { nullptr };

		for ( int i = 0; i < size; ++i ) {
			delete data[i];
			if ( i < rhs.maxSize && rhs.data[i] != nullptr ) {
				newData[i] = new T( *rhs.data[i] );
			} else {
				newData[i] = nullptr;
			}
		}
		delete[] data;
		data = newData;
		size = rhs.size;
		count = rhs.count;
	}

	T*					operator[]( int i ) const { return data[i]; }

	T**					begin() const { return &data[0]; }

	T**					end() const { return &data[size]; }

	int					getCount() const { return count; }

	int					getSize() const { return size; }


	void push_back( T* item ) {
		checkExpand();

		data[size++] = item;
		++count;
	}

	void push( T* item ) {
		for ( int i = 0; i < size; ++i ) {
			if ( data[i] == nullptr ) {
				data[i] = item;
				count++;
				return;
			}
		}

		// If no nullptr was found, push_back
		push_back( item );
	}

	void pop_back( const T* item ) {
		for ( int i = 0; i < size; ++i ) {
			if ( data[i] == item ) {
				delete data[i];
				data[i] = nullptr;
				--count;
				return;
			}
		}
	}

	void checkExpand() {
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
	int					count;
};
