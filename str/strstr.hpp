#ifndef strstr_hpp__
#define strstr_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "strcmp.hpp"
#include "strlen.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����� ���������.
   * ���� ��� ���������� ����������� ������������ strstr, wcsstr.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strstr_x(const X* string1, const X* string2)
  {
    if(!string1 || !string2)
    {
      return NULL;
    }

    const size_t length1 = __strlen_x<X>(string1);
    const size_t length2 = __strlen_x<X>(string2);
    if(length1 < length2)
    {
      return NULL;
    }

    for(size_t i = 0; i <= (length1 - length2); i += 1)
    {
      if(__strequ_nx<X>(&string1[i], string2, length2) == true)
      {
        return (X*)&string1[i];
      }
    }

    return NULL;
  }

  /**
   * [������] ����� ���������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strstr_nx(const X* string1, const X* string2, size_t length1, size_t length2)
  {
    if(!string1 || !string2 || length1 < length2)
    {
      return NULL;
    }

    for(size_t i = 0; i <= (length1 - length2); i += 1)
    {
      if(__strequ_nx<X>(&string1[i], string2, length2) == true)
      {
        return (X*)&string1[i];
      }
    }

    return NULL;
  }

  /**
   * [������] ����� ��������� ��� ����� �������� ���������� ����.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strstr_ex(const X* string1, const X* string2)
  {
    if(!string1 || !string2)
    {
      return NULL;
    }

    const size_t length1 = __strlen_x<X>(string1);
    const size_t length2 = __strlen_x<X>(string2);
    if(length1 < length2)
    {
      return NULL;
    }

    for(size_t i = 0; i <= (length1 - length2); i += 1)
    {
      if(__strequ_enx<X>(&string1[i], string2, length2) == true)
      {
        return (X*)&string1[i];
      }
    }

    return NULL;
  }

  /**
   * [������] ����� ��������� ��� ����� �������� ���������� ����.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strstr_enx(const X* string1, const X* string2, size_t length1, size_t length2)
  {
    if(!string1 || !string2 || length1 < length2)
    {
      return NULL;
    }

    for(size_t i = 0; i <= (length1 - length2); i += 1)
    {
      if(__strequ_enx<X>(&string1[i], string2, length2) == true)
      {
        return (X*)&string1[i];
      }
    }

    return NULL;
  }

  /**
   * [������] ����� ��������� � ����� ������.
   * ���� ��� ���������� ����������� ������������ strrstr, wcsrstr.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrstr_x(const X* string1, const X* string2)
  {
    if(!string1 || !string2)
    {
      return NULL;
    }

    const size_t length1 = __strlen_x<X>(string1);
    const size_t length2 = __strlen_x<X>(string2);
    if(length1 < length2)
    {
      return NULL;
    }

    size_t offset = length1 - length2;

    do
    {
      if(__strequ_nx<X>(&string1[offset], string2, length2) == true)
      {
        return (X*)&string1[offset];
      }
    }
    while(offset-- != 0);

    return NULL;
  }

  /**
   * [������] ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrstr_nx(const X* string1, const X* string2, size_t length1, size_t length2)
  {
    if(!string1 || !string2 || length1 < length2)
    {
      return NULL;
    }
       
    size_t offset = length1 - length2;
    
    do
    {
      if(__strequ_nx<X>(&string1[offset], string2, length2) == true)
      {
        return (X*)&string1[offset];
      }
    }
    while(offset-- != 0);

    return NULL;
  }

  /**
   * [������] ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrstr_ex(const X* string1, const X* string2)
  {
    if(!string1 || !string2)
    {
      return NULL;
    }

    const size_t length1 = __strlen_x<X>(string1);
    const size_t length2 = __strlen_x<X>(string2);
    if(length1 < length2)
    {
      return NULL;
    }

    size_t offset = length1 - length2;

    do
    {
      if(__strequ_enx<X>(&string1[offset], string2, length2) == true)
      {
        return (X*)&string1[offset];
      }
    }
    while(offset-- != 0);

    return NULL;
  }

  /**
   * [������] ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrstr_enx(const X* string1, const X* string2, size_t length1, size_t length2)
  {
    if(!string1 || !string2 || length1 < length2)
    {
      return NULL;
    }
       
    size_t offset = length1 - length2;
    
    do
    {
      if(__strequ_enx<X>(&string1[offset], string2, length2) == true)
      {
        return (X*)&string1[offset];
      }
    }
    while(offset-- != 0);

    return NULL;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strstr_hpp__