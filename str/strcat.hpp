#ifndef strcat_hpp__
#define strcat_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "strcpy.hpp"
#include "strlen.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ������������� ����� ������ � ����� ������ ������.
   * ���� ��� ���������� ����������� ������������ strcat, wcscat.
   *
   * @param dst  �������� ������.
   * @param src  �������� ������.
   *
   * @return  ����� ���������������� �������� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  template<typename X> 
  inline size_t __strcat_x(X* dst, const X* src)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = __strlen_x<X>(dst);
    return length + __strcpy_x<X>(&dst[length], src);
  }

  /**
   * [������] ������������� ����� ������ � ����� ������ ������.
   * ���� ��� ���������� ����������� ������������ strncat, wcsncat.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxcnt  ������������ ���������� �������������� �������� �������� ������.
   *
   * @return  ����� ���������������� �������� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  template<typename X>
  inline size_t __strcat_nx(X* dst, const X* src, size_t maxcnt)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = __strlen_x<X>(dst);
    return length + __strcpy_nx<X>(&dst[length], src, maxcnt);
  }

  /**
   * [������] ������������� ����� ������ � ����� ������ ������.
   * ���� ��� ���������� ����������� ������������ strlcat, wcslcat.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   *
   * @return  ��������� ����� �������� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ����� maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X>
  inline size_t __strcat_lx(X* dst, const X* src, size_t maxlen)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = __strlen_nx<X>(dst, maxlen);
    return length + __strcpy_lx<X>(&dst[length], src, maxlen - length);
  }

  /**
   * [������] ������������� ����� ������ � ����� ������ ������.
   * ���� ��� ���������� ����������� ������������ strncat_s, wcsncat_s.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   * @param maxcnt  ������������ ���������� �������������� �������� �������� ������.
   *
   * @return  ��������� ����� �������� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ����� maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X>
  inline size_t __strcat_lnx(X* dst, const X* src, size_t maxlen, size_t maxcnt)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = __strlen_nx<X>(dst, maxlen);
    return length + __strcpy_lnx<X>(&dst[length], src, maxlen - length, maxcnt);
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strcat_hpp__