#ifndef splice_h__
#define splice_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

#if( APILIB_32 != 0 || APILIB_64 != 0 )

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ��������� ����������.
  */
  enum splice_param_t
  {
    splice_param_no              = 0x00,
    splice_param_search_redirect = 0x01, // ����� ��������� ���������.
    splice_param_create_disabled = 0x02, // �������� ������������ ���������.
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * �������� ����������.
  */
  struct splice_t;

  /**
   * ��������� ����������� � �������� ��������� ��� ��������� ���������.
   *
   * @param target ����� ������������ ���������.
   * @param hooker ����� ��� ������ ������������ ���������.
   * @param splice ����� ���������� ���������.
   * @param bridge ����� ��� ������ ������������ ���������.
  */
  typedef void (__fastcall* splice_notify_t)(void* target, void* hooker, splice_t* splice, void* bridge);

  /**
   * ������� ����������� ��������������� ���������.
  */
  struct spliceitem_t
  {
    void*           target; // ����� ������������ ���������.
    void*           hooker; // ����� ������������ ���������.
    uint32_t        params; // ��������� ����������.
    splice_notify_t notify; // ��������� ������������ � ��������� ��������� ����������.
    splice_t*       splice; // �������� ���������� ����������� ��� ��������� ���������.
    void*           bridge; // ����� ����� ��� ������ ������������ ��������� ����� ���������.
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ����� ������ ��������� ���������.
   *
   * @param target ����� ��������������� ���������.
   *
   * @return ����� ��������� ��������� � ������ ������, NULL � ������ ������.
  */
  void* splice_search_redirect(void* target);

  /**
   * �������� ��������� ����������.
   *
   * @param target ����� ������������ ���������.
   * @param hooker ����� ������������ ���������.
   *
   * @return �������� ���������� � ������ ������, NULL � ������ ������.
  */
  splice_t* splice_create(void* target, void* hooker);

  /**
   * ���������� ��������� ����������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_destroy(splice_t* splice);

  /**
   * ��������� ���������� � ������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_write_modified_bytes(splice_t* splice);

  /**
   * �������� ���������� �� ������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_write_original_bytes(splice_t* splice);

  /**
   * ��������� ��������� ��� ���� �������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_enable(splice_t* splice);

  /**
   * ���������� ��������� ��� ���� �������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_disable(splice_t* splice);

  /**
   * ��������� ��������� ��� �������� ������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_enable_for_current_thread(splice_t* splice);

  /**
   * ���������� ��������� ��� �������� ������.
   *
   * @param splice �������� ����������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_disable_for_current_thread(splice_t* splice);

  /**
   * ��������� ������ �����.
   *
   * @param splice �������� ����������.
   *
   * @return ����� ����� � ������ ������, NULL � ������ ������.
  */
  void* splice_get_bridge_location(splice_t* splice);

  /**
   * ��������� ��������� ����� ���������.
   *
   * @param entry �������� ��������������� ���������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_entry_hook(spliceitem_t* item);

  /**
   * �������� ��������� ����� ���������.
   *
   * @param entry �������� ��������������� ���������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_entry_unhook(spliceitem_t* item);

  /**
   * ��������� ��������� ������ ��������.
   *
   * @param items       ������ ����������� ��������������� ���������.
   * @param items_count ���������� ��������������� �������� � �������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_group_hook(spliceitem_t* items, size_t items_count);

  /**
   * �������� ��������� ������ ��������.
   *
   * @param items       ������ ����������� ��������������� ���������.
   * @param items_count ���������� ��������������� �������� � �������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool splice_group_unhook(spliceitem_t* items, size_t items_count);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

#endif //#if( APILIB_32 != 0 || APILIB_64 != 0 )

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // splice_h__