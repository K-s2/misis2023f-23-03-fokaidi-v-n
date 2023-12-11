#include <cstddef>

class DynArr {
public:
  DynArr() = default;
  DynArr(const DynArr&) = default;
  DynArr(const std::ptrdiff_t size) : size_(size), data_(new float[size]) { }
  ~DynArr() { delete[] data_; }
  DynArr& operator=(const DynArr&) = default;

  std::ptrdiff_t Size() const noexcept { return size_; }
  void resize(const std::ptrdiff_t size) {
    float* newData = new float[size];
    std::memcpy(newData, data_, std::min(size, size_) * sizeof(float));
    delete[] data_;
    data_ = newData;
    size_ = size;
  }
  float& operator[](const std::ptrdiff_t idx) { return data_[idx]; }
  const float& operator[](const std::ptrdiff_t idx) const { return data_[idx]; }

private:
  std::ptrdiff_t size_ = 0; //!< число элементов в массиве
  float* data_ = nullptr;   //!< элементы массива
};

