# RIMD Representation

The implementation of [Efficient and Flexible Deformation Representation for
Data-Driven Surface Modeling](https://users.cs.cf.ac.uk/Yukun.Lai/papers/DeformationTOG2016.pdf). ***I'm not the author of this paper.***


## Dependencies

The only dependencies are stl, eigen, [libigl](http://libigl.github.io/libigl/) and
the dependencies of the `igl::opengl::glfw::Viewer`.

The cmake build system will attempt to find libigl according to environment variables (e.g., `LIBIGL`) and searching in common desitinations (e.g., `/usr/local/libigl/`). If you haven't installed libigl before, we recommend you to clone a copy of libigl right here:

    cd libigl-example-project/
    git clone https://github.com/libigl/libigl.git

## Compile

Compile this project using the standard cmake routine:
```
    mkdir build
    cd build
    cmake ..
    make
```
This should find and build the dependencies and create a `rimd_bin` binary.

## Run

From within the `build` directory just issue:
```
./rimd_bin [baseMesh].ply [targetMesh].ply
```

## Reconstruction result
![](https://i.imgur.com/tPk1Lfc.png)
