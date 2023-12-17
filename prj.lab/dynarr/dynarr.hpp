// 2023 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <iostream>


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
  DynArr(const std::ptrdiff_t& size);

  ~DynArr() = default;

  float& operator[](const std::ptrdiff_t index);

  const float& operator[](const std::ptrdiff_t index) const;

  [[nodiscard]] DynArr& operator=(const DynArr& rhs);

  std::ptrdiff_t Size() const noexcept;
  void Resize(const std::ptrdiff_t size);

private:
  std::ptrdiff_t size_ = 0; //!< число элементов в массиве
  std::ptrdiff_t capacity_ = 0; //вместимость массива
  float* data_ = NULL;          //!< элементы массива
};

std::ostream& operator<<(std::ostream& ostrm, DynArr& a) ;

#endif
