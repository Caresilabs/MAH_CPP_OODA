#pragma once

#include "PtrList.h"

// The Registry holds a key and a value. The Value(V) will be stored on the heap and will release when the Registry is released.
// The key however (which should be small and simple is stored on the stack?)
template <class Key, class Value>
class Registry {
public:

	Registry( int startSize = 20 );

	Registry( const Registry<Key, Value>& rhs );

	Registry& operator=( const Registry<Key, Value>& rhs );

	void				put( const Key& key, Value* value );

	void				remove( Value* value );

	Value*				get( const Key& key ) const;

	bool				contains( const Key& key ) const;

	int					getCount() const { return store.getCount(); }

private:
	struct Entry {
		const Key				key;
		Value*					value;

		Entry( const Key& key, Value* value ) : key( key ), value( value ) {
		}

		Entry( const Entry& rhs ) : key( rhs.key ) {
			if ( rhs.value != nullptr ) {
				//1. this->value = rhs.value; 

				// 2. Really, there is no way to copy without breaking OO design. Is there a way? Maybe using malloc?
				// new V(rhs.value); will only copy the Base class and ignore the subclass

				// 3. Last one is OO friendly but causes issues with std::string
				this->value = static_cast<Value*>(malloc( sizeof( *rhs.value ) ));
				memcpy( this->value, rhs.value, sizeof( *rhs.value ) );
				//*value = *rhs.value;

			} else {
				this->value = nullptr;
			}
		}

		Entry& operator=( const Entry& rhs ) = delete; // Don't allow assigning.
		~Entry() { if ( value != nullptr ) delete value; }
	};

private:
	PtrList<Entry>			store;

};

// =============================
//		  Implementation 
// =============================

template <class Key, class Value>
Registry<Key, Value>::Registry( int startSize = 20 ) : store( startSize ) {
}

template <class Key, class Value>
Registry<Key, Value>::Registry( const Registry<Key, Value>& rhs ) : store( rhs.store ) {
}

template <class Key, class Value>
Registry<Key, Value>& Registry<Key, Value>::operator=( const Registry<Key, Value>& rhs ) {
	if ( this == rhs )
		return this;

	store = rhs.store;
}

template <class Key, class Value>
void Registry<Key, Value>::put( const Key& key, Value* value ) {
	// Check if already exists

	Entry* entry = nullptr;
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) {
			entry = *ptr;
			break;
		}
	}

	// Push new entry or change current
	if ( !entry ) {
		store.push_back( new Entry( key, value ) );
	} else {
		delete (entry->value); // Free replaced value
		entry->value = value;
	}
}

template <class Key, class Value>
bool Registry<Key, Value>::contains( const Key& key ) const {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) return true;
	}
	return false;
}

template <class Key, class Value>
Value* Registry<Key, Value>::get( const Key& key ) const {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->key == key ) return (*ptr)->value;
	}
	return nullptr;
}

template <class Key, class Value>
void Registry<Key, Value>::remove( Value* value ) {
	for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
		if ( *ptr == nullptr ) continue;
		if ( (*ptr)->value == value ) {
			store.remove( *ptr );
			return;
		}
	}
}
