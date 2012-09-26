#pragma once

//-----------------------------------------------------------------------------

#define GLUT_DISABLE_ATEXIT_HACK

#include <map>
#include <string>
#include <iostream>
#include "glm.h"
#include "BoundingBox.h"

//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------

typedef map<string, GLMmodel*> modelMap;
typedef map<string, BoundingBox*> collisionMap;

//-----------------------------------------------------------------------------

/**
 * \file ModelLoader.h ModelLoader.cpp
 * \class ModelLoader
 * \brief Model Loader class implementation
 *
 *		Leverages the GLM modules provided by Tudor Cerean at the website
 *		http://www.3dcodingtutorial.com to load in OBJ model files and their
 *		TGA texture files. Usage instructions are in the accompanying
 *		README file.
 *
 * \author Timothy Veletta
 * \date 23/09/12
 * \version 01 - Timothy Veletta, 23/09/12
 *		Created header and class file and added implementaion for the
 *		LoadModel and DrawModel functions.
 */
class ModelLoader
{
public:
	/**
	 * \brief Loads the model.
	 *
	 * Loads the given model into the class and gives it a specified name 
	 * which is used to access the model when it is to be drawn. Each name
	 * must be unique and if not the function will return false.
	 *
	 * \param modelName the name to reference the model to be loaded in
	 * \param fileName the model file
	 * \retval whether or not loading in the model was successful
	 */
	static bool LoadModel(const string modelName, char* fileName);

	/**
	 * \brief Draws a model.
	 *
	 * Draws the model based upon the reference name and will fail if the
	 * model has not been loaded into the class.
	 *
	 * \param modelName the reference model name
	 * \retval whether or not drawing the model was successful
	 */
	static bool DrawModel(const string modelName);
	
private:
	static modelMap models; /**<! Contains references to all the models
							 * that have been loaded into the model loader */
	static collisionMap collisions;

	static BoundingBox* CreateCollisionBox(GLMmodel* model);
};

//-----------------------------------------------------------------------------