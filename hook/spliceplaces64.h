#ifndef spliceplaces64_h__
#define spliceplaces64_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

#if(APILIB_64 != 0)

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ������� �������� ������.
  */
  enum spliceplaces_size_t
  {
    spliceplaces_relay_longjump_size = 14,
    spliceplaces_relay_nearjump_size = 5,
    spliceplaces_relay_hotpatch_size = 2,
    spliceplaces_tramp_longjump_size = 14,
    spliceplaces_tramp_nearjump_size = 5,
    spliceplaces_tramp_minijump_size = 2,
  };

  /**
   * ������������ ������� ������.
  */
  enum spliceplaces_used_t
  {
    spliceplaces_relay_longjump_used = 0x01,
    spliceplaces_relay_nearjump_used = 0x02,
    spliceplaces_relay_hotpatch_used = 0x04,
    spliceplaces_tramp_longjump_used = 0x08,
    spliceplaces_tramp_nearjump_used = 0x10,
    spliceplaces_tramp_minijump_used = 0x20,
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ������� ��� ���������� ������ � �������� 64-���.
   * �������� �������������� ������ ��� ���������� �������� 14 ����.
  */
  struct spliceplaces_relay_longjump_t
  {
    const void*   address;
    unsigned char original[spliceplaces_relay_longjump_size];
    unsigned char modified[spliceplaces_relay_longjump_size];
  };

  /**
   * �������� ������� ��� ���������� ������ � �������� 32-���.
   * �������� �������������� ������ ��� ���������� �������� 5 ����.
  */
  struct spliceplaces_relay_nearjump_t
  {
    const void*   address;
    unsigned char original[spliceplaces_relay_nearjump_size];
    unsigned char modified[spliceplaces_relay_nearjump_size];
  };

  /**
   * �������� ������� ��� ���������� ������ � �������� 8-���.
   * �������� �������������� ������ ������ ��������� �������� 2 �����.
  */
  struct spliceplaces_relay_hotpatch_t
  {
    const void*   address;
    unsigned char original[spliceplaces_relay_hotpatch_size];
    unsigned char modified[spliceplaces_relay_hotpatch_size];
  };

  /**
   * �������� ������� ��� ���������� ������ � �������� 64-���.
   * �������� ������������ ������ ������ ��������� �������� 14 ����.
  */
  struct spliceplaces_tramp_longjump_t
  {
    const void*   address;
    unsigned char original[spliceplaces_tramp_longjump_size];
    unsigned char modified[spliceplaces_tramp_longjump_size];
  };

  /**
   * �������� ������� ��� ���������� ������ � �������� 32-���.
   * �������� ������������ ������ ������ ��������� �������� 5 ����.
  */
  struct spliceplaces_tramp_nearjump_t
  {
    const void*   address;
    unsigned char original[spliceplaces_tramp_nearjump_size];
    unsigned char modified[spliceplaces_tramp_nearjump_size];
  };

  /**
   * �������� ������� ��� ���������� ������ � �������� 8-���.
   * �������� ������������ ������ ������ ��������� �������� 2 �����.
  */
  struct spliceplaces_tramp_minijump_t
  {
    const void*   address;
    unsigned char original[spliceplaces_tramp_minijump_size];
    unsigned char modified[spliceplaces_tramp_minijump_size];
  };

  /**
   * �������� �������� � ������ �� ���� �� ��������������� ��������� � �������������.
  */
  struct spliceplaces_t
  {
    unsigned char used;

    spliceplaces_relay_longjump_t relay_longjump;
    spliceplaces_relay_nearjump_t relay_nearjump;
    spliceplaces_relay_hotpatch_t relay_hotpatch;
    spliceplaces_tramp_longjump_t tramp_longjump;
    spliceplaces_tramp_nearjump_t tramp_nearjump;
    spliceplaces_tramp_minijump_t tramp_minijump;
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ��������� ��������.
   *
   * @param places         �������� ��������.
   * @param target         ����� ���������.
   * @param jumper         ����� �������������.
   * @param bridge_address ���������� ������� ���������� ��������� �� ����.
   * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceplaces_create(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt);

  /**
   * ���������� ��������� ��������.
   *
   * @param places �������� ��������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceplaces_destroy(spliceplaces_t* places);

  /**
   * �������� ���������� � ���������� ��������� ��������.
   *
   * @param places �������� ��������.
   *
   * @return true �������� ����� � ����������, false �� ����� � ���������� ��� � ������ ������.
  */
  bool spliceplaces_destroy_available(spliceplaces_t* places);

  /**
   * ������ ������������ ������.
   *
   * @param places �������� ��������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceplaces_write_original_bytes(spliceplaces_t* places);

  /**
   * ������ ���������������� ������.
   *
   * @param places �������� ��������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceplaces_write_modified_bytes(spliceplaces_t* places);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

#endif // #if(APILIB_64 != 0)

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // spliceplaces64_h__