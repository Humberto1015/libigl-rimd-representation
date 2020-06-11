#include <igl/opengl/glfw/Viewer.h>
#include <igl/cotmatrix.h>

/*
    The definition of Mesh structures
*/

class Mesh{
public:

    Eigen::MatrixXd verts;
    Eigen::MatrixXi faces;

    // for each vertex, return the indices of its neighbors
    std::vector<std::vector<int> > neighbors;
    // Note that: for each vertex, return the cotangent weight on """j-th neighbor"""
    std::vector<std::vector<double> > cot_weights;

    Mesh(const Eigen::MatrixXd, const Eigen::MatrixXi);

    void show();

private:
    void buildCotWeights();
};
