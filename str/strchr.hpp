#ifndef strchr_hpp__
#define strchr_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "strlen.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����� ������� � ������.
   * ���� ��� ���������� ����������� ������������ strchr, wcschr.
   *
   * @param string  ������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strchr_x(const X* string, X chr)
  {
    if(!string)
    {
      return NULL;
    }

    size_t length = 0;

    while(1)
    {
      X tmp = string[length];

      if(tmp == chr)
      {
        return (X*)&string[length];
      }

      if(tmp == '\0')
      {
        break;
      }

      length += 1;
    }

    return NULL;
  }

  /**
   * [������] ����� ������� � ������.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strchr_nx(const X* string, size_t maxlen, X chr)
  {
    if(!string || !maxlen)
    {
      return NULL;
    }

    size_t length = 0;

    while( length < maxlen )
    {
      X tmp = string[length];

      if(tmp == chr)
      {
        return (X*)&string[length];
      }

      if(tmp == '\0')
      {
        break;
      }

      length += 1;
    }

    return NULL;
  }

  /**
   * [������] ����� ������� c ����� ������.
   * ���� ��� ���������� ����������� ������������ strrchr, wcsrchr.
   *
   * @param string  ������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrchr_x(const X* string, X chr)
  {
    if(!string)
    {
      return NULL;
    }

    size_t length = __strlen_x<X>(string);

    while(1)
    {
      if(string[length] == chr)
      {
        return (X*)&string[length];
      }
      if(length == 0)
      {
        break;
      }
      length -= 1;
    }

    return NULL;
  }

  /**
   * [������] ����� ������� c ����� ������.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  template<typename X> 
  inline X* __strrchr_nx(const X* string, size_t maxlen, X chr)
  {
    if(!string || !maxlen)
    {
      return NULL;
    }

    size_t length = __strlen_nx<X>(string, maxlen);

    while(1)
    {
      if(string[length] == chr)
      {
        return (X*)&string[length];
      }
      if(length == 0)
      {
        break;
      }
      length -= 1;
    }
    
    return NULL;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strchr_hpp__