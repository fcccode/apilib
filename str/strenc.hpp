#ifndef strenc_hpp__
#define strenc_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

# include "strmem.hpp"
# if(APILIB_OS_WINNT != 0)
# include <windows.h>
# endif

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����������� ����� ����������� ANSI � Unicode ������ ��� ASCII ��������.
   *
   * ���� ������ ������ ��� ��������������� ���������� ����������� ��������.
   * ������� ��������� �� ������� ��������� 0x00 - 0x7F ��������� �������.
   *
   * @param dst     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   * @param src     �������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  template<typename X1, typename X2>
  inline size_t __xcstoxcs_le(X2* dst, size_t maxlen, const X1* src)
  {
    size_t result = 0;

    if(src)
    {
      size_t length = __strlen_x<X1>(src);

      if(dst && length < maxlen)
      {
        for(size_t i = 0; i < length; i++)
        {
          X1 chr = src[i];
          if(chr > 0x7F)
          {
            result = (size_t)-1;
            break;
          }
          dst[i] = chr;
          result = result + 1;
        }
      }
      else
      {
        result = length;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }

    return result;
  }

  /**
   * [������] ����������� ����� ����������� ANSI � Unicode ������ ��� ASCII ��������.
   *
   * ���� ������ ������ ��� ��������������� ���������� ����������� ��������.
   * ������� ��������� �� ������� ��������� 0x00 - 0x7F ��������� �������.
   *
   * @param dst     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   * @param src     �������� ������.
   * @oaram length  ����� �������� ������ ��� ����� �������� �������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  template<typename X1, typename X2>
  inline size_t __xcstoxcs_lne(X2* dst, size_t maxlen, const X1* src, size_t length)
  {
    size_t result = 0;

    if(src)
    {
      if(dst && length < maxlen)
      {
        for(size_t i = 0; i < length; i++)
        {
          X1 chr = src[i];
          if(chr > 0x7F)
          {
            result = (size_t)-1;
            break;
          }
          dst[i] = chr;
          result = result + 1;
        }
      }
      else
      {
        result = length;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }

    return result;
  }

  /**
   * [������] ����������� �� ������������� ��������� � ���������������� ���������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param dst       �������� ������.
   * @param maxlen    ������������ ����� �������� ������ � ������ �������� �������.
   * @param src       �������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  inline size_t __mbstowcs_l(unsigned long int codepage, unsigned long int flags, wchar_t* dst, size_t maxlen, const char* src)
  {
#   if(APILIB_OS_WINNT != 0)
    size_t result = 0;
    size_t length = 0;

    if(src && (length = __strlen_x<char>(src)) != 0)
    {
      ::SetLastError(ERROR_SUCCESS);

      int converted = ::MultiByteToWideChar(codepage, flags, src, (int)length, dst, (int)maxlen);
      if( converted > 0 )
      {
        result = converted;
      }

      unsigned long int error = ::GetLastError();
      if(error != ERROR_SUCCESS &&
         error != ERROR_INSUFFICIENT_BUFFER)
      {
        result = (size_t)-1;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }
    return result;
#   else
    return(size_t)-1;
#   endif
  }


  /**
   * [������] ����������� �� ������������� ��������� � ���������������� ���������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param dst       �������� ������.
   * @param maxlen    ������������ ����� �������� ������ � ������ �������� �������.
   * @param src       �������� ������.
   * @oaram length    ����� �������� ������ ��� ����� �������� �������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  inline size_t __mbstowcs_ln(unsigned long int codepage, unsigned long int flags, wchar_t* dst, size_t maxlen, const char* src, size_t length)
  {
#   if(APILIB_OS_WINNT != 0)
    size_t result = 0;

    if(src && length)
    {
      ::SetLastError(ERROR_SUCCESS);

      int converted = ::MultiByteToWideChar(codepage, flags, src, (int)length, dst, (int)maxlen);
      if( converted > 0 )
      {
        result = converted;
      }

      unsigned long int error = ::GetLastError();
      if(error != ERROR_SUCCESS &&
         error != ERROR_INSUFFICIENT_BUFFER)
      {
        result = (size_t)-1;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }

    return result;
#   else
    return(size_t)-1;
#   endif
  }

  /**
   * [������] ����������� �� ���������������� ��������� � ������������� ���������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param dst       �������� ������.
   * @param maxlen    ������������ ����� �������� ������ � ������ �������� �������.
   * @param src       �������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  inline size_t __wcstombs_l(unsigned long int codepage, unsigned long int flags, char* dst, size_t maxlen, const wchar_t* src)
  {
#   if(APILIB_OS_WINNT != 0)
    size_t result = 0;
    size_t length = 0;

    if(src && (length = __strlen_x<wchar_t>(src)) != 0)
    {
      ::SetLastError(ERROR_SUCCESS);

      int converted = ::WideCharToMultiByte(codepage, flags, src, (int)length, dst, (int)maxlen, NULL, NULL);
      if( converted > 0 )
      {
        result = converted;
      }

      unsigned long int error = ::GetLastError();
      if(error != ERROR_SUCCESS &&
         error != ERROR_INSUFFICIENT_BUFFER)
      {
        result = (size_t)-1;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }

    return result;
#   else
    return(size_t)-1;
#   endif
  }

  /**
   * [������] ����������� �� ���������������� ��������� � ������������� ���������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param dst       �������� ������.
   * @param maxlen    ������������ ����� �������� ������ � ������ �������� �������.
   * @param src       �������� ������.
   * @oaram length    ����� �������� ������ ��� ����� �������� �������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ (size_t)-1.
  */
  inline size_t __wcstombs_ln(unsigned long int codepage, unsigned long int flags, char* dst, size_t maxlen, const wchar_t* src, size_t length)
  {
#   if(APILIB_OS_WINNT != 0)
    size_t result = 0;

    if(src && length)
    {
      ::SetLastError(ERROR_SUCCESS);

      int converted = ::WideCharToMultiByte(codepage, flags, src, (int)length, dst, (int)maxlen, NULL, NULL);
      if( converted > 0 )
      {
        result = converted;
      }

      unsigned long int error = ::GetLastError();
      if(error != ERROR_SUCCESS &&
         error != ERROR_INSUFFICIENT_BUFFER)
      {
        result = (size_t)-1;
      }
    }

    if(dst && maxlen)
    {
      if(result < maxlen)dst[result] = 0;
      else               dst[     0] = 0;
    }

    return result;
#   else
    return(size_t)-1;
#   endif
  }

  /**
   * [������] ����������� �� ������������� ��������� � ���������������� ��������� ����� ������������� ������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param src       �������� ������.
   * @param result    ����� �������� ������, ����������� NULL.
   *
   * @return  � ������ ������ - ������, ������� ������� ���������� ����� strfree_w(),
   *          � ������ ������ - NULL.
  */
  inline wchar_t* __mbstowcs_dup(unsigned long int codepage, unsigned long int flags, const char* src, size_t* result)
  {
    size_t required = __mbstowcs_l(codepage, flags, NULL, 0, src);
    if(required == (size_t)-1)
    {
      return NULL;
    }

    wchar_t* allocated = __stralloc_x<wchar_t>(required);
    if(allocated == NULL)
    {
      return NULL;
    }

    size_t converted = __mbstowcs_l(codepage, flags, allocated, required + 1, src);
    if(converted == (size_t)-1)
    {
      __strfree_x<wchar_t>(allocated);
      return NULL;
    }

    if(result)
    {
      *result = (size_t)converted;
    }

    return allocated;
  }

  /**
   * [������] ����������� �� ������������� ��������� � ���������������� ��������� ����� ������������� ������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param src       �������� ������.
   * @oaram length    ����� �������� ������ ��� ����� �������� �������.
   * @param result    ����� �������� ������, ����������� NULL.
   *
   * @return  � ������ ������ - ������, ������� ������� ���������� ����� strfree_w(),
   *          � ������ ������ - NULL.
  */
  inline wchar_t* __mbstowcs_dup_n(unsigned long int codepage, unsigned long int flags, const char* src, size_t length, size_t* result)
  {
    size_t required = __mbstowcs_ln(codepage, flags, NULL, 0, src, length);
    if(required == (size_t)-1)
    {
      return NULL;
    }

    wchar_t* allocated = __stralloc_x<wchar_t>(required);
    if(allocated == NULL)
    {
      return NULL;
    }

    size_t converted = __mbstowcs_ln(codepage, flags, allocated, required + 1, src, length);
    if(converted == (size_t)-1)
    {
      __strfree_x<wchar_t>(allocated);
      return NULL;
    }

    if(result)
    {
      *result = (size_t)converted;
    }

    return allocated;
  }

  /**
   * [������] ����������� �� ���������������� ��������� � ������������� ��������� ����� ������������� ������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param src       �������� ������.
   * @param result    ����� �������� ������, ����������� NULL.
   *
   * @return  � ������ ������ - ������, ������� ������� ���������� ����� strfree_a(),
   *          � ������ ������ - NULL.
  */
  inline char* __wcstombs_dup(unsigned long int codepage, unsigned long int flags, const wchar_t* src, size_t* result)
  {
    size_t required = __wcstombs_l(codepage, flags, NULL, 0, src);
    if(required == (size_t)-1)
    {
      return NULL;
    }

    char* allocated = __stralloc_x<char>(required);
    if(allocated == NULL)
    {
      return NULL;
    }

    size_t converted = __wcstombs_l(codepage, flags, allocated, required + 1, src);
    if(converted == (size_t)-1)
    {
      __strfree_x<char>(allocated);
      return NULL;
    }

    if(result)
    {
      *result = (size_t)converted;
    }

    return allocated;
  }

  /**
   * [������] ����������� �� ���������������� ��������� � ������������� ��������� ����� ������������� ������.
   *
   * @param codepage  ��������� ������������� ������.
   * @param flags     �������������� �����.
   * @param src       �������� ������.
   * @oaram length    ����� �������� ������ ��� ����� �������� �������.
   * @param result    ����� �������� ������, ����������� NULL.
   *
   * @return  � ������ ������ - ������, ������� ������� ���������� ����� strfree_a(),
   *          � ������ ������ - NULL.
  */
  inline char* __wcstombs_dup_n(unsigned long int codepage, unsigned long int flags, const wchar_t* src, size_t length, size_t* result)
  {
    size_t required = __wcstombs_ln(codepage, flags, NULL, 0, src, length);
    if(required == (size_t)-1)
    {
      return NULL;
    }

    char* allocated = __stralloc_x<char>(required);
    if(allocated == NULL)
    {
      return NULL;
    }

    size_t converted = __wcstombs_ln(codepage, flags, allocated, required + 1, src, length);
    if(converted == (size_t)-1)
    {
      __strfree_x<char>(allocated);
      return NULL;
    }

    if(result)
    {
      *result = (size_t)converted;
    }

    return allocated;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strenc_hpp__