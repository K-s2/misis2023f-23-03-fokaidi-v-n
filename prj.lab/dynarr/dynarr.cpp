// 2023 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>

class DynArr {
public:
  //конструктор по умолчанию
  DynArr() {
    size_ = 0;
    capacity_ = 0;
    data_ = NULL;  
  }
  //конструктор копии
  DynArr(const DynArr& a) {
    size_ = a.Size();
    capacity_ = size_;
    data_ = NULL;
    if (size_ != 0) {
      data_ = new float[size_];
    }
    for (int i = 0; i < size_; i++) {
      data_[i] = a.data_[i];
    }
  }
  //конструктор по размеру
  DynArr(const std::ptrdiff_t& size){
    size_ = size;
    capacity_ = size_;
    data_ = new float[size_];
  }
  ~DynArr() {
    delete[] data_;
  }
  float& operator[](const std::ptrdiff_t idx) { return data_[idx]; }
  const float& operator[](const std::ptrdiff_t idx) const { return data_[idx]; }
  DynArr& operator=(const DynArr& rhs) {
    size_ = rhs.size_;
    capacity_ = size_;
    data_ = new float[size_];
    for (int i = 0; i < size_; i++) {
      data_[i] = rhs[i];
    }
  }

  std::ptrdiff_t Size() const noexcept { return size_; }
  void Resize(const std::ptrdiff_t size) {
    if (size > capacity_) {
      float* new_data_ = new float[size];
      for (std::ptrdiff_t ind = 0; ind < size; ind++) {
        delete[] data_;
        data_ = new_data_;
      }
    }
    size_ = size;
  }

private:
  std::ptrdiff_t size_ = 0; //!< число элементов в массиве
  std::ptrdiff_t capacity_ = 0; //вместимость массива
  float* data_ = NULL;          //!< элементы массива
};

#endif // !DYNARR_DYNARR_HPP_20231203

int main() {
  return 0;
}
