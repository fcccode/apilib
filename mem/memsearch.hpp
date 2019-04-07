#ifndef memsearch_hpp__
#define memsearch_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ����� ��������.
   *
   * ����� ����������� � ����� � 1 ����.
   * ����� ����������� �� ������� ����������.
   *
   * @param data  ������.
   * @param size  ������ ������.
   * @param value �������� ��� ������.
   *
   * @return ��������� �������� � ������ ������,
   *         NULL ���� �������� �� ������� ��� ��������� ������.
  */
  template<typename T>
  inline T* __memsearch_x(const void* data, size_t size, T value)
  {
    T* result = NULL;

    if(data != NULL && size >= sizeof(T))
    {
      const T* ptr = (const T*)((const unsigned char*)data);
      const T* end = (const T*)((const unsigned char*)data + size - sizeof(T));

      while(ptr <= end)
      {
        if(*ptr == value)
        {
          result = (T*)ptr;
          break;
        }
        ptr = (const T*)((const unsigned char*)ptr + 1);
      }
    }

    return result;
  }
  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // memsearch_hpp__