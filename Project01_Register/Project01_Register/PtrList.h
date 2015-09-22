#pragma once

#include <math.h>

template <class T>
class PtrList {
public:

	PtrList( int maxSize = 10 );

	PtrList( const PtrList<T>& rhs );

	PtrList& operator=( const PtrList& rhs );

	T*					operator[]( int i ) const { return data[i]; }

	T**					begin() const { return &data[0]; }

	T**					end() const { return &data[count]; }

	int					getCount() const { return count; }


	void				push_back( T* item );

	void				remove( const T* item );

	void				checkExpand();

	~PtrList();

	typedef typename T** iterator_t;

private:
	T**					data;
	int					maxSize;
	int					count;
};


// =============================
//		  Implementation 
// =============================
template <class T>
PtrList<T>::PtrList( int maxSize = 10 ) : maxSize( maxSize ), count( 0 ) {
	this->data = new T*[maxSize] { nullptr };
}

template <class T>
PtrList<T>::PtrList( const PtrList<T>& rhs ) : maxSize( rhs.maxSize ), count( rhs.count ) {
	data = new T*[maxSize] { nullptr };
	for ( int i = 0; i < count; ++i ) {
		if ( rhs.data[i] != nullptr ) {
			data[i] = new T( *rhs.data[i] );
		} else {
			data[i] = nullptr;
		}
	}
}

template<class T>
PtrList<T>& PtrList<T>::operator=( const PtrList& rhs ) {
	auto newData = new T*[rhs.maxSize] { nullptr };

	for ( int i = 0; i < max( count, rhs.count ); ++i ) {
		if ( i < count )
			delete data[i];

		if ( i < rhs.count && rhs.data[i] != nullptr ) {
			newData[i] = new T( *rhs.data[i] );
		}
	}

	delete[] data;
	data = newData;
	count = rhs.count;
	maxSize = rhs.maxSize;
}

template <class T>
void PtrList<T>::push_back( T* item ) {
	checkExpand();

	data[count++] = item;
}

template <class T>
void PtrList<T>::remove( const T* item ) {
	for ( int i = 0; i < count; ++i ) {
		if ( data[i] == item ) {
			--count;
			delete data[i];

			// Swap with front item
			data[i] = data[count];
			data[count] = nullptr;
			return;
		}
	}
}

template <class T>
void PtrList<T>::checkExpand() {
	if ( count >= maxSize ) {
		// Let's expand our array
		maxSize = maxSize * 2 + 1;
		auto newData = new T*[maxSize] { nullptr };

		// We dont need to kill our old data, just change our pointers. <3 Pointers <3
		for ( int i = 0; i < count; ++i ) {
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
	}
}

template <class T>
PtrList<T>::~PtrList() {
	for ( int i = 0; i < count; ++i ) {
		if ( data[i] != nullptr )
			delete data[i];
	}
	delete[] data;
}
