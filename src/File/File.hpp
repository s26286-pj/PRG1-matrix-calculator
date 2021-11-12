#pragma once
#include <vector>

class File {
  public:
      File(std::string filename);
      std::vector<double> getData();
      int getColumnsCount();

  private:
      std::vector<double> data;
      int columnsCount;  
};
