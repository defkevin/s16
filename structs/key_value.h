#ifndef _S16_key_value_H__ // header guards
#define _S16_key_value_H__

template <typename K, typename V> struct key_value {
  key_value(K k, V v) : key(k), value(v) {}
  K key;
  V value;
};

#endif // _S16_key_value_H__