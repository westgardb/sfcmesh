#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "reorder.h"
#include "morton.h"

bool import_model(const char *fp)
{
	const struct aiScene *scene = aiImportFile(fp,
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_ValidateDataStructure);

	if(!scene || !scene->mRootNode || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE) {
		printf("Failed to load model!\n");
		return false;
	}

	// Just printing some data to make sure everything is working.
	printf("num meshes: %u\n", scene->mNumMeshes);
	printf("num vertices: %u\n", scene->mMeshes[0]->mNumVertices);

	struct aiMesh *mesh = scene->mMeshes[0];
	struct aiVector3D *verts = mesh->mVertices;
	for(unsigned int i = 0; i < mesh->mNumVertices; ++i) {
		printf("%f, %f, %f\n", verts[i].x, verts[i].y, verts[i].z);
	}
	printf("\n");	
	struct aiFace *faces = mesh->mFaces;
	for(unsigned int i = 0; i < mesh->mNumFaces; ++i) {
		printf("%u, %u, %u\n", faces[i].mIndices[0], faces[i].mIndices[1], faces[i].mIndices[2]);
	}

	aiReleaseImport(scene);
	return true;
}

int main(int argc, char *argv[])
{
	if(argc == 2) {
		printf("Opening file: %s\n", argv[1]);
		import_model(argv[1]);
	} else {
		printf("Usage: sfcmesh input\n");
	}

	const unsigned int foo = 2;

	for(unsigned int i = 0; i < foo; ++i) {
		for(unsigned int j = 0; j < foo; ++j) {
			for(unsigned int k = 0; k < foo; ++k) {
				printf("Morton encoding of (%u, %u, %u): %" PRIu64 "\n", i,j,k, mortonEncode(i, j, k));
			}
		}
	}


	return 0;
}
