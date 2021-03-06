//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2018 NVIDIA Corporation. All rights reserved.


#ifndef RENDER_DEBUG_TYPED_H
#define RENDER_DEBUG_TYPED_H

#include "RenderDebug.h"


namespace physx
{
	class PxVec2;
	class PxVec3;
	class PxVec4;
	class PxMat33;
	class PxMat44;
	class PxTransform;
	class PxQuat;
	class PxBounds3;
	class PxPlane;
}

namespace RENDER_DEBUG
{

/**
\brief This is an optional interface class which provides typed definition variants which accept  the NVIDIA standard foundation math data types.

Call 'getRenderDebugTyped' on the RenderDebug base class to retrieve this interface.  
The default interface does not have any additional dependencies on any other header files beyond simply <stdint.h>
*/
class RenderDebugTyped : public RenderDebug
{
public:
	/**
	\brief Draw a polygon; 'points' is an array of 3d vectors.

	\param pcount The number of data points in the polygon.
	\param points The array of Vec3 points comprising the polygon boundary
	*/
	virtual void  debugPolygon(uint32_t pcount,
								const physx::PxVec3 *points) = 0;	

	/**
	\brief Draw a single line using the current color state

	\param p1 Starting position
	\param p2 Line end position
	*/
	virtual void  debugLine(const physx::PxVec3 &p1,	
							const physx::PxVec3 &p2) = 0;

	/**
	\brief Draw a gradient line (different start color from end color)

	\param p1 The starting location of the line in 3d
	\param p2 The ending location of the line in 3d
	\param c1 The starting color as a 32 bit ARGB format
	\param c2 The ending color as a 32 bit ARGB format
	*/
	virtual void  debugGradientLine(const physx::PxVec3 &p1,	
									const physx::PxVec3 &p2,	
									const uint32_t &c1,	
									const uint32_t &c2) = 0; 

	/**
	\brief Draws a wireframe line with a small arrow head pointing along the direction vector ending at P2

	\param p1 The start of the ray
	\param p2 The end of the ray, where the arrow head will appear
	*/
	virtual void  debugRay(const physx::PxVec3 &p1,	
						   const physx::PxVec3 &p2) = 0; 

	/**
	\brief Create a debug visualization of a cylinder from P1 to P2 with radius provided.

	\param p1 The starting point of the cylinder
	\param p2 The ending point of the cylinder 
	\param radius The radius of the cylinder
	*/
	virtual void  debugCylinder(const physx::PxVec3 &p1,	
								const physx::PxVec3 &p2,	
								float radius) = 0;	

	/**
	\brief Creates a debug visualization of a 'thick' ray.  Extrudes a cylinder visualization with a nice arrow head.

	\param p1 Starting point of the ray
	\param p2 Ending point of the ray
	\param raySize The thickness of the ray, the arrow head size is used for the arrow head.
	\param arrowTip Whether or not the arrow tip should appear, by default this is true.
	*/
	virtual void  debugThickRay(const physx::PxVec3 &p1,	
								const physx::PxVec3 &p2,	
								float raySize=0.02f,	
								bool arrowTip=true) = 0;

	/**
	\brief Creates a debug visualization of a plane equation as a couple of concentric circles

	\param plane The plane equation
	\param radius1 The inner radius of the plane visualization
	\param radius2 The outer radius of the plane visualization
	*/	
	virtual void  debugPlane(const physx::PxPlane &plane, 
							float radius1,	
							float radius2) = 0; 

	/**
	\brief Debug visualize a 3d triangle using the current render state flags

	\param p1 First point in the triangle
	\param p2 Second point in the triangle
	\param p3 The third point in the triangle
	*/
	virtual void  debugTri(const physx::PxVec3 &p1,	
							const physx::PxVec3 &p2,
							const physx::PxVec3 &p3) = 0;

