#include "manager.h"

std::shared_ptr< Model > FileManager::load(File& loader, ModelBuilder& builder)
{
    return loader.loadModel(builder);
}

void FileManager::save(ObjectIterator begin, ObjectIterator end, File& saver)
{
    ObjectIterator iter = begin;
    for (; iter != end; ++iter) {
        std::shared_ptr< Object > obj = *iter;
        Model model = *(Model*)obj.get();
        saver.saveModel(model);
    }
}

void DrawManager::draw(ObjectIterator begin, ObjectIterator end, Drawer &drawer)
{
    ObjectIterator iter = begin;
    for (; iter != end; ++iter) {
        std::shared_ptr< Object > obj = *iter;
        Model model = *(Model*) obj.get();

        std::vector< Point3D > points = model.getConstPoints();
        std::vector< Edge > edges = model.getConstEdges();

        for (size_t i = 0; i < edges.size(); ++i) {
            drawer.drawLine(Point2D(points[edges[i].getStart()]),
                            Point2D(points[edges[i].getFinish()]));
        }
    }
}
