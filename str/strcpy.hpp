#ifndef strcpy_hpp__
#define strcpy_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����������� ������.
   * ���� ��� ���������� ����������� ������������ strcpy, wcscpy.
   *
   * @param dst  �������� ������.
   * @param src  �������� ������.
   *
   * @return  ����� ���������������� �������� ������ ��� ����� �������� �������,
   *          0 � ������ ������.
  */
  template<typename X> 
  inline size_t __strcpy_x(X* dst, const X* src)
  {     
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = 0;

    while(1)
    {
      X chr = dst[length] = src[length];
      if(chr == '\0')
      {
        break;
      }
      length += 1;
    }

    return length;
  }

  /**
   * [������] ����������� ������.
   * ���� ��� ���������� ����������� ������������ strncpy, wcsncpy.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxcnt  ������������ ���������� ���������� �������� �������� ������.
   *
   * @return  ����� ���������������� �������� ������ ��� ����� �������� �������,
   *          0 � ������ ������.
  */
  template<typename X>
  inline size_t __strcpy_nx(X* dst, const X* src, size_t maxcnt)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = 0;

    while(1)
    {
      if(length >= maxcnt)
      {
        dst[length] = '\0';
        break;
      }

      X chr = dst[length] = src[length];
      if(chr == '\0')
      {
        break;
      }

      length += 1;
    }

    return length;
  }

  /**
   * [������] ����������� ������.
   * ���� ��� ���������� ����������� ������������ strlcpy, wcslcpy.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   *
   * @return  ��������� ����� �������� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ����� maxlen �������� ������������� ������ ������,
   *          0 � ������ ������.
  */
  template<typename X>
  inline size_t __strcpy_lx(X* dst, const X* src, size_t maxlen)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = 0;
    size_t zindex = maxlen - 1;

    while(1)
    {
      X chr = src[length];

      if(length < maxlen)
      {
        dst[length] = ((length != zindex) ? chr : '\0');
      }

      if(chr == '\0')
      {
        break;
      }

      length += 1;
    }

    return length;
  }

  /**
   * [������] ����������� ������.
   * ���� ��� ���������� ����������� ������������ strlcpy, wcslcpy.
   *
   * @param dst     �������� ������.
   * @param src     �������� ������.
   * @param maxlen  ������������ ����� �������� ������ � ������ �������� �������.
   * @param maxcnt  ������������ ���������� ���������� �������� �������� ������.
   *
   * @return  ��������� ����� �������� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ����� maxlen �������� ������������� ������ ������,
   *          0 � ������ ������.
  */
  template<typename X>
  inline size_t __strcpy_lnx(X* dst, const X* src, size_t maxlen, size_t maxcnt)
  {
    if(!dst || !src)
    {
      return 0;
    }

    size_t length = 0;
    size_t zindex = maxlen - 1;

    while(1)
    {
      if(length >= maxcnt)
      {
        if(length < maxlen)
        {
          dst[length] = '\0';
        }
        break;
      }

      X chr = src[length];

      if(length < maxlen)
      {
        dst[length] = ((length != zindex) ? chr : '\0');
      }

      if(chr == '\0')
      {
        break;
      }

      length += 1;
    }

    return length;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strcpy_hpp__