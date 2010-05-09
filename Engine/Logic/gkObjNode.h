/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Nestor Silveira.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _gkObjNode_h_
#define _gkObjNode_h_

#include "gkLogicNode.h"

class gkGameObject;
class gkObjNode : public gkLogicNode
{
public:

	enum
	{
		UPDATE_OBJ,
		UPDATE_STATE,
		LOAD,
		UNLOAD,
		RELOAD,
		SET_LINEAR_VEL,
		SET_LINEAR_VEL_VALUE_X,
		SET_LINEAR_VEL_VALUE_Y,
		SET_LINEAR_VEL_VALUE_Z,
		SET_ROTATION,
		SET_ROTATION_VALUE,
		OBJ_POINTER,
		X,
		Y,
		RESET,
		HAS_OBJ,
		OBJ,
		OBJ_NAME,
		HIT_POINT,
		POSITION,
		ROTATION,
		MOTION,
		MESH_OBJ
	};

	DECLARE_SOCKET_TYPE(UPDATE_OBJ, bool);
	DECLARE_SOCKET_TYPE(UPDATE_STATE, bool);
	DECLARE_SOCKET_TYPE(LOAD, bool);
	DECLARE_SOCKET_TYPE(UNLOAD, bool);
	DECLARE_SOCKET_TYPE(RELOAD, bool);
	DECLARE_SOCKET_TYPE(SET_LINEAR_VEL, bool);
	DECLARE_SOCKET_TYPE(SET_LINEAR_VEL_VALUE_X, gkScalar);
	DECLARE_SOCKET_TYPE(SET_LINEAR_VEL_VALUE_Y, gkScalar);
	DECLARE_SOCKET_TYPE(SET_LINEAR_VEL_VALUE_Z, gkScalar);
	DECLARE_SOCKET_TYPE(SET_ROTATION, bool);
	DECLARE_SOCKET_TYPE(SET_ROTATION_VALUE, gkQuaternion);
	DECLARE_SOCKET_TYPE(OBJ_POINTER, gkGameObject*);
	DECLARE_SOCKET_TYPE(X, gkScalar);
	DECLARE_SOCKET_TYPE(Y, gkScalar);
	DECLARE_SOCKET_TYPE(RESET, bool);
	DECLARE_SOCKET_TYPE(HAS_OBJ, bool);
	DECLARE_SOCKET_TYPE(OBJ, gkGameObject*);
	DECLARE_SOCKET_TYPE(OBJ_NAME, gkString);
	DECLARE_SOCKET_TYPE(HIT_POINT, gkVector3);
	DECLARE_SOCKET_TYPE(POSITION, gkVector3);
	DECLARE_SOCKET_TYPE(ROTATION, gkQuaternion);
	DECLARE_SOCKET_TYPE(MOTION, bool);
	DECLARE_SOCKET_TYPE(MESH_OBJ, gkGameObject*);
	

	enum INPUT_TYPE
	{
		POINTER,
		NAME,
		SCREEN_XY
	};

    gkObjNode(gkLogicTree *parent, size_t id);

	virtual ~gkObjNode() {}

	bool evaluate(gkScalar tick);

	void setType(INPUT_TYPE type) {m_type = type;}

private:

	void updateState();

private:

	INPUT_TYPE m_type;

	gkGameObject* m_obj;
	gkGameObject* m_mesh;
	gkVector3 m_position;
	gkQuaternion m_rotation;
};

#endif//_gkObjNode_h_
