#ifndef REORDER_H
#define REORDER_H

#include <assimp/types.h> // This way, aiVector3D is available.
#include <assimp/mesh.h>

void reorder_model(unsigned int num_verts, struct aiVector3D *verts, unsigned int num_faces, struct aiFace *faces);

#endif /* REORDER_H */
