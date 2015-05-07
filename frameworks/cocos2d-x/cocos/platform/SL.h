
#ifndef __CC_SL_H__
#define __CC_SL_H__


#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

#include "platform/CCPlatformMacros.h"
#include "base/ccTypes.h"
#include "base/CCValue.h"
#include "base/CCData.h"

NS_CC_BEGIN

/**
* @addtogroup platform
* @{
*/

//! @brief  Helper class to handle file operations
class CC_DLL SL
{
public:
	/**
	*  Gets the instance of SL.
	*/
	static SL* getInstance();

	/**
	*  Destroys the instance of SL.
	*/
	static void destroyInstance();

	/**
	* You can inherit from platform dependent implementation of SL, such as SLAndroid,
	* and use this function to set delegate, then SL will invoke delegate's implementation.
	* Fox example, your resources are encrypted, so you need to decrypt it after reading data from
	* resources, then you can implement all getXXX functions, and engine will invoke your own getXX
	* functions when reading data of resources.
	*
	* If you don't want to system default implementation after setting delegate, you can just pass nullptr
	* to this function.
	*
	* @warm It will delete previous delegate
	*/
	static void setDelegate(SL *delegate);

	/**
	*  The destructor of SL.
	* @js NA
	* @lua NA
	*/
	virtual ~SL();

	/**
	*  Gets string from a file.
	*/
	virtual std::string LoadFromFile(const std::string& filename);

	/**
	*  Write a ValueMap to a plist file.
	*  @note This method is used internally.
	*/
	virtual bool saveToFile(const std::string& str, const std::string& filename);

	/**
	*  Remove a file
	*
	*  @param filepath The full path of the file, it must be an absolute path.
	*  @return true if the file have been removed successfully, otherwise it will return false.
	*/
	virtual bool removeFile(const std::string &filepath);
protected:
	/**
	*  The default constructor.
	*/
	SL();

	/**
	*  Initializes the instance of SL. It will set _searchPathArray and _searchResolutionsOrderArray to default values.
	*
	*  @note When you are porting Cocos2d-x to a new platform, you may need to take care of this method.
	*        You could assign a default value to _defaultResRootPath in the subclass of SL(e.g. SLAndroid). Then invoke the SL::init().
	*  @return true if successed, otherwise it returns false.
	*
	*/
	virtual bool init();

	static SL* s_sharedSL;

	const std::string keyStr;

};

// end of platform group
/// @}

NS_CC_END

#endif    // __CC_SL_H__