	/**
	\brief Debug visualize a 3d triangle with provided vertex lighting normals.

	\param p1 First point in the triangle
	\param p2 Second point in the triangle
	\param p3 The third point in the triangle
	\param n1 First normal in the triangle
	\param n2 Second normal in the triangle
	\param n3 The third normal in the triangle
	*/
	virtual void  debugTriNormals(const physx::PxVec3 &p1,
								const physx::PxVec3 &p2,
								const physx::PxVec3 &p3,
								const physx::PxVec3 &n1,
								const physx::PxVec3 &n2,
								const physx::PxVec3 &n3) = 0;

	/**
	\brief Debug visualize a 3d triangle with a unique color at each vertex.

	\param p1 First point in the triangle
	\param p2 Second point in the triangle
	\param p3 The third point in the triangle
	\param c1 The color of the first vertex
	\param c2 The color of the second vertex
	\param c3 The color of the third vertex
	*/
	virtual void  debugGradientTri(const physx::PxVec3 &p1,
									const physx::PxVec3 &p2,
									const physx::PxVec3 &p3,
									const uint32_t &c1,
									const uint32_t &c2,
									const uint32_t &c3) = 0;

	/**
	\brief Debug visualize a 3d triangle with provided vertex normals and colors

	\param p1 First point in the triangle
	\param p2 Second point in the triangle
	\param p3 The third point in the triangle
	\param n1 First normal in the triangle
	\param n2 Second normal in the triangle
	\param n3 The third normal in the triangle
	\param c1 The color of the first vertex
	\param c2 The color of the second vertex
	\param c3 The color of the third vertex
	*/
	virtual void  debugGradientTriNormals(const physx::PxVec3 &p1,
											const physx::PxVec3 &p2,
											const physx::PxVec3 &p3,
											const physx::PxVec3 &n1,
											const physx::PxVec3 &n2,
											const physx::PxVec3 &n3,
											const uint32_t &c1,
											const uint32_t &c2,
											const uint32_t &c3) = 0;

	/**
	\brief Debug visualize a 3d bounding box using the current render state.

	\param bounds The axis aligned bounding box to render.
	*/
	virtual void  debugBound(const physx::PxBounds3 &bounds) = 0;

	/**
	\brief Debug visualize a crude sphere using the current render state settings.

	\param pos The center of the sphere
	\param radius The radius of the sphere.
	\param subdivision The number of subdivisions to use, controls how detailed the sphere is.
	*/
	virtual void  debugSphere(const physx::PxVec3 &pos,	
								float radius,
								uint32_t subdivision=2) = 0;	

	/**
	\brief Debug visualize an oriented circle.

	\param center The center of the circle
	\param radius The radius of the circle
	\param subdivision The number of subdivisions
	*/
	virtual void  debugCircle(const physx::PxVec3 &center,
							float radius,		
							uint32_t subdivision) = 0;	

	/**
	\brief Debug visualize a simple point as a small cross

	\param pos The position of the point
	\param radius The size of the point visualization.
	*/
	virtual void  debugPoint(const physx::PxVec3 &pos,	
							float radius) = 0;	

	/**
	\brief Debug visualize a simple point with provided independent scale on the X, Y, and Z axis

	\param pos The position of the point
	\param scale The X/Y/Z scale of the crosshairs.
	*/
	virtual void  debugPoint(const physx::PxVec3 &pos,	
							const physx::PxVec3 &scale) = 0; 

	/**
	\brief Debug visualize a quad in screenspace (always screen facing)

	\param pos The position of the quad
	\param scale The 2d scale
	\param orientation The 2d orientation in radians
	*/
	virtual void  debugQuad(const physx::PxVec3 &pos,		
							const physx::PxVec2 &scale,	
							float orientation) = 0;	

