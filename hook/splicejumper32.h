#ifndef splicejumper32_h__
#define splicejumper32_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ������������� �������� �� �������� ���������� ������������ ��������� ���� ������������.
 * ���������� ���������� ������������ ��������� ��� ������ ����������� ��������� ��������.
 * ���������� ���������� ������������ ��������� ��� ������ ����������� ��������� ��������.
 *
 * �������������� ���������� �������� ���������� ������������ ��� ��������� ��� ���� �������,
 * ��� � �������� ��� ���������� ������, ���������� ��������� ����� ��� ���������.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////

#if(APILIB_32 != 0)

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ��� ������������� ��� 32-������� ���������.
   * �������� �� �������� ���������� ������ ������ ����������� ������������� ���������.
  */
# pragma pack(1)
  struct splicejumper_bincode_t
  {
    unsigned char dbg;                    ///    int   3               0xCC
    unsigned char dummy00;                ///    pusha                 0x60
    unsigned char dummy01[4];             ///    mov   edx, [esp+8*4]  0x8B,0x54,0x24,0x20
    struct
    {
      unsigned char dummy;                ///    mov   ecx, ???        0xB9
      const void*   jumper;               ///    ??? -> �������� �������������.
    } s1;
    struct
    {
      unsigned char dummy;                ///    mov   eax, ???        0xB8
      const void*   jumper_enter_bincode; ///    ??? -> ���������� ����� � �������������.
    } s2;
    unsigned char dummy02[2];             ///    call  eax             0xFF,0xD0
    unsigned char dummy03[4];             ///    mov   [esp+8*4], eax  0x89,0x44,0x24,0x20
    unsigned char dummy04;                ///    popa                  0x61
    unsigned char dummy05;                ///    pop   eax             0x58
    unsigned char dummy06[2];             ///    call  eax             0xFF,0xD0
    unsigned char dummy07;                ///    push  eax             0x50
    unsigned char dummy08;                ///    pusha                 0x60
    struct
    {
      unsigned char dummy;                ///    mov   ecx, ???        0xB9
      const void*   jumper;               ///    ??? -> �������� �������������.
    } s3;
    struct
    {
      unsigned char dummy;                ///    mov   eax, ???        0xB8
      const void*   jumper_leave_bincode; ///    ??? -> ���������� ������ �� �������������.
    } s4;
    unsigned char dummy09[2];             ///    call  eax             0xFF,0xD0
    unsigned char dummy10[4];             ///    mov   [esp+8*4], eax  0x89,0x44,0x24,0x20
    unsigned char dummy11;                ///    popa                  0x61
    unsigned char dummy12;                ///    retn                  0xC3
  };
# pragma pack()

  /**
   * �������� ������ �������� ��� ������ ������������ �������� ��� �������������.
  */
  struct splicejumper_retaddr_t
  {
    spliceimport_tid_t thread_id;
    void*              return_address;
  };

  /**
   * �������� ������������� ������ ��� �������� �������� ��������.
  */
  struct splicejumper_skipped_t
  {
    spliceimport_tid_t thread_id;
  };

  /**
   * �������� ������������� ��� 32-������� ���������.
   * �������� �������� ���, ������� ������ ���� �������� � ������ � ������� �� ����������.
  */
  struct splicejumper_t
  {
    bool                    active;         // ������� �� �������������.
    void*                   bridge;         // ����� ��� ������ ������������ ���������.
    void*                   hooker;         // ����� ��� ������ ������������ ���������.

    spliceimport_cs_t       retaddr_cs;     // ����������� ������ ��� ������������� �������.
    splicejumper_retaddr_t* retaddr_array;  // ������ ������� ��������.
    size_t                  retaddr_count;  // ���-�� ������� ��������.

    spliceimport_cs_t       skipped_cs;     // ����������� ������ ��� ������������� �������.
    splicejumper_skipped_t* skipped_array;  // ������ ������� �������� ��� ������� ��������.
    size_t                  skipped_count;  // ���-�� ������� �������� ��� ������� ��������.

    splicejumper_bincode_t  bincode;        // �������� ��� �������������.
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ��������� �������������.
   * 
   * @param jumper �������� �������������.
   * @param bridge ����� ��� ������ ������������ ���������.
   * @param hooker ����� ��� ������ ������������ ���������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_create(splicejumper_t* jumper, void* bridge, void* hooker);

  /**
   * ���������� ��������� �������������.
   *
   * ����� ����������� ��������� ���������� ��������� � ��� ���������� � ���������� ��������� 
   * splicejumper_destroy_available(), �������� ���������� ������������ ������� ��������, �����
   * �� �������� ���������� ������ ����������� �������������, �� �� ������������ �� ���� �����.
   *
   * @param jumper �������� �������������. 
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_destroy(splicejumper_t* jumper);

  /**
   * �������� ���������� � ���������� ��������� �������������.
   *
   * @param jumper �������� �������������.
   *
   * @return true �������� ����� � ����������, false �� ����� � ���������� ��� � ������ ������.
  */
  bool splicejumper_destroy_available(splicejumper_t* jumper);

  /**
   * ��������� ���������� ������������� ��� ���� �������.
   *
   * @param jumper �������� �������������.
   *
   * @return true �������� �������, false �������� �� ������� ��� � ������ ������.
  */
  bool splicejumper_get_active(splicejumper_t* jumper);

  /**
   * ��������� ���������� ������������� ��� ���� �������.
   *
   * @param jumper �������� �������������.
   * @param active ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_set_active(splicejumper_t* jumper, bool active);

  /**
   * ��������� ���������� ������������� ��� �������� ������.
   *
   * @param jumper �������� �������������.
   *
   * @return true �������� �������, false �������� �� ������� ��� � ������ ������.
  */
  bool splicejumper_get_active_for_current_thread(splicejumper_t* jumper);

  /**
   * ��������� ���������� ������������� ��� �������� ������.
   *
   * @param jumper �������� �������������.
   * @param active ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_set_active_for_current_thread(splicejumper_t* jumper, bool active);

  /**
   * ��������� ������ ��� ������ ������������ ���������.
   *
   * @param jumper �������� �������������.
   *
   * @return ����� ��� ������ ������������ ��������� � ������ ������, NULL � ������ ������.
  */
  void* splicejumper_get_brdige(splicejumper_t* jumper);

  /**
   * ��������� ������ ��� ������ ������������ ���������.
   *
   * @param jumper �������� �������������.
   * @param bridge ����� ��� ������ ������������ ���������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_set_bridge(splicejumper_t* jumper, void* bridge);

  /**
   * ��������� ������ ��� ������ ������������ ���������.
   *
   * @param jumper �������� �������������.
   *
   * @return ����� ��� ������ ������������ ��������� � ������ ������, NULL � ������ ������.
  */
  void* splicejumper_get_hooker(splicejumper_t* jumper);

  /**
   * ��������� ������ ��� ������ ������������ ���������.
   *
   * @param jumper �������� �������������.
   * @param hooker ����� ��� ������ ������������ ���������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splicejumper_set_hooker(splicejumper_t* jumper, void* hooker);

  /**
   * ��������� ���������� �������������.
   *
   * @param jumper �������� �������������.
   *
   * @return ���������� ������������� � ������ ������, NULL � ������ ������.
  */
  void* splicejumper_get_location(splicejumper_t* jumper);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

#endif // #if(APILIB_32 != 0)

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // splicejumper32_h__