// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TEMPLATEBUFFER_H
#define TEMPLATEBUFFER_H

#include <cstddef>

using namespace std;

template <typename T = int, size_t sz = 8> class Buffer {
public:
  enum class Error { OK, FULL, EMPTY };

  Buffer();
  ~Buffer();

  Error add(const T &value);
  Error get(T &value);
  bool isEmpty();
  void flush();

  // Operator overloads
  //
  void operator<<(T value);
  void operator>>(T &value);

private:
  unsigned int read;
  unsigned int write;
  unsigned int numItems;

  T buffer[sz];
};

template <typename T, size_t sz> Buffer<T, sz>::Buffer() : buffer() { flush(); }

template <typename T, size_t sz> Buffer<T, sz>::~Buffer() {}

template <typename T, size_t sz>
typename Buffer<T, sz>::Error Buffer<T, sz>::add(const T &value) {
  if (numItems == sz) {
    return Error::FULL;
  } else {
    buffer[write] = value;

    ++numItems;
    ++write;
    if (write == sz)
      write = 0;

    return Error::OK;
  }
}

template <typename T, size_t sz>
typename Buffer<T, sz>::Error Buffer<T, sz>::get(T &value) {
  if (numItems == 0) {
    return Error::EMPTY;
  } else {
    value = buffer[read];

    --numItems;
    ++read;
    if (read == sz)
      read = 0;

    return Error::OK;
  }
}

template <typename T, size_t sz> bool Buffer<T, sz>::isEmpty() {
  return (numItems == 0);
}

template <typename T, size_t sz> void Buffer<T, sz>::flush() {
  read = 0;
  write = 0;
  numItems = 0;
}

template <typename T, size_t sz> void Buffer<T, sz>::operator<<(T value) {
  return add(value);
}

template <typename T, size_t sz> void Buffer<T, sz>::operator>>(T &value) {
  return get(value);
}

template <typename T, size_t sz> void operator>>(T value, Buffer<T, sz> &b) {
  return b.add(value);
}

template <typename T, size_t sz> void operator<<(T &value, Buffer<T, sz> &b) {
  return b.get(value);
}

#endif // TEMPLATEBUFFER_H
