#ifndef FILE_H
#define FILE_H

#include <fstream>

#include "builder.h"
#include "managerexception.h"

class File
{
public:
    File(const char* name) : fileName(name) { }
    std::shared_ptr< Model > loadModel(ModelBuilder& builder);
    void saveModel(const Model& model);

private:
    void openSave();
    void openLoad();
    void close();

    const char* fileName;
    std::ifstream in;
    std::ofstream out;
};

#endif // FILE_H
