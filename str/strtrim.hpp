#ifndef strtrim_hpp__
#define strtrim_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "strlen.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ������������� ������� �������� ", ', \  � ������.
   *
   * @param string  ������.
   *
   * @return  � ������ ������ - ����� ���������������� ������ ��� ����� �������� �������,
   *          � ������ ������ - 0.
  */
  template<typename X>
  inline size_t __addslashes_x(X* string)
  {
    if(!string)
    {
      return 0;
    }

    size_t length = __strlen_x<X>(string);
    size_t offset = 0;

    while( offset < length )
    {
      X chr = string[offset];
      if(chr == '"'  || chr == '\'' || chr == '\\')
      {
        X* src = &string[length + 0];
        X* dst = &string[length + 1];
        X* end = &string[offset    ];
        
        while(dst != end)
        {
          *dst-- = *src--;
        }
        *dst = '\\';

        length += 1;
        offset += 1;
      }

      offset += 1;
    }

    return length;
  }

  /**
   * [������] ������������� ������� �������� ", ', \  � ������.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   *
   * @return  ��������� ����� ������ � �������� ��� ����� �������� �������,
   *          ��������� ����� >= maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X>
  inline size_t __addslashes_lx(X* string, size_t maxlen)
  {
    if(!string || !maxlen)
    {
      return 0;
    }

    size_t length = __strlen_nx<X>(string, maxlen);
    size_t needed = length;
    size_t zindex = maxlen - 1;
    size_t offset = 0;

    while( offset < length )
    {
      X chr = string[offset];
      if(chr == '"' || chr == '\'' || chr == '\\')
      {
        if(length < zindex)
        {
          X* src = &string[length + 0];
          X* dst = &string[length + 1];
          X* end = &string[offset    ];

          while(dst != end)
          {
            *dst-- = *src--;
          }
          *dst = '\\';

          length += 1;
          offset += 1;
        }
        needed += 1;
      }
      offset += 1;
    }

    return needed;
  }

  /**
   * [������] * �������� �������� '\r','\n','\t',' ' �� ������ � ����� ������.
   *
   * @param string  ������.
   *
   * @return  � ������ ������ - ����� ���������������� ������ ��� ����� �������� �������,
   *          � ������ ������ - 0.
  */
  template<typename X>
  inline size_t __strtrim_x(X* string)
  {
    if(!string)
    {
      return 0;
    }

    size_t length = __strlen_x<X>(string);
    if(length != 0)
    {
      size_t offset = 0;

      while(length != 0)
      {
        X chr = string[length - 1];
        if(chr != '\r' && chr != '\n' && chr != ' ' && chr != '\t')
        {
          break;
        }
        length -= 1;
      }

      while(offset < length)
      {
        X chr = string[offset];
        if(chr != '\r' && chr != '\n' && chr != ' ' && chr != '\t')
        {
          break;
        }
        offset += 1;
      }

      if(offset != 0)
      {
        for(size_t i = 0; i < (length - offset); i++)
        {
          string[i] = string[i + offset];
        }
        length -= offset;
      }

      string[length] = '\0';
    }

    return length;
  }

  /**
   * [������] �������� �������� '\r','\n','\t',' ' �� ������ � ����� ������.
   *
   * @param string  ������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   *
   * @return  � ������ ������ - ����� ���������������� ������ ��� ����� �������� �������,
   *          � ������ ������ - 0.
   */
  template<typename X>
  inline size_t __strtrim_nx(X* string, size_t maxcnt)
  {
    if(!string)
    {
      return 0;
    }

    size_t length = __strlen_nx<X>(string, maxcnt);
    if(length != 0)
    {
      size_t offset = 0;

      while(length != 0)
      {
        X chr = string[length - 1];
        if(chr != '\r' && chr != '\n' && chr != ' ' && chr != '\t')
        {
          break;
        }
        length -= 1;
      }

      while(offset < length)
      {
        X chr = string[offset];
        if(chr != '\r' && chr != '\n' && chr != ' ' && chr != '\t')
        {
          break;
        }
        offset += 1;
      }

      if(offset != 0)
      {
        for(size_t i = 0; i < (length - offset); i++)
        {
          string[i] = string[i + offset];
        }
        length -= offset;
      }

      string[length] = '\0';
    }

    return length;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strtrim_hpp__