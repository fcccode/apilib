#ifndef chrnum_hpp__
#define chrnum_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   *
   * @param  � ������ ������ - ������ '0'-'9' ��� 'A'-'Z',
   *         � ������ ������ - ������ ' '.
  */
  template<typename X, typename Y>
  inline X __ntochr_x(Y digit)
  {
    if(digit >=  0 && digit <=  9) return('0' + digit);
    if(digit >= 10 && digit <= 35) return('A' + digit - 10);
    return ' ';
  }

  /**
   * [������] ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param radix  �������� ������.
   *
   * @return  � ������ ������ - ����� �� 0 �� 35,
   *          � ������ ������ - 0.
  */
  template<typename X, typename Y>
  inline Y __chrton_x(X chr, int radix)
  {
    if(chr >= '0' && chr <= '9')
    {
      unsigned char t = (chr - '0');
      if(radix <= t)return 0;
      return t;
    }
    if(chr >= 'A' && chr <= 'Z')
    {
      unsigned char t = (chr - 'A' + 10);
      if(radix <= t)return 0;
      return t;
    }
    if(chr >= 'a' && chr <= 'z')
    {
      unsigned char t = (chr - 'a' + 10);
      if(radix <= t)return 0;
      return t;
    }
    return 0;
  }

  /**
   * [������] ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  template<typename X, typename Y>
  inline int __ntochr_x(Y digit, X* chr)
  {
    if(digit >= 0 && digit <= 9)
    {
      if(chr)*chr = (X)('0' + digit);
      return 1;
    }
    if(digit >= 10 && digit <= 35)
    {
      if(chr)*chr = (X)('A' + digit - 10);
      return 1;
    }
    return 0;
  }

  /**
   * [������] ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  template<typename X, typename Y>
  inline int __chrton_x(X chr, Y* digit, int radix)
  {
    if(chr >= '0' && chr <= '9')
    {
      unsigned char t = (chr - '0');
      if(radix <= t)return 0;
      if(digit)*digit = t;
      return 1;
    }
    if(chr >= 'A' && chr <= 'Z')
    {
      unsigned char t = (chr - 'A' + 10);
      if(radix <= t)return 0;
      if(digit)*digit = t;
      return 1;
    }
    if(chr >= 'a' && chr <= 'z')
    {
      unsigned char t = (chr - 'a' + 10);
      if(radix <= t)return 0;
      if(digit)*digit = t;
      return 1;
    }
    return 0;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // chrnum_hpp__