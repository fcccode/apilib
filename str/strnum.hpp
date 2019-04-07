#ifndef strnum_hpp__
#define strnum_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "chr.hpp"
#include "chrnum.hpp"
#include "strlen.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ���������� ����������� ������ � �������.
   * ��������������� ��������� ��� __strton_x() � __strton_nx().
   *
   * @param string  ������.
   * @param endptr  ������ ���������� ����������� ������ � �����.
   *
   * @return  0 �� ���� ������� ��� ��������� ������.
  */
  template<typename X, typename Y>
  inline Y __strton_exit_x(const X* string, X** endptr)
  {
    if(endptr)
    {
      *endptr = (X*)string;
    }
    return 0;
  }

  /**
   * ����������� ������ � ����� ����� ������� ����� ��� �������� ����� 2, 4, 8, 16, 32.
   * ��������������� ��������� ��� __strton_x().
   *
   * �������� SHIFT ���������� ����� ������, ������� ����������� �������:
   *   1) �������� ������  2 -> ����� �� 1.
   *   2) �������� ������  4 -> ����� �� 2.
   *   3) �������� ������  8 -> ����� �� 3.
   *   4) �������� ������ 16 -> ����� �� 4.
   *   5) �������� ������ 32 -> ����� �� 5.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� �������� � �����.
   * @param radix   �������� ������.
   * @param limit   ����������� ���������� �������� ����� �� ������, 0 ��� ����������� �����.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y, int SHIFT>
  inline Y __strton_lsh_x(const X* string, X** endptr, unsigned int radix, Y limit)
  {
    Y value = 0;

    if(string)
    {
      while(1)
      {
        Y digit;

        if(__chrton_x<X, Y>(*string, &digit, radix) == 0)
        {
          break;
        }

        Y temp = ((value << SHIFT) + digit);
        if(limit != 0 && temp > limit)break;
        if(value != 0 && temp < value)break;
        if(value != 0 && temp < value + radix)break;
        value = temp;

        string += 1;
      }
    }

    if(endptr)
    {
      *endptr = (X*)string;
    }

    return value;
  }

  /**
   * ����������� ������ � ����� ����� ��������� ��� ����� �������� �����.
   * ��������������� ��������� ��� __strton_x().
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� �������� � �����.
   * @param radix   �������� ������.
   * @param limit   ����������� ���������� �������� ����� �� ������, 0 ��� ����������� �����.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y>
  inline Y __strton_mul_x(const X* string, X** endptr, unsigned int radix, Y limit)
  {
    Y value = 0;

    if(string)
    {
      while(1)
      {
        Y digit;

        if(__chrton_x<X, Y>(*string, &digit, radix) == 0)
        {
          break;
        }

        Y temp = ((value * radix) + digit);
        if(limit != 0 && temp > limit)break;
        if(value != 0 && temp < value)break;
        if(value != 0 && temp < value + radix)break;
        value = temp;

        string += 1;
      }
    }

    if(endptr)
    {
      *endptr = (X*)string;
    }

    return value;
  }

  /**
   * [������] ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 36, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y, int IS_SIGNED>
  inline Y __strton_x(const X* string, X** endptr, unsigned int radix)
  {
    /** 
     * �������� ������������ ����������.
    */
    if(!string || ((radix != 0) && (radix < 2 || radix > 36)))
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    /**
     * ������������� ���������� ��������.
    */
    while(__isblank_ex<X>(*string) != 0)
    {
      string += 1;
    }

    int negative = 0;

    /**
     * ������ ����� (������� ����� ������ ��������� ������� ��� ����������� �����).
    */
    if(IS_SIGNED != 0)
    {
      switch(*string)
      {
      case '+': negative = 0; string += 1; break;
      case '-': negative = 1; string += 1; break;
      }
    }
    else
    {
      switch(*string)
      {
      case '+': negative = 0; string += 1; break;
      case '-': return __strton_exit_x<X, Y>(string, endptr);
      }
    }

    /** 
     * ������������� ���������� ��������.
    */
    while(__isblank_ex<X>(*string) != 0)
    {
      string += 1;
    }

    /**
     * ������ ��������, ��� �������� ��� ��������:
     *
     * 1) ������� ������������������ ����� '0xN...N'.
     * 2) ������� ������������� ����� '0N...N'
     * 3) ������� ���������� � ����� �������� ��������������� �����.
    */
    if(string[0] == '0')
    {
      X chr = string[1];

      if(chr == 'x' || chr == 'X')
      {
        if     (radix ==  0)radix = 16;
        else if(radix != 16)return __strton_exit_x<X, Y>(string, endptr);
        string += 2;
      }
      else if(chr >= '0' && chr <= '7')
      {
        if     (radix == 0)radix = 8;
        else if(radix != 8)return __strton_exit_x<X, Y>(string, endptr);
        string += 1;
      }
    }

    /**
     * �� ��������� �������� ������ ��������� ����������.
    */
    if(radix == 0)
    {
      radix = 10;
    }

    Y limit = 0;

    /**
     * ����������� ������ ���������� ��� ���������� ����������� �������� �����.
    */
    if(IS_SIGNED != 0)
    {
      if(negative == 0)
      {
        limit = (((Y)-1) >> 1);
      }
      else
      {
        limit = (((Y)-1) >> 1) + 1;
      }
    }

    Y value = 0;

    /**
     * ������ �����.
    */
    switch(radix)
    {
    case  2: value = __strton_lsh_x<X, Y, 1>(string, endptr, radix, limit); break;
    case  4: value = __strton_lsh_x<X, Y, 2>(string, endptr, radix, limit); break;
    case  8: value = __strton_lsh_x<X, Y, 3>(string, endptr, radix, limit); break;
    case 16: value = __strton_lsh_x<X, Y, 4>(string, endptr, radix, limit); break;
    case 32: value = __strton_lsh_x<X, Y, 5>(string, endptr, radix, limit); break;
    default: value = __strton_mul_x<X, Y   >(string, endptr, radix, limit); break;
    }

    return ((negative != 0) ? (~value + 1) : (value));
  }

  /**
   * ����������� ������ � ����� ����� ������� ����� ��� �������� ����� 2, 4, 8, 16, 32.
   * ��������������� ��������� ��� __strton_nx().
   *
   * �������� SHIFT ���������� ����� ������, ������� ����������� �������:
   *   1) �������� ������  2 -> ����� �� 1.
   *   2) �������� ������  4 -> ����� �� 2.
   *   3) �������� ������  8 -> ����� �� 3.
   *   4) �������� ������ 16 -> ����� �� 4.
   *   5) �������� ������ 32 -> ����� �� 5.
   *
   * @param string  ������.
   * @param length  ����� ������.
   * @param endptr  ������ ������ ���������� ����������� �������� � �����.
   * @param radix   �������� ������.
   * @param limit   ����������� ���������� �������� ����� �� ������, 0 ��� ����������� �����.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y, int SHIFT>
  inline Y __strton_lsh_nx(const X* string, size_t length, X** endptr, unsigned int radix, Y limit)
  {
    Y value = 0;

    if(string)
    {
      while(length != 0)
      {
        Y digit;

        if(__chrton_x<X, Y>(*string, &digit, radix) == 0)
        {
          break;
        }

        Y temp = ((value << SHIFT) + digit);
        if(limit != 0 && temp > limit)break;
        if(value != 0 && temp < value)break;
        if(value != 0 && temp < value + radix)break;
        value = temp;

        string += 1;
        length -= 1;
      }
    }

    if(endptr)
    {
      *endptr = (X*)string;
    }

    return value;
  }

  /**
   * ����������� ������ � ����� � ����������� ��������� ��� ����� �������� �����.
   * ��������������� ��������� ��� __strton_nx().
   *
   * @param string  ������.
   * @param length  ����� ������.
   * @param endptr  ������ ������ ���������� ����������� �������� � �����.
   * @param radix   �������� ������.
   * @param limit   ����������� ���������� �������� ����� �� ������, 0 ��� ����������� �����.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y>
  inline Y __strton_mul_nx(const X* string, size_t length, X** endptr, unsigned int radix, Y limit)
  {
    Y value = 0;

    if(string)
    {
      while(length != 0)
      {
        Y digit;

        if(__chrton_x<X, Y>(*string, &digit, radix) == 0)
        {
          break;
        }

        Y temp = ((value * radix) + digit);
        if(limit != 0 && temp > limit)break;
        if(value != 0 && temp < value)break;
        if(value != 0 && temp < value + radix)break;
        value = temp;

        string += 1;
        length -= 1;
      }
    }

    if(endptr)
    {
      *endptr = (X*)string;
    }

    return value;
  }

  /**
   * [������] ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 36, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y, int IS_SIGNED>
  inline Y __strton_nx(const X* string, size_t length, X** endptr, unsigned int radix)
  {
    /** 
     * �������� ������������ ����������.
    */
    if(!string || !length || ((radix != 0) && (radix < 2 || radix > 36)))
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    int negative = 0;

    /**
     * ������������� ���������� ��������.
    */
    while(length != 0 && __isblank_ex<X>(*string) != 0)
    {
      string += 1;
      length -= 1;
    }

    /**
     * �������� ������� ����� ����� �����������.
    */
    if(length == 0)
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    /**
     * ������ ����� (������� ����� ������ ��������� ������� ��� ����������� �����).
    */
    if(IS_SIGNED != 0)
    {
      switch(*string)
      {
      case '+': negative = 0; string += 1; length -= 1; break;
      case '-': negative = 1; string += 1; length -= 1; break;
      }
    }
    else
    {
      switch(*string)
      {
      case '+': negative = 0; string += 1; length -= 1; break;
      case '-': return __strton_exit_x<X, Y>(string, endptr);
      }
    }

    /**
     * �������� ������� ����� ����� �����������.
    */
    if(length == 0)
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    /**
     * ������������� ���������� ��������.
    */
    while(length != 0 && __isblank_ex<X>(*string) != 0)
    {
      string += 1;
      length -= 1;
    }

    /**
     * �������� ������� ����� ����� �����������.
    */
    if(length == 0)
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    /**
     * ������ ��������, ��� �������� ��� ��������:
     *
     * 1) ������� ������������������ ����� '0xN...N'.
     * 2) ������� ������������� ����� '0N...N'
     * 3) ������� ���������� � ����� �������� ��������������� �����.
    */
    if(string[0] == '0')
    {
      /**
       * [!] ����� ������ ������ ���� ����� 1 ������� �� ������ �����.
      */
      if(length > 1)
      {
        X chr = string[1];

        if(chr == 'x' || chr == 'X')
        {
          if     (radix ==  0)radix = 16;
          else if(radix != 16)return __strton_exit_x<X, Y>(string, endptr);
          string += 2;
          length -= 2;
        }
        else if(chr >= '0' && chr <= '7')
        {
          if     (radix == 0)radix = 8;
          else if(radix != 8)return __strton_exit_x<X, Y>(string, endptr);
          string += 1;
          length -= 1;
        }
      }
    }

    /**
     * �������� ������� ����� ����� �����������.
    */
    if(length == 0)
    {
      return __strton_exit_x<X, Y>(string, endptr);
    }

    /**
     * �� ��������� �������� ������ ��������� ����������.
    */
    if(radix == 0)
    {
      radix = 10;
    }

    Y limit = 0;

    /**
     * ����������� ������ ���������� ��� ���������� ����������� �������� �����.
    */
    if(IS_SIGNED != 0)
    {
      if(negative == 0)
      {
        limit = (((Y)-1) >> 1);
      }
      else
      {
        limit = (((Y)-1) >> 1) + 1;
      }
    }

    Y value = 0;

    /**
     * ������ �����.
    */
    switch(radix)
    {
    case  2: value = __strton_lsh_nx<X, Y, 1>(string, length, endptr, radix, limit); break;
    case  4: value = __strton_lsh_nx<X, Y, 2>(string, length, endptr, radix, limit); break;
    case  8: value = __strton_lsh_nx<X, Y, 3>(string, length, endptr, radix, limit); break;
    case 16: value = __strton_lsh_nx<X, Y, 4>(string, length, endptr, radix, limit); break;
    case 32: value = __strton_lsh_nx<X, Y, 5>(string, length, endptr, radix, limit); break;
    default: value = __strton_mul_nx<X, Y   >(string, length, endptr, radix, limit); break;
    }

    return ((negative != 0) ? (~value + 1) : (value));
  }

  /**
   * ����������� ����� � ������ ����� ������� ����� ��� �������� ����� 2, 4, 8, 16, 32.
   * ��������������� ��������� ��� __ntostr_x().
   *
   * �������� SHIFT ���������� ����� ������, ������� ����������� �������:
   *   1) �������� ������  2 -> ����� �� 1.
   *   2) �������� ������  4 -> ����� �� 2.
   *   3) �������� ������  8 -> ����� �� 3.
   *   4) �������� ������ 16 -> ����� �� 4.
   *   5) �������� ������ 32 -> ����� �� 5.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 36.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y, int SHIFT>
  inline size_t __ntostr_lsh_x(Y number, X* string, unsigned int radix)
  {
    size_t length = 0;

    do
    {
      if(string)
      {
        Y digit = number % radix;

        if(__ntochr_x<X, Y>(digit, string) == 0)
        {
          break;
        }

        string -= 1;
      }

      length = length + 1;
      number = number >> SHIFT;
    }
    while(number != 0);

    return length;
  }

  /**
   * ����������� ����� � ������ ����� ������� ��� ����� �������� �����.
   * ��������������� ��������� ��� __ntostr_x().
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 36.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y>
  inline size_t __ntostr_div_x(Y number, X* string, unsigned int radix)
  {
    size_t length = 0;

    do
    {
      if(string)
      {
        Y digit = number % radix;

        if(__ntochr_x<X, Y>(digit, string) == 0)
        {
          break;
        }

        string -= 1;
      }

      length = length + 1;
      number = number / radix;
    }
    while(number != 0);

    return length;
  }

  /**
   * [������] ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 36, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y, int IS_SIGNED> 
  inline size_t __ntostr_x(Y number, X* string, unsigned int radix, int prefix)
  {
    size_t length = 0;

    /** 
     * �������� ������������ ����������.
    */
    if((radix != 0) && (radix < 2 || radix > 36))
    {
      return 0;
    }

    /**
     * ������ ����� ��� �������������.
    */
    if(IS_SIGNED != 0)
    {
      const Y transition = (((Y)-1) >> 1) + 1;
      if(number >= transition)
      {
        if(string != NULL)
        {
          *string++ = '-';
        }
        length = (length + 1);
        number = ~number + 1;
      }
    }

    /**
     * ������ �������� ��� �������������.
    */
    if(prefix != 0)
    {
      switch(radix)
      {
      case 8:
        if(string != NULL)
        {
          *string++ = '0';
        }
        length += 1;
        break;
      case 16:
        if(string != NULL)
        {
          *string++ = '0';
          *string++ = 'x';
        }
        length += 2;
        break;
      }
    }

    /**
     * �� ��������� �������� ������ ��������� ����������.
    */
    if(radix == 0)
    {
      radix = 10;
    }

    size_t offset = 0;

    /**
     * ����������� ���������� �������� ��������� ��� ������ �����.
    */
    switch(radix)
    {
    case  2: offset = __ntostr_lsh_x<X, Y, 1>(number, NULL, radix); break;
    case  4: offset = __ntostr_lsh_x<X, Y, 2>(number, NULL, radix); break;
    case  8: offset = __ntostr_lsh_x<X, Y, 3>(number, NULL, radix); break;
    case 16: offset = __ntostr_lsh_x<X, Y, 4>(number, NULL, radix); break;
    case 32: offset = __ntostr_lsh_x<X, Y, 5>(number, NULL, radix); break;
    default: offset = __ntostr_div_x<X, Y   >(number, NULL, radix); break;
    }

    /**
     * ������ ����� �� ����� � ������.
    */
    if(string != NULL && offset != 0)
    {
      switch(radix)
      {
      case  2: offset = __ntostr_lsh_x<X, Y, 1>(number, &string[offset - 1], radix); break;
      case  4: offset = __ntostr_lsh_x<X, Y, 2>(number, &string[offset - 1], radix); break;
      case  8: offset = __ntostr_lsh_x<X, Y, 3>(number, &string[offset - 1], radix); break;
      case 16: offset = __ntostr_lsh_x<X, Y, 4>(number, &string[offset - 1], radix); break;
      case 32: offset = __ntostr_lsh_x<X, Y, 5>(number, &string[offset - 1], radix); break;
      default: offset = __ntostr_div_x<X, Y   >(number, &string[offset - 1], radix); break;
      }
      string += offset;
    }

    /**
     * ���������� ����� ������.
    */
    length += offset;

    /**
     * ������ �������� �������.
    */
    if(string != NULL)
    {
      *string++ = '\0';
    }
    
    return length;
  }

  /**
   * ����������� ����� � ������ ����� ������� ����� ��� �������� ����� 2, 4, 8, 16, 32.
   * ��������������� ��������� ��� __ntostr_lx().
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   * @param radix   �������� ������ �� 2 �� 36.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ maxcnt �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y, int SHIFT>
  inline size_t __ntostr_lsh_lx(Y number, X* string, size_t maxcnt, unsigned int radix)
  {
    size_t length = 0;

    do
    {
      if(string != NULL && length < maxcnt)
      {
        Y digit = number % radix;

        if(__ntochr_x<X, Y>(digit, string) == 0)
        {
          break;
        }

        string -= 1;
      }

      length = length + 1;
      number = number >> SHIFT;
    }
    while(number != 0);

    return length;
  }
  
  /**
   * ����������� ����� � ������ ����� ������� ��� ����� �������� �����.
   * ��������������� ��������� ��� __ntostr_lx().
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   * @param radix   �������� ������ �� 2 �� 36.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ maxcnt �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y>
  inline size_t __ntostr_div_lx(Y number, X* string, size_t maxcnt, unsigned int radix)
  {
    size_t length = 0;

    do
    {
      if(string != NULL && length < maxcnt)
      {
        Y digit = number % radix;

        if(__ntochr_x<X, Y>(digit, string) == 0)
        {
          break;
        }

        string -= 1;
      }

      length = length + 1;
      number = number / radix;
    }
    while(number != 0);

    return length;
  }

  /**
   * [������] ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 36, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  template<typename X, typename Y, int IS_SIGNED> 
  inline size_t __ntostr_lx(Y number, X* string, size_t maxlen, unsigned int radix, int prefix)
  {
    size_t length = 0;
    size_t maxcnt = 0;

    /** 
     * �������� ������������ ����������.
    */
    if((radix != 0) && (radix < 2 || radix > 36))
    {
      return 0;
    }

    /**
     * ����������� ������������ ����� ������ ��� ����� �������� �������.
    */
    if(string != NULL && maxlen != 0)
    {
      maxcnt = maxlen - 1;
    }

    /**
     * ������ ����� ��� �������������.
    */
    if(IS_SIGNED != 0)
    {
      const Y transition = (((Y)-1) >> 1) + 1;
      if(number >= transition)
      {
        if(string != NULL && length < maxcnt)
        {
          *string++ = '-';
        }
        length = (length + 1);
        number = ~number + 1;
      }
    }

    /**
     * ������ �������� ��� �������������.
    */
    if(prefix != 0)
    {
      switch(radix)
      {
      case 8:
        if(string != NULL && length < maxcnt)
        {
          *string++ = '0';
        }
        length += 1;
        break;
      case 16:
        if(string != NULL && length < maxcnt)
        {
          *string++ = '0';
        }
        length += 1;
        if(string != NULL && length < maxcnt)
        {
          *string++ = 'x';
        }
        length += 1;
        break;
      }
    }

    /**
     * �� ��������� �������� ������ ��������� ����������.
    */
    if(radix == 0)
    {
      radix = 10;
    }

    size_t offset = 0;

    /**
     * ����������� ���������� �������� ��������� ��� ������ �����.
    */
    switch(radix)
    {
    case  2: offset = __ntostr_lsh_lx<X, Y, 1>(number, NULL, 0, radix); break;
    case  4: offset = __ntostr_lsh_lx<X, Y, 2>(number, NULL, 0, radix); break;
    case  8: offset = __ntostr_lsh_lx<X, Y, 3>(number, NULL, 0, radix); break;
    case 16: offset = __ntostr_lsh_lx<X, Y, 4>(number, NULL, 0, radix); break;
    case 32: offset = __ntostr_lsh_lx<X, Y, 5>(number, NULL, 0, radix); break;
    default: offset = __ntostr_div_lx<X, Y   >(number, NULL, 0, radix); break;
    }

    /**
     * ������ ����� �� ����� � ������ ��� ����������� ������� ������.
    */
    if(string != NULL && offset != 0 && maxcnt >= length + offset)
    {
      switch(radix)
      {
      case  2: offset = __ntostr_lsh_lx<X, Y, 1>(number, &string[offset - 1], maxcnt - length, radix); break;
      case  4: offset = __ntostr_lsh_lx<X, Y, 2>(number, &string[offset - 1], maxcnt - length, radix); break;
      case  8: offset = __ntostr_lsh_lx<X, Y, 3>(number, &string[offset - 1], maxcnt - length, radix); break;
      case 16: offset = __ntostr_lsh_lx<X, Y, 4>(number, &string[offset - 1], maxcnt - length, radix); break;
      case 32: offset = __ntostr_lsh_lx<X, Y, 5>(number, &string[offset - 1], maxcnt - length, radix); break;
      default: offset = __ntostr_div_lx<X, Y   >(number, &string[offset - 1], maxcnt - length, radix); break;
      }
      string += offset;
    }

    /**
     * ���������� ����� ������.
    */
    length += offset;
 
    /**
     * ������ �������� �������.
    */
    if(string != NULL && length < maxlen)
    {
      *string++ = '\0';
    }

    return length;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strnum_hpp__