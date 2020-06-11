#include "mesh.h"
#include <unsupported/Eigen/MatrixFunctions>
#include <iostream>
#include <queue>


class RIMD{
public:

    Mesh* baseMesh;
    Mesh* targetMesh;

    std::vector<Eigen::Matrix3d> transforms;
    std::vector<std::vector<Eigen::Matrix3d> > features;

    RIMD(Mesh&, Mesh&);

    std::vector<std::vector<Eigen::Matrix3d> > solveRIMD();

    // given RIMD features, reconstruct the target mesh
    Eigen::MatrixXd solveReconstruct(const std::vector<std::vector<Eigen::Matrix3d> >&);
    // if the RIMD feature is directly derived from the target mesh, run it.
    Eigen::MatrixXd quickReconstruct(const std::vector<std::vector<Eigen::Matrix3d> >&);


private:
    // input: base mesh and target mesh
    // output: transformations from base mesh to target mesh
    void solveTransform();

    std::vector<Eigen::Matrix3d> polarDecomposition(const Eigen::Matrix3d&);

    Eigen::Matrix3d compute_ring(const std::vector<std::vector<Eigen::Matrix3d> >&, const std::vector<Eigen::Matrix3d>&, int);

    void BFS_initialize(const std::vector<std::vector<Eigen::Matrix3d>>&, std::vector<Eigen::Matrix3d>&);

    void solveGlobalStep(Eigen::SimplicialCholesky<Eigen::SparseMatrix<double> >&, Eigen::VectorXd&, Eigen::VectorXd&, const std::vector<Eigen::Matrix3d>&, const std::vector<std::vector<Eigen::Matrix3d> >&);

    void solveLocalStep(const Eigen::VectorXd&, std::vector<Eigen::Matrix3d>&, const std::vector<std::vector<Eigen::Matrix3d> >&);

    double computeEnergy(const Eigen::VectorXd&, const std::vector<Eigen::Matrix3d>&, const std::vector<std::vector<Eigen::Matrix3d> >&);

};
