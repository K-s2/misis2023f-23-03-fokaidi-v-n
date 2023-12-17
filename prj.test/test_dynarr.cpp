#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarr/dynarr.hpp>

TEST_CASE("Конструктор по умолчанию создает пустой массив") {
  DynArr arr;
  CHECK(arr.Size() == 0);
}

TEST_CASE("Конструктор с размером создает массив указанного размера") {
  const std::ptrdiff_t size = 5;
  DynArr arr(size);
  CHECK(arr.Size() == size);
}

TEST_CASE("Конструктор по умолчанию создает пустой массив") {
  DynArr arr;
  CHECK(arr.Size() == 0);
}

TEST_CASE("Конструктор с размером создает массив с указанным размером") {
  const std::ptrdiff_t size = 5;
  DynArr arr(size);
  CHECK(arr.Size() == size);
}

TEST_CASE("Копирующий конструктор создает копию массива") {
  const std::ptrdiff_t size = 3;
  DynArr original(size);
  original[0] = 1.0f;
  original[1] = 2.0f;
  original[2] = 3.0f;

  DynArr copy(original);

  CHECK(copy.Size() == size);
  CHECK(copy[0] == original[0]);
  CHECK(copy[1] == original[1]);
  CHECK(copy[2] == original[2]);
}

TEST_CASE("Конструктор с изменением размера создает массив с указанным размером") {
  const std::ptrdiff_t size = 3;
  DynArr arr(size);
  arr[0] = 1.0f;
  arr[1] = 2.0f;
  arr[2] = 3.0f;

  const std::ptrdiff_t newSize = 5;
  DynArr resizedArr(newSize);

  CHECK(resizedArr.Size() == newSize);
  CHECK(resizedArr[0] == 0.0f);  // Новые элементы должны быть инициализированы значением 0.0
  CHECK(resizedArr[1] == 0.0f);
  CHECK(resizedArr[2] == 0.0f);
  CHECK(resizedArr[3] == 0.0f);
  CHECK(resizedArr[4] == 0.0f);
}

TEST_CASE("Оператор присваивания копирует содержимое массива") {
  const std::ptrdiff_t size = 3;
  DynArr original(size);
  original[0] = 1.0f;
  original[1] = 2.0f;
  original[2] = 3.0f;

  DynArr copy;
  copy = original;

  CHECK(copy.Size() == size);
  CHECK(copy[0] == original[0]);
  CHECK(copy[1] == original[1]);
  CHECK(copy[2] == original[2]);
}

TEST_CASE("Копирующий конструктор создает глубокую копию массива") {
  DynArr arr(3);
  arr[0] = 1.0f;
  arr[1] = 2.0f;
  arr[2] = 3.0f;

  DynArr copy(arr);

  CHECK(copy.Size() == arr.Size());
  CHECK(copy[0] == arr[0]);
  CHECK(copy[1] == arr[1]);
  CHECK(copy[2] == arr[2]);

  copy[0] = 10.0f;
  CHECK(arr[0] == 1.0f);
}

TEST_CASE("Инициализация всех элементов нулями") {
  const std::ptrdiff_t size = 5;

  // Создание объекта DynArr
  DynArr myDynArr(size);

  // Проверка, что все элементы равны нулю
  for (std::ptrdiff_t i = 0; i < size; ++i) {
    CHECK(myDynArr[i] == 0.0f);
  }
}
TEST_CASE("Инициализация новых элементов нулями при изменении размера") {
  const std::ptrdiff_t initialSize = 3;
  const std::ptrdiff_t newSize = 5;

  // Создание объекта DynArr
  DynArr myDynArr(initialSize);

  // Проверка, что все элементы равны нулю
  for (std::ptrdiff_t i = 0; i < initialSize; ++i) {
    CHECK(myDynArr[i] == 0.0f);
  }

  // Изменение размера на больший
  myDynArr.Resize(newSize);

  // Проверка, что новые элементы инициализированы нулем
  for (std::ptrdiff_t i = initialSize; i < newSize; ++i) {
    CHECK(myDynArr[i] == 0.0f);
  }
}

TEST_CASE("Оператор присваивания создает глубокую копию массива") {
  DynArr arr(3);
  arr[0] = 1.0f;
  arr[1] = 2.0f;
  arr[2] = 3.0f;

  DynArr copy;
  copy = arr;

  CHECK(copy.Size() == arr.Size());
  CHECK(copy[0] == arr[0]);
  CHECK(copy[1] == arr[1]);
  CHECK(copy[2] == arr[2]);

  copy[0] = 10.0f;
  CHECK(arr[0] == 1.0f);
}
