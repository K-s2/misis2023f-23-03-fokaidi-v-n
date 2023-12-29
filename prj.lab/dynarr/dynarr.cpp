// 2023 by Polevoi Dmitry under Unlicense

#pragma once

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <dynarr/dynarr.hpp>

DynArr::DynArr(const std::ptrdiff_t& size) {
  if (size < 1) {
    throw std::invalid_argument("Size mustr be natural number");
  }
  size_ = size;
  capacity_ = size;
  data_ = new float[size];
  for (std::ptrdiff_t i = 0; i < size; i++) {
    data_[i] = 0;
  }
}

  std::ptrdiff_t DynArr::Size() const noexcept { return size_; }

  void DynArr::Resize(const std::ptrdiff_t size) {
    if (size < 1) {
      throw std::invalid_argument("Size must be natural number");
    }
    if (size > capacity_) {
      float* new_data_ = new float[size];
      for (std::ptrdiff_t ind = 0; ind < capacity_; ind++) new_data_[ind] = data_[ind];
      delete[] data_;
      data_ = new_data_;
    }
    for (std::ptrdiff_t i = capacity_; i < size; i++) {
      data_[i] = 0;
    }
    size_ = size;
  }

float& DynArr::operator[](const std::ptrdiff_t index) {
    if ((index < 0 ) || (index >= size_)) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }

DynArr& DynArr::operator=(const DynArr& rhs) {
  delete[] data_;
  size_ = rhs.Size();
  capacity_ = size_;
  data_ = new float[size_];
  for (std::ptrdiff_t i = 0; i < size_; i++) {
    data_[i] = rhs[i];
  }
  return *this;
}


const float& DynArr::operator[](const std::ptrdiff_t index) const {
    if ((index < 0) ||  (index >= size_)) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }
