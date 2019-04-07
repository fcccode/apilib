#ifndef strnum_h__
#define strnum_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  //TODO: �������� atol, wtol...

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned char strtouch_a(const char* string, char** endptr, unsigned int radix);
  unsigned char strtouch_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned char strtouch_na(const char* string, size_t length, char** endptr, unsigned int radix);
  unsigned char strtouch_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  char strtoch_a(const char* string, char** endptr, unsigned int radix);
  char strtoch_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  char strtoch_na(const char* string, size_t length, char** endptr, unsigned int radix);
  char strtoch_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned short strtoush_a(const char* string, char** endptr, unsigned int radix);
  unsigned short strtoush_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned short strtoush_na(const char* string, size_t length, char** endptr, unsigned int radix);
  unsigned short strtoush_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  short strtosh_a(const char* string, char** endptr, unsigned int radix);
  short strtosh_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  short strtosh_na(const char* string, size_t length, char** endptr, unsigned int radix);
  short strtosh_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned long int strtoul_a(const char* string, char** endptr, unsigned int radix);
  unsigned long int strtoul_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned long int strtoul_na(const char* string, size_t length, char** endptr, unsigned int radix);
  unsigned long int strtoul_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  long int strtol_a(const char* string, char** endptr, unsigned int radix);
  long int strtol_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  long int strtol_na(const char* string, size_t length, char** endptr, unsigned int radix);
  long int strtol_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned long long int strtoull_a(const char* string, char** endptr, unsigned int radix);
  unsigned long long int strtoull_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  unsigned long long int strtoull_na(const char* string, size_t length, char** endptr, unsigned int radix);
  unsigned long long int strtoull_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  long long int strtoll_a(const char* string, char** endptr, unsigned int radix);
  long long int strtoll_w(const wchar_t* string, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ������ � �����.
   *
   * @param string  ������.
   * @param length  ����� ������ ��� ����� �������� �������.
   * @param endptr  ������ ������ ���������� ����������� ������ � �����.
   * @param radix   �������� ������ �� 2 �� 35, ��� ��������������� ����������� 0.
   *
   * @return  � ������ ������ - �����,
   *          � ������ ������ - 0.
  */
  long long int strtoll_na(const char* string, size_t length, char** endptr, unsigned int radix);
  long long int strtoll_nw(const wchar_t* string, size_t length, wchar_t** endptr, unsigned int radix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t uchtostr_a(unsigned char number, char* string, unsigned int radix, int prefix);
  size_t uchtostr_w(unsigned char number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t uchtostr_la(unsigned char number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t uchtostr_lw(unsigned char number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t chtostr_a(char number, char* string, unsigned int radix, int prefix);
  size_t chtostr_w(char number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t chtostr_la(char number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t chtostr_lw(char number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t ushtostr_a(unsigned short number, char* string, unsigned int radix, int prefix);
  size_t ushtostr_w(unsigned short number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t ushtostr_la(unsigned short number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t ushtostr_lw(unsigned short number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t shtostr_a(short number, char* string, unsigned int radix, int prefix);
  size_t shtostr_w(short number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t shtostr_la(short number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t shtostr_lw(short number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t ultostr_a(unsigned long int number, char* string, unsigned int radix, int prefix);
  size_t ultostr_w(unsigned long int number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t ultostr_la(unsigned long int number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t ultostr_lw(unsigned long int number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t ltostr_a(long int number, char* string, unsigned int radix, int prefix);
  size_t ltostr_w(long int number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t ltostr_la(long int number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t ltostr_lw(long int number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t ulltostr_a(unsigned long long int number, char* string, unsigned int radix, int prefix);
  size_t ulltostr_w(unsigned long long int number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t ulltostr_la(unsigned long long int number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t ulltostr_lw(unsigned long long int number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          � ������ ������ 0.
  */
  size_t lltostr_a(long long int number, char* string, unsigned int radix, int prefix);
  size_t lltostr_w(long long int number, wchar_t* string, unsigned int radix, int prefix);

  /**
   * ����������� ����� � ������.
   *
   * @param number  �����.
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param radix   �������� ������ �� 2 �� 35, �� ��������� ��� 0 ��� ���������� ������.
   *
   * @return  ��������� ����� ������ ��� ����� �������� �������,
   *          ��������� ����� ������ ��� ������ maxlen �������� ������������� ������ ������,
   *          � ������ ������ 0.
  */
  size_t lltostr_la(long long int number, char* string, size_t maxlen, unsigned int radix, int prefix);
  size_t lltostr_lw(long long int number, wchar_t* string, size_t maxlen, unsigned int radix, int prefix);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strnum_h__