#pragma once

#include "GeneralHelper.h"

#include <memory>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <hash_map>
#include <math.h>
using namespace std;
using namespace stdext;

typedef	wstring		CStdStringW;
typedef string		CStdStringA;

#ifdef _UNICODE
	typedef	CStdStringW		CStdString;
#else
	typedef CStdStringA		CStdString;
#endif

typedef list<short>					short_list;
typedef list<int>					int_list;
typedef list<long>					long_list;
typedef list<__int64>				int64_list;
typedef list<unsigned short>		ushort_list;
typedef list<unsigned int>			uint_list;
typedef list<unsigned long>			ulong_list;
typedef list<unsigned __int64>		uint64_list;
typedef list<float>					float_list;
typedef list<double>				double_list;
typedef vector<short>				short_vector;
typedef vector<int>					int_vector;
typedef vector<long>				long_vector;
typedef vector<__int64>				int64_vector;
typedef vector<unsigned short>		ushort_vector;
typedef vector<unsigned int>		uint_vector;
typedef vector<unsigned long>		ulong_vector;
typedef vector<unsigned __int64>	uint64_vector;
typedef vector<float>				float_vector;
typedef vector<double>				double_vector;
typedef set<short>					short_set;
typedef set<int>					int_set;
typedef set<long>					long_set;
typedef set<__int64>				int64_set;
typedef set<unsigned short>			ushort_set;
typedef set<unsigned int>			uint_set;
typedef set<unsigned long>			ulong_set;
typedef set<unsigned __int64>		uint64_set;
typedef set<float>					float_set;
typedef set<double>					double_set;

/*****************************************************************************/
/******************************** ������������ *******************************/

/**********************************
����: �����ͨ���� , ������ vector<Object> / list<Object>
����: 
	v		: vector / list / set

����ֵ: 		
**********************************/
template<class Set> void ClearSet(Set& v)
{
	v.clear();
}

template<class Set> struct Set_Cleaner
{
	static void Clear(Set& v) {ClearSet(v);}
};

