#ifndef spliceimport_h__
#define spliceimport_h__

///////////////////////////////////////////////////////////////////////////////////////////////////

# if(APILIB_OS_WINNT != 0)
# include "../ntdll/ntdll.h"
# endif

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ��� ������ �������������� ������.
  */
# if(APILIB_OS_WINNT != 0)
  typedef unsigned long int spliceimport_tid_t;   
# endif

  /**
   * ��� ������ �������������� ��������.
  */
# if(APILIB_OS_WINNT != 0)
  typedef unsigned long int spliceimport_pid_t;   
# endif

  /**
   * ��� ������ ����������� ������.
  */
# if(APILIB_OS_WINNT != 0)
  typedef RTL_CRITICAL_SECTION spliceimport_cs_t;
# endif

  /**
   * ������������ TID.
  */
# if(APILIB_OS_WINNT != 0)
  static const spliceimport_tid_t THREAD_ID_INVALID = (spliceimport_tid_t)-1;
# endif

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ���������� � ����������� ������.
  */
  struct memquery_t
  {
    void*  addr;     //�����.
    size_t size;     //������.
    bool   free;     //������ �� ���������� ������ ��������.
    bool   rsrv;     //������ �� ���������� ������ � �������. 
  };

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ��������� �������������� �������� ������.
   *
   * @param tid ������������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_get_current_tid(spliceimport_tid_t* tid);

  /**
   * ��������� �������������� �������� ��������.
   *
   * @param pid ������������� ��������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_get_current_pid(spliceimport_pid_t* pid);

  /**
   * �������� ����������� ������.
   *
   * @param cs ����������� ������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_cs_create(spliceimport_cs_t* cs);

  /**
   * ���������� ����������� ������.
   *
   * @param cs ����������� ������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_cs_destroy(spliceimport_cs_t* cs);

  /**
   * ���� � ����������� ������.
   *
   * @param cs ����������� ������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_cs_enter(spliceimport_cs_t* cs);

  /**
   * ����� �� ����������� ������.
   *
   * @param cs ����������� ������.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_cs_leave(spliceimport_cs_t* cs);

  /**
   * ������������� ����������� ������.
   *
   * @param size ������ ������� ������.
   *
   * @return ����� ������� ������ � ������ ������, NULL � ������ ������.
  */
  void* spliceimport_memalloc(size_t size);

  /**
   * ������������� ����������� ������ �� �������������� ������.
   *
   * @param address ����� ������� ������.
   * @param size    ������ ������� ������.
   *
   * @return ����� ������� ������ � ������ ������, NULL � ������ ������.
  */
  void* spliceimport_memalloc_address(void* address, size_t size);

  /**
   * ������������ ����������� ������.
   *
   * @param address ����� ������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_memfree(void* address);

  /**
   * ������ ���������� � ����������� ������.
   *
   * @param address ����� ������� ������.
   * @param mq      ���������� � ����������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_memquery(const void* address, memquery_t* mq);

  /**
   * ������ ����������� ������.
   *
   * @param address ����� ������� ������.
   * @param data    �����.
   * @param size    ������ ����������� ������ � �����.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_memread(const void* address, void* data, size_t size);

  /**
   * ������ ����������� ������.
   *
   * @param address ����� ������� ������.
   * @param data    ������.
   * @param size    ������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  bool spliceimport_memwrite(const void* address, const void* data, size_t size);

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // spliceimport_h__