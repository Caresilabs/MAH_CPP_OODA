#pragma once
#include "PtrList.h"

template <class K, class V>
class Registry {
public:

	Registry( int startSize ) : store( startSize ) { }

	void put( const K& key, V* value ) {
		// Check if already exists
		Entry* entry = nullptr;
		for ( int i = 0; i < store.getSize(); ++i ) {
			if ( store[i] == nullptr ) continue;
			if ( store[i]->key == key ) {
				entry = store[i];
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

	bool contains( const K& key ) const {
		for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
			if ( *ptr == nullptr ) continue;
			if ( (*ptr)->key == key ) return true;
		}
		return false;
	}

	V* get( const K& key ) const {
		for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
			if ( *ptr == nullptr ) continue;
			if ( (*ptr)->key == key ) return (*ptr)->value;
		}
		return nullptr;
	}

	void remove( V* value ) {
		for ( PtrList<Entry>::iterator_t ptr = store.begin(); ptr != store.end(); ++ptr ) {
			if ( *ptr == nullptr ) continue;
			if ( (*ptr)->value == value ) {
				store.pop_back( *ptr );
				return;
			}
		}
	}

	int getCount() {
		return store.getCount();
	}

private:
	struct Entry {
		const K				key;
		V*					value;

		Entry( const K& key, V* value ) : key( key ), value( value ) { }

		// We do allow copy constructor
		Entry( const Entry& rhs ) : key( rhs.key ) {
			if ( rhs.value == nullptr ) {
				this->value = rhs.value; // Really, there is no way to copy without breaking OO design. Is there a way? Maybe using malloc?
			} else {
				this->value = nullptr;
			}
		}

		Entry& operator=( const Entry& rhs ) = delete; // Don't allow assigning.
		~Entry() { delete value; }
	};

	PtrList<Entry>			store;

};

