#include "../cfg.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

#if(APILIB_64 != 0)

#include "../include/lib.h"
#include "../include/log.h"
#include "../include/mem.h"

#include "spliceimport.h"
#include "spliceplaces64.h"
#include "splicerouter64.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ������ ���������� ������ � �������� 8-������ ���������.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 2 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_jmp_relative_8bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 2)
    {
      static const uint64_t himask = 0xFFFFFFFFFFFFFF00;
      static const uint64_t lomask = 0x00000000000000FF;

      uint64_t offset = (uint64_t)to - ((uint64_t)from + 2);
      uint64_t hibits = (offset & himask);
      if(hibits == 0 || hibits == himask)
      {
        *(uint08_t*)((unsigned char*)buffer + 0) = 0xEB;                        /** jmp %offset% **/
        *(uint08_t*)((unsigned char*)buffer + 1) = (uint08_t)(offset & lomask); /** ... %offset% **/
        r = true;
      }
    }

    return r;
  }

  /**
   * ������ ���������� ������ � �������� 32-������ ���������.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 5 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� �����.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_call_relative_32bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 5)
    {
      static const uint64_t himask = 0xFFFFFFFF00000000;
      static const uint64_t lomask = 0x00000000FFFFFFFF;

      uint64_t offset = (uint64_t)to - ((uint64_t)from + 5);
      uint64_t hibits = (offset & himask);
      if(hibits == 0 || hibits == himask)
      {
        *(uint08_t*)((unsigned char*)buffer + 0) = 0xE8;                        /** call %offset% **/
        *(uint32_t*)((unsigned char*)buffer + 1) = (uint32_t)(offset & lomask); /** .... %offset% **/
        r = true;
      }
    }

    return r;
  }

  /**
   * ������ ���������� ������ � �������� 32-������ ���������.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 5 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_jmp_relative_32bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 5)
    {
      static const uint64_t himask = 0xFFFFFFFF00000000;
      static const uint64_t lomask = 0x00000000FFFFFFFF;

      uint64_t offset = (uint64_t)to - ((uint64_t)from + 5);
      uint64_t hibits = (offset & himask);
      if(hibits == 0 || hibits == himask)
      {
        *(uint08_t*)((unsigned char*)buffer + 0) = 0xE9;                        /** jmp %offset% **/
        *(uint32_t*)((unsigned char*)buffer + 1) = (uint32_t)(offset & lomask); /** ... %offset% **/
        r = true;
      }
    }

    return r;;
  }

  /**
   * ������ ���������� ������ � �������� 64-������ ���������.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 14 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� �����.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_call_absolute_64bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 14)
    {
      *(uint08_t*)((unsigned char*)buffer + 0) = 0xFF;           /** jmp [%offset%] **/
      *(uint08_t*)((unsigned char*)buffer + 1) = 0x15;           /** .............. **/
      *(uint32_t*)((unsigned char*)buffer + 2) = 0x00000000;     /** ... [%offset%] **/
      *(uint64_t*)((unsigned char*)buffer + 6) = (uint64_t)(to); /** %address data% **/
      r = true;
    }

    return r;
  }

  /**
   * ������ ���������� ������ � �������� 64-������ ���������.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 14 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_jmp_absolute_64bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 14)
    {
      *(uint08_t*)((unsigned char*)buffer + 0) = 0xFF;           /** jmp [%offset%] **/
      *(uint08_t*)((unsigned char*)buffer + 1) = 0x25;           /** .............. **/
      *(uint32_t*)((unsigned char*)buffer + 2) = 0x00000000;     /** ... [%offset%] **/
      *(uint64_t*)((unsigned char*)buffer + 6) = (uint64_t)(to); /** %address data% **/
      r = true;
    }

    return r;
  }

  /**
   * ������ ���������� ������ � �������� 64-������ ��������� � ������������ �������� RAX.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 12 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� �����.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_call_by_rax_64bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 12)
    {
      *(uint08_t*)((unsigned char*)buffer + 0 ) = 0x48;           /** mov rax, %address% **/
      *(uint08_t*)((unsigned char*)buffer + 1 ) = 0xB8;           /** .................. **/
      *(uint64_t*)((unsigned char*)buffer + 2 ) = (uint64_t)(to); /** ........ %address% **/
      *(uint08_t*)((unsigned char*)buffer + 10) = 0xFF;           /** call rax           **/
      *(uint08_t*)((unsigned char*)buffer + 11) = 0xD0;           /** .................. **/
      r = true;
    }

    return r;
  }

  /**
   * ������ ���������� ������ � �������� 64-������ ��������� � ������������ �������� RAX.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 12 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_jmp_by_rax_64bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 12)
    {
      *(uint08_t*)((unsigned char*)buffer + 0 ) = 0x48;           /** mov rax, %address% **/
      *(uint08_t*)((unsigned char*)buffer + 1 ) = 0xB8;           /** .................. **/
      *(uint64_t*)((unsigned char*)buffer + 2 ) = (uint64_t)(to); /** .......  %address% **/
      *(uint08_t*)((unsigned char*)buffer + 10) = 0xFF;           /** jmp rax            **/
      *(uint08_t*)((unsigned char*)buffer + 11) = 0xE0;           /** .................. **/
      r = true;
    }

    return r;
  }

  /**
   * ������ ������ � �������� 64-������ ��������� � ������������ �������� RSP.
   *
   * @param buffer      �����.
   * @param buffer_size ������ ������, �� ����� 14 ����.
   * @param from        ����� ���� ����� �������� ����������.
   * @param to          ����� ���� ����� �������� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_jmp_by_rsp_64bit(void* buffer, size_t buffer_size, const void* from, const void* to)
  {
    bool r = false;

    if(buffer != NULL && buffer_size >= 14)
    {
      uint32_t lo_address = (uint32_t)((((uint64_t)(to))      ) & 0x00000000FFFFFFFF);
      uint32_t hi_address = (uint32_t)((((uint64_t)(to)) >> 32) & 0x00000000FFFFFFFF);

      *(uint08_t*)((unsigned char*)buffer + 0 ) = 0x68;       /** push %lo address%       **/
      *(uint32_t*)((unsigned char*)buffer + 1 ) = lo_address; /** .... %lo address%       **/
      *(uint08_t*)((unsigned char*)buffer + 5 ) = 0xC7;       /** mov [rsp], %hi address% **/
      *(uint08_t*)((unsigned char*)buffer + 6 ) = 0x44;       /** ....................... **/
      *(uint08_t*)((unsigned char*)buffer + 7 ) = 0x24;       /** ....................... **/
      *(uint08_t*)((unsigned char*)buffer + 8 ) = 0x04;       /** ....................... **/
      *(uint32_t*)((unsigned char*)buffer + 9 ) = hi_address; /** .........  %hi address% **/
      *(uint08_t*)((unsigned char*)buffer + 13) = 0xC3;       /** retn                    **/
      r = true;
    }

    return r;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ������ ����� ��� ������ � �������� 64-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_relay_longjump(spliceplaces_relay_longjump_t* relay, void* from, const void* to)
  {
    bool r = false;

    if(relay != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, relay->original, sizeof(relay->original)) == true)
      {
        static const unsigned char TPL1[spliceplaces_relay_longjump_size] = {0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90};
        static const unsigned char TPL2[spliceplaces_relay_longjump_size] = {0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC};
        static const unsigned char TPL3[spliceplaces_relay_longjump_size] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

        if(memequ_s(relay->original, sizeof(relay->original), TPL1, sizeof(TPL1)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL2, sizeof(TPL2)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL3, sizeof(TPL3)) == true)
        {
          if(spliceplaces_build_jmp_absolute_64bit(relay->modified, sizeof(relay->modified), from, to) == true)
          {
            relay->address = from;
            r = true;
          }
        }
      }
    }

    return r;
  }

  /**
   * ������ ����� ��� ������ � �������� 32-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_relay_nearjump(spliceplaces_relay_nearjump_t* relay, void* from, const void* to)
  {
    bool r = false;

    if(relay != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, relay->original, sizeof(relay->original)) == true)
      {
        static const unsigned char TPL1[spliceplaces_relay_nearjump_size] = {0x90,0x90,0x90,0x90,0x90};
        static const unsigned char TPL2[spliceplaces_relay_nearjump_size] = {0xCC,0xCC,0xCC,0xCC,0xCC};
        static const unsigned char TPL3[spliceplaces_relay_nearjump_size] = {0x00,0x00,0x00,0x00,0x00};
        static const unsigned char TPL4[spliceplaces_relay_nearjump_size] = {0x0F,0x1F,0x44,0x00,0x00}; 

        if(memequ_s(relay->original, sizeof(relay->original), TPL1, sizeof(TPL1)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL2, sizeof(TPL2)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL3, sizeof(TPL3)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL4, sizeof(TPL4)) == true)
        {
          if(spliceplaces_build_jmp_relative_32bit(relay->modified, sizeof(relay->modified), from, to) == true)
          {
            relay->address = from;
            r = true;
          }
        }
      }
    }

    return r;
  }

  /**
   * ������ ����� ��� ������ � �������� 8-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_relay_hotpatch(spliceplaces_relay_hotpatch_t* relay, void* from, const void* to)
  {
    bool r = false;

    if(relay != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, relay->original, sizeof(relay->original)) == true)
      {
        static const unsigned char TPL1[spliceplaces_relay_hotpatch_size] = {0x90,0x90};
        static const unsigned char TPL2[spliceplaces_relay_hotpatch_size] = {0x66,0x90};
        unsigned char b0 = ((const unsigned char*)relay->original)[0];
        unsigned char b1 = ((const unsigned char*)relay->original)[1];

        //�������� ���� �������� � ����������� ���� "mov reg1, reg2", ��� "reg1" ����� "reg2".
        if(memequ_s(relay->original, sizeof(relay->original), TPL1, sizeof(TPL1)) == true ||
           memequ_s(relay->original, sizeof(relay->original), TPL2, sizeof(TPL2)) == true ||
           (b0 == 0x8B && ((b1 >> 6) & 0x03) == 0x03 && ((b1 >> 3) & 0x07) == ((b1) & 0x07)))
        {
          if(spliceplaces_build_jmp_relative_8bit(relay->modified, sizeof(relay->modified), from, to) == true)
          {
            relay->address = from;
            r = true;
          }
        }
      }
    }

    return r;
  }

  /**
   * ������ ��������� ��� ������ � �������� 64-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_tramp_longjump(spliceplaces_tramp_longjump_t* tramp, void* from, const void* to)
  {
    bool r = false;

    if(tramp != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, tramp->original, sizeof(tramp->original)) == true)
      {
        if(spliceplaces_build_jmp_absolute_64bit(tramp->modified, sizeof(tramp->modified), from, to) == true)
        {
          tramp->address = from;
          r = true;
        }
      }
    }

    return r;
  }

  /**
   * ������ ��������� ��� ������ � �������� 32-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_tramp_nearjump(spliceplaces_tramp_nearjump_t* tramp, void* from, const void* to)
  {
    bool r = false;

    if(tramp != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, tramp->original, sizeof(tramp->original)) == true)
      {
        if(spliceplaces_build_jmp_relative_32bit(tramp->modified, sizeof(tramp->modified), from, to) == true)
        {
          tramp->address = from;
          r = true;
        }
      }
    }

    return r;
  }

  /**
   * ������ ��������� ��� ������ � �������� 8-������ ���������.
   *
   * @param relay �������� �����.
   * @param from  ����� ���� ������������ ������.
   * @param to    ����� ���� ������������ ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_build_tramp_minijump(spliceplaces_tramp_minijump_t* tramp, void* from, const void* to)
  {
    bool r = false;

    if(tramp != NULL && from != NULL && to != NULL)
    {
      if(spliceimport_memread(from, tramp->original, sizeof(tramp->original)) == true)
      {
        if(spliceplaces_build_jmp_relative_8bit(tramp->modified, sizeof(tramp->modified), from, to) == true)
        {
          tramp->address = from;
          r = true;
        }
      }
    }

    return r;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ���������� ���� �� ����� 'A'.
   *
   * ������������ ������� ������:
   * 1) 08-������ �� ������� �������, ��������� ���������� ��� �������� 2 ����.
   * 2) 64-������ �� ������� ��� ����������, ��������� ���������� ��� �������� 14 ����.
   *
   * @param places         �������� ��������.
   * @param target         ����� ���������.
   * @param jumper         ����� �������������.
   * @param bridge_address ���������� ������� ���������� ��������� �� ����.
   * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_a(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && jumper != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* relay_longjump_address = (unsigned char*)target - spliceplaces_relay_longjump_size;
      void* relay_hotpatch_address = (unsigned char*)target;

      if(spliceplaces_build_relay_longjump(&places->relay_longjump, relay_longjump_address, jumper) == true &&
         spliceplaces_build_relay_hotpatch(&places->relay_hotpatch, relay_hotpatch_address, relay_longjump_address) == true)
      {
        places->used    = spliceplaces_relay_hotpatch_used | spliceplaces_relay_longjump_used;
        *bridge_address = (unsigned char*)relay_hotpatch_address + spliceplaces_relay_hotpatch_size;
        *bridge_movecnt = 0;
        r = true;
      }
    }

    return r;
  }

  /**
    * ���������� ���� �� ����� 'B'.
    *
    * ������������ ������� ������:
    * 1) 08-������ �� ������� ���������, ��������� ���������� � ��������� 2 ����.
    * 2) 64-������ �� ������� ��� ����������, ��������� ���������� ��� �������� 14 ����.
    *
    * @param places         �������� ��������.
    * @param target         ����� ���������.
    * @param jumper         ����� �������������.
    * @param bridge_address ���������� ������� ���������� ��������� �� ����.
    * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
    * 
    * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_b(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && jumper != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* relay_longjump_address = (unsigned char*)target - spliceplaces_relay_longjump_size;
      void* tramp_minijump_address = (unsigned char*)target;

      if(spliceplaces_build_relay_longjump(&places->relay_longjump, relay_longjump_address, jumper) == true &&
         spliceplaces_build_tramp_minijump(&places->tramp_minijump, tramp_minijump_address, relay_longjump_address) == true)
      {
        places->used    = spliceplaces_tramp_minijump_used | spliceplaces_relay_longjump_used;
        *bridge_address = tramp_minijump_address;
        *bridge_movecnt = spliceplaces_tramp_minijump_size;
        r = true;
      }
    }

    return r;
  }

  /**
    * ���������� ���� �� ����� 'C'.
    *
    * ������������ ������� ������:
    * 1) 08-������ �� ������� �������, ��������� ���������� ��� �������� 2 ����.
    * 2) 32-������ �� ������� ��� ����������, ��������� ���������� ��� �������� 5 ����.
    *
    * @param places         �������� ��������.
    * @param target         ����� ���������.
    * @param jumper         ����� �������������.
    * @param bridge_address ���������� ������� ���������� ��������� �� ����.
    * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
    * 
    * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_c(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* route = splicerouter_get_personal(target, jumper);
      if(route != NULL)
      {
        void* relay_nearjump_address = (unsigned char*)target - spliceplaces_relay_nearjump_size;
        void* relay_hotpatch_address = (unsigned char*)target;

        if(spliceplaces_build_relay_nearjump(&places->relay_nearjump, relay_nearjump_address, route) == true &&
           spliceplaces_build_relay_hotpatch(&places->relay_hotpatch, relay_hotpatch_address, relay_nearjump_address) == true)
        {
          places->used    = spliceplaces_relay_hotpatch_used | spliceplaces_relay_nearjump_used;
          *bridge_address = (unsigned char*)relay_hotpatch_address + spliceplaces_relay_hotpatch_size;
          *bridge_movecnt = 0;
          r = true;
        }
        else
        {
          splicerouter_free_personal(route);
        }
      }
    }

    return r;
  }

  /**
    * ���������� ���� �� ����� 'D'.
    *
    * ������������ ������� ������:
    * 1) 08-������ �� ������� ���������, ��������� ���������� � ��������� 2 ����.
    * 2) 32-������ �� ������� ��� ����������, ��������� ���������� ��� �������� 5 ����.
    *
    * @param places         �������� ��������.
    * @param target         ����� ���������.
    * @param jumper         ����� �������������.
    * @param bridge_address ���������� ������� ���������� ��������� �� ����.
    * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
    * 
    * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_d(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* route = splicerouter_get_personal(target, jumper);
      if(route != NULL)
      {
        void* relay_nearjump_address = (unsigned char*)target - spliceplaces_relay_nearjump_size;
        void* tramp_minijump_address = (unsigned char*)target;

        if(spliceplaces_build_relay_nearjump(&places->relay_nearjump, relay_nearjump_address, route) == true &&
           spliceplaces_build_tramp_minijump(&places->tramp_minijump, tramp_minijump_address, relay_nearjump_address) == true)
        {
          places->used    = spliceplaces_tramp_minijump_used | spliceplaces_relay_nearjump_used;
          *bridge_address = tramp_minijump_address;
          *bridge_movecnt = spliceplaces_tramp_minijump_size;
          r = true;
        }
        else
        {
          splicerouter_free_personal(route);
        }
      }
    }

    return r;
  }

  /**
    * ���������� ���� �� ����� 'E'.
    *
    * ������������ ��������� ������:
    * 1) 32-������ �� ������� ���������, ��������� ���������� � ��������� 5 ����.
    *
    * @param places         �������� ��������.
    * @param target         ����� ���������.
    * @param jumper         ����� �������������.
    * @param bridge_address ���������� ������� ���������� ��������� �� ����.
    * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
    * 
    * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_e(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* route = splicerouter_get_personal(target, jumper);
      if(route != NULL)
      {
        void* tramp_nearjump_address = target;

        if(spliceplaces_build_tramp_nearjump(&places->tramp_nearjump, tramp_nearjump_address, route) == true)
        {
          places->used    = spliceplaces_tramp_nearjump_used;
          *bridge_address = tramp_nearjump_address;
          *bridge_movecnt = spliceplaces_tramp_nearjump_size;
          r = true;
        }
        else
        {
          splicerouter_free_personal(route);
        }
      }
    }

    return r;
  }

  /**
   * ���������� ���� �� ����� 'F'.
   *
   * ������������ ��������� ������:
   * 1) 64-������ �� ������� ���������, ��������� ���������� � ��������� 14 ����.
   *
   * @param places         �������� ��������.
   * @param target         ����� ���������.
   * @param jumper         ����� �������������.
   * @param bridge_address ���������� ������� ���������� ��������� �� ����.
   * @param bridge_movecnt ���������� ���������� � ������ ������� ���������� ��������� �� ����.
   * 
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_create_by_plan_f(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
  {
    bool r = false;

    if(places != NULL && target != NULL && jumper != NULL && bridge_address != NULL && bridge_movecnt != NULL)
    {
      void* tramp_longjump_address = target;

      if(spliceplaces_build_tramp_longjump(&places->tramp_longjump, tramp_longjump_address, jumper) == true)
      {
        places->used    = spliceplaces_tramp_longjump_used;
        *bridge_address = tramp_longjump_address;
        *bridge_movecnt = spliceplaces_tramp_longjump_size;
        r = true;
      }
    }

    return r;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * ������ ������ � ������� ������.
   *
   * 1) ������ ����������� �� ������� ������.
   * 2) ��������� ������ ����������� �� ������������ ��������� ��������� ������������� ������.
   * 3) ������ ������������ � ������� ������ ��� �������������.
   *
   * @param address   ����� ������� ������.
   * @param data      ������ ��� ������.
   * @param data_size ������ ������ ��� ������.
   * @param temp      ������ ��� ������.
   * @param temp_size ������ ������ ��� ������.
   *
   * @return true � ������ ������, false � ������ ������.
  */
  static bool spliceplaces_set_data(const void* address, const void* data, size_t data_size, void* temp, size_t temp_size)
  {
    bool r = false;

    if(address != NULL && data != NULL && data_size != 0 && temp != NULL && temp_size != 0 && data_size == temp_size)
    {
      if(spliceimport_memread(address, temp, temp_size) == true)
      {
        if(memequ_s(data, data_size, temp, temp_size) == true)
        {
          r = true;
        }
        else if(spliceimport_memwrite(address, data, data_size) == true)
        {
          r = true;
        }
      }
    }

    return r;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

bool apilib::spliceplaces_create(spliceplaces_t* places, void* target, void* jumper, void** bridge_address, size_t* bridge_movecnt)
{
  bool r = false;

  do 
  {
    if(places == NULL || target == NULL || jumper == NULL || bridge_address == NULL || bridge_movecnt == NULL)
    {
      loge("Invalid argument.");
      break;
    }

    if(memzero(places, sizeof(spliceplaces_t)) == false)
    {
      loge("Failed to zero memory.");
      break;
    }

    if(spliceplaces_create_by_plan_a(places, target, jumper, bridge_address, bridge_movecnt) == false &&
       spliceplaces_create_by_plan_b(places, target, jumper, bridge_address, bridge_movecnt) == false &&
       spliceplaces_create_by_plan_c(places, target, jumper, bridge_address, bridge_movecnt) == false &&
       spliceplaces_create_by_plan_d(places, target, jumper, bridge_address, bridge_movecnt) == false &&
       spliceplaces_create_by_plan_e(places, target, jumper, bridge_address, bridge_movecnt) == false &&
       spliceplaces_create_by_plan_f(places, target, jumper, bridge_address, bridge_movecnt) == false)
    {
      loge("Failed to create places context (target address %p, jumper address %p).", target, jumper);
      break;
    }

    r = true;
  }
  while(0);

  return r;
}

bool apilib::spliceplaces_destroy(spliceplaces_t* places)
{
  bool r = false;

  do 
  {
    if(places == NULL)
    {
      loge("Invalid argument.");
      break;
    }

    if(memzero(places, sizeof(spliceplaces_t)) == false)
    {
      loge("Failed to zero memory.");
      break;
    }

    r = true;
  }
  while(0);

  return r;
}

bool apilib::spliceplaces_destroy_available(spliceplaces_t* places)
{
  bool r = false;

  do 
  {
    if(places == NULL)
    {
      loge("Invalid argument.");
      break;
    }

    r = true;
  }
  while(0);

  return r;
}

bool apilib::spliceplaces_write_original_bytes(spliceplaces_t* places)
{
  bool r = false;

  do 
  {
    if(places == NULL)
    {
      loge("Invalid argument.");
      break;
    }

    if((places->used & spliceplaces_relay_longjump_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_longjump_size];
      if(spliceplaces_set_data(places->relay_longjump.address, places->relay_longjump.original, sizeof(places->relay_longjump.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_longjump original data.");
        break;
      }
    }

    if((places->used & spliceplaces_relay_nearjump_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_nearjump_size];
      if(spliceplaces_set_data(places->relay_nearjump.address, places->relay_nearjump.original, sizeof(places->relay_nearjump.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_nearjump original data.");
        break;
      }
    }

    if((places->used & spliceplaces_relay_hotpatch_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_hotpatch_size];
      if(spliceplaces_set_data(places->relay_hotpatch.address, places->relay_hotpatch.original, sizeof(places->relay_hotpatch.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_hotpatch original data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_longjump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_longjump_size];
      if(spliceplaces_set_data(places->tramp_longjump.address, places->tramp_longjump.original, sizeof(places->tramp_longjump.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_longjump original data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_nearjump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_nearjump_size];
      if(spliceplaces_set_data(places->tramp_nearjump.address, places->tramp_nearjump.original, sizeof(places->tramp_nearjump.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_nearjump original data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_minijump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_minijump_size];
      if(spliceplaces_set_data(places->tramp_minijump.address, places->tramp_minijump.original, sizeof(places->tramp_minijump.original), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_minijump original data.");
        break;
      }
    }

    r = true;
  }
  while(0);

  return r;
}

bool apilib::spliceplaces_write_modified_bytes(spliceplaces_t* places)
{
  bool r = false;

  do 
  {
    if(places == NULL)
    {
      loge("Invalid argument.");
      break;
    }

    if((places->used & spliceplaces_relay_longjump_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_longjump_size];
      if(spliceplaces_set_data(places->relay_longjump.address, places->relay_longjump.modified, sizeof(places->relay_longjump.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_longjump modified data.");
        break;
      }
    }

    if((places->used & spliceplaces_relay_nearjump_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_nearjump_size];
      if(spliceplaces_set_data(places->relay_nearjump.address, places->relay_nearjump.modified, sizeof(places->relay_nearjump.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_nearjump modified data.");
        break;
      }
    }

    if((places->used & spliceplaces_relay_hotpatch_used) != 0)
    {
      unsigned char temp[spliceplaces_relay_hotpatch_size];
      if(spliceplaces_set_data(places->relay_hotpatch.address, places->relay_hotpatch.modified, sizeof(places->relay_hotpatch.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write relay_hotpatch modified data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_longjump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_longjump_size];
      if(spliceplaces_set_data(places->tramp_longjump.address, places->tramp_longjump.modified, sizeof(places->tramp_longjump.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_longjump modified data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_nearjump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_nearjump_size];
      if(spliceplaces_set_data(places->tramp_nearjump.address, places->tramp_nearjump.modified, sizeof(places->tramp_nearjump.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_nearjump modified data.");
        break;
      }
    }

    if((places->used & spliceplaces_tramp_minijump_used) != 0)
    {
      unsigned char temp[spliceplaces_tramp_minijump_size];
      if(spliceplaces_set_data(places->tramp_minijump.address, places->tramp_minijump.modified, sizeof(places->tramp_minijump.modified), temp, sizeof(temp)) == false)
      {
        loge("Failed to write tramp_minijump modified data.");
        break;
      }
    }

    r = true;
  }
  while(0);

  return r;
}

#endif // #if(APILIB_64 != 0)

///////////////////////////////////////////////////////////////////////////////////////////////////