#pragma once
#include "../Matrix/Matrix.hpp"

class File {
  public:
      File(std::string filename);
      File(Matrix matrix, std::string filename);
      Matrix read();
      int getColumnsCount();
      bool save();

  private:
      bool readFile();
      Matrix matrix;
      int columnsCount;
      std::string filename;
};
