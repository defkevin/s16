#ifndef _S16_key_value_H__ // header guards
#define _S16_key_value_H__


#include "./dlist.h"

template <typename T1, typename T2>
struct key_value {
	T1 key;
	T2 value;
};

#endif // _S16_key_value_H__