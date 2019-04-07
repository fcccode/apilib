#ifndef strstr_h__
#define strstr_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ����� ���������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strstr_a(const char* string1, const char* string2);
  wchar_t* strstr_w(const wchar_t* string1, const wchar_t* string2);

  /**
   * ����� ���������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strstr_na(const char* string1, const char* string2, size_t length1, size_t length2);
  wchar_t* strstr_nw(const wchar_t* string1, const wchar_t* string2, size_t length1, size_t length2);

  /**
   * ����� ��������� ��� ����� �������� ���������� ����.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strstr_ea(const char* string1, const char* string2);
  wchar_t* strstr_ew(const wchar_t* string1, const wchar_t* string2);

  /**
   * ����� ��������� ��� ����� �������� ���������� ����.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strstr_ena(const char* string1, const char* string2, size_t length1, size_t length2);
  wchar_t* strstr_enw(const wchar_t* string1, const wchar_t* string2, size_t length1, size_t length2);

  /**
   * ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strrstr_a(const char* string1, const char* string2);
  wchar_t* strrstr_w(const wchar_t* string1, const wchar_t* string2);

  /**
   * ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strrstr_na(const char* string1, const char* string2, size_t length1, size_t length2);
  wchar_t* strrstr_nw(const wchar_t* string1, const wchar_t* string2, size_t length1, size_t length2);

  /**
   * ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strrstr_ea(const char* string1, const char* string2);
  wchar_t* strrstr_ew(const wchar_t* string1, const wchar_t* string2);

  /**
   * ����� ��������� � ����� ������.
   *
   * @param string1  ������.
   * @param string2  ������� ���������.
   * @param length1  ����� ������ ��� ����� �������� �������.
   * @param length2  ����� ������� ��������� ��� ����� �������� �������.
   *
   * @return  ��������� �� ��������� ��������� � ������,
   *          NULL ���� ��������� �� ������� ��� ��������� ������.
  */
  char* strrstr_ena(const char* string1, const char* string2, size_t length1, size_t length2);
  wchar_t* strrstr_enw(const wchar_t* string1, const wchar_t* string2, size_t length1, size_t length2);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strstr_h__