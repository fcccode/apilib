#ifndef strlen_hpp__
#define strlen_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����������� ����� ������.
   * ���� ��� ���������� ����������� ������������ strlen, wcslen.
   *
   * @param string  ������.
   * 
   * @return  � ������ ������ - ����� ������,
   *          � ������ ������ - 0.
  */
  template<typename X> 
  inline size_t __strlen_x(const X* string)
  {
    if(!string)
    {
      return 0;
    }

    size_t length = 0;

    while( string[length] != '\0' )
    {
      length += 1;
    }

    return length;
  }

  /**
   * [������] ����������� ����� ������.
   * ���� ��� ���������� ����������� ������������ strnlen, wcsnlen.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * 
   * @return  � ������ ������ - ����� ������ ��� ����� �������� �������,
   *          � ������ ������ - 0.
  */
  template<typename X>
  inline size_t __strlen_nx(const X* string, size_t maxlen)
  {
    if(!string || !maxlen) 
    {
      return 0;
    }

    size_t length = 0;
    size_t zindex = maxlen - 1;

    while( length < zindex && string[length] != '\0' )
    {
      length += 1;
    }

    return length;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strlen_hpp__