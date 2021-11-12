#pragma once
#include <vector>
#include "../Matrix/Matrix.hpp"

class File {
  public:
      File(std::string filename);
      Matrix getData();
      int getColumnsCount();
      bool save(std::string filename);

  private:
      bool read();
      Matrix matrix;
      int columnsCount;
      std::string filename;
};