/**********************************
����: ���ָ�뼯�� (���ǰ���ͷ�ָ��), ������ vector<Object*> / list<Object*>
����: 
		v		: vector / list / set

����ֵ: 		
**********************************/
template<class PtrSet> void ClearPtrSet(PtrSet& v)
{
	for(PtrSet::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
		delete (*it);

	v.clear();
}

template<class PtrSet> struct PtrSet_Cleaner
{
	static void Clear(PtrSet& v) {ClearPtrSet(v);}
};

/**********************************
����: ���ָ�뼯�� (ָ��ͬʱ��ָ������), ������ vector<Object*[]> / list<Object*[]>
����: 
		v		: vector / list / set

����ֵ: 		
**********************************/
template<class PtrArraySet> void ClearPtrArraySet(PtrArraySet& v)
{
	for(PtrArraySet::iterator	it = v.begin(); 
								it != v.end(); 
								++it)
		delete[] (*it);

	v.clear();
}

template<class PtrArraySet> struct PtrArraySet_Cleaner
{
	static void Clear(PtrArraySet& v) {ClearPtrArraySet(v);}
};

/**********************************
����: �����ͨӰ�� , ������ map<key, value>
����: 
	v		: map

����ֵ: 		
**********************************/
template<class Map> void ClearMap(Map& v)
{
	v.clear();
}

template<class Map> struct Map_Cleaner
{
	static void Clear(Map& v) {ClearMap(v);}
};

/**********************************
����: ���ָ��Ӱ�� (���ǰ���ͷ�ָ��), ������ map<key, Object*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrMap> void ClearPtrMap(PtrMap& v)
{
	for(PtrMap::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
		delete it->second;

	v.clear();
}

template<class PtrMap> struct PtrMap_Cleaner
{
	static void Clear(PtrMap& v) {ClearPtrMap(v);}
};

/**********************************
����: ���ָ��Ӱ�� (ָ��ͬʱ��ָ������), ������ map<key, Object*[]>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrArrayMap> void ClearPtrArrayMap(PtrArrayMap& v)
{
	for(PtrArrayMap::iterator	it = v.begin(); 
								it != v.end(); 
								++it)
		delete[] it->second;

	v.clear();
}

template<class PtrArrayMap> struct PtrArrayMap_Cleaner
{
	static void Clear(PtrArrayMap& v) {ClearPtrArrayMap(v);}
};

/**********************************
����: �������-���� (���ǰ������ڲ�����), ������ set<vector<Object>*>
����: 
		v		: vector / list / set

����ֵ: 		
**********************************/
template<class SetSet> void ClearSetSet(SetSet& v)
{
	for(SetSet::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		(*it)->clear();
		delete (*it);
	}

	v.clear();
}

template<class SetSet> struct SetSet_Cleaner
{
	static void Clear(SetSet& v) {ClearSetSet(v);}
};

/**********************************
����: ���ָ�뼯��-���� (���ǰ������ڲ�ָ�뼯��), ������ set<vector<Object*>*>
����: 
		v		: vector / list / set

����ֵ: 		
**********************************/
template<class PtrSetSet> void ClearPtrSetSet(PtrSetSet& v)
{
	for(PtrSetSet::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		ClearPtrSet(**it);
		delete (*it);
	}

	v.clear();
}

template<class PtrSetSet> struct PtrSetSet_Cleaner
{
	static void Clear(PtrSetSet& v) {ClearPtrSetSet(v);}
};

/**********************************
����: ���ָ�����鼯��Ӱ�� (���ǰ�����ָ�����鼯��), ������ map<vector<Object*[]>*>
����: 
		v		: vector / list / set

����ֵ: 		
**********************************/
template<class PtrArraySetSet> void ClearPtrArraySetSet(PtrArraySetSet& v)
{
	for(PtrArraySetSet::iterator	it = v.begin(); 
									it != v.end(); 
									++it)
	{
		ClearPtrArraySet(**it);
		delete (*it);
	}

	v.clear();
}

template<class PtrArraySetSet> struct PtrArraySetSet_Cleaner
{
	static void Clear(PtrArraySetSet& v) {ClearPtrArraySetSet(v);}
};

/**********************************
����: �������Ӱ�� (���ǰ���������), ������ map<key, vector<Object>*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class SetMap> void ClearSetMap(SetMap& v)
{
	for(SetMap::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		it->second->clear();
		delete it->second;
	}

	v.clear();
}

template<class SetMap> struct SetMap_Cleaner
{
	static void Clear(SetMap& v) {ClearSetMap(v);}
};

/**********************************
����: ���ָ�뼯��Ӱ�� (���ǰ�����ָ�뼯��), ������ map<key, vector<Object*>*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrSetMap> void ClearPtrSetMap(PtrSetMap& v)
{
	for(PtrSetMap::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		ClearPtrSet(*(it->second));
		delete it->second;
	}

	v.clear();
}

template<class PtrSetMap> struct PtrSetMap_Cleaner
{
	static void Clear(PtrSetMap& v) {ClearPtrSetMap(v);}
};

/**********************************
����: ���ָ�����鼯��Ӱ�� (���ǰ�����ָ�����鼯��), ������ map<key, vector<Object*[]>*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrArraySetMap> void ClearPtrArraySetMap(PtrArraySetMap& v)
{
	for(PtrArraySetMap::iterator	it = v.begin(); 
									it != v.end(); 
									++it)
	{
		ClearPtrArraySet(*(it->second));
		delete it->second;
	}

	v.clear();
}

template<class PtrArraySetMap> struct PtrArraySetMap_Cleaner
{
	static void Clear(PtrArraySetMap& v) {ClearPtrArraySetMap(v);}
};

/**********************************
����: ���ӳ��-Ӱ�� (���ǰ������ڲ�ӳ��), ������ map<key, map<key2, Object>*>
����: 
v		: map

����ֵ: 		
**********************************/
template<class MapMap> void ClearMapMap(MapMap& v)
{
	for(MapMap::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		it->second->clear();
		delete it->second;
	}

	v.clear();
}

template<class MapMap> struct MapMap_Cleaner
{
	static void Clear(MapMap& v) {ClearMapMap(v);}
};

/**********************************
����: ���ָ��ӳ��-Ӱ�� (���ǰ�����ָ���ڲ�ӳ��), ������ map<key, map<key2, Object*>*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrMapMap> void ClearPtrMapMap(PtrMapMap& v)
{
	for(PtrMapMap::iterator	it = v.begin(); 
							it != v.end(); 
							++it)
	{
		ClearPtrMap(*(it->second));
		delete it->second;
	}

	v.clear();
}

template<class PtrMapMap> struct PtrMapMap_Cleaner
{
	static void Clear(PtrMapMap& v) {ClearPtrMapMap(v);}
};

/**********************************
����: ���ָ��ӳ��-Ӱ�� (���ǰ�����ָ�������ڲ�ӳ��), ������ map<key, map<key2, Object*[]>*>
����: 
		v		: map

����ֵ: 		
**********************************/
template<class PtrArrayMapMap> void ClearPtrArrayMapMap(PtrArrayMapMap& v)
{
	for(PtrArrayMapMap::iterator	it = v.begin(); 
									it != v.end(); 
									++it)
	{
		ClearPtrArrayMap(*(it->second));
		delete it->second;
	}

	v.clear();
}

template<class PtrArrayMapMap> struct PtrArrayMapMap_Cleaner
{
	static void Clear(PtrArrayMapMap& v) {ClearPtrArrayMapMap(v);}
};

/************************************************************************/
/*                           ָ�뼯������                               */
/************************************************************************/
template<class Set, class Cleaner> struct SetWrapper
{
	typedef typename Set::iterator			iterator;
	typedef typename Set::const_iterator	const_iterator;
	typedef typename Set::value_type		value_type;
	typedef typename Set::reference			reference;
	typedef typename Set::const_reference	const_reference;
	typedef typename Set::pointer			pointer;
	typedef typename Set::const_pointer		const_pointer;
	typedef typename Set::size_type			size_type;
	typedef typename Set::difference_type	difference_type;

	SetWrapper()
	{
	}

	virtual ~SetWrapper()
	{
		Clear();
	}

	void Clear()
	{
		if(!IsEmpty())
		{
			Cleaner::Clear(m_set);
		}
	}

	Set& operator *			()			{return m_set;}
	const Set& operator *	()	const	{return m_set;}
	Set* operator ->		()			{return &m_set;}
	const Set* operator ->	()	const	{return &m_set;}
	Set& Get				()			{return m_set;}
	operator Set&			()			{return m_set;}
	bool IsEmpty			()	const	{return m_set.empty();}
	size_t Size				()	const	{return m_set.size();}

protected:
	Set m_set;

	DECLARE_NO_COPY_CLASS(SetWrapper)
};

template<class Set, class Cleaner> struct VectorWrapper : public SetWrapper<Set, Cleaner>
{
	VectorWrapper()
	{
	}

	reference		operator []	(size_type i)			{return m_set[i];}
	const_reference operator []	(size_type i)	const	{return m_set[i];}

	DECLARE_NO_COPY_CLASS(VectorWrapper)
};

/************************************************************************/
/*                         ָ�����鼯������                             */
/************************************************************************/


/************************************************************************/
/*                           ָ��ӳ������                               */
/************************************************************************/
template<class Map, class Cleaner> struct MapWrapper
{
	typedef typename Map::iterator			iterator;
	typedef typename Map::const_iterator	const_iterator;
	typedef typename Map::key_type			key_type;
	typedef typename Map::mapped_type		mapped_type;
	typedef typename Map::value_type		value_type;
	typedef typename Map::reference			reference;
	typedef typename Map::const_reference	const_reference;
	typedef typename Map::pointer			pointer;
	typedef typename Map::size_type			size_type;
	typedef typename Map::difference_type	difference_type;

	MapWrapper()
	{
	}

	~MapWrapper()
	{
		Clear();
	}

	void Clear()
	{
		if(!IsEmpty())
		{
			Cleaner::Clear(m_map);
		}
	}

	Map&				operator *	()								{return m_map;}
	const Map&			operator *	()						const	{return m_map;}
	Map*				operator ->	()								{return &m_map;}
	const Map*			operator ->	()						const	{return &m_map;}
	mapped_type&		operator []	(const key_type& key)			{return m_map[key];}
	const mapped_type&	operator []	(const key_type& key)	const	{return m_map[key];}
	Map& Get			()			{return m_map;}
	operator Map&		()			{return m_map;}
	bool IsEmpty		()	const	{return m_map.empty();}
	size_t Size			()	const	{return m_map.size();}

private:
	Map m_map;

	DECLARE_NO_COPY_CLASS(MapWrapper)
};

/************************************************************************/
/*                       �ַ����Ƚ� hash ����                           */
/************************************************************************/
template<class T, bool uncase = true, size_t bk_size = 4, size_t min_bks = 8>
// T -> TCHAR* / CString
struct STR_HASH_FUNCTION
{
	enum
	{
		bucket_size	= bk_size,
		min_buckets	= min_bks,
	};

	//HASH_MAP������
	size_t operator() (const T &A) const
	{
		LPCTSTR key	= (LPCTSTR)A;
		UINT nHash	= 0;

		if(uncase)
		{
			while(*key)
			{
				UINT delta = (*key >= _T('A') && *key <= _T('Z')) ? 32 : 0;
				nHash	= (nHash << 5) + nHash + delta + *key++;
			}
		}
		else
		{
			while(*key)
				nHash	= (nHash << 5) + nHash + *key++;
		}

		return nHash;
	}
	//�ȽϺ�����
	bool operator() (const T &A, const T &B) const
	{
		if(uncase)
			return lstrcmpi((LPCTSTR)A, (LPCTSTR)B) < 0;
		else
			return lstrcmp((LPCTSTR)A, (LPCTSTR)B) < 0;
	}
};

typedef STR_HASH_FUNCTION<LPCTSTR, false>	CASE_TCHAR_HASH_FUNCTION;
typedef STR_HASH_FUNCTION<LPCTSTR, true>	UNCASE_TCHAR_HASH_FUNCTION;
typedef STR_HASH_FUNCTION<CString, false>	CASE_STR_HASH_FUNCTION;
typedef STR_HASH_FUNCTION<CString, true>	UNCASE_STR_HASH_FUNCTION;

/************************************************************************/
/*                            �ȽϷº���                                */
/************************************************************************/
struct bool_comp_func
{
	bool operator() (bool v1, bool v2) const
	{
		if(!v1)
			return false;
		if(v1 == v2)
			return false;

		return true;
	}
};

template<class T>
// T -> (signed / unsigned) short / int / long / __int64
struct integer_comp_func
{
	bool operator() (T v1, T v2) const
	{
		return v1 < v2;
	}
};

typedef integer_comp_func<short>				short_comp_func;
typedef integer_comp_func<int>					int_comp_func;
typedef integer_comp_func<long>					long_comp_func;
typedef integer_comp_func<__int64>				int64_comp_func;
typedef integer_comp_func<unsigned short>		ushort_comp_func;
typedef integer_comp_func<unsigned int>			uint_comp_func;
typedef integer_comp_func<unsigned long>		ulong_comp_func;
typedef integer_comp_func<unsigned __int64>		uint64_comp_func;

struct float_comp_func
{
	bool operator() (float v1, float v2) const
	{
		float disc	= v1 - v2;
		if(fabsf(disc) < 1E-5)
			return false;

		return disc < 0;
	}
};

struct double_comp_func
{
	bool operator() (double v1, double v2) const
	{
		double disc	= v1 - v2;
		if(fabs(disc) < 1E-8)
			return false;

		return disc < 0;
	}
};

template<class T, bool CASE = false>
// T -> (unsigned) char / wchar_t
struct character_comp_func
{
	bool operator() (T v1, T v2) const
	{
		if(!CASE)
		{
			if(v1 >= 'A' && v1 <= 'Z')	v1 += 32;
			if(v2 >= 'A' && v2 <= 'Z')	v2 += 32;
		}

		return v1 < v2;
	}
};

typedef character_comp_func<char, true>				char_case_comp_func;
typedef character_comp_func<unsigned char, true>	uchar_case_comp_func;
typedef character_comp_func<wchar_t, true>			wchar_case_comp_func;
typedef character_comp_func<char, false>			char_ucase_comp_func;
typedef character_comp_func<unsigned char, false>	uchar_ucase_comp_func;
typedef character_comp_func<wchar_t, false>			wchar_ucase_comp_func;

template<class T, bool CASE = false>
// T -> TCHAR* / CString
struct str_comp_func
{
	//�ȽϺ�����
	bool operator() (const T &A, const T &B) const
	{
		if(!CASE)
			return lstrcmpi((LPCTSTR)A, (LPCTSTR)B) < 0;
		else
			return lstrcmp((LPCTSTR)A, (LPCTSTR)B) < 0;
	}
};

typedef str_comp_func<LPCTSTR, true>		case_tchar_comp_func;
typedef str_comp_func<LPCTSTR, false>		uncase_tchar_comp_func;
typedef str_comp_func<CString, true>		case_string_comp_func;
typedef str_comp_func<CString, false>		uncase_string_comp_func;
typedef case_tchar_comp_func				tchar_ptr_case_comp_func;
typedef uncase_tchar_comp_func				tchar_ptr_ucase_comp_func;
typedef case_string_comp_func				string_case_comp_func;
typedef uncase_string_comp_func				string_ucase_comp_func;
/************************************************************************/
/*                            ����º���                                */
/************************************************************************/
template<bool ASC = true>
struct bool_sort_func
{
	bool operator() (bool v1, bool v2) const
	{
		if(v1 == v2)
			return false;

		bool result = !v1;
		return ASC ? result : !result;
	}
};

typedef bool_sort_func<true>	bool_asc_sort_func;
typedef bool_sort_func<false>	bool_desc_sort_func;

template<class T, bool ASC = true>
// T -> (signed / unsigned) short / int / long / __int64
struct integer_sort_func
{
	bool operator() (T v1, T v2) const
	{
		if(v1 == v2)
			return false;

		bool result = v1 < v2;
		return ASC ? result : !result;
	}
};

typedef integer_sort_func<short,			true>		short_asc_sort_func;
typedef integer_sort_func<unsigned short,	true>		ushort_asc_sort_func;
typedef integer_sort_func<int,				true>		int_asc_sort_func;
typedef integer_sort_func<unsigned int,		true>		uint_asc_sort_func;
typedef integer_sort_func<long,				true>		long_asc_sort_func;
typedef integer_sort_func<unsigned long,	true>		ulong_asc_sort_func;
typedef integer_sort_func<__int64,			true>		int64_asc_sort_func;
typedef integer_sort_func<unsigned __int64,	true>		uint64_asc_sort_func;
typedef integer_sort_func<short,			false>		short_desc_sort_func;
typedef integer_sort_func<unsigned short,	false>		ushort_desc_sort_func;
typedef integer_sort_func<int,				false>		int_desc_sort_func;
typedef integer_sort_func<unsigned int,		false>		uint_desc_sort_func;
typedef integer_sort_func<long,				false>		long_desc_sort_func;
typedef integer_sort_func<unsigned long,	false>		ulong_desc_sort_func;
typedef integer_sort_func<__int64,			false>		int64_desc_sort_func;
typedef integer_sort_func<unsigned __int64,	false>		uint64_desc_sort_func;

template<bool ASC = true>
struct float_sort_func
{
	bool operator() (float v1, float v2) const
	{
		float disc	= v1 - v2;
		if(fabsf(disc) < 1E-5)
			return false;

		bool result = disc < 0;
		return ASC ? result : !result;
	}
};

typedef float_sort_func<true>		float_asc_sort_func;
typedef float_sort_func<false>		float_desc_sort_func;

template<bool ASC = true>
struct double_sort_func
{
	bool operator() (double v1, double v2) const
	{
		double disc	= v1 - v2;
		if(fabs(disc) < 1E-8)
			return false;

		bool result = disc < 0;
		return ASC ? result : !result;
	}
};

typedef double_sort_func<true>		double_asc_sort_func;
typedef double_sort_func<false>		double_desc_sort_func;

template<class T, bool ASC = true, bool CASE = false>
// T -> (unsigned) char / wchar_t
struct character_sort_func
{
	bool operator() (T v1, T v2) const
	{
		if(!CASE)
		{
			if(v1 >= 'A' && v1 <= 'Z')	v1 += 32;
			if(v2 >= 'A' && v2 <= 'Z')	v2 += 32;
		}

		if(v1 == v2)
			return false;

		bool result = v1 < v2;
		return ASC ? result : !result;
	}
};

typedef character_sort_func<char, true, true>				char_asc_case_sort_func;
typedef character_sort_func<unsigned char, true, true>		uchar_asc_case_sort_func;
typedef character_sort_func<wchar_t, true, true>			wchar_asc_case_sort_func;
typedef character_sort_func<char, true, false>				char_asc_ucase_sort_func;
typedef character_sort_func<unsigned char, true, false>		uchar_asc_ucase_sort_func;
typedef character_sort_func<wchar_t, true, false>			wchar_asc_ucase_sort_func;
typedef character_sort_func<char, false, true>				char_desc_case_sort_func;
typedef character_sort_func<unsigned char, false, true>		uchar_desc_case_sort_func;
typedef character_sort_func<wchar_t, false, true>			wchar_desc_case_sort_func;
typedef character_sort_func<char, false, false>				char_desc_ucase_sort_func;
typedef character_sort_func<unsigned char, false, false>	uchar_desc_ucase_sort_func;
typedef character_sort_func<wchar_t, false, false>			wchar_desc_ucase_sort_func;

template<class T, bool ASC = true, bool CASE = false>
// T -> TCHAR* / CString
struct str_sort_func
{
	bool operator() (const T& v1, const T& v2) const
	{
		bool result;

		if(CASE)
		{
			int v = lstrcmp((LPCTSTR)v1, (LPCTSTR)v2);
			if(v == 0)
				result = false;
			else
				result = v < 0;
		}
		else
		{
			int v = lstrcmpi((LPCTSTR)v1, (LPCTSTR)v2);
			if(v == 0)
				result = false;
			else
				result = v < 0;
		}

		return ASC ? result : !result;
	}
};

typedef str_sort_func<TCHAR*, true, true>		tchar_ptr_asc_case_sort_func;
typedef str_sort_func<CString, true, true>		string_asc_case_sort_func;
typedef str_sort_func<TCHAR*, true, false>		tchar_ptr_asc_ucase_sort_func;
typedef str_sort_func<CString, true, false>		string_asc_ucase_sort_func;
typedef str_sort_func<TCHAR*, false, true>		tchar_ptr_desc_case_sort_func;
typedef str_sort_func<CString, false, true>		string_desc_case_sort_func;
typedef str_sort_func<TCHAR*, false, false>		tchar_ptr_desc_ucase_sort_func;
typedef str_sort_func<CString, false, false>	string_desc_ucase_sort_func;

/************************************************************************/
/*					   smart_ptr ��ʵ�����������ָ��                    */
/************************************************************************/

template<class _Ty>
struct simple_deleter
{
	static void delete_ptr(_Ty* pv) {delete pv;}
};

template<class _Ty>
struct global_simple_deleter
{
	static void delete_ptr(_Ty* pv) {::delete pv;}
};

template<class _Ty>
struct array_deleter
{
	static void delete_ptr(_Ty* pv) {delete[] pv;}
};

template<class _Ty>
struct global_array_deleter
{
	static void delete_ptr(_Ty* pv) {::delete[] pv;}
};

template<class _Ty, class _Deleter>
class smart_ptr
{
public:
	smart_ptr(_Ty* _Ptr = 0)					: _Myptr(_Ptr)				{}
	smart_ptr(smart_ptr<_Ty, _Deleter>& _Right)	: _Myptr(_Right.release())	{}

	~smart_ptr()
	{
		reset();
	}

	smart_ptr<_Ty, _Deleter>& reset(_Ty* _Ptr = 0)
	{
		if (_Ptr != _Myptr)
		{
			if(_Myptr)
				_Deleter::delete_ptr(_Myptr);

			_Myptr = _Ptr;
		}

		return *this;
	}

	smart_ptr<_Ty, _Deleter>& reset(smart_ptr<_Ty, _Deleter>& _Right)
	{
		if (this != &_Right)
			reset(_Right.release());

		return *this;
	}

	_Ty* release()
	{
		_Ty* _Ptr	= _Myptr;
		_Myptr		= 0;

		return _Ptr;
	}

	smart_ptr<_Ty, _Deleter>& operator = (_Ty* _Ptr)						{return reset(_Ptr);}
	smart_ptr<_Ty, _Deleter>& operator = (smart_ptr<_Ty, _Deleter>& _Right)	{return reset(_Right);}

	bool is_valid		()	const	{return _Myptr != 0;}
	_Ty& operator *		()	const	{return *_Myptr;}
	_Ty* get			()	const	{return _Myptr;}
	_Ty* operator ->	()	const	{return _Myptr;}
	operator _Ty*		()	const	{return _Myptr;}

private:
	template<class _Other> smart_ptr<_Ty, _Deleter>					(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_ptr<_Ty, _Deleter>&	reset		(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_ptr<_Ty, _Deleter>&	operator =	(const smart_ptr<_Ty, _Other>&);

	template<class _Other> smart_ptr<_Ty, _Deleter>					(const smart_ptr<_Other, _Deleter>&);
	template<class _Other> smart_ptr<_Ty, _Deleter>&	reset		(const smart_ptr<_Other, _Deleter>&);
	template<class _Other> smart_ptr<_Ty, _Deleter>&	operator =	(const smart_ptr<_Other, _Deleter>&);

protected:
	_Ty* _Myptr;
};


/************************************************************************/
/*				    smart_simple_ptr ��ʵ������ָ��                      */
/************************************************************************/

template<class _Ty>
class smart_simple_ptr : public smart_ptr<_Ty, simple_deleter<_Ty>>
{
public:
	smart_simple_ptr(_Ty* _Ptr = 0)									: smart_ptr(_Ptr)	{}
	smart_simple_ptr(smart_simple_ptr<_Ty>& _Right)					: smart_ptr(_Right)	{}
	smart_simple_ptr(smart_ptr<_Ty, simple_deleter<_Ty>>& _Right)	: smart_ptr(_Right)	{}

	smart_simple_ptr<_Ty>& operator = (smart_ptr<_Ty, simple_deleter<_Ty>>& _Right)
	{return (smart_simple_ptr<_Ty>&)__super::operator = (_Right);}

	smart_simple_ptr<_Ty>& operator = (smart_simple_ptr<_Ty>& _Right)
	{return (smart_simple_ptr<_Ty>&)__super::operator = (_Right);}

	smart_simple_ptr<_Ty>& operator = (_Ty* _Ptr)
	{return (smart_simple_ptr<_Ty>&)__super::operator = (_Ptr);}

private:
	template<class _Other> smart_simple_ptr<_Ty>				(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_simple_ptr<_Ty>&	operator =	(const smart_ptr<_Ty, _Other>&);

	template<class _Other> smart_simple_ptr<_Ty>				(const smart_simple_ptr<_Other>&);
	template<class _Other> smart_simple_ptr<_Ty>&	operator =	(const smart_simple_ptr<_Other>&);
};

/************************************************************************/
/*		   smart_gd_simple_ptr ��ʵ������ָ�� (ʹ��ȫ�� delete)          */
/************************************************************************/

template<class _Ty>
class smart_gd_simple_ptr : public smart_ptr<_Ty, global_simple_deleter<_Ty>>
{
public:
	smart_gd_simple_ptr(_Ty* _Ptr = 0)										: smart_ptr(_Ptr)	{}
	smart_gd_simple_ptr(smart_gd_simple_ptr<_Ty>& _Right)					: smart_ptr(_Right)	{}
	smart_gd_simple_ptr(smart_ptr<_Ty, global_simple_deleter<_Ty>>& _Right)	: smart_ptr(_Right)	{}

	smart_gd_simple_ptr<_Ty>& operator = (smart_ptr<_Ty, global_simple_deleter<_Ty>>& _Right)
	{return (smart_gd_simple_ptr<_Ty>&)__super::operator = (_Right);}

	smart_gd_simple_ptr<_Ty>& operator = (smart_gd_simple_ptr<_Ty>& _Right)
	{return (smart_gd_simple_ptr<_Ty>&)__super::operator = (_Right);}

	smart_gd_simple_ptr<_Ty>& operator = (_Ty* _Ptr)
	{return (smart_gd_simple_ptr<_Ty>&)__super::operator = (_Ptr);}

private:
	template<class _Other> smart_gd_simple_ptr<_Ty>					(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_gd_simple_ptr<_Ty>&	operator =	(const smart_ptr<_Ty, _Other>&);

	template<class _Other> smart_gd_simple_ptr<_Ty>					(const smart_gd_simple_ptr<_Other>&);
	template<class _Other> smart_gd_simple_ptr<_Ty>&	operator =	(const smart_gd_simple_ptr<_Other>&);
};

/************************************************************************/
/*                   smart_array_ptr ��������ָ��                        */
/************************************************************************/

template<class _Ty>
class smart_array_ptr : public smart_ptr<_Ty, array_deleter<_Ty>>
{
public:
	smart_array_ptr(_Ty* _Ptr = 0)								: smart_ptr(_Ptr)	{}
	smart_array_ptr(smart_simple_ptr<_Ty>& _Right)				: smart_ptr(_Right)	{}
	smart_array_ptr(smart_ptr<_Ty, array_deleter<_Ty>>& _Right)	: smart_ptr(_Right)	{}

	smart_array_ptr<_Ty>& operator = (smart_ptr<_Ty, array_deleter<_Ty>>& _Right)
	{return (smart_array_ptr<_Ty>&)__super::operator = (_Right);}

	smart_array_ptr<_Ty>& operator = (smart_array_ptr<_Ty>& _Right)
	{return (smart_array_ptr<_Ty>&)__super::operator = (_Right);}

	smart_array_ptr<_Ty>& operator = (_Ty* _Ptr)
	{return (smart_array_ptr<_Ty>&)__super::operator = (_Ptr);}

private:
	template<class _Other> smart_array_ptr<_Ty>					(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_array_ptr<_Ty>&	operator =	(const smart_ptr<_Ty, _Other>&);

	template<class _Other> smart_array_ptr<_Ty>					(const smart_array_ptr<_Other>&);
	template<class _Other> smart_array_ptr<_Ty>&	operator =	(const smart_array_ptr<_Other>&);
};

/************************************************************************/
/*          smart_gd_array_ptr ��ʵ������ָ�� (ʹ��ȫ�� delete)          */
/************************************************************************/

template<class _Ty>
class smart_gd_array_ptr : public smart_ptr<_Ty, global_array_deleter<_Ty>>
{
public:
	smart_gd_array_ptr(_Ty* _Ptr = 0)										: smart_ptr(_Ptr)	{}
	smart_gd_array_ptr(smart_gd_array_ptr<_Ty>& _Right)						: smart_ptr(_Right)	{}
	smart_gd_array_ptr(smart_ptr<_Ty, global_array_deleter<_Ty>>& _Right)	: smart_ptr(_Right)	{}

	smart_gd_array_ptr<_Ty>& operator = (smart_ptr<_Ty, global_array_deleter<_Ty>>& _Right)
	{return (smart_gd_array_ptr<_Ty>&)__super::operator = (_Right);}

	smart_gd_array_ptr<_Ty>& operator = (smart_gd_array_ptr<_Ty>& _Right)
	{return (smart_gd_array_ptr<_Ty>&)__super::operator = (_Right);}

	smart_gd_array_ptr<_Ty>& operator = (_Ty* _Ptr)
	{return (smart_gd_array_ptr<_Ty>&)__super::operator = (_Ptr);}

private:
	template<class _Other> smart_gd_array_ptr<_Ty>				(const smart_ptr<_Ty, _Other>&);
	template<class _Other> smart_gd_array_ptr<_Ty>&	operator =	(const smart_ptr<_Ty, _Other>&);

	template<class _Other> smart_gd_array_ptr<_Ty>				(const smart_gd_array_ptr<_Other>&);
	template<class _Other> smart_gd_array_ptr<_Ty>&	operator =	(const smart_gd_array_ptr<_Other>&);
};