#include "System.hpp"
#include "System.IOUtils.hpp"
#include "System.SysUtils.hpp"
#include "TStream.hpp"
#include "TStreamReader.hpp"
#include <boost/filesystem.hpp>


namespace System {

bool operator == (const TGUID &a, const TGUID &b)
{
	return a.D1 == b.D1
		&& a.D2 == b.D2
		&& a.D3 == b.D3		
		&& a.D4[0] == b.D4[0]
		&& a.D4[1] == b.D4[1]
		&& a.D4[2] == b.D4[2]
		&& a.D4[3] == b.D4[3]
		&& a.D4[4] == b.D4[4]
		&& a.D4[5] == b.D4[5]
		&& a.D4[6] == b.D4[6]
		&& a.D4[7] == b.D4[7]
	;
}

bool SystemTimeToFileTime(const SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime)
{
	return false;
}

bool LocalFileTimeToFileTime(const FILETIME *lpLocalFileTime, LPFILETIME lpFileTime)
{
	return false;
}

bool FileTimeToLocalFileTime(const FILETIME *lpLocalFileTime, LPFILETIME lpFileTime)
{
	return false;
}

void GetSystemTime(LPSYSTEMTIME lpSystemTime)
{

}

namespace Classes {

int TStreamReader::Read()
{
	Byte data;
	auto data_read = stream->Read(&data, 1);
	if (data_read != 1) {
		return -1;
	}
	return data;
}

unsigned GetTickCount()
{
	// TODO: GetTickCount()
	return 0;
}

} // Classes

namespace Ioutils {


void CreateDir(const String &dirname)
{
	boost::filesystem::create_directory(boost::filesystem::path(dirname));
}

bool FileExists(const String &filename)
{
	return boost::filesystem::exists(boost::filesystem::path(filename));
}

bool DirectoryExists(const String &filename)
{
	return boost::filesystem::exists(boost::filesystem::path(filename))
		&& boost::filesystem::is_directory(boost::filesystem::path(filename));
}

void DeleteFile(const String &filename)
{
	boost::filesystem::remove(boost::filesystem::path(filename));
}

void RemoveDir(const String &dirname)
{
	boost::filesystem::remove_all(dirname);
}

namespace TDirectory {
	
void CreateDirectory(const String &dirname)		
{
	CreateDir(dirname);
}

} // TDirectory


namespace TPath {

String GetFullPath(const String &filename)
{
	auto absolute_path = boost::filesystem::absolute(boost::filesystem::path(filename));
	return String(absolute_path.string());
}

String GetTempPath()
{
	return boost::filesystem::temp_directory_path().string();
}

void GetTempPath(int bufSize, char *buf)
{
	strncpy(buf, GetTempPath().c_str(), bufSize);
}

} // TPath

} // Ioutils

namespace SysUtils {

static TEncoding *TEncoding::Unicode = new TEncoding();
static TEncoding *TEncoding::UTF8 = new TEncoding();


static int TEncoding::GetBufferEncoding(const System::DynamicArray<Byte> &Buffer, TEncoding* &AEncoding)
{
	// TODO: 
	return 0;
}

static DynamicArray<Byte> TEncoding::Convert(TEncoding * const Source, TEncoding * const Destination, const DynamicArray<Byte> &Bytes, int StartIndex, int Count)
{
	return Bytes;
}

DynamicArray<Byte> TEncoding::GetPreamble()
{
	return DynamicArray<Byte>();
}

int StrToInt(const String &s)
{
	return std::atoi(s.c_str());
}

int FindFirst(const String &Path, int Attr, TSearchRec &rec)
{
	// TODO: FindFirst
	return 1;
}

int  FindNext(TSearchRec &rec)
{
	// TODO: 
	return 1;
}

void FindClose(TSearchRec &rec)
{
	// TODO: 
}

void CreateGUID(TGUID &guid)
{
	// TODO: CreateGUID
}

String ExtractFileExt(const String &filename)
{
	boost::filesystem::path _p(filename);
	return _p.extension().string();
}

String StringReplace(const String &S, const String &OldPattern, const String &NewPattern, TReplaceFlags Flags)
{
	// TODO: StringReplace
	return S.Replace(OldPattern, NewPattern);
}

} // SysUtils

} // System