	/**
	\brief Debug visualize a 4x4 transform.

	\param transform The matrix we are trying to visualize
	\param distance The size of the visualization
	\param brightness The brightness of the axes
	\param showXYZ Whether or not to print 3d text XYZ labels
	\param showRotation Whether or not to visualize rotation or translation axes
	\param axisSwitch Which axis is currently selected/highlighted.
	*/
	virtual void  debugAxes(const physx::PxMat44 &transform,	
							float distance=0.1f,		
							float brightness=1.0f,		
							bool showXYZ=false,			
							bool showRotation=false,	
							uint32_t axisSwitch=0,
							DebugAxesRenderMode::Enum renderMode=DebugAxesRenderMode::DEBUG_AXES_RENDER_SOLID) = 0;
	/**
	\brief Debug visualize an arc as a line with an arrow head at the end.

	\param center The center of the arc
	\param p1 The starting position of the arc
	\param p2 The ending position of the arc
	\param arrowSize The size of the arrow head for the arc.
	\param showRoot Whether or not to debug visualize the center of the arc
	*/
	virtual void debugArc(const physx::PxVec3 &center,	
							const physx::PxVec3 &p1,		
							const physx::PxVec3 &p2,		
							float arrowSize=0.1f,	
							bool showRoot=false) = 0; 

	/**
	\brief Debug visualize a thick arc

	\param center The center of the arc
	\param p1 The starting position of the arc
	\param p2 The ending position of the arc
	\param thickness The thickness of the cylinder drawn along the arc
	\param showRoot Whether or not to debug visualize the center of the arc
	*/
	virtual void debugThickArc(const physx::PxVec3 &center,// The center of the arc
								const physx::PxVec3 &p1,	// The starting position of the arc
								const physx::PxVec3 &p2,	// The ending position of the arc
								float thickness=0.02f,// How thick the arc is.
								bool showRoot=false) = 0;// Whether or not to debug visualize the center of the arc

	/**
	\brief Debug visualize a text string rendered a 3d wireframe lines.  Uses a printf style format.  Not all special symbols available, basic upper/lower case an simple punctuation.

	\param pos The position of the text
	\param fmt The printf style format string
	*/
	virtual void debugText(const physx::PxVec3 &pos,	
							const char *fmt,...) = 0;	

	/**
	\brief Set's the view matrix as a full 4x4 matrix.  Required for screen-space aligned debug rendering. If you are not trying to do screen-facing or 2d screenspace rendering this is not required.

	\param view The 4x4 view matrix  This is not transmitted remotely to the server, this is only for local rendering.
	*/
	virtual void setViewMatrix(const physx::PxMat44 &view) = 0;

	/**
	\brief Set's the projection matrix as a full 4x4 matrix.  Required for screen-space aligned debug rendering.

	\param projection This current projection matrix, note this is not transmitted to the server, it is only used locally.
	*/
	virtual void setProjectionMatrix(const physx::PxMat44 &projection) = 0;

	/**
	\brief Returns the current view*projection matrix

	\return A convenience method to return the current view*projection matrix (local only)
	*/
	virtual const physx::PxMat44* getViewProjectionMatrixTyped(void) const = 0;

	/**
	\brief Returns the current view matrix we are using

	\return  A convenience method which returns the currently set view matrix (local only)
	*/
	virtual const physx::PxMat44 *getViewMatrixTyped(void) const = 0;

	/**
	\brief Gets the current projection matrix.

	\return A convenience method to return the current projection matrix (local only)
	*/
	virtual const physx::PxMat44 *getProjectionMatrixTyped(void) const = 0;

	/**
	\brief A convenience helper method to convert euler angles (in degrees) into a standard XYZW quaternion. 

	\param angles The X,Y,Z angles in degrees
	\param q The output quaternion
	*/
	virtual void  eulerToQuat(const physx::PxVec3 &angles,physx::PxQuat &q) = 0; // angles are in degrees.

