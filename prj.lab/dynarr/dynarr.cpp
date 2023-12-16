// 2023 by Polevoi Dmitry under Unlicense

#pragma once

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <dynarr/dynarr.hpp>

std::ostream& operator<<(std::ostream& ostrm, DynArr& a) {
  for (int i = 0; i < a.Size(); ++i) {
    ostrm << a[i] << ' ';
  }
  return ostrm;
}

  std::ptrdiff_t DynArr::Size() const noexcept { return size_; }

  void DynArr::Resize(const std::ptrdiff_t size) {
    if (size > capacity_) {
      float* new_data_ = new float[size];
      for (std::ptrdiff_t ind = 0; ind < capacity_; ind++) new_data_[ind] = data_[ind];
      delete[] data_;
      data_ = new_data_;
    }
    size_ = size;
  }

DynArr&  DynArr::operator=(const DynArr& rhs) {
    size_ = rhs.size_;
    capacity_ = size_;
    delete[] data_;
    data_ = new float[size_];
    for (int i = 0; i < size_; i++) {
      data_[i] = rhs[i];
    }
    return *this;
  }

float& DynArr::operator[](const std::ptrdiff_t index) {
    if ((index < 0 ) || (index >= size_)) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }

const float& DynArr::operator[](const std::ptrdiff_t index) const {
    if ((index < 0) ||  (index >= size_)) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }
