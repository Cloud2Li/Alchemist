#include "SL.h"
#include "CCFileUtils.h"

#include "xxtea\xxtea.h"

#define MX (z>>5^y<<2) + (y>>3^z<<4)^(sum^y) + (k[p&3^e]^z);

long btea(long* v, long n, long* k) {
	unsigned long z = v[n - 1], y = v[0], sum = 0, e, DELTA = 0x9e3779b9;
	long p, q;
	if (n > 1) {          /* Coding Part */
		q = 6 + 52 / n;
		while (q-- > 0) {
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p<n - 1; p++) y = v[p + 1], z = v[p] += MX;
			y = v[0];
			z = v[n - 1] += MX;
		}
		return 0;
	}
	else if (n < -1) {  /* Decoding Part */
		n = -n;
		q = 6 + 52 / n;
		sum = q*DELTA;
		while (sum != 0) {
			e = (sum >> 2) & 3;
			for (p = n - 1; p>0; p--) z = v[p - 1], y = v[p] -= MX;
			z = v[n - 1];
			y = v[0] -= MX;
			sum -= DELTA;
		}
		return 0;
	}
	return 1;
}

const int SIZE_KEY = 16;

using namespace std;

NS_CC_BEGIN

SL* SL::s_sharedSL = nullptr;

void SL::destroyInstance()
{
	CC_SAFE_DELETE(s_sharedSL);
}

void SL::setDelegate(SL *delegate)
{
	if (s_sharedSL)
		delete s_sharedSL;

	s_sharedSL = delegate;


}

SL::SL():keyStr("lhmgmendlessmaze")
{
	std::string str = "dfniiwoajdinfohuoiioajidofjiaoiwjdoifnuoajiodfnfuoajdiojiwaonfuoeanfodijfoaunewfoxandijdnfuodajfijoajfijdohfoahfoejaoifjo";
	xxtea_long ret_len = 0;
	xxtea_long t = 0;
	auto c = xxtea_encrypt((unsigned char*)str.c_str(), str.length(), (unsigned char*)"lhmgmendlessmaze", SIZE_KEY, &t);
	auto k = xxtea_decrypt(c, t, (unsigned char*)"lhmgmendlessmaze", SIZE_KEY, &ret_len);
	cocos2d::log("%s", c);
	cocos2d::log("%s", k);
}

SL::~SL()
{
}



bool SL::init()
{
	return true;
}

#define MX (z>>5^y<<2) + (y>>3^z<<4)^(sum^y) + (k[p&3^e]^z);

long btea(long* v, long n, long* k) {
	unsigned long z = v[n - 1], y = v[0], sum = 0, e, DELTA = 0x9e3779b9;
	long p, q;
	if (n > 1) {
		q = 6 + 52 / n;
		while (q-- > 0) {
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p<n - 1; p++) y = v[p + 1], z = v[p] += MX;
			y = v[0];
			z = v[n - 1] += MX;
		}
		return 0;
	}
	else if (n < -1) {
		n = -n;
		q = 6 + 52 / n;
		sum = q*DELTA;
		while (sum != 0) {
			e = (sum >> 2) & 3;
			for (p = n - 1; p>0; p--) z = v[p - 1], y = v[p] -= MX;
			z = v[n - 1];
			y = v[0] -= MX;
			sum -= DELTA;
		}
		return 0;
	}
	return 1;
}

static Data getData(const std::string& filename, bool forString)
{
	if (filename.empty())
	{
		return Data::Null;
	}

	Data ret;
	unsigned char* buffer = nullptr;
	size_t size = 0;
	size_t readsize;
	const char* mode = nullptr;

	if (forString)
		mode = "rt";
	else
		mode = "rb";

	do
	{
		// Read the file from hardware
		auto writable = FileUtils::getInstance()->getWritablePath();
		writable = writable.append("/");
		std::string fullPath = writable.append(filename);
		FILE *fp = fopen(fullPath.c_str(), mode);
		CC_BREAK_IF(!fp);
		fseek(fp, 0, SEEK_END);
		size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		if (forString)
		{
			buffer = (unsigned char*)malloc(sizeof(unsigned char)* (size + 1));
			buffer[size] = '\0';
		}
		else
		{
			buffer = (unsigned char*)malloc(sizeof(unsigned char)* size);
		}

		readsize = fread(buffer, sizeof(unsigned char), size, fp);
		fclose(fp);

		if (forString && readsize < size)
		{
			buffer[readsize] = '\0';
		}
	} while (0);

	if (nullptr == buffer || 0 == readsize)
	{
		std::string msg = "Get data from file(";
		msg.append(filename).append(") failed!");
		CCLOG("%s", msg.c_str());
	}
	else
	{
		xxtea_long ret_len = 0;
		auto plain = xxtea_decrypt(buffer, readsize, (unsigned char*)"lhmgmendlessmaze", SIZE_KEY, &ret_len);
		cocos2d::log((char*)buffer);
		ret.fastSet(buffer, readsize);
	}

	return ret;
}

std::string SL::LoadFromFile(const std::string& filename)
{
	Data data = getData(filename, false);
	if (data.isNull())
		return "";

	xxtea_long ret_len = 0;
	auto plain = xxtea_decrypt(data.getBytes(), data.getSize(), (unsigned char*)keyStr.c_str(), SIZE_KEY, &ret_len);
	if (plain)
	{
		std::string ret((const char*)plain);

		return ret;
	}
	return "";
}


bool SL::saveToFile(const std::string& str, const std::string& filename)
{
	xxtea_long ret_len = 0;
	auto cryptstr = xxtea_encrypt((unsigned char*)str.c_str(), str.length(), (unsigned char*)keyStr.c_str(), SIZE_KEY, &ret_len);

	auto writable = FileUtils::getInstance()->getWritablePath();
	writable = writable.append("/");
	std::string fullPath = writable.append(filename);

	FILE *fp = fopen(fullPath.c_str(), "wb");
	if (fp)
	{
		fwrite(cryptstr, sizeof(char), ret_len, fp);
		//fputs((char*)cryptstr, fp);
	}

	fclose(fp);
	fp=NULL;

	//CC_SAFE_DELETE(plain);
	//CC_SAFE_DELETE(crypt);
	return true;

}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
static int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
	auto ret = remove(fpath);
	if (ret)
	{
		log("Fail to remove: %s ", fpath);
	}

	return ret;
}
#endif

bool SL::removeFile(const std::string &path)
{
	// Remove downloaded file

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	std::wstring wpath(path.begin(), path.end());
	if (DeleteFile(wpath.c_str()))
	{
		return true;
	}
	return false;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::string command = "cmd /c del /q ";
	std::string win32path = path;
	int len = win32path.length();
	for (int i = 0; i < len; ++i)
	{
		if (win32path[i] == '/')
		{
			win32path[i] = '\\';
		}
	}
	command += win32path;

	if (WinExec(command.c_str(), SW_HIDE) > 31)
		return true;
	else
		return false;
#else
	if (remove(path.c_str())) {
		return false;
	}
	else {
		return true;
	}
#endif
}

SL* SL::getInstance()
{
	if (s_sharedSL)
	{
		return s_sharedSL;
	}
	else
	{

	}
	if (s_sharedSL == nullptr)
	{
		s_sharedSL = new SL();
		if (!s_sharedSL->init())
		{
			delete s_sharedSL;
			s_sharedSL = nullptr;
			CCLOG("ERROR: Could not init SL");
		}
	}
	return s_sharedSL;
}


NS_CC_END
