//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.1           
//                                                           
//!  \file UGMaterial.h
//!  \brief 三维GPU程序参数类。
//!  \details 完成GPU程序参数的封装
//!  \author sunyl
//!  \attention 
//!   Copyright (c) 1996-2012 SuperMap Software Co., Ltd. <br> 
//!   All Rights Reserved.
//!  \version 6.1
//////////////////////////////////////////////////////////////////////////
#ifndef __GPUPROGRAMPARAMS_H_
#define __GPUPROGRAMPARAMS_H_

// Precompiler options
#include "Base3D/UGPrerequisites3D.h"
#include "Base3D/UGSharedPtr.h"
#include "Base3D/UGVector4d.h"
#include "Base3D/UGVector3d.h"
#include "Base3D/UGMatrix4d.h"
#include "Base3D/UGColorValue3D.h"
#include "Stream/UGStream.h"
#include "Toolkit/UGMarkup.h"
#include <limits.h>

namespace UGC {

	/** The variability of a GPU parameter, as derived from auto-params targetting it.
	These values must be powers of two since they are used in masks.
	*/
	enum GpuParamVariability
	{
		/// No variation except by manual setting - the default
		GPV_GLOBAL = 1, 
		/// Varies per object (based on an auto param usually), but not per light setup
		GPV_PER_OBJECT = 2, 
		/// Varies with light setup
		GPV_LIGHTS = 4, 
		/// Varies with pass iteration number
		GPV_PASS_ITERATION_NUMBER = 8,


		/// Full mask (16-bit)
		GPV_ALL = 0xFFFF

	};

	/** Information about predefined program constants. 
	@note Only available for high-level programs but is referenced generically
	by GpuProgramParameters.
	*/
	struct BASE3D_API GpuConstantDefinition
	{
		/// Data type
		GpuConstantType constType;
		/// Physical start index in buffer (either float or int buffer)
		UGuint index;
		UGString name;
		/// Length of array
		UGuint arraySize;
		//数组的元数,比如输入一个数组，1,3,4,6,7,7。如果是二元的则是(1,3),(4,6),(7,7),三元则是（1,3,4),(6,7,7)
		UGuint multiple;
		//////////////////////////////////////////////////////////////////////////
		//保存的参数值
		UGColorValue3D colourValue;
		UGdouble* arrDouble;
		UGfloat* arrFloat;
		UGint* arrInt;
		UGMatrix4d* arrMatrix4d;
		UGVector3d vec3d;
		UGVector4d vec4d;
		//////////////////////////////////////////////////////////////////////////

		GpuConstantDefinition();

		~GpuConstantDefinition();

		GpuConstantDefinition(const GpuConstantDefinition& other);

		GpuConstantDefinition& operator=(const GpuConstantDefinition& oth);
		

		//读取参数设置
		UGbool FromXML(UGString& strXML);

		//保存参数设置
		UGbool ToXML(UGString& strXML);
	};
	typedef std::map<UGString, GpuConstantDefinition> GpuConstantDefinitionMap;
	//typedef ConstMapIterator<GpuConstantDefinitionMap> GpuConstantDefinitionIterator;

	/// Struct collecting together the information for named constants.
	struct BASE3D_API GpuNamedConstants
	{
		/// Total size of the float buffer required
		UGuint floatBufferSize;
		/// Total size of the int buffer required
		UGuint intBufferSize;
		/// Map of parameter names to GpuConstantDefinition
		GpuConstantDefinitionMap map;

		GpuNamedConstants() : floatBufferSize(0), intBufferSize(0) {}
	};
	typedef UGSharedPtr<GpuNamedConstants> GpuNamedConstantsPtr;

	/** Structure recording the use of a physical buffer by a logical parameter
	index. Only used for low-level programs.
	*/
	struct BASE3D_API GpuLogicalIndexUse
	{
		/// Physical buffer index
		UGuint physicalIndex;
		/// Current physical size allocation
		UGuint currentSize;
		/// How the contents of this slot vary
		mutable UGushort variability;

		GpuLogicalIndexUse() 
			: physicalIndex(99999), currentSize(0), variability(GPV_GLOBAL) {}
		GpuLogicalIndexUse(UGuint bufIdx, UGuint curSz, UGushort v) 
			: physicalIndex(bufIdx), currentSize(curSz), variability(v) {}
	};
	typedef std::map<UGuint, GpuLogicalIndexUse> GpuLogicalIndexUseMap;
	/// Container struct to allow params to safely & update shared list of logical buffer assignments
	struct BASE3D_API GpuLogicalBufferStruct
	{
		/// Map from logical index to physical buffer location
		GpuLogicalIndexUseMap map;
		/// Shortcut to know the buffer size needs
		UGuint bufferSize;
		GpuLogicalBufferStruct() : bufferSize(0) {}
	};
	typedef UGSharedPtr<GpuLogicalBufferStruct> GpuLogicalBufferStructPtr;

	/** Definition of container that holds the current float constants.
	@note Not necessarily in direct index order to constant indexes, logical
	to physical index map is derived from GpuProgram
	*/
	typedef std::vector<UGfloat> FloatConstantList;
	/** Definition of container that holds the current float constants.
	@note Not necessarily in direct index order to constant indexes, logical
	to physical index map is derived from GpuProgram
	*/
	typedef std::vector<UGint> IntConstantList;

	/** A group of manually updated parameters that are shared between many parameter sets.
	@remarks
		Sometimes you want to set some common parameters across many otherwise 
		different parameter sets, and keep them all in sync together. This class
		allows you to define a set of parameters that you can share across many
		parameter sets and have the parameters that match automatically be pulled
		from the shared set, rather than you having to set them on all the parameter
		sets individually.
	@par
		Parameters in a shared set are matched up with instances in a GpuProgramParameters
		structure by matching names. It is up to you to define the named parameters
		that a shared set contains, and ensuring the definition matches.
	@note
		Shared parameter sets can be named, and looked up using the GpuProgramManager.
	*/
	class BASE3D_API UGGpuSharedParameters
	{
	protected:
		GpuNamedConstants mNamedConstants;
		FloatConstantList mFloatConstants;
		IntConstantList mIntConstants;
		UGString mName;

		/// Not used when copying data, but might be useful to RS using shared buffers
		UGuint mFrameLastUpdated;

		/// Version number of the definitions in this buffer
		UGulong mVersion; 

	public:
		// Optional data the rendersystem might want to store
		void* mRenderSystemData;
	public:
		UGGpuSharedParameters(const UGString& name);
		virtual ~UGGpuSharedParameters();

		/// Get the name of this shared parameter set
		const UGString& getName() { return mName; }

		/** Add a new constant definition to this shared set of parameters.
		@remarks
			Unlike GpuProgramParameters, where the parameter list is defined by the
			program being compiled, this shared parameter set is defined by the
			user. Only parameters which have been predefined here may be later
			updated.
		*/
		void addConstantDefinition(const UGString& name, GpuConstantType constType, UGuint arraySize = 1);

		/** Remove a constant definition from this shared set of parameters.
		*/
		void removeConstantDefinition(const UGString& name);

		/** Remove a constant definition from this shared set of parameters.
		*/
		void removeAllConstantDefinitions();

		/** Get the version number of this shared parameter set, can be used to identify when 
			changes have occurred. 
		*/
		UGulong getVersion() const { return mVersion; }

