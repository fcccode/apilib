#ifndef strchr_h__
#define strchr_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ����� ������� � ������.
   *
   * @param string  ������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  char* strchr_a(const char* string, char chr);
  wchar_t* strchr_w(const wchar_t* string, wchar_t chr);

  /**
   * ����� ������� � ������.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  char* strchr_na(const char* string, size_t maxlen, char chr);
  wchar_t* strchr_nw(const wchar_t* string, size_t maxlen, wchar_t chr);

  /**
   * ����� ������� c ����� ������.
   *
   * @param string  ������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  char* strrchr_a(const char* string, char chr);
  wchar_t* strrchr_w(const wchar_t* string, wchar_t chr);

  /**
   * ����� ������� c ����� ������.
   *
   * @param string  ������.
   * @param maxlen  ������������ ����� ������ � ������ �������� �������.
   * @param chr     ������.
   *
   * @return  ��������� �� ��������� ������ � ������,
   *          NULL ���� ������ �� ������ ��� ��������� ������.
  */
  char* strrchr_na(const char* string, size_t maxlen, char chr);
  wchar_t* strrchr_nw(const wchar_t* string, size_t maxlen, wchar_t chr);
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strchr_h__