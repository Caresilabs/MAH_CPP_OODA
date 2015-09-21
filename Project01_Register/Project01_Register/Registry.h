#pragma once

#include "PtrList.h"

// The Registry holds a key and a value. The Value(V) will be stored on the heap and will release when the Registry is released.
// The key however (which should be small and simple is stored on the stack?)
template <class K, class V>
class Registry {
public:

	Registry( int startSize );

	void				put( const K& key, V* value );

	void				remove( V* value );

	V*					get( const K& key ) const;

	bool				contains( const K& key ) const;

	int					getCount() const { return store.getCount(); }

private:
	struct Entry {
		const K				key;
		V*					value;

		Entry( const K& key, V* value ) : key( key ), value( value ) { 
		}

		Entry( const Entry& rhs ) : key( rhs.key ) {
			if ( rhs.value != nullptr ) {
				//1. this->value = rhs.value; 

				// 2. Really, there is no way to copy without breaking OO design. Is there a way? Maybe using malloc?
				// new V(rhs.value); will only copy the Base class and ignore the subclass
				
				// 3. Last one is OO friendly but causes issues with std::string
				this->value = static_cast<V*>(malloc(sizeof(*rhs.value)));
				memcpy(this->value, rhs.value, sizeof(*rhs.value));
				*value = *rhs.value;

			} else {
				this->value = nullptr;
			}
		}

		Entry& operator=( const Entry& rhs ) = delete; // Don't allow assigning.
		~Entry() { if (value != nullptr) delete value; }
	};

private:
	PtrList<Entry>			store;

};

// =============================
//		  Implementation 
// =============================

template <class K, class V>
Registry<K,V>::Registry( int startSize ) : store( startSize ) { 
}

template <class K, class V>
void Registry<K, V>::put( const K& key, V* value ) {
	// Check if already exists

	Entry* entry = nullptr;
	//for ( int i = 0; i < store.getSize(); ++i ) {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) {
			entry = *ptr;
			break;
		}
	}

	// Push new entry or change current
	if ( !entry ) {
		store.push( new Entry( key, value ) );
	} else {
		delete (entry->value);
		entry->value = value;
	}
}

template <class K, class V>
bool Registry<K, V>::contains( const K& key ) const {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) return true;
	}
	return false;
}

template <class K, class V>
V* Registry<K, V>::get( const K& key ) const {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) return (*ptr)->value;
	}
	return nullptr;
}

template <class K, class V>
void Registry<K, V>::remove( V* value ) {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->value == value ) {
			store.pop_back( *ptr );
			return;
		}
	}
}
