#ifndef splicejumper64_h__
#define splicejumper64_h__

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

#if(APILIB_64 != 0)

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ��� ������������� ��� 64-������� ���������.
   * �������� �� �������� ���������� ������ ������ ����������� ������������� ���������.
  */
# pragma pack(1)
  struct splicejumper_bincode_t
  {
    unsigned char dbg;                    ///    int   3               0xCC
    unsigned char dummy00;                ///    pop   rax             0x58
    unsigned char dummy01;                ///    push  rcx             0x51
    unsigned char dummy02;                ///    push  rdx             0x52
    unsigned char dummy03[2];             ///    push  r8              0x41,0x50
    unsigned char dummy04[2];             ///    push  r9              0x41,0x51
    unsigned char dummy05[3];             ///    mov   rdx, rax        0x48,0x89,0xC2
    struct
    {
      unsigned char dummy[2];             ///    mov   rcx, ???        0x48,0xB9
      const void*   jumper;               ///    ??? -> �������� �������������
    } s1;
    struct
    {
      unsigned char dummy[2];             ///    mov   rax, ???        0x48,0xB8
      const void*   jumper_enter_bincode; ///    ??? -> ���������� ����� � �������������
    } s2;
    unsigned char dummy06[4];             ///    sub   rsp, 0x20       0x48,0x83,0xEC,0x20
    unsigned char dummy07[2];             ///    call  rax             0xFF,0xD0
    unsigned char dummy08[4];             ///    add   rsp, 0x20       0x48,0x83,0xC4,0x20
    unsigned char dummy09[2];             ///    pop   r9              0x41,0x59
    unsigned char dummy10[2];             ///    pop   r8              0x41,0x58
    unsigned char dummy11;                ///    pop   rdx             0x5A
    unsigned char dummy12;                ///    pop   rcx             0x59
    unsigned char dummy13[2];             ///    call  rax             0xFF,0xD0
    unsigned char dummy14;                ///    push  rax             0x50
    unsigned char dummy15;                ///    push  rax             0x50
    struct
    {
      unsigned char dummy[2];             ///    mov   rcx, ???        0x48,0xB9
      const void*   jumper;               ///    ??? -> �������� �������������
    } s3;
    struct
    {
      unsigned char dummy[2];             ///    mov   rax, ???        0x48,0xB8
      const void*   jumper_leave_bincode; ///    ??? -> ���������� ������ �� �������������
    } s4;
    unsigned char dummy16[4];             ///    sub   rsp, 0x20       0x48,0x83,0xEC,0x20
    unsigned char dummy17[2];             ///    call  rax             0xFF,0xD0
    unsigned char dummy18[4];             ///    add   rsp, 0x20       0x48,0x83,0xC4,0x20
    unsigned char dummy19[5];             ///    mov   [rsp+1*8], rax  0x48,0x89,0x44,0x24,0x08
    unsigned char dummy20;                ///    pop   rax             0x58
    unsigned char dummy21;                ///    retn                  0xC3
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
    * �������� ������������� ��� 64-������� ���������.
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

#endif // #if(APILIB_64 != 0)

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // splicejumper64_h__