	/**
	\brief A convenience method to convert a position and direction vector into a 4x4 transform

	\param p0 The starting position
	\param p1 The ending position
	\param xform The translation and rotation transform

	*/
	virtual void rotationArc(const physx::PxVec3 &p0,const physx::PxVec3 &p1,physx::PxMat44 &xform) = 0;

	/**
	\brief Begin's a draw group relative to this 4x4 matrix.  Returns the draw group id. A draw group is like a macro set of drawing commands.

	\param pose The base pose of this draw group.
	*/
	virtual int32_t beginDrawGroup(const physx::PxMat44 &pose) = 0;

	/**
	\brief Revises the transform for a previously defined draw group.

	\param blockId The id number of the block we are referencing
	\param pose The pose of that block id
	*/
	virtual void  setDrawGroupPose(int32_t blockId,const physx::PxMat44 &pose) = 0;

	/**
	\brief Sets the global pose for the current debug-rendering context. This is preserved on the state stack.

	\param pose Sets the current global pose for the RenderDebug context, all draw commands will be transformed by this root pose. Default is identity.  
	*/
	virtual void  setPose(const physx::PxMat44 &pose) = 0;

	/**
	\brief Sets the global pose for the current debug-rendering context. This is preserved on the state stack.

	\param pose Sets the pose from a position and quaternion rotation
	*/
	virtual void setPose(const physx::PxTransform &pose) = 0;

	/**
	\brief Sets the global pose position only, does not change the rotation.

	\param position Sets the translation component
	*/
	virtual void setPosition(const physx::PxVec3 &position) = 0;

	/**
	\brief Sets the global pose orientation only, does not change the position

	\param rot Sets the orientation of the global pose
	*/
	virtual void setOrientation(const physx::PxQuat &rot) = 0;

	/**
	\brief Gets the global pose for the current debug rendering context

	\return Returns the current global pose for the RenderDebug
	*/
	virtual const physx::PxMat44 * getPoseTyped(void) const = 0;

	/**
	\brief Debug visualize a view*projection matrix frustum.

	\param viewMatrix The view matrix of the frustm
	\param projMatrix The projection matrix of the frustm
	*/
	virtual void debugFrustum(const physx::PxMat44 &viewMatrix,const physx::PxMat44 &projMatrix) = 0;

	// Due to the issue of 'name hiding' when we have two virtual interfaces which have pure virtual methods of the same name
	// we must explicitly declare that we are intentionally providing access to both the typed as well as the base class
	// non-typed versions here.
	// @see: http://www.programmerinterview.com/index.php/c-cplusplus/c-name-hiding/
	//
	using RenderDebug::debugPolygon;
	using RenderDebug::debugLine;
	using RenderDebug::debugGradientLine;
	using RenderDebug::debugRay;
	using RenderDebug::debugCylinder;
	using RenderDebug::debugThickRay;
	using RenderDebug::debugPlane;
	using RenderDebug::debugTri;
	using RenderDebug::debugTriNormals;
	using RenderDebug::debugGradientTri;
	using RenderDebug::debugGradientTriNormals;
	using RenderDebug::debugBound;
	using RenderDebug::debugSphere;
	using RenderDebug::debugCircle;
	using RenderDebug::debugPoint;
	using RenderDebug::debugQuad;
	using RenderDebug::debugAxes;
	using RenderDebug::debugArc;
	using RenderDebug::debugThickArc;
	using RenderDebug::debugText;
	using RenderDebug::setViewMatrix;
	using RenderDebug::setProjectionMatrix;
	using RenderDebug::eulerToQuat;
	using RenderDebug::rotationArc;
	using RenderDebug::beginDrawGroup;
	using RenderDebug::setDrawGroupPose;
	using RenderDebug::setPose;
	using RenderDebug::setPosition;
	using RenderDebug::setOrientation;
	using RenderDebug::debugFrustum;
protected:

	virtual ~RenderDebugTyped(void) { }
};

} // end of RENDER_DEBUG namespace


#endif // RENDER_DEBUG_TYPED_H
