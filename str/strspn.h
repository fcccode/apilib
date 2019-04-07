#ifndef strspn_h__
#define strspn_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ���������� �������� �������������� � ������ � ������ ������.
   *
   * @param string  ������.
   * @param accept  ������ �������� ������� ������ ��������������.
   *
   * @return  ���������� �������� �������������� � ������ � ������ ������,
   *          0 � ������ ������.
  */
  size_t strspn_a(const char* string, const char* accept);
  size_t strspn_w(const wchar_t* string, const wchar_t* accept);

  /**
   * ���������� �������� �������������� � ������ � ������ ������.
   *
   * @param string  ������.
   * @param accept  ������ �������� ������� ������ ��������������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   *
   * @return  ���������� �������� �������������� � ������ � ������ ������,
   *          0 � ������ ������.
  */
  size_t strspn_na(const char* string, const char* accept, size_t maxcnt);
  size_t strspn_nw(const wchar_t* string, const wchar_t* accept, size_t maxcnt);

  /**
   * ���������� �������� ������������� � ������ � ������ ������.
   *
   * @param string  ������.
   * @param reject  ������ �������� ������� ������ �������������.
   *
   * @return  ���������� �������� ������������� � ������ � ������ ������,
   *          0 � ������ ������.
  */
  size_t strcspn_a(const char* string, const char* reject);
  size_t strcspn_w(const wchar_t* string, const wchar_t* reject);

  /**
   * ���������� �������� ������������� � ������ � ������ ������.
   *
   * @param string  ������.
   * @param reject  ������ �������� ������� ������ �������������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   *
   * @return  ���������� �������� ������������� � ������ � ������ ������,
   *          0 � ������ ������.
  */
  size_t strcspn_na(const char* string, const char* reject, size_t maxcnt);
  size_t strcspn_nw(const wchar_t* string, const wchar_t* reject, size_t maxcnt);

  /**
   * ���������� �������� �������������� � ������ � ����� ������.
   *
   * @param string  ������.
   * @param accept  ������ �������� ������� ������ ��������������.
   *
   * @return  ���������� �������� �������������� � ������ � ����� ������,
   *          0 � ������ ������.
  */
  size_t strrspn_a(const char* string, const char* accept);
  size_t strrspn_w(const wchar_t* string, const wchar_t* accept);

  /**
   * ���������� �������� �������������� � ������ � ����� ������.
   *
   * @param string  ������.
   * @param accept  ������ �������� ������� ������ ��������������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   *
   * @return  ���������� �������� �������������� � ������ � ����� ������,
   *          0 � ������ ������.
  */
  size_t strrspn_na(const char* string, const char* accept, size_t maxcnt);
  size_t strrspn_nw(const wchar_t* string, const wchar_t* accept, size_t maxcnt);

  /**
   * ���������� �������� ������������� � ������ � ����� ������.
   *
   * @param string  ������.
   * @param reject  ������ �������� ������� ������ �������������.
   *
   * @return  ���������� �������� ������������� � ������ � ����� ������,
   *          0 � ������ ������.
  */
  size_t strrcspn_a(const char* string, const char* reject);
  size_t strrcspn_w(const wchar_t* string, const wchar_t* reject);

  /**
   * ���������� �������� ������������� � ������ � ����� ������.
   *
   * @param string  ������.
   * @param reject  ������ �������� ������� ������ �������������.
   * @param maxcnt  ������������ ����� ������ ��� ����� �������� �������.
   *
   * @return  ���������� �������� ������������� � ������ � ����� ������,
   *          0 � ������ ������.
  */
  size_t strrcspn_na(const char* string, const char* reject, size_t maxcnt);
  size_t strrcspn_nw(const wchar_t* string, const wchar_t* reject, size_t maxcnt);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // strspn_h__