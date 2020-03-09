#pragma once
#include <string>
#include <vector>
#include <iostream>


// observer
template <typename T>
struct Observer
{
  virtual void field_changed(
    T& source,
    const std::string& field_name
  ) = 0;
};
