#ifndef chrnum_h__
#define chrnum_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int uchtochr_a(unsigned char digit, char* chr);
  int uchtochr_w(unsigned char digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int ushtochr_a(unsigned short digit, char* chr);
  int ushtochr_w(unsigned short digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int ultochr_a(unsigned long int digit, char* chr);
  int ultochr_w(unsigned long int digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int ulltochr_a(unsigned long long int digit, char* chr);
  int ulltochr_w(unsigned long long int digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int chtochr_a(char digit, char* chr);
  int chtochr_w(char digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int shtochr_a(short digit, char* chr);
  int shtochr_w(short digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int ltochr_a(long int digit, char* chr);
  int ltochr_w(long int digit, wchar_t* chr);

  /**
   * ����������� ����� � ������.
   *
   * @param digit  ����� �� 0 �� 35.
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   *
   * @param  1 - ������������� ���������,
   *         0 - ������������� ���������.
  */
  int lltochr_a(long long int digit, char* chr);
  int lltochr_w(long long int digit, wchar_t* chr);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtouch_a(char chr, unsigned char* digit, int radix);
  int chrtouch_w(wchar_t chr, unsigned char* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtoush_a(char chr, unsigned short* digit, int radix);
  int chrtoush_w(wchar_t chr, unsigned short* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtoul_a(char chr, unsigned long int* digit, int radix);
  int chrtoul_w(wchar_t chr, unsigned long int* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtoull_a(char chr, unsigned long long int* digit, int radix);
  int chrtoull_w(wchar_t chr, unsigned long long int* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtoch_a(char chr, char* digit, int radix);
  int chrtoch_w(wchar_t chr, char* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtosh_a(char chr, short* digit, int radix);
  int chrtosh_w(wchar_t chr, short* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtol_a(char chr, long int* digit, int radix);
  int chrtol_w(wchar_t chr, long int* digit, int radix);

  /**
   * ����������� ������� � �����.
   *
   * @param chr    ������ '0'-'9' ��� 'A'-'Z'.
   * @param digit  ����� �� 0 �� 35.
   * @param radix  �������� ������ �� 0 �� 35.
   *
   * @return  1 - ������������� ���������,
   *          0 - ������������� ���������.
  */
  int chrtoll_a(char chr, long long int* digit, int radix);
  int chrtoll_w(wchar_t chr, long long int* digit, int radix);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // chrnum_h__