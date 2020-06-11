#include <igl/readPLY.h>
#include "rimd.h"

int main(int argc, char *argv[]){

    Eigen::MatrixXd V;
    Eigen::MatrixXi F;


    igl::readPLY(argv[1], V, F);
    Mesh mesh_0(V, F);
    igl::readPLY(argv[2], V, F);
    Mesh mesh_1(V, F);

    RIMD rimd(mesh_0, mesh_1);

    auto feat = rimd.features;

    auto verts = rimd.solveReconstruct(feat);
    Mesh deform(verts, F);
    deform.show();

    return 0;
}
