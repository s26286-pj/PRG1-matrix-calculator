#pragma once
#include <vector>
#include "../Matrix/Matrix.hpp"

class File {
  public:
      File(std::string filename);
      File(Matrix matrix);
      Matrix getData();
      int getColumnsCount();
      bool save();

  private:
      bool read();
      Matrix matrix;
      int columnsCount;
      std::string filename;
};
