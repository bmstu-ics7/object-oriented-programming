#ifndef SCENE_H
#define SCENE_H

#include "scenecontainer.h"
#include "manager.h"

class Scene
{
public:
    Scene() { }

    SceneContainer& getObjects() { return objects; }
    FileManager& getFileManager() { return fileMan; }
    DrawManager& getDrawManager() { return drawMan; }
    TransformManager& getTransformManager() { return transformMan; }
    DeleteManager& getDeleteManager() { return deleteMan; }

private:
    SceneContainer objects;

    FileManager fileMan;
    DrawManager drawMan;
    TransformManager transformMan;
    DeleteManager deleteMan;
};

#endif // SCENE_H
