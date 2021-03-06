#ifndef chrcmp_h__
#define chrcmp_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ��������� ���� ��������.
   *
   * @param c1  ������ ������.
   * @param c2  ������ ������.
   *
   * @return  ( 1) - ������ ������ ������ ������� �������,
   *          (-1) - ������ ������ ������ ������� �������,
   *          ( 0) - ������� ���������.
  */
  int chrcmp_a(char c1, char c2);
  int chrcmp_w(wchar_t c1, wchar_t c2);

  /**
   * ��������� ���� �������� ��� ����� �������� ���������� ����.
   *
   * @param c1  ������ ������.
   * @param c2  ������ ������.
   *
   * @return  ( 1) - ������ ������ ������ ������� �������,
   *          (-1) - ������ ������ ������ ������� �������,
   *          ( 0) - ������� ���������.
  */
  int chrcmp_ea(char c1, char c2);
  int chrcmp_ew(wchar_t c1, wchar_t c2);

  /**
   * �������� ������������ ��������.
   *
   * @param c1  ������ ������.
   * @param c2  ������ ������.
   *
   * @return  true  - ������� ���������,
   *          false - ������� ����������.
  */
  bool chrequ_a(char c1, char c2);
  bool chrequ_w(wchar_t c1, wchar_t c2);

  /**
   * �������� ������������ �������� ��� ����� �������� ���������� ����.
   *
   * @param c1  ������ ������.
   * @param c2  ������ ������.
   *
   * @return  true  - ������� ���������,
   *          false - ������� ����������.
  */
  bool chrequ_ea(char c1, char c2);
  bool chrequ_ew(wchar_t c1, wchar_t c2);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // chrcmp_h__