#include "ModelLoader.h"

//-----------------------------------------------------------------------------

modelMap ModelLoader::models;
collisionMap ModelLoader::collisions;

//-----------------------------------------------------------------------------

bool ModelLoader::LoadModel(const string modelName, char* fileName)
{
	if(!models[modelName])
	{
		models[modelName] = glmReadOBJ(fileName);

		glmUnitize(models[modelName]);

		glmFacetNormals(models[modelName]); 
		glmVertexNormals(models[modelName], 90.0);

		collisions[modelName] = CreateCollisionBox(models[modelName]);

		return true;
	}

	// model with this name has already been loaded
	return false;
}

//-----------------------------------------------------------------------------

bool ModelLoader::DrawModel(const string modelName)
{
	if(!models[modelName])
	{
		// model has not been loaded
		return false;
	}

	glmDraw(models[modelName], GLM_SMOOTH | GLM_TEXTURE);

	collisions[modelName]->DrawBox();

	return true;
}


//-----------------------------------------------------------------------------

BoundingBox* ModelLoader::CreateCollisionBox(GLMmodel* model)
{
	BoundingBox* box = (BoundingBox*)malloc(sizeof(BoundingBox));

	for(int i = 0; i < model->numtriangles; i++)
	{		
		GLfloat x = model->triangles->vindices[0];
		GLfloat y = model->triangles->vindices[1];
		GLfloat z = model->triangles->vindices[2];

		if(box->min.x > x) box->min.x = x;
		if(box->min.y > y) box->min.y = y;
		if(box->min.z > z) box->min.z = z;

		if(box->max.x < x) box->max.x = x;
		if(box->max.y < y) box->max.y = y;
		if(box->max.z < z) box->max.z = z;
	}

	return box;
}

//-----------------------------------------------------------------------------