		/// Get the frame in which this shared parameter set was last updated
		UGuint getFrameLastUpdated() const { return mFrameLastUpdated; }

		/** Gets an iterator over the named GpuConstantDefinition instances as defined
			by the user. 
		*/
		//GpuConstantDefinitionIterator getConstantDefinitionIterator(void) const;

		/** Get a specific GpuConstantDefinition for a named parameter.
		*/
		const GpuConstantDefinition& getConstantDefinition(const UGString& name) const;

		/** Get the full list of GpuConstantDefinition instances.
		*/
		const GpuNamedConstants& getConstantDefinitions() const;
	
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, UGdouble val);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, UGint val);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGVector4d& vec);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGVector3d& vec);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGMatrix4d& m);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGMatrix4d* m, UGuint numEntries);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGfloat *val, UGuint count);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGdouble *val, UGuint count);
			/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGColorValue3D& colour);
		/** @copydoc GpuProgramParameters::setNamedConstant */
		void setNamedConstant(const UGString& name, const UGint *val, UGuint count);

		/// Get a pointer to the 'nth' item in the float buffer
		UGfloat* getFloatPointer(UGuint pos) { return &mFloatConstants[pos]; }
		/// Get a pointer to the 'nth' item in the float buffer
		const UGfloat* getFloatPointer(UGuint pos) const { return &mFloatConstants[pos]; }
		/// Get a pointer to the 'nth' item in the int buffer
		UGint* getIntPointer(UGuint pos) { return &mIntConstants[pos]; }
		/// Get a pointer to the 'nth' item in the int buffer
		const UGint* getIntPointer(UGuint pos) const { return &mIntConstants[pos];}; 
	};

	/// Shared pointer used to hold references to GpuProgramParameters instances
	typedef UGSharedPtr<UGGpuSharedParameters> GpuSharedParametersPtr;

	class UGGpuProgramParameters;

	/** This class records the usage of a set of shared parameters in a concrete
		set of GpuProgramParameters.
	*/
	class BASE3D_API GpuSharedParametersUsage
	{
	protected:
		GpuSharedParametersPtr mSharedParams;
		// Not a shared pointer since this is also parent
		UGGpuProgramParameters* mParams;
		// list of physical mappings that we are going to bring in
		struct CopyDataEntry
		{
			const GpuConstantDefinition* srcDefinition;
			const GpuConstantDefinition* dstDefinition;
		};
		typedef std::vector<CopyDataEntry> CopyDataList;

		CopyDataList mCopyDataList;

		/// Version of shared params we based the copydata on
		UGulong mCopyDataVersion;

		void initCopyData();

	public:
		// Optional data the rendersystem might want to store
		mutable void* mRenderSystemData;
	public:
		/// Construct usage
		GpuSharedParametersUsage(GpuSharedParametersPtr sharedParams, 
			UGGpuProgramParameters* params);

		/** Update the target parameters by copying the data from the shared
			parameters.
		@note This method  may not actually be called if the RenderSystem
			supports using shared parameters directly in their own shared buffer; in
			which case the values should not be copied out of the shared area
			into the individual parameter set, but bound separately.
		*/
		void _copySharedParamsToTargetParams();

		/// Get the name of the shared parameter set
		const UGString& getName() const { return mSharedParams->getName(); }

		GpuSharedParametersPtr getSharedParams() const { return mSharedParams; }
		UGGpuProgramParameters* getTargetParams() const { return mParams; }

	};

	/** Collects together the program parameters used for a GpuProgram.
	@remarks
	Gpu program state includes constant parameters used by the program, and
	bindings to render system state which is propagated into the constants 
	by the engine automatically if requested.
	@par
	GpuProgramParameters objects should be created through the GpuProgram and
	may be shared between multiple Pass instances. For this reason they
	are managed using a shared pointer, which will ensure they are automatically
	deleted when no Pass is using them anymore. 
	@par
	High-level programs use named parameters (uniforms), low-level programs 
	use indexed constants. This class supports both, but you can tell whether 
	named constants are supported by calling hasNamedParameters(). There are
	references in the documentation below to 'logical' and 'physical' indexes;
	logical indexes are the indexes used by low-level programs and represent 
	indexes into an array of float4's, some of which may be settable, some of
	which may be predefined constants in the program. We only store those
	constants which have actually been set, therefore our buffer could have 
	gaps if we used the logical indexes in our own buffers. So instead we map
	these logical indexes to physical indexes in our buffer. When using 
	high-level programs, logical indexes don't necessarily exist, although they
	might if the high-level program has a direct, exposed mapping from parameter
	names to logical indexes. In addition, high-level languages may or may not pack
	arrays of elements that are smaller than float4 (e.g. float2/vec2) contiguously.
	This kind of information is held in the ConstantDefinition structure which 
	is only populated for high-level programs. You don't have to worry about
	any of this unless you intend to read parameters back from this structure
	rather than just setting them.
	*/
	class BASE3D_API UGGpuProgramParameters
	{
	public:
		/** Defines the types of automatically updated values that may be bound to GpuProgram
		parameters, or used to modify parameters on a per-object basis.
		*/
		enum AutoConstantType
		{
			/// The current world matrix
			ACT_WORLD_MATRIX,
			/// The current world matrix, inverted
			ACT_INVERSE_WORLD_MATRIX,
			/** Provides transpose of world matrix.
			Equivalent to RenderMonkey's "WorldTranspose".
			*/
			ACT_TRANSPOSE_WORLD_MATRIX,
			/// The current world matrix, inverted & transposed
			ACT_INVERSE_TRANSPOSE_WORLD_MATRIX,


			/// The current array of world matrices, as a 3x4 matrix, used for blending
			ACT_WORLD_MATRIX_ARRAY_3x4,
			/// The current array of world matrices, used for blending
			ACT_WORLD_MATRIX_ARRAY,

			/// The current view matrix
			ACT_VIEW_MATRIX,
			/// The current view matrix, inverted
			ACT_INVERSE_VIEW_MATRIX,
			/** Provides transpose of view matrix.
			Equivalent to RenderMonkey's "ViewTranspose".
			*/
			ACT_TRANSPOSE_VIEW_MATRIX,
			/** Provides inverse transpose of view matrix.
			Equivalent to RenderMonkey's "ViewInverseTranspose".
			*/
			ACT_INVERSE_TRANSPOSE_VIEW_MATRIX,


			/// The current projection matrix
			ACT_PROJECTION_MATRIX,
			/** Provides inverse of projection matrix.
			Equivalent to RenderMonkey's "ProjectionInverse".
			*/
			ACT_INVERSE_PROJECTION_MATRIX,
			/** Provides transpose of projection matrix.
			Equivalent to RenderMonkey's "ProjectionTranspose".
			*/
			ACT_TRANSPOSE_PROJECTION_MATRIX,
			/** Provides inverse transpose of projection matrix.
			Equivalent to RenderMonkey's "ProjectionInverseTranspose".
			*/
			ACT_INVERSE_TRANSPOSE_PROJECTION_MATRIX,


			/// The current view & projection matrices concatenated
			ACT_VIEWPROJ_MATRIX,
			/** Provides inverse of concatenated view and projection matrices.
			Equivalent to RenderMonkey's "ViewProjectionInverse".
			*/
			ACT_INVERSE_VIEWPROJ_MATRIX,
			/** Provides transpose of concatenated view and projection matrices.
			Equivalent to RenderMonkey's "ViewProjectionTranspose".
			*/
			ACT_TRANSPOSE_VIEWPROJ_MATRIX,
			/** Provides inverse transpose of concatenated view and projection matrices.
			Equivalent to RenderMonkey's "ViewProjectionInverseTranspose".
			*/
			ACT_INVERSE_TRANSPOSE_VIEWPROJ_MATRIX,


			/// The current world & view matrices concatenated
			ACT_WORLDVIEW_MATRIX,
			/// The current world & view matrices concatenated, then inverted
			ACT_INVERSE_WORLDVIEW_MATRIX,
			/** Provides transpose of concatenated world and view matrices.
			Equivalent to RenderMonkey's "WorldViewTranspose".
			*/
			ACT_TRANSPOSE_WORLDVIEW_MATRIX,
			/// The current world & view matrices concatenated, then inverted & transposed
			ACT_INVERSE_TRANSPOSE_WORLDVIEW_MATRIX,
			/// view matrices.


			/// The current world, view & projection matrices concatenated
			ACT_WORLDVIEWPROJ_MATRIX,
			/** Provides inverse of concatenated world, view and projection matrices.
			Equivalent to RenderMonkey's "WorldViewProjectionInverse".
			*/
			ACT_INVERSE_WORLDVIEWPROJ_MATRIX,
			/** Provides transpose of concatenated world, view and projection matrices.
			Equivalent to RenderMonkey's "WorldViewProjectionTranspose".
			*/
			ACT_TRANSPOSE_WORLDVIEWPROJ_MATRIX,
			/** Provides inverse transpose of concatenated world, view and projection
			matrices. Equivalent to RenderMonkey's "WorldViewProjectionInverseTranspose".
			*/
			ACT_INVERSE_TRANSPOSE_WORLDVIEWPROJ_MATRIX,


			/// render target related values
			/** -1 if requires texture flipping, +1 otherwise. It's useful when you bypassed
			projection matrix transform, still able use this value to adjust transformed y position.
			*/
			ACT_RENDER_TARGET_FLIPPING,

			/** -1 if the winding has been inverted (e.g. for reflections), +1 otherwise.
			*/
			ACT_VERTEX_WINDING,

			/// Fog colour
			ACT_FOG_COLOUR,
			/// Fog params: density, linear start, linear end, 1/(end-start)
			ACT_FOG_PARAMS,


			/// Surface ambient colour, as set in Pass::setAmbient
			ACT_SURFACE_AMBIENT_COLOUR,
			/// Surface diffuse colour, as set in Pass::setDiffuse
			ACT_SURFACE_DIFFUSE_COLOUR,
			/// Surface specular colour, as set in Pass::setSpecular
			ACT_SURFACE_SPECULAR_COLOUR,
			/// Surface emissive colour, as set in Pass::setSelfIllumination
			ACT_SURFACE_EMISSIVE_COLOUR,
			/// Surface shininess, as set in Pass::setShininess
			ACT_SURFACE_SHININESS,


			/// The number of active light sources (better than gl_MaxLights)
			ACT_LIGHT_COUNT,


			/// The ambient light colour set in the scene
			ACT_AMBIENT_LIGHT_COLOUR, 

			/// Light diffuse colour (index determined by setAutoConstant call)
			ACT_LIGHT_DIFFUSE_COLOUR,
			/// Light specular colour (index determined by setAutoConstant call)
			ACT_LIGHT_SPECULAR_COLOUR,
			/// Light attenuation parameters, Vector4(range, constant, linear, quadric)
			ACT_LIGHT_ATTENUATION,
			/** Spotlight parameters, Vector4(innerFactor, outerFactor, falloff, isSpot)
			innerFactor and outerFactor are cos(angle/2)
			The isSpot parameter is 0.0f for non-spotlights, 1.0f for spotlights.
			Also for non-spotlights the inner and outer factors are 1 and nearly 1 respectively
			*/ 
			ACT_SPOTLIGHT_PARAMS,
			/// A light position in world space (index determined by setAutoConstant call)
			ACT_LIGHT_POSITION,
			/// A light position in object space (index determined by setAutoConstant call)
			ACT_LIGHT_POSITION_OBJECT_SPACE,
			/// A light position in view space (index determined by setAutoConstant call)
			ACT_LIGHT_POSITION_VIEW_SPACE,
			/// A light direction in world space (index determined by setAutoConstant call)
			ACT_LIGHT_DIRECTION,
			/// A light direction in object space (index determined by setAutoConstant call)
			ACT_LIGHT_DIRECTION_OBJECT_SPACE,
			/// A light direction in view space (index determined by setAutoConstant call)
			ACT_LIGHT_DIRECTION_VIEW_SPACE,
			/** The distance of the light from the center of the object
			a useful approximation as an alternative to per-vertex distance
			calculations.
			*/
			ACT_LIGHT_DISTANCE_OBJECT_SPACE,
			/** Light power level, a single scalar as set in Light::setPowerScale  (index determined by setAutoConstant call) */
			ACT_LIGHT_POWER_SCALE,
			/// Light diffuse colour pre-scaled by Light::setPowerScale (index determined by setAutoConstant call)
			ACT_LIGHT_DIFFUSE_COLOUR_POWER_SCALED,
			/// Light specular colour pre-scaled by Light::setPowerScale (index determined by setAutoConstant call)
			ACT_LIGHT_SPECULAR_COLOUR_POWER_SCALED,
			/// Array of light diffuse colours (count set by extra param)
			ACT_LIGHT_DIFFUSE_COLOUR_ARRAY,
			/// Array of light specular colours (count set by extra param)
			ACT_LIGHT_SPECULAR_COLOUR_ARRAY,
			/// Array of light diffuse colours scaled by light power (count set by extra param)
			ACT_LIGHT_DIFFUSE_COLOUR_POWER_SCALED_ARRAY,
			/// Array of light specular colours scaled by light power (count set by extra param)
			ACT_LIGHT_SPECULAR_COLOUR_POWER_SCALED_ARRAY,
			/// Array of light attenuation parameters, Vector4(range, constant, linear, quadric) (count set by extra param)
			ACT_LIGHT_ATTENUATION_ARRAY,
			/// Array of light positions in world space (count set by extra param)
			ACT_LIGHT_POSITION_ARRAY,
			/// Array of light positions in object space (count set by extra param)
			ACT_LIGHT_POSITION_OBJECT_SPACE_ARRAY,
			/// Array of light positions in view space (count set by extra param)
			ACT_LIGHT_POSITION_VIEW_SPACE_ARRAY,
			/// Array of light directions in world space (count set by extra param)
			ACT_LIGHT_DIRECTION_ARRAY,
			/// Array of light directions in object space (count set by extra param)
			ACT_LIGHT_DIRECTION_OBJECT_SPACE_ARRAY,
			/// Array of light directions in view space (count set by extra param)
			ACT_LIGHT_DIRECTION_VIEW_SPACE_ARRAY,
			/** Array of distances of the lights from the center of the object
			a useful approximation as an alternative to per-vertex distance
			calculations. (count set by extra param)
			*/
			ACT_LIGHT_DISTANCE_OBJECT_SPACE_ARRAY,
			/** Array of light power levels, a single scalar as set in Light::setPowerScale 
			(count set by extra param)
			*/
			ACT_LIGHT_POWER_SCALE_ARRAY,
			/** Spotlight parameters array of Vector4(innerFactor, outerFactor, falloff, isSpot)
			innerFactor and outerFactor are cos(angle/2)
			The isSpot parameter is 0.0f for non-spotlights, 1.0f for spotlights.
			Also for non-spotlights the inner and outer factors are 1 and nearly 1 respectively.
			(count set by extra param)
			*/ 
			ACT_SPOTLIGHT_PARAMS_ARRAY,

			/** The derived ambient light colour, with 'r', 'g', 'b' components filled with
			product of surface ambient colour and ambient light colour, respectively,
			and 'a' component filled with surface ambient alpha component.
			*/
			ACT_DERIVED_AMBIENT_LIGHT_COLOUR,
			/** The derived scene colour, with 'r', 'g' and 'b' components filled with sum
			of derived ambient light colour and surface emissive colour, respectively,
			and 'a' component filled with surface diffuse alpha component.
			*/
			ACT_DERIVED_SCENE_COLOUR,

			/** The derived light diffuse colour (index determined by setAutoConstant call),
			with 'r', 'g' and 'b' components filled with product of surface diffuse colour,
			light power scale and light diffuse colour, respectively, and 'a' component filled with surface
			diffuse alpha component.
			*/
			ACT_DERIVED_LIGHT_DIFFUSE_COLOUR,
			/** The derived light specular colour (index determined by setAutoConstant call),
			with 'r', 'g' and 'b' components filled with product of surface specular colour
			and light specular colour, respectively, and 'a' component filled with surface
			specular alpha component.
			*/
			ACT_DERIVED_LIGHT_SPECULAR_COLOUR,

			/// Array of derived light diffuse colours (count set by extra param)
			ACT_DERIVED_LIGHT_DIFFUSE_COLOUR_ARRAY,
			/// Array of derived light specular colours (count set by extra param)
			ACT_DERIVED_LIGHT_SPECULAR_COLOUR_ARRAY,
			/** The absolute light number of a local light index. Each pass may have
			a number of lights passed to it, and each of these lights will have
			an index in the overall light list, which will differ from the local
			light index due to factors like setStartLight and setIteratePerLight.
			This binding provides the global light index for a local index.
			*/
			ACT_LIGHT_NUMBER,
			/// Returns (int) 1 if the  given light casts shadows, 0 otherwise (index set in extra param)
			ACT_LIGHT_CASTS_SHADOWS,


			/** The distance a shadow volume should be extruded when using
			finite extrusion programs.
			*/
			ACT_SHADOW_EXTRUSION_DISTANCE,
			/// The current camera's position in world space
			ACT_CAMERA_POSITION,
			/// The current camera's position in object space 
			ACT_CAMERA_POSITION_OBJECT_SPACE,
			/// The view/projection matrix of the assigned texture projection frustum
			ACT_TEXTURE_VIEWPROJ_MATRIX,
			/// Array of view/projection matrices of the first n texture projection frustums
			ACT_TEXTURE_VIEWPROJ_MATRIX_ARRAY,
			/** The view/projection matrix of the assigned texture projection frustum, 
			combined with the current world matrix
			*/
			ACT_TEXTURE_WORLDVIEWPROJ_MATRIX,
			/// Array of world/view/projection matrices of the first n texture projection frustums
			ACT_TEXTURE_WORLDVIEWPROJ_MATRIX_ARRAY,
			/// The view/projection matrix of a given spotlight
			ACT_SPOTLIGHT_VIEWPROJ_MATRIX,
			/** The view/projection matrix of a given spotlight projection frustum, 
			combined with the current world matrix
			*/
			ACT_SPOTLIGHT_WORLDVIEWPROJ_MATRIX,
			/// A custom parameter which will come from the renderable, using 'data' as the identifier
			ACT_CUSTOM,
			/** provides current elapsed time
			*/
			ACT_TIME,
			/** Single float value, which repeats itself based on given as
			parameter "cycle time". Equivalent to RenderMonkey's "Time0_X".
			*/
			ACT_TIME_0_X,
			/// Cosine of "Time0_X". Equivalent to RenderMonkey's "CosTime0_X".
			ACT_COSTIME_0_X,
			/// Sine of "Time0_X". Equivalent to RenderMonkey's "SinTime0_X".
			ACT_SINTIME_0_X,
			/// Tangent of "Time0_X". Equivalent to RenderMonkey's "TanTime0_X".
			ACT_TANTIME_0_X,
			/** Vector of "Time0_X", "SinTime0_X", "CosTime0_X", 
			"TanTime0_X". Equivalent to RenderMonkey's "Time0_X_Packed".
			*/
			ACT_TIME_0_X_PACKED,
			/** Single float value, which represents scaled time value [0..1],
			which repeats itself based on given as parameter "cycle time".
			Equivalent to RenderMonkey's "Time0_1".
			*/
			ACT_TIME_0_1,
			/// Cosine of "Time0_1". Equivalent to RenderMonkey's "CosTime0_1".
			ACT_COSTIME_0_1,
			/// Sine of "Time0_1". Equivalent to RenderMonkey's "SinTime0_1".
			ACT_SINTIME_0_1,
			/// Tangent of "Time0_1". Equivalent to RenderMonkey's "TanTime0_1".
			ACT_TANTIME_0_1,
			/** Vector of "Time0_1", "SinTime0_1", "CosTime0_1",
			"TanTime0_1". Equivalent to RenderMonkey's "Time0_1_Packed".
			*/
			ACT_TIME_0_1_PACKED,
			/**	Single float value, which represents scaled time value [0..2*Pi],
			which repeats itself based on given as parameter "cycle time".
			Equivalent to RenderMonkey's "Time0_2PI".
			*/
			ACT_TIME_0_2PI,
			/// Cosine of "Time0_2PI". Equivalent to RenderMonkey's "CosTime0_2PI".
			ACT_COSTIME_0_2PI,
			/// Sine of "Time0_2PI". Equivalent to RenderMonkey's "SinTime0_2PI".
			ACT_SINTIME_0_2PI,
			/// Tangent of "Time0_2PI". Equivalent to RenderMonkey's "TanTime0_2PI".
			ACT_TANTIME_0_2PI,
			/** Vector of "Time0_2PI", "SinTime0_2PI", "CosTime0_2PI",
			"TanTime0_2PI". Equivalent to RenderMonkey's "Time0_2PI_Packed".
			*/
			ACT_TIME_0_2PI_PACKED,
			/// provides the scaled frame time, returned as a floating point value.
			ACT_FRAME_TIME,
			/// provides the calculated frames per second, returned as a floating point value.
			ACT_FPS,
			/// viewport-related values
			/** Current viewport width (in pixels) as floating point value.
			Equivalent to RenderMonkey's "ViewportWidth".
			*/
			ACT_VIEWPORT_WIDTH,
			/** Current viewport height (in pixels) as floating point value.
			Equivalent to RenderMonkey's "ViewportHeight".
			*/
			ACT_VIEWPORT_HEIGHT,
			/** This variable represents 1.0/ViewportWidth. 
			Equivalent to RenderMonkey's "ViewportWidthInverse".
			*/
			ACT_INVERSE_VIEWPORT_WIDTH,
			/** This variable represents 1.0/ViewportHeight.
			Equivalent to RenderMonkey's "ViewportHeightInverse".
			*/
			ACT_INVERSE_VIEWPORT_HEIGHT,
			/** Packed of "ViewportWidth", "ViewportHeight", "ViewportWidthInverse",
			"ViewportHeightInverse".
			*/
			ACT_VIEWPORT_SIZE,

			/// view parameters
			/** This variable provides the view direction vector (world space).
			Equivalent to RenderMonkey's "ViewDirection".
			*/
			ACT_VIEW_DIRECTION,
			/** This variable provides the view side vector (world space).
			Equivalent to RenderMonkey's "ViewSideVector".
			*/
			ACT_VIEW_SIDE_VECTOR,
			/** This variable provides the view up vector (world space).
			Equivalent to RenderMonkey's "ViewUpVector".
			*/
			ACT_VIEW_UP_VECTOR,
			/** This variable provides the field of view as a floating point value.
			Equivalent to RenderMonkey's "FOV".
			*/
			ACT_FOV,
			/**	This variable provides the near clip distance as a floating point value.
			Equivalent to RenderMonkey's "NearClipPlane".
			*/
			ACT_NEAR_CLIP_DISTANCE,
			/**	This variable provides the far clip distance as a floating point value.
			Equivalent to RenderMonkey's "FarClipPlane".
			*/
			ACT_FAR_CLIP_DISTANCE,

			/** provides the pass index number within the technique
			of the active materil.
			*/
			ACT_PASS_NUMBER,

			/** provides the current iteration number of the pass. The iteration
			number is the number of times the current render operation has
			been drawn for the active pass.
			*/
			ACT_PASS_ITERATION_NUMBER,


			/** Provides a parametric animation value [0..1], only available
			where the renderable specifically implements it.
			*/
			ACT_ANIMATION_PARAMETRIC,

			/** Provides the texel offsets required by this rendersystem to map
			texels to pixels. Packed as 
			float4(absoluteHorizontalOffset, absoluteVerticalOffset, 
			horizontalOffset / viewportWidth, verticalOffset / viewportHeight)
			*/
			ACT_TEXEL_OFFSETS,

			/** Provides information about the depth range of the scene as viewed
			from the current camera. 
			Passed as float4(minDepth, maxDepth, depthRange, 1 / depthRange)
			*/
			ACT_SCENE_DEPTH_RANGE,

			/** Provides information about the depth range of the scene as viewed
			from a given shadow camera. Requires an index parameter which maps
			to a light index relative to the current light list.
			Passed as float4(minDepth, maxDepth, depthRange, 1 / depthRange)
			*/
			ACT_SHADOW_SCENE_DEPTH_RANGE,

			/** Provides the fixed shadow colour as configured via SceneManager::setShadowColour;
			useful for integrated modulative shadows.
			*/
			ACT_SHADOW_COLOUR,
			/** Provides texture size of the texture unit (index determined by setAutoConstant
			call). Packed as float4(width, height, depth, 1)
			*/
			ACT_TEXTURE_SIZE,
			/** Provides inverse texture size of the texture unit (index determined by setAutoConstant
			call). Packed as float4(1 / width, 1 / height, 1 / depth, 1)
			*/
			ACT_INVERSE_TEXTURE_SIZE,
			/** Provides packed texture size of the texture unit (index determined by setAutoConstant
			call). Packed as float4(width, height, 1 / width, 1 / height)
			*/
			ACT_PACKED_TEXTURE_SIZE,

			/** Provides the current transform matrix of the texture unit (index determined by setAutoConstant
			call), as seen by the fixed-function pipeline. 
			*/
			ACT_TEXTURE_MATRIX, 

			/** Provides the position of the LOD camera in world space, allowing you 
			to perform separate LOD calculations in shaders independent of the rendering
			camera. If there is no separate LOD camera then this is the real camera
			position. See Camera::setLodCamera.
			*/
			ACT_LOD_CAMERA_POSITION, 
			/** Provides the position of the LOD camera in object space, allowing you 
			to perform separate LOD calculations in shaders independent of the rendering
			camera. If there is no separate LOD camera then this is the real camera
			position. See Camera::setLodCamera.
			*/
			ACT_LOD_CAMERA_POSITION_OBJECT_SPACE, 
			/** Binds custom per-light constants to the shaders. */
			ACT_LIGHT_CUSTOM
		};

		/** Defines the type of the extra data item used by the auto constant.

		*/
		enum ACDataType {
			/// no data is required
			ACDT_NONE,
			/// the auto constant requires data of type int
			ACDT_INT,
			/// the auto constant requires data of type real
			ACDT_REAL
		};

		/** Defines the base element type of the auto constant
		*/
		enum ElementType {
			ET_INT,
			ET_REAL
		};

		/** Structure defining an auto constant that's available for use in 
		a parameters object.
		*/
		struct AutoConstantDefinition
		{
			AutoConstantType acType;
			UGString name;
			UGuint elementCount;
			/// The type of the constant in the program
			ElementType elementType;
			/// The type of any extra data
			ACDataType dataType;

			AutoConstantDefinition(AutoConstantType _acType, const UGString& _name, 
				UGuint _elementCount, ElementType _elementType, 
				ACDataType _dataType)
				:acType(_acType), name(_name), elementCount(_elementCount), 
				elementType(_elementType), dataType(_dataType)
			{

			}
		};

		/** Structure recording the use of an automatic parameter. */
		class AutoConstantEntry
		{
		public:
			/// The type of parameter
			AutoConstantType paramType;
			// 自动变量名称
			UGString strName;
			/// The target (physical) constant index
			UGuint physicalIndex;
			/** The number of elements per individual entry in this constant
			Used in case people used packed elements smaller than 4 (e.g. GLSL)
			and bind an auto which is 4-element packed to it */
			UGuint elementCount;
			/// Additional information to go with the parameter
			union{
				UGuint data;
				UGdouble fData;
			};
			/// The variability of this parameter (see GpuParamVariability)
			UGushort variability;

			/// Additional information 是否是实数类型
			UGbool m_bIsReal;

			AutoConstantEntry();

			AutoConstantEntry(AutoConstantType theType);

			AutoConstantEntry(AutoConstantType theType, UGuint theIndex, UGuint theData, 
				UGushort theVariability = 0, UGuint theElemCount = 4); 

			AutoConstantEntry(AutoConstantType theType, UGuint theIndex, UGdouble theData, 
				UGushort theVariability = 0, UGuint theElemCount = 4);

			AutoConstantEntry(const AutoConstantEntry& other);
		
			//读取参数设置
			UGbool FromXML(UGString& strXML);

			//保存参数设置
			UGbool ToXML(UGString& strXML);
		};
		// Auto parameter storage
		typedef std::vector<AutoConstantEntry*> AutoConstantList;

		typedef std::vector<GpuSharedParametersUsage> GpuSharedParamUsageList;

		typedef std::vector<UGString> SharedParamsNameList;

		//typedef std::vector<GpuConstantDefinition> GpuConstantList;
		typedef std::map<UGString, GpuConstantDefinition*>  GpuConstantList;
		

	public:
		static AutoConstantDefinition AutoConstantDictionary[];
		/// Packed list of floating-point constants (physical indexing)
		FloatConstantList mFloatConstants;
		/// Packed list of integer constants (physical indexing)
		IntConstantList mIntConstants;
		/** Logical index to physical index map - for low-level programs
		or high-level programs which pass params this way. */
		GpuLogicalBufferStructPtr mFloatLogicalToPhysical;
		/** Logical index to physical index map - for low-level programs
		or high-level programs which pass params this way. */
		GpuLogicalBufferStructPtr mIntLogicalToPhysical;
		/// Mapping from parameter names to def - high-level programs are expected to populate this
		GpuNamedConstantsPtr mNamedConstants;
		/// List of automatically updated parameters
		AutoConstantList mAutoConstants;
		/// The combined variability masks of all parameters
		UGushort mCombinedVariability;
		/// Do we need to transpose matrices?
		UGbool mTransposeMatrices;
		/// flag to indicate if names not found will be ignored
		UGbool mIgnoreMissingParams;
		/// physical index for active pass iteration parameter real constant entry;
		UGuint mActivePassIterationIndex;
		// 保存公有参数名称的列表
		SharedParamsNameList m_SharedParamsNames;
		//保存Gpu程序的输入参数常量的数组
		GpuConstantList m_GpuConstantList;

		/// Return the variability for an auto constant
		UGushort deriveVariability(AutoConstantType act);

		void copySharedParamSetUsage(const GpuSharedParamUsageList& srcList);

		GpuSharedParamUsageList mSharedParamSets;

	public:
		// Optional data the rendersystem might want to store
		mutable void* mRenderSystemData;

	public:
		UGGpuProgramParameters();

		~UGGpuProgramParameters();

		/// Copy constructor
		UGGpuProgramParameters(const UGGpuProgramParameters& oth);
		/// Operator = overload
		UGGpuProgramParameters& operator=(const UGGpuProgramParameters& oth);

		/** Internal method for providing a link to a name->definition map for parameters. */
		void _setNamedConstants(const GpuNamedConstantsPtr& constantmap);

		/** Internal method for providing a link to a logical index->physical index map for parameters. */
		void _setLogicalIndexes(const GpuLogicalBufferStructPtr& floatIndexMap, 
			const GpuLogicalBufferStructPtr&  intIndexMap);


		/// Does this parameter set include named parameters?
		UGbool hasNamedParameters() const { return !mNamedConstants.IsNull(); }
		/** Does this parameter set include logically indexed parameters?
		@note Not mutually exclusive with hasNamedParameters since some high-level
		programs still use logical indexes to set the parameters on the 
		rendersystem.
		*/
		UGbool hasLogicalIndexedParameters() const { return !mFloatLogicalToPhysical.IsNull(); }

		/** Sets a 4-element floating-point parameter to the program.
		@param index The logical constant index at which to place the parameter 
		(each constant is a 4D float)
		@param vec The value to set
		*/
		void setConstant(UGuint index, UGVector4d& vec);
		/** Sets a single floating-point parameter to the program.
		@note This is actually equivalent to calling 
		setConstant(index Vector4(val, 0, 0, 0)) since all constants are 4D.
		@param index The logical constant index at which to place the parameter (each constant is
		a 4D float)
		@param val The value to set
		*/
		void setConstant(UGuint index, UGdouble val);
		/** Sets a 4-element floating-point parameter to the program via Vector3.
		@param index The logical constant index at which to place the parameter (each constant is
		a 4D float).
		Note that since you're passing a Vector3, the last element of the 4-element
		value will be set to 1 (a homogeneous vector)
		@param vec The value to set
		*/
		void setConstant(UGuint index, UGVector3d& vec);
		/** Sets a Matrix4 parameter to the program.
		@param index The logical constant index at which to place the parameter (each constant is
		a 4D float).
		NB since a Matrix4 is 16 floats UGlong, this parameter will take up 4 indexes.
		@param m The value to set
		*/
		void setConstant(UGuint index, UGMatrix4d& m);
		/** Sets a list of Matrix4 parameters to the program.
		@param index The logical constant index at which to start placing the parameter (each constant is
		a 4D float).
		NB since a Matrix4 is 16 floats UGlong, so each entry will take up 4 indexes.
		@param m Pointer to an array of matrices to set
		@param numEntries Number of Matrix4 entries
		*/
		void setConstant(UGuint index, UGMatrix4d* m, UGuint numEntries);
		/** Sets a multiple value constant floating-point parameter to the program.
		@param index The logical constant index at which to start placing parameters (each constant is
		a 4D float)
		@param val Pointer to the values to write, must contain 4*count floats
		@param count The number of groups of 4 floats to write
		*/
		void setConstant(UGuint index, UGfloat *val, UGuint count);
		/** Sets a multiple value constant floating-point parameter to the program.
		@param index The logical constant index at which to start placing parameters (each constant is
		a 4D float)
		@param val Pointer to the values to write, must contain 4*count floats
		@param count The number of groups of 4 floats to write
		*/
		void setConstant(UGuint index, UGdouble *val, UGuint count);
		/** Sets a ColourValue parameter to the program.
		@param index The logical constant index at which to place the parameter (each constant is
		a 4D float)
		@param colour The value to set
		*/
		void setConstant(UGuint index, UGColorValue3D& colour);

		/** Sets a multiple value constant integer parameter to the program.
		@remarks
		Different types of GPU programs support different types of constant parameters.
		For example, it's relatively common to find that vertex programs only support
		floating point constants, and that fragment programs only support integer (fixed point)
		parameters. This can vary depending on the program version supported by the
		graphics card being used. You should consult the documentation for the type of
		low level program you are using, or alternatively use the methods
		provided on RenderSystemCapabilities to determine the options.
		@param index The logical constant index at which to place the parameter (each constant is
		a 4D integer)
		@param val Pointer to the values to write, must contain 4*count ints
		@param count The number of groups of 4 ints to write
		*/
		void setConstant(UGuint index, UGint *val, UGuint count);
		/** Get a specific GpuConstantDefinition for a named parameter.
		@note
		Only available if this parameters object has named parameters.
		*/
		const GpuConstantDefinition& getConstantDefinition(const UGString& name) const;

		/** Get the full list of GpuConstantDefinition instances.
		@note
		Only available if this parameters object has named parameters.
		*/
		const GpuNamedConstants& getConstantDefinitions() const;

		/** Get the current list of mappings from low-level logical param indexes
		to physical buffer locations in the float buffer.
		@note
		Only applicable to low-level programs.
		*/
		const GpuLogicalBufferStructPtr& getFloatLogicalBufferStruct() const { return mFloatLogicalToPhysical; }

		/** Retrieves the logical index relating to a physical index in the float
		buffer, for programs which support that (low-level programs and 
		high-level programs which use logical parameter indexes).
		@returns std::numeric_limits<UGuint>::max() if not found
		*/
		UGuint getFloatLogicalIndexForPhysicalIndex(UGuint physicalIndex);
		/** Retrieves the logical index relating to a physical index in the int
		buffer, for programs which support that (low-level programs and 
		high-level programs which use logical parameter indexes).
		@returns std::numeric_limits<UGuint>::max() if not found
		*/
		UGuint getIntLogicalIndexForPhysicalIndex(UGuint physicalIndex);

		/** Get the current list of mappings from low-level logical param indexes
		to physical buffer locations in the integer buffer.
		@note
		Only applicable to low-level programs.
		*/
		const GpuLogicalBufferStructPtr& getIntLogicalBufferStruct() const { return mIntLogicalToPhysical; }
		/// Get a reference to the list of float constants
		const FloatConstantList& getFloatConstantList() const { return mFloatConstants; }
		/// Get a pointer to the 'nth' item in the float buffer
		UGfloat* getFloatPointer(UGuint pos) { return &mFloatConstants[pos]; }
		/// Get a pointer to the 'nth' item in the float buffer
		const UGfloat* getFloatPointer(UGuint pos) const { return &mFloatConstants[pos]; }
		/// Get a reference to the list of int constants
		const IntConstantList& getIntConstantList() const { return mIntConstants; }
		/// Get a pointer to the 'nth' item in the int buffer
		UGint* getIntPointer(UGuint pos) { return &mIntConstants[pos]; }
		/// Get a pointer to the 'nth' item in the int buffer
		const UGint* getIntPointer(UGuint pos) const { return &mIntConstants[pos]; }
		/// Get a reference to the list of auto constant bindings
		const AutoConstantList& getAutoConstantList() const { return mAutoConstants; }

		/** Sets up a constant which will automatically be updated by the system.
		@remarks
		Vertex and fragment programs often need parameters which are to do with the
		current render state, or particular values which may very well change over time,
		and often between objects which are being rendered. This feature allows you 
		to set up a certain number of predefined parameter mappings that are kept up to 
		date for you.
		@param index The location in the constant list to place this updated constant every time
		it is changed. Note that because of the nature of the types, we know how big the 
		parameter details will be so you don't need to set that like you do for manual constants.
		@param acType The type of automatic constant to set
		@param extraInfo If the constant type needs more information (like a light index) put it here.
		*/
		void setAutoConstant(UGuint index, AutoConstantType acType, UGuint extraInfo = 0);
		void setAutoConstantReal(UGuint index, AutoConstantType acType, UGdouble rData);

		/** Sets up a constant which will automatically be updated by the system.
		@remarks
		Vertex and fragment programs often need parameters which are to do with the
		current render state, or particular values which may very well change over time,
		and often between objects which are being rendered. This feature allows you 
		to set up a certain number of predefined parameter mappings that are kept up to 
		date for you.
		@param index The location in the constant list to place this updated constant every time
		it is changed. Note that because of the nature of the types, we know how big the 
		parameter details will be so you don't need to set that like you do for manual constants.
		@param acType The type of automatic constant to set
		@param extraInfo1 The first extra parameter required by the auto constant type
		@param extraInfo2 The first extra parameter required by the auto constant type
		*/
		void setAutoConstant(UGuint index, AutoConstantType acType, UGushort extraInfo1, UGushort extraInfo2);
		/** Unbind an auto constant so that the constant is manually controlled again. */
		void clearAutoConstant(UGuint index);

		/** Sets a named parameter up to track a derivation of the current time.
		@param index The index of the parameter
		@param factor The amount by which to scale the time value
		*/  
		void setConstantFromTime(UGuint index, UGdouble factor);

		/** Clears all the existing automatic constants. */
		void clearAutoConstants(void);
		/// Gets the number of int constants that have been set
		UGuint getAutoConstantCount(void) const { return (UGint)mAutoConstants.size(); }
		/** Gets a specific Auto Constant entry if index is in valid range
		otherwise returns a NULL
		@param index which entry is to be retrieved
		*/
		AutoConstantEntry* getAutoConstantEntry(const UGuint index);
		/** Returns true if this instance has any automatic constants. */
		UGbool hasAutoConstants(void) const { return !(mAutoConstants.empty()); }
		/** Finds an auto constant that's affecting a given physical position in 
		the floating-point buffer
		*/
		const AutoConstantEntry* _findRawAutoConstantEntryFloat(UGuint physicalIndex);
		/** Finds an auto constant that's affecting a given physical position in 
		the integer buffer
		*/
		const AutoConstantEntry* _findRawAutoConstantEntryInt(UGuint physicalIndex);

		/** Tells the program whether to ignore missing parameters or not.
		*/
		void setIgnoreMissingParams(UGbool state) { mIgnoreMissingParams = state; }

		/** Sets a single value constant floating-point parameter to the program.
		@remarks
		Different types of GPU programs support different types of constant parameters.
		For example, it's relatively common to find that vertex programs only support
		floating point constants, and that fragment programs only support integer (fixed point)
		parameters. This can vary depending on the program version supported by the
		graphics card being used. You should consult the documentation for the type of
		low level program you are using, or alternatively use the methods
		provided on RenderSystemCapabilities to determine the options.
		@par
		Another possible limitation is that some systems only allow constants to be set
		on certain boundaries, e.g. in sets of 4 values for example. Again, see
		RenderSystemCapabilities for full details.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param val The value to set
		*/
		void setNamedConstant(const UGString& name, UGdouble val);
		/** Sets a single value constant integer parameter to the program.
		@remarks
		Different types of GPU programs support different types of constant parameters.
		For example, it's relatively common to find that vertex programs only support
		floating point constants, and that fragment programs only support integer (fixed point)
		parameters. This can vary depending on the program version supported by the
		graphics card being used. You should consult the documentation for the type of
		low level program you are using, or alternatively use the methods
		provided on RenderSystemCapabilities to determine the options.
		@par
		Another possible limitation is that some systems only allow constants to be set
		on certain boundaries, e.g. in sets of 4 values for example. Again, see
		RenderSystemCapabilities for full details.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param val The value to set
		*/
		void setNamedConstant(const UGString& name, UGint val);
		/** Sets a Vector4 parameter to the program.
		@param name The name of the parameter
		@param vec The value to set
		*/
		void setNamedConstant(const UGString& name, const UGVector4d& vec);
		/** Sets a Vector3 parameter to the program.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param index The index at which to place the parameter
		NB this index refers to the number of floats, so a Vector3 is 3. Note that many 
		rendersystems & programs assume that every floating point parameter is passed in
		as a vector of 4 items, so you are strongly advised to check with 
		RenderSystemCapabilities before using this version - if in doubt use Vector4
		or ColourValue instead (both are 4D).
		@param vec The value to set
		*/
		void setNamedConstant(const UGString& name, const UGVector3d& vec);
		/** Sets a Matrix4 parameter to the program.
		@param name The name of the parameter
		@param m The value to set
		*/
		void setNamedConstant(const UGString& name, UGMatrix4d m);
		/** Sets a list of Matrix4 parameters to the program.
		@param name The name of the parameter; this must be the first index of an array,
		for examples 'matrices[0]'
		NB since a Matrix4 is 16 floats UGlong, so each entry will take up 4 indexes.
		@param m Pointer to an array of matrices to set
		@param numEntries Number of Matrix4 entries
		*/
		void setNamedConstant(const UGString& name, UGMatrix4d* m, UGuint numEntries);
		/** Sets a multiple value constant floating-point parameter to the program.
		@par
		Some systems only allow constants to be set on certain boundaries, 
		e.g. in sets of 4 values for example. The 'multiple' parameter allows
		you to control that although you should only change it if you know
		your chosen language supports that (at the time of writing, only
		GLSL allows constants which are not a multiple of 4).
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param val Pointer to the values to write
		@param count The number of 'multiples' of floats to write
		@param multiple The number of raw entries in each element to write, 
		the default is 4 so count = 1 would write 4 floats.
		*/
		void setNamedConstant(const UGString& name, UGfloat *val, UGuint count, 
			UGuint multiple = 4);
		/** Sets a multiple value constant floating-point parameter to the program.
		@par
		Some systems only allow constants to be set on certain boundaries, 
		e.g. in sets of 4 values for example. The 'multiple' parameter allows
		you to control that although you should only change it if you know
		your chosen language supports that (at the time of writing, only
		GLSL allows constants which are not a multiple of 4).
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param val Pointer to the values to write
		@param count The number of 'multiples' of floats to write
		@param multiple The number of raw entries in each element to write, 
		the default is 4 so count = 1 would write 4 floats.
		*/
		void setNamedConstant(const UGString& name, UGdouble *val, UGuint count, 
			UGuint multiple = 4);
		/** Sets a ColourValue parameter to the program.
		@param name The name of the parameter
		@param colour The value to set
		*/
		void setNamedConstant(const UGString& name, const UGColorValue3D& colour);

		/** Sets a multiple value constant floating-point parameter to the program.
		@par
		Some systems only allow constants to be set on certain boundaries, 
		e.g. in sets of 4 values for example. The 'multiple' parameter allows
		you to control that although you should only change it if you know
		your chosen language supports that (at the time of writing, only
		GLSL allows constants which are not a multiple of 4).
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param val Pointer to the values to write
		@param count The number of 'multiples' of floats to write
		@param multiple The number of raw entries in each element to write, 
		the default is 4 so count = 1 would write 4 floats.
		*/
		void setNamedConstant(const UGString& name, UGint *val, UGuint count, 
			UGuint multiple = 4);

		/** Sets up a constant which will automatically be updated by the system.
		@remarks
		Vertex and fragment programs often need parameters which are to do with the
		current render state, or particular values which may very well change over time,
		and often between objects which are being rendered. This feature allows you 
		to set up a certain number of predefined parameter mappings that are kept up to 
		date for you.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param acType The type of automatic constant to set
		@param extraInfo If the constant type needs more information (like a light index) put it here.
		*/
		void setNamedAutoConstant(const UGString& name, AutoConstantType acType, UGuint extraInfo = 0);
		void setNamedAutoConstantReal(const UGString& name, AutoConstantType acType, UGdouble rData);

		/** Sets up a constant which will automatically be updated by the system.
		@remarks
		Vertex and fragment programs often need parameters which are to do with the
		current render state, or particular values which may very well change over time,
		and often between objects which are being rendered. This feature allows you 
		to set up a certain number of predefined parameter mappings that are kept up to 
		date for you.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param acType The type of automatic constant to set
		@param extraInfo1 The first extra info required by this auto constant type
		@param extraInfo2 The first extra info required by this auto constant type
		*/
		void setNamedAutoConstant(const UGString& name, AutoConstantType acType, UGushort extraInfo1, UGushort extraInfo2);

		/** Sets a named parameter up to track a derivation of the current time.
		@note
		This named option will only work if you are using a parameters object created
		from a high-level program (HighLevelGpuProgram).
		@param name The name of the parameter
		@param factor The amount by which to scale the time value
		*/  
		void setNamedConstantFromTime(const UGString& name, UGdouble factor);

		/** Unbind an auto constant so that the constant is manually controlled again. */
		void clearNamedAutoConstant(const UGString& name);

		/** Find a constant definition for a named parameter.
		@remarks
		This method returns null if the named parameter did not exist, unlike
		getConstantDefinition which is more strict; unless you set the 
		last parameter to true.
		@param name The name to look up
		@param throwExceptionIfMissing If set to true, failure to find an entry
		will throw an exception.
		*/
		const GpuConstantDefinition* _findNamedConstantDefinition(
			const UGString& name, UGbool throwExceptionIfMissing = FALSE) const;
		/** Sets whether or not we need to transpose the matrices passed in from the rest of OGRE.
		@remarks
		D3D uses transposed matrices compared to GL and OGRE; this is not important when you
		use programs which are written to process row-major matrices, such as those generated
		by Cg, but if you use a program written to D3D's matrix layout you will need to enable
		this flag.
		*/
		void setTransposeMatrices(UGbool val) { mTransposeMatrices = val; } 
		/// Gets whether or not matrices are to be transposed when set
		UGbool getTransposeMatrices(void) const { return mTransposeMatrices; } 

		/** Copies the values of all constants (including auto constants) from another
		GpuProgramParameters object.
		@note This copes the internal storage of the paarameters object and therefore
		can only be used for parameters objects created from the same GpuProgram.
		To merge parameters that match from different programs, use copyMatchingNamedConstantsFrom.
		*/
		void copyConstantsFrom(const UGGpuProgramParameters& source);

		/** Copies the values of all matching named constants (including auto constants) from 
		another GpuProgramParameters object. 
		@remarks
		This method iterates over the named constants in another parameters object
		and copies across the values where they match. This method is safe to
		use when the 2 parameters objects came from different programs, but only
		works for named parameters.
		*/
		void copyMatchingNamedConstantsFrom(const UGGpuProgramParameters& source);

		/** gets the auto constant definition associated with name if found else returns NULL
		@param name The name of the auto constant
		*/
		static const AutoConstantDefinition* getAutoConstantDefinition(const UGString& name);
		/** gets the auto constant definition using an index into the auto constant definition array.
		If the index is out of bounds then NULL is returned;
		@param idx The auto constant index
		*/
		static const AutoConstantDefinition* getAutoConstantDefinition(const UGuint idx);
		/** Returns the number of auto constant definitions
		*/
		static UGuint getNumAutoConstantDefinitions(void);


		/** Does this parameters object have a pass iteration number constant? */
		UGbool hasPassIterationNumber() const 
		{ return mActivePassIterationIndex != UINT_MAX; }
		/** Get the physical buffer index of the pass iteration number constant */
		UGuint getPassIterationNumberIndex() const 
		{ return mActivePassIterationIndex; }

		/** Returns whether this parameter set is using the named shared parameter set. */
		UGbool isUsingSharedParameters(const UGString& sharedParamsName) const;

		/** Stop using the named shared parameter set. */
		void removeSharedParameters(const UGString& sharedParamsName);

		/** Stop using all shared parameter sets. */
		void removeAllSharedParameters();

		/** Get the list of shared parameter sets. */
		const GpuSharedParamUsageList& getSharedParameters() const;

		/** Update the parameters by copying the data from the shared
		parameters.
		@note This method  may not actually be called if the RenderSystem
		supports using shared parameters directly in their own shared buffer; in
		which case the values should not be copied out of the shared area
		into the individual parameter set, but bound separately.
		*/
		void _copySharedParams();

		//! \从XML字符串读取参数设置
		//! \param strXML XML字符串  [in]
		//! \return 返回是否成功
		UGbool FromXML(UGString& strXML);

		//! \保存参数设置到XML字符串
		//! \param strXML XML字符串  [in]
		//! \return 返回是否成功
		UGbool ToXML(UGString& strXML);

	private:
		//! \释放持有的内存
		void Clear();
	
	};

	/// Shared pointer used to hold references to GpuProgramParameters instances
	class BASE3D_API UGGpuProgramParametersSharedPtr : public UGSharedPtr<UGGpuProgramParameters>
	{
	public:	
		//! \brief 构造函数
		UGGpuProgramParametersSharedPtr() : UGSharedPtr<UGGpuProgramParameters>(){}

		//! \brief 拷贝构造函数
		explicit UGGpuProgramParametersSharedPtr(UGGpuProgramParameters* rep):UGSharedPtr<UGGpuProgramParameters>(rep){}
	};

	/** @} */
	/** @} */
}
#endif

