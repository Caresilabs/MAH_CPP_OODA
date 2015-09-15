#pragma once
#include "PtrList.h"

template <class K, class V>
class Registry
{
public:

						Registry(int startSize) : store(startSize) {}

	void				put(const K& key, V* value) { store.push_back(new Entry(key, value)); }

	V* get(const K& key) const {
		for (Entry** ptr = store.begin(); ptr != store.end(); ++ptr) {
			if (*ptr == nullptr) continue;
			if ((*ptr)->key == key) return (*ptr)->value;
		}
		return nullptr;
	}

	void remove(V* value) {
		for (Entry** ptr = store.begin(); ptr != store.end(); ++ptr) {
			if ((*ptr)->value == value) {
				store.pop_back(*ptr);
				return;
			}
		}
	}

private:
	struct Entry {
		const K			key;
		V*				value;

		Entry(const K& key, V* value) : key(key), value(value) {}
		~Entry() { delete value; }
	};

	PtrList<Entry>		store;

};

